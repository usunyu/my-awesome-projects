# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import globals, node, formula


class ModelType:
    Workbook = 0
    Unknown = 999


class ModelBase(globals.ModelBase):
    def __init__ (self, modelType=ModelType.Unknown):
        globals.ModelBase.__init__(self, globals.ModelBase.HostAppType.Excel)
        self.modelType = modelType


class Workbook(ModelBase):

    def __init__ (self):
        ModelBase.__init__(self, ModelType.Workbook)

        # public members
        self.encrypted = False

        # private members
        self.__sheets = []


    def appendSheet (self, sheetType):
        def raiseError(cause):
            def errorFunc():
                raise Exception(cause)

        HANDLERS = { 0x0005: WorkbookGlobal,
                     0x0006: raiseError("Unsupported sheet type: Visual Basic module"),
                     0x0010: lambda: Worksheet(len(self.__sheets)),
                     0x0020: Chart,
                     0x0040: raiseError("Unsupported sheet type: Excel 4.0 macro sheet"),
                     0x0100: raiseError("Unsupported sheet type: Workspace file")
                    }
        self.__sheets.append(HANDLERS[sheetType]())

        return self.__sheets[-1]

    def getWorkbookGlobal (self):
        return filter(lambda x: isinstance(x, WorkbookGlobal), self.__sheets)[0]

    def getCurrentSheet (self):
        return self.__sheets[-1]

    def createDOM (self):
        nd = node.Element('workbook')
        nd.setAttr('encrypted', self.encrypted)
        sheets = filter(lambda x: isinstance(x, Worksheet), self.__sheets)
        n = len(sheets)
        if n == 0:
            return nd

        wbglobal = self.getWorkbookGlobal()
        nd.appendChild(wbglobal.createDOM(self))
        for (i,sheet) in enumerate(sheets):
            sheetNode = sheet.createDOM(self)
            nd.appendChild(sheetNode)
            data = wbglobal.getSheetData(i-1)
            sheetNode.setAttr('name', data.name)
            sheetNode.setAttr('visible', data.visible)

        return nd


class SheetBase(object):

    class Type:
        WorkbookGlobal = 0
        Worksheet = 1
        Chart=2

    def __init__ (self, modelType):
        self.modelType = modelType
        self.version = None

    def createDOM (self, wb):
        nd = node.Element('sheet')
        return nd


class Supbook(object):
    class Type:
        Self     = 0
        AddIn    = 1
        External = 2
        DDE      = 3
        OLE      = 4
        Unused   = 5

    def __init__ (self, sbType=None):
        self.type = sbType


class SupbookSelf(Supbook):
    def __init__ (self, sheetCount):
        Supbook.__init__(self, Supbook.Type.Self)
        self.sheetCount = sheetCount


class ExtSheetCache(object):
    """External sheet cache

To store external reference cache from XCT/CRN records."""

    class CellType:
        Empty   = 0x00
        Number  = 0x01
        String  = 0x02
        Boolean = 0x04
        Error   = 0x10

    cellTypeNames = {
        CellType.Empty:   'empty',
        CellType.Number:  'number',
        CellType.String:  'string',
        CellType.Boolean: 'boolean',
        CellType.Error:   'error'
    }

    def __init__ (self):
        self.__rows = {}

    def setValue (self, row, col, celltype, val):
        if not self.__rows.has_key(row):
            self.__rows[row] = {}
        self.__rows[row][col] = (celltype, val)

    def createDOM (self, wb):
        nd = node.Element("sheet")
        rows = self.__rows.keys()
        rows.sort()
        for row in rows:
            rowElem = nd.appendElement("row")
            rowElem.setAttr("id", row)
            cols = self.__rows[row].keys()
            cols.sort()
            for col in cols:
                cell = self.__rows[row][col]
                celltype, val = cell[0], cell[1]
                cellElem = rowElem.appendElement("cell")
                cellElem.setAttr("col", col)
                cellElem.setAttr("value", val)
                cellElem.setAttr("type", globals.getValueOrUnknown(ExtSheetCache.cellTypeNames, celltype))

        return nd

class SupbookExternal(Supbook):

    def __init__ (self):
        Supbook.__init__(self, Supbook.Type.External)
        self.docURL = None
        self.__sheets = []
        self.__curSheet = 0

    def appendSheetName (self, name):
        # the 2nd item is the sheet cache.
        self.__sheets.append([name, None])

    def setCurrentSheet (self, sheetID):
        self.__curSheet = sheetID

    def getCurrentSheetCache (self):
        sheetItem = self.__sheets[self.__curSheet]
        if sheetItem[1] == None:
            sheetItem[1] = ExtSheetCache()
        return sheetItem[1]

    def createDOM (self, wb):
        nd = node.Element("external-sheet-cache")
        # 1st char is always 0x1.
        nd.setAttr("url", globals.encodeName(self.docURL[1:]))
        for sheet in self.__sheets:
            if sheet[1] == None:
                continue
            elem = sheet[1].createDOM(wb)
            elem.setAttr("name", sheet[0])
            nd.appendChild(elem)

        return nd


class Chart(SheetBase):
    def __init__(self):
        super(Chart, self).__init__(SheetBase.Type.Chart)

class WorkbookGlobal(SheetBase):
    class SheetData:
        def __init__ (self):
            self.name = None
            self.visible = True

    def __init__ (self):
        SheetBase.__init__(self, SheetBase.Type.WorkbookGlobal)

        self.__sheetData = []
        self.__sharedStrings = []
        self.__supbooks = []
        self.__externSheets = []  # tuple (book ID, sheet begin ID, sheet end ID)
        self.__dbRanges = {}      # key: sheet ID (0-based), value: range tokens
        self.__lastSupbook = None

    def createDOM (self, wb):
        nd = node.Element('workbook-global')
        for sb in self.__supbooks:
            if sb.type != Supbook.Type.External:
                continue
            nd.appendChild(sb.createDOM(wb))

        return nd

    def appendSheetData (self, data):
        self.__sheetData.append(data)

    def getSheetData (self, i):
        return self.__sheetData[i]

    def appendSharedString (self, sst):
        self.__sharedStrings.append(sst)

    def getSharedString (self, strID):
        if len(self.__sharedStrings) <= strID:
            return None
        return self.__sharedStrings[strID]

    def appendSupbook (self, sb):
        self.__supbooks.append(sb)
        self.__lastSupbook = sb

    def getSupbook (self, sbID):
        if len(self.__supbooks) <= sbID:
            return None
        return self.__supbooks[sbID]

    def getLastSupbook (self):
        return self.__lastSupbook

    def appendExternSheet (self, bookID, sheetBeginID, sheetEndID):
        self.__externSheets.append((bookID, sheetBeginID, sheetEndID))

    def getExternSheet (self, xtiID):
        if len(self.__externSheets) <= xtiID:
            return None
        return self.__externSheets[xtiID]

    def setFilterRange (self, sheetID, tokens):
        self.__dbRanges[sheetID] = tokens

    def getFilterRange (self, sheetID):
        if not self.__dbRanges.has_key(sheetID):
            return None

        return self.__dbRanges[sheetID]


class Shape(object):
    def __init__ (self, col1, row1, dx1, dy1, col2, row2, dx2, dy2):
        self.col1 = col1
        self.row1 = row1
        self.dx1 = dx1
        self.dy1 = dy1
        self.col2 = col2
        self.row2 = row2
        self.dx2 = dx2
        self.dy2 = dy2

class Worksheet(SheetBase):

    class OrderedRangeList(object):
        def __init__ (self):
            self.__list = [] # list of ranges with value [start, end, value]

        def setValue (self, key, val):
            if len(self.__list) == 0:
                self.__list.append([key, key, val])
                return

            if (key - self.__list[-1][1]) <= 1 and self.__list[-1][2] == val:
                # expand the last range.
                self.__list[-1][1] = key
            else:
                # start a new range.
                self.__list.append([key, key, val])

        def getAllRanges (self):
            return self.__list

        def getLength (self):
            return len(self.__list)


    def __init__ (self, sheetID):
        SheetBase.__init__(self, SheetBase.Type.Worksheet)
        self.__rows = {}
        self.__autoFilterArrows = []
        self.__sheetID = sheetID
        self.__firstDefinedCell = None
        self.__firstFreeCell = None
        self.__hiddenRows = Worksheet.OrderedRangeList()
        self.__rowHeights = Worksheet.OrderedRangeList()
        self.__shapes = []
        self.__lastCell = None
        self.__condFormats = []
        self.__dataValidations = []


    def addShape (self, obj):
        self.__shapes.append(obj)

    def setFirstDefinedCell (self, col, row):
        self.__firstDefinedCell = formula.CellAddress(col, row)

    def setFirstFreeCell (self, col, row):
        self.__firstFreeCell = formula.CellAddress(col, row)

    def setAutoFilterArrowSize (self, arrowSize):
        arrows = []
        for i in xrange(0, arrowSize):
            arrows.append(None)

        # Swap with the new and empty list.
        self.__autoFilterArrows = arrows

    def setAutoFilterArrow (self, filterID, obj):
        self.__autoFilterArrows[filterID] = obj

    def setCell (self, col, row, cell):
        if not self.__rows.has_key(row):
            self.__rows[row] = {}

        self.__rows[row][col] = cell
        self.__lastCell = cell

    def getLastCell (self):
        return self.__lastCell

    def setRowHidden (self, row):
        self.__hiddenRows.setValue(row, True)

    def setRowHeight (self, row, height):
        self.__rowHeights.setValue(row, height)

    def setCondFormat (self, condFmt):
        self.__condFormats.append(condFmt)

    def getLastCondFormat (self):
        return self.__condFormats[-1]

    def setDataValidation (self, dv):
        self.__dataValidations.append(dv)

    def createDOM (self, wb):
        nd = node.Element('worksheet')
        nd.setAttr('version', self.version)

        # cells
        rows = self.__rows.keys()
        rows.sort()
        for row in rows:
            rowNode = nd.appendElement('row')
            rowNode.setAttr('id', row)
            cols = self.__rows[row].keys()
            for col in cols:
                cell = self.__rows[row][col]
                cellNode = cell.createDOM(wb)
                rowNode.appendChild(cellNode)
                cellNode.setAttr('col', col)

        # table dimension
        if self.__firstDefinedCell != None:
            nd.setAttr('first-defined-cell', self.__firstDefinedCell.getName())

        if self.__firstFreeCell != None:
            try:
                nd.setAttr('first-free-cell', self.__firstFreeCell.getName())
            except Exception as e:
                if not globals.params.catchExceptions:
                    raise
                globals.error("createDOM: trying set firstFreeCell: %s\n" % e)
                pass

        self.__appendAutoFilterNode(wb, nd) # autofilter (if exists)
        self.__appendHiddenRowsNode(wb, nd) # hidden rows
        self.__appendRowHeightNode(wb, nd)  # row heights
        self.__appendShapesNode(wb, nd)     # drawing objects
        self.__appendCondFormatNode(wb, nd) # conditional formatting
        self.__appendDataValidationNode(wb, nd) # conditional formatting
        return nd

    def __appendRowHeightNode (self, wb, baseNode):
        if self.__rowHeights.getLength() == 0:
            return

        base = baseNode.appendElement('row-heights')
        for rowRange in self.__rowHeights.getAllRanges():
            entry = base.appendElement('range')
            entry.setAttr('span', "%d:%d"%(rowRange[0]+1, rowRange[1]+1))
            entry.setAttr('height', "%d"%(rowRange[2]))

    def __appendHiddenRowsNode (self, wb, baseNode):
        if self.__hiddenRows.getLength() == 0:
            # no hidden rows
            return

        elem = baseNode.appendElement('hidden-rows')
        for rowRange in self.__hiddenRows.getAllRanges():
            elem.appendElement('range').setAttr('span', "%d:%d"%(rowRange[0]+1, rowRange[1]+1))

    def __appendAutoFilterNode (self, wb, baseNode):
        if len(self.__autoFilterArrows) <= 0:
            # No autofilter in this sheet.
            return

        wbg = wb.getWorkbookGlobal()
        tokens = wbg.getFilterRange(self.__sheetID)
        parser = formula.FormulaParser(None, tokens)
        parser.parse()
        tokens = parser.getTokens()
        if len(tokens) != 1 or tokens[0].tokenType != formula.TokenType.Area3d:
            # We assume that the database range only has one range token, otherwise
            # we bail out.
            return

        tk = tokens[0]
        cellRange = tk.cellRange

        elem = baseNode.appendElement('autofilter')
        elem.setAttr('range', cellRange.getName())

        for i in xrange(0, len(self.__autoFilterArrows)):
            arrowObj = self.__autoFilterArrows[i]
            if arrowObj == None:
                arrow = elem.appendElement('arrow')
                cell = formula.CellAddress(cellRange.firstCol+i, cellRange.firstRow)
                arrow.setAttr('pos', cell.getName())
            else:
                elem.appendChild(arrowObj.createDOM(wb, cellRange))

    def __appendShapesNode (self, wb, baseNode):
        n = len(self.__shapes)
        if n == 0:
            # no drawing objects on this sheet.
            return

        elem = baseNode.appendElement('shapes')
        for obj in self.__shapes:
            objElem = elem.appendElement('shape')
            objElem.setAttr('range', "(col=%d,row=%d)-(col=%d,row=%d)"%(obj.col1,obj.row1,obj.col2,obj.row2))
            objElem.setAttr('offset-begin', "(dx=%d,dy=%d)"%(obj.dx1,obj.dy1))
            objElem.setAttr('offset-end', "(dx=%d,dy=%d)"%(obj.dx2,obj.dy2))

    def __appendCondFormatNode (self, wb, baseNode):
        n = len(self.__condFormats)
        if n == 0:
            return

        elem = baseNode.appendElement('cond-formats')
        for obj in self.__condFormats:
            objElem = elem.appendElement('cond-format')
            objElem.setAttr('format-range', "%s"%obj.formatRange.getName())

    def __appendDataValidationNode (self, wb, baseNode):
        n = len(self.__dataValidations)
        if n == 0:
            return

        elem = baseNode.appendElement('data-validations')
        for obj in self.__dataValidations:
            child = obj.createDOM(wb)
            elem.appendChild(child)


class CellBase(object):

    class Type:
        Label   = 0
        Number  = 1
        Formula = 2
        Unknown = 999

    def __init__ (self, modelType):
        self.modelType = modelType


class LabelCell(CellBase):
    def __init__ (self):
        CellBase.__init__(self, CellBase.Type.Label)
        self.strID = None

    def createDOM (self, wb):
        nd = node.Element('label-cell')
        if self.strID != None:
            sst = wb.getWorkbookGlobal().getSharedString(self.strID)
            if sst != None:
                nd.setAttr('value', sst.baseText)
        return nd


class NumberCell(CellBase):
    def __init__ (self, value):
        CellBase.__init__(self, CellBase.Type.Number)
        self.value = value

    def createDOM (self, wb):
        nd = node.Element('number-cell')
        nd.setAttr('value', self.value)
        return nd


class FormulaCell(CellBase):
    def __init__ (self):
        CellBase.__init__(self, CellBase.Type.Formula)
        self.tokens = None
        self.cachedResult = None

    def createDOM (self, wb):
        nd = node.Element('formula-cell')
        if self.tokens != None:
            parser = formula.FormulaParser(None, self.tokens)
            try:
                parser.parse()
                nd.setAttr('formula', parser.getText())
            except:
                if not globals.params.catchExceptions:
                    raise
                pass
            s = globals.getRawBytes(self.tokens, True, False)
            nd.setAttr('token-bytes', s)
            if self.cachedResult != None:
                nd.setAttr('formula-result', self.cachedResult)

        return nd


class AutoFilterArrow(object):

    def __init__ (self, filterID):
        self.filterID = filterID
        self.isActive = False
        self.equalString1 = None
        self.equalString2 = None

    def createDOM (self, wb, filterRange):
        nd = node.Element('arrow')
        col = self.filterID + filterRange.firstCol
        row = filterRange.firstRow
        cell = formula.CellAddress(col, row)
        nd.setAttr('pos', cell.getName())
        nd.setAttr('active', self.isActive)
        eqStr = ''
        if self.equalString1 != None:
            eqStr = self.equalString1
        if self.equalString2 != None:
            eqStr += ',' + self.equalString2
        nd.setAttr('equals', eqStr)
        return nd


class CondFormat(object):

    def __init__ (self):
        self.formatRange = None


class DataValidation(object):

    def __init__ (self, ranges):
        self.ranges = ranges  # list of formula.CellRange
        self.valueType = None
        self.errorStyle = None
        self.operator = None
        self.strLookup = None
        self.allowBlank = None
        self.showInputMsg = None
        self.showErrorMsg = None

        self.prompt = None
        self.promptTitle = None
        self.error = None
        self.errorTitle = None

        self.formula1 = None
        self.formula2 = None

    def createDOM (self, wb):
        nd = node.Element("data-validation")
        nd.setAttr("value-type", self.valueType)
        nd.setAttr("operator", self.operator)
        nd.setAttr("value-list", self.strLookup)
        nd.setAttr("allow-blank", self.allowBlank)
        nd.setAttr("show-input-message", self.showInputMsg)
        nd.setAttr("show-error-message", self.showErrorMsg)
        for rng in self.ranges:
            s = rng.getName()
            elem = nd.appendElement("range")
            elem.setAttr("address", s)

        if self.prompt != None:
            elem = nd.appendElement("prompt")
            elem.setAttr("text", self.prompt)
            elem.setAttr("title", self.promptTitle)

        if self.error != None:
            elem = nd.appendElement("error")
            elem.setAttr("style", self.errorStyle)
            elem.setAttr("text", self.error)
            elem.setAttr("title", self.errorTitle)

        if self.formula1 != None:
            elem = nd.appendElement("formula")
            elem.setAttr("index", 1)
            elem.setAttr("value", self.formula1)

        if self.formula2 != None:
            elem = nd.appendElement("formula")
            elem.setAttr("index", 2)
            elem.setAttr("value", self.formula2)

        return nd

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import struct, sys
import globals, formula, xlsmodel, msodraw

from globals import debug

class RecordError(Exception): pass

# -------------------------------------------------------------------
# record handler classes

class Bes(object):
    """Boolean or error value"""

    ErrorValues = {
        0x00: "#NULL!",
        0x07: "#DIV/0!",
        0x0F: "#VALUE!",
        0x17: "#REF!",
        0x1D: "#NAME?",
        0x24: "#NUM!",
        0x2A: "#N/A",
        0x2B: "#GETTING_DATA"
    }

    def __init__ (self, strm):
        self.bBoolErr = strm.readUnsignedInt(1)
        self.fError = strm.readUnsignedInt(1) != 0

    def toString (self):
        if self.fError:
            return "(error:%s)"%globals.getValueOrUnknown(Bes.ErrorValues,self.bBoolErr,"???")
        elif self.bBoolErr:
            return "(boolean:true)"
        else:
            return "(boolean:false)"


class CellParsedFormula(object):

    def __init__ (self, strm):
        cce = strm.readUnsignedInt(2)
        bytes = strm.readBytes(cce)
        parser = formula.FormulaParser(strm.header, bytes)
        parser.parse()
        self.text = parser.getText()

    def toString (self):
        return self.text


class ColRelU(object):

    def __init__ (self, strm):
        self.col = strm.readUnsignedInt(2)
        self.colRelative = (self.col & 0x4000) != 0
        self.rowRelative = (self.col & 0x8000) != 0
        self.col = self.col & 0x3FFF


class RgceLoc(object):

    def __init__ (self, strm):
        self.row = strm.readUnsignedInt(2)
        self.column = ColRelU(strm)

    def toString (self):
        s = ''
        if not self.column.colRelative:
            s += '$'
        s += formula.toColName(self.column.col)
        if not self.column.rowRelative:
            s += '$'
        s += "%d"%(self.row+1)
        return s


class Ref8(object):

    def __init__ (self, strm):
        self.row1 = strm.readUnsignedInt(2)
        self.row2 = strm.readUnsignedInt(2)
        self.col1 = strm.readUnsignedInt(2)
        self.col2 = strm.readUnsignedInt(2)

    def toString (self):
        string = ("(col=%d,row=%d) - (col=%d,row=%d)"%
                (self.col1, self.row1, self.col2, self.row2))
        if self.col1 == 0 and self.col2 == 0xFF:
            string += ", entire column"
        if self.row1 == 0 and self.row2 == 0xFFFF:
            string += ", entire row"
        return string


class RefU(object):

    def __init__ (self, strm):
        self.row1 = strm.readUnsignedInt(2)
        self.row2 = strm.readUnsignedInt(2)
        self.col1 = strm.readUnsignedInt(1)
        self.col2 = strm.readUnsignedInt(1)

    def toString (self):
        rge = formula.CellRange()
        rge.firstRow = self.row1
        rge.firstCol = self.col1
        rge.lastRow = self.row2
        rge.lastCol = self.col2
        return rge.toString()


class Ref8U(object):

    def __init__ (self, strm):
        self.row1 = strm.readUnsignedInt(2)
        self.row2 = strm.readUnsignedInt(2)
        self.col1 = strm.readUnsignedInt(2)
        self.col2 = strm.readUnsignedInt(2)

    def toString (self):
        rge = formula.CellRange()
        rge.firstRow = self.row1
        rge.firstCol = self.col1
        rge.lastRow = self.row2
        rge.lastCol = self.col2
        return rge.toString()


class RKAuxData(object):
    """Store auxiliary data for RK value"""
    def __init__ (self):
        self.multi100 = False
        self.signedInt = False

def decodeRK (rkval, auxData = None):
    multi100  = ((rkval & 0x00000001) != 0)
    signedInt = ((rkval & 0x00000002) != 0)
    realVal   = (rkval & 0xFFFFFFFC)

    if signedInt:
        # for integer, perform right-shift by 2 bits.
        realVal = realVal/4
    else:
        # for floating-point, convert the value back to the bytes,
        # pad the bytes to make it 8-byte long, and convert it back
        # to the numeric value.
        tmpBytes = struct.pack('<L', realVal)
        tmpBytes = struct.pack('xxxx') + tmpBytes
        realVal = struct.unpack('<d', tmpBytes)[0]

    if multi100:
        realVal /= 100.0

    if auxData != None:
        auxData.multi100 = multi100
        auxData.signedInt = signedInt

    return realVal


class LongRGB(object):
    def __init__ (self, r, g, b):
        self.red = r
        self.green = g
        self.blue = b

    def toString (self):
        return "(R=%d,G=%d,B=%d)"%(self.red, self.green, self.blue)


def dumpRgb(rgb):
    return {'r': rgb.red,
            'g': rgb.green,
            'b': rgb.blue}

class ICV(object):
    def __init__ (self, value):
        self.value = value

    def toString (self):
        return "color=0x%2.2X"%self.value

def dumpIcv(icv):
    return {'value': icv.value}

class CFRTID(object):
    def __init__ (self, start, end):
        self.start = start
        self.end = end


def dumpCfrtid(cfrtid):
    return {'start': cfrtid.start,
            'end': cfrtid.end}


class FrtHeader(object):
    def __init__ (self, rt, flags):
        self.rt = rt
        self.flags = flags

def dumpFrtHeader(header):
    return {'rt': header.rt,
            'flags': header.flags}


class PivotField(object):
    """Data about pivot cache field.

This is to be stored in the persistent stream data, to be used in the SXDBB
records."""
    def __init__ (self):
        self.hasMoreThan255 = False
        self.values = []


class DXFN(object):

    def __init__ (self, strm):
        bits = strm.readUnsignedInt(4)
        self.alchNinch          = (bits & 0x00000001) != 0  # whether the value of dxfalc.alc MUST be ignored.
        self.alcvNinch          = (bits & 0x00000002) != 0  # whether the value of dxfalc.alcv MUST be ignored.
        self.wrapNinch          = (bits & 0x00000004) != 0  # whether the value of dxfalc.fWrap MUST be ignored.
        self.trotNinch          = (bits & 0x00000008) != 0  # whether the value of dxfalc.trot MUST be ignored.
        self.kintoNinch         = (bits & 0x00000010) != 0  # whether the value of dxfalc.fJustLast MUST be ignored.
        self.cIndentNinch       = (bits & 0x00000020) != 0  # whether the values of dxfalc.cIndent and dxfalc.iIndent MUST be ignored.
        self.fShrinkNinch       = (bits & 0x00000040) != 0  # whether the value of dxfalc.fShrinkToFit MUST be ignored.
        self.fMergeCellNinch    = (bits & 0x00000080) != 0  # whether the value of dxfalc.fMergeCell MUST be ignored.
        self.lockedNinch        = (bits & 0x00000100) != 0  # whether the value of dxfprot.fLocked MUST be ignored.
        self.hiddenNinch        = (bits & 0x00000200) != 0  # whether the value of dxfprot.fHidden MUST be ignored.
        self.glLeftNinch        = (bits & 0x00000400) != 0  # whether the values of dxfbdr.dgLeft and dxfbdr.icvLeft MUST be ignored .
        self.glRightNinch       = (bits & 0x00000800) != 0  # whether the values of dxfbdr.dgRight and dxfbdr.icvRight MUST be ignored.
        self.glTopNinch         = (bits & 0x00001000) != 0  # whether the values of dxfbdr.dgTop and dxfbdr.icvTop MUST be ignored.
        self.glBottomNinch      = (bits & 0x00002000) != 0  # whether the values of dxfbdr.dgBottom and dxfbdr.icvBottom MUST be ignored.
        self.glDiagDownNinch    = (bits & 0x00004000) != 0  # whether the value of dxfbdr.bitDiagDown MUST be ignored.
        self.glDiagUpNinch      = (bits & 0x00008000) != 0  # whether the value of dxfbdr.bitDiagUp MUST be ignored.
        self.flsNinch           = (bits & 0x00010000) != 0  # whether the value of dxfpat.fls MUST be ignored.
        self.icvFNinch          = (bits & 0x00020000) != 0  # whether the value of dxfpat.icvForeground MUST be ignored.
        self.icvBNinch          = (bits & 0x00040000) != 0  # whether the value of dxfpat.icvBackground MUST be ignored.
        self.ifmtNinch          = (bits & 0x00080000) != 0  # whether the value of dxfnum.ifmt MUST be ignored.
        self.fIfntNinch         = (bits & 0x00100000) != 0  # whether the value of dxffntd.ifnt MUST be ignored.
        self.V                  = (bits & 0x00200000) != 0  # (unused)
        self.W                  = (bits & 0x01C00000) != 0  # (reserved; 3-bits)
        self.ibitAtrNum         = (bits & 0x02000000) != 0  # whether number formatting information is part of this structure.
        self.ibitAtrFnt         = (bits & 0x04000000) != 0  # whether font information is part of this structure.
        self.ibitAtrAlc         = (bits & 0x08000000) != 0  # whether alignment information is part of this structure.
        self.ibitAtrBdr         = (bits & 0x10000000) != 0  # whether border formatting information is part of this structure.
        self.ibitAtrPat         = (bits & 0x20000000) != 0  # whether pattern information is part of this structure.
        self.ibitAtrProt        = (bits & 0x40000000) != 0  # whether rotation information is part of this structure.
        self.iReadingOrderNinch = (bits & 0x80000000) != 0  # whether the value of dxfalc.iReadingOrder MUST be ignored.
        bits = strm.readUnsignedInt(2)
        self.fIfmtUser          = (bits & 0x0001) != 0  # When set to 1, dxfnum contains a format string.
        self.f                  = (bits & 0x0002) != 0  # (unused)
        self.fNewBorder         = (bits & 0x0004) != 0  # 0=border formats to all cells; 1=border formats to the range outline only
        self.fZeroInited        = (bits & 0x8000) != 0  # whether the value of dxfalc.iReadingOrder MUST be taken into account.

        if self.ibitAtrNum:
            # DXFNum (number format)
            if self.fIfmtUser:
                # DXFNumUser (string)
                sizeDXFNumUser = strm.readUnsignedInt(2)
                strBytes = strm.readBytes(sizeDXFNumUser)
                text, textLen = globals.getRichText(strBytes)
                self.numFmtName = text
            else:
                # DXFNumIFmt
                strm.readBytes(1) # ignored
                self.numFmtID = strm.readUnsignedInt(1)

        if self.ibitAtrFnt:
            # DXFFntD (font information)
            nameLen = strm.readUnsignedInt(1)
            if nameLen > 0:
                # Note the text length may double in case of a double-byte string.
                curPos = strm.getCurrentPos()
                self.fontName, nameLen = globals.getRichText(strm.readRemainingBytes(), nameLen)
                self.setCurrentPos(curPos) # Move back to the pre-text position.
                self.moveForward(realLen)  # Move for exactly the bytes read.

            if 63 - nameLen < 0:
                raise RecordError

            strm.readBytes(63 - nameLen) # Ignore these bytes.
            self.fontAttrs = strm.readBytes(16) # I'll process this later.
            self.fontColor = strm.readUnsignedInt(4)
            strm.readUnsignedInt(4) # ignored
            tsNinch = strm.readUnsignedInt(4)
            sssNinch = strm.readUnsignedInt(4) != 0
            ulsNinch = strm.readUnsignedInt(4) != 0
            blsNinch = strm.readUnsignedInt(4) != 0
            strm.readUnsignedInt(4) # ignored
            ich = strm.readUnsignedInt(4)
            cch = strm.readUnsignedInt(4)
            iFnt = strm.readUnsignedInt(2)

        if self.ibitAtrAlc:
            # DXFALC (text alignment properties)
            strm.readUnsignedInt(8)

        if self.ibitAtrBdr:
            # DXFBdr (border properties)
            strm.readUnsignedInt(8)

        if self.ibitAtrPat:
            # DXFPat (pattern and colors)
            strm.readUnsignedInt(4)

        if self.ibitAtrProt:
            # DXFProt (protection attributes)
            strm.readUnsignedInt(2)

    def appendLines (self, hdl):
        # (TODO: This is not complete)
        if self.ibitAtrNum:
            if self.fIfmtUser:
                hdl.appendLine("number format to use: %s (name)"%self.numFmtName)
            else:
                hdl.appendLine("number format to use: %d (ID)"%self.numFmtID)

        if self.fNewBorder:
            s = "only outline of the range"
        else:
            s = "all cells in the range"
        hdl.appendLineString("border formats applied", s)


class DXFN12NoCB(object):

    def __init__ (self, strm):
        self.dxfn = DXFN(strm)

    def appendLines (self, hdl):
        self.dxfn.appendLines(hdl)


class XLStream(globals.ByteStream):

    def __init__ (self, bytes):
        globals.ByteStream.__init__(self, bytes)

    def readXLUnicodeString (self):
        return self.readUnicodeString()

    def readShortXLUnicodeString (self):
        cch = self.readUnsignedInt(1)
        return self.readUnicodeString(cch)

    def readXLUnicodeStringNoCch (self, cch):
        return self.readUnicodeString(cch)

    def readXLUnicodeRichExtendedString (self):
        cch = self.readUnsignedInt(2)
        flags = self.readUnsignedInt(1)
        fHighByte = (flags & 0x01) != 0  # double byte string
        fExtSt    = (flags & 0x04) != 0  # phonetic string data
        fRichSt   = (flags & 0x08) != 0  # rich text

        cRun = 0
        if fRichSt:
            cRun = self.readUnsignedInt(2) # number of elemetns in rgRun

        cbExtRst = 0
        if fExtSt:
            cbExtRst = self.readSignedInt(4) # byte count of ExtRst

        if fHighByte:
            rgb = unicode(self.readBytes(2*cch), 'UTF-16LE', errors='replace')
        elif globals.params.utf8:
            # Compressed Unicode-> latin1
            rgb = self.readBytes(cch).decode('cp1252')
        else:
            # Old behaviour with hex dump
            rgb = self.readBytes(cch)

        # optional FormatRun array.  Ignore this for now.
        self.readBytes(cRun*4) # Each FormatRun is 4-byte long.

        # optional ExtRst.  Ignore this for now.
        self.readBytes(cbExtRst)
        return rgb

    def readLongRGB (self):
        r = self.readUnsignedInt(1)
        g = self.readUnsignedInt(1)
        b = self.readUnsignedInt(1)
        self.readBytes(1) # reserved
        return LongRGB(r, g, b)

    def readICV (self):
        return ICV(self.readUnsignedInt(2))

    def readCFRTID (self):
        return CFRTID(self.readUnsignedInt(2),self.readUnsignedInt(2))

    def readFrtHeader (self):
        return FrtHeader(self.readUnsignedInt(2), self.readUnsignedInt(2))


class BaseRecordHandler(XLStream):

    def __init__ (self, header, size, bytes, strmData, roflist = []):
        XLStream.__init__(self, bytes)
        self.header = header
        self.lines = []
        self.strmData = strmData
        self.roflist = roflist

    def parseBytes (self):
        """Parse the original bytes and generate human readable output.

The derived class should only worry about overwriting this function.  The
bytes are given as self.bytes, and call self.appendLine([new line]) to
append a line to be displayed.
"""
        pass

    def fillModel (self, model):
        """Parse the original bytes and populate the workbook model.

Like parseBytes(), the derived classes must overwrite this method."""
        pass

    def dumpData (self):
        """Parse the original bytes and return the data dump as ('name', {'val1': val1,...})

Like parseBytes(), the derived classes must overwrite this method."""
        pass

    def __getHeaderStr (self):
        return "%4.4Xh: "%self.header

    def output (self):
        headerStr = self.__getHeaderStr()
        print (headerStr + "-"*(globals.OutputWidth-len(headerStr)))
        try:
            self.parseBytes()
            for line in self.lines:
                try:
                    print (headerStr + line)
                except:
                    if not globals.params.catchExceptions:
                        raise
                    print (headerStr + "(xlsrecord:unprintable)")
        except globals.ByteStreamError:
            print(headerStr + "Error interpreting the record!")

    def debug (self, msg):
        print ("%4.4Xh: %s"%(self.header, msg))

    def appendLine (self, line):
        self.lines.append(line)

    def appendMultiLine (self, line):
        charWidth = globals.OutputWidth - len(self.__getHeaderStr())
        singleLine = ''
        testLine = ''
        for word in line.split():
            testLine += word + ' '
            if len(testLine) > charWidth:
                self.lines.append(singleLine)
                testLine = word + ' '
            singleLine = testLine

        if len(singleLine) > 0:
            self.lines.append(singleLine)

    def appendLineString (self, name, value):
        text = "%s: %s"%(name, value)
        self.appendLine(text)

    def appendLineInt (self, name, value):
        text = "%s: %d"%(name, value)
        self.appendLine(text)

    def appendLineBoolean (self, name, value):
        text = "%s: %s"%(name, self.getYesNo(value))
        self.appendLine(text)

    def appendCellPosition (self, col, row):
        text = "cell position: (col: %d; row: %d)"%(col, row)
        self.appendLine(text)

    def getYesNo (self, boolVal):
        if boolVal:
            return 'yes'
        else:
            return 'no'

    def getTrueFalse (self, boolVal):
        if boolVal:
            return 'true'
        else:
            return 'false'

    def getEnabledDisabled (self, boolVal):
        if boolVal:
            return 'enabled'
        else:
            return 'disabled'

    def getBoolVal (self, boolVal, trueStr, falseStr):
        if boolVal:
            return trueStr
        else:
            return falseStr


class AutofilterInfo(BaseRecordHandler):

    def __parseBytes (self):
        self.arrowCount = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("number of autofilter arrows: %d"%self.arrowCount)

    def fillModel (self, model):
        self.__parseBytes()
        sh = model.getCurrentSheet()
        sh.setAutoFilterArrowSize(self.arrowCount)



class Autofilter(BaseRecordHandler):

    class DoperType:
        FilterNotUsed     = 0x00  # filter condition not used
        RKNumber          = 0x02
        Number            = 0x04  # IEEE floating point nubmer
        String            = 0x06
        BooleanOrError    = 0x08
        MatchAllBlanks    = 0x0C
        MatchAllNonBlanks = 0x0E

    compareCodes = [
        '< ', # 01
        '= ', # 02
        '<=', # 03
        '> ', # 04
        '<>', # 05
        '>='  # 06
    ]

    errorCodes = {
        0x00: '#NULL! ',
        0x07: '#DIV/0!',
        0x0F: '#VALUE!',
        0x17: '#REF!  ',
        0x1D: '#NAME? ',
        0x24: '#NUM!  ',
        0x2A: '#N/A   '
    }

    class Doper(object):
        def __init__ (self, dataType=None):
            self.dataType = dataType
            self.sign = None

        def appendLines (self, hdl):
            # data type
            s = '(unknown)'
            if self.dataType == Autofilter.DoperType.RKNumber:
                s = "RK number"
            elif self.dataType == Autofilter.DoperType.Number:
                s = "number"
            elif self.dataType == Autofilter.DoperType.String:
                s = "string"
            elif self.dataType == Autofilter.DoperType.BooleanOrError:
                s = "boolean or error"
            elif self.dataType == Autofilter.DoperType.MatchAllBlanks:
                s = "match all blanks"
            elif self.dataType == Autofilter.DoperType.MatchAllNonBlanks:
                s = "match all non-blanks"
            hdl.appendLine("  data type: %s"%s)

            # comparison code
            if self.sign != None:
                s = globals.getValueOrUnknown(Autofilter.compareCodes, self.sign)
                hdl.appendLine("  comparison code: %s (%d)"%(s, self.sign))


    class DoperRK(Doper):
        def __init__ (self):
            Autofilter.Doper.__init__(self, Autofilter.DoperType.RK)
            self.rkval = None

        def appendLines (self, hdl):
            Autofilter.Doper.appendLines(self, hdl)
            hdl.appendLine("  value: %g"%decodeRK(self.rkval))

    class DoperNumber(Doper):
        def __init__ (self):
            Autofilter.Doper.__init__(self, Autofilter.DoperType.Number)
            self.number = None

        def appendLines (self, hdl):
            Autofilter.Doper.appendLines(self, hdl)
            hdl.appendLine("  value: %g"%self.number)

    class DoperString(Doper):
        def __init__ (self):
            Autofilter.Doper.__init__(self, Autofilter.DoperType.String)
            self.strLen = None

        def appendLines (self, hdl):
            Autofilter.Doper.appendLines(self, hdl)
            if self.strLen != None:
                hdl.appendLine("  string length: %d"%self.strLen)


    class DoperBoolean(Doper):
        def __init__ (self):
            Autofilter.Doper.__init__(self, Autofilter.DoperType.Boolean)
            self.flag = None
            self.value = None

        def appendLines (self, hdl):
            Autofilter.Doper.appendLines(self, hdl)
            hdl.appendLine("  boolean or error: %s"%hdl.getBoolVal(self.flag, "error", "boolean"))
            if self.flag:
                # error value
                hdl.appendLine("  error value: %s (0x%2.2X)"%
                    (globals.getValueOrUnknown(Autofilter.errorCodes, self.value), self.value))
            else:
                # boolean value
                hd.appendLine("  boolean value: %s"%hdl.getTrueFalse(self.value))


    def __readDoper (self):
        vt = self.readUnsignedInt(1)
        if vt == Autofilter.DoperType.RKNumber:
            doper = Autofilter.DoperRK()
            doper.sign = self.readUnsignedInt(1)
            doper.rkval = self.readUnsignedInt(4)
            self.readBytes(4) # ignore 4 bytes
        elif vt == Autofilter.DoperType.Number:
            doper = Autofilter.DoperNumber()
            doper.sign = self.readUnsignedInt(1)
            doper.number = self.readDouble()
        elif vt == Autofilter.DoperType.String:
            doper = Autofilter.DoperString()
            doper.sign = self.readUnsignedInt(1)
            self.readBytes(4) # ignore 4 bytes
            doper.strLen = self.readUnsignedInt(1)
            self.readBytes(3) # ignore 3 bytes
        elif vt == Autofilter.DoperType.BooleanOrError:
            doper = Autofilter.DoperBoolean()
            doper.sign = self.readUnsignedInt(1)
            doper.flag = self.readUnsignedInt(1)
            doper.value = self.readUnsignedInt(1)
            self.readBytes(6) # ignore 6 bytes
        else:
            doper = Autofilter.Doper()
            self.readBytes(9) # ignore the entire 10 bytes
        return doper

    def __parseBytes (self):
        self.filterIndex = self.readUnsignedInt(2)  # column ID?
        flag = self.readUnsignedInt(2)
        self.join    = (flag & 0x0003) # 1 = ANDed  0 = ORed
        self.simple1 = (flag & 0x0004) # 1st condition is simple equality (for optimization)
        self.simple2 = (flag & 0x0008) # 2nd condition is simple equality (for optimization)
        self.top10   = (flag & 0x0010) # top 10 autofilter
        self.top     = (flag & 0x0020) # 1 = top 10 filter shows the top item, 0 = shows the bottom item
        self.percent = (flag & 0x0040) # 1 = top 10 shows percentage, 0 = shows items
        self.itemCount = (flag & 0xFF80) / (2*7)
        self.doper1 = self.__readDoper()
        self.doper2 = self.__readDoper()

        # pick up string(s)
        self.string1 = None
        self.string2 = None
        try:
            if self.doper1.dataType == Autofilter.DoperType.String:
                self.string1 = self.readXLUnicodeStringNoCch(self.doper1.strLen)

            if self.doper2.dataType == Autofilter.DoperType.String:
                self.string2 = self.readXLUnicodeStringNoCch(self.doper2.strLen)
        except:
            pass

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("filter index (relative column ID): %d"%self.filterIndex)
        self.appendLine("joining: %s"%self.getBoolVal(self.join, "AND", "OR"))
        self.appendLineBoolean("1st condition is simple equality", self.simple1)
        self.appendLineBoolean("2nd condition is simple equality", self.simple2)
        self.appendLineBoolean("top 10 autofilter", self.top10)
        if self.top10:
            self.appendLine("top 10 shows: %s"%self.getBoolVal(self.top, "top item", "bottom item"))
            self.appendLine("top 10 shows: %s"%self.getBoolVal(self.percent, "percentage", "items"))
            self.appendLine("top 10 item count: %d"%self.itemCount)

        self.appendLine("1st condition:")
        self.doper1.appendLines(self)
        self.appendLine("2nd condition:")
        self.doper2.appendLines(self)

        if self.string1 != None:
            self.appendLine("string for 1st condition: %s"%self.string1)

        if self.string2 != None:
            self.appendLine("string for 2nd condition: %s"%self.string2)

    def fillModel (self, model):
        self.__parseBytes()
        sh = model.getCurrentSheet()
        obj = xlsmodel.AutoFilterArrow(self.filterIndex)
        obj.isActive = True
        obj.equalString1 = self.string1
        obj.equalString2 = self.string2
        sh.setAutoFilterArrow(self.filterIndex, obj)
        # TODO: Pick up more complex states as we need them.

class EOF(BaseRecordHandler):
    pass

class BOF(BaseRecordHandler):

    Type = {
        0x0005: "Workbook globals",
        0x0006: "Visual Basic module",
        0x0010: "Worksheet or dialog sheet",
        0x0020: "Chart",
        0x0040: "Excel 4.0 macro sheet",
        0x0100: "Workspace file"
    }

    # TODO: Add more build identifiers.
    buildId = {
        0x0DBB: 'Excel 97',
        0x0EDE: 'Excel 97',
        0x2775: 'Excel XP'
    }

    def getBuildIdName (self, value):
        if BOF.buildId.has_key(value):
            return BOF.buildId[value]
        else:
            return '(unknown)'

    def __parseBytes (self):
        # BIFF version
        self.ver = self.readUnsignedInt(2)

        # Substream type
        self.dataType = self.readUnsignedInt(2)

        # build ID and year
        self.buildID = self.readUnsignedInt(2)
        self.buildYear = self.readUnsignedInt(2)

        # file history flags
        try:
            self.flags = self.readUnsignedInt(4)
            self.win     = (self.flags & 0x00000001)
            self.risc    = (self.flags & 0x00000002)
            self.beta    = (self.flags & 0x00000004)
            self.winAny  = (self.flags & 0x00000008)
            self.macAny  = (self.flags & 0x00000010)
            self.betaAny = (self.flags & 0x00000020)
            self.riscAny = (self.flags & 0x00000100)
            self.lowestExcelVer = self.readSignedInt(4)
        except:
            self.flags = 0
            self.win     = 0
            self.risc    = 0
            self.beta    = 0
            self.winAny  = 0
            self.macAny  = 0
            self.betaAny = 0
            self.riscAny = 0
            self.lowestExcelVer = 0
            
    def parseBytes (self):
        self.__parseBytes()
        # BIFF version
        s = 'not BIFF8'
        if self.ver == 0x0600:
            s = 'BIFF8'
        self.appendLine("BIFF version: %s"%s)

        # Substream type
        self.appendLine("type: %s"%BOF.Type[self.dataType])

        # build ID and year
        self.appendLine("build ID: %s (%4.4Xh)"%(self.getBuildIdName(self.buildID), self.buildID))
        self.appendLine("build year: %d"%self.buildYear)

        # file history flags
        self.appendLine("last edited by Excel on Windows: %s"%self.getYesNo(self.win))
        self.appendLine("last edited by Excel on RISC: %s"%self.getYesNo(self.risc))
        self.appendLine("last edited by beta version of Excel: %s"%self.getYesNo(self.beta))
        self.appendLine("has ever been edited by Excel for Windows: %s"%self.getYesNo(self.winAny))
        self.appendLine("has ever been edited by Excel for Macintosh: %s"%self.getYesNo(self.macAny))
        self.appendLine("has ever been edited by beta version of Excel: %s"%self.getYesNo(self.betaAny))
        self.appendLine("has ever been edited by Excel on RISC: %s"%self.getYesNo(self.riscAny))

        self.appendLine("earliest Excel version that can read all records: %d"%self.lowestExcelVer)

    def fillModel (self, model):

        if model.modelType != xlsmodel.ModelType.Workbook:
            return
        self.__parseBytes()

        sheet = model.appendSheet(self.dataType)
        s = 'not BIFF8'
        if self.ver == 0x0600:
            s = 'BIFF8'
        sheet.version = s


    def dumpData(self):
        self.__parseBytes()
        return ('bof', {'ver': self.ver,
                        'data-type': self.dataType,
                        'build-id': self.buildID,
                        'build-year': self.buildYear,
                        'win': self.win,
                        'risc': self.risc,
                        'beta': self.beta,
                        'win-any': self.winAny,
                        'mac-any': self.macAny,
                        'beta-any': self.betaAny,
                        'risc-any': self.riscAny,
                        'lowest-version': self.lowestExcelVer})

class BoundSheet(BaseRecordHandler):

    hiddenStates = {0x00: 'visible', 0x01: 'hidden', 0x02: 'very hidden'}

    sheetTypes = {0x00: 'worksheet or dialog sheet',
                  0x01: 'Excel 4.0 macro sheet',
                  0x02: 'chart',
                  0x06: 'Visual Basic module'}

    @staticmethod
    def getHiddenState (flag):
        if BoundSheet.hiddenStates.has_key(flag):
            return BoundSheet.hiddenStates[flag]
        else:
            return 'unknown'

    @staticmethod
    def getSheetType (flag):
        if BoundSheet.sheetTypes.has_key(flag):
            return BoundSheet.sheetTypes[flag]
        else:
            return 'unknown'

    def __parseBytes (self):
        self.posBOF = self.readUnsignedInt(4)
        flags = self.readUnsignedInt(2)
        textLen = self.readUnsignedInt(1)
        self.name, textLen = globals.getRichText(self.readRemainingBytes(), textLen)
        self.hiddenState = (flags & 0x0003)
        self.sheetType = (flags & 0xFF00)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("BOF position in this stream: %d"%self.posBOF)
        self.appendLine("sheet name: %s"%self.name)
        self.appendLine("hidden state: %s"%BoundSheet.getHiddenState(self.hiddenState))
        self.appendLine("sheet type: %s"%BoundSheet.getSheetType(self.sheetType))

    def fillModel (self, model):
        self.__parseBytes()
        wbglobal = model.getWorkbookGlobal()
        data = xlsmodel.WorkbookGlobal.SheetData()
        data.name = self.name
        data.visible = not self.hiddenState
        wbglobal.appendSheetData(data)


class CF(BaseRecordHandler):

    def __parseBytes (self):
        self.conditionType = self.readUnsignedInt(1)
        self.compFunction = self.readUnsignedInt(1)
        sizeFormula1 = self.readUnsignedInt(2)
        sizeFormula2 = self.readUnsignedInt(2)
        self.rgbdxf = DXFN(self)

        self.formula1 = self.readBytes(sizeFormula1)
        self.formula2 = self.readBytes(sizeFormula2)

    conditionType = {
        0x01: "use comparison function",
        0x02: "use 1st formula"
    }

    compFunction = {
        0x01: "(v1 <= v2 && (v1 <= cell || cell == v2)) || (v2 < v1 && v2 <= cell && cell <= v1)",
        0x02: "v1 <= v2 && (cell < v1 || v2 < cell)",
        0x03: "cell == v1",
        0x04: "cell != v1",
        0x05: "v1 < cell",
        0x06: "cell < v1",
        0x07: "v1 <= cell",
        0x08: "cell <= v1"
    }

    def parseBytes (self):
        self.__parseBytes()

        # condition type
        condTypeName = globals.getValueOrUnknown(CF.conditionType, self.conditionType)
        self.appendLine("condition type: %s (0x%2.2X)"%(condTypeName, self.conditionType))

        # comparison function
        compFuncText = globals.getValueOrUnknown(CF.compFunction, self.compFunction)
        self.appendLine("comparison function: %s (0x%2.2X)"%(compFuncText, self.compFunction))

        self.rgbdxf.appendLines(self)

        # formulas

        if len(self.formula1) > 0:
            self.appendLine("formula 1 (bytes): %s"%globals.getRawBytes(self.formula1, True, False))
            parser = formula.FormulaParser(self.header, self.formula1)
            parser.parse()
            self.appendLine("formula 1 (displayed): " + parser.getText())

        if len(self.formula2) > 0:
            self.appendLine("formula 2 (bytes): %s"%globals.getRawBytes(self.formula2, True, False))
            parser = formula.FormulaParser(self.header, self.formula2)
            parser.parse()
            self.appendLine("formula 2 (displayed): " + parser.getText())


class CondFmt(BaseRecordHandler):

    def __parseBytes (self):
        self.cfCount = self.readUnsignedInt(2)
        tmp = self.readUnsignedInt(2)
        self.toughRecalc = (tmp & 0x01) != 0
        self.recordID = (tmp & 0xFE) / 2
        self.refBound = Ref8U(self)

        hitRangeCount = self.readUnsignedInt(2)
        self.hitRanges = []
        for i in xrange(0, hitRangeCount):
            self.hitRanges.append(Ref8U(self))

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("record count: %d"%self.cfCount)
        self.appendLineBoolean("tough recalc", self.toughRecalc)
        self.appendLine("ID of this record: %d"%self.recordID)
        self.appendLine("format range: (col=%d,row=%d) - (col=%d,row=%d)"%
            (self.refBound.col1, self.refBound.row1, self.refBound.col2, self.refBound.row2))
        for hitRange in self.hitRanges:
            self.appendLine("hit range: (col=%d,row=%d) - (col=%d,row=%d)"%
                (hitRange.col1, hitRange.row1, hitRange.col2, hitRange.row2))

    def fillModel (self, model):
        self.__parseBytes()
        formatRange = formula.CellRange()
        formatRange.firstCol = self.refBound.col1
        formatRange.lastCol  = self.refBound.col2
        formatRange.firstRow = self.refBound.row1
        formatRange.lastRow  = self.refBound.row2
        obj = xlsmodel.CondFormat()
        obj.formatRange = formatRange
        sheet = model.getCurrentSheet()
        sheet.setCondFormat(obj)


class Dimensions(BaseRecordHandler):

    def __parseBytes (self):
        self.rowMin = self.readUnsignedInt(4)
        self.rowMax = self.readUnsignedInt(4)
        self.colMin = self.readUnsignedInt(2)
        self.colMax = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("first defined row: %d"%self.rowMin)
        self.appendLine("last defined row plus 1: %d"%self.rowMax)
        self.appendLine("first defined column: %d"%self.colMin)
        self.appendLine("last defined column plus 1: %d"%self.colMax)

    def fillModel (self, model):
        self.__parseBytes()
        sh = model.getCurrentSheet()
        if not isinstance(sh, xlsmodel.Chart):
            sh.setFirstDefinedCell(self.colMin, self.rowMin)
            sh.setFirstFreeCell(self.colMax, self.rowMax)

    def dumpData(self):
        self.__parseBytes()
        return ('dimensions', {'row-min': self.rowMin,
                               'row-max': self.rowMax,
                               'col-min': self.colMin,
                               'col-max': self.colMax})

class Dv(BaseRecordHandler):

    valueTypes = [
        'any type of value',               # 0x0
        'whole number',                    # 0x1
        'decimal value',                   # 0x2
        'matches one in a list of values', # 0x3
        'date value',                      # 0x4
        'time value',                      # 0x5
        'text value',                      # 0x6
        'custom formula'                   # 0x7
    ]

    errorStyles = [
        'stop icon',       # 0x00
        'warning icon',    # 0x01
        'information icon' # 0x02
    ]

    imeModes = [
        'No Control',              # 0x00
        'On',                      # 0x01
        'Off (English)',           # 0x02
        'Hiragana',                # 0x04
        'wide katakana',           # 0x05
        'narrow katakana',         # 0x06
        'Full-width alphanumeric', # 0x07
        'Half-width alphanumeric', # 0x08
        'Full-width hangul',       # 0x09
        'Half-width hangul'        # 0x0A
    ]

    operatorTypes = [
        'Between',                  # 0x0
        'Not Between',              # 0x1
        'Equals',                   # 0x2
        'Not Equals',               # 0x3
        'Greater Than',             # 0x4
        'Less Than',                # 0x5
        'Greater Than or Equal To', # 0x6
        'Less Than or Equal To'     # 0x7
    ]

    def __parseBytes (self):
        bits = self.readUnsignedInt(4)
        self.valType      = (bits & 0x0000000F)
        self.errStyle     = (bits & 0x00000070) / (2**4)
        self.strLookup    = (bits & 0x00000080) != 0
        self.allowBlank   = (bits & 0x00000100) != 0
        self.noDropDown   = (bits & 0x00000200) != 0
        self.imeMode      = (bits & 0x0003FC00) / (2**10)    # take 8 bits and shift by 10 bits
        self.showInputMsg = (bits & 0x00040000) != 0
        self.showErrorMsg = (bits & 0x00080000) != 0
        self.operator     = (bits & 0x00F00000) / (2**20)

        self.promptTitle = self.readUnicodeString()
        self.errorTitle = self.readUnicodeString()
        self.prompt = self.readUnicodeString()
        self.error = self.readUnicodeString()

        formulaLen = self.readUnsignedInt(2)
        self.readUnsignedInt(2) # ignore 2 bytes.
        self.formula1 = self.readBytes(formulaLen)
        self.strFormula1 = ''
        if len(self.formula1) > 0:
            parser = formula.FormulaParser(self.header, self.formula1)
            parser.parse()
            self.strFormula1 = parser.getText()

        formulaLen = self.readUnsignedInt(2)
        self.readUnsignedInt(2) # ignore 2 bytes.
        self.formula2 = self.readBytes(formulaLen)
        self.strFormula2 = ''
        if len(self.formula2) > 0:
            parser = formula.FormulaParser(self.header, self.formula2)
            parser.parse()
            self.strFormula2 = parser.getText()

        rangeCount = self.readUnsignedInt(2)
        self.ranges = []
        for i in xrange(0, rangeCount):
            obj = formula.CellRange()
            obj.firstRow = self.readUnsignedInt(2)
            obj.lastRow = self.readUnsignedInt(2)
            obj.firstCol = self.readUnsignedInt(2)
            obj.lastCol = self.readUnsignedInt(2)
            self.ranges.append(obj)

    def parseBytes (self):
        self.__parseBytes()
        s = globals.getValueOrUnknown(Dv.valueTypes, self.valType)
        self.appendLine("type: %s (0x%1.1X)"%(s, self.valType))
        s = globals.getValueOrUnknown(Dv.errorStyles, self.errStyle)
        self.appendLine("error style: %s (0x%1.1X)"%(s, self.errStyle))
        self.appendLineBoolean("list of valid inputs", self.strLookup)
        self.appendLineBoolean("allow blank", self.allowBlank)
        self.appendLineBoolean("suppress down-down in cell", self.noDropDown)
        s = globals.getValueOrUnknown(Dv.imeModes, self.imeMode)
        self.appendLine("IME mode: %s (0x%1.1X)"%(s, self.imeMode))
        self.appendLineBoolean("show input message", self.showInputMsg)
        self.appendLineBoolean("show error message", self.showErrorMsg)
        s = globals.getValueOrUnknown(Dv.operatorTypes, self.operator)
        self.appendLine("operator type: %s (0x%1.1X)"%(s, self.operator))
        self.appendLine("prompt title: %s"%self.promptTitle)
        self.appendLine("error title: %s"%self.errorTitle)
        self.appendLine("prompt: %s"%self.prompt)
        self.appendLine("error: %s"%self.error)
        self.appendLine("formula 1 (bytes): %s"%globals.getRawBytes(self.formula1, True, False))
        self.appendLine("formula 1 (displayed): %s"%self.strFormula1)

        self.appendLine("formula 2 (bytes): %s"%globals.getRawBytes(self.formula2, True, False))
        self.appendLine("formula 2 (displayed): %s"%self.strFormula2)

        for rng in self.ranges:
            self.appendLine("range: %s"%rng.getName())

    def fillModel (self, model):
        self.__parseBytes()
        obj = xlsmodel.DataValidation(self.ranges)
        obj.valueType = globals.getValueOrUnknown(Dv.valueTypes, self.valType)
        obj.errorStyle = globals.getValueOrUnknown(Dv.errorStyles, self.errStyle)
        obj.operator = globals.getValueOrUnknown(Dv.operatorTypes, self.operator)
        obj.showInputMsg = self.showInputMsg
        obj.showErrorMsg = self.showErrorMsg
        obj.strLookup = self.strLookup
        obj.allowBlank = self.allowBlank
        obj.prompt = self.prompt
        obj.promptTitle = self.promptTitle
        obj.error = self.error
        obj.errorTitle = self.errorTitle
        obj.formula1 = self.strFormula1
        obj.formula2 = self.strFormula2
        sheet = model.getCurrentSheet()
        sheet.setDataValidation(obj)

class DVal(BaseRecordHandler):

    def __parseBytes (self):
        bits = self.readUnsignedInt(2)
        self.winClosed = (bits & 0x0001) != 0
        self.left = self.readUnsignedInt(4)
        self.top = self.readUnsignedInt(4)
        self.objID = self.readSignedInt(4)
        self.dvCount = self.readUnsignedInt(4)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineBoolean("window was closed", self.winClosed)
        self.appendLine("window position: (x=%d,y=%d)"%(self.left, self.top))
        s = ''
        if self.objID == -1:
            s = '(no drop-down displayed)'
        self.appendLine("drop-down button object ID: %d %s"%(self.objID, s))
        self.appendLine("number of DV records: %d"%self.dvCount)

    def fillModel (self, model):
        self.__parseBytes()

class Fbi(BaseRecordHandler):
    def __parseBytes (self):
        self.fontWidth = self.readUnsignedInt(2)
        self.fontHeight = self.readUnsignedInt(2)
        self.defaultHeight = self.readUnsignedInt(2)
        self.scaleType = self.readUnsignedInt(2)
        self.fontID = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("font width (twips): %d"%self.fontWidth)
        self.appendLine("font height (twips): %d"%self.fontHeight)
        self.appendLine("default font height (twips): %d"%self.defaultHeight)
        if self.scaleType == 0:
            s = "chart area"
        else:
            s = "plot area"
        self.appendLine("scale by: %s"%s)
        self.appendLine("font ID: %d"%self.fontID)

    def dumpData(self):
        self.__parseBytes()
        return ('fbi', {'font-width': self.fontWidth,
                        'font-height': self.fontHeight,
                        'default-height': self.defaultHeight,
                        'scale-type': self.scaleType,
                        'font-id': self.fontID})

class FilePass(BaseRecordHandler):

    def parseBytes (self):
        mode = self.readUnsignedInt(2)    # mode: 0 = BIFF5  1 = BIFF8
        self.readUnsignedInt(2)           # ignore 2 bytes.
        subMode = self.readUnsignedInt(2) # submode: 1 = standard encryption  2 = strong encryption

        modeName = 'unknown'
        if mode == 0:
            modeName = 'BIFF5'
        elif mode == 1:
            modeName = 'BIFF8'

        encType = 'unknown'
        if subMode == 1:
            encType = 'standard'
        elif subMode == 2:
            encType = 'strong'

        self.appendLine("mode: %s"%modeName)
        self.appendLine("encryption type: %s"%encType)
        self.appendLine("")
        self.appendMultiLine("NOTE: Since this document appears to be encrypted, the dumper will not parse the record contents from this point forward.")


class FilterMode(BaseRecordHandler):

    def parseBytes (self):
        self.appendMultiLine("NOTE: The presence of this record indicates that the sheet has a filtered list.")


class Format(BaseRecordHandler):

    def __parseBytes (self):
        self.numfmtID = self.readUnsignedInt(2)
        self.code = self.readUnicodeString()

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("index: %d"%self.numfmtID)
        self.appendLine("code: %s"%globals.encodeName(self.code))


class Formula(BaseRecordHandler):

    def __parseBytes (self):
        self.row = self.readUnsignedInt(2)
        self.col = self.readUnsignedInt(2)
        self.xf = self.readUnsignedInt(2)
        self.fval = self.readDouble()

        flag = self.readUnsignedInt(2)
        self.recalc         = (flag & 0x0001) != 0 # A
        reserved            = (flag & 0x0002) != 0 # B
        self.fillAlignment  = (flag & 0x0004) != 0 # C
        self.sharedFormula  = (flag & 0x0008) != 0 # D
        reserved            = (flag & 0x0010) != 0 # E
        self.clearErrors    = (flag & 0x0020) != 0 # F

        self.appCacheInfo = self.readUnsignedInt(4) # used only for app-specific optimization.  Ignore it for now.
        tokenSize = self.readUnsignedInt(2)
        self.tokens = self.readBytes(tokenSize)

    def parseBytes (self):
        self.__parseBytes()
        fparser = formula.FormulaParser(self.header, self.tokens)
        try:
            fparser.parse()
            ftext = fparser.getText()
        except formula.FormulaParserError as e:
            ftext = "(Error: %s)"%e.args[0]

        self.appendCellPosition(self.col, self.row)
        self.appendLine("XF record ID: %d"%self.xf)
        self.appendLine("formula result: %g"%self.fval)
        self.appendLineBoolean("recalculate always", self.recalc)
        self.appendLineBoolean("fill or center across selection", self.fillAlignment)
        self.appendLineBoolean("shared formula", self.sharedFormula)
        self.appendLineBoolean("clear errors", self.clearErrors)
        self.appendLine("formula bytes: %s"%globals.getRawBytes(self.tokens, True, False))
        self.appendLine("formula string: "+ftext)

    def fillModel (self, model):
        self.__parseBytes()
        sheet = model.getCurrentSheet()
        cell = xlsmodel.FormulaCell()
        cell.tokens = self.tokens
        cell.cachedResult = self.fval
        sheet.setCell(self.col, self.row, cell)


class HorBreaks(BaseRecordHandler):
    """Stores all horizontal breaks in a sheet."""

    def __parseBytes (self):
        self.count = self.readUnsignedInt(2)
        self.breaks = []
        for i in xrange(0, self.count):
            row = self.readUnsignedInt(2)
            col1 = self.readUnsignedInt(2)
            col2 = self.readUnsignedInt(2)
            self.breaks.append((row, col1, col2))

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("count: %d"%self.count)
        for i in xrange(0, self.count):
            self.appendLine("break: (row: %d; colums: %d-%d)"%self.breaks[i])


class Array(BaseRecordHandler):

    def __parseBytes (self):
        self.ref = RefU(self)
        flag = self.readUnsignedInt(2)
        self.alwaysCalc = (flag & 0x0001) != 0
        unused = self.readBytes(4)
        tokenSize = self.readUnsignedInt(2)
        self.tokens = self.readBytes(tokenSize)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("range: %s"%self.ref.toString())
        self.appendLineBoolean("always calc", self.alwaysCalc)
        self.appendLine("formula bytes: %s"%globals.getRawBytes(self.tokens, True, False))
        try:
            fparser = formula.FormulaParser(self.header, self.tokens)
            fparser.parse()
            self.appendLine("formula string: %s"%fparser.getText())
        except formula.FormulaParserError:
            self.appendLine("formula string: <error parsing token bytes>")


class Label(BaseRecordHandler):

    def __parseBytes (self):
        self.col = self.readUnsignedInt(2)
        self.row = self.readUnsignedInt(2)
        self.xfIdx = self.readUnsignedInt(2)
        textLen = self.readUnsignedInt(2)
        self.text, textLen = globals.getRichText(self.readRemainingBytes(), textLen)

    def parseBytes (self):
        self.__parseBytes()
        self.appendCellPosition(self.col, self.row)
        self.appendLine("XF record ID: %d"%self.xfIdx)
        self.appendLine("label text: %s"%self.text)

    def dumpData(self):
        self.__parseBytes()
        return ('label', {'col': self.col,
                          'row': self.row,
                          'xf-idx': self.xfIdx,
                          'text': self.text})

class LabelSST(BaseRecordHandler):

    def __parseBytes (self):
        self.row = self.readUnsignedInt(2)
        self.col = self.readUnsignedInt(2)
        self.xfIdx = self.readUnsignedInt(2)
        self.strId = self.readUnsignedInt(4)

    def parseBytes (self):
        self.__parseBytes()
        self.appendCellPosition(self.col, self.row)
        self.appendLine("XF record ID: %d"%self.xfIdx)
        self.appendLine("string ID in SST: %d"%self.strId)

    def fillModel (self, model):
        self.__parseBytes()
        sheet = model.getCurrentSheet()
        cell = xlsmodel.LabelCell()
        cell.strID = self.strId
        sheet.setCell(self.col, self.row, cell)


class MulRK(BaseRecordHandler):
    class RKRec(object):
        def __init__ (self):
            self.xfIdx = None    # XF record index
            self.number = None   # RK number

    def __parseBytes (self):
        self.row = self.readUnsignedInt(2)
        self.col1 = self.readUnsignedInt(2)
        self.rkrecs = []
        rkCount = (self.getSize() - self.getCurrentPos() - 2) / 6
        for i in xrange(0, rkCount):
            rec = MulRK.RKRec()
            rec.xfIdx = self.readUnsignedInt(2)
            rec.number = self.readUnsignedInt(4)
            self.rkrecs.append(rec)

        self.col2 = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("row: %d"%self.row)
        self.appendLine("columns: %d - %d"%(self.col1, self.col2))
        for rkrec in self.rkrecs:
            self.appendLine("XF record ID: %d"%rkrec.xfIdx)
            self.appendLine("RK number: %g"%decodeRK(rkrec.number))

    def fillModel (self, model):
        self.__parseBytes()
        sheet = model.getCurrentSheet()
        n = len(self.rkrecs)
        for i in xrange(0, n):
            rkrec = self.rkrecs[i]
            col = self.col1 + i
            cell = xlsmodel.NumberCell(decodeRK(rkrec.number))
            sheet.setCell(col, self.row, cell)

class MulBlank(BaseRecordHandler):

    def __parseBytes (self):
        self.row = self.readUnsignedInt(2)
        self.col1 = self.readUnsignedInt(2)
        self.col2 = -1
        self.xfCells = []
        while True:
            val = self.readUnsignedInt(2)
            if self.isEndOfRecord():
                self.col2 = val
                break
            self.xfCells.append(val)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("row: %d"%self.row)
        self.appendLine("columns: %d-%d"%(self.col1, self.col2))
        s = "XF Record IDs:"
        for xfCell in self.xfCells:
            s += " %d"%xfCell
        self.appendMultiLine(s)


class Number(BaseRecordHandler):

    def __parseBytes (self):
        self.row = self.readSignedInt(2)
        self.col = self.readSignedInt(2)
        self.xf = self.readSignedInt(2)
        self.fval = self.readDouble()

    def parseBytes (self):
        self.__parseBytes()
        self.appendCellPosition(self.col, self.row)
        self.appendLine("XF record ID: %d"%self.xf)
        self.appendLine("value: %g"%self.fval)

    def dumpData(self):
        self.__parseBytes()
        return ('number', {'row': self.row,
                           'col': self.col,
                           'xf': self.xf,
                           'fval': self.fval})


class Obj(BaseRecordHandler):

    ftEnd      = 0x00 # End of OBJ record
                      # 0x01 - 0x03 (reserved)
    ftMacro    = 0x04 # Fmla-style macro
    ftButton   = 0x05 # Command button
    ftGmo      = 0x06 # Group marker
    ftCf       = 0x07 # Clipboard format
    ftPioGrbit = 0x08 # Picture option flags
    ftPictFmla = 0x09 # Picture fmla-style macro
    ftCbls     = 0x0A # Check box link
    ftRbo      = 0x0B # Radio button
    ftSbs      = 0x0C # Scroll bar
    ftNts      = 0x0D # Note structure
    ftSbsFmla  = 0x0E # Scroll bar fmla-style macro
    ftGboData  = 0x0F # Group box data
    ftEdoData  = 0x10 # Edit control data
    ftRboData  = 0x11 # Radio button data
    ftCblsData = 0x12 # Check box data
    ftLbsData  = 0x13 # List box data
    ftCblsFmla = 0x14 # Check box link fmla-style macro
    ftCmo      = 0x15 # Common object data

    class Cmo:
        Types = [
            'Group',                   # 0x00
            'Line',                    # 0x01
            'Rectangle',               # 0x02
            'Oval',                    # 0x03
            'Arc',                     # 0x04
            'Chart',                   # 0x05
            'Text',                    # 0x06
            'Button',                  # 0x07
            'Picture',                 # 0x08
            'Polygon',                 # 0x09
            '(Reserved)',              # 0x0A
            'Check box',               # 0x0B
            'Option button',           # 0x0C
            'Edit box',                # 0x0D
            'Label',                   # 0x0E
            'Dialog box',              # 0x0F
            'Spinner',                 # 0x10
            'Scroll bar',              # 0x11
            'List box',                # 0x12
            'Group box',               # 0x13
            'Combo box',               # 0x14
            '(Reserved)',              # 0x15
            '(Reserved)',              # 0x16
            '(Reserved)',              # 0x17
            '(Reserved)',              # 0x18
            'Comment',                 # 0x19
            '(Reserved)',              # 0x1A
            '(Reserved)',              # 0x1B
            '(Reserved)',              # 0x1C
            '(Reserved)',              # 0x1D
            'Microsoft Office drawing' # 0x1E
        ]

        @staticmethod
        def getType (typeID):
            if len(Obj.Cmo.Types) > typeID:
                return Obj.Cmo.Types[typeID]
            return "(unknown) (0x%2.2X)"%typeID

    def parseBytes (self):
        while not self.isEndOfRecord():
            fieldType = self.readUnsignedInt(2)
            fieldSize = self.readUnsignedInt(2)
            if fieldType == Obj.ftEnd:
                # reached the end of OBJ record.
                return

            if fieldType == Obj.ftCmo:
                self.parseCmo(fieldSize)
            else:
                fieldBytes = self.readBytes(fieldSize)
                self.appendLine("field 0x%2.2X: %s"%(fieldType, globals.getRawBytes(fieldBytes, True, False)))

    def parseCmo (self, size):
        if size != 18:
            # size of Cmo must be 18.  Something is wrong here.
            self.readBytes(size)
            globals.error("parsing of common object field in OBJ failed due to invalid size.")
            return

        objType = self.readUnsignedInt(2)
        objID  = self.readUnsignedInt(2)
        flag   = self.readUnsignedInt(2)

        # the rest of the bytes are reserved & should be all zero.
        unused1 = self.readUnsignedInt(4)
        unused2 = self.readUnsignedInt(4)
        unused3 = self.readUnsignedInt(4)

        self.appendLine("common object: ")
        self.appendLine("  type: %s (0x%2.2X)"%(Obj.Cmo.getType(objType), objType))
        self.appendLine("  object ID: %d"%objID)

        # 0    0001h fLocked    =1 if the object is locked when the sheet is protected
        # 3-1  000Eh (Reserved) Reserved; must be 0 (zero)
        # 4    0010h fPrint     =1 if the object is printable
        # 12-5 1FE0h (Reserved) Reserved; must be 0 (zero)
        # 13   2000h fAutoFill  =1 if the object uses automatic fill style
        # 14   4000h fAutoLine  =1 if the object uses automatic line style
        # 15   8000h (Reserved) Reserved; must be 0 (zero)

        locked          = (flag & 0x0001) != 0 # A
                                               # B
        defaultSize     = (flag & 0x0004) != 0 # C
        published       = (flag & 0x0008) != 0 # D
        printable       = (flag & 0x0010) != 0 # E
                                               # F
                                               # G
        disabled        = (flag & 0x0080) != 0 # H
        UIObj           = (flag & 0x0100) != 0 # I
        recalcObj       = (flag & 0x0200) != 0 # J
                                               # K
                                               # L
        recalcObjAlways = (flag & 0x1000) != 0 # M
        autoFill        = (flag & 0x2000) != 0 # N
        autoLine        = (flag & 0x4000) != 0 # O
        self.appendLineBoolean("  locked", locked)
        self.appendLineBoolean("  default size", defaultSize)
        self.appendLineBoolean("  printable", printable)
        self.appendLineBoolean("  automatic fill style", autoFill)
        self.appendLineBoolean("  automatic line style", autoLine)

class PlotGrowth(BaseRecordHandler):

    def __parseBytes (self):
        self.dx = self.readFixedPoint()
        self.dy = self.readFixedPoint()

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("horizontal growth: %g"%self.dx)
        self.appendLine("vertical growth: %g"%self.dy)

    def dumpData(self):
        self.__parseBytes()
        return ('plot-growth', {'dx': self.dx,
                                'dy': self.dy})

class PrintSize(BaseRecordHandler):
    Types = [
        "unchanged from the defaults in the workbook",
        "resized non-proportionally to fill the entire page",
        "resized proportionally to fill the entire page",
        "size defined in the chart record"
    ]

    def __parseBytes (self):
        self.typeID = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine(globals.getValueOrUnknown(PrintSize.Types, self.typeID))

    def dumpData(self):
        self.__parseBytes()
        return ('print-size', {'type-id': self.typeID})

class Protect(BaseRecordHandler):
    def __parseBytes (self):
        self.locked = self.readUnsignedInt(2) != 0

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineBoolean("workbook locked", self.locked)

    def dumpData(self):
        self.__parseBytes()
        return ('protect', {'locked': self.locked})


class RK(BaseRecordHandler):
    """Cell with encoded integer or floating-point value"""

    def __parseBytes (self):
        self.row = globals.getSignedInt(self.bytes[0:2])
        self.col = globals.getSignedInt(self.bytes[2:4])
        self.xf  = globals.getSignedInt(self.bytes[4:6])

        rkval = globals.getSignedInt(self.bytes[6:10])
        self.auxData = RKAuxData()
        self.realVal = decodeRK(rkval, self.auxData)

    def parseBytes (self):
        self.__parseBytes()
        self.appendCellPosition(self.col, self.row)
        self.appendLine("XF record ID: %d"%self.xf)
        self.appendLine("multiplied by 100: %d"%self.auxData.multi100)
        if self.auxData.signedInt:
            self.appendLine("type: signed integer")
        else:
            self.appendLine("type: floating point")
        self.appendLine("value: %g"%self.realVal)

    def fillModel (self, model):
        self.__parseBytes()
        sheet = model.getCurrentSheet()
        cell = xlsmodel.NumberCell(self.realVal)
        sheet.setCell(self.col, self.row, cell)

class Scl(BaseRecordHandler):

    def __parseBytes (self):
        self.numerator = self.readSignedInt(2)
        self.denominator = self.readSignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        val = 0.0 # force the value to be treated as double precision.
        val += self.numerator
        val /= self.denominator
        self.appendLine("zoom level: %g"%val)

    def dumpData(self):
        self.__parseBytes()
        return ('scl', {'numer': self.numerator,
                        'denom': self.denominator})

class SeriesText(BaseRecordHandler):

    def __parseBytes (self):
        self.readBytes(2) # must be zero, ignored.
        self.text = self.readShortXLUnicodeString()

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("text: '%s'"%self.text)


class String(BaseRecordHandler):
    """Cached string formula result for preceding formula record."""

    def __parseBytes (self):
        strLen = globals.getSignedInt(self.bytes[0:1])
        self.name, byteLen = globals.getRichText(self.bytes[2:], strLen)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("string value: '%s'"%self.name)

    def fillModel (self, model):
        self.__parseBytes()
        cell = model.getCurrentSheet().getLastCell()
        if cell.modelType == xlsmodel.CellBase.Type.Formula:
            cell.cachedResult = self.name


class Style(BaseRecordHandler):

    BuiltInStyleNames = [
        "Normal",
        "RowLevel_#",
        "ColLevel_#",
        "Comma",
        "Currency",
        "Percent",
        "Comma[0]",
        "Currency[0]",
        "Hyperlink",
        "Followed Hyperlink",
        "Note",
        "Warning Text"
    ]

    def __parseBytes (self):
        flags = self.readUnsignedInt(2)
        self.Xf = (flags & 0x0FFF)
        self.builtIn = (flags & 0x8000) != 0
        self.builtInType = self.readUnsignedInt(1)
        self.builtInLevel = self.readUnsignedInt(1)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("XF record ID: %d"%self.Xf)
        self.appendLineBoolean("built-in", self.builtIn)
        if self.builtIn:
            self.appendLine("built-in type: %d (%s)"%(
                self.builtInType, globals.getValueOrUnknown(Style.BuiltInStyleNames, self.builtInType)))
            if self.builtInType == 1 or self.builtInType == 2:
                self.appendLine("built-in level: %d"%self.builtInLevel)


class SST(BaseRecordHandler):

    def __parseBytes (self):
        self.refCount = self.readSignedInt(4) # total number of references in workbook
        self.strCount = self.readSignedInt(4) # total number of unique strings.
        self.sharedStrings = []
        for i in xrange(0, self.strCount):
            extText, bytesRead = globals.getUnicodeRichExtText(self.bytes, self.getCurrentPos(), self.roflist)
            self.readBytes(bytesRead) # advance current position.
            self.sharedStrings.append(extText)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("total number of references: %d"%self.refCount)
        self.appendLine("total number of unique strings: %d"%self.strCount)
        i = 0
        for s in self.sharedStrings:
            self.appendLine("s%d: %s"%(i, globals.encodeName(s.baseText)))
            i += 1

    def fillModel (self, model):
        self.__parseBytes()
        wbg = model.getWorkbookGlobal()
        for sst in self.sharedStrings:
            wbg.appendSharedString(sst)


class Blank(BaseRecordHandler):

    def parseBytes (self):
        row = globals.getSignedInt(self.bytes[0:2])
        col = globals.getSignedInt(self.bytes[2:4])
        xf  = globals.getSignedInt(self.bytes[4:6])
        self.appendCellPosition(col, row)
        self.appendLine("XF record ID: %d"%xf)


class DBCell(BaseRecordHandler):

    def parseBytes (self):
        rowRecOffset = self.readUnsignedInt(4)
        self.appendLine("offset to first ROW record: %d"%rowRecOffset)
        while not self.isEndOfRecord():
            cellOffset = self.readUnsignedInt(2)
            self.appendLine("offset to CELL record: %d"%cellOffset)
        return


class DefColWidth(BaseRecordHandler):

    def parseBytes (self):
        w = self.readUnsignedInt(2)
        self.appendLine("default column width (in characters): %d"%w)


class DefRowHeight(BaseRecordHandler):

    def __parseBytes (self):
        flag = self.readUnsignedInt(1)
        self.readUnsignedInt(1) # ignore 1 byte.
        self.unsynced = (flag & 0x01) != 0
        self.dyZero   = (flag & 0x02) != 0
        self.exAsc    = (flag & 0x04) != 0
        self.exDsc    = (flag & 0x08) != 0
        self.rowHeight = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineBoolean("default row height settings changed", self.unsynced)
        self.appendLineBoolean("empty rows have a height of zero", self.dyZero)
        self.appendLineBoolean("empty rows have a thick border style at top", self.exAsc)
        self.appendLineBoolean("empty rows have a thick border style at bottom", self.exDsc)
        if self.dyZero:
            self.appendLine("default height for hidden rows: %d"%self.rowHeight)
        else:
            self.appendLine("default height for empty rows: %d"%self.rowHeight)


class ColInfo(BaseRecordHandler):

    def parseBytes (self):
        colFirst = self.readUnsignedInt(2)
        colLast  = self.readUnsignedInt(2)
        coldx    = self.readUnsignedInt(2)
        ixfe     = self.readUnsignedInt(2)
        flags    = self.readUnsignedInt(2)

        isHidden = (flags & 0x0001)
        outlineLevel = (flags & 0x0700)/4
        isCollapsed = (flags & 0x1000)/4

        self.appendLine("formatted columns: %d - %d"%(colFirst,colLast))
        self.appendLine("column width (in 1/256s of a char): %d"%coldx)
        self.appendLine("XF record index: %d"%ixfe)
        self.appendLine("hidden: %s"%self.getYesNo(isHidden))
        self.appendLine("outline level: %d"%outlineLevel)
        self.appendLine("collapsed: %s"%self.getYesNo(isCollapsed))


class Row(BaseRecordHandler):

    def __parseBytes (self):
        self.row  = self.readUnsignedInt(2)
        self.col1 = self.readUnsignedInt(2)
        self.col2 = self.readUnsignedInt(2)

        flag = self.readUnsignedInt(2)
        self.rowHeight     = (flag & 0x7FFF)
        self.defaultHeight = ((flag & 0x8000) != 0)
        self.irwMac = self.readUnsignedInt(2)

        dummy = self.readUnsignedInt(2)
        flag = self.readUnsignedInt(2)
        self.outLevel   = (flag & 0x0007)
        self.collapsed  = (flag & 0x0010)
        self.zeroHeight = (flag & 0x0020)
        self.unsynced   = (flag & 0x0040)
        self.ghostDirty = (flag & 0x0080)

    def parseBytes (self):
        self.__parseBytes()

        self.appendLine("row: %d; col: %d - %d"%(self.row, self.col1, self.col2))
        self.appendLine("row height (twips): %d"%self.rowHeight)

        if self.defaultHeight:
            self.appendLine("row height type: default")
        else:
            self.appendLine("row height type: custom")

        self.appendLine("optimize flag (0 for BIFF): %d"%self.irwMac)

        self.appendLine("outline level: %d"%self.outLevel)
        self.appendLine("collapsed: %s"%self.getYesNo(self.collapsed))
        self.appendLine("zero height: %s"%self.getYesNo(self.zeroHeight))
        self.appendLine("unsynced: %s"%self.getYesNo(self.unsynced))
        self.appendLine("ghost dirty: %s"%self.getYesNo(self.ghostDirty))

    def fillModel (self, model):
        self.__parseBytes()
        sh = model.getCurrentSheet()
        # store whether or not this row is hidden.
        if self.zeroHeight:
            sh.setRowHidden(self.row)
        sh.setRowHeight(self.row, self.rowHeight)


class Name(BaseRecordHandler):
    """Internal defined name (aka Lbl)"""

    builtInNames = [
        "Consolidate_Area",  # 0x00
        "Auto_Open       ",  # 0x01
        "Auto_Close      ",  # 0x02
        "Extract         ",  # 0x03
        "Database        ",  # 0x04
        "Criteria        ",  # 0x05
        "Print_Area      ",  # 0x06
        "Print_Titles    ",  # 0x07
        "Recorder        ",  # 0x08
        "Data_Form       ",  # 0x09
        "Auto_Activate   ",  # 0x0A
        "Auto_Deactivate ",  # 0x0B
        "Sheet_Title     ",  # 0x0C
        "_FilterDatabase "   # 0x0D
    ]

    funcCategories = [
        'All',              # 00
        'Financial',        # 01
        'DateTime',         # 02
        'MathTrigonometry', # 03
        'Statistical',      # 04
        'Lookup',           # 05
        'Database',         # 06
        'Text',             # 07
        'Logical',          # 08
        'Info',             # 09
        'Commands',         # 10
        'Customize',        # 11
        'MacroControl',     # 12
        'DDEExternal',      # 13
        'UserDefined',      # 14
        'Engineering',      # 15
        'Cube'              # 16
    ]

    @staticmethod
    def getBuiltInName (name):
        return globals.getValueOrUnknown(Name.builtInNames, ord(name[0]))

    @staticmethod
    def getFuncCategory (val):
        return globals.getValueOrUnknown(Name.funcCategories, val)

    def __writeOptionFlags (self):
        self.appendLine("option flags:")

        if self.isHidden:
            self.appendLine("  hidden")
        else:
            self.appendLine("  visible")

        if self.isMacroName:
            self.appendLine("  macro name")
            if self.isFuncMacro:
                self.appendLine("  function macro")
                self.appendLine("  function group: %d"%self.funcGrp)
            else:
                self.appendLine("  command macro")
            if self.isVBMacro:
                self.appendLine("  visual basic macro")
            else:
                self.appendLine("  sheet macro")
        else:
            self.appendLine("  standard name")

        if self.isComplFormula:
            self.appendLine("  complex formula - can return an array")
        else:
            self.appendLine("  simple formula")
        if self.isBuiltinName:
            self.appendLine("  built-in name")
        else:
            self.appendLine("  user-defined name")

        self.appendLineBoolean("  published", self.isPublished)
        self.appendLineBoolean("  workbook parameter", self.isWorkbookParam)


    def __parseBytes (self):
        flag = self.readUnsignedInt(2)
        self.isHidden        = (flag & 0x0001) != 0
        self.isFuncMacro     = (flag & 0x0002) != 0
        self.isVBMacro       = (flag & 0x0004) != 0
        self.isMacroName     = (flag & 0x0008) != 0
        self.isComplFormula  = (flag & 0x0010) != 0
        self.isBuiltinName   = (flag & 0x0020) != 0
        self.funcGrp         = (flag & 0x0FC0) / 64
        reserved             = (flag & 0x1000) != 0
        self.isPublished     = (flag & 0x2000) != 0
        self.isWorkbookParam = (flag & 0x4000) != 0
        reserved             = (flag & 0x8000) != 0

        self.keyShortCut      = self.readUnsignedInt(1)
        nameLen               = self.readUnsignedInt(1)
        self.formulaLen       = self.readUnsignedInt(2)
        self.readUnsignedInt(2) # 2-bytes reserved

        # 1-based index into the sheets in the current book, where the list is
        # arranged by the visible order of the tabs.
        self.sheetId = self.readUnsignedInt(2)

        # these optional texts may come after the formula token bytes.
        # NOTE: [MS-XLS] spec says these bytes are reserved and to be ignored.
        self.menuTextLen = self.readUnsignedInt(1)
        self.descTextLen = self.readUnsignedInt(1)
        self.helpTextLen = self.readUnsignedInt(1)
        self.statTextLen = self.readUnsignedInt(1)

        pos = self.getCurrentPos()
        self.name, byteLen = globals.getRichText(self.bytes[pos:], nameLen)
        self.readBytes(byteLen)
        self.tokenBytes = self.readBytes(self.formulaLen)

    def parseBytes (self):
        self.__parseBytes()

        self.appendLine("name: %s"%globals.encodeName(self.name))

        # is this name global or sheet-local?
        s = "global or local: "
        if self.sheetId == 0:
            s += "global"
        else:
            s += "local (1-based sheet ID = %d)"%self.sheetId
        self.appendLine(s)

        if self.isBuiltinName:
            self.appendLine("built-in name: %s"%Name.getBuiltInName(self.name))

        self.appendLine("function category: %s (%d)"%(Name.getFuncCategory(self.funcGrp), self.funcGrp))
        self.__writeOptionFlags()

#       self.appendLine("menu text length: %d"%self.menuTextLen)
#       self.appendLine("description length: %d"%self.descTextLen)
#       self.appendLine("help tip text length: %d"%self.helpTextLen)
#       self.appendLine("status bar text length: %d"%self.statTextLen)

        tokenText = globals.getRawBytes(self.tokenBytes, True, False)
        o = formula.FormulaParser(self.header, self.tokenBytes)
        self.appendLine("formula length: %d"%self.formulaLen)
        self.appendLine("formula bytes: " + tokenText)
        try:
            o.parse()
            formulaText = o.getText()
            self.appendLine("formula: " + formulaText)
        except formula.FormulaParserError as e:
            self.appendLine("Error while parsing the formula tokens (%s)"%e.args[0])



    def fillModel (self, model):
        self.__parseBytes()

        wbg = model.getWorkbookGlobal()
        if self.isBuiltinName and len(self.name) == 1 and ord(self.name[0]) == 0x0D:
            # Pick up a database range for autofilter.
            wbg.setFilterRange(self.sheetId-1, self.tokenBytes)


class SupBook(BaseRecordHandler):
    """Supporting workbook"""

    class Type:
        Self  = 0x0401
        AddIn = 0x3A01

    def __parseBytes (self):
        self.ctab = self.readUnsignedInt(2)
        self.sbType = self.readUnsignedInt(2)

        if self.sbType > 0x00FF or self.sbType == 0x0000:
            return

        self.names = []
        isFirst = True
        self.moveBack(2)
        pos = self.getCurrentPos()
        while pos < self.size:
            ret, bytesLen = globals.getUnicodeRichExtText(self.bytes, pos)
            name = ret.baseText
            self.moveForward(bytesLen)
            self.names.append(name)
            pos = self.getCurrentPos()

    def parseBytes (self):
        self.__parseBytes()
        if self.sbType == SupBook.Type.Self:
            # self-referencing supbook
            self.appendLine("type: self-referencing")
            self.appendLine("sheet name count: %d"%self.ctab)
            return

        if self.sbType == SupBook.Type.AddIn:
            self.appendLine("type: add-in referencing")
            self.appendMultiLine("Add-in function name stored in the following EXTERNNAME record.")
            return

        self.appendLine("sheet name count: %d"%self.ctab)
        if len(self.names) == 0:
            return

        self.appendLine("document URL: %s"%globals.encodeName(self.names[0]))
        for name in self.names[1:]:
            name = globals.encodeName(name)
            self.appendLine("sheet name: %s"%name)

    def fillModel (self, model):
        self.__parseBytes()
        wbg = model.getWorkbookGlobal()
        if self.sbType == SupBook.Type.Self:
            sb = xlsmodel.SupbookSelf(self.ctab)
            wbg.appendSupbook(sb)
        elif self.sbType == SupBook.Type.AddIn:
            # generic supbook instance just to keep the indices in sync.
            wbg.appendSupbook(xlsmodel.Supbook())
        else:
            # external document supbook
            sb = xlsmodel.SupbookExternal()
            sb.docURL = self.names[0]
            for name in self.names[1:]:
                sb.appendSheetName(name)
            wbg.appendSupbook(sb)


class ExternSheet(BaseRecordHandler):

    def __parseBytes (self):
        self.sheets = []
        num = self.readUnsignedInt(2)
        for i in xrange(0, num):
            book = self.readUnsignedInt(2)
            sheet1 = self.readUnsignedInt(2)
            sheet2 = self.readUnsignedInt(2)
            self.sheets.append((book, sheet1, sheet2))

    def parseBytes (self):
        self.__parseBytes()
        for sh in self.sheets:
            self.appendLine("SUPBOOK record ID: %d  (sheet ID range: %d - %d)"%(sh[0], sh[1], sh[2]))

    def fillModel (self, model):
        self.__parseBytes()
        wbg = model.getWorkbookGlobal()
        for sh in self.sheets:
            wbg.appendExternSheet(sh[0], sh[1], sh[2])


class ExternName(BaseRecordHandler):

    class MOper(object):
        Errors = {
            0x00: '#NULL!' ,
            0x07: '#DIV/0!',
            0x0F: '#VALUE!',
            0x17: '#REF!'  ,
            0x1D: '#NAME?' ,
            0x24: '#NUM!'  ,
            0x2A: '#N/A'
        }

        def __init__ (self, bytes):
            self.strm = globals.ByteStream(bytes)

        def parse (self):
            self.lastCol = self.strm.readUnsignedInt(1)
            self.lastRow = self.strm.readUnsignedInt(2)
            self.values = []
            n = (self.lastCol+1)*(self.lastRow+1)
            for i in xrange(0, n):
                # parse each value
                oc = self.strm.readUnsignedInt(1)
                if oc == 0x01:
                    # number
                    val = self.strm.readDouble()
                    self.values.append(val)
                elif oc == 0x02:
                    # string
                    s = self.strm.readUnicodeString()
                    self.values.append(s)
                elif oc == 0x04:
                    # boolean
                    b = self.strm.readUnsignedInt(1) != 0
                    self.strm.readBytes(7)
                    self.values.append(b)
                elif oc == 0x10:
                    # error
                    err = self.strm.readUnsignedInt(1)
                    self.strm.readBytes(7)
                    self.values.append(err)
                else:
                    # null value
                    self.strm.readBytes(8)
                    self.values.append(None)

        def output (self, hdl):
            hdl.appendLine("last column: %d"%self.lastCol)
            hdl.appendLine("last row: %d"%self.lastRow)
            for value in self.values:
                if type(value) == type(0.0):
                    hdl.appendLine("value: %g"%value)
                elif type(value) == type("s"):
                    hdl.appendLine("value: %s"%value)
                elif type(value) == type(True):
                    hdl.appendLine("value: %d (boolean)"%value)
                elif type(value) == type(1):
                    # error code stored as an integer.
                    if ExternName.MOper.Errors.has_key(value):
                        hdl.appendLine("value: %s"%ExternName.MOper.Errors[value])
                    else:
                        hdl.appendLine("value: 0x%2.2X (unknown error)"%value)
                else:
                    hdl.appendLine("value: (unknown)")

    def __parseBytes (self):
        flag = self.readUnsignedInt(2)

        self.isBuiltinName = (flag & 0x0001) != 0
        self.automatic     = (flag & 0x0002) != 0
        self.wantPict      = (flag & 0x0004) != 0
        self.isOLE         = (flag & 0x0008) != 0
        self.isOLELink     = (flag & 0x0010) != 0

        # 5 - 14 bits stores last successful clip format
        self.clipFormat    = (flag & 0x7FE0) / 2**5

        self.displayAsIcon = (flag & 0x8000) != 0

        if self.isOLELink:
            # next 4 bytes are 32-bit storage ID
            self.storageID = self.readUnsignedInt(4)
            nameLen = self.readUnsignedInt(1)
            self.name = self.readUnicodeString(nameLen)
            self.moper = self.readRemainingBytes()
        else:
            # assume external defined name (could be DDE link).
            # TODO: differentiate DDE link from external defined name.

            self.supbookID = self.readUnsignedInt(2)
            reserved = self.readUnsignedInt(2)
            nameLen = self.readUnsignedInt(1)
            self.name = self.readUnicodeString(nameLen)
            self.tokens = self.readRemainingBytes()

    def parseBytes (self):
        self.__parseBytes()

        self.appendLineBoolean("built-in name", self.isBuiltinName)
        self.appendLineBoolean("auto DDE or OLE", self.automatic)
        self.appendLineBoolean("use picture format", self.wantPict)
        self.appendLineBoolean("OLE", self.isOLE)
        self.appendLineBoolean("OLE Link", self.isOLELink)
        self.appendLine("clip format: %d"%self.clipFormat)
        self.appendLineBoolean("display as icon", self.displayAsIcon)

        if self.isOLELink:
            self.appendLine("type: OLE")
            self.appendLine("storage ID: 0x%4.4X"%self.storageID)
            self.appendLine("name: %s"%self.name)
            if len(self.moper) > 0:
                try:
                    parser = ExternName.MOper(self.moper)
                    parser.parse()
                    parser.output(self)
                except:
                    self.appendLine("Error while parsing the moper bytes.")
        else:
            # TODO: Test this.
            self.appendLine("type: defined name")
            if self.supbookID == 0:
                self.appendLine("sheet ID: 0 (global defined names)")
            else:
                self.appendLine("sheet ID: %d"%self.supbookID)

            self.appendLine("name: %s"%self.name)
            tokenText = globals.getRawBytes(self.tokens, True, False)
            self.appendLine("formula bytes: %s"%tokenText)

            # parse formula tokens
            o = formula.FormulaParser(self.header, self.tokens)
            o.parse()
            ftext = o.getText()
            self.appendLine("formula: %s"%ftext)

class Xct(BaseRecordHandler):

    def __parseBytes (self):
        self.crnCount = self.readSignedInt(2)
        self.sheetIndex = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("CRN count: %d"%self.crnCount)
        self.appendLine("index of referenced sheet in the SUPBOOK record: %d"%self.sheetIndex)

    def fillModel (self, model):
        self.__parseBytes()
        sb = model.getWorkbookGlobal().getLastSupbook()
        # this must be an external document supbook.
        if sb.type != xlsmodel.Supbook.Type.External:
            return
        sb.setCurrentSheet(self.sheetIndex)


class Crn(BaseRecordHandler):

    def __parseBytes (self):
        self.lastCol = self.readUnsignedInt(1)
        self.firstCol = self.readUnsignedInt(1)
        self.rowIndex = self.readUnsignedInt(2)
        self.cells = []
        for i in xrange(0, self.lastCol-self.firstCol+1):
            typeId = self.readUnsignedInt(1)
            if typeId == 0x00:
                # empty value
                self.readBytes(8)
                self.cells.append((typeId, None))
            elif typeId == 0x01:
                # number
                val = self.readDouble()
                self.cells.append((typeId, val))
            elif typeId == 0x02:
                # string
                pos = self.getCurrentPos()
                ret, length = globals.getUnicodeRichExtText(self.bytes, pos)
                text = ret.baseText
                text = globals.encodeName(text)
                self.moveForward(length)
                self.cells.append((typeId, text))
            elif typeId == 0x04:
                # boolean
                val = self.readUnsignedInt(1)
                self.readBytes(7) # next 7 bytes not used
                self.cells.append((typeId, val))
            elif typeId == 0x10:
                # error value
                val = self.readUnsignedInt(1)
                self.readBytes(7) # next 7 bytes not used
                self.cells.append((typeId, val))
            else:
                globals.error("error parsing CRN record\n")
                sys.exit(1)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("first column: %d"%self.firstCol)
        self.appendLine("last column:  %d"%self.lastCol)
        self.appendLine("row index: %d"%self.rowIndex)

        for cell in self.cells:
            typeId, val = cell[0], cell[1]
            if typeId == 0x00:
                # empty value
                self.appendLine("* empty value")
            elif typeId == 0x01:
                # number
                self.appendLine("* numeric value (%g)"%val)
            elif typeId == 0x02:
                # string
                self.appendLine("* string value (%s)"%val)
            elif typeId == 0x04:
                # boolean
                self.appendLine("* boolean value (%d)"%val)
            elif typeId == 0x10:
                # error value
                self.appendLine("* error value (%d)"%val)
            else:
                error("error parsing CRN record\n")
                sys.exit(1)

    def fillModel (self, model):
        self.__parseBytes()
        sb = model.getWorkbookGlobal().getLastSupbook()
        # this must be an external document supbook.
        if sb.type != xlsmodel.Supbook.Type.External:
            return
        cache = sb.getCurrentSheetCache()
        for col in xrange(self.firstCol, self.lastCol+1):
            cell = self.cells[col-self.firstCol]
            typeId, val = cell[0], cell[1]
            cache.setValue(self.rowIndex, col, typeId, val)


class RefreshAll(BaseRecordHandler):

    def parseBytes (self):
        boolVal = globals.getSignedInt(self.bytes[0:2])
        strVal = "no"
        if boolVal:
            strVal = "yes"
        self.appendLine("refresh all external data ranges and pivot tables: %s"%strVal)


class Hyperlink(BaseRecordHandler):

    def parseBytes (self):
        rowFirst = self.readUnsignedInt(2)
        rowLast = self.readUnsignedInt(2)
        colFirst = self.readUnsignedInt(2)
        colLast = self.readUnsignedInt(2)
        # Rest of the stream stores undocumented hyperlink stream.  Refer to
        # page 128 of MS Excel binary format spec.
        self.appendLine("rows: %d - %d"%(rowFirst, rowLast))
        self.appendLine("columns: %d - %d"%(colFirst, colLast))
        msg  = "NOTE: The stream after the first 8 bytes stores undocumented hyperlink stream.  "
        msg += "Refer to page 128 of the MS Excel binary format spec."
        self.appendLine('')
        self.appendMultiLine(msg)


class PhoneticInfo(BaseRecordHandler):

    phoneticType = [
        'narrow Katakana', # 0x00
        'wide Katakana',   # 0x01
        'Hiragana',        # 0x02
        'any type'         # 0x03
    ]

    @staticmethod
    def getPhoneticType (flag):
        return globals.getValueOrUnknown(PhoneticInfo.phoneticType, flag)

    alignType = [
        'general alignment',    # 0x00
        'left aligned',         # 0x01
        'center aligned',       # 0x02
        'distributed alignment' # 0x03
    ]

    @staticmethod
    def getAlignType (flag):
        return globals.getValueOrUnknown(PhoneticInfo.alignType, flag)

    def parseBytes (self):
        fontIdx = self.readUnsignedInt(2)
        self.appendLine("font ID: %d"%fontIdx)
        flags = self.readUnsignedInt(1)

        # flags: 0 0 0 0 0 0 0 0
        #       | unused| B | A |

        phType    = (flags)   & 0x03
        alignType = (flags/4) & 0x03

        self.appendLine("phonetic type: %s"%PhoneticInfo.getPhoneticType(phType))
        self.appendLine("alignment: %s"%PhoneticInfo.getAlignType(alignType))

        self.readUnsignedInt(1) # unused byte

        # TODO: read cell ranges.

        return


class Font(BaseRecordHandler):

    fontFamilyNames = [
        'not applicable', # 0x00
        'roman',          # 0x01
        'swiss',          # 0x02
        'modern',         # 0x03
        'script',         # 0x04
        'decorative'      # 0x05
    ]

    @staticmethod
    def getFontFamily (code):
        return globals.getValueOrUnknown(Font.fontFamilyNames, code)

    scriptNames = [
        'normal script',
        'superscript',
        'subscript'
    ]

    @staticmethod
    def getScriptName (code):
        return globals.getValueOrUnknown(Font.scriptNames, code)


    underlineTypes = {
        0x00: 'no underline',
        0x01: 'single underline',
        0x02: 'double underline',
        0x21: 'single accounting',
        0x22: 'double accounting'
    }

    @staticmethod
    def getUnderlineStyleName (val):
        return globals.getValueOrUnknown(Font.underlineTypes, val)

    charSetNames = {
        0x00: 'ANSI_CHARSET',
        0x01: 'DEFAULT_CHARSET',
        0x02: 'SYMBOL_CHARSET',
        0x4D: 'MAC_CHARSET',
        0x80: 'SHIFTJIS_CHARSET',
        0x81: 'HANGEUL_CHARSET',
        0x81: 'HANGUL_CHARSET',
        0x82: 'JOHAB_CHARSET',
        0x86: 'GB2312_CHARSET',
        0x88: 'CHINESEBIG5_CHARSET',
        0xA1: 'GREEK_CHARSET',
        0xA2: 'TURKISH_CHARSET',
        0xA3: 'VIETNAMESE_CHARSET',
        0xB1: 'HEBREW_CHARSET',
        0xB2: 'ARABIC_CHARSET',
        0xBA: 'BALTIC_CHARSET',
        0xCC: 'RUSSIAN_CHARSET',
        0xDD: 'THAI_CHARSET',
        0xEE: 'EASTEUROPE_CHARSET'
    }

    @staticmethod
    def getCharSetName (code):
        return globals.getValueOrUnknown(Font.charSetNames, code)

    def parseBytes (self):
        height     = self.readUnsignedInt(2)
        flags      = self.readUnsignedInt(2)
        colorId    = self.readUnsignedInt(2)

        boldStyle  = self.readUnsignedInt(2)
        boldStyleName = '(unknown)'
        if boldStyle == 400:
            boldStyleName = 'normal'
        elif boldStyle == 700:
            boldStyleName = 'bold'

        superSub   = self.readUnsignedInt(2)
        ulStyle    = self.readUnsignedInt(1)
        fontFamily = self.readUnsignedInt(1)
        charSet    = self.readUnsignedInt(1)
        reserved   = self.readUnsignedInt(1)
        nameLen    = self.readUnsignedInt(1)
        fontName, nameLen = globals.getRichText(self.readRemainingBytes(), nameLen)
        self.appendLine("font height: %d"%height)
        self.appendLine("color ID: %d"%colorId)
        self.appendLine("bold style: %s (%d)"%(boldStyleName, boldStyle))
        self.appendLine("script type: %s"%Font.getScriptName(superSub))
        self.appendLine("underline type: %s"%Font.getUnderlineStyleName(ulStyle))
        self.appendLine("character set: %s"%Font.getCharSetName(charSet))
        self.appendLine("font family: %s"%Font.getFontFamily(fontFamily))
        self.appendLine("font name: %s (%d)"%(fontName, nameLen))

class Window2(BaseRecordHandler):
    def __parseBytes (self):
        flag = self.readUnsignedInt(2)
        self.displayFormula =  (flag & 0x0001) != 0
        self.displayGrid =     (flag & 0x0002) != 0
        self.displayHeadings = (flag & 0x0004) != 0
        self.frozen =          (flag & 0x0008) != 0

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineBoolean("display formula", self.displayFormula)
        self.appendLineBoolean("display grid", self.displayGrid)
        self.appendLineBoolean("display headings", self.displayHeadings)
        self.appendLineBoolean("frozen window", self.frozen)

class Pane(BaseRecordHandler):

    activePanes = [
        "bottom-right",
        "top-right",
        "bottom-left",
        "top-left"
    ]

    def __parseBytes (self):
        self.x = self.readUnsignedInt(2)
        self.y = self.readUnsignedInt(2)
        self.bottomRow = self.readUnsignedInt(2)
        self.rightCol  = self.readUnsignedInt(2)
        self.activePane = self.readUnsignedInt(1)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("split position: (x=%d,y=%d)"%(self.x,self.y))
        self.appendLine("top-left position of SE pane: (row=%d,col=%d)"%
            (self.bottomRow,self.rightCol))
        self.appendLine("active pane: %s"%
            globals.getValueOrUnknown(Pane.activePanes, self.activePane))

class XF(BaseRecordHandler):

    horAlignTypes = [
        '',                                  #            0x00
        'left alignment',                    # ALCLEFT    0x01
        'centered alignment',                # ALCCTR     0x02
        'right alignment',                   # ALCRIGHT   0x03
        'fill alignment',                    # ALCFILL    0x04
        'justify alignment',                 # ALCJUST    0x05
        'center-across-selection alignment', # ALCCONTCTR 0x06
        'distributed alignment',             # ALCDIST    0x07
        'alignment not specified'            # ALCNIL     0xFF
    ]

    vertAlignTypes = [
        'top alignment',        # ALCVTOP  0x00
        'center alignment',     # ALCVCTR  0x01
        'bottom alignment',     # ALCVBOT  0x02
        'justify alignment',    # ALCVJUST 0x03
        'distributed alignment' # ALCVDIST 0x04
    ]

    readOrderTypes = [
        'context',       # READING_ORDER_CONTEXT 0x00
        'left-to-right', # READING_ORDER_LTR     0x01
        'right-to-left'  # READING_ORDER_RTL     0x02
    ]

    borderStyles = [
        ['NONE','No border'],                             # 0x0000
        ['THIN','Thin line'],                             # 0x0001
        ['MEDIUM','Medium line'],                         # 0x0002
        ['DASHED','Dashed line'],                         # 0x0003
        ['DOTTED','Dotted line'],                         # 0x0004
        ['THICK','Thick line'],                           # 0x0005
        ['DOUBLE','Double line'],                         # 0x0006
        ['HAIR','Hairline'],                              # 0x0007
        ['MEDIUMDASHED','Medium dashed line'],            # 0x0008
        ['DASHDOT','Dash-dot line'],                      # 0x0009
        ['MEDIUMDASHDOT','Medium dash-dot line'],         # 0x000A
        ['DASHDOTDOT','Dash-dot-dot line'],               # 0x000B
        ['MEDIUMDASHDOTDOT','Medium dash-dot-dot line'],  # 0x000C
        ['SLANTDASHDOT','Slanted dash-dot-dot line']      # 0x000D
    ]

    @staticmethod
    def printBorderStyle (val):
        if val >= len(XF.borderStyles):
            return '(unknown)'

        return "%s - %s (0x%2.2X)"%(XF.borderStyles[val][0], XF.borderStyles[val][1], val)

    class XFBase(object):
        def __init__ (self):
            pass

        def parseHeaderBytes (self, strm):
            byte = strm.readUnsignedInt(1)
            self.horAlign = (byte & 0x07)
            self.wrapText = (byte & 0x08) != 0
            self.verAlign = (byte & 0x70) / (2**4)
            self.distributed = (byte & 0x80) != 0
            self.textRotation = strm.readUnsignedInt(1)
            byte = strm.readUnsignedInt(1)
            self.indentLevel = (byte & 0x0F)
            self.shrinkToFit = (byte & 0x10) != 0
            self.readOrder   = (byte & 0xC0) / (2**6)

        def parseBorderStyles (self, strm):
            byte = strm.readUnsignedInt(1)
            self.leftBdrStyle   = (byte & 0x0F)
            self.rightBdrStyle  = (byte & 0xF0) / (2**4)
            byte = strm.readUnsignedInt(1)
            self.topBdrStyle    = (byte & 0x0F)
            self.bottomBdrStyle = (byte & 0xF0) / (2**4)

    class CellXF(XFBase):
        def __init__ (self):
            pass

        def parseBytes (self, strm):
            self.parseHeaderBytes(strm)
            byte = strm.readUnsignedInt(1)
            self.atrNum  = (byte & 0x04) != 0
            self.atrFnt  = (byte & 0x08) != 0
            self.atrAlc  = (byte & 0x10) != 0
            self.atrBdr  = (byte & 0x20) != 0
            self.atrPat  = (byte & 0x40) != 0
            self.atrProt = (byte & 0x80) != 0
            self.parseBorderStyles(strm)

    class CellStyleXF(XFBase):
        def __init__ (self):
            pass

        def parseBytes (self, strm):
            self.parseHeaderBytes(strm)
            strm.readUnsignedInt(1) # skip 1 byte.
            self.parseBorderStyles(strm)
            byte = strm.readUnsignedInt(2)
            self.leftColor  = (byte & 0x007F)           # 7-bits
            self.rightColor = (byte & 0x0780) / (2**7)  # 7-bits
            self.diagBorder = (byte & 0xC000) / (2**14) # 2-bits


    def __parseBytes (self):
        self.fontId = self.readUnsignedInt(2)
        self.numId = self.readUnsignedInt(2)
        flags = self.readUnsignedInt(2)
        self.locked = (flags & 0x0001) != 0
        self.hidden = (flags & 0x0002) != 0
        self.style  = (flags & 0x0004) != 0
        self.prefix = (flags & 0x0008) != 0

        # ID of cell style XF record which it inherits styles from.  Should be
        # 0xFFF it the style flag is on.
        self.cellStyleXFIndex = (flags & 0xFFF0) / (2**4)

        if self.style:
            self.data = XF.CellStyleXF()
            self.data.parseBytes(self)
        else:
            self.data = XF.CellXF()
            self.data.parseBytes(self)


    def parseBytes (self):
        self.__parseBytes()
        if self.style:
            self.appendLine("parent style ID: 0x%2.2X (should be 0xFFF for cell style XF)"%self.cellStyleXFIndex)
        else:
            self.appendLine("parent style ID: %d"%self.cellStyleXFIndex)
        self.appendLine("font ID: %d"%self.fontId)
        self.appendLine("number format ID: %d"%self.numId)
        self.appendLineBoolean("locked protection", self.locked)
        self.appendLineBoolean("hidden protection", self.hidden)
        self.appendLineBoolean("prefix characters present", self.prefix)

        s = "cell XF"
        if self.style:
            s = "cell style XF"
        self.appendLine("stored data type: " + s)

        # common data between cell XF and cell style XF

        # Horizontal alignment
        horAlignName = globals.getValueOrUnknown(
            XF.horAlignTypes[:-1], self.data.horAlign, 'not specified')
        self.appendLine("horizontal alignment: %s (0x%2.2X)"%(horAlignName, self.data.horAlign))
        self.appendLineBoolean("distributed", self.data.distributed)

        self.appendLineBoolean("wrap text", self.data.wrapText)

        # Vertical alignment
        verAlignName = globals.getValueOrUnknown(
            XF.vertAlignTypes, self.data.verAlign, 'unknown')
        self.appendLine("vertical alignment: %s (0x%2.2X)"%(verAlignName, self.data.verAlign))

        # Text rotation
        s = "text rotation: "
        if self.data.textRotation == 0xFF:
            s += "vertical"
        elif self.data.textRotation >= 0 and self.data.textRotation <= 90:
            s += "%d degrees (counterclockwise)"%self.data.textRotation
        elif self.data.textRotation > 90 and self.data.textRotation <= 180:
            s += "%d degrees (clockwise)"%(self.data.textRotation - 90)
        self.appendLine(s)

        self.appendLine("indent level: %d"%self.data.indentLevel)
        self.appendLineBoolean("shrink to fit", self.data.shrinkToFit)
        self.appendLine("reading order: %s"%globals.getValueOrUnknown(XF.readOrderTypes, self.data.readOrder))

        self.appendLine("border style (l): %s"%XF.printBorderStyle(self.data.leftBdrStyle))
        self.appendLine("border style (r): %s"%XF.printBorderStyle(self.data.rightBdrStyle))
        self.appendLine("border style (t): %s"%XF.printBorderStyle(self.data.topBdrStyle))
        self.appendLine("border style (b): %s"%XF.printBorderStyle(self.data.bottomBdrStyle))

        if self.style:
            # cell style XF data
            pass
        else:
            # cell XF data
            pass


class SharedFeatureType(object):

    ISFPROTECTION = 0x0002
    ISFFEC2       = 0x0003
    ISFFACTOID    = 0x0004
    ISFLIST       = 0x0005

    @staticmethod
    def toString (val):
        if val == SharedFeatureType.ISFPROTECTION:
            return "ISFPROTECTION (enhanced protection)"
        elif val == SharedFeatureType.ISFFEC2:
            return "ISFFEC2 (ignore formula errors)"
        elif val == SharedFeatureType.ISFFACTOID:
            return "ISFFACTOID (smart tag)"
        elif val == SharedFeatureType.ISFLIST:
            return "ISFLIST (list)"
        else:
            return ""


class SourceType(object):

    LTRANGE        = 0x00000000 # Range
    LTSHAREPOINT   = 0x00000001 # Read/write Web-based data provider list
    LTXML          = 0x00000002 # XML Mapper data
    LTEXTERNALDATA = 0x00000003 # External data source (query table)

    @staticmethod
    def toString (val):
        if val == SourceType.LTRANGE:
            return "LTRANGE"
        elif val == SourceType.LTSHAREPOINT:
            return "LTSHAREPOINT"
        elif val == SourceType.LTXML:
            return "LTXML"
        elif val == SourceType.LTEXTERNALDATA:
            return "LTEXTERNALDATA"
        else:
            return ""


class TableFeatureType(object):

    def __init__ (self, strm):
        self.lt = strm.readUnsignedInt(4)
        self.idList = strm.readUnsignedInt(4)
        self.crwHeader = strm.readUnsignedInt(4) != 0
        self.crwTotals = strm.readUnsignedInt(4) != 0
        self.idFieldNext = strm.readUnsignedInt(4)
        self.cbFSData = strm.readUnsignedInt(4) # must be equal to 64
        self.rupBuild = strm.readUnsignedInt(2)
        strm.readBytes(2) # ignored

        flags = strm.readUnsignedInt(2)
        # unused2                      = (flags & 0x0001) != 0 # A
        self.fAutoFilter               = (flags & 0x0002) != 0 # B
        self.fPersistAutoFilter        = (flags & 0x0004) != 0 # C
        self.fShowInsertRow            = (flags & 0x0008) != 0 # D
        self.fInsertRowInsCells        = (flags & 0x0010) != 0 # E
        self.fLoadPldwIdDeleted        = (flags & 0x0020) != 0 # F
        self.fShownTotalRow            = (flags & 0x0040) != 0 # G
        # reserved1                    = (flags & 0x0080) != 0 # H
        self.fNeedsCommit              = (flags & 0x0100) != 0 # I
        self.fSingleCell               = (flags & 0x0200) != 0 # J
        # reserved2                    = (flags & 0x0400) != 0 # K
        self.fApplyAutoFilter          = (flags & 0x0800) != 0 # L
        self.fForceInsertToBeVis       = (flags & 0x1000) != 0 # M
        self.fCompressedXml            = (flags & 0x2000) != 0 # N
        self.fLoadCSPName              = (flags & 0x4000) != 0 # O
        self.fLoadPldwIdChanged        = (flags & 0x8000) != 0 # P

        flags = strm.readUnsignedInt(2)
        self.verXL = (flags & 0x000F)

        self.fLoadEntryId              = (flags & 0x0010) != 0 # Q
        self.fLoadPllstclInvalid       = (flags & 0x0020) != 0 # R
        self.fGoodRupBld               = (flags & 0x0040) != 0 # S
        # unused3                      = (flags & 0x0080) != 0 # T
        self.fPublished                = (flags & 0x0100) != 0 # U

        self.lPosStmCache = strm.readUnsignedInt(4)
        self.cbStmCache = strm.readUnsignedInt(4)
        self.cchStmCache = strm.readUnsignedInt(4)

        self.lem = strm.readUnsignedInt(4) # table edit mode
        self.rgbHashParam = strm.readBytes(16)
        self.rgbName = strm.readXLUnicodeString()
        self.cFieldData = strm.readUnsignedInt(2)
        if self.fLoadCSPName:
            self.cSPName = strm.readXLUnicodeString()
        if self.fLoadEntryId:
            self.entryId = strm.readXLUnicodeString()

        # TODO : fieldData
        # TODO : idDeleted
        # TODO : idChanged
        # TODO : cellInvalid

    def appendLines (self, hdl):
        hdl.appendLineString("source type", SourceType.toString(self.lt))
        hdl.appendLineInt("table ID", self.idList)
        hdl.appendLineBoolean("table has a header", self.crwHeader)
        hdl.appendLineBoolean("table has a total row", self.crwTotals)
        hdl.appendLineInt("next ID to use", self.idFieldNext)
        hdl.appendLineInt("structure size", self.cbFSData)
        hdl.appendLineInt("build ID", self.rupBuild)
        hdl.appendLineBoolean("has autofilter", self.fAutoFilter)
        hdl.appendLineBoolean("autofilter preserved on refresh", self.fPersistAutoFilter)
        hdl.appendLineBoolean("insert row visible", self.fShowInsertRow)
        hdl.appendLineBoolean("rows below shifted down", self.fInsertRowInsCells)
        hdl.appendLineBoolean("idDeleted field is present", self.fLoadPldwIdDeleted)
        hdl.appendLineBoolean("total row was ever visible", self.fShownTotalRow)
        hdl.appendLineBoolean("table mods needs commit to source", self.fNeedsCommit)
        hdl.appendLineBoolean("single cell table", self.fSingleCell)
        hdl.appendLineBoolean("auto filter applied", self.fApplyAutoFilter)
        hdl.appendLineBoolean("insert row forced visible", self.fForceInsertToBeVis)
        hdl.appendLineBoolean("cached data compressed", self.fCompressedXml)
        hdl.appendLineBoolean("cSPName field present", self.fLoadCSPName)
        hdl.appendLineBoolean("idChanged field present", self.fLoadPldwIdChanged)
        hdl.appendLineInt("Excel version", self.verXL)
        hdl.appendLineBoolean("entryId field present", self.fLoadEntryId)
        hdl.appendLineBoolean("cellInvalid field present", self.fLoadPllstclInvalid)
        hdl.appendLineBoolean("rupBuild field valid", self.fGoodRupBld)
        hdl.appendLineBoolean("table published", self.fPublished)
        hdl.appendLineInt("cached data position in List Data stream", self.lPosStmCache)
        hdl.appendLineInt("cached data size in List Data stream", self.cbStmCache)
        hdl.appendLineInt("number of characters in cached data", self.cchStmCache)

        # TODO : dump more data

        hdl.appendLineString("table name", self.rgbName)
        hdl.appendLineInt("column count", self.cFieldData)

        if self.fLoadCSPName:
            hdl.appendLineString("cryptographic service provider name", self.cSPName)
        if self.fLoadEntryId:
            hdl.appendLineString("unique table identifier", self.entryId)



class FeatureHeader(BaseRecordHandler):
    """Beginning of a collection of records."""

    def parseBytes (self):
        recordType = self.readUnsignedInt(2)
        frtFlag = self.readUnsignedInt(2) # currently 0
        self.readBytes(8) # reserved (currently all 0)
        featureTypeId = self.readUnsignedInt(2)
        featureTypeText = 'unknown'
        if featureTypeId == 2:
            featureTypeText = 'enhanced protection'
        elif featureTypeId == 3:
            featureTypeText = 'ignored formula errors'
        elif featureTypeId == 4:
            featureTypeText = 'smart tag'
        featureHdr = self.readUnsignedInt(1) # must be 1
        sizeHdrData = self.readSignedInt(4)
        sizeHdrDataText = 'byte size'
        if sizeHdrData == -1:
            sizeHdrDataText = 'size depends on feature type'

        self.appendLine("record type: 0x%4.4X (must match the header)"%recordType)
        self.appendLine("feature type: %d (%s)"%(featureTypeId, featureTypeText))
        self.appendLine("size of header data: %d (%s)"%(sizeHdrData, sizeHdrDataText))

        if featureTypeId == 2 and sizeHdrData == -1:
            # enhanced protection options
            flags = self.readUnsignedInt(4)
            self.appendLine("enhanced protection flag: 0x%8.8X"%flags)

            optEditObj             = (flags & 0x00000001)
            optEditScenario        = (flags & 0x00000002)
            optFormatCells         = (flags & 0x00000004)
            optFormatColumns       = (flags & 0x00000008)
            optFormatRows          = (flags & 0x00000010)
            optInsertColumns       = (flags & 0x00000020)
            optInsertRows          = (flags & 0x00000040)
            optInsertLinks         = (flags & 0x00000080)
            optDeleteColumns       = (flags & 0x00000100)
            optDeleteRows          = (flags & 0x00000200)
            optSelectLockedCells   = (flags & 0x00000400)
            optSort                = (flags & 0x00000800)
            optUseAutofilter       = (flags & 0x00001000)
            optUsePivotReports     = (flags & 0x00002000)
            optSelectUnlockedCells = (flags & 0x00004000)
            self.appendLine("  edit object:             %s"%self.getEnabledDisabled(optEditObj))
            self.appendLine("  edit scenario:           %s"%self.getEnabledDisabled(optEditScenario))
            self.appendLine("  format cells:            %s"%self.getEnabledDisabled(optFormatCells))
            self.appendLine("  format columns:          %s"%self.getEnabledDisabled(optFormatColumns))
            self.appendLine("  format rows:             %s"%self.getEnabledDisabled(optFormatRows))
            self.appendLine("  insert columns:          %s"%self.getEnabledDisabled(optInsertColumns))
            self.appendLine("  insert rows:             %s"%self.getEnabledDisabled(optInsertRows))
            self.appendLine("  insert hyperlinks:       %s"%self.getEnabledDisabled(optInsertLinks))
            self.appendLine("  delete columns:          %s"%self.getEnabledDisabled(optDeleteColumns))
            self.appendLine("  delete rows:             %s"%self.getEnabledDisabled(optDeleteRows))
            self.appendLine("  select locked cells:     %s"%self.getEnabledDisabled(optSelectLockedCells))
            self.appendLine("  sort:                    %s"%self.getEnabledDisabled(optSort))
            self.appendLine("  use autofilter:          %s"%self.getEnabledDisabled(optUseAutofilter))
            self.appendLine("  use pivot table reports: %s"%self.getEnabledDisabled(optUsePivotReports))
            self.appendLine("  select unlocked cells:   %s"%self.getEnabledDisabled(optSelectUnlockedCells))

        return

class FeatureData(BaseRecordHandler):

    def parseBytes (self):
        recordType = self.readUnsignedInt(2)
        frtFlag = self.readUnsignedInt(2) # currently 0
        self.readBytes(8) # reserved (currently all 0)
        featureTypeId = self.readUnsignedInt(2)
        featureTypeText = 'unknown'
        if featureTypeId == 2:
            featureTypeText = 'enhanced protection'
        elif featureTypeId == 3:
            featureTypeText = 'ignored formula errors'
        elif featureTypeId == 4:
            featureTypeText = 'smart tag'
        self.readBytes(1) # reserved1, must be 0
        self.readBytes(4) # reserved2, must be 0
        cref = self.readUnsignedInt(2)
        cbFeatData = self.readUnsignedInt(4)
        cbFeatDataText = 'byte size'
        self.readBytes(2) # reserved3, must be 0

        refs = []
        for i in xrange(0, cref):
            refs.append(Ref8U(self))

        self.appendLine("record type: 0x%4.4X (must match the header)"%recordType)
        self.appendLine("feature type: %d (%s)"%(featureTypeId, featureTypeText))
        self.appendLine("size of feature data: %d (%s)"%(cbFeatData, cbFeatDataText))

        if featureTypeId == 2:
            # enhanced protection, ISFPROTECTION, FeatProtection structure
            Areserved = self.readUnsignedInt(4)
            wPassword = self.readUnsignedInt(4)
            stTitle = self.readXLUnicodeString()
            self.appendLine("A and reserved: 0x%8.8X"%Areserved)
            self.appendLine("wPassword: 0x%8.8X"%wPassword)
            self.appendLine("stTitle: %s"%stTitle)
            if Areserved & 0x00000001 == 0x00000001:
                # SDContainer
                cbSD = self.readUnsignedInt(4)
                self.appendLine("cbSD: %d"%cbSD)
                self.readBytes(cbSD)
        elif featureTypeId == 3 and cbFeatData > 0:
            # ignored formula errors, ISFFEC2, FeatFormulaErr2 structure
            self.readBytes(cbFeatData)
            self.appendLine("FeatFormulaErr2 not handled")
        elif featureTypeId == 4:
            # smart tag, ISFFACTOID, FeatSmartTag structure
            self.appendLine("FeatSmartTag not handled")

        for ref in refs:
            self.appendLine("applied to range: (col=%d,row=%d) - (col=%d,row=%d)"%
                (ref.col1, ref.row1, ref.col2, ref.row2))

        return


class Feature11(BaseRecordHandler):

    def __parseBytes (self):
        self.frtRefHeaderU = FrtRefHeaderU(self)
        self.isf = self.readUnsignedInt(2) # SharedFeatureType
        self.readBytes(5) # ignored
        self.cref2 = self.readUnsignedInt(2)
        self.cbFeatData = self.readUnsignedInt(4) # size of rgbFeat
        self.readBytes(2) # ignored
        self.refs2 = []
        for i in xrange(0, self.cref2):
            ref = Ref8U(self)
            self.refs2.append(ref)

        if self.cbFeatData == 0:
            bytes = self.readRemainingBytes()
        else:
            bytes = self.readBytes(self.cbFeatData)
        strm = XLStream(bytes)

        self.rgbFeat = TableFeatureType(strm)


    def parseBytes (self):
        self.__parseBytes()
        self.frtRefHeaderU.appendLines(self)
        self.appendLineString("feature data type", SharedFeatureType.toString(self.isf))
        for ref in self.refs2:
            self.appendLineString("reference", ref.toString())
        self.rgbFeat.appendLines(self)


class ShrFmla(BaseRecordHandler):

    def __parseBytes (self):
        self.ref = RefU(self)
        self.readBytes(1) # 8-bits reserved
        self.cUse = self.readUnsignedInt(1)
        lenFormula = self.readUnsignedInt(2)
        self.tokens = self.readBytes(lenFormula)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("range: %s"%self.ref.toString())
        self.appendLine("cell count: %d"%self.cUse)
        self.appendLine("formula token length: %d"%len(self.tokens))
        if len(self.tokens):
            ftext = None
            try:
                parser = formula.FormulaParser(self.header, self.tokens)
                parser.parse(formula.ParsedFormulaType.Shared)
                ftext = parser.getText()
            except formula.FormulaParserError as e:
                ftext = "(Error: %s)"%e.args[0]
            if ftext != None:
                self.appendLine("formula: %s"%ftext)




# -------------------------------------------------------------------
# SX - Pivot Table

class FrtFlags(object):

    def __init__ (self, strm):
        grbitFrt = strm.readUnsignedInt(2)
        self.flag = grbitFrt
        self.fFrtRef   = (grbitFrt & 0x0001) != 0 # record specifies a range of cells
        self.fFrtAlert = (grbitFrt & 0x0002) != 0 # whether to alert the user of possible problems when saving the file

    def appendLines (self, hdl):
        hdl.appendLine("flag value: 0x%4.4X"%self.flag)
        hdl.appendLineBoolean("range of cells", self.fFrtRef)
        hdl.appendLineBoolean("alert when saving", self.fFrtAlert)


class FrtRefHeaderU(object):

    def __init__ (self, strm):
        self.rt = strm.readUnsignedInt(2)
        self.grbitFrt = FrtFlags(strm)
        self.ref8 = Ref8U(strm)

    def appendLines (self, hdl):
        hdl.appendLine("header value: 0x%4.4X"%self.rt)
        self.grbitFrt.appendLines(hdl)
        hdl.appendLineString("reference", self.ref8.toString())


class XLUnicodeStringSegmentedSXAddl(object):

    def __init__ (self, strm):
        self.cchTotal = strm.readUnsignedInt(4)
        strm.readBytes(2) # ignored

    def appendLines (self, hdl):
        if self.cchTotal <= 65535:
            hdl.appendLineInt("cchTotal", self.cchTotal)


class DConName(BaseRecordHandler):

    def __parseBytes (self):
        self.rangeName = self.readUnicodeString()
        self.flag = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("defined name: %s"%self.rangeName)
        if self.flag == 0:
            self.appendMultiLine("This defined name has a workbook scope and is contained in this file.")
        else:
            # The additional bytes contain info about the workbook and
            # worksheet where the defined name is located.  We don't handle
            # this yet.
            pass

class DConRef(BaseRecordHandler):

    def __parseBytes (self):
        self.ref = RefU(self)
        textLen = self.readUnsignedInt(2)
        bytes = self.bytes[self.pos:]
        text, byteLen = globals.getRichText(bytes, textLen)
        self.sheetName = globals.encodeName(text)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("range: %s"%self.ref.toString())
        self.appendLine("sheet name: %s"%self.sheetName)

class SxIvd(BaseRecordHandler):

    def __parseBytes (self):
        self.ids = []
        n = self.getSize() / 2
        for i in xrange(0, n):
            self.ids.append(self.readSignedInt(2))

    def parseBytes (self):
        self.__parseBytes()
        for id in self.ids:
            if id == -2:
                self.appendLine("pivot field index: %d (data layout field)"%id)
            else:
                self.appendLineInt("pivot field index", id)

        self.appendLine("")
        self.appendMultiLine("NOTE: The first one of this record is for row fields, whereas the second one is for column fields.")


class SXViewEx9(BaseRecordHandler):

    def parseBytes (self):
        rt = self.readUnsignedInt(2)
        dummy = self.readBytes(6)
        flags = self.readUnsignedInt(4)
        autoFmtId = self.readUnsignedInt(2)

        self.appendLine("record type: %4.4Xh (always 0x0810)"%rt)
        self.appendLine("autoformat index: %d"%autoFmtId)

        nameLen = self.readSignedInt(2)
        if nameLen > 0:
            name, nameLen = globals.getRichText(self.readRemainingBytes(), nameLen)
            self.appendLine("grand total name: %s"%name)
        else:
            self.appendLine("grand total name: (none)")
        return


class SXAddlInfo(BaseRecordHandler):

    SxcClassList = {
        0x00: 'sxcView',
        0x01: 'sxcField',
        0x02: 'sxcHierarchy',
        0x03: 'sxcCache',
        0x04: 'sxcCacheField',
        0x05: 'sxcQsi',
        0x06: 'sxcQuery',
        0x07: 'sxcGrpLevel',
        0x08: 'sxcGroup',
        0x09: 'sxcCacheItem',
        0x0C: 'sxcSxrule',
        0x0D: 'sxcSxfilt',
        0x10: 'sxcSxdh',
        0x12: 'sxcAutoSort',
        0x13: 'sxcSxmgs',
        0x14: 'sxcSxmg',
        0x17: 'sxcField12',
        0x1A: 'sxcSxcondfmts',
        0x1B: 'sxcSxcondfmt',
        0x1C: 'sxcSxfilters12',
        0x1D: 'sxcSxfilter12'
    }

    SxcViewTypes = {
        0x00: 'sxdId',
        0x01: 'sxdVerUpdInv',
        0x02: 'sxdVer10Info',
        0x03: 'sxdCalcMember',
        0x0A: 'sxdCalcMemString',
        0x19: 'sxdVer12Info',
        0x1E: 'sxdTableStyleClient',
        0x21: 'sxdCompactRwHdr',
        0x22: 'sxdCompactColHdr',
        0x26: 'sxdSxpiIvmb',
        0xFF: 'sxdEnd'
    }

    def __parseBytes (self):
        self.flags = FrtFlags(self) # ignored
        self.sxc = self.readUnsignedInt(1)
        self.sxd = self.readUnsignedInt(1)
        if self.sxc == 0x00:
            # SxcView
            self.__parseBytesView()

    def __parseBytesView (self):
        assert(self.sxc == 0x00)
        if self.sxd == 0x00:
            # sxdId
            self.__parseSxcViewSxdId()

    def __parseSxcViewSxdId (self):
        self.stName = XLUnicodeStringSegmentedSXAddl(self)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineString("classs name", globals.getValueOrUnknown(SXAddlInfo.SxcClassList, self.sxc))
        if self.sxc == 0x00:
            # SxcView
            self.appendLineString("record type", globals.getValueOrUnknown(SXAddlInfo.SxcViewTypes, self.sxd))
            if self.sxd == 0x00:
                # sxdId
                self.stName.appendLines(self)


class SXDb(BaseRecordHandler):

    def parseBytes (self):
        recCount = self.readUnsignedInt(4)
        strmId   = self.readUnsignedInt(2)
        flags    = self.readUnsignedInt(2)
        self.appendLine("number of records in database: %d"%recCount)
        self.appendLine("stream ID: %4.4Xh"%strmId)
#       self.appendLine("flags: %4.4Xh"%flags)

        saveLayout    = (flags & 0x0001)
        invalid       = (flags & 0x0002)
        refreshOnLoad = (flags & 0x0004)
        optimizeCache = (flags & 0x0008)
        backQuery     = (flags & 0x0010)
        enableRefresh = (flags & 0x0020)
        self.appendLine("save data with table layout: %s"%self.getYesNo(saveLayout))
        self.appendLine("invalid table (must be refreshed before next update): %s"%self.getYesNo(invalid))
        self.appendLine("refresh table on load: %s"%self.getYesNo(refreshOnLoad))
        self.appendLine("optimize cache for least memory use: %s"%self.getYesNo(optimizeCache))
        self.appendLine("query results obtained in the background: %s"%self.getYesNo(backQuery))
        self.appendLine("refresh is enabled: %s"%self.getYesNo(enableRefresh))

        dbBlockRecs = self.readUnsignedInt(2)
        baseFields = self.readUnsignedInt(2)
        allFields = self.readUnsignedInt(2)
        self.appendLine("number of records for each database block: %d"%dbBlockRecs)
        self.appendLine("number of base fields: %d"%baseFields)
        self.appendLine("number of all fields: %d"%allFields)

        dummy = self.readBytes(2)
        type = self.readUnsignedInt(2)
        typeName = '(unknown)'
        if type == 1:
            typeName = 'Excel worksheet'
        elif type == 2:
            typeName = 'External data'
        elif type == 4:
            typeName = 'Consolidation'
        elif type == 8:
            typeName = 'Scenario PivotTable'
        self.appendLine("type: %s (%d)"%(typeName, type))
        textLen = self.readUnsignedInt(2)
        changedBy, textLen = globals.getRichText(self.readRemainingBytes(), textLen)
        self.appendLine("changed by: %s"%changedBy)


class SXDBB(BaseRecordHandler):

    def __parseBytes (self):
        self.items = []
        for fld in self.strmData.pivotCacheFields:
            if fld.hasMoreThan255:
                # read 2 bytes
                idx = self.readUnsignedInt(2)
            else:
                idx = self.readUnsignedInt(1)
            s = fld.values[idx]
            self.items.append(s)

    def parseBytes (self):
        self.__parseBytes()
        for item in self.items:
            self.appendLine(item)


class SXDbEx(BaseRecordHandler):

    def parseBytes (self):
        lastChanged = self.readDouble()
        sxFmlaRecs = self.readUnsignedInt(4)
        self.appendLine("last changed: %g"%lastChanged)
        self.appendLine("count of SXFORMULA records for this cache: %d"%sxFmlaRecs)

class SXEx(BaseRecordHandler):

    def __parseBytes (self):
        self.csxformat = self.readUnsignedInt(2)
        self.cchErrorString = self.readUnsignedInt(2)
        self.cchNullString = self.readUnsignedInt(2)
        self.cchTag = self.readUnsignedInt(2)
        self.csxselect = self.readUnsignedInt(2)
        self.crwPage = self.readUnsignedInt(2)
        self.ccolPage = self.readUnsignedInt(2)
        flag = self.readUnsignedInt(2)

        # Page field layout
        # 0 = top to bottom then left to right
        # 1 = left to right then top to bottom
        self.fAcrossPageLay = (flag & 0x0001)

        # Rows in each page field column
        self.cWrapPage = (flag & 0x01FE) / 2

        flag = self.readUnsignedInt(2)
        self.fEnableWizard            = (flag & 0x0001) != 0 # D
        self.fEnableDrilldown         = (flag & 0x0002) != 0 # E
        self.fEnableFieldDialog       = (flag & 0x0004) != 0 # F
        self.fPreserveFormatting      = (flag & 0x0008) != 0 # G
        self.fMergeLabels             = (flag & 0x0010) != 0 # H
        self.fDisplayErrorString      = (flag & 0x0020) != 0 # I
        self.fDisplayNullString       = (flag & 0x0040) != 0 # J
        self.fSubtotalHiddenPageItems = (flag & 0x0080) != 0 # K

        self.cchPageFieldStyle = self.readUnsignedInt(2)
        self.cchTableStyle = self.readUnsignedInt(2)
        self.cchVacateStyle = self.readUnsignedInt(2)

        self.stError = ""
        if self.cchErrorString != 0xFFFF:
            self.stError = self.readXLUnicodeStringNoCch(self.cchErrorString)

        self.stDisplayNull = ""
        if self.cchNullString != 0xFFFF:
            self.stDisplayNull = self.readXLUnicodeStringNoCch(self.cchNullString)

        self.stTag = ""
        if self.cchTag != 0xFFFF:
            self.stTag = self.readXLUnicodeStringNoCch(self.cchTag)

        self.stPageFieldStyle = ""
        if self.cchPageFieldStyle != 0xFFFF and self.cchPageFieldStyle > 0:
            self.stPageFieldStyle = self.readXLUnicodeStringNoCch(self.cchPageFieldStyle)

        self.stTableStyle = ""
        if self.cchTableStyle != 0xFFFF and self.cchTableStyle > 0:
            self.stTableStyle = self.readXLUnicodeStringNoCch(self.cchTableStyle)

        self.stVacateStyle = ""
        if self.cchVacateStyle != 0xFFFF and self.cchVacateStyle > 0:
            self.stVacateStyle = self.readXLUnicodeStringNoCch(self.cchVacateStyle)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineInt("number of SxFormat records", self.csxformat)
        self.appendLineString("error string", self.stError)
        self.appendLineString("null string", self.stDisplayNull)
        self.appendLineString("custom string", self.stTag)
        self.appendLineString("style used in page area", self.stPageFieldStyle)
        self.appendLineString("style used in table body", self.stTableStyle)
        self.appendLineString("style used in empty cells", self.stVacateStyle)
        if self.fAcrossPageLay:
            self.appendLine("page area layout: left to right, then top to bottom")
        else:
            self.appendLine("page area layout: top to bottom, then left to right")
        self.appendLineInt("rows in each page column", self.cWrapPage)

        self.appendLineBoolean("enable wizard", self.fEnableWizard)
        self.appendLineBoolean("enable drilldown", self.fEnableDrilldown)
        self.appendLineBoolean("enable field properties dialog", self.fEnableFieldDialog)
        self.appendLineBoolean("preserve formatting", self.fPreserveFormatting)
        self.appendLineBoolean("merge labels", self.fMergeLabels)
        self.appendLineBoolean("display custom error string", self.fDisplayErrorString)
        self.appendLineBoolean("display custom empty string", self.fDisplayNullString)
        self.appendLineBoolean("subtotal hidden page items", self.fSubtotalHiddenPageItems)


class SXDtr(BaseRecordHandler):

    def __parseBytes (self):
        self.yr = self.readUnsignedInt(2)
        self.mon = self.readUnsignedInt(2)
        self.dom = self.readUnsignedInt(1)
        self.hr = self.readUnsignedInt(1)
        self.min = self.readUnsignedInt(1)
        self.sec = self.readUnsignedInt(1)
        s = "%d-%d-%dT%2.2d-%2.2d-%2.2d"%(self.yr, self.mon, self.dom, self.hr, self.min, self.sec)
        self.strmData.pivotCacheFields[-1].values.append(s)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("year (1900-9999)    : %d"%self.yr)
        self.appendLine("month (1-12)        : %d"%self.mon)
        self.appendLine("day of month (0-31) : %d"%self.dom)
        self.appendLine("hour (0-23)         : %d"%self.hr)
        self.appendLine("minutes (0-59)      : %d"%self.min)
        self.appendLine("seconds (0-59)      : %d"%self.sec)
        self.appendLine("")
        self.appendMultiLine("The month value must be 1 if the day of month value is 0.")

class SxDXF(BaseRecordHandler):

    def __parseBytes (self):
        self.dxf = DXFN12NoCB(self)

    def parseBytes (self):
        self.__parseBytes()
        self.dxf.appendLines(self)

class SXFDBType(BaseRecordHandler):

    types = {
        0x0000: "SQL_TYPE_NULL",
        0x0001: "SQL_CHAR",
        0x0003: "SQL_DECIMAL",
        0x0004: "SQL_INTEGER",
        0x0005: "SQL_SMALLINT",
        0x0006: "SQL_FLOAT",
        0x0007: "SQL_REAL",
        0x0008: "SQL_DOUBLE",
        0x000B: "SQL_TIMESTAMP",
        0x000C: "SQL_VARCHAR",
        0xFFF9: "SQL_BIT",
        0xFFFE: "SQL_BINARY"
    }

    def __parseBytes (self):
        self.wTypeSql = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        s = globals.getValueOrUnknown(SXFDBType.types, self.wTypeSql)
        self.appendLine("ODBC Type: %s"%s)


class SXFDB(BaseRecordHandler):

    dataTypeNames = {
        0x0000: 'spc',
        0x0480: 'str',
        0x0520: 'int[+dbl]',
        0x0560: 'dbl',
        0x05A0: 'str+int[+dbl]',
        0x05E0: 'str+dbl',
        0x0900: 'dat',
        0x0D00: 'dat+int/dbl',
        0x0D80: 'dat+str[+int/dbl]'
    }

    def __parseBytes (self):
        # parse flag
        bits = self.readUnsignedInt(2)
        self.fAllAtoms           = (bits & 0x0001) != 0 # A
        self.fSomeUnhashed       = (bits & 0x0002) != 0 # B (undefined, must be ignored)
        self.fUsed               = (bits & 0x0004) != 0 # C (undefined, must be ignored)
        self.fHasParent          = (bits & 0x0008) != 0 # D
        self.fRangeGroup         = (bits & 0x0010) != 0 # E
        self.fNumField           = (bits & 0x0020) != 0 # F
        unused                   = (bits & 0x0040) != 0 # G (unused)
        self.fTextEtcField       = (bits & 0x0080) != 0 # H
        self.fnumMinMaxValid     = (bits & 0x0100) != 0 # I
        self.fShortIitms         = (bits & 0x0200) != 0 # J
        self.fNonDates           = (bits & 0x0400) != 0 # K
        self.fDateInField        = (bits & 0x0800) != 0 # L
        unused                   = (bits & 0x1000) != 0 # M
        self.fServerBased        = (bits & 0x2000) != 0 # N
        self.fCantGetUniqueItems = (bits & 0x4000) != 0 # O
        self.fCalculatedField    = (bits & 0x8000) != 0 # P

        self.ifdbParent = self.readUnsignedInt(2)
        self.ifdbBase = self.readUnsignedInt(2)
        self.citmUnq = self.readUnsignedInt(2)          # (undefined, must be ignored)
        self.csxoper = self.readUnsignedInt(2)
        self.cisxoper = self.readUnsignedInt(2)
        self.catm = self.readUnsignedInt(2)
        self.stFieldName = self.readXLUnicodeString()

        if self.fAllAtoms:
            # this cached field has a collection of items in the following
            # SXDBB records.
            obj = PivotField()
            obj.hasMoreThan255 = self.fShortIitms
            self.strmData.pivotCacheFields.append(obj)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineBoolean("collection of items", self.fAllAtoms)
        self.appendLineBoolean("has parent grouping cache field", self.fHasParent)
        self.appendLineBoolean("numeric or date grouping", self.fRangeGroup)
        self.appendLineBoolean("has numeric cache item", self.fNumField)
        self.appendLineBoolean("has text data", self.fTextEtcField)
        self.appendLineBoolean("min/max values can be computed", self.fnumMinMaxValid)
        self.appendLineBoolean("has more than 255 items", self.fShortIitms)
        self.appendLineBoolean("has non-date values", self.fNonDates)
        self.appendLineBoolean("has date item", self.fDateInField)
        self.appendLineBoolean("server-based page field (for ODBC PivotCache)", self.fServerBased)
        self.appendLineBoolean("unique values unavailable (for ODBC source data)", self.fCantGetUniqueItems)
        self.appendLineBoolean("calculated field", self.fCalculatedField)
        self.appendLineInt("field index of parent (for grouped field)", self.ifdbParent)
        self.appendLineInt("field index of base (for grouped field)", self.ifdbBase)
        self.appendLineInt("number of cache items (for grouped field)", self.csxoper)
        self.appendLineInt("number of cache items in base field (for grouped field)", self.cisxoper)
        self.appendLineInt("number of cache items in collection", self.catm)
        self.appendLineString("field name", self.stFieldName)


class SxFormat(BaseRecordHandler):

    def __parseBytes (self):
        flag = self.readUnsignedInt(2)
        self.rlType = (flag & 0x000F) != 0
        self.cbData = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineBoolean("formatting applied", self.rlType)
        self.appendLineInt("number of byts in next SxDXF", self.cbData)


class SXLI(BaseRecordHandler):

    itemTypes = {
        0x00: 'value in the data',
        0x01: 'automatic subtotal selection',
        0x02: 'SUM',
        0x03: 'COUNTA',
        0x04: 'COUNT',
        0x05: 'AVERAGE',
        0x06: 'MAX',
        0x07: 'MIN',
        0x08: 'PRODUCT',
        0x09: 'STDEV',
        0x0A: 'STDEVP',
        0x0B: 'VAR',
        0x0C: 'VARP',
        0x0D: 'grand total',
        0x0E: 'blank line'
    }

    class Item(object):
        def __init__ (self, strm):
            self.cSic = strm.readSignedInt(2)
            flag = strm.readUnsignedInt(2)
            self.itmType = (flag & 0x7FFF)
            self.isxviMac = strm.readSignedInt(2)
            flag = strm.readUnsignedInt(2)
            self.fMultiDataName   = (flag & 0x0001) != 0
            self.iData            = (flag & 0x01FE) / 2
            self.fSbt             = (flag & 0x0200) != 0
            self.fBlock           = (flag & 0x0400) != 0
            self.fGrand           = (flag & 0x0800) != 0
            self.fMultiDataOnAxis = (flag & 0x1000) != 0
            G                     = (flag & 0x2000) != 0 # unused
            H                     = (flag & 0x4000) != 0 # unused
            I                     = (flag & 0x8000) != 0 # reserved
            self.rgisxvi = []
            if self.isxviMac > 0:
                for i in xrange(0, self.isxviMac):
                    id = strm.readSignedInt(2)
                    self.rgisxvi.append(id)

        def appendLines (self, parent):
            parent.appendLine("------------")
            parent.appendLine(" pivot line")
            parent.appendLine("------------")
            parent.appendLineInt("pivot item index count", self.cSic)
            parent.appendLineString("item type", globals.getValueOrUnknown(SXLI.itemTypes, self.itmType))
            parent.appendLineInt("number of elements", self.isxviMac)
            if self.fMultiDataName:
                parent.appendLineString("data field name", "subtotal")
            else:
                parent.appendLineString("data field name", "total")
            parent.appendLineInt("data item index", self.iData)
            parent.appendLineBoolean("subtotal", self.fSbt)
            parent.appendLineBoolean("block total", self.fBlock)
            parent.appendLineBoolean("grand total", self.fGrand)
            parent.appendLineBoolean("multi data on axis", self.fMultiDataOnAxis)
            s = ""
            first = True
            for id in self.rgisxvi:
                if first:
                    first = False
                else:
                    s += ","
                s += "%d"%id
            parent.appendLineString("pivot line entry", s)

    def __parseBytes (self):
        self.items = []
        while not self.isEndOfRecord():
            obj = SXLI.Item(self)
            self.items.append(obj)

    def parseBytes (self):
        self.__parseBytes()
        for item in self.items:
            item.appendLines(self)


class SXStreamID(BaseRecordHandler):

    def parseBytes (self):
        if self.size != 2:
            return

        strmId = globals.getSignedInt(self.bytes)
        self.strmData.appendPivotCacheId(strmId)
        self.appendLine("pivot cache stream ID in SX DB storage: %4.4X"%strmId)

class SxRule(BaseRecordHandler):

    viewAreaTypes = [
        "does not refer to any area.",
        "refers to one or more pivot fields specified by SxFilt records that follow this record.",
        "refers to cells displaying values of data items specified by SxFilt records that follow this record.",
        "refers to the entire PivotTable view.",
        "refers to the cells at the top-left of the PivotTable view, or at the top-right for a right-to-left sheet. For more information about this area, see Location and Body.",
        "refers to a cell displaying a pivot field caption. The pivot field is specified by isxvd.",
        "refers to the cells at the top-right of the PivotTable view, or at the top-left for a right-to-left sheet. For more information about this area, see Location and Body."
    ]

    def __parseBytes (self):
        self.iDim = self.readUnsignedInt(1)
        self.isvxd = self.readUnsignedInt(1)

        flag = self.readUnsignedInt(2)
        self.sxaxisRw   = (flag & 0x0001) != 0
        self.sxaxisCol  = (flag & 0x0002) != 0
        self.sxaxisPage = (flag & 0x0004) != 0
        self.sxaxisData = (flag & 0x0008) != 0
        self.sxrType    = (flag & 0x00F0) / (2**4)

        flag /= 2**8 # shift 8 bits

        self.fPart        = (flag & 0x01) != 0
        self.fDataOnly    = (flag & 0x02) != 0
        self.fLabelOnly   = (flag & 0x04) != 0
        self.fGrandRw     = (flag & 0x08) != 0
        self.fGrandCol    = (flag & 0x10) != 0
        self.fGrandRwSav  = (flag & 0x20) != 0
        self.fCacheBased  = (flag & 0x40) != 0
        self.fGrandColSav = (flag & 0x80) != 0

        self.readBytes(2) # 2 bytes reserved

        self.csxFilt = self.readUnsignedInt(2)

        if not self.fPart:
            return

        # following should exist only when fPart is true
        self.irwFirst  = self.readUnsignedInt(1)
        self.irwLast   = self.readUnsignedInt(1)
        self.icolFirst = self.readUnsignedInt(1)
        self.icolLast  = self.readUnsignedInt(1)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineInt("pivot field position", self.iDim)
        if self.isvxd <= 0xFD:
            if self.fCacheBased:
                self.appendLineInt("cache field index", self.isvxd)
            else:
                self.appendLineInt("pivot field index", self.isvxd)
        elif self.isvxd == 0xFE:
            self.appendLine("this record refers to data field")
        elif self.isvxd == 0xFF:
            if self.fCacheBased:
                self.appendLine("cache fields specified by SxFilt records.")
            else:
                self.appendLine("pivot fields specified by SxFilt records.")

        self.appendLineBoolean("references row axis", self.sxaxisRw)
        self.appendLineBoolean("references column axis", self.sxaxisCol)
        self.appendLineBoolean("references page axis", self.sxaxisPage)
        self.appendLineBoolean("references value axis", self.sxaxisData)
        self.appendMultiLine("view area type: " + globals.getValueOrUnknown(SxRule.viewAreaTypes, self.sxrType))
        self.appendLineBoolean("this rule includes data cells only", self.fDataOnly)
        self.appendLineBoolean("this rule includes labels only", self.fDataOnly)
        self.appendLineBoolean("this rule includes grand total row", self.fGrandRw)
        self.appendLineBoolean("this rule includes grand total column", self.fGrandCol)
        self.appendLineBoolean("this rule previosly included grand total row", self.fGrandRwSav)
        self.appendLineBoolean("this rule previosly included grand total column", self.fGrandColSav)

        self.appendLineInt("number of SxFilt records", self.csxFilt)

        if not self.fPart:
            return

        # following should exist only when fPart is true
        self.appendLineInt("offset to first row", self.irwFirst)
        self.appendLineInt("offset to last row", self.irwLast)
        self.appendLineInt("offset to first column", self.icolFirst)
        self.appendLineInt("offset to last column", self.icolLast)



class SXView(BaseRecordHandler):

    def parseBytes (self):
        rowFirst = self.readUnsignedInt(2)
        rowLast  = self.readUnsignedInt(2)
        self.appendLine("row range: %d - %d"%(rowFirst, rowLast))

        colFirst = self.readUnsignedInt(2)
        colLast  = self.readUnsignedInt(2)
        self.appendLine("col range: %d - %d"%(colFirst,colLast))

        rowHeadFirst = self.readUnsignedInt(2)
        rowDataFirst = self.readUnsignedInt(2)
        colDataFirst = self.readUnsignedInt(2)
        self.appendLine("heading row: %d"%rowHeadFirst)
        self.appendLine("data row: %d"%rowDataFirst)
        self.appendLine("data col: %d"%colDataFirst)

        cacheIndex = self.readUnsignedInt(2)
        self.appendLine("cache index: %d"%cacheIndex)

        self.readBytes(2)

        dataFieldAxis = self.readUnsignedInt(2)
        self.appendLine("default data field axis: %d"%dataFieldAxis)

        dataFieldPos = self.readUnsignedInt(2)
        self.appendLine("default data field pos: %d"%dataFieldPos)

        numFields = self.readUnsignedInt(2)
        numRowFields = self.readUnsignedInt(2)
        numColFields = self.readUnsignedInt(2)
        numPageFields = self.readUnsignedInt(2)
        numDataFields = self.readUnsignedInt(2)
        numDataRows = self.readUnsignedInt(2)
        numDataCols = self.readUnsignedInt(2)
        self.appendLine("field count: %d"%numFields)
        self.appendLine("row field count: %d"%numRowFields)
        self.appendLine("col field count: %d"%numColFields)
        self.appendLine("page field count: %d"%numPageFields)
        self.appendLine("data field count: %d"%numDataFields)
        self.appendLine("data row count: %d"%numDataRows)
        self.appendLine("data col count: %d"%numDataCols)

        # option flags (TODO: display these later.)
        flags = self.readUnsignedInt(2)

        # autoformat index
        autoFmtIndex = self.readUnsignedInt(2)
        self.appendLine("autoformat index: %d"%autoFmtIndex)

        nameLenTable = self.readUnsignedInt(2)
        nameLenDataField = self.readUnsignedInt(2)
        text, nameLenTable = globals.getRichText(self.readBytes(nameLenTable+1), nameLenTable)
        self.appendLine("PivotTable name: %s"%text)
        text, nameLenDataField = globals.getRichText(self.readBytes(nameLenDataField+1), nameLenDataField)
        self.appendLine("data field name: %s"%text)


class SXViewSource(BaseRecordHandler):

    def parseBytes (self):
        if self.size != 2:
            return

        src = globals.getSignedInt(self.bytes)
        srcType = 'unknown'
        if src == 0x01:
            srcType = 'internal range (followed by DConRef, DConName or DConBin)'
        elif src == 0x02:
            srcType = 'external data source (followed by DbQuery)'
        elif src == 0x04:
            srcType = 'multiple consolidation ranges (followed by SXTbl)'
        elif src == 0x10:
            srcType = 'scenario (temporary internal structure)'

        self.appendLine("data source type: %s"%srcType)


class MergeCells(BaseRecordHandler):

    def __parseBytes (self):
        self.cmcs = self.readUnsignedInt(2)
        self.rgref = []
        for i in xrange(0, self.cmcs):
            self.rgref.append(Ref8(self))

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("%d merge ranges:"%self.cmcs)
        i = 0
        for ref in self.rgref:
            i += 1
            self.appendLine("%d: %s"%(i,ref.toString()))


class Sxvd(BaseRecordHandler):

    def __parseBytes (self):
        flag = self.readUnsignedInt(2)
        self.sxaxisRw   = (flag & 0x0001) != 0
        self.sxaxisCol  = (flag & 0x0002) != 0
        self.sxaxisPage = (flag & 0x0004) != 0
        self.sxaxisData = (flag & 0x0008) != 0
        self.cSub = self.readUnsignedInt(2)
        flag = self.readUnsignedInt(2)
        self.fDefault   = (flag & 0x0001) != 0 # A
        self.fSum       = (flag & 0x0002) != 0 # B
        self.fCounta    = (flag & 0x0004) != 0 # C
        self.fAverage   = (flag & 0x0008) != 0 # D
        self.fMax       = (flag & 0x0010) != 0 # E
        self.fMin       = (flag & 0x0020) != 0 # F
        self.fProduct   = (flag & 0x0040) != 0 # G
        self.fCount     = (flag & 0x0080) != 0 # H
        self.fStdev     = (flag & 0x0100) != 0 # I
        self.fStdevp    = (flag & 0x0200) != 0 # J
        self.fVariance  = (flag & 0x0400) != 0 # K
        self.fVariancep = (flag & 0x0800) != 0 # L
        self.cItm = self.readSignedInt(2)
        cchName = self.readUnsignedInt(2)
        self.stName = '(null)'
        if cchName != 0xFFFF:
            self.stName = self.readXLUnicodeStringNoCch(cchName)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("axes type")
        self.appendLineBoolean("  row", self.sxaxisRw)
        self.appendLineBoolean("  column", self.sxaxisCol)
        self.appendLineBoolean("  page", self.sxaxisPage)
        self.appendLineBoolean("  data", self.sxaxisData)
        self.appendLineInt("subtotal count", self.cSub)
        self.appendLineBoolean("  default", self.fDefault)
        self.appendLineBoolean("  sum", self.fSum)
        self.appendLineBoolean("  counta", self.fCounta)
        self.appendLineBoolean("  average", self.fAverage)
        self.appendLineBoolean("  max", self.fMax)
        self.appendLineBoolean("  min", self.fMin)
        self.appendLineBoolean("  product", self.fProduct)
        self.appendLineBoolean("  count", self.fCount)
        self.appendLineBoolean("  stdev", self.fStdev)
        self.appendLineBoolean("  stdevp", self.fStdevp)
        self.appendLineBoolean("  variance", self.fVariance)
        self.appendLineBoolean("  variancep", self.fVariancep)
        self.appendLineInt("number of SXVI records that follow", self.cItm)
        self.appendLineString("caption", self.stName)

class SXViewFieldsEx(BaseRecordHandler):

    def __parseBytes (self):
        flag = self.readUnsignedInt(2)
        self.showAllItems      = (flag & 0x0001) != 0 # A
        self.dragToRow         = (flag & 0x0002) != 0 # B
        self.dragToColumn      = (flag & 0x0004) != 0 # C
        self.dragToPage        = (flag & 0x0008) != 0 # D
        self.dragToHide        = (flag & 0x0010) != 0 # E
        self.disableDragToData = (flag & 0x0020) != 0 # F
        reserved               = (flag & 0x0040) != 0 # G
        self.serverBased       = (flag & 0x0080) != 0 # H
        reserved               = (flag & 0x0100) != 0 # I
        self.autoSort          = (flag & 0x0200) != 0 # J
        self.ascendSort        = (flag & 0x0400) != 0 # K
        self.autoShow          = (flag & 0x0800) != 0 # L
        self.topAutoShow       = (flag & 0x1000) != 0 # M
        self.calculatedField   = (flag & 0x2000) != 0 # N
        self.insertPageBreaks  = (flag & 0x4000) != 0 # O
        self.hideNewItems      = (flag & 0x8000) != 0 # P

        flag = self.readUnsignedInt(1)
        # skip the first 5 bits.
        self.outlineForm       = (flag & 0x20) != 0 # Q
        self.insertBlankRow    = (flag & 0x40) != 0 # R
        self.subtotalAtTop     = (flag & 0x80) != 0 # S

        # number of items to show in auto show mode.
        self.autoShowCount = self.readUnsignedInt(1)

        self.autoSortItem = self.readSignedInt(2)
        self.autoShowItem = self.readSignedInt(2)
        self.numberFormat = self.readUnsignedInt(2)

        nameLen = self.readUnsignedInt(2)
        self.subName = None
        if nameLen != 0xFFFF:
            self.readBytes(8) # ignored
            self.subName, byteLen = getRichText(self.readRemainingBytes(), nameLen)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineBoolean("show all items", self.showAllItems)
        self.appendLineBoolean("drag to row", self.dragToRow)
        self.appendLineBoolean("drag to column", self.dragToColumn)
        self.appendLineBoolean("drag to page", self.dragToPage)
        self.appendLineBoolean("drag to hide", self.dragToHide)
        self.appendLineBoolean("disable drag to data", self.disableDragToData)
        self.appendLineBoolean("server based", self.serverBased)
        self.appendLineBoolean("auto sort", self.autoSort)
        self.appendLineBoolean("ascending sort", self.ascendSort)
        self.appendLineBoolean("auto show", self.autoShow)
        self.appendLineBoolean("top auto show", self.topAutoShow)
        self.appendLineBoolean("calculated field", self.calculatedField)
        self.appendLineBoolean("insert page breaks", self.insertPageBreaks)
        self.appendLineBoolean("hide new items after refresh", self.hideNewItems)

        self.appendLineBoolean("outline form", self.outlineForm)
        self.appendLineBoolean("insert blank row", self.insertBlankRow)
        self.appendLineBoolean("subtotal at top", self.subtotalAtTop)

        self.appendLine("items to show in auto show: %d"%self.autoShowCount)

        if self.autoSort:
            if self.autoSortItem == -1:
                self.appendLine("auto sort: sort by pivot items themselves")
            else:
                self.appendLine("auto sort: sort by data item %d"%self.autoSortItem)

        if self.autoShow:
            if self.autoShowItem == -1:
                self.appendLine("auto show: not enabled")
            else:
                self.appendLine("auto show: use data item %d"%self.autoShowItem)

        self.appendLine("number format: %d"%self.numberFormat)

        if self.subName == None:
            self.appendLine("aggregate function: none")
        else:
            self.appendLine("aggregate function: %s"%self.subName)


class SXDataItem(BaseRecordHandler):

    functionType = {
        0x00: 'sum',
        0x01: 'count',
        0x02: 'average',
        0x03: 'max',
        0x04: 'min',
        0x05: 'product',
        0x06: 'count nums',
        0x07: 'stddev',
        0x08: 'stddevp',
        0x09: 'var',
        0x0A: 'varp'
    }

    displayFormat = {
        0x00: 'normal',
        0x01: 'difference from',
        0x02: 'percentage of',
        0x03: 'perdentage difference from',
        0x04: 'running total in',
        0x05: 'percentage of row',
        0x06: 'percentage of column',
        0x07: 'percentage of total',
        0x08: 'index'
    }

    def parseBytes (self):
        isxvdData = self.readUnsignedInt(2)
        funcIndex = self.readUnsignedInt(2)

        # data display format
        df = self.readUnsignedInt(2)

        # index to the SXVD/SXVI records used by the data display format
        sxvdIndex = self.readUnsignedInt(2)
        sxviIndex = self.readUnsignedInt(2)

        # index to the format table for this item
        fmtIndex = self.readUnsignedInt(2)

        # name
        nameLen = self.readSignedInt(2)
        name, nameLen = globals.getRichText(self.readRemainingBytes(), nameLen)

        self.appendLine("field that this data item is based on: %d"%isxvdData)
        funcName = '(unknown)'
        if SXDataItem.functionType.has_key(funcIndex):
            funcName = SXDataItem.functionType[funcIndex]
        self.appendLine("aggregate function: %s"%funcName)
        dfName = '(unknown)'
        if SXDataItem.displayFormat.has_key(df):
            dfName = SXDataItem.displayFormat[df]
        self.appendLine("data display format: %s"%dfName)
        self.appendLine("SXVD record index: %d"%sxvdIndex)
        self.appendLine("SXVI record index: %d"%sxviIndex)
        self.appendLine("format table index: %d"%fmtIndex)

        if nameLen == -1:
            self.appendLine("name: null (use name in the cache)")
        else:
            self.appendLine("name: %s"%name)

        return

class SXPageItem(BaseRecordHandler):

    class Item(object):

        def __init__ (self, strm):
            self.isxvd = strm.readSignedInt(2)
            self.isxvi = strm.readSignedInt(2)
            self.idObj = strm.readSignedInt(2)

        def appendLines (self, parent):
            parent.appendLine("item")
            parent.appendLine("  field index: %d"%self.isxvd)
            if self.isxvi == 0x7FFD:
                parent.appendLine("  index of selected item: all")
            else:
                # Index of SXVI record, not of cache item in pivot cache.
                # SXVI record holds the index of the cache item in pivot cache.
                # Don't get confused.
                parent.appendLine("  index of selected item: %d"%self.isxvi)
            parent.appendLine("  OBJ record ID for page item drop-down arrow: %d"%self.idObj)

    def __parseBytes (self):
        self.items = []
        while not self.isEndOfRecord():
            item = SXPageItem.Item(self)
            self.items.append(item)

    def parseBytes (self):
        self.__parseBytes()
        for item in self.items:
            item.appendLines(self)


class SXVI(BaseRecordHandler):

    itemTypes = {
        0xFE: 'Page',
        0xFF: 'Null',
        0x00: 'Data value',
        0x01: 'Default subtotal',
        0x02: 'SUM',
        0x03: 'COUNTA',
        0x04: 'COUNT',
        0x05: 'AVERAGE',
        0x06: 'MAX',
        0x07: 'MIN',
        0x08: 'PRODUCT',
        0x09: 'STDEV',
        0x0A: 'STDEVP',
        0x0B: 'VAR',
        0x0C: 'VARP',
        0x0D: 'Grand total',
        0x0E: 'blank'
    }

    def __parseBytes (self):
        self.itmType = self.readSignedInt(2)
        flag = self.readUnsignedInt(1)

        self.fHidden     = (flag & 0x01) != 0
        self.fHideDetail = (flag & 0x02) != 0
        reserved         = (flag & 0x04) != 0
        self.fFormula    = (flag & 0x08) != 0
        self.fMissing    = (flag & 0x10) != 0

        self.readBytes(1) # reserved

        self.iCache = self.readSignedInt(2)
        cch = self.readSignedInt(2)
        if cch > 0:
            self.name = self.readXLUnicodeStringNoCch()
        else:
            self.name = "null (use name in the cache)"

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineString("item type", globals.getValueOrUnknown(SXVI.itemTypes, self.itmType))
        self.appendLineBoolean("hidden", self.fHidden)
        self.appendLineBoolean("collapsed", self.fHideDetail)
        self.appendLineBoolean("calcualted", self.fFormula)
        self.appendLineBoolean("missing in data source", self.fMissing)
        if self.iCache >= 0:
            self.appendLineInt("cache item index", self.iCache)
        else:
            self.appendLine("cache item index: %d (no cache item is referenced)"%self.iCache)
        self.appendLineString("name", self.name)


class PivotQueryTableEx(BaseRecordHandler):
    """QSISXTAG: Pivot Table and Query Table Extensions (802h)"""
    excelVersionList = [
        'Excel 2000',
        'Excel XP',
        'Excel 2003',
        'Excel 2007'
    ]

    class TableType:
        QueryTable = 0
        PivotTable = 1

    def getExcelVersion (self, lastExcelVer):
        s = '(unknown)'
        if lastExcelVer < len(PivotQueryTableEx.excelVersionList):
            s = PivotQueryTableEx.excelVersionList[lastExcelVer]
        return s

    def parseBytes (self):
        recordType = self.readUnsignedInt(2)
        self.appendLine("record type (always 0802h): %4.4Xh"%recordType)
        dummyFlags = self.readUnsignedInt(2)
        self.appendLine("flags (must be zero): %4.4Xh"%dummyFlags)
        tableType = self.readUnsignedInt(2)
        s = '(unknown)'
        if tableType == PivotQueryTableEx.TableType.QueryTable:
            s = 'query table'
        elif tableType == PivotQueryTableEx.TableType.PivotTable:
            s = 'pivot table'
        self.appendLine("this record is for: %s"%s)

        # general flags
        flags = self.readUnsignedInt(2)
        enableRefresh = (flags & 0x0001)
        invalid       = (flags & 0x0002)
        tensorEx      = (flags & 0x0004)
        s = '(unknown)'
        if enableRefresh:
            s = 'ignore'
        else:
            s = 'check'
        self.appendLine("check for SXDB or QSI for table refresh: %s"%s)
        self.appendLine("PivotTable cache is invalid: %s"%self.getYesNo(invalid))
        self.appendLine("This is an OLAP PivotTable report: %s"%self.getYesNo(tensorEx))

        # feature-specific options
        featureOptions = self.readUnsignedInt(4)
        if tableType == PivotQueryTableEx.TableType.QueryTable:
            # query table
            preserveFormat = (featureOptions & 0x00000001)
            autoFit        = (featureOptions & 0x00000002)
            self.appendLine("keep formatting applied by the user: %s"%self.getYesNo(preserveFormat))
            self.appendLine("auto-fit columns after refresh: %s"%self.getYesNo(autoFit))
        elif tableType == PivotQueryTableEx.TableType.PivotTable:
            # pivot table
            noStencil         = (featureOptions & 0x00000001)
            hideTotAnnotation = (featureOptions & 0x00000002)
            includeEmptyRow   = (featureOptions & 0x00000008)
            includeEmptyCol   = (featureOptions & 0x00000010)
            self.appendLine("no large drop zones if no data fields: %s"%self.getTrueFalse(noStencil))
            self.appendLine("no asterisk for the total in OLAP table: %s"%self.getTrueFalse(hideTotAnnotation))
            self.appendLine("retrieve and show empty rows from OLAP source: %s"%self.getTrueFalse(includeEmptyRow))
            self.appendLine("retrieve and show empty columns from OLAP source: %s"%self.getTrueFalse(includeEmptyCol))

        self.appendLine("table last refreshed by: %s"%
            self.getExcelVersion(self.readUnsignedInt(1)))

        self.appendLine("minimal version that can refresh: %s"%
            self.getExcelVersion(self.readUnsignedInt(1)))

        offsetBytes = self.readUnsignedInt(1)
        self.appendLine("offset from first FRT byte to first cchName byte: %d"%offsetBytes)

        self.appendLine("first version that created the table: %s"%
            self.getExcelVersion(self.readUnsignedInt(1)))

        textLen = self.readUnsignedInt(2)
        name, textLen = globals.getRichText(self.readRemainingBytes(), textLen)
        self.appendLine("table name: %s"%name)
        return


class SXDouble(BaseRecordHandler):

    def __parseBytes (self):
        self.val = self.readDouble()
        self.strmData.pivotCacheFields[-1].values.append("%g"%self.val)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("value: %g"%self.val)


class SXBoolean(BaseRecordHandler):
    def parseBytes (self):
        pass

class SXError(BaseRecordHandler):
    def parseBytes (self):
        pass


class SXInt(BaseRecordHandler):

    def __parseBytes (self):
        self.num = self.readSignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineInt("value", self.num)


class SXString(BaseRecordHandler):

    def __parseBytes (self):
        self.text = self.readXLUnicodeString()
        self.strmData.pivotCacheFields[-1].values.append(self.text)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineString("value", self.text)


class SXRng(BaseRecordHandler):

    groupTypes = [
        "numeric value",
        "seconds",
        "minutes",
        "hours",
        "days",
        "months",
        "quarters",
        "years"
    ]

    def __parseBytes (self):
        flag = self.readUnsignedInt(2)
        self.fAutoStart = (flag & 0x0001) != 0 # A
        self.fAutoEnd   = (flag & 0x0002) != 0 # B
        self.iByType    = (flag & 0x001C) / 4  # C

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineBoolean("auto start", self.fAutoStart)
        self.appendLineBoolean("auto end", self.fAutoEnd)
        self.appendLineString("group type", globals.getValueOrUnknown(SXRng.groupTypes, self.iByType))

# -------------------------------------------------------------------
# CT - Change Tracking

class RRD(object):

    RevType = {
        0x0000: "insert row",                  # REVTINSRW
        0x0001: "insert column",               # REVTINSCOL
        0x0002: "delete row",                  # REVTDELRW
        0x0003: "delete column",               # REVTDELCOL
        0x0004: "cell move",                   # REVTMOVE
        0x0005: "insert sheet",                # REVTINSERTSH
        0x0007: "sort",                        # REVTSORT
        0x0008: "cell change",                 # REVTCHANGECELL
        0x0009: "rename sheet",                # REVTRENSHEET
        0x000A: "defined name change",         # REVTDEFNAME
        0x000B: "format revision",             # REVTFORMAT
        0x000C: "autoformat revision",         # REVTAUTOFMT
        0x000D: "comment revision",            # REVTNOTE
        0x0020: "header (meta-data) revision", # REVTHEADER
        0x0025: "conflict",                    # REVTCONFLICT
        0x002B: "custom view add",             # REVTADDVIEW
        0x002C: "custom view delete",          # REVTDELVIEW
        0x002E: "query table field removal"    # REVTTRASHQTFIELD
    }

    def __init__ (self, parent):
        self.parent = parent
        self.cbMemory = parent.readUnsignedInt(4)
        self.revid = parent.readSignedInt(4)
        self.revt = parent.readUnsignedInt(2)

        flags = parent.readUnsignedInt(2)
        self.fAccepted        = (flags & 0x0001) != 0
        self.fUndoAction      = (flags & 0x0002) != 0
        unused                = (flags & 0x0004) != 0
        self.fDelAtEdgeOfSort = (flags & 0x0008) != 0
        self.tabid = parent.readUnsignedInt(2)

    def parseBytes (self):
        self.parent.appendLineInt("memory size", self.cbMemory)
        self.parent.appendLine("revision ID: %d"%self.revid)
        self.parent.appendLine("revision type: %s (0x%4.4X)"%(globals.getValueOrUnknown(RRD.RevType, self.revt), self.revt))
        self.parent.appendLineBoolean("accepted", self.fAccepted)
        self.parent.appendLineBoolean("undo action", self.fUndoAction)
        self.parent.appendLineBoolean("deleted at edge of sorted range", self.fDelAtEdgeOfSort)
        self.parent.appendLineInt("sheet index", self.tabid)


class RRDChgCell(BaseRecordHandler):

    class CellType:
        Blank                       = 0x0000
        RKNumber                    = 0x0001
        Xnum                        = 0x0002
        XLUnicodeRichExtendedString = 0x0003
        Bes                         = 0x0004
        CellParsedFormula           = 0x0005

    CellTypes = [
        "blank",            # 0x0
        "RK",               # 0x1
        "double",           # 0x2
        "string",           # 0x3
        "boolean or error", # 0x4
        "formula"           # 0x5
    ]

    NumFmtTypes = {
        0x0000: "automatic",
        0x0004: "number, two decimal places, use the 1000 separator (,)",
        0x000B: "currency, two decimal places, use parentheses for negative values",
        0x000D: "percentage, zero decimal places",
        0x000E: "percentage, two decimal places",
        0x000F: "scientific",
        0x0010: "engineering",
        0x0011: "fraction, up to one digit numerator and denominator",
        0x0012: "fraction, up to two digit numerator and denominator",
        0x0013: "date (MM-DD-YY)",
        0x0015: "date (DD-MMM)",
        0x0017: "time (H:MM AM/PM)",
        0x001B: "date/time, 24 hour format (M/D/YY H:MM)",
        0x0022: "accounting (currency with decimal point aligned, and centered minus-sign for 0-value), two decimal places, use currency symbol"
    }

    def __parseBytes (self):
        self.rrd = RRD(self)
        flags = self.readUnsignedInt(2)
        self.vt    = (flags & 0x0007)
        flags /= 2**3 # shift 3 bits
        self.vtOld = (flags & 0x0007)
        flags /= 2**3 # shift 3 bits
        self.f123Prefix  = (flags & 0x0001)
        unused           = (flags & 0x0002)
        self.fOldFmt     = (flags & 0x0004)
        self.fOldFmtNull = (flags & 0x0008)
        self.fXfDxf      = (flags & 0x0010)
        self.fStyXfDxf   = (flags & 0x0020)
        self.fDxf        = (flags & 0x0040)
        self.fDxfNull    = (flags & 0x0080)

        self.ifmtDisp = self.readUnsignedInt(1)

        flags = self.readUnsignedInt(1)
        self.fPhShow        = (flags & 0x01)
        self.fPhShowOld     = (flags & 0x02)
        self.fEOLFmlaUpdate = (flags & 0x04)

        self.loc = RgceLoc(self)

        self.cbOldVal = self.readUnsignedInt(4)
        self.cetxpRst = self.readUnsignedInt(2)

        if self.fOldFmt or self.fDxf:
            # TODO : Parse DXFN
            return

        # old value
        if self.vtOld == RRDChgCell.CellType.Blank:
            pass
        elif self.vtOld == RRDChgCell.CellType.RKNumber:
            self.rkOld = decodeRK(self.readUnsignedInt(4))
        elif self.vtOld == RRDChgCell.CellType.Xnum:
            self.numOld = self.readDouble()
        elif self.vtOld == RRDChgCell.CellType.XLUnicodeRichExtendedString:
            self.stOld = self.readXLUnicodeRichExtendedString()
        elif self.vtOld == RRDChgCell.CellType.Bes:
            self.besOld = Bes(self)
        elif self.vtOld == RRDChgCell.CellType.CellParsedFormula:
            self.xpeOld = CellParsedFormula(self)

        # new value
        if self.vt == RRDChgCell.CellType.Blank:
            pass
        elif self.vt == RRDChgCell.CellType.RKNumber:
            self.rk = decodeRK(self.readUnsignedInt(4))
        elif self.vt == RRDChgCell.CellType.Xnum:
            self.num = self.readDouble()
        elif self.vt == RRDChgCell.CellType.XLUnicodeRichExtendedString:
            self.st = self.readXLUnicodeRichExtendedString()
        elif self.vt == RRDChgCell.CellType.Bes:
            self.bes = Bes(self)
        elif self.vt == RRDChgCell.CellType.CellParsedFormula:
            self.xpe = CellParsedFormula(self)

    def parseBytes (self):
        self.__parseBytes()
        self.rrd.parseBytes()
        self.appendLineString("old cell type", globals.getValueOrUnknown(RRDChgCell.CellTypes,self.vtOld))
        self.appendLineString("new cell type", globals.getValueOrUnknown(RRDChgCell.CellTypes,self.vt))
        self.appendLineBoolean("prefix characters present", self.f123Prefix)
        self.appendLineBoolean("old formatting available", self.fOldFmt)
        self.appendLineBoolean("old formatting empty", self.fOldFmtNull)
        self.appendLineBoolean("reset to cell style first", self.fXfDxf)
        self.appendLineBoolean("clear cell format first", self.fStyXfDxf)
        self.appendLineBoolean("format has changed", self.fDxf)
        self.appendLineBoolean("new formatting empty", self.fDxfNull)
        self.appendLineString("number format for new value", globals.getValueOrUnknown(RRDChgCell.NumFmtTypes,self.ifmtDisp))
        self.appendLineBoolean("new cell has phonetic string", self.fPhShow)
        self.appendLineBoolean("old cell has phonetic string", self.fPhShowOld)
        self.appendLineBoolean("new cell is formula update", self.fEOLFmlaUpdate)
        self.appendLineString("cell position", self.loc.toString())
        self.appendLineInt("old cell content size", self.cbOldVal)
        self.appendLineInt("number of RRDRstEtxp records", self.cetxpRst)

        if self.fOldFmt or self.fDxf:
            # TODO : Parse DXFN.
            return

        # old value
        if self.vtOld == RRDChgCell.CellType.Blank:
            self.appendLine("old value: blank")
        elif self.vtOld == RRDChgCell.CellType.RKNumber:
            self.appendLine("old value: %g"%self.rkOld)
        elif self.vtOld == RRDChgCell.CellType.Xnum:
            self.appendLine("old value: %g"%self.numOld)
        elif self.vtOld == RRDChgCell.CellType.XLUnicodeRichExtendedString:
            self.appendLineString("old value", self.stOld)
        elif self.vtOld == RRDChgCell.CellType.Bes:
            self.appendLineString("old value", self.besOld.toString())
        elif self.vtOld == RRDChgCell.CellType.CellParsedFormula:
            self.appendLineString("old value", self.xpeOld.toString())

        # new value
        if self.vt == RRDChgCell.CellType.Blank:
            self.appendLine("new value: blank")
        elif self.vt == RRDChgCell.CellType.RKNumber:
            self.appendLine("new value: %g"%self.rk)
        elif self.vt == RRDChgCell.CellType.Xnum:
            self.appendLine("new value: %g"%self.num)
        elif self.vt == RRDChgCell.CellType.XLUnicodeRichExtendedString:
            self.appendLineString("new value", self.st)
        elif self.vt == RRDChgCell.CellType.Bes:
            self.appendLineString("new value", self.bes.toString())
        elif self.vt == RRDChgCell.CellType.CellParsedFormula:
            self.appendLineString("new value", self.xpe.toString())


class RRDInsDel(BaseRecordHandler):

    def __parseBytes (self):
        self.rrd = RRD(self)
        flags = self.readUnsignedInt(2)
        self.fEndOfList = (flags & 0x0001) != 0
        self.refn = Ref8U(self)
        self.cUcr = self.readUnsignedInt(4)
        # TODO : parse optional undo data.

    def parseBytes (self):
        self.__parseBytes()
        self.rrd.parseBytes()
        self.appendLineBoolean("row inserted at bottom", self.fEndOfList)
        self.appendLineString("range", self.refn.toString())
        self.appendLineInt("number of items in undo data", self.cUcr)


# -------------------------------------------------------------------
# CH - Chart


class Header(BaseRecordHandler):
    def dumpData(self):
        return ('header', {})

class Footer(BaseRecordHandler):
    def dumpData(self):
        return ('footer', {})

class HCenter(BaseRecordHandler):
    def __parseBytes(self):
        self.val = self.readUnsignedInt(2)

    def dumpData(self):
        self.__parseBytes()
        return ('hcenter', {'val': self.val})

class VCenter(BaseRecordHandler):
    def __parseBytes(self):
        self.val = self.readUnsignedInt(2)

    def dumpData(self):
        self.__parseBytes()
        return ('vcenter', {'val': self.val})

class Setup(BaseRecordHandler):
    def dumpData(self):
        return ('setup', {})

class Units(BaseRecordHandler):
    def dumpData(self):
        return ('units', {})

class Begin(BaseRecordHandler):
	pass

class PlotArea(BaseRecordHandler):
    def dumpData(self):
        return ('plot-area', {})

class CrtLink(BaseRecordHandler): # it's unused
    def dumpData(self):
        return ('crt-link', {})

class End(BaseRecordHandler):
	pass

class Chart(BaseRecordHandler):
    def __parseBytes(self):
        self.x = globals.getSignedInt(self.bytes[0:4])
        self.y = globals.getSignedInt(self.bytes[4:8])
        self.w = globals.getSignedInt(self.bytes[8:12])
        self.h = globals.getSignedInt(self.bytes[12:16])

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("position: (x, y) = (%d, %d)"%(self.x, self.y))
        self.appendLine("size: (width, height) = (%d, %d)"%(self.w, self.h))

    def dumpData(self):
        self.__parseBytes()
        return ('chart-xfrm', {'x': self.x,
                               'y': self.y,
                               'w': self.w,
                               'h': self.h})

class Frame(BaseRecordHandler):
    __frt_table = {0x0000: "frame surrounding the chart element",
                   0x0004: "frame with a shadow surrounding the chart element"}

    def __parseBytes(self):
        self.frt = self.readUnsignedInt(2)
        flags = self.readUnsignedInt(2)
        self.autoSize = (flags & 0x001) != 0
        self.autoPosition = (flags & 0x002) != 0

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("frame type: %s" % Frame.__frt_table[self.frt])
        self.appendLine("autoSize: %s" % self.autoSize)
        self.appendLine("autoPosition: %s" % self.autoPosition)

    def dumpData(self):
        self.__parseBytes()
        return ('frame', {'frt': self.frt,
                          'auto-size': self.autoSize,
                          'auto-position': self.autoPosition})

class LineFormat(BaseRecordHandler):

    lineStyles = [
        'Solid',               # 0x0000
        'Dash',                # 0x0001
        'Dot',                 # 0x0002
        'Dash-dot',            # 0x0003
        'Dash dot-dot ',       # 0x0004
        'None',                # 0x0005
        'Dark gray pattern',   # 0x0006
        'Medium gray pattern', # 0x0007
        'Light gray pattern '  # 0x0008
    ]

    def __parseBytes(self):
        self.rgb = self.readLongRGB()
        self.lns = self.readUnsignedInt(2)
        self.we = self.readUnsignedInt(2)
        flags = self.readUnsignedInt(2)
        self.auto = (flags & 0x001) != 0 # A
        unused = (flags & 0x002) != 0 # B (unused)
        self.axisOn = (flags & 0x004) != 0 # C
        self.autoCo = (flags & 0x008) != 0 # D
        self.icv = self.readICV()

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineString("line color", self.rgb.toString())
        self.appendLineString("line style",
            globals.getValueOrUnknown(LineFormat.lineStyles, self.lns))

    def dumpData(self):
        self.__parseBytes()
        return ('line-format', {'lns': self.lns,
                                'we': self.we,
                                'auto': self.auto,
                                'axis-on': self.axisOn,
                                'auto-co': self.autoCo},
                                [('rgb', dumpRgb(self.rgb)),
                                 ('icv', dumpIcv(self.icv))])

class AreaFormat(BaseRecordHandler):
    def __parseBytes(self):
        self.foreColor = self.readLongRGB()
        self.backColor = self.readLongRGB()
        self.fls = self.readUnsignedInt(2)
        flags = self.readUnsignedInt(2)
        self.auto = (flags & 0x001) != 0 # A
        self.invertNeg = (flags & 0x002) != 0 # B
        self.icvFore = self.readICV()
        self.icvBack = self.readICV()

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineString("foreground color", self.foreColor.toString())
        self.appendLineString("background color", self.backColor.toString())
        self.appendLineBoolean("automatic fill color", self.auto)
        self.appendLineBoolean("foreground and background colors inverted", self.invertNeg)

    def dumpData(self):
        self.__parseBytes()
        return ('area-format', {'fls': self.fls,
                                'auto': self.auto,
                                'invert-neg': self.invertNeg},
                                [('fore-color', dumpRgb(self.foreColor)),
                                 ('back-color', dumpRgb(self.backColor)),
                                 ('icv-fore', dumpIcv(self.icvFore)),
                                 ('icv-back', dumpIcv(self.icvBack))])

class PieFormat(BaseRecordHandler):
    def __parseBytes(self):
        self.pcExplode = self.readSignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        # TODO: dump all data

    def dumpData(self):
        self.__parseBytes()
        return ('pie-format', {'pc-explode': self.pcExplode})

class MarkerFormat(BaseRecordHandler):
    def __parseBytes(self):
        self.rgbFore = self.readLongRGB()
        self.rgbBack = self.readLongRGB()
        self.imk = self.readUnsignedInt(2)
        flags = self.readUnsignedInt(2)
        self.auto = (flags & 0x001) != 0 # A
        # next 3 bits are reserved
        self.notShowInt = (flags & 0x010) != 0 # C
        self.notShowBrd = (flags & 0x020) != 0 # D
        self.icvFore = self.readICV()
        self.icvBack = self.readICV()
        self.miSize = self.readUnsignedInt(4)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLineString("foreground color", self.rgbFore.toString())
        self.appendLineString("background color", self.rgbBack.toString())

    def dumpData(self):
        self.__parseBytes()
        return ('marker-format', {'imk': self.imk,
                                  'auto': self.auto,
                                  'not-show-int': self.notShowInt,
                                  'not-show-brd': self.notShowBrd,
                                  'mi-size': self.miSize},
                                [('rgb-fore', dumpRgb(self.rgbFore)),
                                 ('rgb-back', dumpRgb(self.rgbBack)),
                                 ('icv-fore', dumpIcv(self.icvFore)),
                                 ('icv-back', dumpIcv(self.icvBack))])

class DataFormat(BaseRecordHandler):
    def __parseBytes(self):
        self.xi = self.readUnsignedInt(2)
        self.yi = self.readUnsignedInt(2)
        self.iss = self.readUnsignedInt(2)
        flags = self.readUnsignedInt(2)
        unused = (flags & 0x001) != 0 # A (??? - not described in docs)

    def parseBytes (self):
        self.__parseBytes()
        # TODO: dump all data

    def dumpData(self):
        self.__parseBytes()
        return ('data-format', {'xi': self.xi,
                                'yi': self.yi,
                                'iss': self.iss})

class SerFmt(BaseRecordHandler):
    def __parseBytes(self):
        flags = self.readUnsignedInt(2)
        self.smoothedLine = (flags & 0x001) != 0
        self.bubbles3D = (flags & 0x002) != 0
        self.arShadow = (flags & 0x004) != 0

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Smoothed line: %s" % self.getTrueFalse(self.smoothedLine))
        self.appendLine("3D bubbles: %s" % self.getTrueFalse(self.bubbles3D))
        self.appendLine("With shadow: %s" % self.getTrueFalse(self.arShadow))

    def dumpData(self):
        self.__parseBytes()
        return ('ser-fmt', {'smoothed-line': self.smoothedLine,
                            'bubbles-3d': self.bubbles3D,
                            'ar-shadow': self.arShadow})

class ChartFormat(BaseRecordHandler):
    def __parseBytes(self):
        reserved1 = self.readUnsignedInt(4)
        reserved2 = self.readUnsignedInt(4)
        reserved3 = self.readUnsignedInt(4)
        reserved4 = self.readUnsignedInt(4)
        flags = self.readUnsignedInt(2)
        self.varied = (flags & 0x001) != 0 # A
        self.icrt = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        # TODO: dump all data

    def dumpData(self):
        self.__parseBytes()
        return ('chart-format', {'varied': self.varied,
                                 'icrt': self.icrt})

class DataLabExtContents(BaseRecordHandler):
    def __parseBytes(self):
        self.header = self.readFrtHeader()
        flags = self.readUnsignedInt(2)
        self.serName = (flags & 0x001) != 0 # A
        self.catName = (flags & 0x002) != 0 # B
        self.value = (flags & 0x004) != 0 # C
        self.percent = (flags & 0x008) != 0 # D
        self.bubSizes = (flags & 0x010) != 0 # E
        self.sep = self.readUnicodeString()

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Header: %s, %s" % (str(self.header.rt), str(self.header.flags)))
        self.appendLine("Display series name: %s" % self.getTrueFalse(self.serName))
        self.appendLine("Display categories name: %s" % self.getTrueFalse(self.catName))
        self.appendLine("Display value: %s" % self.getTrueFalse(self.value))
        self.appendLine("Is a percent: %s" % self.getTrueFalse(self.percent))
        self.appendLine("Display bubble size: %s" % self.getTrueFalse(self.bubSizes))
        self.appendLine("Separator: %s" % str(self.sep))

    def dumpData(self):
        self.__parseBytes()
        return ('datalab-ext-contents', {'ser-name': self.serName,
                                         'cat-name': self.catName,
                                         'value': self.value,
                                         'percent': self.percent,
                                         'bub-sizes': self.bubSizes,
                                         'sep': self.sep},
                                        [('header', dumpFrtHeader(self.header))])

class ChartFrtInfo(BaseRecordHandler):
    def __parseBytes(self):
        self.headerOld = self.readUnsignedInt(4)
        self.verOriginator = self.readUnsignedInt(1)
        self.verWriter = self.readUnsignedInt(1)
        self.cCFRTID = self.readUnsignedInt(2)
        self.cfrtids = []
        for x in xrange(self.cCFRTID):
            self.cfrtids.append(self.readCFRTID())

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Header old: %s" % str(self.headerOld))
        self.appendLine("verOriginator (version of app that created the file): %s" % str(self.verOriginator))
        self.appendLine("verWriter (version of app that last saved the file): %s" % str(self.verWriter))
        self.appendLine("Count of CFRTID records: %s" % str(self.cCFRTID))
        for cfrtid in self.cfrtids:
            self.appendLine("CFRTID: [%s, %s]" % (cfrtid.start, cfrtid.end))

    def dumpData(self):
        self.__parseBytes()
        return ('chart-frt-info', {'header-old': self.headerOld,
                                   'ver-originator': self.verOriginator,
                                   'ver-writer': self.verWriter,
                                   'cfrtid-count': self.cCFRTID},
                                   [('cfrtid-list', map(lambda x: ('cfrtid', dumpCfrtid(x)),
                                                           self.cfrtids))])

class StartBlock(BaseRecordHandler):
    def __parseBytes(self):
        self.headerOld = self.readUnsignedInt(4)
        self.objectKind = self.readUnsignedInt(2)
        self.objectContext = self.readUnsignedInt(2)
        self.objectInstance1 = self.readUnsignedInt(2)
        self.objectInstance2 = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Header old: %s" % str(self.headerOld))
        self.appendLine("Object kind: %s" % str(self.objectKind))
        self.appendLine("Object context: %s" % str(self.objectContext))
        self.appendLine("Object instance 1: %s" % str(self.objectInstance1))
        self.appendLine("Object instance 2: %s" % str(self.objectInstance2))

    def dumpData(self):
        self.__parseBytes()
        return ('start-block', {'header-old': self.headerOld,
                                'object-kind': self.objectKind,
                                'object-context': self.objectContext,
                                'object-instance1': self.objectInstance1,
                                'object-instance2': self.objectInstance2})

class EndBlock(BaseRecordHandler):
    def __parseBytes(self):
        self.headerOld = self.readUnsignedInt(4)
        self.objectKind = self.readUnsignedInt(2)
        unused = self.readUnsignedInt(2)
        unused = self.readUnsignedInt(2)
        unused = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Header old: %s" % str(self.headerOld))
        self.appendLine("Object kind: %s" % str(self.objectKind))

    def dumpData(self):
        self.__parseBytes()
        return ('end-block', {'header-old': self.headerOld,
                                'object-kind': self.objectKind})

class CatLab(BaseRecordHandler):
    def __parseBytes(self):
        self.headerOld = self.readUnsignedInt(4)
        self.offset = self.readUnsignedInt(2)
        self.at = self.readUnsignedInt(2)
        flags = self.readUnsignedInt(2)
        self.autoCatLabelReal        = (flags & 0x0001) != 0 # A
        reserved = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Header old: %s" % str(self.headerOld))
        self.appendLine("Offset: %s" % str(self.offset))
        self.appendLine("At(alignment): %s" % str(self.at))
        self.appendLine("Auto category label real: %s" % str(self.autoCatLabelReal))

    def dumpData(self):
        self.__parseBytes()
        return ('catlab', {'header-old': self.headerOld,
                           'offset': self.offset,
                           'at': self.at,
                           'auto-catlabel-real': self.autoCatLabelReal})

class Chart3DBarShape(BaseRecordHandler):

    def __parseBytes(self):
        self.riser = self.readUnsignedInt(1)
        self.taper = self.readUnsignedInt(1)

    def parseBytes (self):
        self.__parseBytes()
        s = ''
        if self.riser:
            s = 'ellipse'
        else:
            s = 'rectangle'
        self.appendLineString("base shape of data points", s)
        self.appendLineInt("taper style", self.taper)

    def dumpData(self):
        self.__parseBytes()
        return ('chart-3dbar-shape', {'riser': self.riser,
                                      'taper': self.taper})

class DropBar(BaseRecordHandler):
    def __parseBytes(self):
        self.gap = self.readSignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine('Gap: %s' % str(self.gap))

    def dumpData(self):
        self.__parseBytes()
        return ('drop-bar', {'gap': self.gap})

class CrtLine(BaseRecordHandler):
    def __parseBytes(self):
        self.id = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine('ID: %s' % str(self.id))

    def dumpData(self):
        self.__parseBytes()
        return ('crt-line', {'id': self.id})

class ObjectLink(BaseRecordHandler):
    def __parseBytes(self):
        self.linkObj = self.readUnsignedInt(2)
        self.linkVar1 = self.readUnsignedInt(2)
        self.linkVar2 = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine('Link object: %s' % str(self.linkObj))
        self.appendLine('Link var1: %s' % str(self.linkVar1))
        self.appendLine('Link var2: %s' % str(self.linkVar2))

    def dumpData(self):
        self.__parseBytes()
        return ('object-link', {'link-obj': self.linkObj,
                                'link-var1': self.linkVar1,
                                'link-var2': self.linkVar2})

class AttachedLabel(BaseRecordHandler):
    def __parseBytes(self):
        flag = self.readUnsignedInt(2)
        self.showValue        = (flag & 0x0001) != 0 # A
        self.showPercent          = (flag & 0x0002) != 0 # B
        self.showLabelAndPerc        = (flag & 0x0004) != 0 # C
        unused        = (flag & 0x0008) != 0 # D
        self.showLabel         = (flag & 0x0010) != 0 # E
        self.showBubbleSizes        = (flag & 0x0020) != 0 # F
        self.showSeriesName        = (flag & 0x0040) != 0 # G

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Show value: %s" % self.getTrueFalse(self.showValue))
        self.appendLine("Show percent: %s" % self.getTrueFalse(self.showPercent))
        self.appendLine("Show label and percent: %s" % self.getTrueFalse(self.showLabelAndPerc))
        self.appendLine("Show bubble sizes: %s" % self.getTrueFalse(self.showBubbleSizes))
        self.appendLine("Show series name: %s" % self.getTrueFalse(self.showSeriesName))
        # TODO: dump all data

    def dumpData(self):
        self.__parseBytes()
        return ('attached-label', {'show-value': self.showValue,
                                   'show-percent': self.showPercent,
                                   'show-label-and-perc': self.showLabelAndPerc,
                                   'show-label': self.showLabel,
                                   'show-bubble-sizes': self.showBubbleSizes,
                                   'show-series-name': self.showSeriesName})

class Chart3d(BaseRecordHandler):
    def __parseBytes(self):
        self.rot = self.readSignedInt(2)
        self.elev = self.readSignedInt(2)
        self.dist = self.readSignedInt(2)
        self.height = self.readUnsignedInt(2) # TODO: it can be a signed int too
        self.depth = self.readUnsignedInt(2)
        self.gap = self.readUnsignedInt(2)

        flag = self.readUnsignedInt(2)
        self.perspective        = (flag & 0x0001) != 0 # A
        self.cluster          = (flag & 0x0002) != 0 # B
        self.scaling        = (flag & 0x0004) != 0 # C
        reserved        = (flag & 0x0008) != 0 # D
        self.notPieChart         = (flag & 0x0010) != 0 # E
        self.walls2D        = (flag & 0x0020) != 0 # F

    def parseBytes (self):
        self.__parseBytes()
        # TODO: dump all data

    def dumpData(self):
        self.__parseBytes()
        return ('chart-3d', {'rot': self.rot,
                             'elev': self.elev,
                             'dist': self.dist,
                             'height': self.height,
                             'depth': self.depth,
                             'gap': self.gap,
                             'perspective': self.perspective,
                             'cluster': self.cluster,
                             'scaling': self.scaling,
                             'not-pie-chart': self.notPieChart,
                             'walls-2d': self.walls2D})

class SerToCrt(BaseRecordHandler):
    def __parseBytes(self):
        self.id = self.readUnsignedInt(2)

    def dumpData(self):
        self.__parseBytes()
        return ('ser-to-crt', {'id': self.id})

class Pos(BaseRecordHandler):
    def __parseBytes(self):
        self.mdTopLt = self.readUnsignedInt(2)
        self.mdBotRt = self.readUnsignedInt(2)
        self.x1 = self.readSignedInt(2)
        unused = self.readUnsignedInt(2)
        self.y1 = self.readSignedInt(2)
        unused = self.readUnsignedInt(2)
        self.x2 = self.readSignedInt(2)
        unused = self.readUnsignedInt(2)
        self.y2 = self.readSignedInt(2)
        unused = self.readUnsignedInt(2)

    def dumpData(self):
        self.__parseBytes()
        return ('pos', {'md-top-lt': self.mdTopLt,
                        'md-bot-rt': self.mdBotRt,
                        'x1': self.x1,
                        'y1': self.y1,
                        'x2': self.x2,
                        'y2': self.y2})

class FontX(BaseRecordHandler):
    def __parseBytes(self):
        self.iFont = self.readUnsignedInt(2)

    def dumpData(self):
        self.__parseBytes()
        return ('font-x', {'i-font': self.iFont})

class AxesUsed(BaseRecordHandler):
    def __parseBytes(self):
        self.cAxes = self.readUnsignedInt(2)

    def dumpData(self):
        self.__parseBytes()
        return ('axes-used', {'c-axes': self.cAxes})

class AxisParent(BaseRecordHandler):
    def __parseBytes(self):
        self.iax = self.readUnsignedInt(2)
        # 16 bytes are unused

    def dumpData(self):
        self.__parseBytes()
        return ('axis-parent', {'iax': self.iax})

class BobPop(BaseRecordHandler):
    def __parseBytes(self):
        self.pst = self.readUnsignedInt(1)
        self.autoSplit = self.readUnsignedInt(1)
        self.split = self.readUnsignedInt(2)
        self.splitPos = self.readSignedInt(2)
        self.splitPercent = self.readSignedInt(2)
        self.pie2Size = self.readSignedInt(2)
        self.gap = self.readSignedInt(1)
        self.splitValue = self.readDouble()

        flag = self.readUnsignedInt(2)
        self.hasShadow        = (flag & 0x0001) != 0 # A

    def dumpData(self):
        self.__parseBytes()
        return ('bobpop', {'pst': self.pst,
                           'auto-split': self.autoSplit,
                           'split': self.split,
                           'split-pos': self.splitPos,
                           'split-percent': self.splitPercent,
                           'pie-2-size': self.pie2Size,
                           'gap': self.gap,
                           'split-balue': self.splitValue,
                           'has-shadow': self.hasShadow})

    def parseBytes (self):
        self.__parseBytes()

        self.appendLine("Chart group type: %s" % str(self.pst))
        self.appendLine("Auto split: %s" % self.getTrueFalse(self.autoSplit))
        self.appendLine("Split type: %s" % str(self.split))
        if self.split == 0x0: # pos
            self.appendLine("Split pos: %s" % str(self.splitPos))
        elif self.split == 0x1: # value
            self.appendLine("Split value: %s" % str(self.splitValue))
        elif self.split == 0x2: # percent
            self.appendLine("Split percent: %s" % str(self.splitPercent))
        else:
            self.appendLine("Custom split is specified in BopPopCustom record that follows")

        self.appendLine("Size of a secondary pie/bar: %s" % str(self.pie2Size))
        self.appendLine("Gap: %s" % str(self.gap))
        self.appendLine("Has shadow: %s" % self.getTrueFalse(self.hasShadow))

class Dat(BaseRecordHandler):
    def __parseBytes(self):
        flag = self.readUnsignedInt(2)
        self.hasBordHorz        = (flag & 0x0001) != 0 # A
        self.hasBordVert          = (flag & 0x0002) != 0 # B
        self.hasBordOutline        = (flag & 0x0004) != 0 # C
        self.showSeriesKey        = (flag & 0x0008) != 0 # D

    def dumpData(self):
        self.__parseBytes()
        return ('dat', {'has-bord-horz': self.hasBordHorz,
                        'has-bord-vert': self.hasBordVert,
                        'has-bord-outline': self.hasBordOutline,
                        'show-series-key': self.showSeriesKey})

    def parseBytes (self):
        self.__parseBytes()

        self.appendLine("Has horizontal borders: %s" % self.getTrueFalse(self.hasBordHorz))
        self.appendLine("Has vertical borders: %s" % self.getTrueFalse(self.hasBordVert))
        self.appendLine("Has outline borders: %s" % self.getTrueFalse(self.hasBordOutline))
        self.appendLine("Show series key: %s" % self.getTrueFalse(self.showSeriesKey))

class AxcExt(BaseRecordHandler):
    def __parseBytes (self):
        self.catMin = self.readUnsignedInt(2)
        self.catMax = self.readUnsignedInt(2)
        self.catMajor = self.readUnsignedInt(2)
        self.duMajor = self.readUnsignedInt(2)
        self.catMinor = self.readUnsignedInt(2)
        self.duMinor = self.readUnsignedInt(2)
        self.duBase = self.readUnsignedInt(2)
        self.catCrossDate = self.readUnsignedInt(2)

        flag = self.readUnsignedInt(2)
        self.autoMin        = (flag & 0x0001) != 0 # A
        self.autoMax          = (flag & 0x0002) != 0 # B
        self.autoMajor        = (flag & 0x0004) != 0 # C
        self.autoMinor        = (flag & 0x0008) != 0 # D
        self.dateAxis         = (flag & 0x0010) != 0 # E
        self.autoBase        = (flag & 0x0020) != 0 # F
        self.autoCross          = (flag & 0x0040) != 0 # G
        self.autoDate         = (flag & 0x0080) != 0 # H

    def dumpData(self):
        self.__parseBytes()
        return ('axc-ext', {'cat-min': self.catMin,
                            'cat-max': self.catMax,
                            'cat-major': self.catMajor,
                            'du-major': self.duMajor,
                            'cat-minor': self.catMinor,
                            'du-minor': self.duMinor,
                            'du-base': self.duBase,
                            'cat-cross-date': self.catCrossDate,
                            'auto-min': self.autoMin,
                            'auto-max': self.autoMax,
                            'auto-major': self.autoMajor,
                            'auto-minor': self.autoMinor,
                            'date-axis': self.dateAxis,
                            'auto-base': self.autoBase,
                            'auto-cross': self.autoCross,
                            'auto-date': self.autoDate})

class Tick(BaseRecordHandler):
    def __parseBytes (self):
        self.tktMajor = self.readUnsignedInt(1)
        self.tktMinor = self.readUnsignedInt(1)
        self.tlt = self.readUnsignedInt(1)
        self.wBkgMode = self.readUnsignedInt(1)
        self.rgb = self.readLongRGB()
        reserved1 = self.readUnsignedInt(4)
        reserved2 = self.readUnsignedInt(4)
        reserved3 = self.readUnsignedInt(4)
        reserved4 = self.readUnsignedInt(4)
        flag = self.readUnsignedInt(2)
        # TODO: recheck it
        self.autoCo        = (flag & 0x0001) != 0 # A
        self.autoMode          = (flag & 0x0002) != 0 # B
        self.rot = (flag & (0x4+0x8+0x10)) >> 2
        self.readingOrder        = (flag >>14)

        self.icv = self.readICV()
        self.trot = self.readUnsignedInt(2)

    def dumpData(self):
        self.__parseBytes()
        return ('tick', {'tkt-major': self.tktMajor,
                         'tkt-minor': self.tktMinor,
                         'tlt': self.tlt,
                         'w-bkg-mode': self.wBkgMode,
                         'auto-co': self.autoCo,
                         'auto-mode': self.autoMode,
                         'rot': self.rot,
                         'reading-order': self.readingOrder,
                         'trot': self.trot},
                         [('rgb', dumpRgb(self.rgb)),
                          ('icv', dumpIcv(self.icv))])

class SeriesList(BaseRecordHandler):
    def __parseBytes(self):
        self.cser = self.readUnsignedInt(2)
        self.series = []
        for x in xrange(self.cser):
            self.series.append(self.readUnsignedInt(2))

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Series count : %s" % str(self.cser))
        for x in self.series:
            self.appendLine("Series id : %s" % str(x))

    def dumpData(self):
        self.__parseBytes()
        return ('series-list',
                {'cser': self.cser},
                map(lambda x: ('series-index',x),
                    self.series))

class AxisLine(BaseRecordHandler):
    def __parseBytes(self):
        self.id = self.readUnsignedInt(2)

    def dumpData(self):
        self.__parseBytes()
        return ('axis-line', {'id': self.id})

class SIIndex(BaseRecordHandler):
    def __parseBytes(self):
        self.numIndex = self.readUnsignedInt(2)

    def dumpData(self):
        self.__parseBytes()
        return ('si-index', {'num-index': self.numIndex})

class DefaultText(BaseRecordHandler):

    __types = [
        'non-percent or non-value',
        'percent or value',
        'non-scalable font',
        'scalable font']

    def __parseBytes (self):
        self.id = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine(globals.getValueOrUnknown(DefaultText.__types, self.id))

    def dumpData(self):
        self.__parseBytes()
        return ('default-text', {'id': self.id})

class Text(BaseRecordHandler):

    __horAlign = { 1: 'left', 2: 'center', 3: 'right', 4: 'justify', 7: 'distributed' }
    __verAlign = { 1: 'top', 2: 'center', 3: 'bottom', 4: 'justify', 7: 'distributed' }
    __bkgMode = { 1: 'transparent', 2: 'opaque' }

    def __parseBytes (self):
        self.at = self.readUnsignedInt(1)
        self.vat = self.readUnsignedInt(1)
        self.bkgMode = self.readUnsignedInt(2)
        self.textColor = self.readLongRGB()
        self.x = self.readSignedInt(4)
        self.y = self.readSignedInt(4)
        self.dx = self.readSignedInt(4)
        self.dy = self.readSignedInt(4)

        flag = self.readUnsignedInt(2)
        self.autoColor        = (flag & 0x0001) != 0 # A
        self.showKey          = (flag & 0x0002) != 0 # B
        self.showValue        = (flag & 0x0004) != 0 # C
        unused                = (flag & 0x0008) != 0 # D (unused)
        self.autoText         = (flag & 0x0010) != 0 # E
        self.generated        = (flag & 0x0020) != 0 # F
        self.deleted          = (flag & 0x0040) != 0 # G
        self.autoMode         = (flag & 0x0080) != 0 # H
        unused                = (flag & 0x0700) != 0 # I (unused)
        self.showLabelAndPerc = (flag & 0x0800) != 0 # J
        self.showPercent      = (flag & 0x1000) != 0 # K
        self.showBubbleSizes  = (flag & 0x2000) != 0 # L
        self.showLabel        = (flag & 0x4000) != 0 # M
        reserved              = (flag & 0x8000) != 0 # N (reserved)

        self.icvTextColor = self.readICV()

        flag = self.readUnsignedInt(2)
        self.dlp = (flag & 0x000F)
        self.readingOrder = (flag & 0xC000) / (2**14)
        self.trot = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("horizontal alignment: %s"%
            globals.getValueOrUnknown(Text.__horAlign, self.at))
        self.appendLine("vertical alignment: %s"%
            globals.getValueOrUnknown(Text.__verAlign, self.vat))
        self.appendLine("text background: %s"%
            globals.getValueOrUnknown(Text.__bkgMode, self.bkgMode))

        # TODO : handle the rest of the data.

    def dumpData(self):
        self.__parseBytes()
        return ('text', {'at': self.at,
                         'vat': self.vat,
                         'bkg-mode': self.bkgMode,
                         'x': self.x,
                         'y': self.y,
                         'dx': self.dx,
                         'dy': self.dy,
                         'auto-color': self.autoColor,
                         'show-key': self.showKey,
                         'show-value': self.showValue,
                         'auto-text': self.autoText,
                         'generated': self.generated,
                         'deleted': self.deleted,
                         'show-label-and-perc': self.showLabelAndPerc,
                         'show-percent': self.showPercent,
                         'show-bubble-sizes': self.showBubbleSizes,
                         'show-label': self.showLabel,
                         'dlp': self.dlp,
                         'reading-order': self.readingOrder,
                         'trot': self.trot},
                         [('text-color', dumpRgb(self.textColor)),
                          ('icv-text-color', dumpIcv(self.icvTextColor))])

class Series(BaseRecordHandler):

    DATE     = 0
    NUMERIC  = 1
    SEQUENCE = 2
    TEXT     = 3

    seriesTypes = ['date', 'numeric', 'sequence', 'text']

    @staticmethod
    def getSeriesType (idx):
        r = 'unknown'
        if idx < len(CHSeries.seriesTypes):
            r = CHSeries.seriesTypes[idx]
        return r

    def __parseBytes (self):
        self.catType     = self.readUnsignedInt(2)
        self.valType     = self.readUnsignedInt(2) # must be 1 (ignored)
        self.catCount    = self.readUnsignedInt(2)
        self.valCount    = self.readUnsignedInt(2)
        self.bubbleType  = self.readUnsignedInt(2) # must be 1 (ignored)
        self.bubbleCount = self.readUnsignedInt(2)

    def parseBytes (self):
        self.__parseBytes()
        s = "unknown"
        if self.catType == 1:
            s = "numeric"
        elif self.catType == 3:
            s = "text"
        self.appendLine("data type: %s"%s)
        self.appendLine("category or horizontal value count: %d"%self.catCount)
        self.appendLine("value or vertical value count: %d"%self.valCount)
        self.appendLine("bubble size value count: %d"%self.bubbleCount)

    def dumpData(self):
        self.__parseBytes()
        return ('series', {'cat-type': self.catType,
                         'val-type': self.valType,
                         'cat-count': self.catCount,
                         'val-count': self.valCount,
                         'bubble-type': self.bubbleType,
                         'bubble-count': self.bubbleCount})

class CHAxis(BaseRecordHandler):

    axisTypeList = ['x-axis', 'y-axis', 'z-axis']

    def __parseBytes(self):
        self.axisType = self.readUnsignedInt(2)
        self.x = self.readSignedInt(4)
        self.y = self.readSignedInt(4)
        self.w = self.readSignedInt(4)
        self.h = self.readSignedInt(4)

    def parseBytes (self):
        self.__parseBytes()
        if self.axisType < len(CHAxis.axisTypeList):
            self.appendLine("axis type: %s (%d)"%(CHAxis.axisTypeList[self.axisType], self.axisType))
        else:
            self.appendLine("axis type: unknown")
        self.appendLine("area: (x, y, w, h) = (%d, %d, %d, %d) [no longer used]"%(self.x, self.y, self.w, self.h))

    def dumpData(self):
        self.__parseBytes()
        return ('axis', {'axis-type': self.axisType,
                         'x': self.x,
                         'y': self.y,
                         'w': self.w,
                         'h': self.h})


class CHProperties(BaseRecordHandler):
    def __parseBytes(self):
        flags = self.readUnsignedInt(2)
        self.emptyFlags = self.readUnsignedInt(2)
        self.manualSeries   = (flags & 0x0001) != 0
        self.showVisCells   = (flags & 0x0002) != 0
        self.noResize       = (flags & 0x0004) != 0
        self.manualPlotArea = (flags & 0x0008) != 0

    def parseBytes (self):
        self.__parseBytes()

        self.appendLine("manual series: %s" % self.getTrueFalse(self.manualSeries))
        self.appendLine("show only visible cells: %s" % self.getTrueFalse(self.showVisCells))
        self.appendLine("no resize: %s"%self.getTrueFalse(self.noResize))
        self.appendLine("manual plot area: %s" % self.getTrueFalse(self.manualPlotArea))

        emptyValues = "skip"
        if self.emptyFlags == 1:
            emptyValues = "plot as zero"
        elif self.emptyFlags == 2:
            emptyValues = "interpolate empty values"

        self.appendLine("empty value treatment: %s" % emptyValues)

    def dumpData(self):
        self.__parseBytes()
        return ('sht-props', {'empty-flags': self.emptyFlags,
                             'manual-series': self.manualSeries,
                             'show-vis-cells': self.showVisCells,
                             'no-resize': self.noResize,
                             'manual-plot-area': self.manualPlotArea})

class CHLabelRange(BaseRecordHandler):


    def __parseBytes (self):
        self.axisCross = self.readUnsignedInt(2)
        self.freqLabel = self.readUnsignedInt(2)
        self.freqTick  = self.readUnsignedInt(2)
        flags     = self.readUnsignedInt(2)
        self.betweenCateg = (flags & 0x0001) != 0
        self.maxCross     = (flags & 0x0002) != 0
        self.reversed     = (flags & 0x0004) != 0

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("axis crossing: %d"%self.axisCross)
        self.appendLine("label frequency: %d"%self.freqLabel)
        self.appendLine("tick frequency: %d"%self.freqTick)

        self.appendLineBoolean("axis between categories", self.betweenCateg)
        self.appendLineBoolean("other axis crosses at maximum", self.maxCross)
        self.appendLineBoolean("axis reversed", self.reversed)

    def dumpData(self):
        self.__parseBytes()
        return ('cat-ser-range', {'axis-cross': self.axisCross,
                                  'freq-label': self.freqLabel,
                                  'freq-tick': self.freqTick,
                                  'between-categ': self.betweenCateg,
                                  'max-cross': self.maxCross,
                                  'reversed': self.reversed})


class Legend(BaseRecordHandler):

    dockModeMap = {0: 'bottom', 1: 'corner', 2: 'top', 3: 'right', 4: 'left', 7: 'not docked'}
    spacingMap = ['close', 'medium', 'open']

    def getDockModeText (self, val):
        if Legend.dockModeMap.has_key(val):
            return Legend.dockModeMap[val]
        else:
            return '(unknown)'

    def getSpacingText (self, val):
        if val < len(Legend.spacingMap):
            return Legend.spacingMap[val]
        else:
            return '(unknown)'

    def __parseBytes (self):
        self.x = self.readSignedInt(4)
        self.y = self.readSignedInt(4)
        self.w = self.readSignedInt(4)
        self.h = self.readSignedInt(4)
        self.dockMode = self.readUnsignedInt(1) # [MS-XLS] says unused !?
        self.spacing  = self.readUnsignedInt(1)
        flags    = self.readUnsignedInt(2)

        self.docked     = (flags & 0x0001) != 0
        self.autoSeries = (flags & 0x0002) != 0
        self.autoPosX   = (flags & 0x0004) != 0
        self.autoPosY   = (flags & 0x0008) != 0
        self.stacked    = (flags & 0x0010) != 0
        self.dataTable  = (flags & 0x0020) != 0

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("legend position: (x, y) = (%d, %d)"%(self.x, self.y))
        self.appendLine("legend size: width = %d, height = %d"%(self.w, self.h))
        self.appendLine("dock mode: %s"%self.getDockModeText(self.dockMode))
        self.appendLine("spacing: %s"%self.getSpacingText(self.spacing))
        self.appendLineBoolean("docked", self.docked)
        self.appendLineBoolean("auto series", self.autoSeries)
        self.appendLineBoolean("auto position x", self.autoPosX)
        self.appendLineBoolean("auto position y", self.autoPosY)
        self.appendLineBoolean("stacked", self.stacked)
        self.appendLineBoolean("data table", self.dataTable)

        self.appendLine("")
        self.appendMultiLine("NOTE: Position and size are in units of 1/4000 of chart's width or height.")

    def dumpData(self):
        self.__parseBytes()
        return ('legend', {'x': self.x,
                           'y': self.y,
                           'w': self.w,
                           'h': self.h,
                           'dock-mode': self.dockMode,
                           'spacing': self.spacing,
                           'docked': self.docked,
                           'auto-series': self.autoSeries,
                           'auto-pos-x': self.autoPosX,
                           'auto-pos-y': self.autoPosY,
                           'stacked': self.stacked,
                           'data-table': self.dataTable})

class CHValueRange(BaseRecordHandler):

    def __parseBytes (self):
        self.minVal = globals.getDouble(self.readBytes(8))
        self.maxVal = globals.getDouble(self.readBytes(8))
        self.majorStep = globals.getDouble(self.readBytes(8))
        self.minorStep = globals.getDouble(self.readBytes(8))
        self.cross = globals.getDouble(self.readBytes(8))
        flags = globals.getSignedInt(self.readBytes(2))

        self.autoMin   = (flags & 0x0001) != 0
        self.autoMax   = (flags & 0x0002) != 0
        self.autoMajor = (flags & 0x0004) != 0
        self.autoMinor = (flags & 0x0008) != 0
        self.autoCross = (flags & 0x0010) != 0
        self.logScale  = (flags & 0x0020) != 0
        self.reversed  = (flags & 0x0040) != 0
        self.maxCross  = (flags & 0x0080) != 0
        self.bit8      = (flags & 0x0100) != 0

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("min: %g (auto min: %s)"%(self.minVal, self.getYesNo(self.autoMin)))
        self.appendLine("max: %g (auto max: %s)"%(self.maxVal, self.getYesNo(self.autoMax)))
        self.appendLine("major step: %g (auto major: %s)"%
            (self.majorStep, self.getYesNo(self.autoMajor)))
        self.appendLine("minor step: %g (auto minor: %s)"%
            (self.minorStep, self.getYesNo(self.autoMinor)))
        self.appendLine("cross: %g (auto cross: %s) (max cross: %s)"%
            (self.cross, self.getYesNo(self.autoCross), self.getYesNo(self.maxCross)))
        self.appendLine("biff5 or above: %s"%self.getYesNo(self.bit8))

    def dumpData(self):
        self.__parseBytes()
        return ('value-range', {'min-val': self.minVal,
                                'max-val': self.maxVal,
                                'major-step': self.majorStep,
                                'minor-step': self.minorStep,
                                'cross': self.cross,
                                'auto-min': self.autoMin,
                                'auto-max': self.autoMax,
                                'auto-major': self.autoMajor,
                                'auto-minor': self.autoMinor,
                                'auto-cross': self.autoCross,
                                'log-scale': self.logScale,
                                'reversed': self.reversed,
                                'max-cross': self.maxCross,
                                'biff5bit': self.bit8})


class CHBar(BaseRecordHandler):
    def __parseBytes (self):
        self.overlap = globals.getSignedInt(self.readBytes(2))
        self.gap     = globals.getSignedInt(self.readBytes(2))
        flags   = globals.getUnsignedInt(self.readBytes(2))

        self.horizontal = (flags & 0x0001) != 0
        self.stacked    = (flags & 0x0002) != 0
        self.percent    = (flags & 0x0004) != 0
        self.shadow     = (flags & 0x0008) != 0

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("overlap width: %d"%self.overlap)
        self.appendLine("gap: %d"%self.gap)
        self.appendLine("horizontal: %s"%self.getYesNo(self.horizontal))
        self.appendLine("stacked: %s"%self.getYesNo(self.stacked))
        self.appendLine("percent: %s"%self.getYesNo(self.percent))
        self.appendLine("shadow: %s"%self.getYesNo(self.shadow))

    def dumpData(self):
        self.__parseBytes()
        return ('bar', {'overlap': self.overlap,
                        'gap': self.gap,
                        'horizontal': self.horizontal,
                        'stacked': self.stacked,
                        'shadow': self.shadow})

class CHLine(BaseRecordHandler):

    def __parseBytes (self):
        flags   = globals.getUnsignedInt(self.readBytes(2))
        self.stacked = (flags & 0x0001)
        self.percent = (flags & 0x0002)
        self.shadow  = (flags & 0x0004)

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("stacked: %s"%self.getYesNo(self.stacked))
        self.appendLine("percent: %s"%self.getYesNo(self.percent))
        self.appendLine("shadow: %s"%self.getYesNo(self.shadow))

    def dumpData(self):
        self.__parseBytes()
        return ('line', {'stacked': self.stacked,
                         'percent': self.percent,
                         'shadow': self.shadow})

class CHRadar(BaseRecordHandler):
    def __parseBytes (self):
        flags   = self.readUnsignedInt(2)
        self.rdrAxLab = (flags & 0x0001) != 0 # A
        self.hasShadow = (flags & 0x0002) != 0 # B

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Display category labels: %s"%self.getYesNo(self.rdrAxLab))
        self.appendLine("Data markers have shadow: %s"%self.getYesNo(self.hasShadow))

    def dumpData(self):
        self.__parseBytes()
        return ('radar', {'rdr-ax-lab': self.rdrAxLab,
                          'has-shadow': self.hasShadow})

class CHSurf(BaseRecordHandler):
    def __parseBytes (self):
        flags   = self.readUnsignedInt(2)
        self.fillSurface = (flags & 0x0001) != 0 # A
        self.phongShade3D = (flags & 0x0002) != 0 # B

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Surface has a fill: %s"%self.getYesNo(self.fillSurface))
        self.appendLine("3D Phong shading: %s"%self.getYesNo(self.phongShade3D))

    def dumpData(self):
        self.__parseBytes()
        return ('surf', {'fill-surface': self.fillSurface,
                         'phong-shade-3d': self.phongShade3D})


class CHArea(BaseRecordHandler):
    def __parseBytes (self):
        flags   = self.readUnsignedInt(2)
        self.stacked = (flags & 0x0001) != 0 # A
        self.f100 = (flags & 0x0002) != 0 # B
        self.hasShadow = (flags & 0x0002) != 0 # B

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Is stacked: %s"%self.getYesNo(self.stacked))
        self.appendLine("Data points are percentage of sum: %s"%self.getYesNo(self.f100))
        self.appendLine("Has shadow: %s"%self.getYesNo(self.hasShadow))

    def dumpData(self):
        self.__parseBytes()
        return ('surf', {'stacked': self.stacked,
                         'f100': self.f100,
                         'has-shadow': self.hasShadow})

class CHScatter(BaseRecordHandler):
    def __parseBytes (self):
        self.bubbleSizeRatio   = self.readUnsignedInt(2)
        self.bubbleSize   = self.readUnsignedInt(2)
        flags   = self.readUnsignedInt(2)
        self.bubbles = (flags & 0x0001) != 0 # A
        self.showNegBubbles = (flags & 0x0002) != 0 # B
        self.hasShadow = (flags & 0x0004) != 0 # C

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Bubble size ratio: %s" % str(self.bubbleSizeRatio))
        self.appendLine("Bubble size: %s" % str(self.bubbleSize))
        self.appendLine("Is a bubble chart group: %s"%self.getYesNo(self.bubbles))
        self.appendLine("Show negative bubbles: %s"%self.getYesNo(self.showNegBubbles))
        self.appendLine("Data points have shadow: %s"%self.getYesNo(self.hasShadow))

    def dumpData(self):
        self.__parseBytes()
        return ('pie', {'bubble-size-ratio': self.bubbleSizeRatio,
                        'bubble-size': self.bubbleSize,
                        'bubble': self.bubbles,
                        'show-neg-bubbles': self.showNegBubbles,
                        'has-shadow': self.hasShadow})

class CHPie(BaseRecordHandler):
    def __parseBytes (self):
        self.start   = self.readUnsignedInt(2)
        self.donut   = self.readUnsignedInt(2)
        flags   = self.readUnsignedInt(2)
        self.hasShadow = (flags & 0x0001) != 0 # A
        self.showLdrLines = (flags & 0x0002) != 0 # B

    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("Start angle: %s"%self.getYesNo(self.start))
        self.appendLine("Size of center hole: %s"%self.getYesNo(self.donut))
        self.appendLine("Data points have shadow: %s"%self.getYesNo(self.hasShadow))
        self.appendLine("Show leader lines: %s"%self.getYesNo(self.showLdrLines))

    def dumpData(self):
        self.__parseBytes()
        return ('pie', {'start': self.start,
                        'donut': self.donut,
                        'has-shadow': self.hasShadow,
                        'show-ldr-Lines': self.showLdrLines})


class Brai(BaseRecordHandler):
    destTypes = [
        'series, legend entry, trendline name, or error bars name',
        'values or horizontal values',
        'categories or vertical values',
        'bubble size values of the series']

    linkTypes = [
        'auto-generated category name, series name, or bubble size',
        'text or value',
        'range of cells']

    def __parseBytes (self):
        self.id = self.readUnsignedInt(1)
        self.rt = self.readUnsignedInt(1)
        flag = self.readUnsignedInt(2)
        self.unlinkedIFmt = (flag & 0x0001) != 0
        self.iFmt = self.readUnsignedInt(2)
        tokenBytes = self.readUnsignedInt(2)
        self.formulaBytes = self.readBytes(tokenBytes)
        self.formula = None
        self.formulaError = None
        if len(self.formulaBytes) > 0:
            parser = formula.FormulaParser(self.header, self.formulaBytes)
            try:
                parser.parse()
                self.formula = parser.getText()
            except formula.FormulaParserError as e:
                self.formulaError = e.args[0]


    def parseBytes (self):
        self.__parseBytes()
        self.appendLine("part type: %s"%globals.getValueOrUnknown(Brai.destTypes, self.id))
        self.appendLine("referenced data type: %s"%globals.getValueOrUnknown(Brai.linkTypes, self.rt))
        s = "number format: "
        if self.unlinkedIFmt:
            s += "custom format"
        else:
            s += "source data format"
        self.appendLine(s)

        self.appendLine("number format ID: %d"%self.iFmt)
        self.appendLine("formula size (bytes): %d"%len(self.formulaBytes))

        if not self.formula is None:
            self.appendLine("formula: %s"%self.formula)
        else:
            self.appendLine("formula parser error: %s"%self.formulaError)

    def dumpData(self):
        self.__parseBytes()
        return ('brai', {'id': self.id,
                         'rt': self.rt,
                         'unlinked-ifmt': self.unlinkedIFmt,
                         'i-fmt': self.iFmt,
                         'formula': self.formula}) # assuming the formula is fine

class MSODrawing(BaseRecordHandler):
    """Handler for the MSODRAWING record

This record consists of BIFF-like sub-records, with their own headers and
contents.  The structure of this record is specified in [MS-ODRAW].pdf found
somewhere in the MSDN website.  In case of multiple MSODRAWING records in a
single worksheet stream, they need to be treated as if they are lumped
together.
"""
    def __parseBytes (self):
        self.msodHdl = msodraw.MSODrawHandler(self.bytes, self)

    def parseBytes (self):
        self.__parseBytes()
        try:
            self.msodHdl.parseBytes()
        except:
            self.appendLine("Error while parsing MSO Drawing record!")

    def fillModel (self, model):
        self.__parseBytes()
        self.msodHdl.fillModel(model)


class MSODrawingGroup(BaseRecordHandler):

    def __parseBytes (self):
        self.msodHdl = msodraw.MSODrawHandler(self.bytes, self)

    def parseBytes (self):
        self.__parseBytes()
        self.msodHdl.parseBytes()

    def fillModel (self, model):
        self.__parseBytes()
        self.msodHdl.fillModel(model)


class MSODrawingSelection(BaseRecordHandler):

    def __parseBytes (self):
        self.msodHdl = msodraw.MSODrawHandler(self.bytes, self)

    def parseBytes (self):
        self.__parseBytes()
        self.msodHdl.parseBytes()

    def fillModel (self, model):
        self.__parseBytes()
        self.msodHdl.fillModel(model)

class GelFrame(BaseRecordHandler):
    def __parseBytes (self):
        self.msodHdl = msodraw.MSODrawHandler(self.bytes, self)

    def parseBytes (self):
        self.__parseBytes()
        # it seems there are errors in msodraw parser :(
        #self.msodHdl.parseBytes()

    def dumpData(self):
        # we don't dump data!
        return ('gel-frame', {'bytes': globals.getRawBytes(self.bytes, False, False)})


class Pls(BaseRecordHandler):
    def __parseBytes (self):
        # DEVMODE is quite a big structure so we don't parse it
        pass

    def parseBytes (self):
        self.__parseBytes()

    def dumpData(self):
        return ('devmode', {'bytes': globals.getRawBytes(self.bytes, False, False)})

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

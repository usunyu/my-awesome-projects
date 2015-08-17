# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import struct, sys
import globals

class InvalidCellAddress(Exception): pass
class FormulaParserError(Exception): pass

class ColRelU(object):
    def __init__ (self, strm):
        bits = strm.readUnsignedInt(2)
        self.col = (bits & 0x3FFF)
        self.colRelative = (bits & 0x4000) != 0
        self.rowRelative = (bits & 0x8000) != 0

def toColName (colID):
    if colID > 255:
        globals.error("Column ID greater than 255")
        raise InvalidCellAddress
    n1 = colID % 26
    n2 = int(colID/26)
    name = struct.pack('b', n1 + ord('A'))
    if n2 > 0:
        name += struct.pack('b', n2 + ord('A'))
    return name

def toAbsName (name, isRelative):
    if not isRelative:
        name = '$' + name
    return name

class CellAddress(object):
    def __init__ (self, col=0, row=0, colRel=False, rowRel=False):
        self.col = col
        self.row = row
        self.isColRelative = colRel
        self.isRowRelative = rowRel

    def toString (self):
        return self.getName()

    def getName (self):
        colName = toAbsName(toColName(self.col), self.isColRelative)
        rowName = toAbsName("%d"%(self.row+1),   self.isRowRelative)
        return colName + rowName

class CellRange(object):
    def __init__ (self):
        self.firstRow = 0
        self.lastRow = 0
        self.firstCol = 0
        self.lastCol = 0
        self.isFirstRowRelative = False
        self.isLastRowRelative = False
        self.isFirstColRelative = False
        self.isLastColRelative = False

    def toString (self):
        return self.getName()

    def getName (self):
        col1 = toColName(self.firstCol)
        col2 = toColName(self.lastCol)
        row1 = "%d"%(self.firstRow+1)
        row2 = "%d"%(self.lastRow+1)
        col1 = toAbsName(col1, self.isFirstColRelative)
        col2 = toAbsName(col2, self.isLastColRelative)
        row1 = toAbsName(row1, self.isFirstRowRelative)
        row2 = toAbsName(row2, self.isLastRowRelative)
        return col1 + row1 + ':' + col2 + row2

def parseCellAddress (bytes):
    if len(bytes) != 4:
        globals.error("Byte size is %d but expected 4 bytes for cell address.\n"%len(bytes))
        raise InvalidCellAddress

    row = globals.getSignedInt(bytes[0:2])
    col = globals.getSignedInt(bytes[2:4])
    colRelative = ((col & 0x4000) != 0)
    rowRelative = ((col & 0x8000) != 0)
    col = (col & 0x00FF)
    obj = CellAddress(col, row, colRelative, rowRelative)
    return obj

def parseCellRangeAddress (bytes):
    if len(bytes) != 8:
        raise InvalidCellAddress

    obj = CellRange()
    obj.firstRow = globals.getSignedInt(bytes[0:2])
    obj.lastRow  = globals.getSignedInt(bytes[2:4])
    obj.firstCol = globals.getSignedInt(bytes[4:6])
    obj.lastCol  = globals.getSignedInt(bytes[6:8])

    obj.isFirstColRelative = ((obj.firstCol & 0x4000) != 0)
    obj.isFirstRowRelative = ((obj.firstCol & 0x8000) != 0)
    obj.firstCol = (obj.firstCol & 0x00FF)

    obj.isLastColRelative = ((obj.lastCol & 0x4000) != 0)
    obj.isLastRowRelative = ((obj.lastCol & 0x8000) != 0)
    obj.lastCol = (obj.lastCol & 0x00FF)
    return obj


class RgceLocRel(object):

    def __init__ (self, strm):
        self.row = strm.readSignedInt(2)
        self.col = strm.readSignedInt(2)
        self.colRelative = ((self.col & 0x4000) != 0)
        self.rowRelative = ((self.col & 0x8000) != 0)
        self.col = (self.col & 0x00FF)
        self.loc = CellAddress(self.col, self.row, self.colRelative, self.rowRelative)

    def getText (self):
        return self.loc.toString()


# ============================================================================

class TokenType:
    Area3d = 0
    Unknown = 9999

class ParsedFormulaType:
    Cell = 0
    Name = 1
    Shared = 2
    Unknown = 9999

def getPtgDataType (opcode):
    return (opcode & 0x60) / (2**5)

class PtgDataType(object):

    Reference = 0x1
    Value     = 0x2
    Array     = 0x3

    __names = ['ref', 'value', 'array']
    @staticmethod
    def getText (value):
        if 1 <= value and value <= 3:
            return PtgDataType.__names[value-1]
        return 'unknown'

class PtgBase(object):
    def __init__ (self, strm, opcode, parseType):
        self.opcode = opcode
        self.strm = strm
        self.tokenType = TokenType.Unknown
        self.parseType = parseType

    def parse (self):
        self.parseBytes()
        self.strm = None # no need to hold reference to the stream.

    def parseBytes (self):
        # derived class should overwrite this method.
        pass

    def getText (self):
        return ''

class PtgExp(PtgBase):
    def parseBytes (self):
        self.row = self.strm.readUnsignedInt(2)
        self.col = self.strm.readUnsignedInt(2)

    def getText (self):
        return "(ptgexp: row=%d, col=%d)"%(self.row, self.col)

class PtgMissArg(PtgBase):
    def parseBytes (self):
        pass

    def getText (self):
        return '(arg missing)'

class PtgMemFunc(PtgBase):
    def parseBytes(self):
        self.dataType = getPtgDataType(self.opcode)
        self.length = self.strm.readUnsignedInt(2)

    def getText (self):
        return "(mem func: type=%s size=%d)"%(PtgDataType.getText(self.dataType), self.length)

class PtgStr(PtgBase):
    def parseBytes (self):
        length = self.strm.readUnsignedInt(1)
        self.value = self.strm.readUnicodeString(length)

    def getText (self):
        return "(str: '%s')"%self.value

class PtgAtt(PtgBase):
    def parseBytes (self):
        attType = self.strm.readUnsignedInt(1)
        if attType == 0x01:
            # PtgAttSemi: volatile
            self.attName = 'volatile'
            self.strm.readBytes(2) # ignore bytes
        else:
            raise FormulaParserError("unknown attribute token type (0x%2.2X)"%attType)

    def getText (self):
        return "(att: %s)"%self.attName

class PtgArray(PtgBase):
    def parseBytes (self):
        self.strm.readBytes(7)

    def getText (self):
        return "(array)"

class PtgName(PtgBase):
    def parseBytes (self):
        self.nameIdx = self.strm.readUnsignedInt(4)

    def getText (self):
        return "(name: %d)"%self.nameIdx

class PtgRef(PtgBase):
    def parseBytes (self):
        self.row = self.strm.readUnsignedInt(2)
        self.col = ColRelU(self.strm)

    def getText (self):
        return "(ref: row=%d,col=%d,rowRelative=%d,colRelative=%d)"%(self.row, self.col.col, self.col.rowRelative, self.col.colRelative)

class PtgNameX(PtgBase):
    def parseBytes (self):
        self.xti = self.strm.readUnsignedInt(2)
        self.nameID = self.strm.readUnsignedInt(4)

    def getText (self):
        return "(name: xti=%d, name=%d)"%(self.xti, self.nameID)

class PtgInt(PtgBase):
    def parseBytes (self):
        self.value = self.strm.readUnsignedInt(2)

    def getText (self):
        return "(int: %d)"%self.value

class PtgParen(PtgBase):
    def getText (self):
        return '(paren)'

class PtgUnion(PtgBase):
    def getText (self):
        return '(union)'

class _Area3d(PtgBase):
    def parseBytes (self):
        self.xti = self.strm.readUnsignedInt(2)
        self.cellRange = parseCellRangeAddress(self.strm.readBytes(8))
        self.tokenType = TokenType.Area3d

    def getText (self):
        return "(xti=%d,"%self.xti + self.cellRange.getName() + ")"

class PtgRef3d(PtgBase):
    def parseBytes (self):
        self.ixti = self.strm.readUnsignedInt(2)
        # TODO: parse differently for named range formulas.
        self.cell = parseCellAddress(self.strm.readBytes(4))
        self.cell.isColRelative = False
        self.cell.isRowRelative = False

    def getText (self):
        return "(xti=%d,%s)"%(self.ixti, self.cell.getName())

class PtgFuncVar(PtgBase):

    funcTab = {
        0x0000: 'COUNT',
        0x0001: 'IF',
        0x0002: 'ISNA',
        0x0003: 'ISERROR',
        0x0004: 'SUM',
        0x0005: 'AVERAGE',
        0x0006: 'MIN',
        0x0007: 'MAX',
        0x0008: 'ROW',
        0x0009: 'COLUMN',
        0x000A: 'NA',
        0x000B: 'NPV',
        0x000C: 'STDEV',
        0x000D: 'DOLLAR',
        0x000E: 'FIXED',
        0x000F: 'SIN',
        0x0010: 'COS',
        0x0011: 'TAN',
        0x0012: 'ATAN',
        0x0013: 'PI',
        0x0014: 'SQRT',
        0x0015: 'EXP',
        0x0016: 'LN',
        0x0017: 'LOG10',
        0x0018: 'ABS',
        0x0019: 'INT',
        0x001A: 'SIGN',
        0x001B: 'ROUND',
        0x001C: 'LOOKUP',
        0x001D: 'INDEX',
        0x001E: 'REPT',
        0x001F: 'MID',
        0x0020: 'LEN',
        0x0021: 'VALUE',
        0x0022: 'TRUE',
        0x0023: 'FALSE',
        0x0024: 'AND',
        0x0025: 'OR',
        0x0026: 'NOT',
        0x0027: 'MOD',
        0x0028: 'DCOUNT',
        0x0029: 'DSUM',
        0x002A: 'DAVERAGE',
        0x002B: 'DMIN',
        0x002C: 'DMAX',
        0x002D: 'DSTDEV',
        0x002E: 'VAR',
        0x002F: 'DVAR',
        0x0030: 'TEXT',
        0x0031: 'LINEST',
        0x0032: 'TREND',
        0x0033: 'LOGEST',
        0x0034: 'GROWTH',
        0x0035: 'GOTO',
        0x0036: 'HALT',
        0x0037: 'RETURN',
        0x0038: 'PV',
        0x0039: 'FV',
        0x003A: 'NPER',
        0x003B: 'PMT',
        0x003C: 'RATE',
        0x003D: 'MIRR',
        0x003E: 'IRR',
        0x003F: 'RAND',
        0x0040: 'MATCH',
        0x0041: 'DATE',
        0x0042: 'TIME',
        0x0043: 'DAY',
        0x0044: 'MONTH',
        0x0045: 'YEAR',
        0x0046: 'WEEKDAY',
        0x0047: 'HOUR',
        0x0048: 'MINUTE',
        0x0049: 'SECOND',
        0x004A: 'NOW',
        0x004B: 'AREAS',
        0x004C: 'ROWS',
        0x004D: 'COLUMNS',
        0x004E: 'OFFSET',
        0x004F: 'ABSREF',
        0x0050: 'RELREF',
        0x0051: 'ARGUMENT',
        0x0052: 'SEARCH',
        0x0053: 'TRANSPOSE',
        0x0054: 'ERROR',
        0x0055: 'STEP',
        0x0056: 'TYPE',
        0x0057: 'ECHO',
        0x0058: 'SET.NAME',
        0x0059: 'CALLER',
        0x005A: 'DEREF',
        0x005B: 'WINDOWS',
        0x005C: 'SERIES',
        0x005D: 'DOCUMENTS',
        0x005E: 'ACTIVE.CELL',
        0x005F: 'SELECTION',
        0x0060: 'RESULT',
        0x0061: 'ATAN2',
        0x0062: 'ASIN',
        0x0063: 'ACOS',
        0x0064: 'CHOOSE',
        0x0065: 'HLOOKUP',
        0x0066: 'VLOOKUP',
        0x0067: 'LINKS',
        0x0068: 'INPUT',
        0x0069: 'ISREF',
        0x006A: 'GET.FORMULA',
        0x006B: 'GET.NAME',
        0x006C: 'SET.VALUE',
        0x006D: 'LOG',
        0x006E: 'EXEC',
        0x006F: 'CHAR',
        0x0070: 'LOWER',
        0x0071: 'UPPER',
        0x0072: 'PROPER',
        0x0073: 'LEFT',
        0x0074: 'RIGHT',
        0x0075: 'EXACT',
        0x0076: 'TRIM',
        0x0077: 'REPLACE',
        0x0078: 'SUBSTITUTE',
        0x0079: 'CODE',
        0x007A: 'NAMES',
        0x007B: 'DIRECTORY',
        0x007C: 'FIND',
        0x007D: 'CELL',
        0x007E: 'ISERR',
        0x007F: 'ISTEXT',
        0x0080: 'ISNUMBER',
        0x0081: 'ISBLANK',
        0x0082: 'T',
        0x0083: 'N',
        0x0084: 'FOPEN',
        0x0085: 'FCLOSE',
        0x0086: 'FSIZE',
        0x0087: 'FREADLN',
        0x0088: 'FREAD',
        0x0089: 'FWRITELN',
        0x008A: 'FWRITE',
        0x008B: 'FPOS',
        0x008C: 'DATEVALUE',
        0x008D: 'TIMEVALUE',
        0x008E: 'SLN',
        0x008F: 'SYD',
        0x0090: 'DDB',
        0x0091: 'GET.DEF',
        0x0092: 'REFTEXT',
        0x0093: 'TEXTREF',
        0x0094: 'INDIRECT',
        0x0095: 'REGISTER',
        0x0096: 'CALL',
        0x0097: 'ADD.BAR',
        0x0098: 'ADD.MENU',
        0x0099: 'ADD.COMMAND',
        0x009A: 'ENABLE.COMMAND',
        0x009B: 'CHECK.COMMAND',
        0x009C: 'RENAME.COMMAND',
        0x009D: 'SHOW.BAR',
        0x009E: 'DELETE.MENU',
        0x009F: 'DELETE.COMMAND',
        0x00A0: 'GET.CHART.ITEM',
        0x00A1: 'DIALOG.BOX',
        0x00A2: 'CLEAN',
        0x00A3: 'MDETERM',
        0x00A4: 'MINVERSE',
        0x00A5: 'MMULT',
        0x00A6: 'FILES',
        0x00A7: 'IPMT',
        0x00A8: 'PPMT',
        0x00A9: 'COUNTA',
        0x00AA: 'CANCEL.KEY',
        0x00AB: 'FOR',
        0x00AC: 'WHILE',
        0x00AD: 'BREAK',
        0x00AE: 'NEXT',
        0x00AF: 'INITIATE',
        0x00B0: 'REQUEST',
        0x00B1: 'POKE',
        0x00B2: 'EXECUTE',
        0x00B3: 'TERMINATE',
        0x00B4: 'RESTART',
        0x00B5: 'HELP',
        0x00B6: 'GET.BAR',
        0x00B7: 'PRODUCT',
        0x00B8: 'FACT',
        0x00B9: 'GET.CELL',
        0x00BA: 'GET.WORKSPACE',
        0x00BB: 'GET.WINDOW',
        0x00BC: 'GET.DOCUMENT',
        0x00BD: 'DPRODUCT',
        0x00BE: 'ISNONTEXT',
        0x00BF: 'GET.NOTE',
        0x00C0: 'NOTE',
        0x00C1: 'STDEVP',
        0x00C2: 'VARP',
        0x00C3: 'DSTDEVP',
        0x00C4: 'DVARP',
        0x00C5: 'TRUNC',
        0x00C6: 'ISLOGICAL',
        0x00C7: 'DCOUNTA',
        0x00C8: 'DELETE.BAR',
        0x00C9: 'UNREGISTER',
        0x00CC: 'USDOLLAR',
        0x00CD: 'FINDB',
        0x00CE: 'SEARCHB',
        0x00CF: 'REPLACEB',
        0x00D0: 'LEFTB',
        0x00D1: 'RIGHTB',
        0x00D2: 'MIDB',
        0x00D3: 'LENB',
        0x00D4: 'ROUNDUP',
        0x00D5: 'ROUNDDOWN',
        0x00D6: 'ASC',
        0x00D7: 'DBCS',
        0x00D8: 'RANK',
        0x00DB: 'ADDRESS',
        0x00DC: 'DAYS360',
        0x00DD: 'TODAY',
        0x00DE: 'VDB',
        0x00DF: 'ELSE',
        0x00E0: 'ELSE.IF',
        0x00E1: 'END.IF',
        0x00E2: 'FOR.CELL',
        0x00E3: 'MEDIAN',
        0x00E4: 'SUMPRODUCT',
        0x00E5: 'SINH',
        0x00E6: 'COSH',
        0x00E7: 'TANH',
        0x00E8: 'ASINH',
        0x00E9: 'ACOSH',
        0x00EA: 'ATANH',
        0x00EB: 'DGET',
        0x00EC: 'CREATE.OBJECT',
        0x00ED: 'VOLATILE',
        0x00EE: 'LAST.ERROR',
        0x00EF: 'CUSTOM.UNDO',
        0x00F0: 'CUSTOM.REPEAT',
        0x00F1: 'FORMULA.CONVERT',
        0x00F2: 'GET.LINK.INFO',
        0x00F3: 'TEXT.BOX',
        0x00F4: 'INFO',
        0x00F5: 'GROUP',
        0x00F6: 'GET.OBJECT',
        0x00F7: 'DB',
        0x00F8: 'PAUSE',
        0x00FB: 'RESUME',
        0x00FC: 'FREQUENCY',
        0x00FD: 'ADD.TOOLBAR',
        0x00FE: 'DELETE.TOOLBAR',
        0x00FF: 'User Defined Function',
        0x0100: 'RESET.TOOLBAR',
        0x0101: 'EVALUATE',
        0x0102: 'GET.TOOLBAR',
        0x0103: 'GET.TOOL',
        0x0104: 'SPELLING.CHECK',
        0x0105: 'ERROR.TYPE',
        0x0106: 'APP.TITLE',
        0x0107: 'WINDOW.TITLE',
        0x0108: 'SAVE.TOOLBAR',
        0x0109: 'ENABLE.TOOL',
        0x010A: 'PRESS.TOOL',
        0x010B: 'REGISTER.ID',
        0x010C: 'GET.WORKBOOK',
        0x010D: 'AVEDEV',
        0x010E: 'BETADIST',
        0x010F: 'GAMMALN',
        0x0110: 'BETAINV',
        0x0111: 'BINOMDIST',
        0x0112: 'CHIDIST',
        0x0113: 'CHIINV',
        0x0114: 'COMBIN',
        0x0115: 'CONFIDENCE',
        0x0116: 'CRITBINOM',
        0x0117: 'EVEN',
        0x0118: 'EXPONDIST',
        0x0119: 'FDIST',
        0x011A: 'FINV',
        0x011B: 'FISHER',
        0x011C: 'FISHERINV',
        0x011D: 'FLOOR',
        0x011E: 'GAMMADIST',
        0x011F: 'GAMMAINV',
        0x0120: 'CEILING',
        0x0121: 'HYPGEOMDIST',
        0x0122: 'LOGNORMDIST',
        0x0123: 'LOGINV',
        0x0124: 'NEGBINOMDIST',
        0x0125: 'NORMDIST',
        0x0126: 'NORMSDIST',
        0x0127: 'NORMINV',
        0x0128: 'NORMSINV',
        0x0129: 'STANDARDIZE',
        0x012A: 'ODD',
        0x012B: 'PERMUT',
        0x012C: 'POISSON',
        0x012D: 'TDIST',
        0x012E: 'WEIBULL',
        0x012F: 'SUMXMY2',
        0x0130: 'SUMX2MY2',
        0x0131: 'SUMX2PY2',
        0x0132: 'CHITEST',
        0x0133: 'CORREL',
        0x0134: 'COVAR',
        0x0135: 'FORECAST',
        0x0136: 'FTEST',
        0x0137: 'INTERCEPT',
        0x0138: 'PEARSON',
        0x0139: 'RSQ',
        0x013A: 'STEYX',
        0x013B: 'SLOPE',
        0x013C: 'TTEST',
        0x013D: 'PROB',
        0x013E: 'DEVSQ',
        0x013F: 'GEOMEAN',
        0x0140: 'HARMEAN',
        0x0141: 'SUMSQ',
        0x0142: 'KURT',
        0x0143: 'SKEW',
        0x0144: 'ZTEST',
        0x0145: 'LARGE',
        0x0146: 'SMALL',
        0x0147: 'QUARTILE',
        0x0148: 'PERCENTILE',
        0x0149: 'PERCENTRANK',
        0x014A: 'MODE',
        0x014B: 'TRIMMEAN',
        0x014C: 'TINV',
        0x014E: 'MOVIE.COMMAND',
        0x014F: 'GET.MOVIE',
        0x0150: 'CONCATENATE',
        0x0151: 'POWER',
        0x0152: 'PIVOT.ADD.DATA',
        0x0153: 'GET.PIVOT.TABLE',
        0x0154: 'GET.PIVOT.FIELD',
        0x0155: 'GET.PIVOT.ITEM',
        0x0156: 'RADIANS',
        0x0157: 'DEGREES',
        0x0158: 'SUBTOTAL',
        0x0159: 'SUMIF',
        0x015A: 'COUNTIF',
        0x015B: 'COUNTBLANK',
        0x015C: 'SCENARIO.GET',
        0x015D: 'OPTIONS.LISTS.GET',
        0x015E: 'ISPMT',
        0x015F: 'DATEDIF',
        0x0160: 'DATESTRING',
        0x0161: 'NUMBERSTRING',
        0x0162: 'ROMAN',
        0x0163: 'OPEN.DIALOG',
        0x0164: 'SAVE.DIALOG',
        0x0165: 'VIEW.GET',
        0x0166: 'GETPIVOTDATA',
        0x0167: 'HYPERLINK',
        0x0168: 'PHONETIC',
        0x0169: 'AVERAGEA',
        0x016A: 'MAXA',
        0x016B: 'MINA',
        0x016C: 'STDEVPA',
        0x016D: 'VARPA',
        0x016E: 'STDEVA',
        0x016F: 'VARA',
        0x0170: 'BAHTTEXT',
        0x0171: 'THAIDAYOFWEEK',
        0x0172: 'THAIDIGIT',
        0x0173: 'THAIMONTHOFYEAR',
        0x0174: 'THAINUMSOUND',
        0x0175: 'THAINUMSTRING',
        0x0176: 'THAISTRINGLENGTH',
        0x0177: 'ISTHAIDIGIT',
        0x0178: 'ROUNDBAHTDOWN',
        0x0179: 'ROUNDBAHTUP',
        0x017A: 'THAIYEAR',
        0x017B: 'RTD'
    }

    def parseBytes (self):
        self.dataType = (self.opcode & 0x60)/32  # 0x1 = reference, 0x2 = value, 0x3 = array
        self.argCount = self.strm.readUnsignedInt(1)
        tab = self.strm.readUnsignedInt(2)
        self.funcType = (tab & 0x7FFF)
        self.isCeTab = (tab & 0x8000) != 0

    def getText (self):
        if self.isCeTab:
            # I'll support this later.
            raise FormulaParserError("special built-in function not supported yet")

        if not PtgFuncVar.funcTab.has_key(self.funcType):
            # unknown function name
            return '#NAME!'

        return "(func: %s; arg: %d)"%(PtgFuncVar.funcTab[self.funcType], self.argCount)


class PtgRefN(PtgBase):
    """Reference to a single cell"""

    def parseBytes (self):
        self.loc = RgceLocRel(self.strm)

    def getText (self):
        colrel = "abs"
        if self.loc.colRelative:
            colrel = "rel"

        rowrel = "abs"
        if self.loc.rowRelative:
            rowrel = "rel"

        return "(single-ref: col=%d[%s],row=%d[%s])"%(self.loc.col, colrel, self.loc.row, rowrel)


_tokenMap = {
    0x01: PtgExp,
    0x10: PtgUnion,
    0x15: PtgParen,
    0x16: PtgMissArg,
    0x17: PtgStr,
    0x19: PtgAtt,
    0x1E: PtgInt,
    0x22: PtgFuncVar,
    0x24: PtgRef,
    0x29: PtgMemFunc,
    0x3B: _Area3d,
    0x40: PtgArray,
    0x43: PtgName,
    0x44: PtgRef,
    0x59: PtgNameX,
    0x5A: PtgRef3d,
    0x5B: _Area3d,
    0x7B: _Area3d,

    0x3A: PtgRef3d,
    0x42: PtgFuncVar,
    0x4C: PtgRefN
}

class FormulaParser(object):
    """This is a new formula parser that will eventually replace the old one.

Once replaced, I'll change the name to FormulaParser and the names of the
associated token classes will be without the leading underscore (_)."""


    def __init__ (self, header, bytes):
        self.header = header
        self.tokens = []
        try:
            # We are sometimes called with None bytes
            self.strm = globals.ByteStream(bytes)
        except:
            if not globals.params.catchExceptions:
                raise
            globals.error("FormulaParser: init called with None source\n")
            self.strm = globals.ByteStream("")

    def parse (self, parseType=ParsedFormulaType.Cell):
        while not self.strm.isEndOfRecord():
            b = self.strm.readUnsignedInt(1)
            if not _tokenMap.has_key(b):
                # Unknown token.  Stop parsing.
                raise FormulaParserError("unknown token 0x%2.2X"%b)

            token = _tokenMap[b](self.strm, b, parseType)
            token.parse()
            self.tokens.append(token)

    def getText (self):
        s = ''
        for tk in self.tokens:
            s += tk.getText()
        return s

    def getTokens (self):
        return self.tokens

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

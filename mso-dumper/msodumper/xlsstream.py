# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import sys
import ole, globals, xlsrecord
from globals import output

class EndOfStream(Exception): pass

unusedRecDesc = "[unused, must be ignored]"

# opcode: [canonical name, description, handler (optional)]

# Please use the same record name as canonical name as it appears in the
# [MS-XLS] specification.  The description should be short enough to fit the
# screen column width when it's dumped to stdout.

recData = {
    0x0006: ["FORMULA", "Cell Formula", xlsrecord.Formula],
    0x000A: ["EOF", "End of File", xlsrecord.EOF],
    0x000C: ["CALCCOUNT", "Iteration Count"],
    0x000D: ["CALCMODE", "Calculation Mode"],
    0x000E: ["PRECISION", "Precision"],
    0x000F: ["REFMODE", "Reference Mode"],
    0x0010: ["DELTA", "Iteration Increment"],
    0x0011: ["ITERATION", "Iteration Mode"],
    0x0012: ["PROTECT", "Protection Flag", xlsrecord.Protect],
    0x0013: ["PASSWORD", "Protection Password"],
    0x0014: ["HEADER", "Print Header on Each Page", xlsrecord.Header],
    0x0015: ["FOOTER", "Print Footer on Each Page", xlsrecord.Footer],
    0x0016: ["EXTERNCOUNT", "Number of External References"],
    0x0017: ["EXTERNSHEET", "External Reference", xlsrecord.ExternSheet],
    0x0018: ["LBL", "Internal Defined Name", xlsrecord.Name],
    0x0019: ["WINDOWPROTECT", "Windows Are Protected"],
    0x0021: ["ARRAY", "Array-Entered Formula", xlsrecord.Array], # undocumented, but identical to 0x0221 ?
    0x001A: ["VERTICALPAGEBREAKS", "Explicit Column Page Breaks"],
    0x001B: ["HORIZONTALPAGEBREAKS", "Explicit Row Page Breaks", xlsrecord.HorBreaks],
    0x001C: ["NOTE", "Comment Associated with a Cell"],
    0x001D: ["SELECTION", "Current Selection"],
    0x0022: ["DATEMODE", "Base Date for Displaying Date Values"],
    0x0023: ["EXTERNNAME", "Externally Defined Name", xlsrecord.ExternName],
    0x0026: ["LEFTMARGIN", "Left Margin Measurement"],
    0x0027: ["RIGHTMARGIN", "Right Margin Measurement"],
    0x0028: ["TOPMARGIN", "Top Margin Measurement"],
    0x0029: ["BOTTOMMARGIN", "Bottom Margin Measurement"],
    0x002A: ["PRINTHEADERS", "Print Row/Column Labels"],
    0x002B: ["PRINTGRIDLINES", "Print Gridlines Flag"],
    0x002F: ["FILEPASS", "File Is Password-Protected", xlsrecord.FilePass],
    0x0031: ["FONT", "Font and Character Formatting", xlsrecord.Font],
    0x0033: ["PRINTSIZE", "Printed Size of the Chart", xlsrecord.PrintSize],
    0x003C: ["CONTINUE", "Continues Long Records"],
    0x003D: ["WINDOW1", "Window Information"],
    0x0040: ["BACKUP", "Save Backup Version of the File"],
    0x0041: ["PANE", "Number of Panes and Their Position", xlsrecord.Pane],
    0x0042: ["CODEPAGE/CODENAME", "Default Code Page/VBE Object Name"],
    0x004D: ["PLS", "Environment-Specific Print Record", xlsrecord.Pls],
    0x0050: ["DCON", "Data Consolidation Information"],
    0x0051: ["DCONREF", "Data Consolidation References", xlsrecord.DConRef],
    0x0052: ["DCONNAME", "Data Consolidation Named References", xlsrecord.DConName],
    0x0055: ["DEFCOLWIDTH", "Default Width for Columns", xlsrecord.DefColWidth],
    0x0059: ["XCT", "CRN Record Count", xlsrecord.Xct],
    0x005A: ["CRN", "Nonresident Operands", xlsrecord.Crn],
    0x005B: ["FILESHARING", "File-Sharing Information"],
    0x005C: ["WRITEACCESS", "Write Access User Name"],
    0x005D: ["OBJ", "Describes a Graphic Object", xlsrecord.Obj],
    0x005E: ["UNCALCED", "Recalculation Status"],
    0x005F: ["SAVERECALC", "Recalculate Before Save"],
    0x0060: ["TEMPLATE", "Workbook Is a Template"],
    0x0063: ["OBJPROTECT", "Objects Are Protected"],
    0x007D: ["COLINFO", "Column Formatting Information", xlsrecord.ColInfo],
    0x007F: ["IMDATA", "Image Data"],
    0x0080: ["GUTS", "Size of Row and Column Gutters"],
    0x0081: ["WSBOOL", "Additional Workspace Information"],
    0x0082: ["GRIDSET", "State Change of Gridlines Option"],
    0x0083: ["HCENTER", "Center Between Horizontal Margins", xlsrecord.HCenter],
    0x0084: ["VCENTER", "Center Between Vertical Margins", xlsrecord.VCenter],
    0x0085: ["BOUNDSHEET", "Sheet Information", xlsrecord.BoundSheet],
    0x0086: ["WRITEPROT", "Workbook Is Write-Protected"],
    0x0087: ["ADDIN", "Workbook Is an Add-in Macro"],
    0x0088: ["EDG", "Edition Globals"],
    0x0089: ["PUB", "Publisher"],
    0x008C: ["COUNTRY", "Default Country and WIN.INI Country"],
    0x008D: ["HIDEOBJ", "Object Display Options"],
    0x0090: ["SORT", "Sorting Options"],
    0x0091: ["SUB", "Subscriber"],
    0x0092: ["PALETTE", "Color Palette Definition"],
    0x0094: ["LHRECORD", ".WK? File Conversion Information"],
    0x0095: ["LHNGRAPH", "Named Graph Information"],
    0x0096: ["SOUND", "Sound Note"],
    0x0098: ["LPR", "Sheet Was Printed Using LINE.PRINT()"],
    0x0099: ["STANDARDWIDTH", "Standard Column Width"],
    0x009A: ["FNGROUPNAME", "Function Group Name"],
    0x009B: ["FILTERMODE", "Sheet Contains Filtered List", xlsrecord.FilterMode],
    0x009C: ["FNGROUPCOUNT", "Built-in Function Group Count"],
    0x009D: ["AUTOFILTERINFO", "Drop-Down Arrow Count", xlsrecord.AutofilterInfo],
    0x009E: ["AUTOFILTER", "AutoFilter Data", xlsrecord.Autofilter],
    0x00A0: ["SCL", "Window Zoom Magnification", xlsrecord.Scl],
    0x00A1: ["SETUP", "Page Setup", xlsrecord.Setup],
    0x00A9: ["COORDLIST", "Polygon Object Vertex Coordinates"],
    0x00AB: ["GCW", "Global Column-Width Flags"],
    0x00AE: ["SCENMAN", "Scenario Output Data"],
    0x00AF: ["SCENARIO", "Scenario Data"],
    0x00B0: ["SXVIEW", "View Definition", xlsrecord.SXView],
    0x00B1: ["SXVD", "View Fields", xlsrecord.Sxvd],
    0x00B2: ["SXVI", "View Item", xlsrecord.SXVI],
    0x00B4: ["SXIVD", "Row/Column Field IDs", xlsrecord.SxIvd],
    0x00B5: ["SXLI", "Line Item Array", xlsrecord.SXLI],
    0x00B6: ["SXPI", "Page Item", xlsrecord.SXPageItem],
    0x00B8: ["DOCROUTE", "Routing Slip Information"],
    0x00B9: ["RECIPNAME", "Recipient Name"],
    0x00BC: ["SHRFMLA", "Shared Formula"],
    0x00BD: ["MULRK", "Multiple RK Cells", xlsrecord.MulRK],
    0x00BE: ["MULBLANK", "Multiple Blank Cells", xlsrecord.MulBlank],
    0x00C1: ["MMS", "ADDMENU/DELMENU Record Group Count"],
    0x00C2: ["ADDMENU", "Menu Addition"],
    0x00C3: ["DELMENU", "Menu Deletion"],
    0x00C5: ["SXDI", "Data Item", xlsrecord.SXDataItem],
    0x00C6: ["SXDB", "PivotTable Cache Data", xlsrecord.SXDb],
    0x00C7: ["SXFDB", "Pivot Field", xlsrecord.SXFDB],
    0x00C8: ["SXDBB", "Indices to Source Data", xlsrecord.SXDBB],
    0x00C9: ["SXDOUBLE", "Double Value", xlsrecord.SXDouble],
    0x00CA: ["SXBOOLEAN", "Boolean Value", xlsrecord.SXBoolean],
    0x00CB: ["SXERROR", "Error Code", xlsrecord.SXError],
    0x00CC: ["SXINT", "Integer Value", xlsrecord.SXInt],
    0x00CD: ["SXSTRING", "String", xlsrecord.SXString],
    0x00CE: ["SXDTR", "Date & Time Special Format", xlsrecord.SXDtr],
    0x00CF: ["SXEMPTY", "Empty Value"],
    0x00D0: ["SXTBL", "Multiple Consolidation Source Info"],
    0x00D1: ["SXTBRGIITM", "Page Item Name Count"],
    0x00D2: ["SXTBPG", "Page Item Indexes"],
    0x00D3: ["OBPROJ", "Visual Basic Project"],
    0x00D5: ["SXSTREAMID", "PivotCache Stream ID", xlsrecord.SXStreamID],
    0x00D6: ["RSTRING", "Cell with Character Formatting"],
    0x00D7: ["DBCELL", "Stream Offsets", xlsrecord.DBCell],
    0x00D8: ["SXRNG", "Numeric/Date Grouping Properties", xlsrecord.SXRng],
    0x00DA: ["BOOKBOOL", "Workbook Option Flag"],
    0x00DC: ["PARAMQRY", "Query Parameters"],
    0x00DC: ["SXEXT", "External Source Information"],
    0x00DD: ["SCENPROTECT", "Scenario Protection"],
    0x00DE: ["OLESIZE", "Size of OLE Object"],
    0x00DF: ["UDDESC", "Description String for Chart Autoformat"],
    0x00E0: ["XF", "Extended Format", xlsrecord.XF],
    0x00E1: ["INTERFACEHDR", "Beginning of User Interface Records"],
    0x00E2: ["INTERFACEEND", "End of User Interface Records"],
    0x00E3: ["SXVS", "PivotCache Source Data Type", xlsrecord.SXViewSource],
    0x00E5: ["MERGECELLS", "Merged cells in the document", xlsrecord.MergeCells],
    0x00EA: ["TABIDCONF", "Sheet Tab ID of Conflict History"],
    0x00EB: ["MSODRAWINGGROUP", "Microsoft Office Drawing Group", xlsrecord.MSODrawingGroup],
    0x00EC: ["MSODRAWING", "Microsoft Office Drawing", xlsrecord.MSODrawing],
    0x00ED: ["MSODRAWINGSELECTION", "Microsoft Office Drawing Selection", xlsrecord.MSODrawingSelection],
    0x00EF: ["PHONETIC", "Asian Phonetic Settings", xlsrecord.PhoneticInfo],
    0x00F0: ["SXRULE", "PivotTable Rule Data", xlsrecord.SxRule],
    0x00F1: ["SXEX", "PivotTable View Extended Information", xlsrecord.SXEx],
    0x00F2: ["SXFILT", "PivotTable Rule Filter"],
    0x00F4: ["SXDXF", "PivotTable Differential Formatting", xlsrecord.SxDXF],
    0x00F5: ["SXITM", "PivotTable Referenced Items"],
    0x00F6: ["SXNAME", "PivotTable Name"],
    0x00F7: ["SXSELECT", "PivotTable Selection Information"],
    0x00F8: ["SXPAIR", "PivotTable Name Pair"],
    0x00F9: ["SXFMLA", "PivotTable Parsed Expression"],
    0x00FB: ["SXFORMAT", "PivotTable Format Record", xlsrecord.SxFormat],
    0x00FC: ["SST", "Shared String Table", xlsrecord.SST],
    0x00FD: ["LABELSST", "Cell Value", xlsrecord.LabelSST],
    0x00FF: ["EXTSST", "Extended Shared String Table"],
    0x0100: ["SXVDEX", "Extended Pivot Field Properties", xlsrecord.SXViewFieldsEx],
    0x0103: ["SXFORMULA", "PivotTable Formula Record"],
    0x0122: ["SXDBEX", "PivotTable Cache Data", xlsrecord.SXDbEx],
    0x013D: ["TABID", "Sheet Tab Index Array"],
    0x0160: ["USESELFS", "Natural Language Formulas Flag"],
    0x0161: ["DSF", "Double Stream File"],
    0x01A9: ["USERBVIEW", "Workbook Custom View Settings"],
    0x01AA: ["USERSVIEWBEGIN", "Custom View Settings"],
    0x01AB: ["USERSVIEWEND", "End of Custom View Records"],
    0x01AD: ["QSI", "External Data Range"],
    0x01AE: ["SUPBOOK", "Supporting Workbook", xlsrecord.SupBook],
    0x01AF: ["PROT4REV", "Shared Workbook Protection Flag"],
    0x01B0: ["CONDFMT", "Conditional Formatting Range Information", xlsrecord.CondFmt],
    0x01B1: ["CF", "Conditional Formatting Conditions", xlsrecord.CF],
    0x01B2: ["DVAL", "Data Validation Information", xlsrecord.DVal],
    0x01B5: ["DCONBIN", "Data Consolidation Information"],
    0x01B6: ["TXO", "Text Object"],
    0x01B7: ["REFRESHALL", "Refresh Flag", xlsrecord.RefreshAll],
    0x01B8: ["HLINK", "Hyperlink", xlsrecord.Hyperlink],
    0x01BB: ["SXFDBTYPE", "SQL Datatype Identifier", xlsrecord.SXFDBType],
    0x01BC: ["PROT4REVPASS", "Shared Workbook Protection Password"],
    0x01BE: ["DV", "Data Validation Criteria", xlsrecord.Dv],
    0x01C0: ["EXCEL9FILE", "Excel 9 File"],
    0X01C1: ["RECALCID", "Recalc Information"],
    0x0200: ["DIMENSIONS", "Cell Table Size", xlsrecord.Dimensions],
    0x0201: ["BLANK", "Blank Cell", xlsrecord.Blank],
    0x0203: ["NUMBER", "Floating-Point Cell Value", xlsrecord.Number],
    0x0204: ["LABEL", "Cell Value", xlsrecord.Label],
    0x0205: ["BOOLERR", "Cell Value"],
    0x0207: ["STRING", "String Value of a Formula", xlsrecord.String],
    0x0208: ["ROW", "Describes a Row", xlsrecord.Row],
    0x020B: ["INDEX", "Index Record"],
    0x0218: ["NAME", "Defined Name"],
    0x0221: ["ARRAY", "Array-Entered Formula", xlsrecord.Array],
    0x0223: ["EXTERNNAME", "Externally Referenced Name"],
    0x0225: ["DEFAULTROWHEIGHT", "Default Row Height", xlsrecord.DefRowHeight],
    0x0231: ["FONT", "Font Description", xlsrecord.Font],
    0x0236: ["TABLE", "Data Table"],
    0x023E: ["WINDOW2", "Sheet Window Information", xlsrecord.Window2],
    0x027E: ["RK", "Cell with Encoded Integer or Floating-Point", xlsrecord.RK],
    0x0293: ["STYLE", "Style Information", xlsrecord.Style],
    0x041E: ["FORMAT", "Number Format", xlsrecord.Format],
    0x04BC: ["SHRFMLA", "Shared Formula", xlsrecord.ShrFmla],
    0x0802: ["QSISXTAG", "Pivot Table and Query Table Extensions", xlsrecord.PivotQueryTableEx],
    0x0809: ["BOF", "Beginning of File", xlsrecord.BOF],
    0x0810: ["SXVIEWEX9", "Pivot Table Extensions", xlsrecord.SXViewEx9],
    0x0850: ["CHARTFRTINFO", "Versions of the application that edited the file", xlsrecord.ChartFrtInfo],
    0x0852: ["CHSTARTBLOCK", "Specifies the beginning of future records", xlsrecord.StartBlock],
    0x0853: ["CHENDBLOCK", "Specifies the end of future records", xlsrecord.EndBlock],
    0x0856: ["CATLAB", "Attributes of axis label", xlsrecord.CatLab],
    0x0858: ["CHPIVOTREF", "Pivot Chart Reference"],
    0x0862: ["SHEETLAYOUT", "Tab Color below Sheet Name"],
    0x0863: ["BOOKEXT", "Extra Book Info"],
    0x0864: ["SXADDL", "Pivot Table Additional Info", xlsrecord.SXAddlInfo],
    0x0867: ["FEATHDR", "Shared Feature Header", xlsrecord.FeatureHeader],
    0x0868: ["FEAT", "Shared Feature Data (wrongly named RANGEPROTECTION elsewhere)", xlsrecord.FeatureData],
    0x086A: ["DATALABEXT", "Extended Data Label"],
    0x086B: ["DATALABEXTCONTENTS", "Contents of an extended data label", xlsrecord.DataLabExtContents],
    0x086C: ["CELLWATCH", "Reference to a watched cell"],
    0x0871: ["FEATHDR11", "Common information for all tables on a sheet"],
    0x0872: ["FEATURE11", "Shared feature data for a table in a worksheet", xlsrecord.Feature11],
    0x0873: ["DROPDOWNOBJIDS", "Object identifiers of autofilter dropdown objects"],
    0x0875: ["CONTINUEFRT11", "Continuation of the data in a preceding Future Record Type record that has data longer than 8,224 bytes"],
    0x0876: ["DCONN", "Information for a single data connection"],
    0x0877: ["LIST12", "Additional formatting information for a table"],
    0x0878: ["FEATURE12", "Shared feature data that is used to describe a table in a worksheet"],
    0x0879: ["CONDFMT12", "Conditional formatting rules that are associated with a set of cells, when all the rules are specified using CF12 records"],
    0x087A: ["CF12", "Conditional formatting rule"],
    0x087B: ["CFEX", "Extends a CondFmt"],
    0x087C: ["XFCRC", "Number of XF records contained in this file and that contains a checksum of the data in those records"],
    0x087D: ["XFEXT", "XF Extension"],
    0x087E: ["AUTOFILTER12", "AutoFilter properties"],
    0x087F: ["CONTINUEFRT12", "Continuation of the data in a preceding Future Record Type record that has data longer than 8,224 bytes"],
    0x088B: ["PLV", "Page Layout view for a sheet"],
    0x088C: ["COMPAT12", "Compatibility Checker 12"],
    0x088E: ["TABLESTYLES", "Table Styles"],
    0x0892: ["STYLEEXT", "Named Cell Style Extension"],
    0x0896: ["THEME", "Theme"],
    0x089A: ["MTRSETTINGS", "Multi-threaded Calculation Settings"],
    0x089C: ["HEADERFOOTER", "Header Footer"],
    0x089B: ["COMPRESSPICTURES", "Automatic Picture Compression Mode"],
    0x08A3: ["FORCEFULLCALCULATION", "Force Full Calculation Mode"],
    0x1001: ["UNITS", unusedRecDesc, xlsrecord.Units],
    0x1002: ["CHART", "Position And Size of Chart Area", xlsrecord.Chart],
    0x1003: ["SERIES", "Data Properties for Series, Trendlines or Error Bars", xlsrecord.Series],
    0x1006: ["CHDATAFORMAT", "Data point or series that the formatting information that follows applies to (2.4.74)", xlsrecord.DataFormat],
    0x1007: ["LINEFORMAT", "Appearance of A Line", xlsrecord.LineFormat],
    0x1009: ["MARKERFORMAT", "Color, Size, and Shape of the Markers", xlsrecord.MarkerFormat],
    0x100A: ["AREAFORMAT", "Patterns and Colors in Filled Region of Chart", xlsrecord.AreaFormat],
    0x100B: ["CHPIEFORMAT", "Distance of a data point from the center", xlsrecord.PieFormat],
    0x100C: ["CHATTACHEDLABEL", "Properties of a data label", xlsrecord.AttachedLabel],
    0x100D: ["SERIESTEXT", "Series Category Name or Title Text in Chart", xlsrecord.SeriesText],
    0x1014: ["CHTYPEGROUP", "Properties of a chart group", xlsrecord.ChartFormat],
    0x1015: ["LEGEND", "Legend Properties", xlsrecord.Legend],
    0x1016: ["SERIESLIST", "Series of the chart", xlsrecord.SeriesList],
    0x1017: ["CHBAR, CHCOLUMN", "Bar chart group", xlsrecord.CHBar],
    0x1018: ["CHLINE", "Line chart group", xlsrecord.CHLine],
    0x1019: ["CHPIE", "Pie/Doughnut chart group", xlsrecord.CHPie],
    0x101A: ["CHAREA", "Area chart group", xlsrecord.CHArea],
    0x101B: ["CHSCATTER", "Scatter/Bubble chart group", xlsrecord.CHScatter],
    0x101C: ["CHCHARTLINE", "Specifies the presence of lines", xlsrecord.CrtLine],
    0x101D: ["CHAXIS", "Chart Axis", xlsrecord.CHAxis],
    0x101E: ["CHTICK", "Attributes of the axis labels and tick marks", xlsrecord.Tick],
    0x101F: ["CHVALUERANGE", "Chart Axis Value Range", xlsrecord.CHValueRange],
    0x1020: ["CHLABELRANGE", "Chart Axis Label Range", xlsrecord.CHLabelRange],
    0x1021: ["CHAXISLINE", "Specifies which part of the axis is specified by the LineFormat record  that follows(2.4.12)", xlsrecord.AxisLine],
    0x1022: ["CRTLINK", unusedRecDesc, xlsrecord.CrtLink],
    0x1024: ["DEFAULTTEXT", "Default Text", xlsrecord.DefaultText],
    0x1025: ["TEXT", "Label Properties", xlsrecord.Text],
    0x1026: ["CHFONT", "Font for a given text element", xlsrecord.FontX],
    0x1027: ["CHOBJECTLINK", "Object on a chart that is linked to a text", xlsrecord.ObjectLink],
    0x1032: ["FRAME", "Type, Size and Position of the Frame around A Chart", xlsrecord.Frame],
    0x1033: ["BEGIN", "Start of Chart Sheet Substream", xlsrecord.Begin],
    0x1034: ["END", "End of Chart Sheet Substream", xlsrecord.End],
    0x1035: ["CHPLOTFRAME", "Chart Plot Frame (indicates the frame that follows)", xlsrecord.PlotArea],
    0x103A: ["CHCHART3D", "Attributes of the 3-D plot area", xlsrecord.Chart3d],
    0x103C: ["CHPICFORMAT", "?"],
    0x103D: ["CHDROPBAR", "Attributes of the up/down bars between multiple series", xlsrecord.DropBar],
    0x103E: ["CHRADARLINE", "Radar chart group", xlsrecord.CHRadar],
    0x103F: ["CHSURFACE", "Surface chart group", xlsrecord.CHRadar],
    0x1040: ["CHRADARAREA", "?"],
    0x1041: ["CHAXESSET", "Properties of an axis group", xlsrecord.AxisParent],
    0x1044: ["CHPROPERTIES", "Properties of a chart(2.4.261)", xlsrecord.CHProperties],
    0x1045: ["CHSERGROUP", "Chart group for the current series(2.4.256)", xlsrecord.SerToCrt],
    0x1046: ["AXESUSED", "Number of axis groups on the chart(2.4.10)", xlsrecord.AxesUsed],
    0x1048: ["CHPIVOTREF", "?"],
    0x104A: ["CHSERPARENT", "?"],
    0x104B: ["CHSERTRENDLINE", "?"],
    0x104E: ["CHFORMAT", "?"],
    0x104F: ["CHFRAMEPOS", "Size and position for a legend, an attached label, or the plot area(2.4.201)", xlsrecord.Pos],
    0x1050: ["CHFORMATRUNS", "?"],
    0x1051: ["BRAI", "Data Source of A Chart", xlsrecord.Brai],
    0x105B: ["CHSERERRORBAR", "?"],
    0x105D: ["CHSERIESFORMAT", "Series properties", xlsrecord.SerFmt],
    0x105F: ["CHART3DBARSHAPE", "Shape of the Data Points", xlsrecord.Chart3DBarShape],
    0x1060: ["FBI", "Font Information for Chart", xlsrecord.Fbi],
    0x1061: ["CHPIEEXT", "Pie/bar of pie chart group", xlsrecord.BobPop],
    0x1062: ["AXCEXT", "Additional extension properties of a date axis(2.4.9)", xlsrecord.AxcExt],
    0x1063: ["DAT", "Options of the data table(2.4.73)", xlsrecord.Dat],
    0x1064: ["PLOTGROWTH", "Font Scaling Information in the Plot Area", xlsrecord.PlotGrowth],
    0x1065: ["CHSIINDEX*", "Part of a group of records which specify the data of a chart", xlsrecord.SIIndex],
    0x1066: ["CHESCHERFORMAT", "Properties of a fill pattern", xlsrecord.GelFrame]
}

recDataRev = {
    0x0137: ["RRDINSDEL", "Insertion / deletion of rows / columns", xlsrecord.RRDInsDel],
    0x0138: ["INFO*", "Change Track Info"],
    0x013B: ["RRDCHGCELL", "Change cell revision", xlsrecord.RRDChgCell],
    0x013D: ["SHEETID*", "Change Track Sheet Identifier"],
    0x0140: ["MOVERANGE*", "Change Track Move Range"],
    0x014D: ["INSERTSHEET*", "Change Track Insert Sheet"],
    0x014E: ["BONB*", "Change Track Beginning of Nested Block"],
    0x0150: ["BONB*", "Change Track Beginning of Nested Block"],
    0x014F: ["EONB*", "Change Track End of Nested Block"],
    0x0151: ["EONB*", "Change Track End of Nested Block"]
}


class StreamData(object):
    """run-time stream data."""
    def __init__ (self):
        self.encrypted = False
        self.pivotCacheIDs = {}
        self.pivotCacheFields = []

    def appendPivotCacheId (self, newId):
        # must be 4-digit with leading '0's.
        strId = "%.4d"%newId
        self.pivotCacheIDs[strId] = True

    def isPivotCacheStream (self, name):
        return self.pivotCacheIDs.has_key(name)


class XLStream(object):

    def __init__ (self, chars, params, strmData):
        self.chars = chars
        self.size = len(self.chars)
        self.pos = 0
        self.version = None

        self.header = None
        self.MSAT = None
        self.SAT = None

        self.params = params
        self.strmData = strmData

    def __printSep (self, c, w, prefix=''):
        print(prefix + c*w)

    def printStreamInfo (self):
        self.__printSep('=', globals.OutputWidth)
        print("Excel File Format Dumper by Kohei Yoshida")
        print("  total stream size: %d bytes"%self.size)
        self.__printSep('=', globals.OutputWidth)
        print('')

    def printHeader (self):
        self.__parseHeader()
        self.header.output()
        self.MSAT = self.header.getMSAT()

    def printMSAT (self):
        self.MSAT.output()

    def printSAT (self):
        sat = self.MSAT.getSAT()
        sat.output()

    def printSSAT (self):
        obj = self.header.getSSAT()
        if obj == None:
            return
        obj.output()

    def __parseHeader (self):
        if self.header == None:
            self.header = ole.Header(self.chars, self.params)
            self.pos = self.header.parse()

    def __getDirectoryObj (self):
        self.__parseHeader()
        obj = self.header.getDirectory()
        if obj == None:
            return None
        obj.parseDirEntries()
        return obj

    def printDirectory (self):
        obj = self.__getDirectoryObj()
        if obj == None:
            return
        obj.output()

    def getDirectoryEntries (self):
        obj = self.__getDirectoryObj()
        if obj == None:
            return
        return obj.getDirectoryEntries()

    def getDirectoryStream (self, entry):
        obj = self.__getDirectoryObj()
        bytes = []
        if obj != None:
            bytes = obj.getRawStream(entry)
        strm = XLDirStream(bytes, self.params, self.strmData)
        return strm


class DirType:
    Workbook = 0
    RevisionLog = 1
    PivotTableCache = 2


class XLDirStream(object):

    def __init__ (self, bytes, params, strmData):
        self.bytes = bytes
        self.size = len(self.bytes)
        self.pos = 0
        self.type = DirType.Workbook

        self.params = params
        self.strmData = strmData


    def readRaw (self, size=1):
        # assume little endian
        bytes = 0
        for i in xrange(0, size):
            b = ord(self.bytes[self.pos])
            if i == 0:
                bytes = b
            else:
                bytes += b*(256**i)
            self.pos += 1

        return bytes

    def readByteArray (self, size=1):
        if self.pos + size >= self.size:
            raise EndOfStream
        curpos = self.pos
        self.pos += size
        return self.bytes[curpos:self.pos]

    def __printSep (self, c, w, prefix=''):
        print(prefix + c*w)

    def __readRecordBytes (self):
        if self.size - self.pos < 4:
            raise EndOfStream

        pos = self.pos
        header = self.readRaw(2)
        if header == 0x0000:
            raise EndOfStream
        size = self.readRaw(2)
        bytes = self.readByteArray(size)
        return pos, header, size, bytes

    def __readRecAndContBytes(self):
        '''Read record itself and possible CONTINUE blocks.'''

        pos, header, size, bytes = self.__readRecordBytes()

        # Records boundaries/offset list (only useful if there are
        # CONTINUE records)
        roflist = [size]
        
        # Read possible CONTINUE records, and concatenate the data
        while self.peekNext() == 0x3c:
            cpos, cheader, csize, cbytes = self.__readRecordBytes()
            bytes += cbytes
            size += csize
            roflist.append(size)

        return pos, header, size, bytes, roflist

    def peekNext (self):
        '''Check type of next record without changing stream state'''
        
        if self.size - self.pos < 4:
            raise EndOfStream

        pos = self.pos
        header = self.readRaw(2)
        if header == 0x0000:
            raise EndOfStream
        self.pos = pos
        return header
        
    def __getRecordHandler (self, header, size, bytes, roflist):
        # record handler that parses the raw bytes and displays more
        # meaningful information.
        handler = None
        if recData.has_key(header) and len(recData[header]) >= 3:
            handler = recData[header][2](header, size, bytes, self.strmData, roflist)

        if handler != None and self.strmData.encrypted:
            # record handler exists.  Parse the record and display more info
            # unless the stream is encrypted.
            handler = None

        return handler

    def __postReadRecord (self, header):
        if recData.has_key(header) and recData[header][0] == "FILEPASS":
            # presence of FILEPASS record indicates that the stream is
            # encrypted.
            self.strmData.encrypted = True

    def fillModel (self, model):
        pos, header, size, bytes, roflist = self.__readRecAndContBytes()
        handler = self.__getRecordHandler(header, size, bytes, roflist)
        if handler != None:
            try:
                handler.fillModel(model)
            except Exception as e:
                if not globals.params.catchExceptions:
                    raise
                globals.error("XLDirStream:fillModel: %s\n" % e)
        self.__postReadRecord(header)


    def getNextRecordHandler (self):
        pos, header, size, bytes, roflist = self.__readRecAndContBytes()
        return self.__getRecordHandler(header, size, bytes, roflist)

    def readRecord (self):
        pos, header, size, bytes, roflist = self.__readRecAndContBytes()

        # record handler that parses the raw bytes and displays more
        # meaningful information.
        handler = None

        print("")
        headerStr = "%4.4Xh: "%header
        self.__printSep('=', globals.OutputWidth-len(headerStr), headerStr)
        if recData.has_key(header):
            print("%4.4Xh: %s - %s (%4.4Xh)"%
                  (header, recData[header][0], recData[header][1], header))
            if len(recData[header]) >= 3:
                handler = recData[header][2](header, size, bytes, self.strmData, roflist)
        elif self.type == DirType.RevisionLog and recDataRev.has_key(header):
            print("%4.4Xh: %s - %s (%4.4Xh)"%
                  (header, recDataRev[header][0], recDataRev[header][1], header))
            if len(recDataRev[header]) >= 3:
                handler = recDataRev[header][2](header, size, bytes, self.strmData, roflist)
        else:
            print("%4.4Xh: [unknown record name] (%4.4Xh)"%(header, header))

        if self.params.showStreamPos:
            print("%4.4Xh:   size = %d; pos = %d"%(header, size, pos))
        else:
            print("%4.4Xh:   size = %d"%(header, size))

        # print the raw bytes, with 16 bytes per line.
        self.__printSep('-', globals.OutputWidth-len(headerStr), headerStr)
        lines = []
        for i in xrange(0, size):
            if i % 16 == 0:
                lines.append([])
            lines[-1].append(bytes[i])

        for line in lines:
            output("%4.4Xh: "%header)
            n = len(line)
            for byte in line:
                output("%2.2X "%ord(byte))
            for i in xrange(n, 16):
                output("   ")
            output('  ')

            for byte in line:
                output(globals.toCharOrDot(byte))

            print("")

        if handler != None and not self.strmData.encrypted:
            # record handler exists.  Parse the record and display more info
            # unless the stream is encrypted.
            handler.output()

        self.__postReadRecord(header)
        return header

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

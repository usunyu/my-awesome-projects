# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import globals, xlsmodel
import sys
import textwrap
import zlib
import base64
from pptrecord import shapeTypes

def indent (level):
    return '  '*level

def headerLine ():
    return "+ " + "-"*58 + "+"

def mm100_to_twip(value):
    if value >= 0:
        return (((value)*72+63)/127)
    else:
        return (((value)*72-63)/127)

def emu_to_mm100(value):
    return value / 360

def emu_to_twip(value):
    return mm100_to_twip(emu_to_mm100(value))

def hexdump(value):
    ret = []
    for i in value:
        ret.append("%02x" % ord(i))
    return "".join(ret)

def inflate(bytes):
    return textwrap.fill(base64.b64encode(zlib.decompress(bytes)), width=160)

class RecordHeader:

    size = 8

    class Type:
        dggContainer            = 0xF000
        BStoreContainer         = 0xF001
        dgContainer             = 0xF002
        spgrContainer           = 0xF003
        spContainer             = 0xF004
        solverContainer         = 0xF005
        FDGGBlock               = 0xF006
        FBSE                    = 0xF007
        FDG                     = 0xF008
        FSPGR                   = 0xF009
        FSP                     = 0xF00A
        FOPT                    = 0xF00B
        FClientTextbox          = 0xF00D
        FClientAnchor           = 0xF010
        FClientData             = 0xF011
        FConnectorRule          = 0xF012
        BlipEMF                 = 0xF01A
        BlipPNG                 = 0xF01E
        FDGSL                   = 0xF119
        SplitMenuColorContainer = 0xF11E
        TertiaryFOPT            = 0xF122

    containerTypeNames = {
        Type.dggContainer:            'OfficeArtDggContainer',
        Type.BStoreContainer:         'OfficeArtBStoreContainer',
        Type.dgContainer:             'OfficeArtDgContainer',
        Type.spContainer:             'OfficeArtSpContainer',
        Type.spgrContainer:           'OfficeArtSpgrContainer',
        Type.solverContainer:         'OfficeArtSolverContainer',
        Type.FDG:                     'OfficeArtFDG',
        Type.FDGGBlock:               'OfficeArtFDGGBlock',
        Type.FBSE:                    'OfficeArtFBSE',
        Type.FOPT:                    'OfficeArtFOPT',
        Type.FClientTextbox:          'OfficeArtClientTextbox',
        Type.FClientAnchor:           'OfficeArtClientAnchor',
        Type.FClientData:             'OfficeArtClientData',
        Type.FSP:                     'OfficeArtFSP',
        Type.FSPGR:                   'OfficeArtFSPGR',
        Type.FConnectorRule:          'OfficeArtFConnectorRule',
        Type.BlipPNG:                 'OfficeArtBlipPng',
        Type.FDGSL:                   'OfficeArtFDGSL',
        Type.SplitMenuColorContainer: 'OfficeArtSplitMenuColorContainer'
    }

    @staticmethod
    def getRecTypeName (recType):
        if RecordHeader.containerTypeNames.has_key(recType):
            return RecordHeader.containerTypeNames[recType]
        return 'unknown'

    @staticmethod
    def appendHeaderLine (recHdl, line):
        n = len(line)
        if n < 60:
            line += ' '*(60-n)
            line += '|'
        recHdl.appendLine(line)

    def __init__ (self, strm):
        mixed = strm.readUnsignedInt(2)
        self.recVer = (mixed & 0x000F)
        self.recInstance = (mixed & 0xFFF0) / 16
        self.recType = strm.readUnsignedInt(2)
        self.recLen  = strm.readUnsignedInt(4)

    def appendLines (self, recHdl, level=0):
        pre = "| "
        RecordHeader.appendHeaderLine(recHdl, pre + "Record type: 0x%4.4X (%s)"%(self.recType, RecordHeader.getRecTypeName(self.recType)))
        RecordHeader.appendHeaderLine(recHdl, pre + "  version: 0x%1.1X   instance: 0x%3.3X   size: %d"%
            (self.recVer, self.recInstance, self.recLen))

    def dumpXml(self, recHdl):
        recHdl.appendLine('<rh type="OfficeArtRecordHeader">')
        recHdl.appendLine('<recVer value="0x%1.1X"/>' % self.recVer)
        shapeType = ""
        if self.recType == RecordHeader.Type.FSP:
            # In this case recInstance is from the MSOSPT enumeration
            shapeType = ' msospt="%s"' % shapeTypes[self.recInstance][0]
        recHdl.appendLine('<recInstance value="0x%1.1X"%s/>' % (self.recInstance, shapeType))
        recHdl.appendLine('<recType value="0x%1.1X"/>' % self.recType)
        recHdl.appendLine('<recLen value="0x%1.1X"/>' % self.recLen)
        recHdl.appendLine('</rh>')


class ColorRef:
    def __init__ (self, byte):
        self.red   = (byte & 0x000000FF)
        self.green = (byte & 0x0000FF00) / 256
        self.blue  = (byte & 0x00FF0000) / 65536
        self.flag  = (byte & 0xFF000000) / 16777216

        self.paletteIndex = (self.flag & 0x01) != 0
        self.paletteRGB   = (self.flag & 0x02) != 0
        self.systemRGB    = (self.flag & 0x04) != 0
        self.schemeIndex  = (self.flag & 0x08) != 0
        self.sysIndex     = (self.flag & 0x10) != 0

    def appendLine (self, recHdl, level):
        if self.paletteIndex:
            # red and green and used as an unsigned index into the current color palette.
            paletteId = self.green * 256 + self.red
            recHdl.appendLine(indent(level) + "color index in current palette: %d"%paletteId)
        if self.sysIndex:
            # red and green are used as an unsigned 16-bit index into the system color table.
            sysId = self.green * 256 + self.red
            recHdl.appendLine(indent(level) + "system index: %d"%sysId)
        elif self.schemeIndex:
            # the red value is used as as a color scheme index
            recHdl.appendLine(indent(level) + "color scheme index: %d"%self.red)

        else:
            recHdl.appendLine(indent(level) + "color: (red=%d, green=%d, blue=%d)    flag: 0x%2.2X"%
                (self.red, self.green, self.blue, self.flag))
            recHdl.appendLine(indent(level) + "palette index: %s"%recHdl.getTrueFalse(self.paletteIndex))
            recHdl.appendLine(indent(level) + "palette RGB: %s"%recHdl.getTrueFalse(self.paletteRGB))
            recHdl.appendLine(indent(level) + "system RGB: %s"%recHdl.getTrueFalse(self.systemRGB))
            recHdl.appendLine(indent(level) + "system RGB: %s"%recHdl.getTrueFalse(self.systemRGB))
            recHdl.appendLine(indent(level) + "scheme index: %s"%recHdl.getTrueFalse(self.schemeIndex))
            recHdl.appendLine(indent(level) + "system index: %s"%recHdl.getTrueFalse(self.sysIndex))

    def dumpXml(self, recHdl):
        recHdl.appendLine('<colorRef type="OfficeArtCOLORREF">')
        if self.paletteIndex:
            # red and green and used as an unsigned index into the current color palette.
            paletteId = self.green * 256 + self.red
            recHdl.appendLine('<paletteIndex value="%d"/>'%paletteId)
        if self.sysIndex:
            # red and green are used as an unsigned 16-bit index into the system color table.
            sysId = self.green * 256 + self.red
            recHdl.appendLine('<sysIndex value="%d"/>'%sysId)
        elif self.schemeIndex:
            # the red value is used as as a color scheme index
            recHdl.appendLine('<schemeIndex value="%d"/>'%self.red)

        else:
            recHdl.appendLine('<color red="%d" green="%d" blue="%d" flag="0x%2.2X"/>'%
                (self.red, self.green, self.blue, self.flag))
            recHdl.appendLine('<paletteIndex value="%s"/>'%self.paletteIndex)
            recHdl.appendLine('<paletteRGB value="%s"/>'%self.paletteRGB)
            recHdl.appendLine('<systemRGB value="%s"/>'%self.systemRGB)
            recHdl.appendLine('<schemeIndex value="%s"/>'%self.schemeIndex)
            recHdl.appendLine('<sysIndex value="%s"/>'%self.sysIndex)
        recHdl.appendLine('</colorRef>')



class FDG:
    def __init__ (self, strm):
        self.shapeCount  = strm.readUnsignedInt(4)
        self.lastShapeID = strm.readUnsignedInt(4)

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("FDG content (drawing data):")
        recHdl.appendLine("  ID of this shape: %d"%rh.recInstance)
        recHdl.appendLine("  shape count: %d"%self.shapeCount)
        recHdl.appendLine("  last shape ID: %d"%self.lastShapeID)

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<drawingData type="OfficeArtFDG">')
        recHdl.appendLine('<csp value="%d"/>' % self.shapeCount)
        recHdl.appendLine('<spidCur value="%d"/>' % self.lastShapeID)
        recHdl.appendLine('</drawingData>')


class IDCL:
    def __init__ (self, strm):
        self.dgid = strm.readUnsignedInt(4)
        self.cspidCur = strm.readUnsignedInt(4)

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("IDCL content:")
        recHdl.appendLine("  drawing ID: %d"%self.dgid)
        recHdl.appendLine("  cspidCur: 0x%8.8X"%self.cspidCur)

    def dumpXml(self, recHdl, rh):
        recHdl.appendLine('<idcl type="OfficeArtIDCL">')
        recHdl.appendLine('<dgid value="%d"/>' % self.dgid)
        recHdl.appendLine('<cspidCur value="0x%8.8X"/>' % self.cspidCur)
        recHdl.appendLine('</idcl>')

class FDGG:
    def __init__ (self, strm):
        self.spidMax  = strm.readUnsignedInt(4) # current max shape ID
        self.cidcl    = strm.readUnsignedInt(4) # number of OfficeArtIDCL's.
        self.cspSaved = strm.readUnsignedInt(4) # total number of shapes in all drawings
        self.cdgSaved = strm.readUnsignedInt(4) # total number of drawings saved in the file

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("FDGG content:")
        recHdl.appendLine("  current max shape ID: %d"%self.spidMax)
        recHdl.appendLine("  number of OfficeArtIDCL's: %d"%self.cidcl)
        recHdl.appendLine("  total number of shapes in all drawings: %d"%self.cspSaved)
        recHdl.appendLine("  total number of drawings in the file: %d"%self.cdgSaved)

    def dumpXml(self, recHdl, rh):
        recHdl.appendLine('<fdgg type="OfficeArtFDGG">')
        recHdl.appendLine('<spidMax value="%d"/>' % self.spidMax)
        recHdl.appendLine('<cidcl value="%d"/>' % self.cidcl)
        recHdl.appendLine('<cspSaved value="%d"/>' % self.cspSaved)
        recHdl.appendLine('<cdgSaved value="%d"/>' % self.cdgSaved)
        recHdl.appendLine('</fdgg>')

class FDGGBlock:
    def __init__ (self, strm):
        self.head = FDGG(strm)
        self.idcls = []
        # NOTE: The spec says head.cidcl stores the number of IDCL's, but each
        # FDGGBlock only contains bytes enough to store (head.cidcl - 1) of
        # IDCL's.
        for i in xrange(0, self.head.cidcl-1):
            idcl = IDCL(strm)
            self.idcls.append(idcl)

    def appendLines (self, recHdl, rh):
        self.head.appendLines(recHdl, rh)
        for idcl in self.idcls:
            idcl.appendLines(recHdl, rh)

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<drawingGroup type="OfficeArtFDGGBlock">')
        self.head.dumpXml(recHdl, rh)
        for i, idcl in enumerate(self.idcls):
            recHdl.appendLine('<Rgidcl index="%d">' % i)
            idcl.dumpXml(recHdl, rh)
            recHdl.appendLine('</Rgidcl>')
        recHdl.appendLine('</drawingGroup>')


class FDGSL:
    selectionMode = {
        0x00000000: 'default state',
        0x00000001: 'ready to rotate',
        0x00000002: 'ready to change the curvature of line shapes',
        0x00000007: 'ready to crop the picture'
    }

    def __init__ (self, strm):
        self.cpsp = strm.readUnsignedInt(4)  # the spec says undefined.
        self.dgslk = strm.readUnsignedInt(4) # selection mode
        self.shapeFocus = strm.readUnsignedInt(4) # shape ID in focus
        self.shapesSelected = []
        shapeCount = (strm.getSize() - 20)/4
        for i in xrange(0, shapeCount):
            spid = strm.readUnsignedInt(4)
            self.shapesSelected.append(spid)

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("FDGSL content:")
        recHdl.appendLine("  selection mode: %s"%
            globals.getValueOrUnknown(FDGSL.selectionMode, self.dgslk))
        recHdl.appendLine("  ID of shape in focus: %d"%self.shapeFocus)
        for shape in self.shapesSelected:
            recHdl.appendLine("  ID of shape selected: %d"%shape)

class MetafileHeader:
    """[MS-ODRAW] 2.2.31 The OfficeArtMetafileHeader record specifies how to process a metafile."""
    def __init__(self, strm):
        self.strm = strm

    def parseBytes(self, rh):
        self.cbSize = self.strm.readUnsignedInt(4)
        self.strm.readBytes(16) # TODO rcBounds
        self.strm.readBytes(8) # TODO ptSize
        self.cbSave = self.strm.readUnsignedInt(4)
        self.compression = self.strm.readUnsignedInt(1)
        self.filter = self.strm.readUnsignedInt(1)

    def appendLines(self, recHdl, rh):
        pass

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<metafileHeader type="OfficeArtMetafileHeader">')
        recHdl.appendLine('<cbSize value="%s"/>' % self.cbSize)
        recHdl.appendLine('<cbSave value="%s"/>' % self.cbSave)
        recHdl.appendLine('<compression value="%s"/>' % hex(self.compression))
        recHdl.appendLine('<filter value="%s"/>' % hex(self.filter))
        recHdl.appendLine('</metafileHeader>')

class BlipEMF:
    """[MS-ODRAW] 2.2.24 The OfficeArtBlipEMF record specifies BLIP file data for the enhanced metafile format (EMF)."""
    def __init__(self, strm):
        self.strm = strm

    def __parseBytes(self, rh):
        pos = self.strm.pos
        self.rgbUid1 = self.strm.readBytes(16)
        if rh.recInstance == 0x3D5:
            self.rgbUid2 = self.strm.readBytes(16)
        else:
            self.rgbUid2 = None
        self.metafileHeader = MetafileHeader(self.strm)
        self.metafileHeader.parseBytes(rh)
        self.BLIPFileData = self.strm.readBytes(self.metafileHeader.cbSave)

    def appendLines(self, recHdl, rh):
        pass

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<blipEmf type="OfficeArtBlipEMF">')
        self.__parseBytes(rh)
        recHdl.appendLine('<rgbUid1 value="%s"/>' % hexdump(self.rgbUid1))
        if self.rgbUid2:
            recHdl.appendLine('<rgbUid2 value="%s"/>' % hexdump(self.rgbUid2))
        self.metafileHeader.dumpXml(recHdl, model, rh)
        if self.metafileHeader.compression == 0x00:
            # No idea if this is a reasonable limit.
            if len(self.BLIPFileData) > pow(2, 18):
                recHdl.appendLine('<info what="BLIPFileData size is too large (%s bytes), skipping"/>' % len(self.BLIPFileData))
            else:
                recHdl.appendLine('<BLIPFileData value="%s"/>' % inflate(self.BLIPFileData))
        else:
            recHdl.appendLine('<todo what="BlipEMF::dumpXml(): unexpected metafileHeader.compression == %s"/>' % hex(self.metafileHeader.compression))
        recHdl.appendLine('</blipEmf>')

class BlipPNG:
    def __init__(self, strm):
        self.strm = strm

    def __parseBytes(self, rh):
        pos = self.strm.pos
        self.rgbUid1 = self.strm.readBytes(16)
        if rh.recInstance == 0x06E1:
            self.rgbUid2 = self.strm.readBytes(16)
        else:
            self.rgbUid2 = None
        self.tag = self.strm.readUnsignedInt(1)
        header = self.strm.pos - pos
        data = rh.recLen - header
        self.BLIPFileData = self.strm.readBytes(data)

    def appendLines(self, recHdl, rh):
        pass

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<blipPng type="OfficeArtBlipPng">')
        self.__parseBytes(rh)
        recHdl.appendLine('<rgbUid1 value="%s"/>' % hexdump(self.rgbUid1))
        if self.rgbUid2:
            recHdl.appendLine('<rgbUid2 value="%s"/>' % hexdump(self.rgbUid2))
        recHdl.appendLine('<tag value="%s"/>' % self.tag)
        recHdl.appendLine('<BLIPFileData value="%s"/>' % hexdump(self.BLIPFileData))
        recHdl.appendLine('</blipPng>')

class FOPT:
    """property table for a shape instance"""

    class TextBoolean:

        def __parseBytes(self, prop):
            self.A = (prop.value & 0x00000001) != 0
            self.B = (prop.value & 0x00000002) != 0
            self.C = (prop.value & 0x00000004) != 0
            self.D = (prop.value & 0x00000008) != 0
            self.E = (prop.value & 0x00000010) != 0
            self.F = (prop.value & 0x00010000) != 0
            self.G = (prop.value & 0x00020000) != 0
            self.H = (prop.value & 0x00040000) != 0
            self.I = (prop.value & 0x00080000) != 0
            self.J = (prop.value & 0x00100000) != 0

        def appendLines (self, recHdl, prop, level):
            self.__parseBytes(prop)
            recHdl.appendLineBoolean(indent(level) + "fit shape to text",     self.B)
            recHdl.appendLineBoolean(indent(level) + "auto text margin",      self.D)
            recHdl.appendLineBoolean(indent(level) + "select text",           self.E)
            recHdl.appendLineBoolean(indent(level) + "use fit shape to text", self.G)
            recHdl.appendLineBoolean(indent(level) + "use auto text margin",  self.I)
            recHdl.appendLineBoolean(indent(level) + "use select text",       self.J)

        def dumpXml(self, recHdl, prop):
            self.__parseBytes(prop)
            recHdl.appendLine('<textBooleanProperties>')
            recHdl.appendLine('<fUsefSelectText value="%s"/>' % self.A)
            recHdl.appendLine('<fUsefAutoTextMargin value="%s"/>' % self.B)
            recHdl.appendLine('<unused2 value="%s"/>' % self.C)
            recHdl.appendLine('<fUsefFitShapeToText value="%s"/>' % self.D)
            recHdl.appendLine('<unused3 value="%s"/>' % self.E)
            recHdl.appendLine('<fSelectText value="%s"/>' % self.F)
            recHdl.appendLine('<fAutoTextMargin value="%s"/>' % self.G)
            recHdl.appendLine('<unused5 value="%s"/>' % self.H)
            recHdl.appendLine('<fFitShapeToText value="%s"/>' % self.I)
            recHdl.appendLine('<unused6 value="%s"/>' % self.J)
            recHdl.appendLine('</textBooleanProperties>')

    class CXStyle:
        style = [
            'straight connector',     # 0x00000000
            'elbow-shaped connector', # 0x00000001
            'curved connector',       # 0x00000002
            'no connector'            # 0x00000003
        ]

        def appendLines (self, recHdl, prop, level):
            styleName = globals.getValueOrUnknown(FOPT.CXStyle.style, prop.value)
            recHdl.appendLine(indent(level) + "connector style: %s (0x%8.8X)"%(styleName, prop.value))

        def dumpXml(self, recHdl, prop):
            styleName = globals.getValueOrUnknown(FOPT.CXStyle.style, prop.value)
            recHdl.appendLine('<cxstyle name="%s" value="0x%8.8X"/>' % (styleName, prop.value))

    class FillColor:

        def appendLines (self, recHdl, prop, level):
            color = ColorRef(prop.value)
            color.appendLine(recHdl, level)

        def dumpXml(self, recHdl, prop):
            recHdl.appendLine('<fillColor>')
            color = ColorRef(prop.value)
            color.dumpXml(recHdl)
            recHdl.appendLine('</fillColor>')

    class FillStyle:

        def __parseBytes(self, recHdl):
            flag1 = recHdl.readUnsignedInt(1)
            recHdl.moveForward(1)
            flag2 = recHdl.readUnsignedInt(1)
            recHdl.moveForward(1)
            self.A = (flag1 & 0x01) != 0 # fNoFillHitTest
            self.B = (flag1 & 0x02) != 0 # fillUseRect
            self.C = (flag1 & 0x04) != 0 # fillShape
            self.D = (flag1 & 0x08) != 0 # fHitTestFill
            self.E = (flag1 & 0x10) != 0 # fFilled
            self.F = (flag1 & 0x20) != 0 # fUseShapeAnchor
            self.G = (flag1 & 0x40) != 0 # fRecolorFillAsPicture

            self.H = (flag2 & 0x01) != 0 # fUseNoFillHitTest
            self.I = (flag2 & 0x02) != 0 # fUsefillUseRect
            self.J = (flag2 & 0x04) != 0 # fUsefillShape
            self.K = (flag2 & 0x08) != 0 # fUsefHitTestFill
            self.L = (flag2 & 0x10) != 0 # fUsefFilled
            self.M = (flag2 & 0x20) != 0 # fUsefUseShapeAnchor
            self.N = (flag2 & 0x40) != 0 # fUsefRecolorFillAsPicture

        def appendLines (self, recHdl, prop, level):
            self.__parseBytes(recHdl)

            recHdl.appendLine(indent(level)+"fNoFillHitTest            : %s"%recHdl.getTrueFalse(self.A))
            recHdl.appendLine(indent(level)+"fillUseRect               : %s"%recHdl.getTrueFalse(self.B))
            recHdl.appendLine(indent(level)+"fillShape                 : %s"%recHdl.getTrueFalse(self.C))
            recHdl.appendLine(indent(level)+"fHitTestFill              : %s"%recHdl.getTrueFalse(self.D))
            recHdl.appendLine(indent(level)+"fFilled                   : %s"%recHdl.getTrueFalse(self.E))
            recHdl.appendLine(indent(level)+"fUseShapeAnchor           : %s"%recHdl.getTrueFalse(self.F))
            recHdl.appendLine(indent(level)+"fRecolorFillAsPicture     : %s"%recHdl.getTrueFalse(self.G))

            recHdl.appendLine(indent(level)+"fUseNoFillHitTest         : %s"%recHdl.getTrueFalse(self.H))
            recHdl.appendLine(indent(level)+"fUsefillUseRect           : %s"%recHdl.getTrueFalse(self.I))
            recHdl.appendLine(indent(level)+"fUsefillShape             : %s"%recHdl.getTrueFalse(self.J))
            recHdl.appendLine(indent(level)+"fUsefHitTestFill          : %s"%recHdl.getTrueFalse(self.K))
            recHdl.appendLine(indent(level)+"fUsefFilled               : %s"%recHdl.getTrueFalse(self.L))
            recHdl.appendLine(indent(level)+"fUsefUseShapeAnchor       : %s"%recHdl.getTrueFalse(self.M))
            recHdl.appendLine(indent(level)+"fUsefRecolorFillAsPicture : %s"%recHdl.getTrueFalse(self.N))

        def dumpXml(self, recHdl, prop):
            self.__parseBytes(recHdl)

            recHdl.appendLine('<fNoFillHitTest value="%s"/>' % self.A)
            recHdl.appendLine('<fillUseRect value="%s"/>' % self.B)
            recHdl.appendLine('<fillShape value="%s"/>' % self.C)
            recHdl.appendLine('<fHitTestFill value="%s"/>' % self.D)
            recHdl.appendLine('<fFilled value="%s"/>' % self.E)
            recHdl.appendLine('<fUseShapeAnchor value="%s"/>' % self.F)
            recHdl.appendLine('<fRecolorFillAsPicture value="%s"/>' % self.G)

            recHdl.appendLine('<fUseNoFillHitTest value="%s"/>' % self.H)
            recHdl.appendLine('<fUsefillUseRect value="%s"/>' % self.I)
            recHdl.appendLine('<fUsefillShape value="%s"/>' % self.J)
            recHdl.appendLine('<fUsefHitTestFill value="%s"/>' % self.K)
            recHdl.appendLine('<fUsefFilled value="%s"/>' % self.L)
            recHdl.appendLine('<fUsefUseShapeAnchor value="%s"/>' % self.M)
            recHdl.appendLine('<fUsefRecolorFillAsPicture value="%s"/>' % self.N)

    class LineColor:

        def appendLines (self, recHdl, prop, level):
            color = ColorRef(prop.value)
            color.appendLine(recHdl, level)

        def dumpXml(self, recHdl, prop):
            recHdl.appendLine('<lineColor>')
            color = ColorRef(prop.value)
            color.dumpXml(recHdl)
            recHdl.appendLine('</lineColor>')

    # Hack, can't inherit from nested class otherwise.
    global UnicodeComplex

    class UnicodeComplex:
        """Base class for properties that have a null-terminated Unicode string
        as a complex property."""

        def __init__(self, name):
            self.name = name
            self.todo = None

        def __parseBytes(self, prop):
            # A null-terminated Unicode string.
            try:
                self.string = prop.extra[0:-2].decode('utf-16')
            except UnicodeDecodeError, reason:
                self.todo = reason
                self.string = prop.extra[0:-2].decode('utf-16', errors="replace")

        def appendLines(self, recHdl, prop, level):
            self.__parseBytes(prop)
            recHdl.appendLine(indent(level)+"%s: %s"%(self.name,self.string))

        def dumpXml(self, recHdl, prop):
            self.__parseBytes(prop)
            if self.todo:
                print '<todo what="UnicodeComplex::dumpXml(): %s"/>' % self.todo
            recHdl.appendLine('<%s value="%s"/>' % (self.name, globals.encodeName(self.string)))

    class GtextUNICODE(UnicodeComplex):

        def __init__(self):
            UnicodeComplex.__init__(self, "gtextUNICODE")

    class GtextFont(UnicodeComplex):

        def __init__(self):
            UnicodeComplex.__init__(self, "gtextFont")

    class WzName(UnicodeComplex):

        def __init__(self):
            UnicodeComplex.__init__(self, "wzName")

    class WzDescription(UnicodeComplex):

        def __init__(self):
            UnicodeComplex.__init__(self, "wzDescription")

    class PibName(UnicodeComplex):

        def __init__(self):
            UnicodeComplex.__init__(self, "pibName")

    class ShadowOffsetX:

        def appendLines(self, recHdl, prop, level):
            recHdl.appendLine(indent(level)+"shadowOffsetX: %s"%prop.value)

        def dumpXml(self, recHdl, prop):
            recHdl.appendLine('<shadowOffsetX value="%s" inTwips="%s"/>' % (prop.value, emu_to_twip(prop.value)))

    class LineWidth:

        def appendLines(self, recHdl, prop, level):
            recHdl.appendLine(indent(level)+"lineWidth: %s"%prop.value)

        def dumpXml(self, recHdl, prop):
            recHdl.appendLine('<lineWidth value="%s" inTwips="%s"/>' % (prop.value, emu_to_twip(prop.value)))

    class MetroBlob:
        """The metroBlob property specifies alternative XML content for a
        shape. This property specifies a binary serialization of an OPC
        container. The package contains an OOXML DrawingML document."""

        def appendLines(self, recHdl, prop, level):
            recHdl.appendLine(indent(level)+"metroBlob: %s"%hexdump(prop.value))

        def dumpXml(self, recHdl, prop):
            recHdl.appendLine('<metroBlob value="%s"/>' % hexdump(prop.extra))

    class GroupShape:

        flagNames = [
            'fPrint',                 # A
            'fHidden',                # B
            'fOneD',                  # C
            'fIsButton',              # D
            'fOnDblClickNotify',      # E
            'fBehindDocument',        # F
            'fEditedWrap',            # G
            'fScriptAnchor',          # H
            'fReallyHidden',          # I
            'fAllowOverlap',          # J
            'fUserDrawn',             # K
            'fHorizRule',             # L
            'fNoshadeHR',             # M
            'fStandardHR',            # N
            'fIsBullet',              # O
            'fLayoutInCell',          # P
            'fUsefPrint',             # Q
            'fUsefHidden',            # R
            'fUsefOneD',              # S
            'fUsefIsButton',          # T
            'fUsefOnDblClickNotify',  # U
            'fUsefBehindDocument',    # V
            'fUsefEditedWrap',        # W
            'fUsefScriptAnchor',      # X
            'fUsefReallyHidden',      # Y
            'fUsefAllowOverlap',      # Z
            'fUsefUserDrawn',         # a
            'fUsefHorizRule',         # b
            'fUsefNoshadeHR',         # c
            'fUsefStandardHR',        # d
            'fUsefIsBullet',          # e
            'fUsefLayoutInCell'       # f
        ]

        def appendLines (self, recHdl, prop, level):
            flag = prop.value
            flagCount = len(FOPT.GroupShape.flagNames)
            recHdl.appendLine(indent(level)+"flag: 0x%8.8X"%flag)
            for i in xrange(0, flagCount):
                bval = (flag & 0x00000001)
                recHdl.appendLine(indent(level)+"%s: %s"%(FOPT.GroupShape.flagNames[i], recHdl.getTrueFalse(bval)))
                flag /= 2

        def dumpXml(self, recHdl, prop):
            flag = prop.value
            flagCount = len(FOPT.GroupShape.flagNames)
            for i in xrange(0, flagCount):
                bval = (flag & 0x00000001)
                recHdl.appendLine('<%s value="%s"/>' % (FOPT.GroupShape.flagNames[i], bval))
                flag /= 2

    class ShapeBooleanProperties:

        # The order of the members is in the opposite order in the spec, but
        # this seems to be the reality.
        memberNames = [
            'fBackground',
            'reserved1',
            'fInitiator',
            'fLockShapeType',
            'fPreferRelativeResize',
            'fOleIcon',
            'fFlipVOverride',
            'fFlipHOverride',
            'fPolicyBarcode',
            'fPolicyLabel',
            'unused1',
            'unused2',
            'unused3',
            'fUsefBackground',
            'unused4',
            'fUsefInitiator',
            'fUsefLockShapeType',
            'fusePreferrelativeResize',
            'fUsefOleIcon',
            'fUsefFlipVOverride',
            'fUsefFlipHOverride',
            'fUsefPolicyBarcode',
            'fUsefPolicyLabel',
            'unused5',
            'unused6',
            'unused7',
            ]

        def __parseBytes(self, buf):
            self.fBackground =                 buf & 0x00000001  # 1st bit
            self.reserved1 =                  (buf & 0x00000002) >> 1 # 2nd bit
            self.fInitiator =                 (buf & 0x00000004) >> 2 # 3rd bit
            self.fLockShapeType =             (buf & 0x00000008) >> 3 # 4th bit
            self.fPreferRelativeResize =      (buf & 0x00000010) >> 4 # 5th bit
            self.fOleIcon =                   (buf & 0x00000020) >> 5 # 6th bit
            self.fFlipVOverride =             (buf & 0x00000040) >> 6 # 7th bit
            self.fFlipHOverride =             (buf & 0x00000080) >> 7 # 8th bit
            self.fPolicyBarcode =             (buf & 0x00000100) >> 8 # 9th bit
            self.fPolicyLabel =               (buf & 0x00000200) >> 9 # 10th bit
            self.unused1 =                    (buf & 0x00000400) >> 10 # 11th bit
            self.unused2 =                    (buf & 0x00000800) >> 11 # 12th bit
            self.unused3 =                    (buf & 0x0000f000) >> 12 # 13..16th bits
            self.fUsefBackground =            (buf & 0x00010000) >> 16 # 17th bit
            self.unused4 =                    (buf & 0x00020000) >> 17 # 18th bit
            self.fUsefInitiator =             (buf & 0x00040000) >> 18 # 19th bit
            self.fUsefLockShapeType =         (buf & 0x00080000) >> 19 # 20th bit
            self.fusePreferrelativeResize =   (buf & 0x00100000) >> 20 # 21th bit
            self.fUsefOleIcon =               (buf & 0x00200000) >> 21 # 22th bit
            self.fUsefFlipVOverride =         (buf & 0x00400000) >> 22 # 23th bit
            self.fUsefFlipHOverride =         (buf & 0x00800000) >> 23 # 24th bit
            self.fUsefPolicyBarcode =         (buf & 0x01000000) >> 24 # 25th bit
            self.fUsefPolicyLabel =           (buf & 0x02000000) >> 25 # 26th bit
            self.unused5 =                    (buf & 0x04000000) >> 26 # 27th bit
            self.unused6 =                    (buf & 0x08000000) >> 27 # 28th bit
            self.unused7 =                    (buf & 0xf0000000) >> 28 # 29..32th bits

        def appendLines (self, recHdl, prop, level):
            self.__parseBytes(prop.value)
            for i in FOPT.ShapeBooleanProperties.memberNames:
                recHdl.appendLine(indent(level)+"%s: %s"%(i, recHdl.getTrueFalse(getattr(self, i))))

        def dumpXml(self, recHdl, prop):
            self.__parseBytes(prop.value)
            for i in FOPT.ShapeBooleanProperties.memberNames:
                recHdl.appendLine('<%s value="%s"/>' % (i, getattr(self, i)))

    class PibFlags:
        """An MSOBLIPFLAGS enumeration value, that specifies how to interpret
        the pibName property."""
        def __parseBytes(self, prop):
            self.pibFlags = globals.getValueOrUnknown(MSOBLIPFLAGS, prop.value, "todo")

        def appendLines (self, recHdl, prop, level):
            recHdl.appendLine(indent(level)+"pibFlags: %s"%prop.value)

        def dumpXml(self, recHdl, prop):
            self.__parseBytes(prop)
            recHdl.appendLine('<pibFlags name="%s" value="%s"/>' % (self.pibFlags, hex(prop.value)))

    propTable = {
        0x00BF: ['Text Boolean Properties', TextBoolean],
        0x00C0: ['gtextUNICODE', GtextUNICODE],
        0x00C5: ['gtextFont', GtextFont],
        0x0181: ['Fill Color', FillColor],
        0x01BF: ['Fill Style Boolean Properties', FillStyle],
        0x01C0: ['Line Color', LineColor],
        0x0303: ['Connector Shape Style (cxstyle)', CXStyle],
        0x0380: ['wzName', WzName],
        0x0381: ['wzDescription', WzDescription],
        0x03BF: ['Group Shape Boolean Properties', GroupShape],
        0x0205: ['X Shadow Offset', ShadowOffsetX],
        0x01CB: ['Line Width', LineWidth],
        0x0186: ['fillBlip'],
        0x01C5: ['lineFillBlip'],
        0x0080: ['lTxid'],
        0x008A: ['hspNext'],
        0x0200: ['shadowType'],
        0x0201: ['shadowColor'],
        0x0207: ['shadowSecondOffsetX'],
        0x023F: ['Shadow Style Boolean Properties'],
        0x01FF: ['Line Style Boolean Properties'],
        0x0304: ['Black-and-white Display Mode'],
        0x033F: ['Shape Boolean Properties', ShapeBooleanProperties],
        0x0081: ['dxTextLeft'],
        0x0082: ['dyTextTop'],
        0x0083: ['dxTextRight'],
        0x0084: ['dyTextBottom'],
        0x0088: ['txflTextFlow'],
        0x0183: ['fillBackColor'],
        0x01C2: ['lineBackColor'],
        0x01CD: ['lineStyle'],
        0x01CE: ['lineDashing'],
        0x0384: ['dxWrapDistLeft'],
        0x0385: ['dyWrapDistTop'],
        0x0386: ['dyWrapDistRight'],
        0x0387: ['dyWrapDistBottom'],
        0x038F: ['posh'],
        0x0390: ['posrelh'],
        0x0391: ['posv'],
        0x0392: ['posrelv'],
        0x0004: ['rotation'],
        0x00C3: ['gtextSize'],
        0x00FF: ['Geometry Text Boolean Properties'],
        0x0182: ['fillOpacity'],
        0x053F: ['Diagram Boolean Properties'],
        0x03A9: ['metroBlob', MetroBlob],
        0x0105: ['pibName', PibName],
        0x0085: ['WrapText'],
        0x0087: ['anchorText'],
        0x00C2: ['gtextAlign'],
        0x0147: ['adjustValue'],
        0x017F: ['Geometry Boolean Properties'],
        0x0180: ['fillType'],
        0x01C1: ['lineOpacity'],
        0x01D6: ['lineJoinStyle'],
        0x01D7: ['lineEndCapStyle'],
        0x0104: ['pib'],
        0x018C: ['fillFocus'],
        0x007F: ['Protection Boolean Properties'],
        0x0106: ['pibFlags', PibFlags],
    }

    class E:
        """single property entry in a property table"""
        def __init__ (self):
            self.ID          = None
            self.flagBid     = False
            self.flagComplex = False
            self.value       = None
            self.extra       = None

    def __init__ (self, strm, name = "shapePrimaryOptions", type = "OfficeArtFOPT"):
        self.properties = []
        self.strm = strm
        self.name = name
        self.type = type

    def __parseBytes(self, rh):
        complexPos = self.strm.pos + (rh.recInstance * 6)
        strm = globals.ByteStream(self.strm.readBytes(rh.recLen))
        for i in xrange(0, rh.recInstance):
            entry = FOPT.E()
            val = strm.readUnsignedInt(2)
            entry.ID          = (val & 0x3FFF)
            entry.flagBid     = (val & 0x4000) # if true, the value is a blip ID.
            entry.flagComplex = (val & 0x8000) # if true, the value stores the size of the extra bytes.
            entry.value = strm.readSignedInt(4)
            if entry.flagComplex:
                if self.strm.pos + entry.value > self.strm.size:
                    break
                entry.extra = self.strm.bytes[complexPos:complexPos+entry.value]
                complexPos += entry.value
            self.properties.append(entry)

    def appendLines (self, recHdl, rh):
        self.__parseBytes(rh)

        recHdl.appendLine("FOPT content (property table):")
        recHdl.appendLine("  property count: %d"%rh.recInstance)
        for i in xrange(0, rh.recInstance):
            recHdl.appendLine("    "+"-"*57)
            prop = self.properties[i]
            if FOPT.propTable.has_key(prop.ID) and len(FOPT.propTable[prop.ID]) > 1:
                # We have a handler for this property.
                # propData is expected to have two elements: name (0) and handler (1).
                propHdl = FOPT.propTable[prop.ID]
                recHdl.appendLine("    property name: %s (0x%4.4X)"%(propHdl[0], prop.ID))
                propHdl[1]().appendLines(recHdl, prop, 2)
            else:
                recHdl.appendLine("    property ID: 0x%4.4X"%prop.ID)
                if prop.flagComplex:
                    recHdl.appendLine("    complex property: %s"%globals.getRawBytes(prop.extra, True, False))
                elif prop.flagBid:
                    recHdl.appendLine("    blip ID: %d"%prop.value)
                else:
                    # regular property value
                    if FOPT.propTable.has_key(prop.ID):
                        recHdl.appendLine("    property name: %s"%FOPT.propTable[prop.ID][0])
                    recHdl.appendLine("    property value: 0x%8.8X"%prop.value)

    def dumpXml(self, recHdl, model, rh):
        self.__parseBytes(rh)

        recHdl.appendLine('<%s type="%s">' % (self.name, self.type))
        recHdl.appendLine('<fopt type="OfficeArtRGFOPTE">')
        for i in xrange(0, rh.recInstance):
            recHdl.appendLine('<rgfopte index="%d">' % i)
            if i < len(self.properties):
                prop = self.properties[i]
                recHdl.appendLine('<opid>')
                recHdl.appendLine('<opid value="0x%4.4X"/>' % prop.ID)
                recHdl.appendLine('<opid fBid="%d"/>' % prop.flagBid)
                recHdl.appendLine('<opid fComplex="%d"/>' % prop.flagComplex)
                recHdl.appendLine('</opid>')
                if FOPT.propTable.has_key(prop.ID) and len(FOPT.propTable[prop.ID]) > 1:
                    # We have a handler for this property.
                    # propData is expected to have two elements: name (0) and handler (1).
                    propHdl = FOPT.propTable[prop.ID]
                    recHdl.appendLine('<op name="%s" value="0x%4.4X">' % (propHdl[0], prop.ID))
                    propHdl[1]().dumpXml(recHdl, prop)
                    recHdl.appendLine('</op>')
                else:
                    if FOPT.propTable.has_key(prop.ID):
                        recHdl.appendLine('<op name="%s" value="0x%8.8X"/>' % (FOPT.propTable[prop.ID][0], prop.value))
                    else:
                        recHdl.appendLine('<op name="todo" value="0x%8.8X"/>' % prop.value)
                    if prop.flagComplex:
                        recHdl.appendLine('<todo what="FOPT: fComplex != 0 unhandled"/>')
            recHdl.appendLine('</rgfopte>')
        recHdl.appendLine('</fopt>')
        recHdl.appendLine('</%s>' % self.name)

class TertiaryFOPT(FOPT):
    def __init__ (self, strm):
        FOPT.__init__(self, strm, "shapeTertiaryOptions", "OfficeArtTertiaryFOPT")

class FRIT:
    def __init__ (self, strm):
        self.lastGroupID = strm.readUnsignedInt(2)
        self.secondLastGroupID = strm.readUnsignedInt(2)

    def appendLines (self, recHdl, rh):
        pass


class FSP:
    def __init__ (self, strm):
        self.spid = strm.readUnsignedInt(4)
        self.flag = strm.readUnsignedInt(4)
        self.groupShape     = (self.flag & 0x0001) != 0
        self.childShape     = (self.flag & 0x0002) != 0
        self.topMostInGroup = (self.flag & 0x0004) != 0
        self.deleted        = (self.flag & 0x0008) != 0
        self.oleObject      = (self.flag & 0x0010) != 0
        self.haveMaster     = (self.flag & 0x0020) != 0
        self.flipHorizontal = (self.flag & 0x0040) != 0
        self.flipVertical   = (self.flag & 0x0080) != 0
        self.isConnector    = (self.flag & 0x0100) != 0
        self.haveAnchor     = (self.flag & 0x0200) != 0
        self.background     = (self.flag & 0x0400) != 0
        self.haveProperties = (self.flag & 0x0800) != 0

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("FSP content (instance of a shape):")
        recHdl.appendLine("  ID of this shape: %d"%self.spid)
        recHdl.appendLineBoolean("  group shape", self.groupShape)
        recHdl.appendLineBoolean("  child shape", self.childShape)
        recHdl.appendLineBoolean("  topmost in group", self.topMostInGroup)
        recHdl.appendLineBoolean("  deleted", self.deleted)
        recHdl.appendLineBoolean("  OLE object shape", self.oleObject)
        recHdl.appendLineBoolean("  have valid master", self.haveMaster)
        recHdl.appendLineBoolean("  horizontally flipped", self.flipHorizontal)
        recHdl.appendLineBoolean("  vertically flipped", self.flipVertical)
        recHdl.appendLineBoolean("  connector shape", self.isConnector)
        recHdl.appendLineBoolean("  have anchor", self.haveAnchor)
        recHdl.appendLineBoolean("  background shape", self.background)
        recHdl.appendLineBoolean("  have shape type property", self.haveProperties)

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<shapeProp type="OfficeArtFSP">')
        recHdl.appendLine('<spid value="%d"/>' % self.spid)
        recHdl.appendLine('<fGroup value="%d"/>' % self.groupShape)
        recHdl.appendLine('<fChild value="%d"/>' % self.childShape)
        recHdl.appendLine('<fPatriarch value="%d"/>' % self.topMostInGroup)
        recHdl.appendLine('<fDeleted value="%d"/>' % self.deleted)
        recHdl.appendLine('<fOleShape value="%d"/>' % self.oleObject)
        recHdl.appendLine('<fHaveMaster value="%d"/>' % self.haveMaster)
        recHdl.appendLine('<fFlipH value="%d"/>' % self.flipHorizontal)
        recHdl.appendLine('<fFlipV value="%d"/>' % self.flipVertical)
        recHdl.appendLine('<fConnector value="%d"/>' % self.isConnector)
        recHdl.appendLine('<fHaveAnchor value="%d"/>' % self.haveAnchor)
        recHdl.appendLine('<fBackground value="%d"/>' % self.background)
        recHdl.appendLine('<fHaveSpt value="%d"/>' % self.haveProperties)
        recHdl.appendLine('</shapeProp>')


class FSPGR:
    def __init__ (self, strm):
        self.left   = strm.readSignedInt(4)
        self.top    = strm.readSignedInt(4)
        self.right  = strm.readSignedInt(4)
        self.bottom = strm.readSignedInt(4)

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("FSPGR content (coordinate system of group shape):")
        recHdl.appendLine("  left boundary: %d"%self.left)
        recHdl.appendLine("  top boundary: %d"%self.top)
        recHdl.appendLine("  right boundary: %d"%self.right)
        recHdl.appendLine("  bottom boundary: %d"%self.bottom)

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<shapeGroup type="OfficeArtFSPGR">')
        recHdl.appendLine('<xLeft value="%d"/>' % self.left)
        recHdl.appendLine('<yTop value="%d"/>' % self.top)
        recHdl.appendLine('<xRight value="%d"/>' % self.right)
        recHdl.appendLine('<yBottom value="%d"/>' % self.bottom)
        recHdl.appendLine('</shapeGroup>')


class FConnectorRule:
    def __init__ (self, strm):
        self.ruleID = strm.readUnsignedInt(4)
        self.spIDA = strm.readUnsignedInt(4)
        self.spIDB = strm.readUnsignedInt(4)
        self.spIDC = strm.readUnsignedInt(4)
        self.conSiteIDA = strm.readUnsignedInt(4)
        self.conSiteIDB = strm.readUnsignedInt(4)

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("FConnectorRule content:")
        recHdl.appendLine("  rule ID: %d"%self.ruleID)
        recHdl.appendLine("  ID of the shape where the connector starts: %d"%self.spIDA)
        recHdl.appendLine("  ID of the shape where the connector ends: %d"%self.spIDB)
        recHdl.appendLine("  ID of the connector shape: %d"%self.spIDB)
        recHdl.appendLine("  ID of the connection site in the begin shape: %d"%self.conSiteIDA)
        recHdl.appendLine("  ID of the connection site in the end shape: %d"%self.conSiteIDB)


class MSOCR:
    def __init__ (self, strm):
        self.red = strm.readUnsignedInt(1)
        self.green = strm.readUnsignedInt(1)
        self.blue = strm.readUnsignedInt(1)
        flag = strm.readUnsignedInt(1)
        self.isSchemeIndex = (flag & 0x08) != 0

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("MSOCR content (color index)")
        if self.isSchemeIndex:
            recHdl.appendLine("  scheme index: %d"%self.red)
        else:
            recHdl.appendLine("  RGB color: (red=%d, green=%d, blue=%d)"%(self.red, self.green, self.blue))

    def dumpXml(self, recHdl, rh):
        recHdl.appendLine('<msocr type="MSOCR">')
        recHdl.appendLine('<red value="%d"/>' % self.red)
        recHdl.appendLine('<green value="%d"/>' % self.green)
        recHdl.appendLine('<blue value="%d"/>' % self.blue)
        recHdl.appendLine('<fSchemeIndex value="%d"/>' % self.isSchemeIndex)
        recHdl.appendLine('</msocr>')

class FClientData:
    def __init__ (self, strm):
        self.data = strm.readUnsignedInt(4)

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("FClientData content")
        recHdl.appendLine("  data: 0x%8.8X"%self.data)

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<clientData type="OfficeArtClientData">')
        recHdl.appendLine('<data value="0x%8.8X"/>' % self.data)
        recHdl.appendLine('</clientData>')

class FClientTextbox:
    def __init__ (self, strm):
        self.data = strm.readUnsignedInt(4)

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("FClientTextbox content")
        recHdl.appendLine("  data: 0x%8.8X"%self.data)

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<clientTextbox type="OfficeArtClientTextbox">')
        recHdl.appendLine('<data value="0x%8.8X"/>' % self.data)
        recHdl.appendLine('</clientTextbox>')

class BStoreContainerFileBlock:
    def __init__(self, parent):
        self.strm = parent.strm
        self.parent = parent

    def dumpXml(self, recHdl, model):
        rh = RecordHeader(self.strm)
        rh.dumpXml(recHdl)
        if rh.recType in recData:
            child = recData[rh.recType](self.strm)
            child.dumpXml(self.strm, model, rh)
        else:
            recHdl.appendLine('<todo what="BStoreContainerFileBlock: recType = %s unhandled (size: %d bytes)"/>' % (hex(rh.recType), rh.recLen))
            self.strm.pos += rh.recLen

class BStoreContainer:
    def __init__ (self, strm):
        self.strm = strm

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("BStoreContainer content")

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<bStoreContainer type="OfficeArtBStoreContainer">')
        for i in xrange(rh.recInstance):
            bStoreContainerFileBlock = BStoreContainerFileBlock(self)
            bStoreContainerFileBlock.dumpXml(recHdl, model)
        recHdl.appendLine('</bStoreContainer>')

class SplitMenuColorContainer:
    def __init__ (self, strm):
        self.smca = []
        # this container contains 4 MSOCR records.
        for i in xrange(0, 4):
            msocr = MSOCR(strm)
            self.smca.append(msocr)

    def appendLines (self, recHdl, rh):
        for msocr in self.smca:
            msocr.appendLines(recHdl, rh)

    def dumpXml(self, recHdl, model, rh):
        recHdl.appendLine('<splitColors type="OfficeArtSplitMenuColorContainer">')
        for i, smca in enumerate(self.smca):
            recHdl.appendLine('<smca index="%d">' % i)
            smca.dumpXml(recHdl, rh)
            recHdl.appendLine('</smca>')
        recHdl.appendLine('</splitColors>')

MSOBLIPTYPE = {
        0x00: 'msoblipERROR',
        0x01: 'msoblipUNKNOWN',
        0x02: 'msoblipEMF',
        0x03: 'msoblipWMF',
        0x04: 'msoblipPICT',
        0x05: 'msoblipJPEG',
        0x06: 'msoblipPNG',
        0x07: 'msoblipDIB',
        0x11: 'msoblipTIFF',
        0x12: 'msoblipCMYKJPEG',
        }

MSOBLIPFLAGS = {
        0x00000000: 'msoblipflagComment',
        0x00000001: 'msoblipflagFile',
        0x00000002: 'msoblipflagURL',
        0x00000004: 'msoblipflagDoNotSave',
        0x00000008: 'msoblipflagLinkToFile',
        }

class FBSE:
    """2.2.32 The OfficeArtFBSE record specifies a File BLIP Store Entry (FBSE)
    that contains information about the BLIP."""
    def __init__(self, strm):
        self.strm = strm
        self.posOrig = strm.pos
        self.btWin32 = strm.readUnsignedInt(1)
        self.btMacOS = strm.readUnsignedInt(1)
        self.rgbUid = strm.readBytes(16)
        self.tag = strm.readUnsignedInt(2)
        self.size = strm.readUnsignedInt(4)
        self.cRef = strm.readUnsignedInt(4)
        self.foDelay = strm.readUnsignedInt(4)
        self.unused1 = strm.readUnsignedInt(1)
        self.cbName = strm.readUnsignedInt(1)
        self.unused2 = strm.readUnsignedInt(1)
        self.unused3 = strm.readUnsignedInt(1)

    def appendLines (self, recHdl, rh):
        pass

    def dumpXml(self, recHdl, model, rh):

        def dumpChild(strm):
            rh = RecordHeader(strm)
            rh.dumpXml(recHdl)
            if rh.recType in recData:
                child = recData[rh.recType](strm)
                child.dumpXml(strm, model, rh)
            else:
                recHdl.appendLine('<todo what="FBSE::dumpXml(): recType = %s unhandled (size: %d bytes)"/>' % (hex(rh.recType), rh.recLen))
                strm.pos += rh.recLen

        recHdl.appendLine('<fbse>')
        recHdl.appendLine('<btWin32 value="%s" name="%s"/>' % (self.btWin32, globals.getValueOrUnknown(MSOBLIPTYPE, self.btWin32, "todo")))
        recHdl.appendLine('<btMacOS value="%s" name="%s"/>' % (self.btMacOS, globals.getValueOrUnknown(MSOBLIPTYPE, self.btMacOS, "todo")))
        recHdl.appendLine('<rgbUid value="%s"/>' % hexdump(self.rgbUid))
        recHdl.appendLine('<tag value="%s"/>' % self.tag)
        recHdl.appendLine('<size value="%s"/>' % self.size)
        recHdl.appendLine('<cRef value="%s"/>' % self.cRef)
        recHdl.appendLine('<foDelay value="%s"/>' % hex(self.foDelay))
        recHdl.appendLine('<unused1 value="%s"/>' % self.unused1)
        recHdl.appendLine('<cbName value="%s"/>' % self.cbName)
        recHdl.appendLine('<unused2 value="%s"/>' % self.unused2)
        recHdl.appendLine('<unused3 value="%s"/>' % self.unused3)
        if self.cbName != 0:
            recHdl.appendLine('<todo what="FBSE::dumpXml(): cbName != 0"/>')
        if self.strm.pos < self.posOrig + rh.recLen:
            dumpChild(self.strm)
        elif self.foDelay != 0xffffffff and self.cRef > 0:
            # Picture is in the delay stream, try to dump it.
            if model.hostApp == globals.ModelBase.HostAppType.Word:
                posOrig = model.delayStream.pos
                model.delayStream.pos = self.foDelay
                dumpChild(model.delayStream)
                model.delayStream.pos = posOrig
        recHdl.appendLine('</fbse>')

class FClientAnchorSheet:
    """Excel-specific anchor data (OfficeArtClientAnchorSheet)"""

    def __init__ (self, strm):
        # dx is 1/1024th of the underlying cell's width.
        # dy is 1/1024th of the underlying cell's height.
        flag = strm.readUnsignedInt(2)
        self.moveWithCells   = (flag & 0x0001) != 0
        self.resizeWithCells = (flag & 0x0002 != 0)
        self.col1 = strm.readUnsignedInt(2)
        self.dx1 = strm.readUnsignedInt(2)
        self.row1 = strm.readUnsignedInt(2)
        self.dy1 = strm.readUnsignedInt(2)
        self.col2 = strm.readUnsignedInt(2)
        self.dx2 = strm.readUnsignedInt(2)
        self.row2 = strm.readUnsignedInt(2)
        self.dy2 = strm.readUnsignedInt(2)

    def appendLines (self, recHdl, rh):
        recHdl.appendLine("Client anchor (Excel):")
        recHdl.appendLine("  cols: %d-%d   rows: %d-%d"%(self.col1, self.col2, self.row1, self.row2))
        recHdl.appendLine("  dX1: %d  dY1: %d"%(self.dx1, self.dy1))
        recHdl.appendLine("  dX2: %d  dY2: %d"%(self.dx2, self.dy2))
        recHdl.appendLineBoolean("  move with cells", self.moveWithCells)
        recHdl.appendLineBoolean("  resize with cells", self.resizeWithCells)

    def fillModel (self, model, sheet):
        obj = xlsmodel.Shape(self.col1, self.row1, self.dx1, self.dy1, self.col2, self.row2, self.dx2, self.dy2)
        sheet.addShape(obj)

class OfficeArtClientAnchor:
    """Word-specific anchor data."""

    def __init__ (self, strm):
        self.clientanchor = strm.readSignedInt(4)

    def dumpXml(self, recHdl):
        recHdl.appendLine('<officeArtClientAnchor type="OfficeArtClientAnchor">')
        recHdl.appendLine('<clientanchor value="0x%4.4X"/>' % self.clientanchor)
        recHdl.appendLine('</officeArtClientAnchor>')

# ----------------------------------------------------------------------------

class MSODrawHandler(globals.ByteStream):

    def __init__ (self, bytes, parent, name = None, type = None):
        """The 'parent' instance must have appendLine() method that takes one string argument.
           The optional parameters are used by dumpXml() only."""

        globals.ByteStream.__init__(self, bytes)
        self.parent = parent
        if name and type:
            self.name = name
            self.type = type
            self.pos = parent.pos

    def parseBytes (self):
        while not self.isEndOfRecord():
            self.parent.appendLine(headerLine())
            rh = RecordHeader(self)
            rh.appendLines(self.parent, 0)
            # if rh.recType == Type.dgContainer:
            if rh.recVer == 0xF:
                # container
                continue

            self.parent.appendLine(headerLine())
            if recData.has_key(rh.recType):
                obj = recData[rh.recType](self)
                obj.appendLines(self.parent, rh)
            else:
                # unknown object
                bytes = self.readBytes(rh.recLen)
                self.parent.appendLine(globals.getRawBytes(bytes, True, False))

    def fillModel (self, model):
        sheet = model.getCurrentSheet()
        while not self.isEndOfRecord():
            rh = RecordHeader(self)
            if rh.recVer == 0xF:
                # container
                continue

            if rh.recType == RecordHeader.Type.FClientAnchor and \
                model.hostApp == globals.ModelBase.HostAppType.Excel:
                obj = FClientAnchorSheet(self)
                obj.fillModel(model, sheet)
            else:
                # unknown object
                bytes = self.readBytes(rh.recLen)

    def dumpXml (self, recHdl, model, rh = None):
        recHdl.appendLine('<%s type="%s">' % (self.name, self.type))
        if rh:
            self.rh = rh
        else:
            self.rh = RecordHeader(self)
            self.rh.dumpXml(self)
        base = self.pos
        while (self.rh.recLen - (self.pos - base)) > 0:
            rh = RecordHeader(self)
            rh.dumpXml(self)
            saved = self.pos
            if rh.recType == RecordHeader.Type.FClientAnchor and model.hostApp == globals.ModelBase.HostAppType.Word:
                child = OfficeArtClientAnchor(self)
                child.dumpXml(self)
            elif rh.recType in recData:
                child = recData[rh.recType](self)
                child.dumpXml(self, model, rh)
            else:
                recHdl.appendLine('<todo what="%s: recType = %s unhandled (size: %d bytes)"/>' % (self.type, hex(rh.recType), rh.recLen))
            self.pos = saved + rh.recLen
        recHdl.appendLine('</%s>' % self.name)
        self.parent.pos = self.pos

    def appendLine(self, line):
        self.parent.appendLine(line)


class DggContainer(MSODrawHandler):
    """The OfficeArtDggContainer record type specifies the container for all the OfficeArt file records that contain document-wide data."""
    def __init__(self, officeArtContent, name):
        MSODrawHandler.__init__(self, officeArtContent.bytes, officeArtContent, name, "OfficeArtDggContainer")


class DgContainer(MSODrawHandler):
    """The OfficeArtDgContainer record specifies the container for all the file records for the objects in a drawing."""
    def __init__(self, officeArtContent, name):
        MSODrawHandler.__init__(self, officeArtContent.bytes, officeArtContent, name, "OfficeArtDgContainer")

class InlineSpContainer:
    """The OfficeArtInlineSpContainer record specifies a container for inline shapes."""
    def __init__(self, officeArtContent, size):
        self.strm = officeArtContent
        self.size = size

    def dumpXml (self, recHdl, model):
        recHdl.appendLine('<inlineSpContainer>')
        pos = self.strm.pos
        shape = SpContainer(self.strm)
        shape.dumpXml(recHdl, model)
        while self.size > self.strm.pos - pos:
            bStoreContainerFileBlock = BStoreContainerFileBlock(self)
            bStoreContainerFileBlock.dumpXml(recHdl, model)
        recHdl.appendLine('</inlineSpContainer>')

class SpContainer(MSODrawHandler):
    """The OfficeArtSpContainer record specifies a shape container."""
    def __init__(self, parent):
        MSODrawHandler.__init__(self, parent.bytes, parent, "shape", "OfficeArtSpContainer")


class SpgrContainer(MSODrawHandler):
    """The OfficeArtSpgrContainer record specifies a container for groups of shapes."""
    def __init__(self, officeArtDgContainer):
        MSODrawHandler.__init__(self, officeArtDgContainer.bytes, officeArtDgContainer, "groupShape", "OfficeArtSpgrContainer")


recData = {
    RecordHeader.Type.spgrContainer: SpgrContainer,
    RecordHeader.Type.spContainer: SpContainer,
    RecordHeader.Type.FDG: FDG,
    RecordHeader.Type.FSPGR: FSPGR,
    RecordHeader.Type.FSP: FSP,
    RecordHeader.Type.FOPT: FOPT,
    RecordHeader.Type.FDGGBlock: FDGGBlock,
    RecordHeader.Type.FConnectorRule: FConnectorRule,
    RecordHeader.Type.FDGSL: FDGSL,
    RecordHeader.Type.BlipPNG: BlipPNG,
    RecordHeader.Type.BlipEMF: BlipEMF,
    RecordHeader.Type.FClientAnchor: FClientAnchorSheet,
    RecordHeader.Type.FClientData: FClientData,
    RecordHeader.Type.FClientTextbox: FClientTextbox,
    RecordHeader.Type.SplitMenuColorContainer: SplitMenuColorContainer,
    RecordHeader.Type.TertiaryFOPT: TertiaryFOPT,
    RecordHeader.Type.BStoreContainer: BStoreContainer,
    RecordHeader.Type.FBSE: FBSE,
}

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

#!/usr/bin/env python2
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import struct
import locale
import globals
from docdirstream import DOCDirStream
import docsprm
import msodraw


def getWordModel(mainStream):
    model = globals.ModelBase(globals.ModelBase.HostAppType.Word)
    model.delayStream = mainStream
    return model


class FcCompressed(DOCDirStream):
    """The FcCompressed structure specifies the location of text in the WordDocument Stream."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

        buf = self.readuInt32()
        self.fc = buf & ((2 ** 32 - 1) >> 2)  # bits 0..29
        self.fCompressed = self.getBit(buf, 30)
        self.r1 = self.getBit(buf, 31)

    def dump(self):
        print '<fcCompressed type="FcCompressed" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("fc", self.fc)
        self.printAndSet("fCompressed", self.fCompressed)
        self.printAndSet("r1", self.r1)
        print '</fcCompressed>'


class Pcd(DOCDirStream):
    """The Pcd structure specifies the location of text in the WordDocument Stream and additional properties for this text."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

        buf = self.readuInt16()
        self.fNoParaLast = self.getBit(buf, 0)
        self.fR1 = self.getBit(buf, 1)
        self.fDirty = self.getBit(buf, 2)
        self.fR2 = buf & (2 ** 13 - 1)
        self.fc = FcCompressed(self.bytes, self.mainStream, self.pos, 4)
        self.pos += 4

    def dump(self):
        print '<pcd type="Pcd" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("fNoParaLast", self.fNoParaLast)
        self.printAndSet("fR1", self.fR1)
        self.printAndSet("fDirty", self.fDirty)
        self.printAndSet("fR2", self.fR2)
        self.fc.dump()
        print '</pcd>'


class PLC:
    """The PLC structure is an array of character positions followed by an array of data elements."""
    def __init__(self, totalSize, structSize):
        self.totalSize = totalSize
        self.structSize = structSize

    def getElements(self):
        return (self.totalSize - 4) / (4 + self.structSize)  # defined by 2.2.2

    def getOffset(self, pos, i):
        return self.getPLCOffset(pos, self.getElements(), self.structSize, i)

    @staticmethod
    def getPLCOffset(pos, elements, structSize, i):
        return pos + (4 * (elements + 1)) + (structSize * i)


class BKC(DOCDirStream):
    """The BKC structure contains information about how a bookmark interacts with tables."""
    def __init__(self, bkc):
        self.bkc = bkc

    def dump(self):
        print '<bkc type="BKC">'
        self.printAndSet("itcFirst", self.bkc & 0x007f)  # 1..7th bits
        self.printAndSet("fPub", self.getBit(self.bkc, 8))
        self.printAndSet("itcLim", (self.bkc & 0x3f00) >> 8)  # 9..14th bits
        self.printAndSet("fNative", self.getBit(self.bkc, 15))
        self.printAndSet("fCol", self.getBit(self.bkc, 16))
        print '</bkc>'


class FBKF(DOCDirStream):
    """The FBKF structure contains information about a bookmark."""
    def __init__(self, plcfAtnBkf, offset):
        DOCDirStream.__init__(self, plcfAtnBkf.bytes)
        self.pos = offset

    def dump(self):
        print '<aFBKF type="FBKF" offset="%d">' % self.pos
        self.printAndSet("ibkl", self.readuInt16())
        BKC(self.readuInt16()).dump()
        print '</aFBKF>'


class PlcfBkf(DOCDirStream, PLC):
    """A PLCFBKF is a PLC whose data elements are FBKF structures."""
    def __init__(self, mainStream, offset, size):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, size, 4)  # 4 is defined by 2.8.10
        self.pos = offset
        self.size = size
        self.aCP = []
        self.aFBKF = []

    def dump(self):
        print '<plcfBkf type="PlcfBkf" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        for i in range(self.getElements()):
            # aCp
            start = self.getuInt32(pos=pos)
            self.aCP.append(start)
            print '<aCP index="%d" bookmarkStart="%d">' % (i, start)
            pos += 4

            # aFBKF
            aFBKF = FBKF(self, self.getOffset(self.pos, i))
            aFBKF.dump()
            self.aFBKF.append(aFBKF)
            print '</aCP>'
        print '</plcfBkf>'


class Fldch(DOCDirStream):
    """The fldch structure determines the type of the field character."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent

    def dump(self):
        print '<fldch type="fldch" offset="%d" size="1 byte">' % self.pos
        buf = self.readuInt8()
        self.printAndSet("ch", buf & 0x1f)  # 1..5th bits
        self.printAndSet("reserved", (buf & 0xe0) >> 5)  # 6..8th bits
        print '</fldch>'
        self.parent.pos = self.pos


class Fld(DOCDirStream):
    """The Fld structure specifies a field character."""
    def __init__(self, parent, offset):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = offset

    def dump(self):
        print '<fld type="FLD" offset="%d" size="2 bytes">' % self.pos
        self.fldch = Fldch(self)
        self.fldch.dump()
        self.printAndSet("grffld", self.readuInt8())  # TODO parse flt and grffldEnd
        print '</fld>'


class PlcFld(DOCDirStream, PLC):
    """The Plcfld structure specifies the location of fields in the document."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, mainStream.lcbPlcfFldMom, 2)  # 2 is defined by 2.8.25
        self.pos = mainStream.fcPlcfFldMom
        self.size = mainStream.lcbPlcfFldMom

    def dump(self):
        print '<plcFld type="PlcFld" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        aFlds = []
        for i in range(self.getElements()):
            # aCp
            value = self.getuInt32(pos=pos)
            print '<aCP index="%d" value="%d">' % (i, value)
            pos += 4

            # aFld
            aFld = Fld(self, self.getOffset(self.pos, i))
            aFld.dump()

            # This is a separator and the previous was a start: display the field instructions.
            if aFld.fldch.ch == 0x14 and aFlds[-1][1].fldch.ch == 0x13:
                print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(aFlds[-1][0] + 1, value))
            # This is an end and the previous was a separator: display the field result.
            elif aFld.fldch.ch == 0x15 and aFlds[-1][1].fldch.ch == 0x14:
                print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(aFlds[-1][0] + 1, value))
            aFlds.append((value, aFld))
            print '</aCP>'
        print '</plcFld>'


class PlcfBkl(DOCDirStream, PLC):
    """The Plcfbkl structure is a PLC that contains only CPs and no additional data."""
    def __init__(self, mainStream, offset, size, start):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, size, 0)  # 0 is defined by 2.8.12
        self.pos = offset
        self.size = size
        self.start = start

    def dump(self):
        print '<plcfBkl type="PlcfBkl" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        for i in range(self.getElements()):
            # aCp
            end = self.getuInt32(pos=pos)
            print '<aCP index="%d" bookmarkEnd="%d">' % (i, end)
            start = self.start.aCP[self.start.aFBKF[i].ibkl]
            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(start, end))
            pos += 4
            print '</aCP>'
        print '</plcfBkl>'


class PlcPcd(DOCDirStream, PLC):
    """The PlcPcd structure is a PLC whose data elements are Pcds (8 bytes each)."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        PLC.__init__(self, size, 8)  # 8 is defined by 2.8.35
        self.pos = offset
        self.size = size
        self.aCp = []
        self.aPcd = []
        self.ranges = []

        pos = self.pos
        for i in range(self.getElements()):
            # aCp
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            self.ranges.append((start, end))
            self.aCp.append(start)
            pos += 4

            # aPcd
            aPcd = Pcd(self.bytes, self.mainStream, self.getOffset(self.pos, i), 8)
            self.aPcd.append(aPcd)

    def dump(self):
        print '<plcPcd type="PlcPcd" offset="%d" size="%d bytes">' % (self.pos, self.size)
        for i in range(self.getElements()):
            start, end = self.ranges[i]
            print '<aCP index="%d" start="%d" end="%d">' % (i, start, end)
            self.aPcd[i].dump()
            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(start, end))
            print '</aCP>'
        print '</plcPcd>'


class Sepx(DOCDirStream):
    """The Sepx structure specifies an array of Prl structures and the size of the array."""
    def __init__(self, sed):
        DOCDirStream.__init__(self, sed.plcfSed.mainStream.bytes)
        self.pos = sed.fcSepx

    def dump(self):
        print '<sepx type="Sepx" offset="%d">' % self.pos
        self.printAndSet("cb", self.readInt16())
        pos = self.pos
        while (self.cb - (pos - self.pos)) > 0:
            prl = Prl(self, pos)
            prl.dump()
            pos += prl.getSize()
        print '</sepx>'


class Sed(DOCDirStream):
    """The Sed structure specifies the location of the section properties."""
    size = 12  # defined by 2.8.26

    def __init__(self, plcfSed, offset):
        DOCDirStream.__init__(self, plcfSed.bytes)
        self.pos = offset
        self.plcfSed = plcfSed

    def dump(self):
        print '<aSed type="Sed" offset="%d" size="%d bytes">' % (self.pos, Sed.size)
        self.printAndSet("fn", self.readuInt16())
        self.printAndSet("fcSepx", self.readuInt32())
        if self.fcSepx != 0xffffffff:
            Sepx(self).dump()
        self.printAndSet("fnMpr", self.readuInt16())
        self.printAndSet("fcMpr", self.readuInt32())
        print '</aSed>'


class PlcfSed(DOCDirStream, PLC):
    """The PlcfSed structure is a PLC structure where the data elements are Sed structures."""
    def __init__(self, mainStream, offset, size):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, size, Sed.size)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<plcfSed type="PlcfSed" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        for i in range(self.getElements()):
            # aCp
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aCP index="%d" start="%d" end="%d">' % (i, start, end)
            pos += 4

            # aSed
            aSed = Sed(self, self.getOffset(self.pos, i))
            aSed.dump()

            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(start, end))
            print '</aCP>'
        print '</plcfSed>'


class Tcg(DOCDirStream):
    """The Tcg structure specifies command-related customizations."""
    def __init__(self, mainStream, offset, size):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<tcg type="Tcg" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("nTcgVer", self.readuInt8())
        self.printAndSet("chTerminator", self.readuInt8())
        if self.chTerminator != 0x40:
            print '<todo what="Tcg: chTerminator != 0x40"/>'
        print '</tcg>'


class Sty(DOCDirStream):
    """The Sty structure specifies the type of the selection that was made."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent

    def dump(self):
        value = self.readuInt16()
        styMap = {
            0x0000: "styNil",
            0x0001: "styChar",
            0x0002: "styWord",
            0x0003: "stySent",
            0x0004: "styPara",
            0x0005: "styLine",
            0x000C: "styCol",
            0x000D: "styRow",
            0x000E: "styColAll",
            0x000F: "styWholeTable",
            0x001B: "styPrefix",
        }
        print '<sty name="%s" value="%s"/>' % (styMap[value], hex(value))
        self.parent.pos = self.pos


class Selsf(DOCDirStream):
    size = 36  # defined by 2.9.241
    """The Selsf structure specifies the last selection that was made to the document."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes)
        self.pos = mainStream.fcWss
        self.size = mainStream.lcbWss
        self.mainStream = mainStream

    def dump(self):
        print '<selsf type="Selsf" offset="%d" size="%d bytes">' % (self.pos, self.size)

        buf = self.readuInt16()
        self.printAndSet("fRightward", self.getBit(buf, 0))
        self.printAndSet("unused1", self.getBit(buf, 1))
        self.printAndSet("fWithinCell", self.getBit(buf, 2))
        self.printAndSet("fTableAnchor", self.getBit(buf, 3))
        self.printAndSet("fTableSelNonShrink", self.getBit(buf, 4))
        self.printAndSet("unused2", self.getBit(buf, 5))
        self.printAndSet("fDiscontiguous", self.getBit(buf, 6))
        self.printAndSet("fPrefix", self.getBit(buf, 7))
        self.printAndSet("fShape", self.getBit(buf, 8))
        self.printAndSet("fFrame", self.getBit(buf, 9))
        self.printAndSet("fColumn", self.getBit(buf, 10))
        self.printAndSet("fTable", self.getBit(buf, 11))
        self.printAndSet("fGraphics", self.getBit(buf, 12))
        self.printAndSet("fBlock", self.getBit(buf, 13))
        self.printAndSet("unused3", self.getBit(buf, 14))
        self.printAndSet("fIns", self.getBit(buf, 15))

        buf = self.readuInt8()
        self.printAndSet("fForward", buf & 0x7f)  # 1..7th bits
        self.printAndSet("fPrefixW2007", self.getBit(buf, 7))

        self.printAndSet("fInsEnd", self.readuInt8())
        self.printAndSet("cpFirst", self.readuInt32())
        self.printAndSet("cpLim", self.readuInt32())
        self.printAndSet("unused4", self.readuInt32())
        self.printAndSet("blktblSel", self.readuInt32())
        self.printAndSet("cpAnchor", self.readuInt32())
        Sty(self).dump()
        self.printAndSet("unused5", self.readuInt16())
        self.printAndSet("cpAnchorShrink", self.readuInt32())
        self.printAndSet("xaTableLeft", self.readInt16())
        self.printAndSet("xaTableRight", self.readInt16())
        assert self.pos == self.mainStream.fcWss + Selsf.size
        print '</selsf>'


class COLORREF(DOCDirStream):
    """The COLORREF structure specifies a color in terms of its red, green, and blue components."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.red = self.readuInt8()
        self.green = self.readuInt8()
        self.blue = self.readuInt8()
        self.fAuto = self.readuInt8()
        parent.pos = self.pos

    def dump(self, name):
        print '<%s type="COLORREF">' % name
        self.printAndSet("red", self.red)
        self.printAndSet("green", self.green)
        self.printAndSet("blue", self.blue)
        self.printAndSet("fAuto", self.fAuto)
        print '</%s>' % name


class BRC(DOCDirStream):
    """The Brc structure specifies a border."""
    def __init__(self, parent, name="brc"):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent
        self.name = name
        self.posOrig = self.pos
        self.cv = COLORREF(self)
        self.dptLineWidth = self.readuInt8()
        self.brcType = self.readuInt8()
        buf = self.readuInt16()
        self.dptSpace = buf & 0x1f  # 1..5th bits
        self.fShadow = self.getBit(buf, 5)
        self.fFrame = self.getBit(buf, 6)
        self.fReserved = (buf & 0xff80) >> 7  # 8..16th bits

    def dump(self):
        print '<%s type="BRC" offset="%d">' % (self.name, self.posOrig)
        self.cv.dump("cv")
        self.printAndSet("dptLineWidth", self.dptLineWidth)
        self.printAndSet("brcType", self.brcType, dict=BrcType)
        self.printAndSet("dptSpace", self.dptSpace)
        self.printAndSet("fShadow", self.fShadow)
        self.printAndSet("fFrame", self.fFrame)
        self.printAndSet("fReserved", self.fReserved)
        print '</%s>' % self.name
        self.parent.pos = self.pos


class PChgTabsDel(DOCDirStream):
    """The PChgTabsDel structure specifies the locations at which custom tab stops are ignored."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos

    def dump(self):
        print '<pchgTabsDel type="PChgTabsDel" offset="%d">' % self.pos
        self.printAndSet("cTabs", self.readuInt8())
        if self.cTabs != 0:
            print '<todo what="PChgTabsDel::dump() cTabs is non-zero"/>'
        print '</pchgTabsDel>'
        self.parent.pos = self.pos


class PChgTabsDelClose(DOCDirStream):
    """The PChgTabsDelClose structure specifies the locations at which custom tab stops are ignored."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos

    def dump(self):
        print '<pchgTabsDelClose type="PChgTabsDelClose" offset="%d">' % self.pos
        self.printAndSet("cTabs", self.readuInt8())
        if self.cTabs != 0:
            print '<todo what="PChgTabsDelClose::dump() cTabs is non-zero"/>'
        print '</pchgTabsDelClose>'
        self.parent.pos = self.pos


class PChgTabsAdd(DOCDirStream):
    """The PChgTabsAdd structure specifies the locations and properties of custom tab stops."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos

    def dump(self):
        print '<pchgTabsAdd type="PChgTabsAdd" offset="%d">' % self.pos
        self.printAndSet("cTabs", self.readuInt8())
        for i in range(self.cTabs):
            print '<rgdxaDel index="%d" value="%d"/>' % (i, self.readuInt16())
        print '</pchgTabsAdd>'
        self.parent.pos = self.pos


class PChgTabsPapxOperand(DOCDirStream):
    """The PChgTabsPapxOperand structure is used by sprmPChgTabsPapx to specify custom tab stops to be added or ignored."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<pchgTabsPapxOperand type="PChgTabsPapxOperand" offset="%d">' % self.pos
        self.printAndSet("cb", self.readuInt8())
        PChgTabsDel(self).dump()
        PChgTabsAdd(self).dump()
        print '</pchgTabsPapxOperand>'


class PChgTabsOperand(DOCDirStream):
    """The PChgTabsOperand structure is used by sprmPChgTabs to specify a list
    of custom tab stops to add and another list of custom tab stops to
    ignore."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<pchgTabsOperand type="PChgTabsOperand" offset="%d">' % self.pos
        self.printAndSet("cb", self.readuInt8())
        PChgTabsDelClose(self).dump()
        PChgTabsAdd(self).dump()
        print '</pchgTabsOperand>'

# The Ico structure specifies an entry in the color palette that is listed in the following table.
Ico = {
    0x00: "Red: 0x00, Green: 0x00, Blue: 0x00, fAuto: 0xFF",
    0x01: "Red: 0x00, Green: 0x00, Blue: 0x00, fAuto: 0x00",
    0x02: "Red: 0x00, Green: 0x00, Blue: 0xFF, fAuto: 0x00",
    0x03: "Red: 0x00, Green: 0xFF, Blue: 0xFF, fAuto: 0x00",
    0x04: "Red: 0x00, Green: 0xFF, Blue: 0x00, fAuto: 0x00",
    0x05: "Red: 0xFF, Green: 0x00, Blue: 0xFF, fAuto: 0x00",
    0x06: "Red: 0xFF, Green: 0x00, Blue: 0x00, fAuto: 0x00",
    0x07: "Red: 0xFF, Green: 0xFF, Blue: 0x00, fAuto: 0x00",
    0x08: "Red: 0xFF, Green: 0xFF, Blue: 0xFF, fAuto: 0x00",
    0x09: "Red: 0x00, Green: 0x00, Blue: 0x80, fAuto: 0x00",
    0x0A: "Red: 0x00, Green: 0x80, Blue: 0x80, fAuto: 0x00",
    0x0B: "Red: 0x00, Green: 0x80, Blue: 0x00, fAuto: 0x00",
    0x0C: "Red: 0x80, Green: 0x00, Blue: 0x80, fAuto: 0x00",
    0x0D: "Red: 0x80, Green: 0x00, Blue: 0x80, fAuto: 0x00",
    0x0E: "Red: 0x80, Green: 0x80, Blue: 0x00, fAuto: 0x00",
    0x0F: "Red: 0x80, Green: 0x80, Blue: 0x80, fAuto: 0x00",
    0x10: "Red: 0xC0, Green: 0xC0, Blue: 0xC0, fAuto: 0x00",
}

# The Ipat enumeration is an index to a shading pattern.
Ipat = {
    0x0000: "ipatAuto",
    0x0001: "ipatSolid",
    0x0002: "ipatPct5",
    0x0003: "ipatPct10",
    0x0004: "ipatPct20",
    0x0005: "ipatPct25",
    0x0006: "ipatPct30",
    0x0007: "ipatPct40",
    0x0008: "ipatPct50",
    0x0009: "ipatPct60",
    0x000A: "ipatPct70",
    0x000B: "ipatPct75",
    0x000C: "ipatPct80",
    0x000D: "ipatPct90",
    0x000E: "ipatDkHorizontal",
    0x000F: "ipatDkVertical",
    0x0010: "ipatDkForeDiag",
    0x0011: "ipatDkBackDiag",
    0x0012: "ipatDkCross",
    0x0013: "ipatDkDiagCross",
    0x0014: "ipatHorizontal",
    0x0015: "ipatVertical",
    0x0016: "ipatForeDiag",
    0x0017: "ipatBackDiag",
    0x0018: "ipatCross",
    0x0019: "ipatDiagCross",
    0x0023: "ipatPctNew2",
    0x0024: "ipatPctNew7",
    0x0025: "ipatPctNew12",
    0x0026: "ipatPctNew15",
    0x0027: "ipatPctNew17",
    0x0028: "ipatPctNew22",
    0x0029: "ipatPctNew27",
    0x002A: "ipatPctNew32",
    0x002B: "ipatPctNew35",
    0x002C: "ipatPctNew37",
    0x002D: "ipatPctNew42",
    0x002E: "ipatPctNew45",
    0x002F: "ipatPctNew47",
    0x0030: "ipatPctNew52",
    0x0031: "ipatPctNew55",
    0x0032: "ipatPctNew57",
    0x0033: "ipatPctNew62",
    0x0034: "ipatPctNew65",
    0x0035: "ipatPctNew67",
    0x0036: "ipatPctNew72",
    0x0037: "ipatPctNew77",
    0x0038: "ipatPctNew82",
    0x0039: "ipatPctNew85",
    0x003A: "ipatPctNew87",
    0x003B: "ipatPctNew92",
    0x003C: "ipatPctNew95",
    0x003D: "ipatPctNew97",
    0xFFFF: "ipatNil"
}


class Shd80(DOCDirStream):
    """The Shd80 structure specifies the colors and pattern that are used for background shading."""
    size = 2  # in bytes, see 2.9.245

    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent

    def dump(self):
        print '<shd80 type="Shd80" offset="%d">' % self.pos
        buf = self.readuInt16()
        self.printAndSet("icoFore", buf & 0x001f, dict=Ico)  # 1..5th bits
        self.printAndSet("icoBack", (buf & 0x03e0) >> 5, dict=Ico)  # 6..10th bits
        self.printAndSet("ipat", (buf & 0xfc00) >> 10, dict=Ipat)  # 11.16th bits
        print '</shd80>'
        self.parent.pos = self.pos


class DefTableShd80Operand(DOCDirStream):
    """The DefTableSdh800Operand structure is an operand that is used by several Table Sprms to
    specify each style of background shading that is applied to each of the cells in a single row."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<defTableShd80Operand type="DefTableShd80Operand" offset="%d">' % self.pos
        self.printAndSet("cb", self.readuInt8())
        for i in xrange(self.cb / Shd80.size):
            Shd80(self).dump()
        print '</defTableShd80Operand>'


class CMajorityOperand(DOCDirStream):
    """The CMajorityOperand structure is used by sprmCMajority to specify which
    character properties of the text to reset to match that of the underlying
    paragraph style."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<cMajorityOperand type="CMajorityOperand" offset="%d">' % self.pos
        self.printAndSet("cb", self.readuInt8())
        pos = 0
        print '<grpprl offset="%d" size="%d bytes">' % (self.pos, self.cb)
        while self.cb - pos > 0:
            prl = Prl(self, self.pos + pos)
            prl.dump()
            pos += prl.getSize()
        print '</grpprl>'
        print '</cMajorityOperand>'

# The PgbApplyTo enumeration is used to specify the pages to which a page border applies.
PgbApplyTo = {
    0x0: "pgbAllPages",
    0x1: "pgbFirstPage",
    0x2: "pgbAllButFirst"
}

# The PgbOffsetFrom enumeration is used to specify the location from which the offset of a page
# border is measured.
PgbOffsetFrom = {
    0x0: "pgbFromText",
    0x1: "pgbFromEdge"
}

# The PgbPageDepth enumeration is used to specify the "depth" of a page border in relation to other
# page elements.
PgbPageDepth = {
    0x0: "pgbAtFront",
    0x1: "pgbAtBack",
}


class SPgbPropOperand(DOCDirStream):
    """The SPgbPropOperand structure is the operand to sprmSPgbProp. It specifies the properties of a
    page border."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<sPgbPropOperand type="SPgbPropOperand" offset="%d">' % self.pos
        buf = self.readuInt8()
        self.printAndSet("pgbApplyTo", buf & 0x7, dict=PgbApplyTo)  # 1..3rd bits
        self.printAndSet("pgbPageDepth", (buf & 0x18) >> 3, dict=PgbPageDepth)  # 4..5th bits
        self.printAndSet("pgbOffsetFrom", (buf & 0xe0) >> 5, dict=PgbOffsetFrom)  # 6..8th bits
        self.printAndSet("reserved", self.readuInt8())
        print '</sPgbPropOperand>'


class MFPF(DOCDirStream):
    """The MFPF structure specifies the type of picture data that is stored."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent

    def dump(self):
        mmDict = {
            0x0064: "MM_SHAPE",
            0x0066: "MM_SHAPEFILE",
        }
        print '<mfpf type="MFPF" offset="%d">' % self.pos
        self.printAndSet("mm", self.readInt16(), dict=mmDict, default="todo")
        self.printAndSet("xExt", self.readuInt16())
        self.printAndSet("yExt", self.readuInt16())
        self.printAndSet("swHMF", self.readuInt16())
        self.parent.pos = self.pos
        print '</mfpf>'


class PICF_Shape(DOCDirStream):
    """The PICF_Shape structure specifies additional header information for
    pictures of type MM_SHAPE or MM_SHAPEFILE."""
    def __init__(self, parent, name):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent
        self.name = name

    def dump(self):
        print '<%s type="PICF_Shape" offset="%d">' % (self.name, self.pos)
        self.printAndSet("grf", self.readuInt32())
        self.printAndSet("padding1", self.readuInt32())
        self.printAndSet("mmpm", self.readuInt16())
        self.printAndSet("padding2", self.readuInt32())
        self.parent.pos = self.pos
        print '</%s>' % self.name

# BrcType is an unsigned integer that specifies the type of border.
BrcType = {
    0x00: "none",
    0x01: "single",
    0x03: "double",
    0x05: "A thin single solid line.",
    0x06: "dotted",
    0x07: "dashed",
    0x08: "dotDash",
    0x09: "dotDotDash",
    0x0A: "triple",
    0x0B: "thinThickSmallGap",
    0x0C: "thickThinSmallGap",
    0x0D: "thinThickThinSmallGap",
    0x0E: "thinThickMediumGap",
    0x0F: "thickThinMediumGap",
    0x10: "thinThickThinMediumGap",
    0x11: "thinThickLargeGap",
    0x12: "thickThinLargeGap",
    0x13: "thinThickThinLargeGap",
    0x14: "wave",
    0x15: "doubleWave",
    0x16: "dashSmallGap",
    0x17: "dashDotStroked",
    0x18: "threeDEmboss",
    0x19: "threeDEngrave",
    0x1A: "outset",
    0x1B: "inset",
    0x40: "apples",
    0x41: "archedScallops",
    0x42: "babyPacifier",
    0x43: "babyRattle",
    0x44: "balloons3Colors",
    0x45: "balloonsHotAir",
    0x46: "basicBlackDashes",
    0x47: "basicBlackDots",
    0x48: "basicBlackSquares",
    0x49: "basicThinLines",
    0x4A: "basicWhiteDashes",
    0x4B: "basicWhiteDots",
    0x4C: "basicWhiteSquares",
    0x4D: "basicWideInline",
    0x4E: "basicWideMidline",
    0x4F: "basicWideOutline",
    0x50: "bats",
    0x51: "birds",
    0x52: "birdsFlight",
    0x53: "cabins",
    0x54: "cakeSlice",
    0x55: "candyCorn",
    0x56: "celticKnotwork",
    0x57: "certificateBanner",
    0x58: "chainLink",
    0x59: "champagneBottle",
    0x5A: "checkedBarBlack",
    0x5B: "checkedBarColor",
    0x5C: "checkered",
    0x5D: "christmasTree",
    0x5E: "circlesLines",
    0x5F: "circlesRectangles",
    0x60: "classicalWave",
    0x61: "clocks",
    0x62: "compass",
    0x63: "confetti",
    0x64: "confettiGrays",
    0x65: "confettiOutline",
    0x66: "confettiStreamers",
    0x67: "confettiWhite",
    0x68: "cornerTriangles",
    0x69: "couponCutoutDashes",
    0x6A: "couponCutoutDots",
    0x6B: "crazyMaze",
    0x6C: "creaturesButterfly",
    0x6D: "creaturesFish",
    0x6E: "creaturesInsects",
    0x6F: "creaturesLadyBug",
    0x70: "crossStitch",
    0x71: "cup",
    0x72: "decoArch",
    0x73: "decoArchColor",
    0x74: "decoBlocks",
    0x75: "diamondsGray",
    0x76: "doubleD",
    0x77: "doubleDiamonds",
    0x78: "earth1",
    0x79: "earth2",
    0x7A: "eclipsingSquares1",
    0x7B: "eclipsingSquares2",
    0x7C: "eggsBlack",
    0x7D: "fans",
    0x7E: "film",
    0x7F: "firecrackers",
    0x80: "flowersBlockPrint",
    0x81: "flowersDaisies",
    0x82: "flowersModern1",
    0x83: "flowersModern2",
    0x84: "flowersPansy",
    0x85: "flowersRedRose",
    0x86: "flowersRoses",
    0x87: "flowersTeacup",
    0x88: "flowersTiny",
    0x89: "gems",
    0x8A: "gingerbreadMan",
    0x8B: "gradient",
    0x8C: "handmade1",
    0x8D: "handmade2",
    0x8E: "heartBalloon",
    0x8F: "heartGray",
    0x90: "hearts",
    0x91: "heebieJeebies",
    0x92: "holly",
    0x93: "houseFunky",
    0x94: "hypnotic",
    0x95: "iceCreamCones",
    0x96: "lightBulb",
    0x97: "lightning1",
    0x98: "lightning2",
    0x99: "mapPins",
    0x9A: "mapleLeaf",
    0x9B: "mapleMuffins",
    0x9C: "marquee",
    0x9D: "marqueeToothed",
    0x9E: "moons",
    0x9F: "mosaic",
    0xA0: "musicNotes",
    0xA1: "northwest",
    0xA2: "ovals",
    0xA3: "packages",
    0xA4: "palmsBlack",
    0xA5: "palmsColor",
    0xA6: "paperClips",
    0xA7: "papyrus",
    0xA8: "partyFavor",
    0xA9: "partyGlass",
    0xAA: "pencils",
    0xAB: "people",
    0xAC: "peopleWaving",
    0xAD: "peopleHats",
    0xAE: "poinsettias",
    0xAF: "postageStamp",
    0xB0: "pumpkin1",
    0xB1: "pushPinNote2",
    0xB2: "pushPinNote1",
    0xB3: "pyramids",
    0xB4: "pyramidsAbove",
    0xB5: "quadrants",
    0xB6: "rings",
    0xB7: "safari",
    0xB8: "sawtooth",
    0xB9: "sawtoothGray",
    0xBA: "scaredCat",
    0xBB: "seattle",
    0xBC: "shadowedSquares",
    0xBD: "sharksTeeth",
    0xBE: "shorebirdTracks",
    0xBF: "skyrocket",
    0xC0: "snowflakeFancy",
    0xC1: "snowflakes",
    0xC2: "sombrero",
    0xC3: "southwest",
    0xC4: "stars",
    0xC5: "starsTop",
    0xC6: "stars3d",
    0xC7: "starsBlack",
    0xC8: "starsShadowed",
    0xC9: "sun",
    0xCA: "swirligig",
    0xCB: "tornPaper",
    0xCC: "tornPaperBlack",
    0xCD: "trees",
    0xCE: "triangleParty",
    0xCF: "triangles",
    0xD0: "tribal1",
    0xD1: "tribal2",
    0xD2: "tribal3",
    0xD3: "tribal4",
    0xD4: "tribal5",
    0xD5: "tribal6",
    0xD6: "twistedLines1",
    0xD7: "twistedLines2",
    0xD8: "vine",
    0xD9: "waveline",
    0xDA: "weavingAngles",
    0xDB: "weavingBraid",
    0xDC: "weavingRibbon",
    0xDD: "weavingStrips",
    0xDE: "whiteFlowers",
    0xDF: "woodwork",
    0xE0: "xIllusions",
    0xE1: "zanyTriangles",
    0xE2: "zigZag",
    0xE3: "zigZagStitch"
}


class Brc80(DOCDirStream):
    """The Brc80 structure describes a border."""
    def __init__(self, parent, name):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent
        self.name = name

    def dump(self):
        buf = self.readuInt32()
        print '<%s type="Brc80" offset="%d">' % (self.name, self.pos)
        self.printAndSet("dptLineWidth", buf & 0x000000ff)  # 1..8th bits
        self.printAndSet("brcType", (buf & 0x0000ff00) >> 8, dict=BrcType)  # 9..16th bits
        self.printAndSet("ico", (buf & 0x00ff0000) >> 16, dict=Ico)  # 17..24th bits
        self.printAndSet("dptSpace", (buf & 0x1f000000) >> 24)  # 25..29th bits
        self.printAndSet("fShadow", self.getBit(buf, 29))
        self.printAndSet("fFrame", self.getBit(buf, 30))
        self.printAndSet("reserved", self.getBit(buf, 31))
        print '</%s>' % self.name
        self.parent.pos = self.pos


class Brc80MayBeNil(DOCDirStream):
    """The Brc80MayBeNil structure is a Brc80 structure. When all bits are set,
    this structure specifies that the region in question has no border."""
    def __init__(self, parent, name):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent
        self.name = name

    def dump(self):
        buf = self.getuInt32()
        if buf == 0xFFFFFFFF:
            print '<%s type="Brc80MayBeNil" offset="%d" value="%s"/>' % (self.name, self.pos, hex(buf))
            self.pos += 4
        else:
            print '<%s type="Brc80MayBeNil" offset="%d">' % (self.name, self.pos)
            Brc80(self, self.name).dump()
            print '</%s>' % self.name
        self.parent.pos = self.pos


class PICMID(DOCDirStream):
    """The PICMID structure specifies the size and border information for a picture."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent

    def dump(self):
        print '<picmid type="PICMID" offset="%d">' % self.pos
        self.printAndSet("dxaGoal", self.readuInt16())
        self.printAndSet("dyaGoal", self.readuInt16())
        self.printAndSet("mx", self.readuInt16())
        self.printAndSet("my", self.readuInt16())
        self.printAndSet("dxaReserved1", self.readuInt16())
        self.printAndSet("dyaReserved1", self.readuInt16())
        self.printAndSet("dxaReserved2", self.readuInt16())
        self.printAndSet("dyaReserved2", self.readuInt16())
        self.printAndSet("fReserved", self.readuInt8())
        self.printAndSet("bpp", self.readuInt8())
        Brc80(self, "brcTop80").dump()
        Brc80(self, "brcLeft80").dump()
        Brc80(self, "brcBottom80").dump()
        Brc80(self, "brcRight80").dump()
        self.printAndSet("dxaReserved3", self.readuInt16())
        self.printAndSet("dyaReserved3", self.readuInt16())
        self.parent.pos = self.pos
        print '</picmid>'


class PICF(DOCDirStream):
    """The PICF structure specifies the type of a picture, as well as the size
    of the picture and information about its border."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent

    def dump(self):
        print '<picf type="PICF" offset="%d">' % self.pos
        posOrig = self.pos
        self.printAndSet("lcb", self.readInt32())
        self.printAndSet("cbHeader", self.readInt16())
        assert self.cbHeader == 0x44
        self.mfpf = MFPF(self)
        self.mfpf.dump()
        if self.mfpf.mm == 0x0064:  # MM_SHAPEFILE
            PICF_Shape(self, "innerHeader").dump()
            PICMID(self).dump()
            self.printAndSet("cProps", self.readuInt16())
        else:
            self.pos = posOrig + self.cbHeader
        self.parent.pos = self.pos
        print '</picf>'


IType = {
    0: "iTypeText",
    1: "iTypeChck",
    2: "iTypeDrop"
}


ITypeTxt = {
    0: "iTypeTxtReg",
    1: "iTypeTxtNum",
    2: "iTypeTxtDate",
    3: "iTypeTxtCurDate",
    4: "iTypeTxtCurTime",
    5: "iTypeTxtCalc"
}


class FFDataBits(DOCDirStream):
    """The FFDataBits structure specifies the type and properties for a form
    field that is specified by a FFData."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent

    def dump(self):
        print '<FFDataBits>'
        buf = self.readuInt8()
        self.printAndSet("iType", buf & 0x0003, dict=IType)  # 1..2nd bits
        self.printAndSet("iRes", buf & 0x007c)  # 3..7th bits
        self.printAndSet("fOwnHelp", self.getBit(buf, 8))
        buf = self.readuInt8()
        self.printAndSet("fOwnStat", self.getBit(buf, 1))
        self.printAndSet("fProt", self.getBit(buf, 2))
        self.printAndSet("iSize", self.getBit(buf, 3))
        self.printAndSet("iTypeTxt", buf & 0x0038, dict=ITypeTxt)  # 4..6th bits
        self.printAndSet("fRecalc", self.getBit(buf, 7))
        self.printAndSet("fHasListBox", self.getBit(buf, 8))
        print '</FFDataBits>'
        self.parent.pos = self.pos


class FFData(DOCDirStream):
    """The FFData structure specifies form field data for a text box, check
    box, or drop-down list box. (Page 348 of [MS-DOC] spec.)"""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent

    def dump(self):
        print '<FFData>'
        self.printAndSet("version", self.readuInt32())
        self.bits = FFDataBits(self)
        self.bits.dump()
        self.printAndSet("cch", self.readuInt16())
        self.printAndSet("hps", self.readuInt16())
        xstzName = Xstz(self, "xstzName")
        xstzName.dump()
        self.pos = xstzName.pos
        xstzTextDef = Xstz(self, "xstzTextDef")
        xstzTextDef.dump()
        self.pos = xstzTextDef.pos
        if self.bits.iType == 1 or self.bits.iType == 2:  # iTypeChck or iTypeDrop
            self.printAndSet("wDef", self.readuInt16())
        xstzTextFormat = Xstz(self, "xstzTextFormat")
        xstzTextFormat.dump()
        self.pos = xstzTextFormat.pos
        xstzHelpText = Xstz(self, "xstzHelpText")
        xstzHelpText.dump()
        self.pos = xstzHelpText.pos
        xstzStatText = Xstz(self, "xstzStatText")
        xstzStatText.dump()
        self.pos = xstzStatText.pos
        xstzEntryMcr = Xstz(self, "xstzEntryMcr")
        xstzEntryMcr.dump()
        self.pos = xstzEntryMcr.pos
        xstzExitMcr = Xstz(self, "xstzExitMcr")
        xstzExitMcr.dump()
        self.pos = xstzExitMcr.pos
        if self.bits.iType == 2:  # iTypeDrop
            print '<todo what="FFData::dump(): handle hsttbDropList for iTypeDrop"/>'
        print '</FFData>'


class NilPICFAndBinData(DOCDirStream):
    """The NilPICFAndBinData structure that holds header information and binary
    data for a hyperlink, form field, or add-in field. The NilPICFAndBinData
    structure MUST be stored in the Data Stream."""
    def __init__(self, parent):
        dataStream = parent.mainStream.doc.getDirectoryStreamByName("Data")
        DOCDirStream.__init__(self, dataStream.bytes)
        self.pos = parent.operand
        self.parent = parent

    def dump(self):
        print '<NilPICFAndBinData>'
        # self -> sprm -> prl -> chpx -> chpxFkp
        chpxFkp = self.parent.parent.parent.parent
        self.printAndSet("lcb", self.readInt32())
        self.printAndSet("cbHeader", self.readInt16())
        self.printAndSet("ignored0", self.readInt32())
        self.printAndSet("ignored1", self.readInt32())
        self.printAndSet("ignored2", self.readInt32())
        self.printAndSet("ignored3", self.readInt32())
        self.printAndSet("ignored4", self.readInt32())
        self.printAndSet("ignored5", self.readInt32())
        self.printAndSet("ignored6", self.readInt32())
        self.printAndSet("ignored7", self.readInt32())
        self.printAndSet("ignored8", self.readInt32())
        self.printAndSet("ignored9", self.readInt32())
        self.printAndSet("ignored10", self.readInt32())
        self.printAndSet("ignored11", self.readInt32())
        self.printAndSet("ignored12", self.readInt32())
        self.printAndSet("ignored13", self.readInt32())
        self.printAndSet("ignored14", self.readInt32())
        self.printAndSet("ignored15", self.readInt16())
        fieldType = chpxFkp.transformeds[-2]
        if fieldType == " FORMTEXT ":
            FFData(self).dump()
        else:
            print '<todo what="NilPICFAndBinData::dump(): handle %s"/>' % fieldType
        print '</NilPICFAndBinData>'


class PICFAndOfficeArtData(DOCDirStream):
    """The PICFAndOfficeArtData structure specifies header information and
    binary data for a picture."""
    def __init__(self, parent):
        dataStream = parent.mainStream.doc.getDirectoryStreamByName("Data")
        DOCDirStream.__init__(self, dataStream.bytes)
        self.pos = parent.operand
        self.parent = parent

    def dump(self):
        print '<PICFAndOfficeArtData>'
        found = False
        for prl in self.parent.parent.parent.prls:
            if prl.sprm.sprm in (0x0806, 0x080a):  # sprmCFData, sprmCFOle2
                found = True
                break
        if not found:
            pos = self.pos
            picf = PICF(self)
            picf.dump()
            assert self.pos == pos + 68
            if picf.mfpf.mm == 0x0066:  # MM_SHAPEFILE
                print '<todo what="PICFAndOfficeArtData::dump(): picf.mfpf.mm == MM_SHAPEFILE is unhandled"/>'
            elif picf.mfpf.mm == 0x0064:  # MM_SHAPE
                remaining = picf.lcb - (self.pos - pos)
                msodraw.InlineSpContainer(self, remaining).dumpXml(self, getWordModel(self.parent.mainStream))
            else:
                print '<todo what="PICFAndOfficeArtData::dump(): picf.mfpf.mm is unhandled (not MM_SHAPE or MM_SHAPEFILE): %d"/>' % picf.mfpf.mm
        else:
            print '<todo what="PICFAndOfficeArtData::dump(): handle sprmCFData or sprmCFOle2"/>'
        print '</PICFAndOfficeArtData>'

# The TextFlow enumeration specifies the rotation settings for a block of text and for the individual
# East Asian characters in each line of the block.
TextFlow = {
    0x0000: "grpfTFlrtb",
    0x0001: "grpfTFtbrl",
    0x0003: "grpfTFbtlr",
    0x0004: "grpfTFlrtbv",
    0x0005: "grpfTFtbrlv"
}

# The VerticalMergeFlag enumeration provides a 2-bit value that specifies whether a table cell is
# merged with the cells above or below it.
VerticalMergeFlag = {
    0x00: "fvmClear",
    0x01: "fvmMerge",
    0x03: "fvmRestart"
}

# The VerticalAlign enumeration specifies the vertical alignment of content within table cells.
VerticalAlign = {
    0x00: "vaTop",
    0x01: "vaCenter",
    0x02: "vaBottom",
}

# The Fts enumeration specifies how the preferred width for a table, table indent, table cell, cell
# margin, or cell spacing is defined.
Fts = {
    0x00: "ftsNil",
    0x01: "ftsAuto",
    0x02: "ftsPercent",
    0x03: "ftsDxa",
    0x13: "ftsDxaSys"
}


class SHD(DOCDirStream):
    """The Shd structure specifies the colors and pattern that are used for background shading."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos

    def dump(self):
        print '<shd type="SHD" offset="%d">' % self.pos
        COLORREF(self).dump("cvFore")
        COLORREF(self).dump("cvBack")
        self.printAndSet("ipat", self.readuInt16(), dict=Ipat)
        print '</shd>'


class TCGRF(DOCDirStream):
    """A TCGRF structure specifies the text layout and cell merge properties for a single cell in a table."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos

    def dump(self):
        print '<tcgrf type="TCGRF" offset="%d">' % self.pos
        buf = self.readuInt16()
        self.printAndSet("horzMerge", buf & 0x0003)  # 1..2nd bits
        self.printAndSet("textFlow", (buf & 0x001c) >> 2, dict=TextFlow, default="todo")  # 3..6th bits
        self.printAndSet("vertMerge", (buf & 0x0060) >> 6, dict=VerticalMergeFlag)  # 7..8th bits
        self.printAndSet("vertAlign", (buf & 0x0180) >> 8, dict=VerticalAlign)  # 9..10th bits
        self.printAndSet("ftsWidth", (buf & 0x0e00) >> 10, dict=Fts)  # 11..12th bits
        self.printAndSet("fFitText", self.getBit(buf, 12))
        self.printAndSet("fNoWrap", self.getBit(buf, 13))
        self.printAndSet("fHideMark", self.getBit(buf, 14))
        self.printAndSet("fUnused", self.getBit(buf, 15))
        print '</tcgrf>'
        self.parent.pos = self.pos


class TC80(DOCDirStream):
    """The TC80 structure specifies the border and other formatting for a single cell in a table."""
    def __init__(self, parent, index):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos
        self.index = index

    def dump(self):
        print '<tc80 index="%d">' % self.index
        TCGRF(self).dump()
        self.printAndSet("wWidth", self.readuInt16(), hexdump=False)
        Brc80MayBeNil(self, "brcTop").dump()
        Brc80MayBeNil(self, "brcLeft").dump()
        Brc80MayBeNil(self, "brcBottom").dump()
        Brc80MayBeNil(self, "brcRight").dump()
        print '</tc80>'
        self.parent.pos = self.pos


class TDefTableOperand(DOCDirStream):
    """The TDefTableOperand structure is the operand that is used by the
    sprmTDefTable value. It specifies the initial layout of the columns in the
    current table row."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<tDefTableOperand>'
        self.printAndSet("cb", self.readuInt16())
        size = self.pos + self.cb - 1
        self.printAndSet("NumberOfColumns", self.readuInt8())
        for i in range(self.NumberOfColumns + 1):
            print '<rgdxaCenter index="%d" value="%d"/>' % (i, self.readInt16())
        i = 0
        while self.pos < size:
            TC80(self, i).dump()
            i += 1
        print '</tDefTableOperand>'


class TableBordersOperand(DOCDirStream):
    """The TableBordersOperand structure specifies a set of borders for a table row."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<tableBordersOperand>'
        self.printAndSet("cb", self.readuInt8())
        posOrig = self.pos
        BRC(self, "brcTop").dump()
        BRC(self, "brcLeft").dump()
        BRC(self, "brcBottom").dump()
        BRC(self, "brcRight").dump()
        BRC(self, "brcHorizontalInside").dump()
        BRC(self, "brcVerticalInside").dump()
        assert self.pos == posOrig + 0x30
        print '</tableBordersOperand>'


class TableBordersOperand80(DOCDirStream):
    """The TableBordersOperand80 structure is an operand that specifies the
    borders which are applied to a row of table cells."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<tableBordersOperand80>'
        self.printAndSet("cb", self.readuInt8())
        posOrig = self.pos
        Brc80MayBeNil(self, "brcTop").dump()
        Brc80MayBeNil(self, "brcLeft").dump()
        Brc80MayBeNil(self, "brcBottom").dump()
        Brc80MayBeNil(self, "brcRight").dump()
        Brc80MayBeNil(self, "brcHorizontalInside").dump()
        Brc80MayBeNil(self, "brcVerticalInside").dump()
        assert self.pos == posOrig + 0x18
        print '</tableBordersOperand80>'


class SHDOperand(DOCDirStream):
    """The SDHOperand structure is an operand that is used by several Sprm
    structures to specify the background shading to be applied."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<shdOperand>'
        self.printAndSet("cb", self.readuInt8())
        SHD(self).dump()
        print '</shdOperand>'


class BrcOperand(DOCDirStream):
    """The BrcOperand structure is the operand to several SPRMs that control borders."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.posOrig = self.pos
        self.cb = self.readuInt8()
        self.brc = BRC(self)

    def dump(self):
        print '<brcOperand type="BrcOperand" offset="%d">' % self.posOrig
        self.brc.dump()
        print '</brcOperand>'


class Sprm(DOCDirStream):
    """The Sprm structure specifies a modification to a property of a character, paragraph, table, or section."""
    def __init__(self, parent, mainStream=None, transformed=None):
        DOCDirStream.__init__(self, parent.bytes, mainStream=mainStream)
        self.parent = parent
        self.transformed = transformed
        self.pos = parent.pos
        self.operandSizeMap = {
            0: 1,
            1: 1,
            2: 2,
            3: 4,
            4: 2,
            5: 2,
            7: 3,
        }

        self.sprm = self.readuInt16()

        self.ispmd = (self.sprm & 0x1ff)  # 1-9th bits
        self.fSpec = (self.sprm & 0x200) >> 9  # 10th bit
        self.sgc = (self.sprm & 0x1c00) >> 10  # 11-13th bits
        self.spra = (self.sprm & 0xe000) >> 13  # 14-16th bits

        self.ct = False  # If it's a complex type, it can't be dumped as a simple string.
        self.operand = "todo"
        if self.getOperandSize() == 1:
            self.operand = self.getuInt8()
        elif self.getOperandSize() == 2:
            self.operand = self.getuInt16()
            if self.sprm == 0x522f:
                self.ct = SPgbPropOperand(self)
        elif self.getOperandSize() == 3:
            self.operand = self.getuInt24()
        elif self.getOperandSize() == 4:
            self.operand = self.getuInt32()
            if self.sprm == 0x6a03 and transformed == r"\x01":  # sprmCPicLocation
                # Can't decide right now, depends on if there will be an sprmCFData later or not.
                self.ct = True
            elif self.sprm == 0x6646:  # sprmPHugePapx
                dataStream = mainStream.doc.getDirectoryStreamByName("Data")
                dataStream.pos = self.operand
                self.ct = PrcData(dataStream)
        elif self.getOperandSize() == 7:
            self.operand = self.getuInt64() & 0x0fffffff
        elif self.getOperandSize() == 9:
            # top, left, bottom and right page / paragraph borders
            if self.sprm in (0xd234, 0xd235, 0xd236, 0xd237, 0xc64e, 0xc64f, 0xc650, 0xc651):
                self.ct = BrcOperand(self)
            elif self.sprm == 0xc60d:
                self.ct = PChgTabsPapxOperand(self)
            elif self.sprm == 0xc615:
                self.ct = PChgTabsOperand(self)
            elif self.sprm == 0xd609:
                self.ct = DefTableShd80Operand(self)
            elif self.sprm == 0xca47:
                self.ct = CMajorityOperand(self)
            else:
                print '<todo what="Sprm::__init__() unhandled sprm of size 9: %s"/>' % hex(self.sprm)
        else:
            if self.sprm == 0xd608:
                self.ct = TDefTableOperand(self)
            elif self.sprm == 0xca71:
                self.ct = SHDOperand(self)
            elif self.sprm == 0xd613:
                self.ct = TableBordersOperand(self)
            elif self.sprm == 0xd605:
                self.ct = TableBordersOperand80(self)
            elif self.sprm == 0xc60d:
                self.ct = PChgTabsPapxOperand(self)
            else:
                print '<todo what="Sprm::__init__() unhandled sprm of size %s: %s"/>' % (self.getOperandSize(), hex(self.sprm))

    def dump(self):
        sgcmap = {
            1: 'paragraph',
            2: 'character',
            3: 'picture',
            4: 'section',
            5: 'table'
        }
        nameMap = {
            1: docsprm.parMap,
            2: docsprm.chrMap,
            3: docsprm.picMap,
            4: docsprm.secMap,
            5: docsprm.tblMap,
        }
        attrs = []
        close = False
        attrs.append('value="%s"' % hex(self.sprm))
        attrs.append('ispmd="%s"' % hex(self.ispmd))
        attrs.append('fSpec="%s"' % hex(self.fSpec))
        if self.sgc in sgcmap:
            attrs.append('sgc="%s"' % sgcmap[self.sgc])
        attrs.append('spra="%s"' % self.spra)
        if self.sgc in nameMap and self.sprm in nameMap[self.sgc]:
            attrs.append('name="%s"' % nameMap[self.sgc][self.sprm])
        attrs.append('operandSize="%s"' % self.getOperandSize())
        if not self.ct:
            close = True
            if self.operand == "todo":
                attrs.append('operand=""')
            else:
                attrs.append('operand="%s"' % hex(self.operand))
        print '<sprm %s%s>' % (" ".join(attrs), {True: "/", False: ""}[close])
        if self.ct:
            if type(self.ct) == bool:
                if self.sprm == 0x6a03 and self.transformed == r"\x01":
                    haveCFData = False
                    for prl in self.parent.parent.prls:
                        if prl.sprm.sprm == 0x0806:  # sprmCFData
                            haveCFData = True
                            break
                    if haveCFData:
                        self.ct = NilPICFAndBinData(self)
                    else:
                        self.ct = PICFAndOfficeArtData(self)
            self.ct.dump()
            print '</sprm>'

    def getOperandSize(self):
        if self.spra == 6:  # variable
            if self.sprm not in [0xD608, 0xC615]:  # sprmTDefTable, sprmPChgTabs
                # these structures are prefixed with their size
                return self.getuInt8() + 1
            elif self.sprm == 0xD608:
                return self.getuInt16() + 1
            elif self.sprm == 0xC615:
                cb = self.getuInt8()
                if cb < 255:
                    return cb + 1
                else:
                    raise Exception("PChgTabsOperand: cb is 255")
            raise Exception("No idea what is the size of SPRM %s" % hex(self.sprm))
        return self.operandSizeMap[self.spra]


class Prl(DOCDirStream):
    """The Prl structure is a Sprm that is followed by an operand."""
    def __init__(self, parent, offset, mainStream=None, transformed=None, index=None):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = offset
        self.posOrig = self.pos
        self.sprm = Sprm(self, mainStream, transformed)
        self.pos += 2
        self.index = index

    def dump(self):
        indexstr = ""
        if self.index is not None:
            indexstr = ' index="%d"' % self.index
        print '<prl type="Prl" offset="%d"%s>' % (self.posOrig, indexstr)
        self.sprm.dump()
        print '</prl>'

    def getSize(self):
        return 2 + self.sprm.getOperandSize()


class GrpPrlAndIstd(DOCDirStream):
    """The GrpPrlAndIstd structure specifies the style and properties that are applied to a paragraph, a table row, or a table cell."""
    def __init__(self, bytes, offset, size, mainStream=None):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<grpPrlAndIstd type="GrpPrlAndIstd" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        self.printAndSet("istd", self.getuInt16())
        pos += 2
        while (self.size - (pos - self.pos)) > 0:
            prl = Prl(self, pos, mainStream=self.mainStream)
            prl.dump()
            pos += prl.getSize()
        print '</grpPrlAndIstd>'


class Chpx(DOCDirStream):
    """The Chpx structure specifies a set of properties for text."""
    def __init__(self, parent, mainStream, offset, transformed=None):
        DOCDirStream.__init__(self, parent.bytes, mainStream=mainStream)
        self.parent = parent
        self.pos = offset
        self.transformed = transformed

        self.cb = self.readuInt8()
        pos = self.pos
        index = 0
        self.prls = []
        while (self.cb - (pos - self.pos)) > 0:
            prl = Prl(self, pos, self.mainStream, self.transformed, index)
            self.prls.append(prl)
            pos += prl.getSize()
            index += 1

    def dump(self):
        print '<chpx type="Chpx" offset="%d">' % self.pos
        self.printAndSet("cb", self.cb)
        for prl in self.prls:
            prl.dump()
        print '</chpx>'


class PapxInFkp(DOCDirStream):
    """The PapxInFkp structure specifies a set of text properties."""
    def __init__(self, bytes, mainStream, offset):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset

    def dump(self):
        print '<papxInFkp type="PapxInFkp" offset="%d">' % self.pos
        self.printAndSet("cb", self.readuInt8())
        if self.cb == 0:
            self.printAndSet("cb_", self.readuInt8())
            grpPrlAndIstd = GrpPrlAndIstd(self.bytes, self.pos, 2 * self.cb_, mainStream=self.mainStream)
        else:
            grpPrlAndIstd = GrpPrlAndIstd(self.bytes, self.pos, self.cb, mainStream=self.mainStream)
        grpPrlAndIstd.dump()
        print '</papxInFkp>'


class BxPap(DOCDirStream):
    """The BxPap structure specifies the offset of a PapxInFkp in PapxFkp."""
    size = 13  # in bytes, see 2.9.23

    def __init__(self, bytes, mainStream, offset, parentoffset):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.parentpos = parentoffset

    def dump(self):
        print '<bxPap type="BxPap" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("bOffset", self.readuInt8())
        papxInFkp = PapxInFkp(self.bytes, self.mainStream, self.parentpos + self.bOffset * 2)
        papxInFkp.dump()
        print '</bxPap>'


class ChpxFkp(DOCDirStream):
    """The ChpxFkp structure maps text to its character properties."""
    def __init__(self, pnFkpChpx, offset, size):
        DOCDirStream.__init__(self, pnFkpChpx.mainStream.bytes, mainStream=pnFkpChpx.mainStream)
        self.pos = offset
        self.size = size
        self.pnFkpChpx = pnFkpChpx

    def dump(self):
        print '<chpxFkp type="ChpxFkp" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.crun = self.getuInt8(pos=self.pos + self.size - 1)
        pos = self.pos
        self.transformeds = []
        for i in range(self.crun):
            # rgfc
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<rgfc index="%d" start="%d" end="%d">' % (i, start, end)
            self.transformed = self.quoteAttr(self.pnFkpChpx.mainStream.retrieveOffset(start, end))
            print '<transformed value="%s"/>' % self.transformed
            self.transformeds.append(self.transformed)
            pos += 4

            # rgbx
            offset = PLC.getPLCOffset(self.pos, self.crun, 1, i)
            chpxOffset = self.getuInt8(pos=offset) * 2
            chpx = Chpx(self, self.mainStream, self.pos + chpxOffset, self.transformed)
            chpx.dump()
            print '</rgfc>'

        self.printAndSet("crun", self.crun)
        print '</chpxFkp>'


class PapxFkp(DOCDirStream):
    """The PapxFkp structure maps paragraphs, table rows, and table cells to their properties."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, mainStream.bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<papxFkp type="PapxFkp" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.cpara = self.getuInt8(pos=self.pos + self.size - 1)
        pos = self.pos
        for i in range(self.cpara):
            # rgfc
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<rgfc index="%d" start="%d" end="%d">' % (i, start, end)
            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveOffset(start, end))
            pos += 4

            # rgbx
            offset = PLC.getPLCOffset(self.pos, self.cpara, BxPap.size, i)
            bxPap = BxPap(self.bytes, self.mainStream, offset, self.pos)
            bxPap.dump()
            print '</rgfc>'

        self.printAndSet("cpara", self.cpara)
        print '</papxFkp>'


class PnFkpChpx(DOCDirStream):
    """The PnFkpChpx structure specifies the location in the WordDocument Stream of a ChpxFkp structure."""
    def __init__(self, plcBteChpx, offset, size, name):
        DOCDirStream.__init__(self, plcBteChpx.bytes, mainStream=plcBteChpx.mainStream)
        self.pos = offset
        self.size = size
        self.name = name
        self.plcBteChpx = plcBteChpx

    def dump(self):
        print '<%s type="PnFkpChpx" offset="%d" size="%d bytes">' % (self.name, self.pos, self.size)
        buf = self.readuInt32()
        self.printAndSet("pn", buf & (2 ** 22 - 1))
        chpxFkp = ChpxFkp(self, self.pn * 512, 512)
        chpxFkp.dump()
        print '</%s>' % self.name


class LPXCharBuffer9(DOCDirStream):
    """The LPXCharBuffer9 structure is a length-prefixed buffer for up to 9 Unicode characters."""
    def __init__(self, parent, name):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.name = name

    def dump(self):
        print '<%s type="LPXCharBuffer9" offset="%d" size="20 bytes">' % (self.name, self.pos)
        self.printAndSet("cch", self.readuInt16())
        self.printAndSet("xcharArray", self.bytes[self.pos:self.pos + (self.cch * 2)].decode('utf-16'), hexdump=False)
        print '</%s>' % self.name


class ATRDPre10(DOCDirStream):
    """The ATRDPre10 structure contains information about a comment in the document."""
    def __init__(self, aPlcfandRef, offset):
        DOCDirStream.__init__(self, aPlcfandRef.bytes)
        self.pos = offset

    def dump(self):
        print '<aATRDPre10 type="ATRDPre10" offset="%d" size="30 bytes">' % self.pos
        xstUsrInitl = LPXCharBuffer9(self, "xstUsrInitl")
        xstUsrInitl.dump()
        self.pos += 20
        self.printAndSet("ibst", self.readuInt16())
        self.printAndSet("bitsNotUsed", self.readuInt16())
        self.printAndSet("grfNotUsed", self.readuInt16())
        self.printAndSet("ITagBkmk", self.readInt32())
        print '</aATRDPre10>'


class PnFkpPapx(DOCDirStream):
    """The PnFkpPapx structure specifies the offset of a PapxFkp in the WordDocument Stream."""
    def __init__(self, bytes, mainStream, offset, size, name):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size
        self.name = name

    def dump(self):
        print '<%s type="PnFkpPapx" offset="%d" size="%d bytes">' % (self.name, self.pos, self.size)
        buf = self.readuInt32()
        self.printAndSet("pn", buf & (2 ** 22 - 1))
        papxFkp = PapxFkp(self.bytes, self.mainStream, self.pn * 512, 512)
        papxFkp.dump()
        print '</%s>' % self.name


class PlcBteChpx(DOCDirStream, PLC):
    """The PlcBteChpx structure is a PLC that maps the offsets of text in the WordDocument stream to the character properties of that text."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, mainStream.lcbPlcfBteChpx, 4)
        self.pos = mainStream.fcPlcfBteChpx
        self.size = mainStream.lcbPlcfBteChpx

    def dump(self):
        print '<plcBteChpx type="PlcBteChpx" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        for i in range(self.getElements()):
            # aFC
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aFC index="%d" start="%d" end="%d">' % (i, start, end)
            pos += 4

            # aPnBteChpx
            aPnBteChpx = PnFkpChpx(self, self.getOffset(self.pos, i), 4, "aPnBteChpx")
            aPnBteChpx.dump()
            print '</aFC>'
        print '</plcBteChpx>'


class PlcfHdd(DOCDirStream, PLC):
    """The Plcfhdd structure is a PLC that contains only CPs and no additional data. It specifies where
    header document stories begin and end."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, mainStream.lcbPlcfHdd, 0)
        self.pos = mainStream.fcPlcfHdd
        self.size = mainStream.lcbPlcfHdd

    def getContents(self, i):
        if i <= 5:
            contentsMap = {
                0: "Footnote separator",
                1: "Footnote continuation separator",
                2: "Footnote continuation notice",
                3: "Endnote separator",
                4: "Endnote continuation separator",
                5: "Endnote continuation notice",
            }
            return contentsMap[i]
        else:
            contentsMap = {
                0: "Even page header",
                1: "Odd page header",
                2: "Even page footer",
                3: "Odd page footer",
                4: "First page header",
                5: "First page footer",
            }
            sectionIndex = i / 6
            contentsIndex = i % 6
            return "%s (section #%s)" % (contentsMap[contentsIndex], sectionIndex)

    def dump(self):
        print '<plcfHdd type="PlcfHdd" offset="%d" size="%d bytes">' % (self.pos, self.size)
        offset = self.mainStream.getHeaderOffset()
        pos = self.pos
        for i in range(self.getElements() - 1):
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aCP index="%d" contents="%s" start="%d" end="%d">' % (i, self.getContents(i), start, end)
            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(offset + start, offset + end))
            pos += 4
            print '</aCP>'
        print '</plcfHdd>'


class PlcfandTxt(DOCDirStream, PLC):
    """The PlcfandTxt structure is a PLC that contains only CPs and no additional data."""
    def __init__(self, mainStream, offset, size):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, size, 0)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<plcfandTxt type="PlcfandTxt" offset="%d" size="%d bytes">' % (self.pos, self.size)
        offset = self.mainStream.getCommentOffset()
        pos = self.pos
        for i in range(self.getElements() - 1):
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aCP index="%d" start="%d" end="%d">' % (i, start, end)
            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(offset + start, offset + end))
            pos += 4
            print '</aCP>'
        print '</plcfandTxt>'


class PlcfandRef(DOCDirStream, PLC):
    """The PlcfandRef structure is a PLC whose data elements are ATRDPre10 structures."""
    def __init__(self, mainStream, offset, size):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, size, 30)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<plcfandRef type="PlcfandRef" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        for i in range(self.getElements()):
            start = self.getuInt32(pos=pos)
            print '<aCP index="%d" commentEnd="%d">' % (i, start)
            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCP(start))
            pos += 4

            # aATRDPre10
            aATRDPre10 = ATRDPre10(self, self.getOffset(self.pos, i))
            aATRDPre10.dump()
            print '</aCP>'
        print '</plcfandRef>'


class PlcBtePapx(DOCDirStream, PLC):
    """The PlcBtePapx structure is a PLC that specifies paragraph, table row, or table cell properties."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        PLC.__init__(self, size, 4)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<plcBtePapx type="PlcBtePapx" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        for i in range(self.getElements()):
            # aFC
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aFC index="%d" start="%d" end="%d">' % (i, start, end)
            pos += 4

            # aPnBtePapx
            aPnBtePapx = PnFkpPapx(self.bytes, self.mainStream, self.getOffset(self.pos, i), 4, "aPnBtePapx")
            aPnBtePapx.dump()
            print '</aFC>'
        print '</plcBtePapx>'


class Pcdt(DOCDirStream):
    """The Pcdt structure contains a PlcPcd structure and specifies its size."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

        self.clxt = self.readuInt8()
        self.lcb = self.readuInt32()
        self.plcPcd = PlcPcd(self.bytes, self.mainStream, self.pos, self.lcb)

    def dump(self):
        print '<pcdt type="Pcdt" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("clxt", self.clxt)
        self.printAndSet("lcb", self.lcb)
        self.plcPcd.dump()
        print '</pcdt>'


class PrcData(DOCDirStream):
    """The PrcData structure specifies an array of Prl elements and the size of
    the array."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

        self.cbGrpprl = self.readInt16()
        pos = 0
        self.prls = []
        while self.cbGrpprl - pos > 0:
            prl = Prl(self, self.pos + pos)
            pos += prl.getSize()
            self.prls.append(prl)
        self.pos += self.cbGrpprl
        parent.pos = self.pos

    def dump(self):
        print '<prcData>'
        self.printAndSet("cbGrpprl", self.cbGrpprl)
        print '<grpPrl>'
        for i in self.prls:
            i.dump()
        print '</grpPrl>'
        print '</prcData>'


class Prc(DOCDirStream):
    """The Prc structure specifies a set of properties for document content
    that is referenced by a Pcd structure."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

        self.clxt = self.readuInt8()
        self.prcData = PrcData(self)
        parent.pos = self.pos

    def dump(self, index):
        print '<prc index="%d">' % index
        self.prcData.dump()
        print '</prc>'


class Clx(DOCDirStream):
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

        self.firstByte = self.getuInt8()
        self.prcs = []
        while True:
            self.firstByte = self.getuInt8()
            if self.firstByte != 0x01:
                break
            self.prcs.append(Prc(self))
        self.pcdt = Pcdt(self.bytes, self.mainStream, self.pos, self.size)

    def dump(self):
        print '<clx type="Clx" offset="%d" size="%d bytes">' % (self.pos, self.size)
        for index, elem in enumerate(self.prcs):
            elem.dump(index)
        self.pcdt.dump()
        print '</clx>'


class Copts60(DOCDirStream):
    """The Copts60 structure specifies compatibility options."""
    def __init__(self, dop):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos

    def dump(self):
        print '<copts60 type="Copts60" offset="%s" size="2 bytes">' % self.pos
        # Copts60 first byte
        buf = self.readuInt8()
        self.printAndSet("fNoTabForInd", self.getBit(buf, 0))
        self.printAndSet("fNoSpaceRaiseLower", self.getBit(buf, 1))
        self.printAndSet("fSuppressSpBfAfterPgBrk", self.getBit(buf, 2))
        self.printAndSet("fWrapTrailSpaces", self.getBit(buf, 3))
        self.printAndSet("fMapPrintTextColor", self.getBit(buf, 4))
        self.printAndSet("fNoColumnBalance", self.getBit(buf, 5))
        self.printAndSet("fConvMailMergeEsc", self.getBit(buf, 6))
        self.printAndSet("fSuppressTopSpacing", self.getBit(buf, 7))

        # Copts60 second byte
        buf = self.readuInt8()
        self.printAndSet("fOrigWordTableRules", self.getBit(buf, 0))
        self.printAndSet("unused14", self.getBit(buf, 1))
        self.printAndSet("fShowBreaksInFrames", self.getBit(buf, 2))
        self.printAndSet("fSwapBordersFacingPgs", self.getBit(buf, 3))
        self.printAndSet("fLeaveBackslashAlone", self.getBit(buf, 4))
        self.printAndSet("fExpShRtn", self.getBit(buf, 5))
        self.printAndSet("fDntULTrlSpc", self.getBit(buf, 6))
        self.printAndSet("fDntBlnSbDbWid", self.getBit(buf, 7))
        print '</copts60>'


class DTTM(DOCDirStream):
    """The DTTM structure specifies date and time."""
    def __init__(self, parent, name):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos
        self.name = name

    def dump(self):
        buf = self.readuInt32()
        print '<%s type="DTTM" offset="%d" size="4 bytes">' % (self.name, self.pos)
        self.printAndSet("mint", buf & 0x0000003f)  # 1..6th bits
        self.printAndSet("hr", (buf & 0x000007c0) >> 6)  # 7..11th bits
        self.printAndSet("dom", (buf & 0x0000f800) >> 11)  # 12..16th bits
        self.printAndSet("mon", (buf & 0x000f0000) >> 16)  # 17..20th bits
        self.printAndSet("yr", (buf & 0x1ff00000) >> 20)  # 21..29th bits
        self.printAndSet("wdy", (buf & 0xe0000000) >> 29)  # 30..32th bits
        print '<transformed value="%s-%s-%s %s:%s"/>' % (1900 + self.yr, self.mon, self.dom, self.hr, self.mint)
        print '</%s>' % self.name
        self.parent.pos = self.pos


class GRFSTD(DOCDirStream):
    """The GRFSTD structure specifies the general properties of a style."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos

    def dump(self):
        print '<grfstd type="GRFSTD" offset="%d" size="2 bytes">' % self.pos
        buf = self.readuInt8()
        self.printAndSet("fAutoRedef", self.getBit(buf, 0))
        self.printAndSet("fHidden", self.getBit(buf, 1))
        self.printAndSet("f97LidsSet", self.getBit(buf, 2))
        self.printAndSet("fCopyLang", self.getBit(buf, 3))
        self.printAndSet("fPersonalCompose", self.getBit(buf, 4))
        self.printAndSet("fPersonalReply", self.getBit(buf, 5))
        self.printAndSet("fPersonal", self.getBit(buf, 6))
        self.printAndSet("fNoHtmlExport", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("fSemiHidden", self.getBit(buf, 0))
        self.printAndSet("fLocked", self.getBit(buf, 1))
        self.printAndSet("fInternalUse", self.getBit(buf, 2))
        self.printAndSet("fUnhideWhenUsed", self.getBit(buf, 3))
        self.printAndSet("fQFormat", self.getBit(buf, 4))
        self.printAndSet("fReserved", (buf & 0xe0) >> 5)  # 6..8th bits
        print '</grfstd>'
        self.parent.pos = self.pos


class DopBase(DOCDirStream):
    """The DopBase structure contains document and compatibility settings."""
    size = 84

    def __init__(self, dop):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop

    def dump(self):
        print '<dopBase offset="%d" size="%d bytes">' % (self.pos, 84)
        buf = self.readuInt8()
        self.printAndSet("fFacingPages", self.getBit(buf, 0))
        self.printAndSet("unused1", self.getBit(buf, 1))
        self.printAndSet("fPMHMainDoc", self.getBit(buf, 2))
        self.printAndSet("unused2", (buf & 0x18) >> 3)  # 4..5th bits
        self.printAndSet("fpc", (buf & 0x60) >> 5)  # 6..7th bits
        self.printAndSet("unused3", self.getBit(buf, 7))

        self.printAndSet("unused4", self.readuInt8())

        buf = self.readuInt16()
        self.printAndSet("rncFtn", buf & 0x03)  # 1..2nd bits
        self.printAndSet("nFtn", (buf & 0xfffc) >> 2)  # 3..16th bits

        buf = self.readuInt8()
        self.printAndSet("unused5", self.getBit(buf, 0))
        self.printAndSet("unused6", self.getBit(buf, 1))
        self.printAndSet("unused7", self.getBit(buf, 2))
        self.printAndSet("unused8", self.getBit(buf, 3))
        self.printAndSet("unused9", self.getBit(buf, 4))
        self.printAndSet("unused10", self.getBit(buf, 5))
        self.printAndSet("fSplAllDone", self.getBit(buf, 6))
        self.printAndSet("fSplAllClean", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("fSplHideErrors", self.getBit(buf, 0))
        self.printAndSet("fGramHideErrors", self.getBit(buf, 1))
        self.printAndSet("fLabelDoc", self.getBit(buf, 2))
        self.printAndSet("fHyphCapitals", self.getBit(buf, 3))
        self.printAndSet("fAutoHyphen", self.getBit(buf, 4))
        self.printAndSet("fFormNoFields", self.getBit(buf, 5))
        self.printAndSet("fLinkStyles", self.getBit(buf, 6))
        self.printAndSet("fRevMarking", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("unused11", self.getBit(buf, 0))
        self.printAndSet("fExactCWords", self.getBit(buf, 1))
        self.printAndSet("fPagHidden", self.getBit(buf, 2))
        self.printAndSet("fPagResults", self.getBit(buf, 3))
        self.printAndSet("fLockAtn", self.getBit(buf, 4))
        self.printAndSet("fMirrorMargins", self.getBit(buf, 5))
        self.printAndSet("fWord97Compat", self.getBit(buf, 6))
        self.printAndSet("unused12", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("unused13", self.getBit(buf, 0))
        self.printAndSet("fProtEnabled", self.getBit(buf, 1))
        self.printAndSet("fDispFormFldSel", self.getBit(buf, 2))
        self.printAndSet("fRMView", self.getBit(buf, 3))
        self.printAndSet("fRMPrint", self.getBit(buf, 4))
        self.printAndSet("fLockVbaProj", self.getBit(buf, 5))
        self.printAndSet("fLockRev", self.getBit(buf, 6))
        self.printAndSet("fEmbedFonts", self.getBit(buf, 7))

        copts60 = Copts60(self)
        copts60.dump()
        self.pos += 2

        self.printAndSet("dxaTab", self.readuInt16())
        self.printAndSet("cpgWebOpt", self.readuInt16())
        self.printAndSet("dxaHotZ", self.readuInt16())
        self.printAndSet("cConsecHypLim", self.readuInt16())
        self.printAndSet("wSpare2", self.readuInt16())
        DTTM(self, "dttmCreated").dump()
        DTTM(self, "dttmRevised").dump()
        DTTM(self, "dttmLastprint").dump()
        self.printAndSet("nRevision", self.readInt16())
        self.printAndSet("tmEdited", self.readInt32())
        self.printAndSet("cWords", self.readInt32())
        self.printAndSet("cCh", self.readInt32())
        self.printAndSet("cPg", self.readInt16())
        self.printAndSet("cParas", self.readInt32())

        buf = self.readuInt16()
        self.printAndSet("rncEdn", buf & 0x0003)  # 1..2nd bits
        self.printAndSet("nEdn", (buf & 0xfffc) >> 2)  # 3..16th bits

        buf = self.readuInt16()
        self.printAndSet("epc", buf & 0x0003)  # 1..2nd bits
        self.printAndSet("unused14", (buf & 0x003c) >> 2)  # 3..6th bits
        self.printAndSet("unused15", (buf & 0x03c0) >> 6)  # 7..10th bits
        self.printAndSet("fPrintFormData", self.getBit(buf, 10))
        self.printAndSet("fSaveFormData", self.getBit(buf, 11))
        self.printAndSet("fShadeFormData", self.getBit(buf, 12))
        self.printAndSet("fShadeMergeFields", self.getBit(buf, 13))
        self.printAndSet("reserved2", self.getBit(buf, 14))
        self.printAndSet("fIncludeSubdocsInStats", self.getBit(buf, 15))

        self.printAndSet("cLines", self.readInt32())
        self.printAndSet("cWordsWithSubdocs", self.readInt32())
        self.printAndSet("cChWithSubdocs", self.readInt32())
        self.printAndSet("cPgWithSubdocs", self.readInt16())
        self.printAndSet("cParasWithSubdocs", self.readInt32())
        self.printAndSet("cLinesWithSubdocs", self.readInt32())
        self.printAndSet("lKeyProtDoc", self.readInt32())

        buf = self.readuInt16()
        self.printAndSet("wvkoSaved", buf & 0x0007)  # 1..3rd bits
        self.printAndSet("pctWwdSaved", (buf & 0x0ff8) >> 3)  # 4..12th bits
        self.printAndSet("zkSaved", (buf & 0x3000) >> 12)  # 13..14th bits
        self.printAndSet("unused16", self.getBit(buf, 14))
        self.printAndSet("iGutterPos", self.getBit(buf, 15))
        print '</dopBase>'
        assert self.pos == self.dop.pos + DopBase.size
        self.dop.pos = self.pos


class Copts80(DOCDirStream):
    """The Copts80 structure specifies compatibility options."""
    def __init__(self, dop):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos

    def dump(self):
        print '<copts80 type="Copts80" offset="%d" size="4 bytes">' % self.pos
        Copts60(self).dump()
        self.pos += 2

        buf = self.readuInt8()
        self.printAndSet("fSuppressTopSpacingMac5", self.getBit(buf, 0))
        self.printAndSet("fTruncDxaExpand", self.getBit(buf, 1))
        self.printAndSet("fPrintBodyBeforeHdr", self.getBit(buf, 2))
        self.printAndSet("fNoExtLeading", self.getBit(buf, 3))
        self.printAndSet("fDontMakeSpaceForUL", self.getBit(buf, 4))
        self.printAndSet("fMWSmallCaps", self.getBit(buf, 5))
        self.printAndSet("f2ptExtLeadingOnly", self.getBit(buf, 6))
        self.printAndSet("fTruncFontHeight", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("fSubOnSize", self.getBit(buf, 0))
        self.printAndSet("fLineWrapLikeWord6", self.getBit(buf, 1))
        self.printAndSet("fWW6BorderRules", self.getBit(buf, 2))
        self.printAndSet("fExactOnTop", self.getBit(buf, 3))
        self.printAndSet("fExtraAfter", self.getBit(buf, 4))
        self.printAndSet("fWPSpace", self.getBit(buf, 5))
        self.printAndSet("fWPJust", self.getBit(buf, 6))
        self.printAndSet("fPrintMet", self.getBit(buf, 7))
        print '</copts80>'


class Copts(DOCDirStream):
    """A structure that specifies compatibility options."""
    size = 32

    def __init__(self, dop):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop

    def dump(self):
        print '<copts type="Copts" offset="%d" size="%d bytes">' % (self.pos, Copts.size)
        Copts80(self).dump()
        self.pos += 4

        buf = self.readuInt8()
        self.printAndSet("fSpLayoutLikeWW8", self.getBit(buf, 0))
        self.printAndSet("fFtnLayoutLikeWW8", self.getBit(buf, 1))
        self.printAndSet("fDontUseHTMLParagraphAutoSpacing", self.getBit(buf, 2))
        self.printAndSet("fDontAdjustLineHeightInTable", self.getBit(buf, 3))
        self.printAndSet("fForgetLastTabAlign", self.getBit(buf, 4))
        self.printAndSet("fUseAutospaceForFullWidthAlpha", self.getBit(buf, 5))
        self.printAndSet("fAlignTablesRowByRow", self.getBit(buf, 6))
        self.printAndSet("fLayoutRawTableWidth", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("fLayoutTableRowsApart", self.getBit(buf, 0))
        self.printAndSet("fUseWord97LineBreakingRules", self.getBit(buf, 1))
        self.printAndSet("fDontBreakWrappedTables", self.getBit(buf, 2))
        self.printAndSet("fDontSnapToGridInCell", self.getBit(buf, 3))
        self.printAndSet("fDontAllowFieldEndSelect", self.getBit(buf, 4))
        self.printAndSet("fApplyBreakingRules", self.getBit(buf, 5))
        self.printAndSet("fDontWrapTextWithPunct", self.getBit(buf, 6))
        self.printAndSet("fDontUseAsianBreakRules", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("fUseWord2002TableStyleRules", self.getBit(buf, 0))
        self.printAndSet("fGrowAutoFit", self.getBit(buf, 1))
        self.printAndSet("fUseNormalStyleForList", self.getBit(buf, 2))
        self.printAndSet("fDontUseIndentAsNumberingTabStop", self.getBit(buf, 3))
        self.printAndSet("fFELineBreak11", self.getBit(buf, 4))
        self.printAndSet("fAllowSpaceOfSameStyleInTable", self.getBit(buf, 5))
        self.printAndSet("fWW11IndentRules", self.getBit(buf, 6))
        self.printAndSet("fDontAutofitConstrainedTables", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("fAutofitLikeWW11", self.getBit(buf, 0))
        self.printAndSet("fUnderlineTabInNumList", self.getBit(buf, 1))
        self.printAndSet("fHangulWidthLikeWW11", self.getBit(buf, 2))
        self.printAndSet("fSplitPgBreakAndParaMark", self.getBit(buf, 3))
        self.printAndSet("fDontVertAlignCellWithSp", self.getBit(buf, 4))
        self.printAndSet("fDontBreakConstrainedForcedTables", self.getBit(buf, 5))
        self.printAndSet("fDontVertAlignInTxbx", self.getBit(buf, 6))
        self.printAndSet("fWord11KerningPairs", self.getBit(buf, 7))

        buf = self.readuInt32()
        self.printAndSet("fCachedColBalance", self.getBit(buf, 0))
        self.printAndSet("empty1", (buf & 0xfffffffe) >> 1)  # 2..32th bits
        self.printAndSet("empty2", self.readuInt32())
        self.printAndSet("empty3", self.readuInt32())
        self.printAndSet("empty4", self.readuInt32())
        self.printAndSet("empty5", self.readuInt32())
        self.printAndSet("empty6", self.readuInt32())
        print '</copts>'
        assert self.pos == self.dop.pos + Copts.size
        self.dop.pos = self.pos


class Dop95(DOCDirStream):
    """The Dop95 structure contains document and compatibility settings."""
    size = 88

    def __init__(self, dop, dopSize):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop
        self.dopSize = dopSize

    def dump(self):
        print '<dop95 type="Dop95" offset="%d" size="88 bytes">' % self.pos
        pos = self.pos
        dopBase = DopBase(self)
        dopBase.dump()
        if self.pos >= pos + self.dopSize:
            print '</dop95>'
            self.dop.pos = self.pos
            return
        Copts80(self).dump()
        self.pos += 4
        print '</dop95>'
        assert self.pos == self.dop.pos + Dop95.size
        self.dop.pos = self.pos


class DopTypography(DOCDirStream):
    """The DopTypography structure contains East Asian language typography settings."""
    size = 310

    def __init__(self, dop):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop

    def dump(self):
        print '<dopTypography type="DopTypography" offset="%d" size="310 bytes">' % self.pos
        buf = self.readuInt16()
        self.printAndSet("fKerningPunct", self.getBit(buf, 0))
        self.printAndSet("iJustification", (buf & 0x0006) >> 1)  # 2..3rd bits
        self.printAndSet("iLevelOfKinsoku", (buf & 0x0018) >> 1)  # 4..5th bits
        self.printAndSet("f2on1", self.getBit(buf, 5))
        self.printAndSet("unused", self.getBit(buf, 6))
        self.printAndSet("iCustomKsu", (buf & 0x0380) >> 7)  # 8..10th bits
        self.printAndSet("fJapaneseUseLevel2", self.getBit(buf, 10))
        self.printAndSet("reserved", (buf & 0xf800) >> 11)  # 12..16th bits

        self.printAndSet("cchFollowingPunct", self.readInt16())
        self.printAndSet("cchLeadingPunct", self.readInt16())

        self.printAndSet("rgxchFPunct", self.getString(self.cchFollowingPunct), hexdump=False)
        self.pos += 202

        self.printAndSet("rgxchLPunct", self.getString(self.cchLeadingPunct), hexdump=False)
        self.pos += 102

        print '</dopTypography>'
        assert self.pos == self.dop.pos + DopTypography.size
        self.dop.pos = self.pos


class Dogrid(DOCDirStream):
    """The Dogrid structure specifies parameters for the drawn object properties of the document."""
    size = 10

    def __init__(self, dop):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop

    def dump(self):
        print '<dogrid type="Dogrid" offset="%d" size="%d bytes">' % (self.pos, Dogrid.size)
        self.printAndSet("xaGrid", self.readuInt16())
        self.printAndSet("yaGrid", self.readuInt16())
        self.printAndSet("dxaGrid", self.readuInt16())
        self.printAndSet("dyaGrid", self.readuInt16())

        buf = self.readuInt8()
        self.printAndSet("dyGridDisplay", (buf & 0x7f))  # 1..7th bits
        self.printAndSet("unused", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("dxGridDisplay", (buf & 0x7f))  # 1..7th bits
        self.printAndSet("fFollowMargins", self.getBit(buf, 7))
        print '</dogrid>'
        assert self.pos == self.dop.pos + Dogrid.size
        self.dop.pos = self.pos


class Asumyi(DOCDirStream):
    """The Asumyi structure specifies AutoSummary state information"""
    def __init__(self, dop):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos

    def dump(self):
        print '<asumyi type="Asumyi" offset="%d" size="12 bytes">' % self.pos
        buf = self.readuInt16()
        self.printAndSet("fValid", self.getBit(buf, 0))
        self.printAndSet("fView", self.getBit(buf, 1))
        self.printAndSet("iViewBy", (buf & 0x0c) >> 2)  # 3..4th bits
        self.printAndSet("fUpdateProps", self.getBit(buf, 4))
        self.printAndSet("reserved", (buf & 0xffe0) >> 5)  # 6..16th bits

        self.printAndSet("wDlgLevel", self.readuInt16())
        self.printAndSet("lHighestLevel", self.readuInt32())
        self.printAndSet("lCurrentLevel", self.readuInt32())
        print '</asumyi>'


class Dop97(DOCDirStream):
    """The Dop97 structure contains document and compatibility settings."""
    size = 500

    def __init__(self, dop, dopSize):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop
        self.dopSize = dopSize

    def dump(self):
        print '<dop97 type="Dop97" offset="%d" size="%d bytes">' % (self.pos, Dop97.size)
        pos = self.pos
        dop95 = Dop95(self, self.dopSize)
        dop95.dump()
        if self.pos >= pos + self.dopSize:
            print '</dop97>'
            self.dop.pos = self.pos
            return

        self.printAndSet("adt", self.readuInt16())
        dopTypography = DopTypography(self)
        dopTypography.dump()
        dogrid = Dogrid(self)
        dogrid.dump()

        buf = self.readuInt8()
        self.printAndSet("unused1", self.getBit(buf, 0))
        self.printAndSet("lvlDop", (buf & 0x1e) >> 1)  # 2..5th bits
        self.printAndSet("fGramAllDone", self.getBit(buf, 5))
        self.printAndSet("fGramAllClean", self.getBit(buf, 6))
        self.printAndSet("fSubsetFonts", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("unused2", self.getBit(buf, 0))
        self.printAndSet("fHtmlDoc", self.getBit(buf, 1))
        self.printAndSet("fDiskLvcInvalid", self.getBit(buf, 2))
        self.printAndSet("fSnapBorder", self.getBit(buf, 3))
        self.printAndSet("fIncludeHeader", self.getBit(buf, 4))
        self.printAndSet("fIncludeFooter", self.getBit(buf, 5))
        self.printAndSet("unused3", self.getBit(buf, 6))
        self.printAndSet("unused4", self.getBit(buf, 7))

        self.printAndSet("unused5", self.readuInt16())
        Asumyi(self).dump()
        self.pos += 12
        self.printAndSet("cChWS", self.readuInt32())
        self.printAndSet("cChWSWithSubdocs", self.readuInt32())
        self.printAndSet("grfDocEvents", self.readuInt32())

        buf = self.readuInt32()
        self.printAndSet("fVirusPrompted", self.getBit(buf, 0))
        self.printAndSet("fVirusLoadSafe", self.getBit(buf, 1))
        self.printAndSet("KeyVirusSession30", (buf & 0xfffffffc) >> 2)

        self.printAndSet("space1", self.readuInt32())
        self.printAndSet("space2", self.readuInt32())
        self.printAndSet("space3", self.readuInt32())
        self.printAndSet("space4", self.readuInt32())
        self.printAndSet("space5", self.readuInt32())
        self.printAndSet("space6", self.readuInt32())
        self.printAndSet("space7", self.readuInt32())
        self.printAndSet("space8", self.readuInt16())

        self.printAndSet("cpMaxListCacheMainDoc", self.readuInt32())
        self.printAndSet("ilfoLastBulletMain", self.readuInt16())
        self.printAndSet("ilfoLastNumberMain", self.readuInt16())
        self.printAndSet("cDBC", self.readuInt32())
        self.printAndSet("cDBCWithSubdocs", self.readuInt32())
        self.printAndSet("reserved3a", self.readuInt32())
        self.printAndSet("nfcFtnRef", self.readuInt16())
        self.printAndSet("nfcEdnRef", self.readuInt16())
        self.printAndSet("hpsZoomFontPag", self.readuInt16())
        self.printAndSet("dywDispPag", self.readuInt16())
        print '</dop97>'
        assert self.pos == self.dop.pos + Dop97.size
        self.dop.pos = self.pos


class Dop2000(DOCDirStream):
    """The Dop2000 structure contains document and compatibility settings."""
    size = 544

    def __init__(self, dop, dopSize):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop
        self.dopSize = dopSize

    def dump(self):
        print '<dop2000 type="Dop2000" offset="%d" size="544 bytes">' % self.pos
        dop97 = Dop97(self, self.dopSize)
        dop97.dump()

        if self.pos == self.size:
            print '<info what="Dop2000 size is smaller than expected."/>'
            print '</dop2000>'
            self.dop.pos = self.pos
            return

        self.printAndSet("ilvlLastBulletMain", self.readuInt8())
        self.printAndSet("ilvlLastNumberMain", self.readuInt8())
        self.printAndSet("istdClickParaType", self.readuInt16())

        buf = self.readuInt8()
        self.printAndSet("fLADAllDone", self.getBit(buf, 0))
        self.printAndSet("fEnvelopeVis", self.getBit(buf, 1))
        self.printAndSet("fMaybeTentativeListInDoc", self.getBit(buf, 2))
        self.printAndSet("fMaybeFitText", self.getBit(buf, 3))
        self.printAndSet("empty1", (buf & 0xf0) >> 4)  # 5..8th bits

        buf = self.readuInt8()
        self.printAndSet("fFCCAllDone", self.getBit(buf, 0))
        self.printAndSet("fRelyOnCSS_WebOpt", self.getBit(buf, 1))
        self.printAndSet("fRelyOnVML_WebOpt", self.getBit(buf, 2))
        self.printAndSet("fAllowPNG_WebOpt", self.getBit(buf, 3))
        self.printAndSet("screenSize_WebOpt", (buf & 0xf0) >> 4)  # 5..8th bits

        buf = self.readuInt16()
        self.printAndSet("fOrganizeInFolder_WebOpt", self.getBit(buf, 0))
        self.printAndSet("fUseLongFileNames_WebOpt", self.getBit(buf, 1))
        self.printAndSet("iPixelsPerInch_WebOpt", (buf & 0x0ffc) >> 2)  # 3..12th bits
        self.printAndSet("fWebOptionsInit", self.getBit(buf, 12))
        self.printAndSet("fMaybeFEL", self.getBit(buf, 12))
        self.printAndSet("fCharLineUnits", self.getBit(buf, 12))
        self.printAndSet("unused1", self.getBit(buf, 12))

        copts = Copts(self)
        copts.dump()

        self.printAndSet("verCompatPre10", self.readuInt16())
        buf = self.readuInt8()
        self.printAndSet("fNoMargPgvwSaved", self.getBit(buf, 0))
        self.printAndSet("unused2", self.getBit(buf, 1))
        self.printAndSet("unused3", self.getBit(buf, 2))
        self.printAndSet("unused4", self.getBit(buf, 3))
        self.printAndSet("fBulletProofed", self.getBit(buf, 4))
        self.printAndSet("empty2", self.getBit(buf, 5))
        self.printAndSet("fSaveUim", self.getBit(buf, 6))
        self.printAndSet("fFilterPrivacy", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("empty3", self.getBit(buf, 0))
        self.printAndSet("fSeenRepairs", self.getBit(buf, 1))
        self.printAndSet("fHasXML", self.getBit(buf, 2))
        self.printAndSet("unused5", self.getBit(buf, 3))
        self.printAndSet("fValidateXML", self.getBit(buf, 4))
        self.printAndSet("fSaveInvalidXML", self.getBit(buf, 5))
        self.printAndSet("fShowXMLErrors", self.getBit(buf, 6))
        self.printAndSet("fAlwaysMergeEmptyNamespace", self.getBit(buf, 7))
        print '</dop2000>'
        assert self.pos == self.dop.pos + Dop2000.size
        self.dop.pos = self.pos


class Dop2002(DOCDirStream):
    """The Dop2002 structure contains document and compatibility settings."""
    size = 594

    def __init__(self, dop, dopSize):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop
        self.dopSize = dopSize

    def dump(self):
        print '<dop2002 type="Dop2002" offset="%d" size="%d bytes">' % (self.pos, Dop2002.size)
        dop2000 = Dop2000(self, self.dopSize)
        dop2000.dump()

        self.printAndSet("unused", self.readuInt32())

        buf = self.readuInt8()
        self.printAndSet("fDoNotEmbedSystemFont", self.getBit(buf, 0))
        self.printAndSet("fWordCompat", self.getBit(buf, 1))
        self.printAndSet("fLiveRecover", self.getBit(buf, 2))
        self.printAndSet("fEmbedFactoids", self.getBit(buf, 3))
        self.printAndSet("fFactoidXML", self.getBit(buf, 4))
        self.printAndSet("fFactoidAllDone", self.getBit(buf, 5))
        self.printAndSet("fFolioPrint", self.getBit(buf, 6))
        self.printAndSet("fReverseFolio", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("iTextLineEnding", (buf & 0x7))  # 1..3rd bits
        self.printAndSet("fHideFcc", self.getBit(buf, 3))
        self.printAndSet("fAcetateShowMarkup", self.getBit(buf, 4))
        self.printAndSet("fAcetateShowAtn", self.getBit(buf, 5))
        self.printAndSet("fAcetateShowInsDel", self.getBit(buf, 6))
        self.printAndSet("fAcetateShowProps", self.getBit(buf, 7))

        self.printAndSet("istdTableDflt", self.readuInt16())
        self.printAndSet("verCompat", self.readuInt16())
        self.printAndSet("grfFmtFilter", self.readuInt16())
        self.printAndSet("iFolioPages", self.readuInt16())
        self.printAndSet("cpgText", self.readuInt32())
        self.printAndSet("cpMinRMText", self.readuInt32())
        self.printAndSet("cpMinRMFtn", self.readuInt32())
        self.printAndSet("cpMinRMHdd", self.readuInt32())
        self.printAndSet("cpMinRMAtn", self.readuInt32())
        self.printAndSet("cpMinRMEdn", self.readuInt32())
        self.printAndSet("cpMinRmTxbx", self.readuInt32())
        self.printAndSet("cpMinRmHdrTxbx", self.readuInt32())
        self.printAndSet("rsidRoot", self.readuInt32())
        print '</dop2002>'
        assert self.pos == self.dop.pos + Dop2002.size
        self.dop.pos = self.pos


class Dop2003(DOCDirStream):
    """The Dop2003 structure contains document and compatibility settings."""
    size = 616

    def __init__(self, dop, dopSize):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop
        self.dopSize = dopSize

    def dump(self):
        print '<dop2003 type="Dop2003" offset="%d" size="616 bytes">' % self.pos
        dop2002 = Dop2002(self, self.dopSize)
        dop2002.dump()

        buf = self.readuInt8()
        self.printAndSet("fTreatLockAtnAsReadOnly", self.getBit(buf, 0))
        self.printAndSet("fStyleLock", self.getBit(buf, 1))
        self.printAndSet("fAutoFmtOverride", self.getBit(buf, 2))
        self.printAndSet("fRemoveWordML", self.getBit(buf, 3))
        self.printAndSet("fApplyCustomXForm", self.getBit(buf, 4))
        self.printAndSet("fStyleLockEnforced", self.getBit(buf, 5))
        self.printAndSet("fFakeLockAtn", self.getBit(buf, 6))
        self.printAndSet("fIgnoreMixedContent", self.getBit(buf, 7))

        buf = self.readuInt8()
        self.printAndSet("fShowPlaceholderText", self.getBit(buf, 0))
        self.printAndSet("unused", self.getBit(buf, 1))
        self.printAndSet("fWord97Doc", self.getBit(buf, 2))
        self.printAndSet("fStyleLockTheme", self.getBit(buf, 3))
        self.printAndSet("fStyleLockQFSet", self.getBit(buf, 4))
        self.printAndSet("empty1", (buf & 0xe0) >> 5)  # 6..8th bits
        self.printAndSet("empty1_", self.readuInt16())

        buf = self.readuInt8()
        self.printAndSet("fReadingModeInkLockDown", self.getBit(buf, 0))
        self.printAndSet("fAcetateShowInkAtn", self.getBit(buf, 1))
        self.printAndSet("fFilterDttm", self.getBit(buf, 2))
        self.printAndSet("fEnforceDocProt", self.getBit(buf, 3))
        self.printAndSet("iDocProtCur", (buf & 0x70) >> 4)  # 5..7th bits
        self.printAndSet("fDispBkSpSaved", self.getBit(buf, 7))

        self.printAndSet("empty2", self.readuInt8())
        self.printAndSet("dxaPageLock", self.readuInt32())
        self.printAndSet("dyaPageLock", self.readuInt32())
        self.printAndSet("pctFontLock", self.readuInt32())
        self.printAndSet("grfitbid", self.readuInt8())
        self.printAndSet("empty3", self.readuInt8())
        self.printAndSet("ilfoMacAtCleanup", self.readuInt16())
        print '</dop2003>'
        assert self.pos == self.dop.pos + Dop2003.size
        self.dop.pos = self.pos


class DopMth(DOCDirStream):
    """The DopMth structure specifies document-wide math settings."""
    def __init__(self, dop):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos

    def dump(self):
        print '<dopMth type="DopMth" offset="%d" size="34 bytes">' % self.pos
        buf = self.readuInt32()
        self.printAndSet("mthbrk", (buf & 0x03))  # 1..2nd bits
        self.printAndSet("mthbrkSub", (buf & 0xc) >> 2)  # 3..4th bits
        self.printAndSet("mthbpjc", (buf & 0x70) >> 4)  # 5..7th bits
        self.printAndSet("reserved1", self.getBit(buf, 7))
        self.printAndSet("fMathSmallFrac", self.getBit(buf, 8))
        self.printAndSet("fMathIntLimUndOvr", self.getBit(buf, 9))
        self.printAndSet("fMathNaryLimUndOvr", self.getBit(buf, 10))
        self.printAndSet("fMathWrapAlignLeft", self.getBit(buf, 11))
        self.printAndSet("fMathUseDispDefaults", self.getBit(buf, 12))
        self.printAndSet("reserved2", (buf & 0xffffe000) >> 13)  # 14..32th bits

        self.printAndSet("ftcMath", self.readuInt16())
        self.printAndSet("dxaLeftMargin", self.readuInt32())
        self.printAndSet("dxaRightMargin", self.readuInt32())
        self.printAndSet("empty1", self.readuInt32())
        self.printAndSet("empty2", self.readuInt32())
        self.printAndSet("empty3", self.readuInt32())
        self.printAndSet("empty4", self.readuInt32())
        self.printAndSet("dxaIndentWrapped", self.readuInt32())
        print '</dopMth>'


class Dop2007(DOCDirStream):
    """The Dop2007 structure contains document and compatibility settings."""
    def __init__(self, dop, dopSize):
        DOCDirStream.__init__(self, dop.bytes)
        self.pos = dop.pos
        self.dop = dop
        self.dopSize = dopSize

    def dump(self):
        print '<dop2007 type="Dop2007" offset="%d">' % self.pos
        dop2003 = Dop2003(self, self.dopSize)
        dop2003.dump()

        self.printAndSet("reserved1", self.readuInt32())

        buf = self.readuInt16()
        self.printAndSet("fRMTrackFormatting", self.getBit(buf, 0))
        self.printAndSet("fRMTrackMoves", self.getBit(buf, 1))
        self.printAndSet("reserved2", self.getBit(buf, 2))
        self.printAndSet("empty1", self.getBit(buf, 3))
        self.printAndSet("empty2", self.getBit(buf, 4))
        self.printAndSet("ssm", (buf & 0x01e0) >> 5)  # 6..9th bits
        self.printAndSet("fReadingModeInkLockDownActualPage", self.getBit(buf, 9))
        self.printAndSet("fAutoCompressPictures", self.getBit(buf, 10))
        self.printAndSet("reserved3", (buf & 0xf800) >> 11)  # 12..16th bits
        self.printAndSet("reserved3_", self.readuInt16())

        self.printAndSet("empty3", self.readuInt32())
        self.printAndSet("empty4", self.readuInt32())
        self.printAndSet("empty5", self.readuInt32())
        self.printAndSet("empty6", self.readuInt32())
        DopMth(self).dump()
        self.pos += 34
        print '</dop2007>'


class RC4EncryptionHeader(DOCDirStream):
    """The encryption header structure used for RC4 encryption."""
    def __init__(self, fib, pos, size):
        DOCDirStream.__init__(self, fib.getTableStream().bytes)
        self.fib = fib
        self.pos = pos
        self.size = size

    def dump(self):
        print '<RC4EncryptionHeader>'
        self.Salt = self.readBytes(16)
        print '<Salt value="%s"/>' % globals.encodeName(self.Salt)
        self.EncryptedVerifier = self.readBytes(16)
        print '<EncryptedVerifier value="%s"/>' % globals.encodeName(self.EncryptedVerifier)
        self.EncryptedVerifierHash = self.readBytes(16)
        print '<EncryptedVerifierHash value="%s"/>' % globals.encodeName(self.EncryptedVerifierHash)
        print '</RC4EncryptionHeader>'
        assert self.pos == self.size


class Dop(DOCDirStream):
    """The Dop structure contains the document and compatibility settings for the document."""
    def __init__(self, fib):
        DOCDirStream.__init__(self, fib.getTableStream().bytes)
        self.pos = fib.fcDop
        self.size = fib.lcbDop
        self.fib = fib

    def dump(self):
        print '<dop type="Dop" offset="%s" size="%d bytes">' % (self.pos, self.size)
        if self.fib.nFibNew == 0:
            Dop97(self, self.size).dump()
        elif self.fib.nFibNew == 0x00d9:
            Dop2000(self, self.size).dump()
        elif self.fib.nFibNew == 0x0101:
            Dop2002(self, self.size).dump()
        elif self.fib.nFibNew == 0x0112:
            Dop2007(self, self.size).dump()
        else:
            print """<todo what="Dop.dump() doesn't know how to handle nFibNew = %s"/>""" % hex(self.fib.nFibNew)
        print '</dop>'


class FFID(DOCDirStream):
    """The FFID structure specifies the font family and character pitch for a font."""
    def __init__(self, bytes, offset):
        DOCDirStream.__init__(self, bytes)
        self.pos = offset

    def dump(self):
        self.ffid = self.readuInt8()

        self.prq = (self.ffid & 0x3)  # first two bits
        self.fTrueType = (self.ffid & 0x4) >> 2  # 3rd bit
        self.unused1 = (self.ffid & 0x8) >> 3  # 4th bit
        self.ff = (self.ffid & 0x70) >> 4  # 5-7th bits
        self.unused2 = (self.ffid & 0x80) >> 7  # 8th bit

        print '<ffid value="%s" prq="%s" fTrueType="%s" ff="%s"/>' % (hex(self.ffid), hex(self.prq), self.fTrueType, hex(self.ff))


class PANOSE(DOCDirStream):
    """The PANOSE structure defines the PANOSE font classification values for a TrueType font."""
    def __init__(self, bytes, offset):
        DOCDirStream.__init__(self, bytes)
        self.pos = offset

    def dump(self):
        print '<panose type="PANOSE" offset="%s" size="10 bytes">' % self.pos
        for i in ["bFamilyType", "bSerifStyle", "bWeight", "bProportion", "bContrast", "bStrokeVariation", "bArmStyle", "bLetterform", "bMidline", "bHeight"]:
            self.printAndSet(i, self.readuInt8())
        print '</panose>'


class FontSignature(DOCDirStream):
    """Contains information identifying the code pages and Unicode subranges for which a given font provides glyphs."""
    def __init__(self, bytes, offset):
        DOCDirStream.__init__(self, bytes)
        self.pos = offset

    def dump(self):
        fsUsb1 = self.readuInt32()
        fsUsb2 = self.readuInt32()
        fsUsb3 = self.readuInt32()
        fsUsb4 = self.readuInt32()
        fsCsb1 = self.readuInt32()
        fsCsb2 = self.readInt32()
        print '<fontSignature fsUsb1="%s" fsUsb2="%s" fsUsb3="%s" fsUsb4="%s" fsCsb1="%s" fsCsb2="%s"/>' % (
            hex(fsUsb1), hex(fsUsb2), hex(fsUsb3), hex(fsUsb4), hex(fsCsb1), hex(fsCsb2)
        )


class FFN(DOCDirStream):
    """The FFN structure specifies information about a font that is used in the document."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<ffn type="FFN" offset="%d" size="%d bytes">' % (self.pos, self.size)
        FFID(self.bytes, self.pos).dump()
        self.pos += 1
        self.printAndSet("wWeight", self.readInt16(), hexdump=False)
        self.printAndSet("chs", self.readuInt8(), hexdump=False)
        self.printAndSet("ixchSzAlt", self.readuInt8())
        PANOSE(self.bytes, self.pos).dump()
        self.pos += 10
        FontSignature(self.bytes, self.pos).dump()
        self.pos += 24
        print '<xszFfn value="%s"/>' % self.readString()
        print '</ffn>'


class SttbfFfn(DOCDirStream):
    """The SttbfFfn structure is an STTB whose strings are FFN records that specify details of system fonts."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<sttbfFfn type="SttbfFfn" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("cData", self.readuInt16())
        self.printAndSet("cbExtra", self.readuInt16())
        for i in range(self.cData):
            cchData = self.readuInt8()
            print '<cchData index="%d" offset="%d" size="%d bytes">' % (i, self.pos, cchData)
            FFN(self.bytes, self.mainStream, self.pos, cchData).dump()
            self.pos += cchData
            print '</cchData>'
        print '</sttbfFfn>'


class GrpXstAtnOwners(DOCDirStream):
    """This array contains the names of authors of comments in the document."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes)
        self.pos = mainStream.fcGrpXstAtnOwners
        self.size = mainStream.lcbGrpXstAtnOwners
        self.mainStream = mainStream

    def dump(self):
        posOrig = self.pos
        print '<grpXstAtnOwners type="GrpXstAtnOwners" offset="%d" size="%d bytes">' % (self.pos, self.size)
        while self.pos < posOrig + self.size:
            xst = Xst(self)
            xst.dump()
            self.pos = xst.pos
        print '</grpXstAtnOwners>'


class SttbfAssoc(DOCDirStream):
    """The SttbfAssoc structure is an STTB that contains strings which are associated with this document."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes)
        self.pos = mainStream.fcSttbfAssoc
        self.size = mainStream.lcbSttbfAssoc
        self.mainStream = mainStream

    def dump(self):
        indexMap = {
            0x00: "Unused. MUST be ignored.",
            0x01: "The path of the associated document template (2), if it is not the default Normal template.",
            0x02: "The title of the document.",
            0x03: "The subject of the document.",
            0x04: "Key words associated with the document.",
            0x05: "Unused. This index MUST be ignored.",
            0x06: "The author of the document.",
            0x07: "The user who last revised the document.",
            0x08: "The path of the associated mail merge data source.",
            0x09: "The path of the associated mail merge header document.",
            0x0A: "Unused. This index MUST be ignored.",
            0x0B: "Unused. This index MUST be ignored.",
            0x0C: "Unused. This index MUST be ignored.",
            0x0D: "Unused. This index MUST be ignored.",
            0x0E: "Unused. This index MUST be ignored.",
            0x0F: "Unused. This index MUST be ignored.",
            0x10: "Unused. This index MUST be ignored.",
            0x11: "The write-reservation password of the document.",
        }
        print '<sttbfAssoc type="SttbfAssoc" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("fExtend", self.readuInt16())
        self.printAndSet("cData", self.readuInt16())
        self.printAndSet("cbExtra", self.readuInt16())
        for i in range(self.cData):
            cchData = self.readuInt16()
            if i in indexMap.keys():
                meaning = indexMap[i]
            else:
                meaning = "unknown"
            if self.pos + 2 * cchData > self.size:
                self.cData = 0
                print '<info what="SttbfAssoc::dump() wanted to read beyond the end of the stream"/>'
                break
            print '<cchData index="%s" meaning="%s" offset="%d" size="%d bytes">' % (hex(i), meaning, self.pos, cchData)
            print '<string value="%s"/>' % globals.encodeName(self.bytes[self.pos:self.pos + 2 * cchData].decode('utf-16'), lowOnly=True)
            self.pos += 2 * cchData
            print '</cchData>'
        # Probably this was cleared manually.
        if self.cData != 0:
            assert self.pos == self.mainStream.fcSttbfAssoc + self.size
        print '</sttbfAssoc>'


class SttbfRMark(DOCDirStream):
    """The SttbfRMark structure is an STTB structure where the strings specify the names of the authors of the revision marks, comments, and e-mail messages in the document."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes)
        self.pos = mainStream.fcSttbfRMark
        self.size = mainStream.lcbSttbfRMark
        self.mainStream = mainStream

    def dump(self):
        print '<sttbfRMark type="SttbfRMark" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("fExtend", self.readuInt16())
        self.printAndSet("cData", self.readuInt16())
        self.printAndSet("cbExtra", self.readuInt16())
        for i in range(self.cData):
            cchData = self.readuInt16()
            print '<cchData index="%s" offset="%d" size="%d bytes">' % (i, self.pos, cchData)
            print '<string value="%s"/>' % globals.encodeName(self.bytes[self.pos:self.pos + 2 * cchData].decode('utf-16'), lowOnly=True)
            self.pos += 2 * cchData
            print '</cchData>'
        if self.cData != 0:
            assert self.pos == self.mainStream.fcSttbfRMark + self.size
        print '</sttbfRMark>'


class OfficeArtWordDrawing(DOCDirStream):
    """The OfficeArtWordDrawing structure specifies information about the drawings in the document."""
    def __init__(self, officeArtContent):
        DOCDirStream.__init__(self, officeArtContent.bytes)
        self.pos = officeArtContent.pos
        self.officeArtContent = officeArtContent

    def dump(self):
        print '<officeArtWordDrawing type="OfficeArtWordDrawing" pos="%d">' % self.pos
        self.printAndSet("dgglbl", self.readuInt8())
        msodraw.DgContainer(self, "container").dumpXml(self, getWordModel(self.officeArtContent.mainStream))
        print '</officeArtWordDrawing>'
        self.officeArtContent.pos = self.pos


class OfficeArtContent(DOCDirStream):
    """The OfficeArtContent structure specifies information about a drawing in the document."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes)
        self.pos = mainStream.fcDggInfo
        self.size = mainStream.lcbDggInfo
        self.mainStream = mainStream

    def dump(self):
        print '<officeArtContent type="OfficeArtContent" offset="%d" size="%d bytes">' % (self.pos, self.size)
        msodraw.DggContainer(self, "DrawingGroupData").dumpXml(self, getWordModel(self.mainStream))
        print '<Drawings type="main" offset="%d">' % self.pos
        OfficeArtWordDrawing(self).dump()
        print '</Drawings>'
        if self.pos < self.mainStream.fcDggInfo + self.size:
            print '<Drawings type="header" offset="%d">' % self.pos
            OfficeArtWordDrawing(self).dump()
            print '</Drawings>'
        assert self.pos == self.mainStream.fcDggInfo + self.size
        print '</officeArtContent>'


class ATNBE(DOCDirStream):
    """The ATNBE structure contains information about an annotation bookmark in the document."""
    size = 10  # in bytes, see 2.9.4

    def __init__(self, sttbfAtnBkmk):
        DOCDirStream.__init__(self, sttbfAtnBkmk.bytes)
        self.pos = sttbfAtnBkmk.pos

    def dump(self):
        print '<atnbe type="ATNBE">'
        self.printAndSet("bmc", self.readuInt16())
        self.printAndSet("ITag", self.readuInt32())
        self.printAndSet("ITagOld", self.readuInt32())
        print '</atnbe>'


class SttbfAtnBkmk(DOCDirStream):
    """The SttbfAtnBkmk structure is an STTB whose strings are all of zero length."""
    def __init__(self, mainStream, offset, size):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<sttbfAtnBkmk type="SttbfAtnBkmk" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("fExtended", self.readuInt16())
        self.printAndSet("cData", self.readuInt16())
        self.printAndSet("cbExtra", self.readuInt16())
        for i in range(self.cData):
            cchData = self.readuInt16()
            print '<cchData index="%d" offset="%d" size="%d bytes"/>' % (i, self.pos, cchData)
            print '<extraData index="%d" offset="%d" size="%d bytes">' % (i, self.pos, ATNBE.size)
            atnbe = ATNBE(self)
            atnbe.dump()
            self.pos += ATNBE.size
            print '</extraData>'
        print '</sttbfAtnBkmk>'


class Stshif(DOCDirStream):
    """The Stshif structure specifies general stylesheet information."""
    def __init__(self, bytes, mainStream, offset):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = 18

    def dump(self):
        print '<stshif type="Stshif" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("cstd", self.readuInt16())
        self.printAndSet("cbSTDBaseInFile", self.readuInt16())
        buf = self.readuInt16()
        self.printAndSet("fStdStylenamesWritten", buf & 1)  # first bit
        self.printAndSet("fReserved", (buf & 0xfe) >> 1)  # 2..16th bits
        self.printAndSet("stiMaxWhenSaved", self.readuInt16())
        self.printAndSet("istdMaxFixedWhenSaved", self.readuInt16())
        self.printAndSet("nVerBuiltInNamesWhenSaved", self.readuInt16())
        self.printAndSet("ftcAsci", self.readuInt16())
        self.printAndSet("ftcFE", self.readuInt16())
        self.printAndSet("ftcOther", self.readuInt16())
        print '</stshif>'


class LSD(DOCDirStream):
    """The LSD structure specifies the properties to be used for latent application-defined styles (see StshiLsd) when they are created."""
    def __init__(self, bytes, offset):
        DOCDirStream.__init__(self, bytes)
        self.pos = offset

    def dump(self):
        buf = self.readuInt16()
        self.printAndSet("fLocked", self.getBit(buf, 1))
        self.printAndSet("fSemiHidden", self.getBit(buf, 2))
        self.printAndSet("fUnhideWhenUsed", self.getBit(buf, 3))
        self.printAndSet("fQFormat", self.getBit(buf, 4))
        self.printAndSet("iPriority", (buf & 0xfff0) >> 4)  # 5-16th bits
        self.printAndSet("fReserved", self.readuInt16())


class StshiLsd(DOCDirStream):
    """The StshiLsd structure specifies latent style data for application-defined styles."""
    def __init__(self, bytes, stshi, offset):
        DOCDirStream.__init__(self, bytes)
        self.stshi = stshi
        self.pos = offset

    def dump(self):
        print '<stshiLsd type="StshiLsd" offset="%d">' % (self.pos)
        self.printAndSet("cbLSD", self.readuInt16())
        for i in range(self.stshi.stshif.stiMaxWhenSaved):
            print '<mpstiilsd index="%d" type="LSD">' % i
            LSD(self.bytes, self.pos).dump()
            print '</mpstiilsd>'
            self.pos += self.cbLSD
        print '</stshiLsd>'


class STSHI(DOCDirStream):
    """The STSHI structure specifies general stylesheet and related information."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<stshi type="STSHI" offset="%d" size="%d bytes">' % (self.pos, self.size)
        posOrig = self.pos
        self.stshif = Stshif(self.bytes, self.mainStream, self.pos)
        self.stshif.dump()
        self.pos += self.stshif.size
        if self.pos - posOrig < self.size:
            self.printAndSet("ftcBi", self.readuInt16())
            if self.pos - posOrig < self.size:
                stshiLsd = StshiLsd(self.bytes, self, self.pos)
                stshiLsd.dump()
        print '</stshi>'


class LPStshi(DOCDirStream):
    """The LPStshi structure specifies general stylesheet information."""
    def __init__(self, bytes, mainStream, offset):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset

    def dump(self):
        print '<lpstshi type="LPStshi" offset="%d">' % self.pos
        self.printAndSet("cbStshi", self.readuInt16(), hexdump=False)
        self.stshi = STSHI(self.bytes, self.mainStream, self.pos, self.cbStshi)
        self.stshi.dump()
        self.pos += self.cbStshi
        print '</lpstshi>'


class StdfBase(DOCDirStream):
    """The Stdf structure specifies general information about the style."""
    def __init__(self, bytes, mainStream, offset):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = 10

    def dump(self):
        print '<stdfBase type="StdfBase" offset="%d" size="%d bytes">' % (self.pos, self.size)
        buf = self.readuInt16()
        self.printAndSet("sti", buf & 0x0fff)  # 1..12th bits
        self.printAndSet("fScratch", self.getBit(buf, 13))
        self.printAndSet("fInvalHeight", self.getBit(buf, 14))
        self.printAndSet("fHasUpe", self.getBit(buf, 15))
        self.printAndSet("fMassCopy", self.getBit(buf, 16))
        buf = self.readuInt16()
        self.stk = buf & 0x000f  # 1..4th bits
        stkmap = {
            1: "paragraph",
            2: "character",
            3: "table",
            4: "numbering"
        }
        print '<stk value="%d" name="%s"/>' % (self.stk, stkmap[self.stk])
        self.printAndSet("istdBase", (buf & 0xfff0) >> 4)  # 5..16th bits
        buf = self.readuInt16()
        self.printAndSet("cupx", buf & 0x000f)  # 1..4th bits
        self.printAndSet("istdNext", (buf & 0xfff0) >> 4)  # 5..16th bits
        self.printAndSet("bchUpe", self.readuInt16(), hexdump=False)
        GRFSTD(self).dump()
        print '</stdfBase>'


class StdfPost2000(DOCDirStream):
    """The StdfPost2000 structure specifies general information about a style."""
    def __init__(self, stdf):
        DOCDirStream.__init__(self, stdf.bytes, mainStream=stdf.mainStream)
        self.pos = stdf.pos
        self.size = 8

    def dump(self):
        print '<stdfPost2000 type="StdfPost2000" offset="%d" size="%d bytes">' % (self.pos, self.size)
        buf = self.readuInt16()
        self.printAndSet("istdLink", buf & 0xfff)  # 1..12th bits
        self.printAndSet("fHasOriginalStyle", self.getBit(buf, 13))  # 13th bit
        self.printAndSet("fSpare", (buf & 0xe000) >> 13)  # 14..16th bits
        self.printAndSet("rsid", self.readuInt32())
        buf = self.readuInt16()
        self.printAndSet("iftcHtml", buf & 0x7)  # 1..3rd bits
        self.printAndSet("unused", self.getBit(buf, 4))
        self.printAndSet("iPriority", (buf & 0xfff0) >> 4)  # 5..16th bits
        print '</stdfPost2000>'


class Stdf(DOCDirStream):
    """The Stdf structure specifies general information about the style."""
    def __init__(self, std):
        DOCDirStream.__init__(self, std.bytes, mainStream=std.mainStream)
        self.std = std
        self.pos = std.pos

    def dump(self):
        print '<stdf type="Stdf" offset="%d">' % self.pos
        self.stdfBase = StdfBase(self.bytes, self.mainStream, self.pos)
        self.stdfBase.dump()
        self.pos += self.stdfBase.size
        if self.pos - self.std.pos < self.std.size:
            stsh = self.std.lpstd.stsh  # root of the stylesheet table
            cbSTDBaseInFile = stsh.lpstshi.stshi.stshif.cbSTDBaseInFile
            print '<stdfPost2000OrNone cbSTDBaseInFile="%s">' % hex(cbSTDBaseInFile)
            if cbSTDBaseInFile == 0x0012:
                stdfPost2000 = StdfPost2000(self)
                stdfPost2000.dump()
                self.pos = stdfPost2000.pos
            print '</stdfPost2000OrNone>'
        print '</stdf>'


class Xst(DOCDirStream):
    """The Xst structure is a string. The string is prepended by its length and is not null-terminated."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos

    def dump(self):
        print '<xst type="Xst" offset="%d">' % self.pos
        self.printAndSet("cch", self.readuInt16())
        lowOnly = locale.getdefaultlocale()[1] == "UTF-8"
        print '<rgtchar value="%s"/>' % globals.encodeName(self.bytes[self.pos:self.pos + 2 * self.cch].decode('utf-16'), lowOnly=lowOnly)
        self.pos += 2 * self.cch
        print '</xst>'


class Xstz(DOCDirStream):
    """The Xstz structure is a string. The string is prepended by its length and is null-terminated."""
    def __init__(self, parent, name="xstz"):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.name = name

    def dump(self):
        print '<%s type="Xstz" offset="%d">' % (self.name, self.pos)
        xst = Xst(self)
        xst.dump()
        self.pos = xst.pos
        self.printAndSet("chTerm", self.readuInt16())
        print '</%s>' % self.name


class UpxPapx(DOCDirStream):
    """The UpxPapx structure specifies the paragraph formatting properties that differ from the parent"""
    def __init__(self, lPUpxPapx):
        DOCDirStream.__init__(self, lPUpxPapx.bytes)
        self.lPUpxPapx = lPUpxPapx
        self.pos = lPUpxPapx.pos

    def dump(self):
        print '<upxPapx type="UpxPapx" offset="%d">' % self.pos
        self.printAndSet("istd", self.readuInt16())
        size = self.lPUpxPapx.cbUpx - 2
        pos = 0
        print '<grpprlPapx offset="%d" size="%d bytes">' % (self.pos, size)
        while size - pos > 0:
            prl = Prl(self, self.pos + pos)
            prl.dump()
            pos += prl.getSize()
        print '</grpprlPapx>'
        print '</upxPapx>'


class UpxChpx(DOCDirStream):
    """The UpxChpx structure specifies the character formatting properties that differ from the parent"""
    def __init__(self, lPUpxChpx):
        DOCDirStream.__init__(self, lPUpxChpx.bytes)
        self.lPUpxChpx = lPUpxChpx
        self.pos = lPUpxChpx.pos

    def dump(self):
        print '<upxChpx type="UpxChpx" offset="%d">' % self.pos
        size = self.lPUpxChpx.cbUpx
        pos = 0
        print '<grpprlChpx offset="%d" size="%d bytes">' % (self.pos, size)
        while size - pos > 0:
            prl = Prl(self, self.pos + pos)
            prl.dump()
            pos += prl.getSize()
        print '</grpprlChpx>'
        print '</upxChpx>'


class UpxTapx(DOCDirStream):
    """The UpxTapx structure specifies the table formatting properties that differ from the parent"""
    def __init__(self, lPUpxTapx):
        DOCDirStream.__init__(self, lPUpxTapx.bytes)
        self.lPUpxTapx = lPUpxTapx
        self.pos = lPUpxTapx.pos

    def dump(self):
        print '<upxTapx type="UpxTapx" offset="%d">' % self.pos
        size = self.lPUpxTapx.cbUpx
        pos = 0
        print '<grpprlTapx offset="%d" size="%d bytes">' % (self.pos, size)
        while size - pos > 0:
            prl = Prl(self, self.pos + pos)
            prl.dump()
            pos += prl.getSize()
        print '</grpprlTapx>'
        print '</upxTapx>'


class UPXPadding:
    """The UPXPadding structure specifies the padding that is used to pad the UpxPapx/Chpx/Tapx structures if any of them are an odd number of bytes in length."""
    def __init__(self, parent):
        self.parent = parent
        self.pos = parent.pos

    def pad(self):
        if self.parent.cbUpx % 2 == 1:
            self.pos += 1


class LPUpxPapx(DOCDirStream):
    """The LPUpxPapx structure specifies paragraph formatting properties."""
    def __init__(self, stkParaGRLPUPX):
        DOCDirStream.__init__(self, stkParaGRLPUPX.bytes)
        self.pos = stkParaGRLPUPX.pos

    def dump(self):
        print '<lPUpxPapx type="LPUpxPapx" offset="%d">' % self.pos
        self.printAndSet("cbUpx", self.readuInt16())
        upxPapx = UpxPapx(self)
        upxPapx.dump()
        self.pos += self.cbUpx
        uPXPadding = UPXPadding(self)
        uPXPadding.pad()
        self.pos = uPXPadding.pos
        print '</lPUpxPapx>'


class LPUpxChpx(DOCDirStream):
    """The LPUpxChpx structure specifies character formatting properties."""
    def __init__(self, stkParaGRLPUPX):
        DOCDirStream.__init__(self, stkParaGRLPUPX.bytes)
        self.pos = stkParaGRLPUPX.pos

    def dump(self):
        print '<lPUpxChpx type="LPUpxChpx" offset="%d">' % self.pos
        self.printAndSet("cbUpx", self.readuInt16())
        upxChpx = UpxChpx(self)
        upxChpx.dump()
        self.pos += self.cbUpx
        uPXPadding = UPXPadding(self)
        uPXPadding.pad()
        self.pos = uPXPadding.pos
        print '</lPUpxChpx>'


class LPUpxTapx(DOCDirStream):
    """The LPUpxTapx structure specifies table formatting properties."""
    def __init__(self, stkParaGRLPUPX):
        DOCDirStream.__init__(self, stkParaGRLPUPX.bytes)
        self.pos = stkParaGRLPUPX.pos

    def dump(self):
        print '<lPUpxTapx type="LPUpxTapx" offset="%d">' % self.pos
        self.printAndSet("cbUpx", self.readuInt16())
        upxTapx = UpxTapx(self)
        upxTapx.dump()
        self.pos += self.cbUpx
        uPXPadding = UPXPadding(self)
        uPXPadding.pad()
        self.pos = uPXPadding.pos
        print '</lPUpxTapx>'


class StkListGRLPUPX(DOCDirStream):
    """The StkListGRLPUPX structure that specifies the formatting properties for a list style."""
    def __init__(self, grLPUpxSw):
        DOCDirStream.__init__(self, grLPUpxSw.bytes)
        self.grLPUpxSw = grLPUpxSw
        self.pos = grLPUpxSw.pos

    def dump(self):
        print '<stkListGRLPUPX type="StkListGRLPUPX" offset="%d">' % self.pos
        lpUpxPapx = LPUpxPapx(self)
        lpUpxPapx.dump()
        self.pos = lpUpxPapx.pos
        print '</stkListGRLPUPX>'


class StkTableGRLPUPX(DOCDirStream):
    """The StkTableGRLPUPX structure that specifies the formatting properties for a table style."""
    def __init__(self, grLPUpxSw):
        DOCDirStream.__init__(self, grLPUpxSw.bytes)
        self.grLPUpxSw = grLPUpxSw
        self.pos = grLPUpxSw.pos

    def dump(self):
        print '<stkTableGRLPUPX type="StkTableGRLPUPX" offset="%d">' % self.pos
        lpUpxTapx = LPUpxTapx(self)
        lpUpxTapx.dump()
        self.pos = lpUpxTapx.pos
        lpUpxPapx = LPUpxPapx(self)
        lpUpxPapx.dump()
        self.pos = lpUpxPapx.pos
        lpUpxChpx = LPUpxChpx(self)
        lpUpxChpx.dump()
        self.pos = lpUpxChpx.pos
        print '</stkTableGRLPUPX>'


class StkCharGRLPUPX(DOCDirStream):
    """The StkCharGRLPUPX structure that specifies the formatting properties for a character style."""
    def __init__(self, grLPUpxSw):
        DOCDirStream.__init__(self, grLPUpxSw.bytes)
        self.grLPUpxSw = grLPUpxSw
        self.pos = grLPUpxSw.pos
        self.grLPUpxSw = grLPUpxSw

    def dump(self):
        print '<stkCharGRLPUPX type="StkCharGRLPUPX" offset="%d">' % self.pos
        if self.grLPUpxSw.std.stdf.stdfBase.cupx == 1:
            lpUpxChpx = LPUpxChpx(self)
            lpUpxChpx.dump()
            self.pos = lpUpxChpx.pos
        else:
            print '<todo what="StkCharGRLPUPX: cupx != 1"/>'
        print '</stkCharGRLPUPX>'


class StkParaGRLPUPX(DOCDirStream):
    """The StkParaGRLPUPX structure that specifies the formatting properties for a paragraph style."""
    def __init__(self, grLPUpxSw):
        DOCDirStream.__init__(self, grLPUpxSw.bytes)
        self.grLPUpxSw = grLPUpxSw
        self.pos = grLPUpxSw.pos
        self.grLPUpxSw = grLPUpxSw

    def dump(self):
        print '<stkParaGRLPUPX type="StkParaGRLPUPX" offset="%d">' % self.pos
        if self.grLPUpxSw.std.stdf.stdfBase.cupx == 2:
            lPUpxPapx = LPUpxPapx(self)
            lPUpxPapx.dump()
            self.pos = lPUpxPapx.pos
            lpUpxChpx = LPUpxChpx(self)
            lpUpxChpx.dump()
            self.pos = lpUpxChpx.pos
        else:
            print '<todo what="StkParaGRLPUPX: cupx != 2"/>'
        print '</stkParaGRLPUPX>'


class GrLPUpxSw(DOCDirStream):
    """The GrLPUpxSw structure is an array of variable-size structures that specify the formatting of the style."""
    def __init__(self, std):
        DOCDirStream.__init__(self, std.bytes)
        self.std = std
        self.pos = std.pos

    def dump(self):
        stkMap = {
            1: StkParaGRLPUPX,
            2: StkCharGRLPUPX,
            3: StkTableGRLPUPX,
            4: StkListGRLPUPX
        }
        child = stkMap[self.std.stdf.stdfBase.stk](self)
        child.dump()
        self.pos = child.pos


class STD(DOCDirStream):
    """The STD structure specifies a style definition."""
    def __init__(self, lpstd):
        DOCDirStream.__init__(self, lpstd.bytes, mainStream=lpstd.mainStream)
        self.lpstd = lpstd
        self.pos = lpstd.pos
        self.posOrig = self.pos
        self.size = lpstd.cbStd

    def dump(self):
        print '<std type="STD" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.stdf = Stdf(self)
        self.stdf.dump()
        self.pos = self.stdf.pos
        if self.pos - self.posOrig < self.size:
            xstzName = Xstz(self)
            xstzName.dump()
            self.pos = xstzName.pos
            grLPUpxSw = GrLPUpxSw(self)
            grLPUpxSw.dump()
            self.pos = grLPUpxSw.pos
        print '</std>'


class LPStd(DOCDirStream):
    """The LPStd structure specifies a length-prefixed style definition."""
    def __init__(self, stsh):
        DOCDirStream.__init__(self, stsh.bytes, mainStream=stsh.mainStream)
        self.stsh = stsh
        self.pos = stsh.pos

    def dump(self):
        self.printAndSet("cbStd", self.readuInt16())
        posOrig = self.pos
        if self.cbStd > 0:
            std = STD(self)
            std.dump()
            self.pos = std.pos
        self.pos = posOrig + self.cbStd


class STSH(DOCDirStream):
    """The STSH structure specifies the stylesheet for a document."""
    def __init__(self, bytes, mainStream, offset, size):
        DOCDirStream.__init__(self, bytes, mainStream=mainStream)
        self.pos = offset
        self.size = size

    def dump(self):
        print '<stsh type="STSH" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.lpstshi = LPStshi(self.bytes, self.mainStream, self.pos)
        self.lpstshi.dump()
        self.pos = self.lpstshi.pos
        for i in range(self.lpstshi.stshi.stshif.cstd):
            print '<rglpstd index="%d" type="LPStd" offset="%d">' % (i, self.pos)
            lpstd = LPStd(self)
            lpstd.dump()
            self.pos = lpstd.pos
            print '</rglpstd>'
        print '</stsh>'


class Rca(DOCDirStream):
    """The Rca structure is used to define the coordinates of a rectangular area in the document."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos

    def dump(self):
        print '<rca type="Rca" offset="%s">' % self.pos
        self.printAndSet("left", self.readuInt32())
        self.printAndSet("top", self.readuInt32())
        self.printAndSet("right", self.readuInt32())
        self.printAndSet("bottom", self.readuInt32())
        print '</rca>'
        self.parent.pos = self.pos


class SPA(DOCDirStream):
    """The Spa structure specifies information about the shapes and drawings that the document contains."""
    size = 26  # defined by 2.8.37

    def __init__(self, parent, offset):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = offset

    def dump(self):
        pos = self.pos
        print '<spa type="SPA" offset="%s" size="%d bytes">' % (self.pos, SPA.size)
        self.printAndSet("lid", self.readuInt32())
        Rca(self).dump()
        buf = self.readuInt16()
        self.printAndSet("fHdr", self.getBit(buf, 0))  # 1st bit
        self.printAndSet("bx", (buf & 0x6) >> 1)  # 2..3rd bits
        self.printAndSet("by", (buf & 0x18) >> 3)  # 4..5th bits
        self.printAndSet("wr", (buf & 0x1e0) >> 5)  # 6..9th bits
        self.printAndSet("wrk", (buf & 0x1e00) >> 9)  # 10..13th bits
        self.printAndSet("fRcaSimple", self.getBit(buf, 13))  # 14th bit
        self.printAndSet("fBelowText", self.getBit(buf, 14))  # 15th bit
        self.printAndSet("fAnchorLock", self.getBit(buf, 15))  # 16th bit
        self.printAndSet("cTxbx", self.readuInt32())
        print '</spa>'
        assert pos + SPA.size == self.pos


class SPLS(DOCDirStream):
    """The SPLS structure specifies the current state of a range of text with regard to one of the language checking features."""
    size = 2  # defined by 2.9.253

    def __init__(self, name, plcfSpl, offset):
        DOCDirStream.__init__(self, plcfSpl.bytes)
        self.name = name
        self.plcfSpl = plcfSpl
        self.pos = offset

    def dump(self):
        splfMap = {
            0x1: "splfPending",
            0x2: "splfMaybeDirty",
            0x3: "splfDirty",
            0x4: "splfEdit",
            0x5: "splfForeign",
            0x7: "splfClean",
            0x8: "splfNoLAD",
            0xA: "splfErrorMin",
            0xB: "splfRepeatWord",
            0xC: "splfUnknownWord",
        }
        print '<spls type="SPLS" offset="%d" size="%d bytes">' % (self.pos, SPLS.size)
        buf = self.readuInt16()
        self.printAndSet("splf", buf & 0x000f, end=False)  # 1..4th bits
        if self.splf in splfMap:
            print '<transformed name="%s"/>' % splfMap[self.splf]
        print '</splf>'
        self.printAndSet("fError", self.getBit(buf, 4))
        self.printAndSet("fExtend", self.getBit(buf, 5))
        self.printAndSet("fTypo", self.getBit(buf, 6))
        self.printAndSet("unused", (buf & 0xff80) >> 7)  # 8..16th bits
        print '</spls>'


class PlcfSpl(DOCDirStream, PLC):
    """The Plcfspl structure is a Plc structure whose data elements are SpellingSpls structures."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, mainStream.lcbPlcfSpl, 2)  # 2 is defined by 2.8.28
        self.pos = mainStream.fcPlcfSpl
        self.size = mainStream.lcbPlcfSpl

    def dump(self):
        print '<plcfSpl type="PlcfSpl" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        for i in range(self.getElements()):
            # aCp
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aCP index="%d" start="%d" end="%d">' % (i, start, end)
            pos += 4

            # aSpellingSpls
            aSpellingSpls = SPLS("SpellingSpls", self, self.getOffset(self.pos, i))
            aSpellingSpls.dump()

            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(start, end))
            print '</aCP>'
        print '</plcfSpl>'


class FTXBXNonReusable(DOCDirStream):
    """The FTXBXNonReusable structure is used within the FTXBXS structure when that structure
    describes a real textbox. A real textbox is any shape object into which text is added, and that is the
    first or only shape in a linked chain."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos

    def dump(self):
        print '<ftxbxsunion type="FTXBXNonReusable" offset="%d" size="8 bytes">' % (self.pos)
        self.printAndSet("cTxbx", self.readuInt32())
        self.printAndSet("cTxbxEdit", self.readuInt32())
        print '</ftxbxsunion>'
        self.parent.pos = self.pos


class FTXBXSReusable(DOCDirStream):
    """The FTXBXSReusable structure is used within the FTXBXS structure when it describes a spare
    structure that can be reused by the application and converted into an actual textbox."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = parent.pos

    def dump(self):
        print '<ftxbxsunion type="FTXBXReusable" offset="%d" size="8 bytes">' % (self.pos)
        self.printAndSet("iNextReuse", self.readuInt32())
        self.printAndSet("cReusable", self.readuInt32())
        print '</ftxbxsunion>'
        self.parent.pos = self.pos


class FTXBXS(DOCDirStream):
    """Associates ranges of text from the Textboxes Document and the Header
    Textboxes Document, with shape objects."""
    size = 22  # 2.8.32

    def __init__(self, parent, offset):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = self.posOrig = offset

    def dump(self):
        print '<aFTXBXS type="FTXBXS" offset="%d" size="%d bytes">' % (self.pos, FTXBXS.size)
        self.fReusable = self.getuInt16(pos=self.pos + 8)
        if self.fReusable:
            FTXBXSReusable(self).dump()
        else:
            FTXBXNonReusable(self).dump()
        self.printAndSet("fReusable", self.readuInt16())
        self.printAndSet("itxbxsDest", self.readuInt32())
        self.printAndSet("lid", self.readuInt32())
        self.printAndSet("txidUndo", self.readuInt32())
        print '</aFTXBXS>'
        if not self.fReusable:
            assert self.posOrig + FTXBXS.size == self.pos


class PlcftxbxTxt(DOCDirStream, PLC):
    """Specifies which ranges of text are contained in which textboxes."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, mainStream.lcbPlcftxbxTxt, FTXBXS.size)
        self.pos = mainStream.fcPlcftxbxTxt
        self.size = mainStream.lcbPlcftxbxTxt

    def dump(self):
        print '<plcftxbxTxt type="PlcftxbxTxt" offset="%d" size="%d bytes">' % (self.pos, self.size)
        offset = self.mainStream.getHeaderOffset()
        pos = self.pos
        for i in range(self.getElements() - 1):
            # aCp
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aCP index="%d" start="%d" end="%d">' % (i, start, end)
            pos += 4

            # aFTXBXS
            aFTXBXS = FTXBXS(self, self.getOffset(self.pos, i))
            aFTXBXS.dump()

            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(offset + start, offset + end))
            print '</aCP>'
        print '</plcftxbxTxt>'


class Tbkd(DOCDirStream):
    """The Tbkd structure is used by the PlcftxbxBkd and PlcfTxbxHdrBkd structures to associate ranges of
    text from the Textboxes Document and the Header Textboxes Document with FTXBXS objects."""
    size = 6  # 2.9.309

    def __init__(self, parent, offset):
        DOCDirStream.__init__(self, parent.bytes)
        self.parent = parent
        self.pos = self.posOrig = offset

    def dump(self):
        print '<aTbkd type="Tbkd" offset="%d" size="%d bytes">' % (self.pos, Tbkd.size)
        self.printAndSet("itxbxs", self.readuInt16())
        self.printAndSet("dcpDepend", self.readuInt16())
        buf = self.readuInt16()
        self.printAndSet("reserved1", buf & 0x03ff)  # 1..10th bits
        self.printAndSet("fMarkDelete", self.getBit(buf, 10))
        self.printAndSet("fUnk", self.getBit(buf, 11))
        self.printAndSet("fTextOverflow", self.getBit(buf, 12))
        self.printAndSet("reserved2", (buf & 0xe000) >> 13)  # 14..16th bits
        print '</aTbkd>'
        assert self.posOrig + Tbkd.size == self.pos


class PlcftxbxBkd(DOCDirStream, PLC):
    """Specifies which ranges of text go inside which textboxes."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, mainStream.lcbPlcfTxbxBkd, 6)
        self.pos = mainStream.fcPlcfTxbxBkd
        self.size = mainStream.lcbPlcfTxbxBkd

    def dump(self):
        print '<plcftxbxBkd type="PlcftxbxBkd" offset="%d" size="%d bytes">' % (self.pos, self.size)
        offset = self.mainStream.getHeaderOffset()
        pos = self.pos
        for i in range(self.getElements()):
            # aCp
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aCP index="%d" start="%d" end="%d">' % (i, start, end)
            pos += 4

            # aTbkd
            Tbkd(self, self.getOffset(self.pos, i)).dump()
            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(offset + start, offset + end))
            print '</aCP>'
        print '</plcftxbxBkd>'


class PlcfSpa(DOCDirStream, PLC):
    """The PlcfSpa structure is a PLC structure in which the data elements are
    SPA structures."""
    def __init__(self, mainStream, pos, size):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, size, 26)  # 2.8.37
        self.pos = pos
        self.size = size

    def dump(self):
        print '<plcfSpa type="PlcfSpa" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        for i in range(self.getElements()):
            # aCp
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aCP index="%d" start="%d" end="%d">' % (i, start, end)
            pos += 4

            # aSpa
            aSpa = SPA(self, self.getOffset(self.pos, i))
            aSpa.dump()

            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(start, end))
            print '</aCP>'
        print '</plcfSpa>'


class PlcfGram(DOCDirStream, PLC):
    """The PlcfGram structure is a Plc structure whose data elements are GrammarSpls structures."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        PLC.__init__(self, mainStream.lcbPlcfGram, 2)  # 2 is defined by 2.8.21
        self.pos = mainStream.fcPlcfGram
        self.size = mainStream.lcbPlcfGram

    def dump(self):
        print '<plcfGram type="PlcfGram" offset="%d" size="%d bytes">' % (self.pos, self.size)
        pos = self.pos
        for i in range(self.getElements()):
            # aCp
            start = self.getuInt32(pos=pos)
            end = self.getuInt32(pos=pos + 4)
            print '<aCP index="%d" start="%d" end="%d">' % (i, start, end)
            pos += 4

            # aGrammarSpls
            aGrammarSpls = SPLS("GrammarSpls", self, self.getOffset(self.pos, i))
            aGrammarSpls.dump()

            print '<transformed value="%s"/>' % self.quoteAttr(self.mainStream.retrieveCPs(start, end))
            print '</aCP>'
        print '</plcfGram>'


class Grfhic(DOCDirStream):
    """The grfhic structure is a set of HTML incompatibility flags that specify
    the HTML incompatibilities of a list structure."""
    def __init__(self, parent):
        DOCDirStream.__init__(self, parent.bytes)
        self.pos = parent.pos
        self.parent = parent

    def dump(self):
        print '<grfhic type="grfhic">'
        buf = self.readuInt8()
        self.printAndSet("fhicChecked", self.getBit(buf, 0))
        self.printAndSet("fhicFormat", self.getBit(buf, 1))
        self.printAndSet("fhicListText", self.getBit(buf, 2))
        self.printAndSet("fhicPeriod", self.getBit(buf, 3))
        self.printAndSet("fhicLeft1", self.getBit(buf, 4))
        self.printAndSet("fhicListTab", self.getBit(buf, 5))
        self.printAndSet("unused", self.getBit(buf, 6))
        self.printAndSet("fhicBullet", self.getBit(buf, 7))
        self.parent.pos = self.pos
        print '</grfhic>'


class LSTF(DOCDirStream):
    """The LSTF structure contains formatting properties that apply to an entire list."""
    def __init__(self, plfLst, index):
        DOCDirStream.__init__(self, plfLst.bytes)
        self.pos = plfLst.pos
        self.size = 28
        self.index = index

    def dump(self):
        print '<lstf type="LSTF" index="%d" offset="%d" size="%d bytes">' % (self.index, self.pos, self.size)
        self.printAndSet("lsid", self.readInt32())
        self.printAndSet("tplc", self.readInt32())
        for i in range(9):
            print '<rgistdPara value="%s"/>' % self.readInt16()
        buf = self.readuInt8()
        self.printAndSet("fSimpleList", self.getBit(buf, 0))
        self.printAndSet("unused1", self.getBit(buf, 1))
        self.printAndSet("fAutoNum", self.getBit(buf, 2))
        self.printAndSet("unused2", self.getBit(buf, 3))
        self.printAndSet("fHybrid", self.getBit(buf, 4))
        self.printAndSet("reserved1", (buf & 0xe0) >> 5)  # 6..8th bits
        Grfhic(self).dump()
        print '</lstf>'


class LVLF(DOCDirStream):
    """The LVLF structure contains formatting properties for an individual level in a list."""
    def __init__(self, lvl):
        DOCDirStream.__init__(self, lvl.bytes)
        self.pos = lvl.pos

    def dump(self):
        print '<lvlf type="LVLF" offset="%d">' % self.pos
        self.printAndSet("iStartAt", self.readInt32())
        self.printAndSet("nfc", self.readuInt8())
        buf = self.readuInt8()
        self.printAndSet("jc", buf & 0x3)  # 1..2nd bits
        self.printAndSet("fLegal", self.getBit(buf, 2))
        self.printAndSet("fNoRestart", self.getBit(buf, 3))
        self.printAndSet("fIndentSav", self.getBit(buf, 4))
        self.printAndSet("fConverted", self.getBit(buf, 5))
        self.printAndSet("unused1", self.getBit(buf, 6))
        self.printAndSet("fTentative", self.getBit(buf, 7))
        for i in range(9):
            print '<rgrgbxchNums index="%d" value="%s"/>' % (i, self.readuInt8())
        self.printAndSet("ixchFollow", self.readuInt8())
        self.printAndSet("dxaIndentSav", self.readInt32())
        self.printAndSet("unused2", self.readuInt32())
        self.printAndSet("cbGrpprlChpx", self.readuInt8())
        self.printAndSet("cbGrpprlPapx", self.readuInt8())
        self.printAndSet("ilvlRestartLim", self.readuInt8())
        Grfhic(self).dump()
        print '</lvlf>'


class LVL(DOCDirStream):
    """The LVL structure contains formatting information about a specific level in a list."""
    def __init__(self, plfLst, index):
        DOCDirStream.__init__(self, plfLst.bytes)
        self.pos = plfLst.pos
        self.index = index

    def dump(self):
        print '<lvl type="LVL" index="%d" offset="%d">' % (self.index, self.pos)
        lvlf = LVLF(self)
        lvlf.dump()
        self.pos = lvlf.pos

        print '<grpprlPapx offset="%d">' % self.pos
        pos = self.pos
        while (lvlf.cbGrpprlPapx - (pos - self.pos)) > 0:
            prl = Prl(self, pos)
            prl.dump()
            pos += prl.getSize()
        self.pos = pos
        print '</grpprlPapx>'

        print '<grpprlChpx offset="%d">' % self.pos
        pos = self.pos
        while (lvlf.cbGrpprlChpx - (pos - self.pos)) > 0:
            prl = Prl(self, pos)
            prl.dump()
            pos += prl.getSize()
        self.pos = pos
        print '</grpprlChpx>'
        xst = Xst(self)
        xst.dump()
        self.pos = xst.pos
        print '</lvl>'


class PlfLst(DOCDirStream):
    """The PlfLst structure contains the list formatting information for the document."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        self.pos = mainStream.fcPlfLst
        self.size = mainStream.lcbPlfLst

    def dump(self):
        print '<plfLst type="PlfLst" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("cLst", self.readInt16())
        cLvl = 0
        for i in range(self.cLst):
            rgLstf = LSTF(self, i)
            rgLstf.dump()
            if rgLstf.fSimpleList:
                cLvl += 1
            else:
                cLvl += 9
            self.pos = rgLstf.pos
        for i in range(cLvl):
            lvl = LVL(self, i)
            lvl.dump()
            self.pos = lvl.pos
        print '</plfLst>'


class LFO(DOCDirStream):
    """The LFO structure specifies the LSTF element that corresponds to a list that contains a paragraph."""
    def __init__(self, plfLfo, name, index):
        DOCDirStream.__init__(self, plfLfo.bytes)
        self.pos = plfLfo.pos
        self.name = name
        self.index = index

    def dump(self):
        print '<%s type="LFO" index="%s" offset="%d">' % (self.name, self.index, self.pos)
        self.printAndSet("lsid", self.readInt32())
        self.printAndSet("unused1", self.readuInt32())
        self.printAndSet("unused2", self.readuInt32())
        self.printAndSet("clfolvl", self.readuInt8())
        self.printAndSet("ibstFltAutoNum", self.readuInt8())
        Grfhic(self).dump()
        self.printAndSet("unused3", self.readuInt8())
        print '</%s>' % self.name


class LFOData(DOCDirStream):
    """The LFOData structure contains the Main Document CP of the corresponding LFO."""
    def __init__(self, plfLfo, lfo):
        DOCDirStream.__init__(self, plfLfo.bytes)
        self.pos = plfLfo.pos
        self.lfo = lfo

    def dump(self):
        print '<lfoData type="LFOData" offset="%d">' % self.pos
        self.printAndSet("cp", self.readuInt32())
        if self.lfo.clfolvl > 0:
            print '<todo what="LFOData: clfolvl != 0"/>'
        print '</lfoData>'


class PlfLfo(DOCDirStream):
    """The PlfLfo structure contains the list format override data for the document."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        self.pos = mainStream.fcPlfLfo
        self.size = mainStream.lcbPlfLfo

    def dump(self):
        print '<plfLfo type="PlfLfo" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("lfoMac", self.readInt32())
        lfos = []
        for i in range(self.lfoMac):
            lfo = LFO(self, "rgLfo", i)
            lfos.append(lfo)
            lfo.dump()
            self.pos = lfo.pos
        for i in range(self.lfoMac):
            lfoData = LFOData(self, lfos[i])
            lfoData.dump()
            self.pos = lfoData.pos
        print '</plfLfo>'


class SttbListNames(DOCDirStream):
    """The SttbListNames structure is an STTB structure whose strings are the names used by the LISTNUM field."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        self.pos = mainStream.fcSttbListNames
        self.size = mainStream.lcbSttbListNames

    def dump(self):
        print '<sttbListNames type="SttbListNames" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("fExtend", self.readuInt16())
        self.printAndSet("cData", self.readuInt16())
        self.printAndSet("cbExtra", self.readuInt16())
        for i in range(self.cData):
            cchData = self.readuInt16()
            print '<cchData index="%s" offset="%d" size="%d bytes">' % (i, self.pos, cchData)
            print '<string value="%s"/>' % globals.encodeName(self.bytes[self.pos:self.pos + 2 * cchData].decode('utf-16'), lowOnly=True)
            self.pos += 2 * cchData
            print '</cchData>'
        print '</sttbListNames>'


class SttbSavedBy(DOCDirStream):
    """The SttbSavedBy structure is an STTB structure that specifies the save history of this document."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes, mainStream=mainStream)
        self.pos = mainStream.fcSttbSavedBy
        self.size = mainStream.lcbSttbSavedBy

    def dump(self):
        print '<sttbSavedBy type="SttbSavedBy" offset="%d" size="%d">' % (self.pos, self.size)
        self.printAndSet("fExtend", self.readuInt16())
        self.printAndSet("cData", self.readuInt16())
        self.printAndSet("cbExtra", self.readuInt16())
        for i in range(self.cData):
            cchData = self.readuInt16()
            print '<cchData index="%s" offset="%d" size="%d bytes">' % (i, self.pos, cchData)
            print '<string value="%s"/>' % globals.encodeName(self.bytes[self.pos:self.pos + 2 * cchData].decode('utf-16'), lowOnly=True)
            self.pos += 2 * cchData
            print '</cchData>'
        # Probably this was cleared manually.
        if self.cData != 0:
            assert self.pos == self.mainStream.fcSttbSavedBy + self.size
        print '</sttbSavedBy>'


class SttbfBkmk(DOCDirStream):
    """The SttbfBkmk structure is an STTB structure whose strings specify the names of bookmarks."""
    def __init__(self, mainStream):
        DOCDirStream.__init__(self, mainStream.getTableStream().bytes)
        self.pos = mainStream.fcSttbfBkmk
        self.size = mainStream.lcbSttbfBkmk
        self.mainStream = mainStream

    def dump(self):
        print '<sttbfBkmk type="SttbfBkmk" offset="%d" size="%d bytes">' % (self.pos, self.size)
        self.printAndSet("fExtended", self.readuInt16())
        self.printAndSet("cData", self.readuInt16())
        self.printAndSet("cbExtra", self.readuInt16())
        for i in range(self.cData):
            cchData = self.readuInt16()
            print '<cchData index="%d" offset="%d" size="%d bytes">' % (i, self.pos, cchData)
            print '<string value="%s"/>' % globals.encodeName(self.bytes[self.pos:self.pos + 2 * cchData].decode('utf-16'), lowOnly=True)
            self.pos += 2 * cchData
            print '</cchData>'
        assert self.pos == self.mainStream.fcSttbfBkmk + self.size
        print '</sttbfBkmk>'

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

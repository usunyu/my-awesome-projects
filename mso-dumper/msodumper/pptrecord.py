# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import globals

# -------------------------------------------------------------------
# record handler classes

class BaseRecordHandler(object):

    def __init__ (self, recordType, recordInstance, size, bytes, streamProperties, prefix='', propertyName=None):
        self.recordType = recordType
        self.recordInstance = recordInstance
        self.size = size
        self.bytes = bytes
        self.lines = []
        self.streamProperties = streamProperties
        self.propertyName = propertyName
        self.prefix = prefix
        self.pos = 0       # current byte position

    def parseBytes (self):
        """Parse the original bytes and generate human readable output.

The derived class should only worry about overwriting this function.  The
bytes are given as self.bytes, and call self.appendLine([new line]) to
append a line to be displayed.
"""
        pass

    def __print (self, text):
        try:
            globals.outputln(self.prefix + text, recordType = self.recordType)
        except UnicodeEncodeError:
            globals.outputln(self.prefix + "<%d invalid chars>"%len(text),
                             recordType = self.recordType)

    def output (self):
        self.parseBytes()
        self.__print("%4.4Xh: %s"%(self.recordType, "-"*61))
        for line in self.lines:
            self.__print("%4.4Xh: %s"%(self.recordType, line))

    def appendText(self, text):
        global textdump
        # unfortunaley we have no access to the globals.params, so we
        # can't keep the text local and let output() behave according
        # to params. Have to use a global if we want to keep a minimal
        # modification
        globals.textdump += text + "\n"

    def appendLine (self, line):
        self.lines.append(line)

    def appendLineBoolean (self, name, value):
        text = "%s: %s"%(name, self.getYesNo(value))
        self.appendLine(text)

    def appendProperty (self, value):
        if self.propertyName is not None:
            self.streamProperties[self.propertyName] = value

    def isEmpty (self):
        return len(self.bytes) <= self.pos

    def readBytes (self, length):
        r = self.bytes[self.pos:self.pos+length]
        self.pos += length
        return r

    def readRemainingBytes (self):
        r = self.bytes[self.pos:]
        self.pos = self.size
        return r

    def getCurrentPos (self):
        return self.pos

    def setCurrentPos (self, pos):
        self.pos = pos

    def getYesNo (self, boolVal):
        if boolVal:
            return 'yes'
        else:
            return 'no'

    def readUnsignedInt (self, length):
        bytes = self.readBytes(length)
        return globals.getUnsignedInt(bytes)

    def readSignedInt (self, length):
        bytes = self.readBytes(length)
        return globals.getSignedInt(bytes)

    def readDouble (self):
        # double is always 8 bytes.
        bytes = self.readBytes(8)
        return globals.getDouble(bytes)

    def readRatio (self):
        numer = self.readSignedInt(4)
        denom = self.readSignedInt(4)
        return "%d/%d"%(numer, denom)

    def readScaling (self):
        xratio = self.readRatio()
        yratio = self.readRatio()
        return "(%s,%s)"%(xratio, yratio)


class String(BaseRecordHandler):
    """Textual content."""

    def parseBytes (self):
        name = globals.getTextBytes(self.readRemainingBytes())
        self.appendProperty(name)
        # The MS doc says that the bytes are the low bytes of unicode
        # chars, with the high byte ignored. Only latin1 could stand
        # this transformation.
        name = name.decode('cp1252').encode('UTF-8')
        self.appendLine("text: '%s'"%name)
        self.appendText(name)

def ShapeString (*args):
    args += "ShapeText",
    return String(*args)

class UniString(BaseRecordHandler):
    """Textual content."""

    def parseBytes (self):
        name = globals.getUTF8FromUTF16(globals.getTextBytes(self.readRemainingBytes()))
        self.appendProperty(name)
        self.appendLine("text: '%s'"%name)
        self.appendText(name)

def ShapeUniString (*args):
    args += "ShapeText",
    return UniString(*args)

def CString (*args):
    args += "CString",
    return UniString(*args)

class ZipRecord(BaseRecordHandler):
    """Zipped content."""

    def parseBytes (self):
        globals.outputZipContent(self.readRemainingBytes(), self.appendLine, 61)

class FontEntity(BaseRecordHandler):
    """Font entity."""

    def parseBytes (self):
        faceName       = globals.getUTF8FromUTF16(
            globals.getTextBytes(self.readBytes(64)))
        charSet        = self.readUnsignedInt(1)
        flags          = self.readUnsignedInt(1)
        fontType       = self.readUnsignedInt(1)
        pitchAndFamily = self.readUnsignedInt(1)
        self.appendLine("Font: name=\"%s\" charset=%d flags=0x%x type=%d family=%d"%(faceName, charSet, flags, fontType, pitchAndFamily))

# -------------------------------------------------------------------
# special record handler: properties

class Property(BaseRecordHandler):
    """Shape properties."""

    def parseBytes (self):
        # each prop entry takes 6 bytes; complex stuff comes after
        # prop entries and fills remaining record space
        allComplexBytes = self.bytes[self.pos+self.recordInstance*6:]

        # recordInstance gives number of properties
        for i in xrange(0, self.recordInstance):
            propType = self.readUnsignedInt(2)
            propValue = self.readUnsignedInt(4)

            isComplex = (propType & 0x8000) != 0
            isBlip = ((propType & 0x4000) != 0) and not isComplex
            propType = (propType & 0x3FFF)
            complexBytes = []

            if isComplex:
                # eat propValue bytes from complexBytes
                complexBytes = allComplexBytes[:propValue]
                allComplexBytes = allComplexBytes[propValue:]

            if propType in propData:
                handler = propData[propType][1](propType, propValue, isComplex, isBlip, complexBytes, self.appendLine)
                handler.output()
            else:
                self.appendLine("%4.4Xh: [unknown property type: %4.4Xh, value: %8.8Xh, complex: %d, blip: %d]"%(propType, propType, propValue, isComplex, isBlip))

# -------------------------------------------------------------------
# special record handler: shape anchor rect

class Rect(BaseRecordHandler):
    """Rectangle."""

    def parseBytes (self):
        # seems there are 16bit and 32bit coordinate values in the
        # wild
        if self.size == 16:
            left = self.readUnsignedInt(4)
            top = self.readUnsignedInt(4)
            right = self.readUnsignedInt(4)
            bottom = self.readUnsignedInt(4)
            self.appendLine("Anchor(long): (%d,%d)(%d,%d)"%(left,top,right,bottom))
        elif self.size == 8:
            top = self.readUnsignedInt(2)
            left = self.readUnsignedInt(2)
            right = self.readUnsignedInt(2)
            bottom = self.readUnsignedInt(2)
            self.appendLine("Anchor(short): (%d,%d)(%d,%d)"%(left,top,right,bottom))
        else:
            self.appendLine("%4.4Xh: [invalid anchor payload (size: %d)]"%(propType, self.size))


# -------------------------------------------------------------------
# special record handler: shape

class Shape(BaseRecordHandler):
    """PowerPoint Shape."""

    def parseBytes (self):
        # recordInstance gives shape type
        theType = self.recordInstance

        # 4 bytes shape id
        shapeId = self.readUnsignedInt(4)
        if theType in shapeTypes:
            self.appendLine("Shape %s, id=%d"%(shapeTypes[theType][0], shapeId))
        else:
            self.appendLine("Unknown shape, id=%d"%shapeId)

        # 4 bytes shape persist flags
        flags = self.readUnsignedInt(4)

        group = (flags & 0x00000001) != 0
        child = (flags & 0x00000002) != 0
        patriarch = (flags & 0x00000004) != 0
        deleted = (flags & 0x00000008) != 0
        oleshape = (flags & 0x00000010) != 0
        haveMaster = (flags & 0x00000020) != 0
        flipH = (flags & 0x00000040) != 0
        flipV = (flags & 0x00000080) != 0
        connector = (flags & 0x00000100) != 0
        haveAnchor = (flags & 0x00000200) != 0
        background = (flags & 0x00000400) != 0
        haveTypeProp = (flags & 0x00000800) != 0

        self.appendLine("flags:\n"
                        "                group        = %d\n"
                        "                child        = %d\n"
                        "                patriarch    = %d\n"
                        "                deleted      = %d\n"
                        "                oleshape     = %d\n"
                        "                haveMaster   = %d\n"
                        "                flipH        = %d\n"
                        "                flipV        = %d\n"
                        "                connector    = %d\n"
                        "                haveAnchor   = %d\n"
                        "                background   = %d\n"
                        "                haveTypeProp = %d"%(group,
                                                             child,
                                                             patriarch,
                                                             deleted,
                                                             oleshape,
                                                             haveMaster,
                                                             flipH,
                                                             flipV,
                                                             connector,
                                                             haveAnchor,
                                                             background,
                                                             haveTypeProp))

# -------------------------------------------------------------------
# special record handler: TextHeader

class TextHeader(BaseRecordHandler):
    """TextHeaderAtom."""

    def parseBytes (self):
        # 4 bytes type
        textType = self.readUnsignedInt(4)
        if textType in textHeader:
            self.appendLine("Text type: %s"%textHeader[textType][0])
        else:
            self.appendLine("Text type: unknown")


# -------------------------------------------------------------------
# special record handler: embedded wav atom

class EmbeddedWav(BaseRecordHandler):
    """Wav atom."""

    def parseBytes (self):
        self.appendLine("sound id: %Xh"%self.readUnsignedInt(4))
        self.appendLine("sound len: %d bytes"%self.readUnsignedInt(4))


# -------------------------------------------------------------------
# special record handler: media atom

class MediaAtom(BaseRecordHandler):
    """Media atom."""

    def parseBytes (self):
        self.appendLine("id: %Xh"%self.readUnsignedInt(4))
        flags = self.readUnsignedInt(2)
        self.appendLine("loop: %s"%((flags & 0x0001)!=0))
        self.appendLine("rewind: %s"%((flags & 0x0002)!=0))
        self.appendLine("is narration: %s"%((flags & 0x0004)!=0))


# -------------------------------------------------------------------
# special record handler: object ref atom

class ObjectRefAtom(BaseRecordHandler):
    """Object reference atom."""

    def parseBytes (self):
        self.appendLine("external object id: %Xh"%self.readUnsignedInt(4))


# -------------------------------------------------------------------
# special record handler: object ref atom

class InteractiveInfoAtom(BaseRecordHandler):
    """Interaction info atom."""

    actionDesc=["noAction","macroAction","runProgramAction","jumpAction","hyperlinkAction",
                "oleAction","mediaAction","customShowAction"]
    def parseBytes (self):
        self.appendLine("sound object id: %Xh"%self.readUnsignedInt(4))
        self.appendLine("external hyperlink id: %Xh"%self.readUnsignedInt(4))
        self.appendLine("action: %s"%self.actionDesc[self.readUnsignedInt(1)])
        self.appendLine("ole verb id: %d"%self.readUnsignedInt(1))
        flags = self.readUnsignedInt(1)
        self.appendLine("animated button: %s"%((flags & 0x01)!=0))
        self.appendLine("stop sound: %s"%((flags & 0x02)!=0))
        self.appendLine("custom show return: %s"%((flags & 0x04)!=0))
        self.appendLine("interaction visited: %s"%((flags & 0x08)!=0))
        self.appendLine("hyperlink type: %d"%self.readUnsignedInt(1))


# -------------------------------------------------------------------
# special record handler: document atom

class DocAtom(BaseRecordHandler):
    """Document atom."""

    def parseBytes (self):
        slideWidth = self.readSignedInt(4)
        slideHeight = self.readSignedInt(4)
        notesWidth = self.readSignedInt(4)
        notesHeight = self.readSignedInt(4)
        oleWidth = self.readSignedInt(4)
        oleHeight = self.readSignedInt(4)
        notesMasterPersist = self.readUnsignedInt(4)
        handoutMasterPersist = self.readUnsignedInt(4)
        firstSlideNum = self.readUnsignedInt(2)
        slideSizeType = self.readSignedInt(2)
        savedWithFont = self.readUnsignedInt(1)
        omitTitlePlace = self.readUnsignedInt(1)
        right2Left = self.readUnsignedInt(1)
        showComments = self.readUnsignedInt(1)

        self.appendLine("Slide: (%d,%d), notes: (%d,%d), ole zoom: (%d,%d)"%(slideWidth, slideHeight,
                                                                             notesWidth, notesHeight,
                                                                             oleWidth, oleHeight))
        self.appendLine("Notes master persist offset: %8.8Xh"%notesMasterPersist)
        self.appendLine("Handout master persist offset: %8.8Xh"%handoutMasterPersist)
        self.appendLine("1st slide num: %d, slide size type: %4.4Xh"%(firstSlideNum, slideSizeType))
        self.appendLine("embedded fonts: %s, no placeholders on title slide: %s"%(savedWithFont,
                                                                                  omitTitlePlace))
        self.appendLine("RTL doc: %s, show comment shapes: %s"%(right2Left, showComments))


# -------------------------------------------------------------------
# special record handler: color scheme atom

class ColorScheme(BaseRecordHandler):
    """Color scheme atom."""

    def parseBytes (self):
        self.appendLine(globals.stringizeColorRef(self.readUnsignedInt(4),
                                                  "Background"))
        self.appendLine(globals.stringizeColorRef(self.readUnsignedInt(4),
                                                  "Text and lines"))
        self.appendLine(globals.stringizeColorRef(self.readUnsignedInt(4),
                                                  "Shadows"))
        self.appendLine(globals.stringizeColorRef(self.readUnsignedInt(4),
                                                  "Title text"))
        self.appendLine(globals.stringizeColorRef(self.readUnsignedInt(4),
                                                  "Fills"))
        self.appendLine(globals.stringizeColorRef(self.readUnsignedInt(4),
                                                  "Accent"))
        self.appendLine(globals.stringizeColorRef(self.readUnsignedInt(4),
                                                  "Accent and hyperlink"))
        self.appendLine(globals.stringizeColorRef(self.readUnsignedInt(4),
                                                  "Accent and followed hyperlink"))

# -------------------------------------------------------------------
# special record handler: ssslide info atom

class SlideInfo(BaseRecordHandler):
    """SSSlide Info atom."""

    def parseBytes (self):
        self.appendLine("slide time: %d"%self.readUnsignedInt(4))
        self.appendLine("sound ref: %d"%self.readUnsignedInt(4))
        ttype=self.readUnsignedInt(2)
        self.appendLine("direction: %d"%(ttype & 0xff))
        self.appendLine("transition type: %d"%(ttype & 0xff00))
        self.appendLine("flags: %d"%self.readUnsignedInt(2))
        self.appendLine("speed: %d"%self.readUnsignedInt(1))

# -------------------------------------------------------------------
# special record handler: slide atom

class SlideAtom(BaseRecordHandler):
    """Slide atom."""

    def parseBytes (self):
        geom=self.readUnsignedInt(4)
        self.appendLine("geom: %s %4.4Xh (%d)"%(slideLayoutTypes[geom], geom, geom))
        self.appendLine("placeholder type: %s"%(placeholderEnum[self.readUnsignedInt(1)]))
        self.appendLine("placeholder type: %s"%(placeholderEnum[self.readUnsignedInt(1)]))
        self.appendLine("placeholder type: %s"%(placeholderEnum[self.readUnsignedInt(1)]))
        self.appendLine("placeholder type: %s"%(placeholderEnum[self.readUnsignedInt(1)]))
        self.appendLine("placeholder type: %s"%(placeholderEnum[self.readUnsignedInt(1)]))
        self.appendLine("placeholder type: %s"%(placeholderEnum[self.readUnsignedInt(1)]))
        self.appendLine("placeholder type: %s"%(placeholderEnum[self.readUnsignedInt(1)]))
        self.appendLine("placeholder type: %s"%(placeholderEnum[self.readUnsignedInt(1)]))
        self.appendLine("masterIdRef: %d"%(self.readUnsignedInt(4)))
        self.appendLine("notesIdRef: %d"%(self.readUnsignedInt(4)))
        self.appendLine("slideflags: %2.2Xh"%(self.readUnsignedInt(2)))
        self.appendLine("unused: %2.2Xh (must be ignored)"%(self.readUnsignedInt(2)))

# -------------------------------------------------------------------
# special record handler: slide persist atom

class SlidePersistAtom(BaseRecordHandler):
    """Slide Persist atom."""

    def parseBytes (self):
        slideref=self.readUnsignedInt(4)
        self.appendLine("logical slide reference: %4.4Xh (%d)"%(slideref, slideref))
        flags=self.readUnsignedInt(4)
        self.appendLine("outline view is collapsed: %s"%((flags & 0x02)!=0))
        self.appendLine("slide contains shapes other than placeholders: %s"%((flags & 0x04)!=0))
        self.appendLine("number of placeholder texts: %d"%self.readUnsignedInt(4))
        self.appendLine("unique slide id: %d"%self.readUnsignedInt(4))

# -------------------------------------------------------------------
# special record handler: slide view info atom

class SlideViewInfoAtom(BaseRecordHandler):
    """Slide View Info atom."""

    def parseBytes (self):
        self.appendLine("guides visible: %s"%(self.readUnsignedInt(1)!=0))
        self.appendLine("snap to grid: %s"%(self.readUnsignedInt(1)!=0))
        self.appendLine("snap to shape: %s"%(self.readUnsignedInt(1)!=0))

# -------------------------------------------------------------------
# special record handler: view info atom

class ViewInfoAtom(BaseRecordHandler):
    """View Info atom."""

    def parseBytes (self):
        self.appendLine("current scale: %s"%self.readScaling())
        self.readBytes(24)
        self.appendLine("origin: (%d,%d)"%(self.readSignedInt(4), self.readSignedInt(4)))
        self.appendLine("zoom to fit: %s"%(self.readUnsignedInt(1)!=0))

# -------------------------------------------------------------------
# special record handlers: ppt97 animation info

class AnimationInfo(BaseRecordHandler):
    """Animation properties."""

    def parseBytes (self):
        self.appendLine(globals.stringizeColorRef(self.readUnsignedInt(4),
                                                  "DimColor"))
        flags = self.readUnsignedInt(4)
        self.appendLine("reverse: %d"%((flags & 0x00000001)!=0))
        self.appendLine("automatic: %d"%((flags & 0x00000002)!=0))
        self.appendLine("sound: %d"%((flags & 0x00000004)!=0))
        self.appendLine("stopsound: %d"%((flags & 0x00000008)!=0))
        self.appendLine("play: %d"%((flags & 0x00000010)!=0))
        self.appendLine("synchronous: %d"%((flags & 0x00000020)!=0))
        self.appendLine("hide: %d"%((flags & 0x00000040)!=0))
        self.appendLine("animateBackground: %d"%((flags & 0x00000080)!=0))
        self.appendLine("associated shape: %d"%((flags & 0x00004000)!=0))

        self.appendLine("sound reference ID: %Xh"%self.readUnsignedInt(4))
        self.appendLine("delay time: %d"%self.readUnsignedInt(4))
        orderID = self.readSignedInt(2)
        if orderID == -2:
            self.appendLine("order: follow master slide")
        else:
            self.appendLine("order: ID %4.4Xh"%orderID)

        self.appendLine("num slides to play object: %d"%self.readUnsignedInt(2))

        buildDesc = ["no build","all at once","by text level 1","by text level 2",
                     "by text level 3","by text level 4","by text level 5",
                     "graph by series","graph by category","element in series",
                     "element in category"]
        buildType = self.readUnsignedInt(1)
        try:
            # can fail with index out of range
            self.appendLine("build type: %s"%buildDesc[buildType])
        except Exception, err:
            error("AnimationInfo::parsebytes: %s: %s" % (str(buildType),str(err)))

        flyDesc = ["none","random","blinds","checker","cover","dissolve",
                   "fade","pull","random bar","strips","wipe","zoom","fly",
                   "split","flash","(unused)","(unused)","diamond","plus",
                   "wedge","push","comb","newsflash","alphafade","blur",
                   "pushelem","wheel","circle"]
        flyMethod = self.readUnsignedInt(1)
        self.appendLine("fly method: %s"%flyDesc[flyMethod])

        flyDirectionDesc = ["left","up","right","down","leftUp","rightUp",
                            "leftDown","rightDown","fromLeftEdge","fromBottomEdge",
                            "fromRightEdge","fromTopEdge","leftSlow","upSlow",
                            "rightSlow","downSlow","zoomIn","zoomInSlightly",
                            "zoomOut","zoomOutSlightly","zoomCenter","zoomBottom",
                            "stretchAcross","stretchLeft","stretchUp","stretchRight",
                            "stretchDown","rotate","spiral"]
        flyDirection = self.readUnsignedInt(1)
        self.appendLine("fly direction: %s"%flyDirectionDesc[flyDirection])

        afterEffectDesc = ["none","dim","hide","hideImmediately"]
        afterEffect = self.readUnsignedInt(1)
        self.appendLine("after effect: %s"%afterEffectDesc[afterEffect])

        subEffectDesc = ["none","build by word","build by letter"]
        subEffect = self.readUnsignedInt(1)
        self.appendLine("sub effect: %s"%subEffectDesc[subEffect])

        self.appendLine("OLE verb: %4.4Xh"%self.readUnsignedInt(1))


# -------------------------------------------------------------------
# special record handlers: SMIL animation

class AnimNode(BaseRecordHandler):
    """Animation node."""

    restartDesc=["default","always","whenNotActive","never"]
    groupTypeDesc=["parallel","sequential","node","media","unknown"]
    fillDesc=["unknown","always","whenOff","never"]
    nodeActivationDesc=["unknown","onClick","withPrevious","afterPrevious",
                        "mainSequence","interactiveSequence","timingRoot"]

    def parseBytes (self):
        self.readUnsignedInt(4)
        self.appendLine("restart: %s"%self.restartDesc[self.readUnsignedInt(4)])
        self.appendLine("groupType: %s"%self.groupTypeDesc[self.readUnsignedInt(4)])
        self.appendLine("fill: %s"%self.fillDesc[self.readUnsignedInt(4)])
        self.readUnsignedInt(4)
        self.readUnsignedInt(4)
        self.appendLine("duration: %f secs"%(self.readSignedInt(4)/1000.0))
        nodeKind = self.readUnsignedInt(4)
        if nodeKind == 25:
            self.appendLine("nodeKind: animation")
        elif nodeKind == 24:
            self.appendLine("nodeKind: transitionFilter")
        else:
            self.appendLine("nodeKind: unknown/ignore")


class AnimAttributeValue(BaseRecordHandler):
    """Animation attribute values."""

    def handleByte (self):
        self.appendLine("byte value: %2.2Xh"%self.readUnsignedInt(1))

    def handleLong (self):
        self.appendLine("long value: %d"%self.readUnsignedInt(4))

    def handleFloat (self):
        self.appendLine("float value: %f"%globals.getFloat(self.readBytes(4)))

    def handleString (self):
        value = globals.getUTF8FromUTF16(globals.getTextBytes(self.readRemainingBytes()))
        self.appendLine("text value: '%s'"%value)

    valueHandlers=[handleByte,handleLong,handleFloat,handleString]

    def parseBytes (self):
        valueType = self.readUnsignedInt(1)
        self.valueHandlers[valueType](self)


class AnimateData(BaseRecordHandler):
    """Animate data values."""

    calcModeDesc=["discrete","linear","formula"]
    valueTypeDesc=["string","number","color"]
    def parseBytes (self):
        self.appendLine("calc mode: %s"%self.calcModeDesc[self.readUnsignedInt(4)])
        self.appendLine("flags: %4.4Xh"%self.readUnsignedInt(4))
        self.appendLine("value type: %s"%self.valueTypeDesc[self.readUnsignedInt(4)])


class AnimKeyTime(BaseRecordHandler):
    """Animate key times."""

    def parseBytes (self):
        self.appendLine("time: %f"%(self.readSignedInt(4)/1000.0))


class AnimTrigger(BaseRecordHandler):
    """Animation trigger."""

    triggerDesc=["none","onBegin","onEnd","beginEvent","endEvent","onClick",
                 "onDoubleClick","onMouseEnter","onMouseLeave","onNext",
                 "onPrev","onStopAudio"]
    def parseBytes (self):
        self.readUnsignedInt(4)
        self.appendLine("trigger: %s"%self.triggerDesc[self.readUnsignedInt(4)])
        self.readUnsignedInt(4)
        self.appendLine("begin time: %f"%(self.readSignedInt(4)/1000.0))


class AnimKeyTime(BaseRecordHandler):
    """Animate key times."""

    def parseBytes (self):
        self.appendLine("time: %f"%(self.readSignedInt(4)/1000.0))


class AnimValue(BaseRecordHandler):
    """Animate values."""

    def handleDefault (self):
        self.appendLine("unknown value: %Xh"%self.readUnsignedInt(4))

    def handleRepeat (self):
        self.appendLine("repeat count: %f"%globals.getFloat(self.readBytes(4)))

    def handleAccelerate (self):
        self.appendLine("accelerate amount: %f"%globals.getFloat(self.readBytes(4)))

    def handleDecelerate (self):
        self.appendLine("decelerate amount: %f"%globals.getFloat(self.readBytes(4)))

    def handleAutoReverse (self):
        if self.readUnsignedInt(4) != 0:
            self.appendLine("autoReverse is on")

    valueHandlers=[handleRepeat,handleDefault,handleDefault,handleAccelerate,handleDecelerate,handleAutoReverse]

    def parseBytes (self):
        valueType = self.readUnsignedInt(4)
        self.valueHandlers[valueType](self)


class AnimReference(BaseRecordHandler):
    """Animation reference object."""

    def handleDefault (self,type,mode):
        self.appendLine("unknown ref kind: %Xh (mode %Xh)"%(type,mode))

    def handleShapeAsWhole (self,type,mode):
        self.appendLine("whole shape animation: shape ID %d"%self.readUnsignedInt(4))

    def handleShapeOnePara (self,type,mode):
        self.appendLine("one paragraph of shape: shape ID %d"%self.readUnsignedInt(4))
        self.appendLine("begin character: %d"%self.readSignedInt(4))
        self.appendLine("end character: %d"%self.readSignedInt(4))

    def handleShapeOnlyBackground (self,type,mode):
        self.appendLine("only background of shape: shape ID %d"%self.readUnsignedInt(4))

    def handleShapeOnlyText (self,type,mode):
        self.appendLine("only text content of shape: shape ID %d"%self.readUnsignedInt(4))

    shapeRefModeHandler=[handleShapeAsWhole,handleDefault,handleShapeOnePara,
                         handleDefault,handleDefault,handleDefault,
                         handleShapeOnlyBackground,handleDefault,handleShapeOnlyText]
    def handleShape (self,type,mode):
        self.shapeRefModeHandler[mode](self,type,mode)

    def handleSound (self,type,mode):
        self.appendLine("sound object: ID %d"%self.readUnsignedInt(4))

    def handleAudio (self,type,mode):
        self.appendLine("audio shape: shape ID %d"%self.readUnsignedInt(4))

    def handleVideo (self,type,mode):
        self.appendLine("video shape: shape ID %d"%self.readUnsignedInt(4))

    refTypeHandler=[handleDefault,handleShape,handleSound,handleAudio,handleVideo]
    def parseBytes (self):
        refMode = self.readUnsignedInt(4)
        refType = self.readUnsignedInt(4)
        self.refTypeHandler[refType](self,refType,refMode)


class TextRulerAtom(BaseRecordHandler):
    """Text Ruler Atom."""
    def parseBytes (self):
        rulerMask = self.readUnsignedInt(4)

        self.appendLine("ruler mask %Xh"%rulerMask)

        if rulerMask & 0x0002:
            levels = self.readUnsignedInt(2)
            self.appendLine("number of indent levels %d"%levels)

        if rulerMask & 0x0001:
            tabSize = self.readUnsignedInt(2)
            self.appendLine("default tab size %d"%tabSize)

        if rulerMask & 0x0004:
            numTabStops = self.readUnsignedInt(2)
            for i in xrange(0, numTabStops):
                tabDistance = self.readUnsignedInt(2)
                tabAlignment = self.readUnsignedInt(2)
                self.appendParaProp("para tab stop %d: distance %d, align %4.4Xh"%(i, tabDistance, tabAlignment))

        if rulerMask & 0x0008:
            leftMargin = self.readUnsignedInt(2)
            self.appendLine("leftMargin0 %d"%leftMargin)

        if rulerMask & 0x0100:
            leftIndent = self.readUnsignedInt(2)
            self.appendLine("leftIndent0 %d"%leftIndent)

        if rulerMask & 0x0010:
            leftMargin = self.readUnsignedInt(2)
            self.appendLine("leftMargin1 %d"%leftMargin)

        if rulerMask & 0x0200:
            leftIndent = self.readUnsignedInt(2)
            self.appendLine("leftIndent1 %d"%leftIndent)

        if rulerMask & 0x0020:
            leftMargin = self.readUnsignedInt(2)
            self.appendLine("leftMargin2 %d"%leftMargin)

        if rulerMask & 0x0400:
            leftIndent = self.readUnsignedInt(2)
            self.appendLine("leftIndent2 %d"%leftIndent)

        if rulerMask & 0x0040:
            leftMargin = self.readUnsignedInt(2)
            self.appendLine("leftMargin3 %d"%leftMargin)

        if rulerMask & 0x0800:
            leftIndent = self.readUnsignedInt(2)
            self.appendLine("leftIndent3 %d"%leftIndent)

        if rulerMask & 0x0080:
            leftMargin = self.readUnsignedInt(2)
            self.appendLine("leftMargin4 %d"%leftMargin)

        if rulerMask & 0x1000:
            leftIndent = self.readUnsignedInt(2)
            self.appendLine("leftIndent4 %d"%leftIndent)

    def appendParaProp (self, text):
        self.appendLine("para prop given: "+text)

# -------------------------------------------------------------------
# special record handlers: text style properties

class TextStyles(BaseRecordHandler):
    """Text style properties."""

    def parseBytes (self):
        # any shape text set? if not, no chance to calc run lengths
        if not "ShapeText" in self.streamProperties:
            self.appendLine("no shape text given, assuming length of 1")
            textLen = 1
        else:
            textLen = len(self.streamProperties["ShapeText"])

        # 4 bytes: <count> characters of shape text this para run is meant for
        # <para attribs>
        # repeat until all shape text is consumed
        charPos = 0
        while not self.isEmpty() and charPos < textLen:
            runLen = self.readUnsignedInt(4)
            charPos += runLen
            indentLevel = self.readUnsignedInt(2)
            self.appendLine("para props for %d chars, indent: %d"%(runLen,indentLevel))
            self.parseParaStyle()
            self.appendLine("-"*61)

        # 4 bytes: <count> characters of shape text this char run is meant for
        # <char attribs>
        # repeat until all shape text is consumed
        charPos = 0
        while not self.isEmpty() and charPos < textLen:
            runLen = self.readUnsignedInt(4)
            charPos += runLen
            self.appendLine("char props for %d chars"%runLen)
            self.parseCharStyle()
            self.appendLine("-"*61)

    def appendParaProp (self, text):
        self.appendLine("para prop given: "+text)

    def appendCharProp (self, text):
        self.appendLine("char prop given: "+text)

    def parseParaStyle (self):
        styleMask = self.readUnsignedInt(4)

        if styleMask & 0x000F:
            bulletFlags = self.readUnsignedInt(2)
            # filter bits not in flag field
            bulletFlags = bulletFlags & (styleMask & 0x000F)
            self.appendParaProp("bullet flags %4.4Xh"%bulletFlags)

        if styleMask & 0x0080:
            bulletChar = self.readUnsignedInt(2)
            self.appendParaProp("bullet char %4.4Xh"%bulletChar)

        if styleMask & 0x0010:
            bulletTypeface = self.readUnsignedInt(2)
            self.appendParaProp("bullet typeface %d"%bulletTypeface)

        if styleMask & 0x0040:
            bulletSize = self.readSignedInt(2)
            self.appendParaProp("bullet size %d"%bulletSize)

        if styleMask & 0x0020:
            bulletColorAtom = ColorPropertyHandler(self.readUnsignedInt(2), self.readUnsignedInt(4), False, False, [], self.appendParaProp)
            bulletColorAtom.output()
            self.appendParaProp("bullet color atom")

        if styleMask & 0x0800:
            paraAlignment = self.readSignedInt(2)
            self.appendParaProp("para alignment %4.4Xh"%paraAlignment)

        if styleMask & 0x0400:
            paraIndent = self.readSignedInt(2)
            self.appendParaProp("para indent %d"%paraIndent)

        if styleMask & 0x0200:
            unused = self.readSignedInt(2)
            self.appendParaProp("unused para property %4.4Xh"%unused)

        if styleMask & 0x0100:
            paraLeftMargin = self.readSignedInt(2)
            self.appendParaProp("para left margin %d"%paraLeftMargin)

        if styleMask & 0x1000:
            paraLineSpacing = self.readSignedInt(2)
            self.appendParaProp("para linespacing %d"%paraLineSpacing)

        if styleMask & 0x2000:
            paraSpaceBefore = self.readSignedInt(2)
            self.appendParaProp("para space before %d"%paraSpaceBefore)

        if styleMask & 0x4000:
            paraSpaceAfter = self.readSignedInt(2)
            self.appendParaProp("para space after %d"%paraSpaceAfter)

        if styleMask & 0x8000:
            paraDefaultTabSize = self.readSignedInt(2)
            self.appendParaProp("para default tab size %d"%paraDefaultTabSize)

        if styleMask & 0x100000:
            numTabStops = self.readUnsignedInt(2)
            for i in xrange(0, numTabStops):
                tabDistance = self.readUnsignedInt(2)
                tabAlignment = self.readUnsignedInt(2)
                self.appendParaProp("para tab stop %d: distance %d, align %4.4Xh"%(i, tabDistance, tabAlignment))

        if styleMask & 0x10000:
            paraBaseline = self.readUnsignedInt(2)
            self.appendParaProp("para baseline %d"%paraBaseline)

        if styleMask & 0xE0000:
            paraAsianLinebreaking = self.readUnsignedInt(2)
            # filter bits not in flag field
            paraAsianLinebreaking = paraAsianLinebreaking & ((styleMask & 0xE0000) // 0x20000)
            self.appendParaProp("para asian line breaking flags %4.4Xh"%paraAsianLinebreaking)

        if styleMask & 0x200000:
            paraTextDirection = self.readUnsignedInt(2)
            self.appendParaProp("para text direction %4.4Xh"%paraTextDirection)

    def parseCharStyle (self):
        styleMask = self.readUnsignedInt(4)

        if styleMask & 0xFFFF:
            charFlags = self.readUnsignedInt(2)
            self.appendCharProp("char flags %4.4Xh"%charFlags)

        if styleMask & 0x10000:
            typeFace = self.readUnsignedInt(2)
            self.appendCharProp("char typeface %d"%typeFace)

        if styleMask & 0x200000:
            oldTypeFace = self.readUnsignedInt(2)
            self.appendCharProp("char old asian typeface %d"%oldTypeFace)

        if styleMask & 0x400000:
            ansiTypeFace = self.readUnsignedInt(2)
            self.appendCharProp("char ansi typeface %d"%ansiTypeFace)

        if styleMask & 0x800000:
            symbolTypeFace = self.readUnsignedInt(2)
            self.appendCharProp("char symbol typeface %d"%symbolTypeFace)

        if styleMask & 0x20000:
            fontSize = self.readUnsignedInt(2)
            self.appendCharProp("char font size %d"%fontSize)

        if styleMask & 0x40000:
            charColorAtom = ColorPropertyHandler(self.readUnsignedInt(2), self.readUnsignedInt(4), False, False, [], self.appendCharProp)
            charColorAtom.output()
            self.appendCharProp("char color atom")

        if styleMask & 0x80000:
            fontPosition = self.readSignedInt(2)
            self.appendCharProp("char font position %d"%fontPosition)


class MasterTextStyles(TextStyles):
    """Master text style properties."""

    def parseBytes (self):
        self.appendLine("Master style for text type: %d"%self.recordInstance)
        self.appendLine("-"*61)

        # 2 bytes: number of indent levels following. each indent
        # level has one para and one char prop entry, the para prop
        # entry misses the indent specifier it has for StyleTextAtom.
        numLevels = self.readUnsignedInt(2)

        for i in xrange(0, numLevels):
            self.appendLine("para props for indent level: %d"%i)
            self.parseParaStyle()
            self.appendLine("-"*61)
            self.appendLine("char props for indent level: %d"%i)
            self.parseCharStyle()
            self.appendLine("-"*61)


# -------------------------------------------------------------------
# special record handlers: property atoms

class BasePropertyHandler():
    """Base property handler."""

    def __init__ (self, propType, propValue, isComplex, isBlip, complexBytes, printer):
        self.propType = propType
        self.propValue = propValue
        self.isComplex = isComplex
        self.isBlip = isBlip
        self.bytes = complexBytes
        self.pos = 0
        self.printer = printer
        if self.propType in propData:
            self.propEntry = propData[self.propType]

    def output (self):
        if self.propType in propData:
            self.printer("%4.4Xh: %s = %8.8Xh [\"%s\" - default handler]"%(self.propType, self.propEntry[0],
                                                                           self.propValue, self.propEntry[2]))

class BoolPropertyHandler(BasePropertyHandler):
    """Bool properties."""

    def getTrueFalse (self, boolVal):
        if boolVal:
            return 'true'
        else:
            return 'false'

    def output (self):
        bitMask = 1
        for i in xrange(self.propType, self.propType-32, -1):
            if i in propData:
                propEntry = propData[i]
                if propEntry[1] == BoolPropertyHandler:
                    flagValue = self.getTrueFalse(self.propValue & bitMask)
                    self.printer("%4.4Xh: %s = %s [\"%s\"]"%(i, propEntry[0], flagValue, propEntry[2]))
            bitMask *= 2


class LongPropertyHandler(BasePropertyHandler):
    """Long property."""

    def output (self):
        if self.propType in propData:
            self.printer("%4.4Xh: %s = %d [\"%s\"]"%(self.propType, self.propEntry[0],
                                                     self.propValue, self.propEntry[2]))

class MsoArrayPropertyHandler(BasePropertyHandler):
    """MsoArray property."""

    def readBytes (self, length):
        r = self.bytes[self.pos:self.pos+length]
        self.pos += length
        return r

    def readUnsignedInt (self, length):
        bytes = self.readBytes(length)
        return globals.getUnsignedInt(bytes)

    def output (self):
        if self.isComplex:
            numElements = self.readUnsignedInt(2)
            dummy = self.readUnsignedInt(2)
            elementSize = self.readUnsignedInt(2)
            self.printer("%4.4Xh: %s: [\"%s\"]"%(self.propType, self.propEntry[0], self.propEntry[2]))
            for i in xrange(0, numElements):
                if elementSize in [0,1,2,4]:
                    currElem = self.readUnsignedInt(elementSize)
                    self.printer("%4.4Xh: %d = %Xh"%(self.propType,i,currElem))
                else:
                    bytes = self.readBytes(elementSize)
                    self.printer("%4.4Xh: %d = [complex type]"%(self.propType,i))

class UniCharPropertyHandler(BasePropertyHandler):
    """unicode string property."""

    def output (self):
        if self.isComplex:
            name = globals.getUTF8FromUTF16(globals.getTextBytes(self.bytes))
            self.printer("%4.4Xh: %s = %s: [\"%s\"]"%(self.propType, self.propEntry[0], name, self.propEntry[2]))

class FixedPointHandler(BasePropertyHandler):
    """FixedPoint property."""

    def output (self):
        value = self.propValue / 65536.0
        self.printer("%4.4Xh: %s = %f [\"%s\"]"%(self.propType, self.propEntry[0], value, self.propEntry[2]))

class ColorPropertyHandler(BasePropertyHandler):
    """Color property."""

    def output (self):
        propEntry = ["<color atom>", None, "undocumented color property"]
        if self.propType in propData:
            propEntry = propData[self.propType]
        self.printer("%4.4Xh: %s [\"%s\"]"%(self.propType,
                                            globals.stringizeColorRef(self.propValue,
                                                                      propEntry[0]),
                                            propEntry[2]))

class CharPropertyHandler(BasePropertyHandler):
    """string property."""

    def output (self):
        if self.isComplex:
            name = globals.getTextBytes(self.bytes)
            self.printer("%4.4Xh: %s = %s: [\"%s\"]"%(self.propType, self.propEntry[0], name, self.propEntry[2]))

class HandlesPropertyHandler(BasePropertyHandler):
    """handles property."""

class ZipStoragePropertyHandler(BasePropertyHandler):
    """zip storage."""

    def output (self):
        globals.outputZipContent(self.bytes, self.printer, 61)

# -------------------------------------------------------------------
# special record handler: properties
#
# IDs, shape types and comments from OOo's svx/inc/svx/msdffdef.hxx
# (slightly adapted)
#
# opcode: [canonical name, prop handler, comment]

propData = {
# Transform group
   0:  ["DFF_Prop_Left",                         LongPropertyHandler,      "left pos of unrotated shape in emu"],
   1:  ["DFF_Prop_Top",                          LongPropertyHandler,      "top pos of unrotated shape in emu"],
   2:  ["DFF_Prop_Right",                        LongPropertyHandler,      "right pos of unrotated shape in emu"],
   3:  ["DFF_Prop_Bottom",                       LongPropertyHandler,      "bottom pos of unrotated shape in emu"],
   4:  ["DFF_Prop_Rotation",                     FixedPointHandler,        "degrees"],
   5:  ["DFF_Prop_gvPage",                       LongPropertyHandler,      "no idea, MSOGV"],
   61: ["DFF_Prop_fChangePage",                  BoolPropertyHandler,      "no idea"],
   62: ["DFF_Prop_fFlipV",                       BoolPropertyHandler,      "vertical flip"],
   63: ["DFF_Prop_fFlipH",                       BoolPropertyHandler,      "horiz flip"],

# Protection group
 118:  ["DFF_Prop_LockAgainstUngrouping",        BoolPropertyHandler,              "Do not ungroup this shape"],
 119:  ["DFF_Prop_LockRotation",                 BoolPropertyHandler,              "No rotation"],
 120:  ["DFF_Prop_LockAspectRatio",              BoolPropertyHandler,              "Don't allow changes in aspect ratio"],
 121:  ["DFF_Prop_LockPosition",                 BoolPropertyHandler,              "Don't allow the shape to be moved"],
 122:  ["DFF_Prop_LockAgainstSelect",            BoolPropertyHandler,              "Shape may not be selected"],
 123:  ["DFF_Prop_LockCropping",                 BoolPropertyHandler,              "No cropping this shape"],
 124:  ["DFF_Prop_LockVertices",                 BoolPropertyHandler,              "Edit Points not allowed"],
 125:  ["DFF_Prop_LockText",                     BoolPropertyHandler,              "Do not edit text"],
 126:  ["DFF_Prop_LockAdjustHandles",            BoolPropertyHandler,              "Do not adjust"],
 127:  ["DFF_Prop_LockAgainstGrouping",          BoolPropertyHandler,              "Do not group this shape"],

# Text group
 128:  ["DFF_Prop_lTxid",                        LongPropertyHandler,              "id for the text, value determined by the host"],
 129:  ["DFF_Prop_dxTextLeft",                   LongPropertyHandler,              "margins relative to shape's inscribed text rectangle (in EMUs)"],
 130:  ["DFF_Prop_dyTextTop",                    LongPropertyHandler, ""],
 131:  ["DFF_Prop_dxTextRight",                  LongPropertyHandler, ""],
 132:  ["DFF_Prop_dyTextBottom",                 LongPropertyHandler, ""],
 133:  ["DFF_Prop_WrapText",                     LongPropertyHandler,              "Wrap text at shape margins"],
 134:  ["DFF_Prop_scaleText",                    LongPropertyHandler,              "Text zoom/scale (used if fFitTextToShape)"],
 135:  ["DFF_Prop_anchorText",                   LongPropertyHandler,              "How to anchor the text"],
 136:  ["DFF_Prop_txflTextFlow",                 LongPropertyHandler,              "Text flow"],
 137:  ["DFF_Prop_cdirFont",                     LongPropertyHandler,              "Font rotation in 90 degree steps"],
 138:  ["DFF_Prop_hspNext",                      LongPropertyHandler,              "ID of the next shape (used by Word for linked textboxes)"],
 139:  ["DFF_Prop_txdir",                        LongPropertyHandler,              "Bi-Di Text direction"],
 140:  ["DFF_Prop_ccol",                         LongPropertyHandler,              "Column count"],
 141:  ["DFF_Prop_dzColMargin",                  LongPropertyHandler,              "Column margin on both sides, in emu"],
 187:  ["DFF_Prop_SelectText",                   BoolPropertyHandler,              "TRUE if single click selects text, FALSE if two clicks"],
 188:  ["DFF_Prop_AutoTextMargin",               BoolPropertyHandler,              "use host's margin calculations"],
 189:  ["DFF_Prop_RotateText",                   BoolPropertyHandler,              "Rotate text with shape"],
 190:  ["DFF_Prop_FitShapeToText",               BoolPropertyHandler,              "Size shape to fit text size"],
 191:  ["DFF_Prop_FitTextToShape",               BoolPropertyHandler,              "Size text to fit shape size"],

# GeoText group
 192:  ["DFF_Prop_gtextUNICODE",                 UniCharPropertyHandler,            "UNICODE text string"],
 193:  ["DFF_Prop_gtextRTF",                     CharPropertyHandler,             "RTF text string"],
 194:  ["DFF_Prop_gtextAlign",                   LongPropertyHandler,              "alignment on curve"],
 195:  ["DFF_Prop_gtextSize",                    LongPropertyHandler,              "default point size"],
 196:  ["DFF_Prop_gtextSpacing",                 FixedPointHandler,              "fixed point 16.16"],
 197:  ["DFF_Prop_gtextFont",                    UniCharPropertyHandler,            "font family name"],
 198:  ["DFF_Prop_gtextCSSFont",                 UniCharPropertyHandler,            "css font family name, preserves css font selectors"],
 240:  ["DFF_Prop_gtextFReverseRows",            BoolPropertyHandler,              "Reverse row order"],
 241:  ["DFF_Prop_fGtext",                       BoolPropertyHandler,              "Has text effect"],
 242:  ["DFF_Prop_gtextFVertical",               BoolPropertyHandler,              "Rotate characters"],
 243:  ["DFF_Prop_gtextFKern",                   BoolPropertyHandler,              "Kern characters"],
 244:  ["DFF_Prop_gtextFTight",                  BoolPropertyHandler,              "Tightening or tracking"],
 245:  ["DFF_Prop_gtextFStretch",                BoolPropertyHandler,              "Stretch to fit shape"],
 246:  ["DFF_Prop_gtextFShrinkFit",              BoolPropertyHandler,              "Char bounding box"],
 247:  ["DFF_Prop_gtextFBestFit",                BoolPropertyHandler,              "Scale text-on-path"],
 248:  ["DFF_Prop_gtextFNormalize",              BoolPropertyHandler,              "Stretch char height"],
 249:  ["DFF_Prop_gtextFDxMeasure",              BoolPropertyHandler,              "Do not measure along path"],
 250:  ["DFF_Prop_gtextFBold",                   BoolPropertyHandler,              "Bold font"],
 251:  ["DFF_Prop_gtextFItalic",                 BoolPropertyHandler,              "Italic font"],
 252:  ["DFF_Prop_gtextFUnderline",              BoolPropertyHandler,              "Underline font"],
 253:  ["DFF_Prop_gtextFShadow",                 BoolPropertyHandler,              "Shadow font"],
 254:  ["DFF_Prop_gtextFSmallcaps",              BoolPropertyHandler,              "Small caps font"],
 255:  ["DFF_Prop_gtextFStrikethrough",          BoolPropertyHandler,              "Strike through font"],

# Blip group
 256:  ["DFF_Prop_cropFromTop",                  FixedPointHandler,        "Fraction times total image height, as appropriate."],
 257:  ["DFF_Prop_cropFromBottom",               FixedPointHandler,        "Fraction times total image height, as appropriate."],
 258:  ["DFF_Prop_cropFromLeft",                 FixedPointHandler,        "Fraction times total image width, as appropriate."],
 259:  ["DFF_Prop_cropFromRight",                FixedPointHandler,        "Fraction times total image width, as appropriate."],
 260:  ["DFF_Prop_pib",                          LongPropertyHandler,              "Blip ID to display"],
 261:  ["DFF_Prop_pibName",                      UniCharPropertyHandler,            "Blip file name"],
 262:  ["DFF_Prop_pibFlags",                     LongPropertyHandler,              "Blip flags"],
 263:  ["DFF_Prop_pictureTransparent",           LongPropertyHandler,              "transparent color (none if ~0UL)"],
 264:  ["DFF_Prop_pictureContrast",              LongPropertyHandler,              "contrast setting"],
 265:  ["DFF_Prop_pictureBrightness",            LongPropertyHandler,              "brightness setting"],
 266:  ["DFF_Prop_pictureGamma",                 FixedPointHandler,        "gamma"],
 267:  ["DFF_Prop_pictureId",                    LongPropertyHandler,              "Host-defined ID for OLE objects (usually a pointer)"],
 268:  ["DFF_Prop_pictureDblCrMod",              LongPropertyHandler,              "MSO_CLR Modification used if shape has double shadow"],
 269:  ["DFF_Prop_pictureFillCrMod",             LongPropertyHandler, ""],
 270:  ["DFF_Prop_pictureLineCrMod",             LongPropertyHandler, ""],
 271:  ["DFF_Prop_pibPrint",                     LongPropertyHandler,              "Blip ID to display when printing"],
 272:  ["DFF_Prop_pibPrintName",                 UniCharPropertyHandler,            "Blip file name"],
 273:  ["DFF_Prop_pibPrintFlags",                LongPropertyHandler,              "Blip flags"],
 274:  ["DFF_Prop_movie",                        LongPropertyHandler,              "movie data"],
 282:  ["DFF_Prop_pictureRecolor",               ColorPropertyHandler,             "Recolor pic to this color"],
 313:  ["DFF_Prop_picturePreserveGrays",         BoolPropertyHandler,              "leave grays when doing color manipulation"],
 314:  ["DFF_Prop_fRewind",                      BoolPropertyHandler,              "rewind movie when done"],
 315:  ["DFF_Prop_fLooping",                     BoolPropertyHandler,              "Is movie looping"],
 316:  ["DFF_Prop_fNoHitTestPicture",            BoolPropertyHandler,              "Do not hit test the picture"],
 317:  ["DFF_Prop_pictureGray",                  BoolPropertyHandler,              "grayscale display"],
 318:  ["DFF_Prop_pictureBiLevel",               BoolPropertyHandler,              "bi-level display"],
 319:  ["DFF_Prop_pictureActive",                BoolPropertyHandler,              "Server is active (OLE objects only)"],

# Geometry group
 320:  ["DFF_Prop_geoLeft",                      LongPropertyHandler,              "Defines the G (geometry) coordinate space."],
 321:  ["DFF_Prop_geoTop",                       LongPropertyHandler, ""],
 322:  ["DFF_Prop_geoRight",                     LongPropertyHandler, ""],
 323:  ["DFF_Prop_geoBottom",                    LongPropertyHandler, ""],
 324:  ["DFF_Prop_shapePath",                    LongPropertyHandler,              "MSO_SHAPEPATH, todo"],
 325:  ["DFF_Prop_pVertices",                    MsoArrayPropertyHandler,         "An array of points, in G units."],
 326:  ["DFF_Prop_pSegmentInfo",                 MsoArrayPropertyHandler, ""],
 327:  ["DFF_Prop_adjustValue",                  LongPropertyHandler,              "Adjustment values corresponding to the positions of the"],
 328:  ["DFF_Prop_adjust2Value",                 LongPropertyHandler,              "adjust handles of the shape. The number of values used"],
 329:  ["DFF_Prop_adjust3Value",                 LongPropertyHandler,              "and their allowable ranges vary from shape type to shape type."],
 330:  ["DFF_Prop_adjust4Value",                 LongPropertyHandler, ""],
 331:  ["DFF_Prop_adjust5Value",                 LongPropertyHandler, ""],
 332:  ["DFF_Prop_adjust6Value",                 LongPropertyHandler, ""],
 333:  ["DFF_Prop_adjust7Value",                 LongPropertyHandler, ""],
 334:  ["DFF_Prop_adjust8Value",                 LongPropertyHandler, ""],
 335:  ["DFF_Prop_adjust9Value",                 LongPropertyHandler, ""],
 336:  ["DFF_Prop_adjust10Value",                LongPropertyHandler, ""],
 337:  ["DFF_Prop_connectorPoints",             MsoArrayPropertyHandler, ""],
 339:  ["DFF_Prop_stretchPointX",               LongPropertyHandler, ""],
 340:  ["DFF_Prop_stretchPointY",               LongPropertyHandler, ""],
 341:  ["DFF_Prop_Handles",                     HandlesPropertyHandler, ""],
 342:  ["DFF_Prop_pFormulas",                   LongPropertyHandler, ""],
 343:  ["DFF_Prop_textRectangles",              LongPropertyHandler, ""],
 344:  ["DFF_Prop_connectorType",               LongPropertyHandler,               "0=none, 1=segments, 2=custom, 3=rect"],
 345:  ["DFF_Prop_pFragments",                  MsoArrayPropertyHandler,           "Array of fragment ids"],
 377:  ["DFF_Prop_fColumnLine",                  BoolPropertyHandler,              "Column style may be set"],
 378:  ["DFF_Prop_fShadowOK",                    BoolPropertyHandler,              "Shadow may be set"],
 379:  ["DFF_Prop_f3DOK",                        BoolPropertyHandler,              "3D may be set"],
 380:  ["DFF_Prop_fLineOK",                      BoolPropertyHandler,              "Line style may be set"],
 381:  ["DFF_Prop_fGtextOK",                     BoolPropertyHandler,              "Text effect (FontWork) supported"],
 382:  ["DFF_Prop_fFillShadeShapeOK",            BoolPropertyHandler, ""],
 383:  ["DFF_Prop_fFillOK",                      BoolPropertyHandler,              "OK to fill the shape through the UI or VBA?"],

# Fill group
 384:  ["DFF_Prop_fillType",                     LongPropertyHandler,              "MSO_FILLTYPE Type of fill"],
 385:  ["DFF_Prop_fillColor",                    ColorPropertyHandler,             "Foreground color"],
 386:  ["DFF_Prop_fillOpacity",                  FixedPointHandler,        "Fill Opacity"],
 387:  ["DFF_Prop_fillBackColor",                ColorPropertyHandler,             "Background color"],
 388:  ["DFF_Prop_fillBackOpacity",              FixedPointHandler,        "Shades only"],
 389:  ["DFF_Prop_fillCrMod",                    ColorPropertyHandler,             "Modification for BW views"],
 390:  ["DFF_Prop_fillBlip",                     LongPropertyHandler,              "Pattern/texture blip ID"],
 391:  ["DFF_Prop_fillBlipName",                 UniCharPropertyHandler,            "Blip file name"],
 392:  ["DFF_Prop_fillBlipFlags",                LongPropertyHandler,              "Blip flags"],
 393:  ["DFF_Prop_fillWidth",                    LongPropertyHandler,              "How big (A units) to make a metafile texture."],
 394:  ["DFF_Prop_fillHeight",                   LongPropertyHandler, ""],
 395:  ["DFF_Prop_fillAngle",                    FixedPointHandler,              "Fade angle - degrees in 16.16"],
 396:  ["DFF_Prop_fillFocus",                    LongPropertyHandler,              "Linear shaded fill focus percent"],
 397:  ["DFF_Prop_fillToLeft",                   FixedPointHandler,        "Fraction 16.16"],
 398:  ["DFF_Prop_fillToTop",                    FixedPointHandler,        "Fraction 16.16"],
 399:  ["DFF_Prop_fillToRight",                  FixedPointHandler,        "Fraction 16.16"],
 400:  ["DFF_Prop_fillToBottom",                 FixedPointHandler,        "Fraction 16.16"],
 401:  ["DFF_Prop_fillRectLeft",                 LongPropertyHandler,              "For shaded fills, use the specified rectangle instead of the shape's bounding rect to define how large the fade is going to be."],
 402:  ["DFF_Prop_fillRectTop",                  LongPropertyHandler, ""],
 403:  ["DFF_Prop_fillRectRight",                LongPropertyHandler, ""],
 404:  ["DFF_Prop_fillRectBottom",               LongPropertyHandler, ""],
 405:  ["DFF_Prop_fillDztype",                   LongPropertyHandler, ""],
 406:  ["DFF_Prop_fillShadePreset",              LongPropertyHandler,              "Special shades"],
 407:  ["DFF_Prop_fillShadeColors",              MsoArrayPropertyHandler,         "a preset array of colors"],
 408:  ["DFF_Prop_fillOriginX",                  LongPropertyHandler, ""],
 409:  ["DFF_Prop_fillOriginY",                  LongPropertyHandler, ""],
 410:  ["DFF_Prop_fillShapeOriginX",             LongPropertyHandler, ""],
 411:  ["DFF_Prop_fillShapeOriginY",             LongPropertyHandler, ""],
 412:  ["DFF_Prop_fillShadeType",                LongPropertyHandler,              "Type of shading, if a shaded (gradient) fill."],
 441:  ["DFF_Prop_fRecolorFillAsPicture",        BoolPropertyHandler,              "Recolor pic according to pic recolor props from pic prop set"],
 442:  ["DFF_Prop_fUseShapeAnchor",              BoolPropertyHandler,              "Fit fill to shape anchor, not bounds"],
 443:  ["DFF_Prop_fFilled",                      BoolPropertyHandler,              "Is shape filled?"],
 444:  ["DFF_Prop_fHitTestFill",                 BoolPropertyHandler,              "Should we hit test fill?"],
 445:  ["DFF_Prop_fillShape",                    BoolPropertyHandler,              "Register pattern on shape"],
 446:  ["DFF_Prop_fillUseRect",                  BoolPropertyHandler,              "Use the large rect?"],
 447:  ["DFF_Prop_fNoFillHitTest",               BoolPropertyHandler,              "Hit test a shape as though filled"],

# Line group
 448:  ["DFF_Prop_lineColor",                    ColorPropertyHandler,             "Color of line"],
 449:  ["DFF_Prop_lineOpacity",                  LongPropertyHandler,              "Not implemented"],
 450:  ["DFF_Prop_lineBackColor",                ColorPropertyHandler,             "Background color"],
 451:  ["DFF_Prop_lineCrMod",                    ColorPropertyHandler,             "Modification for BW views"],
 452:  ["DFF_Prop_lineType",                     LongPropertyHandler,              "Type of line"],
 453:  ["DFF_Prop_lineFillBlip",                 LongPropertyHandler,              "Pattern/texture blip ID"],
 454:  ["DFF_Prop_lineFillBlipName",             UniCharPropertyHandler,            "Blip file name"],
 455:  ["DFF_Prop_lineFillBlipFlags",            LongPropertyHandler,              "Blip flags"],
 456:  ["DFF_Prop_lineFillWidth",                LongPropertyHandler,              "How big (A units) to make a metafile texture."],
 457:  ["DFF_Prop_lineFillHeight",               LongPropertyHandler, ""],
 458:  ["DFF_Prop_lineFillDztype",               LongPropertyHandler,              "How to interpret fillWidth/Height numbers."],
 459:  ["DFF_Prop_lineWidth",                    LongPropertyHandler,              "A units; 1pt == 12700 EMUs"],
 460:  ["DFF_Prop_lineMiterLimit",               FixedPointHandler,        "ratio (16.16) of width"],
 461:  ["DFF_Prop_lineStyle",                    LongPropertyHandler,              "Draw parallel lines?"],
 462:  ["DFF_Prop_lineDashing",                  LongPropertyHandler,              "Can be overridden by:"],
 463:  ["DFF_Prop_lineDashStyle",                MsoArrayPropertyHandler,         "As Win32 ExtCreatePen"],
 464:  ["DFF_Prop_lineStartArrowhead",           LongPropertyHandler,              "Arrow at start"],
 465:  ["DFF_Prop_lineEndArrowhead",             LongPropertyHandler,              "Arrow at end"],
 466:  ["DFF_Prop_lineStartArrowWidth",          LongPropertyHandler,              "Arrow at start"],
 467:  ["DFF_Prop_lineStartArrowLength",         LongPropertyHandler,              "Arrow at end"],
 468:  ["DFF_Prop_lineEndArrowWidth",            LongPropertyHandler,              "Arrow at start"],
 469:  ["DFF_Prop_lineEndArrowLength",           LongPropertyHandler,              "Arrow at end"],
 470:  ["DFF_Prop_lineJoinStyle",                LongPropertyHandler,              "How to join lines"],
 471:  ["DFF_Prop_lineEndCapStyle",              LongPropertyHandler,              "How to end lines"],
 505:  ["DFF_Prop_fInsetPen",                    BoolPropertyHandler,              "Draw line inside the shape"],
 506:  ["DFF_Prop_fInsetPenOK",                  BoolPropertyHandler,              "Enable inset pen property on this shape"],
 507:  ["DFF_Prop_fArrowheadsOK",                BoolPropertyHandler,              "Allow arrowheads if prop. is set"],
 508:  ["DFF_Prop_fLine",                        BoolPropertyHandler,              "Any line?"],
 509:  ["DFF_Prop_fHitTestLine",                 BoolPropertyHandler,              "Should we hit test lines?"],
 510:  ["DFF_Prop_lineFillShape",                BoolPropertyHandler,              "Register pattern on shape"],
 511:  ["DFF_Prop_fNoLineDrawDash",              BoolPropertyHandler,              "Draw a dashed line if no line"],

# Shadow group
 512:  ["DFF_Prop_shadowType",                   LongPropertyHandler,              "Type of effect"],
 513:  ["DFF_Prop_shadowColor",                  ColorPropertyHandler,             "Foreground color"],
 514:  ["DFF_Prop_shadowHighlight",              ColorPropertyHandler,             "Embossed color"],
 515:  ["DFF_Prop_shadowCrMod",                  ColorPropertyHandler,             "Modification for BW views"],
 516:  ["DFF_Prop_shadowOpacity",                FixedPointHandler,        "Fixed 16.16"],
 517:  ["DFF_Prop_shadowOffsetX",                LongPropertyHandler,              "Offset shadow"],
 518:  ["DFF_Prop_shadowOffsetY",                LongPropertyHandler,              "Offset shadow"],
 519:  ["DFF_Prop_shadowSecondOffsetX",          LongPropertyHandler,              "Double offset shadow"],
 520:  ["DFF_Prop_shadowSecondOffsetY",          LongPropertyHandler,              "Double offset shadow"],
 521:  ["DFF_Prop_shadowScaleXToX",              FixedPointHandler,        "16.16"],
 522:  ["DFF_Prop_shadowScaleYToX",              FixedPointHandler,        "16.16"],
 523:  ["DFF_Prop_shadowScaleXToY",              FixedPointHandler,        "16.16"],
 524:  ["DFF_Prop_shadowScaleYToY",              FixedPointHandler,        "16.16"],
 525:  ["DFF_Prop_shadowPerspectiveX",           FixedPointHandler,        "16.16 / weight"],
 526:  ["DFF_Prop_shadowPerspectiveY",           FixedPointHandler,        "16.16 / weight"],
 527:  ["DFF_Prop_shadowWeight",                 LongPropertyHandler,              "scaling factor"],
 528:  ["DFF_Prop_shadowOriginX",                LongPropertyHandler, ""],
 529:  ["DFF_Prop_shadowOriginY",                LongPropertyHandler, ""],
 574:  ["DFF_Prop_fShadow",                      BoolPropertyHandler,              "Any shadow?"],
 575:  ["DFF_Prop_fshadowObscured",              BoolPropertyHandler,              "Excel5-style shadow"],

# Perspective group
 576:  ["DFF_Prop_perspectiveType",              LongPropertyHandler,              "Where transform applies"],
 577:  ["DFF_Prop_perspectiveOffsetX",           LongPropertyHandler,              "The LONG values define a transformation matrix, effectively, each value is scaled by the perspectiveWeight parameter."],
 578:  ["DFF_Prop_perspectiveOffsetY",           LongPropertyHandler, ""],
 579:  ["DFF_Prop_perspectiveScaleXToX",         LongPropertyHandler, ""],
 580:  ["DFF_Prop_perspectiveScaleYToX",         LongPropertyHandler, ""],
 581:  ["DFF_Prop_perspectiveScaleXToY",         LongPropertyHandler, ""],
 582:  ["DFF_Prop_perspectiveScaleYToY",         LongPropertyHandler, ""],
 583:  ["DFF_Prop_perspectivePerspectiveX",      LongPropertyHandler, ""],
 584:  ["DFF_Prop_perspectivePerspectiveY",      LongPropertyHandler, ""],
 585:  ["DFF_Prop_perspectiveWeight",            LongPropertyHandler,              "Scaling factor"],
 586:  ["DFF_Prop_perspectiveOriginX",           LongPropertyHandler, ""],
 587:  ["DFF_Prop_perspectiveOriginY",           LongPropertyHandler, ""],
 639:  ["DFF_Prop_fPerspective",                 BoolPropertyHandler,              "On/off"],

# 3d object group
 640:  ["DFF_Prop_c3DSpecularAmt",               FixedPointHandler,        "Fixed-point 16.16"],
 641:  ["DFF_Prop_c3DDiffuseAmt",                FixedPointHandler,        "Fixed-point 16.16"],
 642:  ["DFF_Prop_c3DShininess",                 LongPropertyHandler,              "Default gives OK results"],
 643:  ["DFF_Prop_c3DEdgeThickness",             LongPropertyHandler,              "Specular edge thickness"],
 644:  ["DFF_Prop_c3DExtrudeForward",            LongPropertyHandler,              "Distance of extrusion in EMUs"],
 645:  ["DFF_Prop_c3DExtrudeBackward",           LongPropertyHandler, ""],
 646:  ["DFF_Prop_c3DExtrudePlane",              LongPropertyHandler,              "Extrusion direction"],
 647:  ["DFF_Prop_c3DExtrusionColor",            ColorPropertyHandler,             "Basic color of extruded part of shape; the lighting model used will determine the exact shades used when rendering."],
 648:  ["DFF_Prop_c3DCrMod",                     ColorPropertyHandler,             "Modification for BW views"],
 700:  ["DFF_Prop_f3D",                          BoolPropertyHandler,              "Does this shape have a 3D effect?"],
 701:  ["DFF_Prop_fc3DMetallic",                 BoolPropertyHandler,              "Use metallic specularity?"],
 702:  ["DFF_Prop_fc3DUseExtrusionColor",        BoolPropertyHandler, ""],
 703:  ["DFF_Prop_fc3DLightFace",                BoolPropertyHandler, ""],

# 3d style group
 704:  ["DFF_Prop_c3DYRotationAngle",            FixedPointHandler,        "degrees (16.16) about y axis"],
 705:  ["DFF_Prop_c3DXRotationAngle",            FixedPointHandler,        "degrees (16.16) about x axis"],
 706:  ["DFF_Prop_c3DRotationAxisX",             LongPropertyHandler,              "These specify the rotation axis; only their relative magnitudes matter."],
 707:  ["DFF_Prop_c3DRotationAxisY",             LongPropertyHandler, ""],
 708:  ["DFF_Prop_c3DRotationAxisZ",             LongPropertyHandler, ""],
 709:  ["DFF_Prop_c3DRotationAngle",             FixedPointHandler,        "degrees (16.16) about axis"],
 710:  ["DFF_Prop_c3DRotationCenterX",           FixedPointHandler,        "rotation center x (16.16 or g-units)"],
 711:  ["DFF_Prop_c3DRotationCenterY",           FixedPointHandler,        "rotation center y (16.16 or g-units)"],
 712:  ["DFF_Prop_c3DRotationCenterZ",           FixedPointHandler,        "rotation center z (absolute (emus))"],
 713:  ["DFF_Prop_c3DRenderMode",                LongPropertyHandler,              "Full,wireframe, or bcube"],
 714:  ["DFF_Prop_c3DTolerance",                 FixedPointHandler,        "pixels (16.16)"],
 715:  ["DFF_Prop_c3DXViewpoint",                LongPropertyHandler,              "X view point (emus)"],
 716:  ["DFF_Prop_c3DYViewpoint",                LongPropertyHandler,              "Y view point (emus)"],
 717:  ["DFF_Prop_c3DZViewpoint",                LongPropertyHandler,              "Z view distance (emus)"],
 718:  ["DFF_Prop_c3DOriginX",                   LongPropertyHandler, ""],
 719:  ["DFF_Prop_c3DOriginY",                   LongPropertyHandler, ""],
 720:  ["DFF_Prop_c3DSkewAngle",                 FixedPointHandler,        "degree (16.16) skew angle"],
 721:  ["DFF_Prop_c3DSkewAmount",                LongPropertyHandler,              "Percentage skew amount"],
 722:  ["DFF_Prop_c3DAmbientIntensity",          FixedPointHandler,        "Fixed point intensity"],
 723:  ["DFF_Prop_c3DKeyX",                      LongPropertyHandler,              "Key light source direction; only their relative magnitudes matter"],
 724:  ["DFF_Prop_c3DKeyY",                      LongPropertyHandler,              "Key light source direction; only their relative magnitudes matter"],
 725:  ["DFF_Prop_c3DKeyZ",                      LongPropertyHandler,              "Key light source direction; only their relative magnitudes matter"],
 726:  ["DFF_Prop_c3DKeyIntensity",              FixedPointHandler,        "Fixed point intensity"],
 727:  ["DFF_Prop_c3DFillX",                     LongPropertyHandler,              "Fill light source direction; only their relative magnitudes matter"],
 728:  ["DFF_Prop_c3DFillY",                     LongPropertyHandler,              "Fill light source direction; only their relative magnitudes matter"],
 729:  ["DFF_Prop_c3DFillZ",                     LongPropertyHandler,              "Fill light source direction; only their relative magnitudes matter"],
 730:  ["DFF_Prop_c3DFillIntensity",             FixedPointHandler,        "Fixed point intensity"],
 763:  ["DFF_Prop_fc3DConstrainRotation",        BoolPropertyHandler, ""],
 764:  ["DFF_Prop_fc3DRotationCenterAuto",       BoolPropertyHandler, ""],
 765:  ["DFF_Prop_fc3DParallel",                 BoolPropertyHandler,              "Parallel projection?"],
 766:  ["DFF_Prop_fc3DKeyHarsh",                 BoolPropertyHandler,              "Is key lighting harsh?"],
 767:  ["DFF_Prop_fc3DFillHarsh",                BoolPropertyHandler,              "Is fill lighting harsh?"],

# shape group
 769:  ["DFF_Prop_hspMaster",                    LongPropertyHandler,              "master shape"],
 771:  ["DFF_Prop_cxstyle",                      LongPropertyHandler,              "Type of connector"],
 772:  ["DFF_Prop_bWMode",                       LongPropertyHandler,              "Settings for modifications to be made when in different forms of black-and-white mode."],
 773:  ["DFF_Prop_bWModePureBW",                 LongPropertyHandler, ""],
 774:  ["DFF_Prop_bWModeBW",                     LongPropertyHandler, ""],
 826:  ["DFF_Prop_fOleIcon",                     BoolPropertyHandler,              "For OLE objects, whether the object is in icon form"],
 827:  ["DFF_Prop_fPreferRelativeResize",        BoolPropertyHandler,              "For UI only. Prefer relative resizing."],
 828:  ["DFF_Prop_fLockShapeType",               BoolPropertyHandler,              "Lock the shape type (don't allow Change Shape)"],
 830:  ["DFF_Prop_fDeleteAttachedObject",        BoolPropertyHandler, ""],
 831:  ["DFF_Prop_fBackground",                  BoolPropertyHandler,              "If TRUE, this is the background shape."],

# callout group
 832:  ["DFF_Prop_spcot",                        LongPropertyHandler,              "Callout type"],
 833:  ["DFF_Prop_dxyCalloutGap",                LongPropertyHandler,              "Distance from box to first point.(EMUs)"],
 834:  ["DFF_Prop_spcoa",                        LongPropertyHandler,              "Callout angle (any, 30,45,60,90,0)"],
 835:  ["DFF_Prop_spcod",                        LongPropertyHandler,              "Callout drop type"],
 836:  ["DFF_Prop_dxyCalloutDropSpecified",      LongPropertyHandler,              "if mso_spcodSpecified, the actual drop distance"],
 837:  ["DFF_Prop_dxyCalloutLengthSpecified",    LongPropertyHandler,              "if fCalloutLengthSpecified, the actual distance"],
 889:  ["DFF_Prop_fCallout",                     BoolPropertyHandler,              "Is the shape a callout?"],
 890:  ["DFF_Prop_fCalloutAccentBar",            BoolPropertyHandler,              "does callout have accent bar"],
 891:  ["DFF_Prop_fCalloutTextBorder",           BoolPropertyHandler,              "does callout have a text border"],
 892:  ["DFF_Prop_fCalloutMinusX",               BoolPropertyHandler, ""],
 893:  ["DFF_Prop_fCalloutMinusY",               BoolPropertyHandler, ""],
 894:  ["DFF_Prop_fCalloutDropAuto",             BoolPropertyHandler,              "If true, then we occasionally invert the drop distance"],
 895:  ["DFF_Prop_fCalloutLengthSpecified",      BoolPropertyHandler,              "if true, we look at dxyCalloutLengthSpecified"],

# group shape group
 896:  ["DFF_Prop_wzName",                       UniCharPropertyHandler,            "Shape Name (present only if explicitly set)"],
 897:  ["DFF_Prop_wzDescription",                UniCharPropertyHandler,            "alternate text"],
 898:  ["DFF_Prop_pihlShape",                    LongPropertyHandler,              "The hyperlink in the shape."],
 899:  ["DFF_Prop_pWrapPolygonVertices",         MsoArrayPropertyHandler,         "The polygon that text will be wrapped around (Word)"],
 900:  ["DFF_Prop_dxWrapDistLeft",               LongPropertyHandler,              "Left wrapping distance from text (Word)"],
 901:  ["DFF_Prop_dyWrapDistTop",                LongPropertyHandler,              "Top wrapping distance from text (Word)"],
 902:  ["DFF_Prop_dxWrapDistRight",              LongPropertyHandler,              "Right wrapping distance from text (Word)"],
 903:  ["DFF_Prop_dyWrapDistBottom",             LongPropertyHandler,              "Bottom wrapping distance from text (Word)"],
 904:  ["DFF_Prop_lidRegroup",                   LongPropertyHandler,              "Regroup ID"],
 905:  ["DFF_Prop_groupLeft",                    LongPropertyHandler,              "group left pos"],
 906:  ["DFF_Prop_groupTop",                     LongPropertyHandler,              "group top pos"],
 907:  ["DFF_Prop_groupRight",                   LongPropertyHandler,              "group right pos"],
 908:  ["DFF_Prop_groupBottom",                  LongPropertyHandler,              "group bottom pos"],
 909:  ["DFF_Prop_wzTooltip",                    UniCharPropertyHandler,           "hyperlink tooltip"],
 910:  ["DFF_Prop_wzScript",                     UniCharPropertyHandler,           "javascript, vbscript of shape"],
 911:  ["DFF_Prop_xAlign",                       LongPropertyHandler,              "X pos cm from left"],
 912:  ["DFF_Prop_xRelTo",                       LongPropertyHandler,              "X relative to column"],
 913:  ["DFF_Prop_yAlign",                       LongPropertyHandler,              "Y pos cm below"],
 914:  ["DFF_Prop_yRelTo",                       LongPropertyHandler,              "Y relative to paragraph"],
 915:  ["DFF_Prop_pctHR",                        LongPropertyHandler,              "Percentage width for horizontal rule"],
 916:  ["DFF_Prop_alignHR",                      LongPropertyHandler,              "alignment for horiz rule: left=0, center=1, right=2"],
 917:  ["DFF_Prop_dxHeightHR",                   LongPropertyHandler,              "height for HR"],
 918:  ["DFF_Prop_dxWidthHR",                    LongPropertyHandler,              "width for HR"],
 919:  ["DFF_Prop_wzScriptEx",                   UniCharPropertyHandler,           "extended script attrs"],
 920:  ["DFF_Prop_scriptLang",                   LongPropertyHandler,              "script language"],
 921:  ["DFF_Prop_wzScriptIdAttr",               UniCharPropertyHandler,           "Id script attr"],
 922:  ["DFF_Prop_wzScriptLangAttr",             UniCharPropertyHandler,           "Id script lang attr"],
 923:  ["DFF_Prop_borderTopColor",               ColorPropertyHandler,              "top border color (word)"],
 924:  ["DFF_Prop_borderLeftColor",              ColorPropertyHandler,              "left border color (word)"],
 925:  ["DFF_Prop_borderBottomColor",            ColorPropertyHandler,              "bottom border color (word)"],
 926:  ["DFF_Prop_borderRightColor",             ColorPropertyHandler,              "right border color (word)"],
 927:  ["DFF_Prop_tableProperties",              LongPropertyHandler, "Type of table: bit 1 plain, bit 2 placeholder, bit 3 rtl"],
 928:  ["DFF_Prop_tableRowProperties",           MsoArrayPropertyHandler, "Table row properties (row heights, actually)"],
 929:  ["DFF_Prop_scriptHtmlLocation",           LongPropertyHandler,              "script html location"],
 930:  ["DFF_Prop_wzApplet",                     UniCharPropertyHandler,           "applet body"],
 934:  ["DFF_Prop_wzAppletArg",                  UniCharPropertyHandler,           "applet arg"],
 937:  ["DFF_Prop_metroBlob",                    ZipStoragePropertyHandler,        "Embedded ooxml"],
 938:  ["DFF_Prop_dght",                         LongPropertyHandler,              "shape's z order. smaller means further away"],
 944:  ["DFF_Prop_fLayoutInCell",                BoolPropertyHandler,              "layout inside nested table when true"],
 945:  ["DFF_Prop_fIsBullet",                    BoolPropertyHandler,              "is shape picture bullet"],
 946:  ["DFF_Prop_fStandardHR",                  BoolPropertyHandler,              "true iff not graphical HR"],
 947:  ["DFF_Prop_fNoshadeHR",                   BoolPropertyHandler,              "true iff HR with NOSHADE set"],
 948:  ["DFF_Prop_fHorizRule",                   BoolPropertyHandler,              "true if horiz rule"],
 949:  ["DFF_Prop_fUserDrawn",                   BoolPropertyHandler,              "user drawn shape on ppt master"],
 950:  ["DFF_Prop_fAllowOverlap",                BoolPropertyHandler,              "overlap with other shapes permitted in web view"],
 951:  ["DFF_Prop_fReallyHidden",                BoolPropertyHandler,              "when hidden flag really set by user"],
 952:  ["DFF_Prop_fScriptAnchor",                BoolPropertyHandler,              "show visual clue that this shape has script block"],

# dunno group
 953:  ["DFF_Prop_fEditedWrap",                  BoolPropertyHandler,              "Has the wrap polygon been edited?"],
 954:  ["DFF_Prop_fBehindDocument",              BoolPropertyHandler,              "Word-only (shape is behind text)"],
 955:  ["DFF_Prop_fOnDblClickNotify",            BoolPropertyHandler,              "Notify client on a double click"],
 956:  ["DFF_Prop_fIsButton",                    BoolPropertyHandler,              "A button shape (i.e., clicking performs an action). Set for shapes with attached hyperlinks or macros."],
 957:  ["DFF_Prop_fOneD",                        BoolPropertyHandler,              "1D adjustment"],
 958:  ["DFF_Prop_fHidden",                      BoolPropertyHandler,              "Do not display"],
 959:  ["DFF_Prop_fPrint",                       BoolPropertyHandler,              "Print this shape"],

# clip group
 1728: ["DFF_Prop_pVerticesClip",                MsoArrayPropertyHandler,          "vertices of clip path"],
 1729: ["DFF_Prop_pSegmentInfoClip",             MsoArrayPropertyHandler,          "segment info of clip path"],
 1730: ["DFF_Prop_shapePathClip",                LongPropertyHandler,              "type of clipping path"],
 1790: ["DFF_Prop_fClipToWrap",                  BoolPropertyHandler,              "clip shape to text tight wrap polygon"],
 1791: ["DFF_Prop_fClippedOk",                   BoolPropertyHandler,              "enable additional clipping"]

}


shapeTypes = {
   0:  ["mso_sptNotPrimitive"],
   1:  ["mso_sptRectangle"],
   2:  ["mso_sptRoundRectangle"],
   3:  ["mso_sptEllipse"],
   4:  ["mso_sptDiamond"],
   5:  ["mso_sptIsocelesTriangle"],
   6:  ["mso_sptRightTriangle"],
   7:  ["mso_sptParallelogram"],
   8:  ["mso_sptTrapezoid"],
   9:  ["mso_sptHexagon"],
   10:  ["mso_sptOctagon"],
   11:  ["mso_sptPlus"],
   12:  ["mso_sptStar"],
   13:  ["mso_sptArrow"],
   14:  ["mso_sptThickArrow"],
   15:  ["mso_sptHomePlate"],
   16:  ["mso_sptCube"],
   17:  ["mso_sptBalloon"],
   18:  ["mso_sptSeal"],
   19:  ["mso_sptArc"],
   20:  ["mso_sptLine"],
   21:  ["mso_sptPlaque"],
   22:  ["mso_sptCan"],
   23:  ["mso_sptDonut"],
   24:  ["mso_sptTextSimple"],
   25:  ["mso_sptTextOctagon"],
   26:  ["mso_sptTextHexagon"],
   27:  ["mso_sptTextCurve"],
   28:  ["mso_sptTextWave"],
   29:  ["mso_sptTextRing"],
   30:  ["mso_sptTextOnCurve"],
   31:  ["mso_sptTextOnRing"],
   32:  ["mso_sptStraightConnector1"],
   33:  ["mso_sptBentConnector2"],
   34:  ["mso_sptBentConnector3"],
   35:  ["mso_sptBentConnector4"],
   36:  ["mso_sptBentConnector5"],
   37:  ["mso_sptCurvedConnector2"],
   38:  ["mso_sptCurvedConnector3"],
   39:  ["mso_sptCurvedConnector4"],
   40:  ["mso_sptCurvedConnector5"],
   41:  ["mso_sptCallout1"],
   42:  ["mso_sptCallout2"],
   43:  ["mso_sptCallout3"],
   44:  ["mso_sptAccentCallout1"],
   45:  ["mso_sptAccentCallout2"],
   46:  ["mso_sptAccentCallout3"],
   47:  ["mso_sptBorderCallout1"],
   48:  ["mso_sptBorderCallout2"],
   49:  ["mso_sptBorderCallout3"],
   50:  ["mso_sptAccentBorderCallout1"],
   51:  ["mso_sptAccentBorderCallout2"],
   52:  ["mso_sptAccentBorderCallout3"],
   53:  ["mso_sptRibbon"],
   54:  ["mso_sptRibbon2"],
   55:  ["mso_sptChevron"],
   56:  ["mso_sptPentagon"],
   57:  ["mso_sptNoSmoking"],
   58:  ["mso_sptSeal8"],
   59:  ["mso_sptSeal16"],
   60:  ["mso_sptSeal32"],
   61:  ["mso_sptWedgeRectCallout"],
   62:  ["mso_sptWedgeRRectCallout"],
   63:  ["mso_sptWedgeEllipseCallout"],
   64:  ["mso_sptWave"],
   65:  ["mso_sptFoldedCorner"],
   66:  ["mso_sptLeftArrow"],
   67:  ["mso_sptDownArrow"],
   68:  ["mso_sptUpArrow"],
   69:  ["mso_sptLeftRightArrow"],
   70:  ["mso_sptUpDownArrow"],
   71:  ["mso_sptIrregularSeal1"],
   72:  ["mso_sptIrregularSeal2"],
   73:  ["mso_sptLightningBolt"],
   74:  ["mso_sptHeart"],
   75:  ["mso_sptPictureFrame"],
   76:  ["mso_sptQuadArrow"],
   77:  ["mso_sptLeftArrowCallout"],
   78:  ["mso_sptRightArrowCallout"],
   79:  ["mso_sptUpArrowCallout"],
   80:  ["mso_sptDownArrowCallout"],
   81:  ["mso_sptLeftRightArrowCallout"],
   82:  ["mso_sptUpDownArrowCallout"],
   83:  ["mso_sptQuadArrowCallout"],
   84:  ["mso_sptBevel"],
   85:  ["mso_sptLeftBracket"],
   86:  ["mso_sptRightBracket"],
   87:  ["mso_sptLeftBrace"],
   88:  ["mso_sptRightBrace"],
   89:  ["mso_sptLeftUpArrow"],
   90:  ["mso_sptBentUpArrow"],
   91:  ["mso_sptBentArrow"],
   92:  ["mso_sptSeal24"],
   93:  ["mso_sptStripedRightArrow"],
   94:  ["mso_sptNotchedRightArrow"],
   95:  ["mso_sptBlockArc"],
   96:  ["mso_sptSmileyFace"],
   97:  ["mso_sptVerticalScroll"],
   98:  ["mso_sptHorizontalScroll"],
   99:  ["mso_sptCircularArrow"],
   100:  ["mso_sptNotchedCircularArrow"],
   101:  ["mso_sptUturnArrow"],
   102:  ["mso_sptCurvedRightArrow"],
   103:  ["mso_sptCurvedLeftArrow"],
   104:  ["mso_sptCurvedUpArrow"],
   105:  ["mso_sptCurvedDownArrow"],
   106:  ["mso_sptCloudCallout"],
   107:  ["mso_sptEllipseRibbon"],
   108:  ["mso_sptEllipseRibbon2"],
   109:  ["mso_sptFlowChartProcess"],
   110:  ["mso_sptFlowChartDecision"],
   111:  ["mso_sptFlowChartInputOutput"],
   112:  ["mso_sptFlowChartPredefinedProcess"],
   113:  ["mso_sptFlowChartInternalStorage"],
   114:  ["mso_sptFlowChartDocument"],
   115:  ["mso_sptFlowChartMultidocument"],
   116:  ["mso_sptFlowChartTerminator"],
   117:  ["mso_sptFlowChartPreparation"],
   118:  ["mso_sptFlowChartManualInput"],
   119:  ["mso_sptFlowChartManualOperation"],
   120:  ["mso_sptFlowChartConnector"],
   121:  ["mso_sptFlowChartPunchedCard"],
   122:  ["mso_sptFlowChartPunchedTape"],
   123:  ["mso_sptFlowChartSummingJunction"],
   124:  ["mso_sptFlowChartOr"],
   125:  ["mso_sptFlowChartCollate"],
   126:  ["mso_sptFlowChartSort"],
   127:  ["mso_sptFlowChartExtract"],
   128:  ["mso_sptFlowChartMerge"],
   129:  ["mso_sptFlowChartOfflineStorage"],
   130:  ["mso_sptFlowChartOnlineStorage"],
   131:  ["mso_sptFlowChartMagneticTape"],
   132:  ["mso_sptFlowChartMagneticDisk"],
   133:  ["mso_sptFlowChartMagneticDrum"],
   134:  ["mso_sptFlowChartDisplay"],
   135:  ["mso_sptFlowChartDelay"],
   136:  ["mso_sptTextPlainText"],
   137:  ["mso_sptTextStop"],
   138:  ["mso_sptTextTriangle"],
   139:  ["mso_sptTextTriangleInverted"],
   140:  ["mso_sptTextChevron"],
   141:  ["mso_sptTextChevronInverted"],
   142:  ["mso_sptTextRingInside"],
   143:  ["mso_sptTextRingOutside"],
   144:  ["mso_sptTextArchUpCurve"],
   145:  ["mso_sptTextArchDownCurve"],
   146:  ["mso_sptTextCircleCurve"],
   147:  ["mso_sptTextButtonCurve"],
   148:  ["mso_sptTextArchUpPour"],
   149:  ["mso_sptTextArchDownPour"],
   150:  ["mso_sptTextCirclePour"],
   151:  ["mso_sptTextButtonPour"],
   152:  ["mso_sptTextCurveUp"],
   153:  ["mso_sptTextCurveDown"],
   154:  ["mso_sptTextCascadeUp"],
   155:  ["mso_sptTextCascadeDown"],
   156:  ["mso_sptTextWave1"],
   157:  ["mso_sptTextWave2"],
   158:  ["mso_sptTextWave3"],
   159:  ["mso_sptTextWave4"],
   160:  ["mso_sptTextInflate"],
   161:  ["mso_sptTextDeflate"],
   162:  ["mso_sptTextInflateBottom"],
   163:  ["mso_sptTextDeflateBottom"],
   164:  ["mso_sptTextInflateTop"],
   165:  ["mso_sptTextDeflateTop"],
   166:  ["mso_sptTextDeflateInflate"],
   167:  ["mso_sptTextDeflateInflateDeflate"],
   168:  ["mso_sptTextFadeRight"],
   169:  ["mso_sptTextFadeLeft"],
   170:  ["mso_sptTextFadeUp"],
   171:  ["mso_sptTextFadeDown"],
   172:  ["mso_sptTextSlantUp"],
   173:  ["mso_sptTextSlantDown"],
   174:  ["mso_sptTextCanUp"],
   175:  ["mso_sptTextCanDown"],
   176:  ["mso_sptFlowChartAlternateProcess"],
   177:  ["mso_sptFlowChartOffpageConnector"],
   178:  ["mso_sptCallout90"],
   179:  ["mso_sptAccentCallout90"],
   180:  ["mso_sptBorderCallout90"],
   181:  ["mso_sptAccentBorderCallout90"],
   182:  ["mso_sptLeftRightUpArrow"],
   183:  ["mso_sptSun"],
   184:  ["mso_sptMoon"],
   185:  ["mso_sptBracketPair"],
   186:  ["mso_sptBracePair"],
   187:  ["mso_sptSeal4"],
   188:  ["mso_sptDoubleWave"],
   189:  ["mso_sptActionButtonBlank"],
   190:  ["mso_sptActionButtonHome"],
   191:  ["mso_sptActionButtonHelp"],
   192:  ["mso_sptActionButtonInformation"],
   193:  ["mso_sptActionButtonForwardNext"],
   194:  ["mso_sptActionButtonBackPrevious"],
   195:  ["mso_sptActionButtonEnd"],
   196:  ["mso_sptActionButtonBeginning"],
   197:  ["mso_sptActionButtonReturn"],
   198:  ["mso_sptActionButtonDocument"],
   199:  ["mso_sptActionButtonSound"],
   200:  ["mso_sptActionButtonMovie"],
   201:  ["mso_sptHostControl"],
   202:  ["mso_sptTextBox"]
}

textHeader = {
   0:  ["title"],
   1:  ["body"],
   2:  ["notes"],
   3:  ["outline"],
   4:  ["text in a shape"],
   5:  ["subtitle in title slide"],
   6:  ["title in title slide"],
   7:  ["body in two-column slide"],
   8:  ["body in four-column slide"]
}

slideLayoutTypes = {
    0: ["SL_TitleSlide"],
    1: ["SL_TitleBody"],
    2: ["SL_MasterTitle"],
    7: ["SL_TitleOnly"],
    8: ["SL_TwoColumns"],
    9: ["SL_TwoRows"],
    10: ["SL_ColumnTwoRows"],
    11: ["SL_TwoRowsColumn"],
    13: ["SL_TwoColumnsRow"],
    14: ["SL_FourObjects"],
    15: ["SL_BigObject"],
    16: ["SL_Blank"],
    17: ["SL_VerticalTitleBody"],
    18: ["SL_VerticalTwoRows"]
}

placeholderEnum = {
    0: ["PT_None"],
    1: ["PT_MasterTitle"],
    2: ["PT_MasterBody"],
    3: ["PT_MasterCenterTitle"],
    4: ["PT_MasterSubtitle"],
    5: ["PT_MasterNotesSlideImage"],
    6: ["PT_MasterNotesBody"],
    7: ["PT_MasterDate"],
    8: ["PT_MasterSlideNumber"],
    9: ["PT_MasterFooter"],
    10: ["PT_MasterHeader"],
    11: ["PT_NotesSlideImage"],
    12: ["PT_NotesBody"],
    13: ["PT_Title"],
    14: ["PT_Body"],
    15: ["PT_CenterTitle"],
    16: ["PT_SubTitle"],
    17: ["PT_VerticalTitle"],
    18: ["PT_VerticalBody"],
    19: ["PT_Object"],
    20: ["PT_Graph"],
    21: ["PT_Table"],
    22: ["PT_ClipArt"],
    23: ["PT_OrgChart"],
    24: ["PT_Media"],
    25: ["PT_VerticalObject"],
    26: ["PT_Picture"]
}

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

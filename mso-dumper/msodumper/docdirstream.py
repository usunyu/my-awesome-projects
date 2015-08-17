#!/usr/bin/env python2
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import globals
import struct
from xml.sax.saxutils import quoteattr


class DOCDirStream:
    """Represents one single word file subdirectory, like e.g. 'WordDocument'."""

    def __init__(self, bytes, params=None, name=None, mainStream=None, doc=None):
        self.bytes = bytes
        self.size = len(self.bytes)
        self.pos = 0
        self.params = params
        self.name = name
        self.mainStream = mainStream
        self.doc = doc

    def printAndSet(self, key, value, hexdump=True, end=True, offset=False, silent=False, dict=None, default=None):
        setattr(self, key, value)
        if silent:
            return
        attrs = ""
        if dict:
            if value in dict or not default:
                attrs += ' name="%s"' % dict[value]
            else:
                attrs += ' name="%s"' % default
        if hexdump and type(value) != float:
            value = hex(value)
        if offset:
            attrs += ' offset="%s"' % hex(self.pos)
        if end:
            print '<%s value="%s"%s/>' % (key, value, attrs)
        else:
            print '<%s value="%s"%s>' % (key, value, attrs)

    def quoteAttr(self, value):
        """Wrapper around xml.sax.saxutils.quoteattr, assumes the caller will put " around the result."""
        ret = quoteattr("'" + value + "'")
        return ret[2:len(ret) - 2]

    def getuInt8(self, bytes=None, pos=None):
        if not bytes:
            bytes = self.bytes
        if not pos:
            pos = self.pos
        return struct.unpack("<B", bytes[pos:pos + 1])[0]

    def readuInt8(self):
        ret = self.getuInt8()
        self.pos += 1
        return ret

    def getuInt16(self, bytes=None, pos=None):
        if not bytes:
            bytes = self.bytes
        if not pos:
            pos = self.pos
        return struct.unpack("<H", bytes[pos:pos + 2])[0]

    def readuInt16(self):
        ret = self.getuInt16()
        self.pos += 2
        return ret

    def getInt16(self, bytes=None, pos=None):
        if not bytes:
            bytes = self.bytes
        if not pos:
            pos = self.pos
        return struct.unpack("<h", bytes[pos:pos + 2])[0]

    def readInt16(self):
        ret = self.getInt16()
        self.pos += 2
        return ret

    def getuInt24(self):
        return struct.unpack("<I", self.bytes[self.pos:self.pos + 3] + "\x00")[0]

    def getuInt32(self, bytes=None, pos=None):
        if not bytes:
            bytes = self.bytes
        if not pos:
            pos = self.pos
        return struct.unpack("<I", bytes[pos:pos + 4])[0]

    def readuInt32(self):
        ret = self.getuInt32()
        self.pos += 4
        return ret

    def getInt32(self, bytes=None, pos=None):
        if not bytes:
            bytes = self.bytes
        if not pos:
            pos = self.pos
        return struct.unpack("<i", bytes[pos:pos + 4])[0]

    def readInt32(self):
        ret = self.getInt32()
        self.pos += 4
        return ret

    def getFloat32(self, bytes=None, pos=None):
        if not bytes:
            bytes = self.bytes
        if not pos:
            pos = self.pos
        return struct.unpack("<f", bytes[pos:pos + 4])[0]

    def readFloat32(self):
        ret = self.getFloat32()
        self.pos += 4
        return ret

    def getuInt64(self, bytes=None, pos=None):
        if not bytes:
            bytes = self.bytes
        if not pos:
            pos = self.pos
        return struct.unpack("<Q", bytes[pos:pos + 8])[0]

    def readuInt64(self):
        ret = self.getuInt64()
        self.pos += 8
        return ret

    def __getString(self, limit):
        bytes = []
        count = 0
        pos = self.pos
        while True:
            if (not limit is None) and count == limit:
                break
            i = self.getuInt8(pos=pos)
            pos += 1
            j = self.getuInt8(pos=pos)
            pos += 1
            if i != 0 or j != 0:
                bytes.append(i)
                bytes.append(j)
            else:
                break
            count += 1
        return (self.quoteAttr(globals.encodeName(globals.getUTF8FromUTF16("".join(map(lambda x: chr(x), bytes))))), pos)

    def getString(self, limit=None):
        ret, pos = self.__getString(limit)
        return ret

    def readString(self, limit=None):
        ret, pos = self.__getString(limit)
        self.pos = pos
        return ret

    def getBit(self, byte, bitNumber):
        return (byte & (1 << bitNumber)) >> bitNumber

    def dump(self):
        print '<stream name="%s" size="%s"/>' % (self.quoteAttr(globals.encodeName(self.name)), self.size)

    # compat methods to make msodraw happy
    def readUnsignedInt(self, size):
        if size == 1:
            return self.readuInt8()
        elif size == 2:
            return self.readuInt16()
        elif size == 4:
            return self.readuInt32()
        raise Exception

    def readSignedInt(self, size):
        if size == 4:
            return self.readInt32()
        raise Exception

    def readBytes(self, length):
        r = self.bytes[self.pos:self.pos + length]
        self.pos += length
        return r

    def moveForward(self, byteCount):
        self.pos += byteCount

    def appendLine(self, line):
        print line

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

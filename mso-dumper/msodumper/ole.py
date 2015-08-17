# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import sys
import globals
from globals import getSignedInt
# ----------------------------------------------------------------------------
# Reference: The Microsoft Compound Document File Format by Daniel Rentz
# http://sc.openoffice.org/compdocfileformat.pdf
# ----------------------------------------------------------------------------

from globals import output


class NoRootStorage(Exception): pass

class ByteOrder:
    LittleEndian = 0
    BigEndian    = 1
    Unknown      = 2

class BlockType:
    MSAT      = 0
    SAT       = 1
    SSAT      = 2
    Directory = 3

class StreamLocation:
    SAT  = 0
    SSAT = 1

class Header(object):

    @staticmethod
    def byteOrder (chars):
        b1, b2 = ord(chars[0]), ord(chars[1])
        if b1 == 0xFE and b2 == 0xFF:
            return ByteOrder.LittleEndian
        elif b1 == 0xFF and b2 == 0xFE:
            return ByteOrder.BigEndian
        else:
            return ByteOrder.Unknown


    def __init__ (self, bytes, params):
        self.bytes = bytes
        self.MSAT = None

        self.docId = None
        self.uId = None
        self.revision = 0
        self.version = 0
        self.byteOrder = ByteOrder.Unknown
        self.minStreamSize = 0

        self.numSecMSAT = 0
        self.numSecSSAT = 0
        self.numSecSAT = 0

        self.__secIDFirstMSAT = -2
        self.__secIDFirstDirStrm = -2
        self.__secIDFirstSSAT = -2

        self.secSize = 512
        self.secSizeShort = 64

        self.params = params

    def getSectorSize (self):
        return 2**self.secSize


    def getShortSectorSize (self):
        return 2**self.secSizeShort


    def getFirstSectorID (self, blockType):
        if blockType == BlockType.MSAT:
            return self.__secIDFirstMSAT
        elif blockType == BlockType.SSAT:
            return self.__secIDFirstSSAT
        elif blockType == BlockType.Directory:
            return self.__secIDFirstDirStrm
        return -2


    def output (self):

        def printRawBytes (bytes):
            for b in bytes:
                output("%2.2X "%ord(b))
            output("\n")

        def printSep (c, w, prefix=''):
            globals.outputln(prefix + c*w)

        printSep('=', globals.OutputWidth)
        globals.outputln("Compound Document Header")
        printSep('-', globals.OutputWidth)

        if self.params.debug:
            globals.dumpBytes(self.bytes[0:512])
            printSep('-', globals.OutputWidth)

        # document ID and unique ID
        output("Document ID: ")
        printRawBytes(self.docId)
        output("Unique ID: ")
        printRawBytes(self.uId)

        # revision and version
        globals.outputln("Revision: %d  Version: %d"%(self.revision, self.version))

        # byte order
        output("Byte order: ")
        if self.byteOrder == ByteOrder.LittleEndian:
            globals.outputln("little endian")
        elif self.byteOrder == ByteOrder.BigEndian:
            globals.outputln("big endian")
        else:
            globals.outputln("unknown")

        # sector size (usually 512 bytes)
        globals.outputln("Sector size: %d (%d)"%(2**self.secSize, self.secSize))

        # short sector size (usually 64 bytes)
        globals.outputln("Short sector size: %d (%d)"%(2**self.secSizeShort, self.secSizeShort))

        # total number of sectors in SAT (equals the number of sector IDs
        # stored in the MSAT).
        globals.outputln("Total number of sectors used in SAT: %d"%self.numSecSAT)

        globals.outputln("Sector ID of the first sector of the directory stream: %d"%
              self.__secIDFirstDirStrm)

        globals.outputln("Minimum stream size: %d"%self.minStreamSize)

        if self.__secIDFirstSSAT == -2:
            globals.outputln("Sector ID of the first SSAT sector: [none]")
        else:
            globals.outputln("Sector ID of the first SSAT sector: %d"%self.__secIDFirstSSAT)

        globals.outputln("Total number of sectors used in SSAT: %d"%self.numSecSSAT)

        if self.__secIDFirstMSAT == -2:
            # There is no more sector ID stored outside the header.
            globals.outputln("Sector ID of the first MSAT sector: [end of chain]")
        else:
            # There is more sector IDs than 109 IDs stored in the header.
            globals.outputln("Sector ID of the first MSAT sector: %d"%(self.__secIDFirstMSAT))

        globals.outputln("Total number of sectors used to store additional MSAT: %d"%self.numSecMSAT)


    def parse (self):

        # document ID and unique ID
        self.docId = self.bytes[0:8]
        self.uId = self.bytes[8:24]

        # revision and version
        self.revision = getSignedInt(self.bytes[24:26])
        self.version = getSignedInt(self.bytes[26:28])

        # byte order
        self.byteOrder = Header.byteOrder(self.bytes[28:30])

        # sector size (usually 512 bytes)
        self.secSize = getSignedInt(self.bytes[30:32])

        # short sector size (usually 64 bytes)
        self.secSizeShort = getSignedInt(self.bytes[32:34])

        # total number of sectors in SAT (equals the number of sector IDs
        # stored in the MSAT).
        self.numSecSAT = getSignedInt(self.bytes[44:48])

        self.__secIDFirstDirStrm = getSignedInt(self.bytes[48:52])
        self.minStreamSize = getSignedInt(self.bytes[56:60])
        self.__secIDFirstSSAT = getSignedInt(self.bytes[60:64])
        self.numSecSSAT = getSignedInt(self.bytes[64:68])
        self.__secIDFirstMSAT = getSignedInt(self.bytes[68:72])
        self.numSecMSAT = getSignedInt(self.bytes[72:76])

        # master sector allocation table
        self.MSAT = MSAT(2**self.secSize, self.bytes, self.params)

        # First part of MSAT consisting of an array of up to 109 sector IDs.
        # Each sector ID is 4 bytes in length.
        for i in xrange(0, 109):
            pos = 76 + i*4
            id = getSignedInt(self.bytes[pos:pos+4])
            if id == -1:
                break

            self.MSAT.appendSectorID(id)

        if self.__secIDFirstMSAT != -2:
            # additional sectors are used to store more SAT sector IDs.
            secID = self.__secIDFirstMSAT
            size = self.getSectorSize()
            if size < 4:
                raise Exception("ole.Header::parse: got %d as sector size!" % size)
            inLoop = True
            while inLoop:
                pos = 512 + secID*size
                bytes = self.bytes[pos:pos+size]
                n = int(size/4)
                for i in xrange(0, n):
                    pos = i*4
                    id = getSignedInt(bytes[pos:pos+4])
                    if id < 0:
                        inLoop = False
                        break
                    elif i == n-1:
                        # last sector ID - points to the next MSAT sector.
                        secID = id
                        break
                    else:
                        self.MSAT.appendSectorID(id)

        return 512


    def getMSAT (self):
        return self.MSAT


    def getSAT (self):
        return self.MSAT.getSAT()


    def getSSAT (self):
        ssatID = self.getFirstSectorID(BlockType.SSAT)
        if ssatID < 0:
            return None
        chain = self.getSAT().getSectorIDChain(ssatID)
        if len(chain) == 0:
            return None
        obj = SSAT(2**self.secSize, self.bytes, self.params)
        for secID in chain:
            obj.addSector(secID)
        obj.buildArray()
        return obj


    def getDirectory (self):
        dirID = self.getFirstSectorID(BlockType.Directory)
        if dirID < 0:
            return None
        chain = self.getSAT().getSectorIDChain(dirID)
        if len(chain) == 0:
            return None
        obj = Directory(self, self.params)
        for secID in chain:
            obj.addSector(secID)
        return obj


    def dummy ():
        pass




class MSAT(object):
    """Master Sector Allocation Table (MSAT)

This class represents the master sector allocation table (MSAT) that stores
sector IDs that point to all the sectors that are used by the sector
allocation table (SAT).  The actual SAT are to be constructed by combining
all the sectors pointed by the sector IDs in order of occurrence.
"""
    def __init__ (self, sectorSize, bytes, params):
        self.sectorSize = sectorSize
        self.secIDs = []
        self.bytes = bytes
        self.__SAT = None

        self.params = params

    def appendSectorID (self, id):
        self.secIDs.append(id)

    def output (self):
        globals.outputln('')
        globals.outputln("="*globals.OutputWidth)
        globals.outputln("Master Sector Allocation Table (MSAT)")
        globals.outputln("-"*globals.OutputWidth)

        for id in self.secIDs:
            globals.outputln("sector ID: %5d   (pos: %7d)"%(id, 512+id*self.sectorSize))

    def getSATSectorPosList (self):
        list = []
        for id in self.secIDs:
            pos = 512 + id*self.sectorSize
            list.append([id, pos])
        return list

    def getSAT (self):
        if self.__SAT != None:
            return self.__SAT

        obj = SAT(self.sectorSize, self.bytes, self.params)
        for id in self.secIDs:
            obj.addSector(id)
        obj.buildArray()
        self.__SAT = obj
        return self.__SAT


class SAT(object):
    """Sector Allocation Table (SAT)
"""
    def __init__ (self, sectorSize, bytes, params):
        self.sectorSize = sectorSize
        self.sectorIDs = []
        self.bytes = bytes
        self.array = []
        self.params = params


    def getSectorSize (self):
        return self.sectorSize


    def addSector (self, id):
        self.sectorIDs.append(id)


    def buildArray (self):
        if len(self.array) > 0:
            # array already built.
            return

        numItems = int(self.sectorSize/4)
        self.array = []
        for secID in self.sectorIDs:
            pos = 512 + secID*self.sectorSize
            for i in xrange(0, numItems):
                beginPos = pos + i*4
                id = getSignedInt(self.bytes[beginPos:beginPos+4])
                self.array.append(id)


    def outputRawBytes (self):
        bytes = ""
        for secID in self.sectorIDs:
            pos = 512 + secID*self.sectorSize
            bytes += self.bytes[pos:pos+self.sectorSize]
        globals.dumpBytes(bytes, 512)


    def outputArrayStats (self):
        sectorTotal = len(self.array)
        sectorP  = 0       # >= 0
        sectorM1 = 0       # -1
        sectorM2 = 0       # -2
        sectorM3 = 0       # -3
        sectorM4 = 0       # -4
        sectorMElse = 0    # < -4
        sectorLiveTotal = 0
        for i in xrange(0, len(self.array)):
            item = self.array[i]
            if item >= 0:
                sectorP += 1
            elif item == -1:
                sectorM1 += 1
            elif item == -2:
                sectorM2 += 1
            elif item == -3:
                sectorM3 += 1
            elif item == -4:
                sectorM4 += 1
            elif item < -4:
                sectorMElse += 1
            else:
                sectorLiveTotal += 1
        globals.outputln("total sector count:          %4d"%sectorTotal)
        globals.outputln("* live sector count:         %4d"%sectorP)
        globals.outputln("* end-of-chain sector count: %4d"%sectorM2)  # end-of-chain is also live

        globals.outputln("* free sector count:         %4d"%sectorM1)
        globals.outputln("* SAT sector count:          %4d"%sectorM3)
        globals.outputln("* MSAT sector count:         %4d"%sectorM4)
        globals.outputln("* other sector count:        %4d"%sectorMElse)


    def output (self):
        globals.outputln('')
        globals.outputln("="*globals.OutputWidth)
        globals.outputln("Sector Allocation Table (SAT)")
        globals.outputln("-"*globals.OutputWidth)
        if self.params.debug:
            self.outputRawBytes()
            globals.outputln("-"*globals.OutputWidth)
            for i in xrange(0, len(self.array)):
                globals.outputln("%5d: %5d"%(i, self.array[i]))
            globals.outputln("-"*globals.OutputWidth)

        self.outputArrayStats()


    def getSectorIDChain (self, initID):
        if initID < 0:
            return []
        chain = [initID]
        nextID = self.array[initID]
        while nextID != -2:
            chain.append(nextID)
            if nextID == self.array[nextID]:
                # Beware of infinite loop: happens on bad files.
                break
            nextID = self.array[nextID]
        return chain


class SSAT(SAT):
    """Short Sector Allocation Table (SSAT)

SSAT contains an array of sector ID chains of all short streams, as oppposed
to SAT which contains an array of sector ID chains of all standard streams.
The sector IDs included in the SSAT point to the short sectors in the short
stream container stream.

The first sector ID of SSAT is in the header, and the IDs of the remaining
sectors are contained in the SAT as a sector ID chain.
"""

    def output (self):
        globals.outputln('')
        globals.outputln("="*globals.OutputWidth)
        globals.outputln("Short Sector Allocation Table (SSAT)")
        globals.outputln("-"*globals.OutputWidth)
        if self.params.debug:
            self.outputRawBytes()
            globals.outputln("-"*globals.OutputWidth)
            for i in xrange(0, len(self.array)):
                item = self.array[i]
                output("%3d : %3d\n"%(i, item))

        self.outputArrayStats()


class Directory(object):
    """Directory Entries

This stream contains a list of directory entries that are stored within the
entire file stream.
"""

    class Type:
        Empty = 0
        UserStorage = 1
        UserStream = 2
        LockBytes = 3
        Property = 4
        RootStorage = 5

    class NodeColor:
        Red = 0
        Black = 1
        Unknown = 99

    class Entry:
        def __init__ (self):
            self.Name = ''
            self.CharBufferSize = 0
            self.Type = Directory.Type.Empty
            self.NodeColor = Directory.NodeColor.Unknown
            self.DirIDLeft = -1
            self.DirIDRight = -1
            self.DirIDRoot = -1
            self.UniqueID = None
            self.UserFlags = None
            self.TimeCreated = None
            self.TimeModified = None
            self.StreamSectorID = -2
            self.StreamSize = 0
            self.bytes = []

        def isStorage (self):
            return self.Type == Directory.Type.RootStorage or \
                self.Type == Directory.Type.UserStorage

    def __init__ (self, header, params):
        self.sectorSize = header.getSectorSize()
        self.bytes = header.bytes
        self.minStreamSize = header.minStreamSize
        self.sectorIDs = []
        self.entries = []
        self.SAT = header.getSAT()
        self.SSAT = header.getSSAT()
        self.header = header
        self.RootStorage = None
        self.RootStorageBytes = ""
        self.params = params


    def __buildRootStorageBytes (self):
        if self.RootStorage == None:
            # no root storage exists.
            return

        firstSecID = self.RootStorage.StreamSectorID
        chain = self.header.getSAT().getSectorIDChain(firstSecID)
        for secID in chain:
            pos = 512 + secID*self.sectorSize
            self.RootStorageBytes += self.header.bytes[pos:pos+self.sectorSize]


    def __getRawStream (self, entry):
        chain = []
        if entry.StreamLocation == StreamLocation.SAT:
            chain = self.header.getSAT().getSectorIDChain(entry.StreamSectorID)
        elif entry.StreamLocation == StreamLocation.SSAT:
            chain = self.header.getSSAT().getSectorIDChain(entry.StreamSectorID)

        if entry.StreamLocation == StreamLocation.SSAT:
            # Get the root storage stream.
            if self.RootStorage == None:
                raise NoRootStorage

            bytes = ""
            self.__buildRootStorageBytes()
            size = self.header.getShortSectorSize()
            for id in chain:
                pos = id*size
                bytes += self.RootStorageBytes[pos:pos+size]
            return bytes

        offset = 512
        size = self.header.getSectorSize()
        bytes = ""
        for id in chain:
            pos = offset + id*size
            bytes += self.header.bytes[pos:pos+size]

        return bytes

    def getRawStream (self, entry):
        bytes = self.__getRawStream(entry)
        return bytes

    def getRawStreamByName (self, name):
        bytes = []
        for entry in self.entries:
            if entry.Name == name:
                bytes = self.__getRawStream(entry)
                break
        return bytes


    def addSector (self, id):
        self.sectorIDs.append(id)


    def output (self, debug=False):
        globals.outputln('')
        globals.outputln("="*globals.OutputWidth)
        globals.outputln("Directory")

        if debug:
            globals.outputln("-"*globals.OutputWidth)
            globals.outputln("sector(s) used:")
            for secID in self.sectorIDs:
                globals.outputln("  sector %d"%secID)

            globals.outputln("")
            for secID in self.sectorIDs:
                globals.outputln("-"*globals.OutputWidth)
                globals.outputln("  Raw Hex Dump (sector %d)"%secID)
                globals.outputln("-"*globals.OutputWidth)
                pos = globals.getSectorPos(secID, self.sectorSize)
                globals.dumpBytes(self.bytes[pos:pos+self.sectorSize], 128)

        for entry in self.entries:
            self.__outputEntry(entry, debug)

    def __outputEntry (self, entry, debug):
        globals.outputln("-"*globals.OutputWidth)
        if len(entry.Name) > 0:
            name = entry.Name
            if ord(name[0]) <= 5:
                name = "<%2.2Xh>%s"%(ord(name[0]), name[1:])
            globals.outputln("name: %s   (name buffer size: %d bytes)"%(name, entry.CharBufferSize))
        else:
            globals.outputln("name: [empty]   (name buffer size: %d bytes)"%entry.CharBufferSize)

        if self.params.debug:
            globals.outputln("-"*globals.OutputWidth)
            globals.dumpBytes(entry.bytes)
            globals.outputln("-"*globals.OutputWidth)

        output("type: ")
        if entry.Type == Directory.Type.Empty:
            globals.outputln("empty")
        elif entry.Type == Directory.Type.LockBytes:
            globals.outputln("lock bytes")
        elif entry.Type == Directory.Type.Property:
            globals.outputln("property")
        elif entry.Type == Directory.Type.RootStorage:
            globals.outputln("root storage")
        elif entry.Type == Directory.Type.UserStorage:
            globals.outputln("user storage")
        elif entry.Type == Directory.Type.UserStream:
            globals.outputln("user stream")
        else:
            globals.outputln("[unknown type]")

        output("node color: ")
        if entry.NodeColor == Directory.NodeColor.Red:
            globals.outputln("red")
        elif entry.NodeColor == Directory.NodeColor.Black:
            globals.outputln("black")
        elif entry.NodeColor == Directory.NodeColor.Unknown:
            globals.outputln("[unknown color]")

        globals.outputln("linked dir entries: left: %d; right: %d; root: %d"%
              (entry.DirIDLeft, entry.DirIDRight, entry.DirIDRoot))

        self.__outputRaw("unique ID",  entry.UniqueID)
        self.__outputRaw("user flags", entry.UserFlags)
        self.__outputRaw("time created", entry.TimeCreated)
        self.__outputRaw("time last modified", entry.TimeModified)

        output("stream info: ")
        if entry.StreamSectorID < 0 or entry.StreamSize == 0:
            globals.outputln("[empty stream]")
        else:
            strmLoc = "SAT"
            if entry.StreamLocation == StreamLocation.SSAT:
                strmLoc = "SSAT"
            globals.outputln("(first sector ID: %d; size: %d; location: %s)"%
                  (entry.StreamSectorID, entry.StreamSize, strmLoc))

            satObj = None
            secSize = 0
            if entry.StreamLocation == StreamLocation.SAT:
                satObj = self.SAT
                secSize = self.header.getSectorSize()
            elif entry.StreamLocation == StreamLocation.SSAT:
                satObj = self.SSAT
                secSize = self.header.getShortSectorSize()
            if satObj != None:
                chain = satObj.getSectorIDChain(entry.StreamSectorID)
                globals.outputln("sector count: %d"%len(chain))
                globals.outputln("total sector size: %d"%(len(chain)*secSize))
                if self.params.showSectorChain:
                    self.__outputSectorChain(chain)


    def __outputSectorChain (self, chain):
        line = "sector chain: "
        lineLen = len(line)
        for id in chain:
            frag = "%d, "%id
            fragLen = len(frag)
            if lineLen + fragLen > 68:
                globals.outputln(line)
                line = frag
                lineLen = fragLen
            else:
                line += frag
                lineLen += fragLen
        if line[-2:] == ", ":
            line = line[:-2]
            lineLen -= 2
        if lineLen > 0:
            globals.outputln(line)


    def __outputRaw (self, name, bytes):
        if bytes == None:
            return

        output("%s: "%name)
        for byte in bytes:
            output("%2.2X "%ord(byte))
        globals.outputln("")

    def getDirectoryEntries (self):
        return self.entries

    def getDirectoryNames (self):
        names = []
        for entry in self.entries:
            names.append(entry.Name)
        return names


    def parseDirEntries (self):
        if len(self.entries):
            # directory entries already built
            return

        # combine all sectors first.
        bytes = ""
        for secID in self.sectorIDs:
            pos = globals.getSectorPos(secID, self.sectorSize)
            bytes += self.bytes[pos:pos+self.sectorSize]

        self.entries = []

        # each directory entry is exactly 128 bytes.
        numEntries = int(len(bytes)/128)
        if numEntries == 0:
            return
        for i in xrange(0, numEntries):
            pos = i*128
            self.entries.append(self.parseDirEntry(bytes[pos:pos+128]))


    def parseDirEntry (self, bytes):
        entry = Directory.Entry()
        entry.bytes = bytes
        name = globals.getUTF8FromUTF16(bytes[0:64])
        entry.Name = name
        entry.CharBufferSize = getSignedInt(bytes[64:66])
        entry.Type = getSignedInt(bytes[66:67])
        entry.NodeColor = getSignedInt(bytes[67:68])

        entry.DirIDLeft  = getSignedInt(bytes[68:72])
        entry.DirIDRight = getSignedInt(bytes[72:76])
        entry.DirIDRoot  = getSignedInt(bytes[76:80])

        entry.UniqueID     = bytes[80:96]
        entry.UserFlags    = bytes[96:100]
        entry.TimeCreated  = bytes[100:108]
        entry.TimeModified = bytes[108:116]

        entry.StreamSectorID = getSignedInt(bytes[116:120])
        entry.StreamSize     = getSignedInt(bytes[120:124])
        entry.StreamLocation = StreamLocation.SAT
        if entry.Type != Directory.Type.RootStorage and \
            entry.StreamSize < self.header.minStreamSize:
            entry.StreamLocation = StreamLocation.SSAT

        if entry.Type == Directory.Type.RootStorage and entry.StreamSectorID >= 0:
            # This is an existing root storage.
            self.RootStorage = entry

        return entry

class DateTime:
    def __init__(self):
        self.day = 0
        self.month = 0
        self.year = 0
        self.hour = 0
        self.second = 0

class DirNode:

    def __init__(self, entry, olecontainer):
        self.Nodes = []
        self.Entry = entry;
        self.HierachicalName = ''
        self.OleContainer = olecontainer
    def isStorage(self):
        return self.Entry.DirIDRoot > 0

    def getName(self):
        return self.Entry.Name

    def getHierarchicalName(self):
        return self.HierachicalName

    def getChildren(self):
        return self.Nodes

    def getStream(self):
        return self.OleContainer.getStreamForEntry( self.Entry )

class OleContainer:

    def __init__(self,filePath, params ):
        self.filePath = filePath
        self.header = None
        self.rootNode = None
        self.params = params

    def __getModifiedTime(self, entry):
        # need parse/decode Entry.TimeModified
        # ( although the documentation indicates that it might not be
        # worth it 'cause they are not universally used
        modified  = DateTime
        modified.day = 0
        modified.month = 0
        modified.year = 0
        modified.hour = 0
        modified.second = 0
        return modified

    def __parseFile (self):
        if self.rootNode == None:
            file = open(self.filePath, 'rb')
            self.chars = file.read()
            file.close()
            self.header = Header(self.chars, self.params)
            self.header.parse()
            self.obj = self.header.getDirectory()
            self.obj.parseDirEntries()
            count = 0
            self.rootNode = self.__buildTree( self.obj.entries )

    def __addSiblings( self, entries, parent, child ):
        # add left siblings
        nextLeft = child.Entry.DirIDLeft
        if ( nextLeft > 0 ):
            newEntry = DirNode( entries[ nextLeft ], self )
#            newEntry.HierachicalName = parent.HierachicalName + globals.encodeName( newEntry.Entry.Name )
            newEntry.HierachicalName = parent.HierachicalName + newEntry.Entry.Name
            if  newEntry.Entry.DirIDRoot > 0:
                newEntry.HierachicalName = newEntry.HierachicalName + '/'

            self.__addSiblings( entries, parent, newEntry )
            parent.Nodes.insert( 0, newEntry )

        nextRight = child.Entry.DirIDRight
        # add children to the right
        if ( nextRight > 0 ):
            newEntry = DirNode( entries[ nextRight ], self )
#            newEntry.HierachicalName = parent.HierachicalName + globals.encodeName( newEntry.Entry.Name )
            newEntry.HierachicalName = parent.HierachicalName + newEntry.Entry.Name
            if  newEntry.Entry.DirIDRoot > 0:
                newEntry.HierachicalName = newEntry.HierachicalName + '/'
            self.__addSiblings( entries, parent, newEntry )
            parent.Nodes.append( newEntry )

    def __buildTreeImpl(self, entries, parent ):

        if ( parent.Entry.DirIDRoot > 0 ):
            newEntry = DirNode( entries[ parent.Entry.DirIDRoot ], self )
#            newEntry.HierachicalName = parent.HierachicalName + globals.encodeName( newEntry.Entry.Name )
            newEntry.HierachicalName = parent.HierachicalName +  newEntry.Entry.Name
            if ( newEntry.Entry.DirIDRoot > 0 ):
                newEntry.HierachicalName =  newEntry.HierachicalName + '/'

            self.__addSiblings( entries, parent, newEntry )
            parent.Nodes.append( newEntry )

        for child in parent.Nodes:
            if child.Entry.DirIDRoot > 0:
                self.__buildTreeImpl( entries, child )

    def __buildTree(self, entries ):
        treeRoot = DirNode( entries[0], self )
        self.__buildTreeImpl( entries, treeRoot )
        return treeRoot

    def __findEntryByHierachicalName( self, node, name ):
        if node.HierachicalName == name:
            return node.Entry
        else:
            for child in node.Nodes:
                result = self.__findEntryByHierachicalName( child, name )
                if result != None:
                    return result
        return None

    def __printListReport( self, treeNode ):

        dateInfo = self.__getModifiedTime( treeNode.Entry )

        if len( treeNode.HierachicalName ) > 0 :
            globals.outputln('{0:8d}  {1:0<2d}-{2:0<2d}-{3:0<2d} {4:0<2d}:{5:0<2d}   {6}'.format(treeNode.Entry.StreamSize, dateInfo.day, dateInfo.month, dateInfo.year, dateInfo.hour, dateInfo.second, treeNode.HierachicalName ))

        for node in treeNode.Nodes:
            # ignore the root
            self.__printListReport( node )

    def __printHeader(self):
        globals.outputln("OLE: %s")%self.filePath
        globals.outputln(" Length     Date   Time    Name")
        globals.outputln("--------    ----   ----    ----")

    def list(self):
        # need to share the inititialisation and parse stuff between the different options

        self.__parseFile()
        if  self.rootNode != None:
            self.__printHeader()
            self.__printListReport( self.rootNode )
            # need to print a footer ( total bytes, total files like unzip )

    def getStreamForEntry( self, entry ):
        if  entry == None or entry.DirIDRoot > 0 :
            raise Exception("can't get stream for invalid entry")
        bytes = bytearray()
        bytes = self.obj.getRawStream( entry )
        bytes = bytes[0:entry.StreamSize]
        return bytes

    def getStreamForName( self, name ):
        self.__parseFile()
        if  self.rootNode != None:
            entry = self.__findEntryByHierachicalName( self.rootNode, name )
            return self.getStreamForEntry( entry )

    def extract(self, name):
        self.__parseFile()
        if  self.rootNode != None:
            entry = self.__findEntryByHierachicalName( self.rootNode, name )
            bytes = self.getStreamForEntry( entry )
            file = open(entry.Name, 'wb')
            file.write( bytes )
            file.close
        else:
            globals.outputln("failed to initialise ole container")

    def read(self):
        self.__parseFile()

    def getRoot(self):
        self.__parseFile()
        return self.rootNode

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

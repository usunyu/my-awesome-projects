#!/usr/bin/env python2
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import sys, os.path, optparse, math

from msodumper import ole, globals, node, olestream, vbahelper

#codepage -> codepagename map
# note: there are some missing entries ( the commented out ones ) that
# I couldn't find in python docs ... library/codecs.html
codePageMap = {
    437: "cp437",        #IBM_437
    708: "iso8859_6",    #ISO_8859_6
    737: "cp737",        #IBM_737
    775: "cp775",        #IBM_775;
    850: "cp850",        #IBM_850;
    852: "cp852",        #IBM_852;
    855: "cp855",        #IBM_855;
    857: "cp857",        #IBM_857;
    860: "cp860",        #IBM_860;
    861: "cp861",        #IBM_861;
    862: "cp862",        #IBM_862;
    863: "cp863",        #IBM_863;
    864: "cp864",        #IBM_864;
    865: "cp865",        #IBM_865;
    866: "cp866",        #IBM_866;
    869: "cp869",        #IBM_869;
    874: "cp874",        #MS_874;
    932: "cp932",        #MS_932;
    936: "cp936",        #MS_936;
    949: "cp949",        #MS_949;
    950: "cp950",        #MS_950;
    1250: "cp1250",      #MS_1250;
    1251: "cp1251",      #MS_1251;
    1252: "cp1252",      #MS_1252;
    1253: "cp1253",      #MS_1253;
    1254: "cp1254",      #MS_1254;
    1255: "cp1255",      #MS_1255;
    1256: "cp1256",      #MS_1256;
    1257: "cp1257",      #MS_1257;
    1258: "cp1258",      #MS_1258;
    1361: "cp1361",      #MS_1361;
    10000: "macroman",   #APPLE_ROMAN;
#    10001: "",           #APPLE_JAPANESE;
#    10002: "",           #APPLE_CHINTRAD;
#    10003: "",           #APPLE_KOREAN;
    10004: "mac_arabic", #APPLE_ARABIC;
#    10005: "",           #APPLE_HEBREW;
    10006: "mac_greek",    #APPLE_GREEK;
    10007: "mac_cyrillic", #APPLE_CYRILLIC;
#    10008: "",           #APPLE_CHINSIMP;
#    10010: "",           #APPLE_ROMANIAN;
#    10017: "",           #APPLE_UKRAINIAN;
    10029: "mac_latin2", #APPLE_CENTEURO;
    10079: "mac_iceland",#APPLE_ICELAND;
    10081: "mac_turkish",#APPLE_TURKISH;
#    10082: "",           #APPLE_CROATIAN;
    20127: "ascii",      #ASCII_US;
    20866: "koi8",       #KOI8_R;
    21866: "koi8",       #KOI8_U;
    28591: "latin_1",    #ISO_8859_1;
    28592: "iso8859_2",  #ISO_8859_2;
    28593: "iso8859_3",  #ISO_8859_3;
    28594: "iso8859_4",  #ISO_8859_4;
    28595: "iso8859_5",  #ISO_8859_5;
    28596: "iso8859_6",  #ISO_8859_6;
    28597: "iso8859_7",  #ISO_8859_7;
    28598: "iso8859_8",  #ISO_8859_8;
    28599: "iso8859_9",  #ISO_8859_9;
    28605: "iso8859_15", #ISO_8859_15;
    50220: "iso2022_jp", #ISO_2022_JP;
    50225: "iso2022_kr", #ISO_2022_KR;
    51932: "euc_jp",     #EUC_JP;
    51936: "gb2312",     #EUC_CN;
    51949: "euc_kr",     #EUC_KR;
#    57002: "",           #ISCII_DEVANAGARI;
    65000: "utf_7",      #UTF7;
    65001: "utf_8",      #UTF8;
}

class StdReader:
    def __init__ (self, reader ):
        self.reader = reader
    # subclass needs to implement this
    def parse(self): 
        pass

class ProjectVersionReader( StdReader ):
    def parse(self):
        # reserved
        self.reader.readBytes(4)
        # major
        major = self.reader.readUnsignedInt( 4 )
        minor = self.reader.readUnsignedInt( 2 )
        print("  major: %i"%major)
        print("  minor: %i"%minor)

class CodePageReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        self.reader.codepage = self.reader.readUnsignedInt( size )

        #default codepage to something reasonable
        self.reader.codepageName = "cp1252"
        if codePageMap.has_key( self.reader.codepage ):
            self.reader.codepageName = codePageMap[  self.reader.codepage ]
        print("  codepage: %i"%self.reader.codepage)

class ProjectNameReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        bytes = self.reader.readBytes( size )
        print("  ProjectName: %s"%bytes.decode(self.reader.codepageName))

class DocStringRecordReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        bytes = self.reader.readBytes( size )
        print("  DocString: %s size[0x%x]"%(bytes.decode(self.reader.codepageName),size))
        #reserved
        self.reader.readBytes( 2 )
        #unicode docstring
        size = self.reader.readUnsignedInt( 4 )
        bytes = self.reader.readBytes( size )
        print("  DocStringUnicode: %s size[0x%x]"%(bytes.decode("utf-16").decode(self.reader.codepageName), size ))

class ReferenceProjectReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        sizeOfLibidAbsolute = self.reader.readUnsignedInt( 4 )
        sLibidAbsolute =  self.reader.readBytes( sizeOfLibidAbsolute )
        nSizeOfLibidRelative =   self.reader.readUnsignedInt( 4 )
        sLibidRelative =  self.reader.readBytes( nSizeOfLibidRelative )
        majorVersion = self.reader.readUnsignedInt( 4 )
        minorVersion = self.reader.readUnsignedInt( 2 )
        print("  LibidAbsolute: %s"%sLibidAbsolute.decode( self.reader.codepageName ) )
        print("  LibidRelative: %s"%sLibidRelative.decode( self.reader.codepageName ) )
        print("  MajorVersion: %i"%majorVersion )
        print("  MinorVersion: %i"%minorVersion )

class ConstantsRecordReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        bytes = self.reader.readBytes( size )
        print("  Constants: size[0x%x]"%size)
        if size:
            print("%s"%bytes.decode(self.reader.codepageName))
        #reserved
        self.reader.readBytes( 2 )
        #unicode docstring
        size = self.reader.readUnsignedInt( 4 )
        bytes = self.reader.readBytes( size )
        print("  Constants(Utf-16): size[0x%x]"%size)
        if size:
            print("%s"%bytes.decode("uft-16").decode(self.reader.codepageName))

class ProjectHelpFilePathReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        bytes = self.reader.readBytes( size )
        print("  HelpFile1: %s size[0x%x]"%(bytes.decode(self.reader.codepageName),size))
        #reserved
        self.reader.readBytes( 2 )
        #unicode docstring
        size = self.reader.readUnsignedInt( 4 )
        bytes = self.reader.readBytes( size )
        print("  HelpFile2: %s size[0x%x]"%(bytes.decode(self.reader.codepageName), size ))

class ProjectHelpFileContextReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        context = self.reader.readUnsignedInt( size )
        print("  HelpContext: 0x%x"%context)

class ProjectModulesReader(StdReader):
    def parse(self):
        # start of module specific data
        size = self.reader.readUnsignedInt( 4 )
        count = self.reader.readUnsignedInt( size )
        self.reader.CurrentModule = ModuleInfo()
        print("  Num Modules: %i"%count) 

class ModuleNameReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        nameBytes = self.reader.readBytes( size )
        moduleInfo = self.reader.CurrentModule
        moduleInfo.name = nameBytes.decode( self.reader.codepageName )
        print("  ModuleName: %s"%moduleInfo.name)

class ModuleStreamNameReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        nameBytes = self.reader.readBytes( size )
        moduleInfo = self.reader.CurrentModule
        moduleInfo.streamname = nameBytes.decode( self.reader.codepageName )
        print("  ModuleStreamName: %s"%moduleInfo.name)
        #reserved
        self.reader.readBytes( 2 )
        size = self.reader.readUnsignedInt( 4 )
        nameUnicodeBytes = self.reader.readBytes( size )
        nameUnicode = nameUnicodeBytes.decode("utf-16").decode( self.reader.codepageName)
        print("  ModuleStreamNameUnicode: %s"%nameUnicode)

class ReferenceNameRecordReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        nameBytes = self.reader.readBytes( size )
        print("  ReferenceName: %s"%nameBytes.decode( self.reader.codepageName ))
        #reserved
        self.reader.readBytes( 2 )
        size = self.reader.readUnsignedInt( 4 )
        nameUnicodeBytes = self.reader.readBytes( size )
        nameUnicode = nameUnicodeBytes.decode("utf-16").decode( self.reader.codepageName)
        print("  ReferenceNameUnicode: %s"%nameUnicode)

class ReferenceRegisteredReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        sizeOfLibid = self.reader.readUnsignedInt( 4 )
        libidBytes = self.reader.readBytes( sizeOfLibid )
        print("  Libid: %s"%libidBytes.decode( self.reader.codepageName ))
        #reserved1 & reserved2
        self.reader.readBytes( 6 )
class ModuleNameUnicodeReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        nameUnicodeBytes = self.reader.readBytes( size )
        nameUnicode = nameUnicodeBytes.decode("utf-16").decode( self.reader.codepageName)
        print("  ModuleNameUnicode: %s"%nameUnicode)

class ModuleOffSetReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        moduleInfo = self.reader.CurrentModule
        moduleInfo.offset = self.reader.readUnsignedInt( size )

        print("  Offset: 0x%x"%moduleInfo.offset)

class ProjectModuleTermReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        # size must be zero ( assert? )
        moduleInfo = self.reader.CurrentModule
        self.reader.CurrentModule = ModuleInfo()
        # add current module to list
        self.reader.Modules.append( moduleInfo )

class ModuleTypeProceduralReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        # size must be zero ( assert? )
        print("  Module Type: procedure")

class ModuleTypeOtherReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        # size must be zero ( assert? )
        print("  Module Type: document, class or design")

class SysKindReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        val = self.reader.readUnsignedInt( size )
        sysKind = "Unknown"
        if val == 0:
           sysKind = "16 bit windows"
        elif val == 1:
           sysKind = "32 bit windows"
        elif val == 2:
           sysKind = "Macintosh"
        print("  SysType: %s"%sysKind)

class LcidReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        val = self.reader.readUnsignedInt( size )
        print("  LCID: 0x%x ( expected 0x409 )"%val)

class LcidInvokeReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        val = self.reader.readUnsignedInt( size )
        print("  LCIDINVOKE: 0x%x ( expected 0x409 )"%val)

class LibFlagReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        val = self.reader.readUnsignedInt( size )
        print("  LIBFLAGS: 0x%x"%val)

class ModuleCookieReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        val = self.reader.readUnsignedInt( size )
        print("  ModuleCookie: 0x%x"%val)

class ModuleHelpContextReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        val = self.reader.readUnsignedInt( size )
        print("  HelpConext: 0x%x"%val)

class ProjectCookieReader(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        val = self.reader.readUnsignedInt( size )
        print("  ProjectCookie: 0x%x"%val)

class ReferenceOriginalRecord(StdReader):
    def parse(self):
        size = self.reader.readUnsignedInt( 4 )
        sLibidOriginalBytes = self.reader.readBytes( size )
        print("  LibIdOriginal: %s"%sLibidOriginalBytes.decode( self.reader.codepageName))

class ReferenceControlReaderPart1(StdReader):
    def parse(self):
        sizeOfTwiddled = self.reader.readUnsignedInt( 4 )
        sizeOfLibidTwiddled =  self.reader.readUnsignedInt( 4 )
        sLibidTwiddledBytes =  self.reader.readBytes( sizeOfLibidTwiddled )
        print("  LibIdTwiddled: %s"%sLibidTwiddledBytes.decode( self.reader.codepageName))

        # Reserved1 & Reserved2 ( suppose we could really read these and assert if
        # they don't conform to expected values ( 0x00000000 & 0x00000000 )
        self.reader.readBytes( 6 )

class ReferenceControlReaderPart2(StdReader):
    def parse(self):
        sizeExtended = self.reader.readUnsignedInt( 4 )
        sizeOfLibidExtended =  self.reader.readUnsignedInt( 4 )
        sLibidExtendedBytes =  self.reader.readBytes( sizeOfLibidExtended )
        print("  LibidExtended: %s"%sLibidExtendedBytes.decode( self.reader.codepageName))

        # Reserved4 & Reserved5 ( suppose we could really read these and assert if
        # they don't conform to expected values ( 0x00000000 & 0x00000000 )
        self.reader.readBytes( 6 )
        origTypeLib = self.reader.readBytes( 16 )
        sys.stdout.write("  GUID: " )
        for i in xrange( 0, 16 ):
            if i:
                sys.stdout.write(" ")
            sys.stdout.write("0x%x"%origTypeLib[ i ])
        print("")
        cookie = self.reader.readUnsignedInt( 4 )
        print("  cookie: 0x%x"%cookie)

# map of record id to array containing description of records and optional
# a handler ( inspired by xlsstream.py )
dirRecordData = {
    #dir stream contains........
    #PROJECTINFORMATION RECORD
    #  which contains any of the following sub records
    0x0001: ["PROJECTSYSKIND", "SysKindRecord",SysKindReader],
    0x0002: ["PROJECTLCID", "LcidRecord",LcidReader],
    0x0003: ["PROJECTCODEPAGE", "CodePageRecord", CodePageReader ],
    0x0004: ["PROJECTNAME", "NameRecord", ProjectNameReader],
    0x0005: ["PROJECTDOCSTRING", "DocStringRecord", DocStringRecordReader ],
    0x0006: ["PROJECTHELPFILEPATH", "HelpFilePathRecord", ProjectHelpFilePathReader],
    0x0007: ["PROJECTHELPCONTEXT", "HelpContextRecord", ProjectHelpFileContextReader],
    0x0008: ["PROJECTLIBFLAGS", "LibFlagsRecord",LibFlagReader],
    0x0009: ["PROJECTVERSION", "VersionRecord",ProjectVersionReader],
    0x0010: ["DIRTERMINATOR", "DirTerminator"],
    0x000C: ["PROJECTCONSTANTS", "ConstantsRecord", ConstantsRecordReader],
    0x0014: ["PROJECTLCIDINVOKE", "LcidInvokeRecord",LcidInvokeReader],
    #PROJECTREFERENCES
    # which contains any of the following sub records
    0x0016: ["REFERENCENAME", "NameRecord", ReferenceNameRecordReader ],
    0x000D: ["REFERENCEREGISTERED", "ReferenceRegistered", ReferenceRegisteredReader],
    0x000E: ["REFERENCEPROJECT", "ReferenceProject", ReferenceProjectReader],
    0x002F: ["REFERENCECONTROL-Part1", "ReferenceControl", ReferenceControlReaderPart1],
    #the following record is not really a record but actually
    #is a reserved word ( with fixed value 0x0030 ) in the middle of a
    #REFEREBCECONTROL record
    0x0030: ["REFERENCECONTROL-Part2", "ReferenceControl", ReferenceControlReaderPart2 ],
    0x0033: ["REFERENCEORIGINAL", "ReferenceOriginal",ReferenceOriginalRecord],
    #
    0x000F: ["PROJECTMODULES", "ModulesRecord", ProjectModulesReader],
    0x0013: ["PROJECTCOOKIE", "CookieRecord", ProjectCookieReader],
    0x002B: ["PROJECTMODULETERM", "ModuleTerminator", ProjectModuleTermReader],
    0x0019: ["MODULENAME", "ModuleName",ModuleNameReader],
    0x0047: ["MODULENAMEUNICODE", "ModuleNameUnicode", ModuleNameUnicodeReader ],
    0x001A: ["MODULESTREAMNAME", "ModuleStreamName", ModuleStreamNameReader],
    0x001C: ["MODULEDOCSTRING", "ModuleDocString", DocStringRecordReader],
    0x0031: ["MODULEOFFSET", "ModuleOffSet", ModuleOffSetReader],
    0x001E: ["MODULEHELPCONTEXT", "ModuleHelpContext", ModuleHelpContextReader],
    0x002C: ["MODULECOOKIE", "ModuleCookie", ModuleCookieReader ],
    0x0021: ["MODULETYPE", "ModuleTypeProcedural", ModuleTypeProceduralReader],
    0x0022: ["MODULETYPE", "ModuleTypeDocClassOrDesgn", ModuleTypeOtherReader],
    0x0025: ["MODULEREADONLY", "ModuleReadOnly"],
    0x0028: ["MODULEPRIVATE", "ModulePrivate"],
}


class ModuleInfo:
    def __init__(self):
        self.name = ""
        self.offset = 0
        self.streamname = ""

class DirStreamReader( globals.ByteStream ):
    def __init__ (self, bytes ):
        globals.ByteStream.__init__(self, bytes)
        self.Modules = []
        self.CodePage = None
        self.CurrentModule = None

    def parse(self):
        print("============ Dir Stream (inflated) size: 0x%x bytes ============"%len(self.bytes))
        print("")
        print("Offset  [recId]  RecordName")
        print("------- -------  -----------")
        while self.isEndOfRecord() == False:
            pos = self.getCurrentPos()
            recordID = self.readUnsignedInt( 2 )
            name = "Unknown"
            if dirRecordData.has_key( recordID ):
                name = dirRecordData[ recordID ][0]
            # if we have a handler let it deal with the record
            labelWidth = int(math.ceil(math.log(len(self.bytes), 10)))
            fmt = "0x%%%d.%dx: "%(labelWidth, labelWidth)
            sys.stdout.write(fmt%pos)
#            print ("%s [0x%x] "%(name,recordID))
            print '[0x{0:0>4x}] {1}'.format(recordID,name)
            if ( dirRecordData.has_key( recordID ) and len( dirRecordData[ recordID ] ) > 2 ):
                reader = dirRecordData[ recordID ][2]( self )
                reader.parse()
            else:
                size = self.readUnsignedInt( 4 )
                if size:
                    self.readBytes(size)

class VBAContainer:
    def __init__( self, root ):
        # we'll take a storage DirNode
        # and try and find the VBA container
        # relative to that. That way we should
        # be able to cater for the normal 'word' or
        # 'excel' compound documents or indeed any arbitrary
        # storage that contains a 'VBA' sub-folder
        self.oleRoot = root
        self.vbaRoot = None

    def __findNodeByHierarchicalName( self, node, name ):
        if ( node.getHierarchicalName() == name ):
            return node
        else:
            for child in node.getChildren():
                result = self.__findNodeByHierarchicalName( child, name )
                if result != None:
                    return result
        return None

    def __findNodeContainingLeafName( self, parentNode, name ):
        for child in parentNode.getChildren():
            if name == child.Entry.Name:
                return parentNode
            node = self.__findNodeContainingLeafName( child, name )
            if node != None:
                return node
        return None

    def findVBARoot(self):
        # find the node that containes 'VBA' storage
        return self.__findNodeContainingLeafName( self.oleRoot, "VBA" )

    def dump( self ):
        self.vbaRoot = self.findVBARoot()
        if self.vbaRoot == None:
            print("Can't find VBA subcontainer")
            exit(1)
        # need to read the dir stream
        dirName = self.vbaRoot.getHierarchicalName() + "VBA/dir"
        dirNode = self.__findNodeByHierarchicalName( self.vbaRoot, dirName )
        if dirNode != None:
            #decompress
            bytes = dirNode.getStream()
            compressed = vbahelper.CompressedVBAStream( bytes, 0 )
            bytes = compressed.decompress()
            reader = DirStreamReader( bytes )
            reader.parse()

            # dump the PROJECTxxx streams ( need to codepage from dir )
            for child in self.vbaRoot.getChildren():
                # first level children are PROJECT, PROJECTwm & PROJECTlk
                if child.isStorage() == False:
                    bytes = child.getStream()
                    print("")
                    print("============ %s Stream size: 0x%x bytes)============"%(child.getName(), len(bytes)))
                    print("")
                    if child.getName() == "PROJECT":
                        #straight text file
                        print("%s"%bytes.decode(reader.codepageName))
                    else:
                        globals.dumpBytes( bytes, 512)
            for module in reader.Modules:
                fullStreamName = self.vbaRoot.getHierarchicalName() + "VBA/" + module.streamname
                moduleNode = self.__findNodeByHierarchicalName( self.vbaRoot, fullStreamName )
                bytes = moduleNode.getStream()
                print("============ %s Stream (inflated) size: 0x%x bytes offset: 0x%x ============"%(module.streamname,len(bytes), module.offset) )
                compressed = vbahelper.CompressedVBAStream( bytes, module.offset )
                bytes = compressed.decompress()
                source = bytes.decode( reader.codepageName )
                print("")
                print(source)
                print("")


def main():
    parser = optparse.OptionParser()

    if ( len ( sys.argv ) <= 1 ):
        print("usage: vbadump: file")
        sys.exit(1)
    # prepare for supporting more options
    options, args = parser.parse_args()

    params = globals.Params()

    container = ole.OleContainer( args[ 0 ], params )

    container.read()
    root = container.getRoot()
    vba = VBAContainer( root )
    vba.dump()

    exit(0)

if __name__ == '__main__':
    main()

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

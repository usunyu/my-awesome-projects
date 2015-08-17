#!/usr/bin/env python2
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import sys, os.path, optparse

from msodumper import ole, xlsstream, globals, node, xlsmodel, olestream
from msodumper import xlsparser, msocrypto

from msodumper.globals import error

def equalsName (name, array):
    if len(name) != len(array):
        return False

    for i in xrange(0, len(name)):
        if ord(name[i]) != array[i]:
            return False

    return True

def isOleStream (dirname):
    """Determine whether or not a stream is an OLE stream.

Accodring to the spec, an OLE stream is always named '\1Ole'."""

    name = [0x01, 0x4F, 0x6C, 0x65] # 0x01, 'Ole'
    return equalsName(dirname, name)

def isCompObjStream (dirname):
    name = [0x01, 0x43, 0x6F, 0x6D, 0x70, 0x4F, 0x62, 0x6A] # 0x01, 'CompObj'
    return equalsName(dirname, name)

class XLDumper(object):

    def __init__ (self, filepath, params):
        self.filepath = filepath
        self.params = params
        self.strm = None
        self.strmData = None

    def __printDirHeader (self, direntry, byteLen):
        dirname = direntry.Name
        dirname = globals.encodeName(dirname)
        print("")
        print("="*globals.OutputWidth)
        if direntry.isStorage():
            print("%s (storage)"%dirname)
        else:
            print("%s (stream, size: %d bytes)"%(dirname, byteLen))
        print("-"*globals.OutputWidth)

    def __parseFile (self):
        file = open(self.filepath, 'rb')
        self.strmData = xlsstream.StreamData()
        self.strm = xlsstream.XLStream(file.read(), self.params, self.strmData)
        file.close()

    def dumpXML (self):
        self.__parseFile()
        dirs = self.strm.getDirectoryEntries()
        docroot = node.Root()
        root = docroot.appendElement('xls-dump')

        for d in dirs:
            if d.Name != "Workbook":
                # for now, we only dump the Workbook directory stream.
                continue

            dirstrm = self.strm.getDirectoryStream(d)
            data = self.__readSubStreamXML(dirstrm)
            self.__dumpDataAsXML(data, root)
        node.prettyPrint(sys.stdout, docroot, utf8 = self.params.utf8)

    def dumpCanonicalXML (self):
        self.__parseFile()
        docroot = node.Root()
        root = docroot.appendElement('xls-dump')

        dirEntries = self.strm.getDirectoryEntries()
        for entry in dirEntries:
            dirname = entry.Name
            if dirname != "Workbook":
                # for now, we only dump the Workbook directory stream.
                continue

            dirstrm = self.strm.getDirectoryStream(entry)
            wbmodel = self.__buildWorkbookModel(dirstrm)
            wbmodel.encrypted = self.strmData.encrypted
            root.appendChild(wbmodel.createDOM())

        node.prettyPrint(sys.stdout, docroot, utf8 = self.params.utf8)

    def dump (self):
        self.__parseFile()
        self.strm.printStreamInfo()
        self.strm.printHeader()
        self.strm.printMSAT()
        self.strm.printSAT()
        self.strm.printSSAT()
        self.strm.printDirectory()
        dirEntries = self.strm.getDirectoryEntries()
        for entry in dirEntries:
            dirname = entry.Name
            if len(dirname) == 0:
                continue

            dirstrm = self.strm.getDirectoryStream(entry)
            self.__printDirHeader(entry, len(dirstrm.bytes))
            if entry.isStorage():
                continue

            elif dirname == "Workbook":
                success = True
                while success:
                    success = self.__readSubStream(dirstrm)

            elif dirname == "Revision Log":
                dirstrm.type = xlsstream.DirType.RevisionLog
                self.__readSubStream(dirstrm)

            elif dirname == "EncryptionInfo":
                globals.dumpBytes(dirstrm.bytes, 512)
                print("-"*globals.OutputWidth)
                info = msocrypto.EncryptionInfo(dirstrm.bytes)
                info.read()
                info.output()

            elif self.strmData.isPivotCacheStream(dirname):
                dirstrm.type = xlsstream.DirType.PivotTableCache
                self.__readSubStream(dirstrm)
            elif isOleStream(dirname):
                self.__readOleStream(dirstrm)
            elif isCompObjStream(dirname):
                self.__readCompObjStream(dirstrm)
            else:
                globals.dumpBytes(dirstrm.bytes, 512)

    def __readSubStream (self, strm):
        try:
            # read bytes from BOF to EOF.
            header = 0x0000
            while header != 0x000A:
                header = strm.readRecord()
            return True
        except xlsstream.EndOfStream:
            return False

    def __readOleStream (self, dirstrm):
        strm = olestream.OLEStream(dirstrm.bytes)
        strm.read()

    def __readCompObjStream (self, dirstrm):
        try:
            strm = olestream.CompObjStream(dirstrm.bytes)
            strm.read()
        except olestream.CompObjStreamError:
            globals.error("failed to parse CompObj stream.\n")

    def __dumpDataAsXML(self, data, root):
        if isinstance(data, tuple):
            newRoot = root.appendElement(data[0])
            if isinstance(data[1], dict): # attrs
                for key,val in data[1].iteritems():
                    newRoot.setAttr(key, val)
                if len(data) > 2: # data has a list of children
                    self.__dumpDataAsXML(data[2], newRoot)
            else:
                self.__dumpDataAsXML(data[1], newRoot)
        elif isinstance(data, list):
            for x in data:
                self.__dumpDataAsXML(x, root)
        else:
            pass # we're skipping all unknown elems

    def __readSubStreamXML (self, strm):
        handlers = []
        try:
            while True:
                handler = strm.getNextRecordHandler()
                handlers.append(handler)
        except xlsstream.EndOfStream:
            pass
        parser = xlsparser.XlsParser(handlers)
        return parser.dumpData()

    def __buildWorkbookModel (self, strm):
        model = xlsmodel.Workbook()
        try:
            while True:
                strm.fillModel(model)
        except xlsstream.EndOfStream:
            pass

        return model

def main ():
    parser = optparse.OptionParser()
    parser.add_option("-d", "--debug", action="store_true", dest="debug", default=False,
        help="Turn on debug mode")
    parser.add_option("--show-sector-chain", action="store_true", dest="show_sector_chain", default=False,
        help="Show sector chain information at the start of the output.")
    parser.add_option("--show-stream-pos", action="store_true", dest="show_stream_pos", default=False,
        help="Show the position of each record relative to the stream.")
    parser.add_option("--dump-mode", dest="dump_mode", default="flat", metavar="MODE",
        help="Specify the dump mode.  Possible values are: 'flat', 'xml', or 'canonical-xml'.  The default value is 'flat'.")
    parser.add_option("--catch", action="store_true", dest="catch_exceptions", default=False,
        help="Catch exceptions and try to continue.")
    parser.add_option("--utf-8", action="store_true", dest="utf8", default=False,
        help="Output strings as UTF-8.")
    options, args = parser.parse_args()
    params = globals.params
    params.debug = options.debug
    params.showSectorChain = options.show_sector_chain
    params.showStreamPos = options.show_stream_pos
    params.catchExceptions = options.catch_exceptions
    params.utf8 = options.utf8
    
    if len(args) < 1:
        globals.error("takes at least one argument\n")
        parser.print_help()
        sys.exit(1)

    dumper = XLDumper(args[0], params)
    if options.dump_mode == 'flat':
        dumper.dump()
    elif options.dump_mode == 'xml':
        dumper.dumpXML()
    elif options.dump_mode == 'canonical-xml' or options.dump_mode == 'cxml':
        dumper.dumpCanonicalXML()
    else:
        error("unknown dump mode: '%s'\n"%options.dump_mode)
        parser.print_help()
        sys.exit(1)

if __name__ == '__main__':
    main()

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

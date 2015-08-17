#!/usr/bin/env python2
# -*- encoding: UTF-8 -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import sys
sys.path.append(sys.path[0] + "/../..")
doc_dumper = __import__('doc-dump')
from xml.etree import ElementTree
import unittest
import os


class Test(unittest.TestCase):
    def dump(self, name):
        try:
            os.unlink("%s.doc.xml" % name)
        except OSError:
            pass
        sock = open("%s.doc.xml" % name, "w")
        saved = sys.stdout
        sys.stdout = sock
        doc_dumper.main(["doc-dumper", "%s.doc" % name])
        sys.stdout = saved
        sock.close()
        tree = ElementTree.parse('%s.doc.xml' % name)
        self.root = tree.getroot()
        # Make sure everything is dumped - so it can't happen that dump(a) == dump(b), but a != b.
        self.assertEqual(0, len(self.root.findall('todo')))

    def getFontId(self, name):
        fonts = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbSttbfFfn/sttbfFfn/cchData')
        for i in fonts:
            if len(i.findall('ffn/xszFfn[@value="%s"]' % name)) == 1:
                return int(i.attrib['index'])

    def getRuns(self):
        return self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfBteChpx/plcBteChpx/aFC/aPnBteChpx/chpxFkp/rgfc')

    def getParas(self):
        return self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfBtePapx/plcBtePapx/aFC/aPnBtePapx/papxFkp/rgfc')

    def getHex(self, num):
        return int(num, 16)

    def test_pass(self):
        """This test just makes sure that all files in the 'pass' directory are
        dumped without problems."""

        for dirname, dirnames, filenames in os.walk('pass'):
            for filename in filenames:
                if filename.endswith(".doc"):
                    self.dump(os.path.join(dirname, filename).replace('.doc', ''))

    def test_hello(self):
        self.dump('hello')

        runs = self.getRuns()
        self.assertEqual(1, len(runs))

        self.assertEqual('Hello world!\\x0D', runs[0].findall('transformed')[0].attrib['value'])

    def test_unicode(self):
        self.dump('unicode')

        uni = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbClx/clx/pcdt/plcPcd/aCP/transformed')
        self.assertEqual('Hello world! éáőű\\x0D', uni[0].attrib['value'])

    def test_charprops(self):
        self.dump('charprops')

        runs = self.getRuns()
        self.assertEqual(2, len(runs))

        self.assertEqual('Hello ', runs[0].findall('transformed')[0].attrib['value'])
        self.assertEqual(0, len(runs[0].findall('chpx/prl/sprm[@name="sprmCFBold"]')))

        self.assertEqual('world!\\x0D', runs[1].findall('transformed')[0].attrib['value'])
        self.assertEqual(1, len(runs[1].findall('chpx/prl/sprm[@name="sprmCFBold"]')))

    def test_fonts(self):
        self.dump('fonts')
        runs = self.getRuns()
        self.assertEqual(2, len(runs))

        self.assertEqual('This is Times New Roman ', runs[0].findall('transformed')[0].attrib['value'])
        self.assertEqual(self.getFontId("Times New Roman"), self.getHex(runs[0].findall('chpx/prl/sprm[@name="sprmCRgFtc0"]')[0].attrib['operand']))

        self.assertEqual('this is arial.\\x0D', runs[1].findall('transformed')[0].attrib['value'])
        self.assertEqual(self.getFontId("Arial"), self.getHex(runs[1].findall('chpx/prl/sprm[@name="sprmCRgFtc0"]')[0].attrib['operand']))

    def test_parprops(self):
        self.dump('parprops')
        paras = self.getParas()
        self.assertEqual(2, len(paras))

        self.assertEqual('Second para.\\x0D', paras[1].findall('transformed')[0].attrib['value'])
        self.assertEqual('0x1', paras[1].findall('bxPap/papxInFkp/grpPrlAndIstd/prl/sprm[@name="sprmPJc"]')[0].attrib['operand'])

    def test_parstyles(self):
        self.dump('parstyles')
        styles = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbStshf/stsh/rglpstd')
        self.assertEqual('Center', styles[15].findall('std/xstz/xst/rgtchar')[0].attrib['value'])

        paras = self.getParas()
        self.assertEqual(15, self.getHex(paras[1].findall('bxPap/papxInFkp/grpPrlAndIstd/istd')[0].attrib['value']))

    def test_comment(self):
        self.dump('comment')
        comments = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfandTxt/plcfandTxt/aCP')
        self.assertEqual(2, len(comments))

        self.assertEqual('This is a comment.\\x0D', comments[0].findall('transformed')[0].attrib['value'])
        self.assertEqual('This is also commented.\\x0D', comments[1].findall('transformed')[0].attrib['value'])

        commentStarts = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfAtnBkf/plcfBkf/aCP')
        commentEnds = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfAtnBkl/plcfBkl/aCP')

        # The first comment covers Hello\x05, the second covers This\x05.
        self.assertEqual('Hello', commentEnds[0].findall('transformed')[0].attrib['value'])
        self.assertEqual('This', commentEnds[1].findall('transformed')[0].attrib['value'])

        authors = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbGrpXstAtnOwners/grpXstAtnOwners/xst/rgtchar')
        self.assertEqual(1, len(authors))
        self.assertEqual('vmiklos', authors[0].attrib['value'])

    def test_bookmark(self):
        self.dump('bookmark')

        bookmarkStarts = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfBkf/plcfBkf/aCP')
        bookmarkEnds = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfBkl/plcfBkl/aCP')
        self.assertEqual(1, len(bookmarkStarts))
        self.assertEqual(1, len(bookmarkEnds))

        # The bookmark covers Hello
        self.assertEqual('Hello', bookmarkEnds[0].findall('transformed')[0].attrib['value'])

    def test_bookmark_nested(self):
        self.dump('bookmark-nested')

        bookmarkStarts = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfBkf/plcfBkf/aCP')
        bookmarkEnds = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfBkl/plcfBkl/aCP')
        self.assertEqual(2, len(bookmarkStarts))
        self.assertEqual(2, len(bookmarkEnds))

        # The outer bookmark should cover the inner one.
        # This was 'aaa bbb', not 'bbb': the bookmark start was incorrect.
        self.assertEqual('bbb', bookmarkEnds[0].findall('transformed')[0].attrib['value'])
        self.assertEqual('aaa bbb ccc', bookmarkEnds[1].findall('transformed')[0].attrib['value'])

    def test_zoom(self):
        self.dump('zoom')
        dopBase = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbDop/dop/dop2007/dop2003/dop2002/dop2000/dop97/dop95/dopBase')[0]
        # Zoom is 42%
        self.assertEqual('0x2a', dopBase.findall('pctWwdSaved')[0].attrib['value'])

    def test_nofibnew(self):
        self.dump('nofibnew')

        runs = self.getRuns()
        self.assertEqual(1, len(runs))

        self.assertEqual('Hello world!', runs[0].findall('transformed')[0].attrib['value'])

    def test_escape(self):
        # From https://bugs.freedesktop.org/show_bug.cgi?id=59106
        # This first caused unhandled exceptions, then later invalid XML output.
        self.dump('escape')

    def test_field(self):
        self.dump('field')

        instruction = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfFldMom/plcFld/aCP[@index="1"]/transformed')
        self.assertEqual(' PAGE ', instruction[0].attrib['value'])

        result = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfFldMom/plcFld/aCP[@index="2"]/transformed')
        self.assertEqual('1', result[0].attrib['value'])

    def test_sections(self):
        self.dump('sections')

        sections = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfSed/plcfSed/')
        self.assertEqual('Before section 1.\\x0D\\x0D\\x0C', sections[0].findall('transformed')[0].attrib['value'])
        self.assertEqual("\\x0DThe next one isn't a balanced one:\\x0D\\x0D\\x0C", sections[2].findall('transformed')[0].attrib['value'])

    def test_list(self):
        self.dump('list')

        levels = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlfLst/plfLst/lvl')
        self.assertEqual("•", levels[0].findall('xst/rgtchar')[0].attrib['value'])

    def test_header(self):
        self.dump('header')

        firstHeader = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfHdd/plcfHdd/aCP[@index="7"]')
        self.assertEqual("This is a header.\\x0D\\x0D", firstHeader[0].findall('transformed')[0].attrib['value'])

    def test_headerlo(self):
        self.dump('headerlo')

        firstHeader = self.root.findall('stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfHdd/plcfHdd/aCP[@index="7"]')
        self.assertEqual("This is a header.\\x0D\\x0D", firstHeader[0].findall('transformed')[0].attrib['value'])

    def test_abi1157(self):
        self.dump('abi1157-1')

    def test_picture(self):
        self.dump('picture')

        runs = self.getRuns()
        self.assertEqual(3, len(runs))

        # make sure the correct PNG data is dumped
        expected = "89504e470d0a1a0a0000000d4948445200000010000000100802000000909168360000015049444154789c9592c14a02511486bf99714ccb322d7521140541cb6a11448b164150fb8a363d41f4083d40cba0655044d0a637a837682fd1a6a2488b10b23475bcb77b671c491dc1cee23077e67cf7fcff39139252f29f08b59e3e1dae8b4c45998ff501a82e070f5cbd3366733acb5c6fa609fc0872651236df0deeca7d002a6cc33d1b941a146ab49ca937e37610e0c590c5c92b67f926a07243b293613f8b1108a8a84aadb01575c9799edd0c895010a0ae71048e77b99b6a92e53861a387a48a6033c5d208c297a43ca8a3697601d217b010632dd9a9f34be09968021698bea4c76ab72f5dd0d6216c3211e1bec2a0c5e59bce9303baa770c7bd38aca7d729692bcd4d512b53bb3b7cc2f45dd604ab098e67b499366025ce5e96a317fd2162e2d76bbbb725bdcd80b12a603aca4581e7aade97e14ec2916ca719ed96e4c54692f5241f755de7019641eacfaff10b469261dc6a800dd30000000049454e44ae426082"
        actual = runs[1].findall('chpx/prl[@index="0"]/sprm/PICFAndOfficeArtData/inlineSpContainer/fbse/blipPng/BLIPFileData')[0].attrib['value']
        self.assertEqual(expected, actual)

    def test_picture_wrap(self):
        self.dump('picture-wrap')

        # make sure the correct PNG data is dumped
        expected = "89504e470d0a1a0a0000000d4948445200000010000000100802000000909168360000015049444154789c9592c14a02511486bf99714ccb322d7521140541cb6a11448b164150fb8a363d41f4083d40cba0655044d0a637a837682fd1a6a2488b10b23475bcb77b671c491dc1cee23077e67cf7fcff39139252f29f08b59e3e1dae8b4c45998ff501a82e070f5cbd3366733acb5c6fa609fc0872651236df0deeca7d002a6cc33d1b941a146ab49ca937e37610e0c590c5c92b67f926a07243b293613f8b1108a8a84aadb01575c9799edd0c895010a0ae71048e77b99b6a92e53861a387a48a6033c5d208c297a43ca8a3697601d217b010632dd9a9f34be09968021698bea4c76ab72f5dd0d6216c3211e1bec2a0c5e59bce9303baa770c7bd38aca7d729692bcd4d512b53bb3b7cc2f45dd604ab098e67b499366025ce5e96a317fd2162e2d76bbbb725bdcd80b12a603aca4581e7aade97e14ec2916ca719ed96e4c54692f5241f755de7019641eacfaff10b469261dc6a800dd30000000049454e44ae426082"
        xpath = 'stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbDggInfo/officeArtContent/DrawingGroupData/bStoreContainer/fbse/blipPng/BLIPFileData'
        actual = self.root.findall(xpath)[0].attrib['value']
        self.assertEqual(expected, actual)

    def test_formtext(self):
        self.dump('formtext')

        # make sure we find that the max length is 5 chars
        expected = "0x5"
        xpath = 'stream[@name="WordDocument"]/fib/fibRgFcLcbBlob/lcbPlcfBteChpx/plcBteChpx/aFC/aPnBteChpx/chpxFkp/rgfc/chpx/prl/sprm/NilPICFAndBinData/FFData/cch'
        actual = self.root.findall(xpath)[0].attrib['value']
        self.assertEqual(expected, actual)

if __name__ == '__main__':
    unittest.main()

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

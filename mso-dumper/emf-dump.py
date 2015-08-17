#!/usr/bin/env python2
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import sys
sys = reload(sys)
sys.setdefaultencoding("utf-8")

from msodumper import emfrecord


class EMFDumper:
    def __init__(self, filepath):
        self.filepath = filepath

    def dump(self):
        file = open(self.filepath, 'rb')
        strm = emfrecord.EMFStream(file.read())
        file.close()
        print '<?xml version="1.0"?>'
        strm.dump()


def main(args):
    exname, args = args[0], args[1:]
    dumper = EMFDumper(args[0])
    dumper.dump()

if __name__ == '__main__':
    main(sys.argv)

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

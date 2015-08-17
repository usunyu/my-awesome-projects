#!/usr/bin/env python2
# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import sys
sys.path.append(sys.path[0]+"/../..")
xls_dumper = __import__('xls-dump')
import unittest
import os

class Test(unittest.TestCase):

    def test_foo (self):
        self.assertEqual(1+1, 2)

if __name__ == '__main__':
    unittest.main()

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

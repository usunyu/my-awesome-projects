# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import globals

class EncryptionInfo(object):

    class Type:
        Unknown = -1
        Standard = 0
        Extensible = 1
        Agile = 2

    def __init__ (self, bytes):
        self.strm = globals.ByteStream(bytes)
        self.type = EncryptionInfo.Type.Unknown
        self.size = -1

    def read (self):
        self.major = self.strm.readUnsignedInt(2)
        self.minor = self.strm.readUnsignedInt(2)

        if self.major == 3 or self.major == 4:
            if self.minor == 2:
                self.type = EncryptionInfo.Type.Standard
            elif self.minor == 3:
                self.type = EncryptionInfo.Type.Extensible
            elif self.minor == 4:
                self.type = EncryptionInfo.Type.Agile

        flag = self.strm.readUnsignedInt(4)
        self.fCryptoAPI = (flag & 0x00000004) != 0 # C
        self.fDocProps  = (flag & 0x00000008) != 0 # D (false if document properties are encrypted.)
        self.fExternal  = (flag & 0x00000010) != 0 # E (extensible encryption used)
        self.fAES       = (flag & 0x00000020) != 0 # F (ECMA-376 document)

        if self.type == EncryptionInfo.Type.Standard or self.type == EncryptionInfo.Type.Extensible:
            self.size = self.strm.readUnsignedInt(4)
        elif self.type == EncryptionInfo.Type.Agile:
            self.bytes = self.strm.readRemainingBytes()

    def outputBoolean (self, name, value):
        if value:
            bs = "true"
        else:
            bs = "false"
        print ("%s: %s"%(name, bs))

    def outputInt (self, name, value):
        print ("%s: %d"%(name, value))

    def output (self):
        print ("version: %d.%d"%(self.major, self.minor))
        self.outputBoolean("crypto API", self.fCryptoAPI)
        self.outputBoolean("encrypted document properties", not self.fDocProps)
        self.outputBoolean("extensible encryption", self.fExternal)
        self.outputBoolean("ECMA-376 document", self.fAES)
        if self.type == EncryptionInfo.Type.Standard:
            self.outputStandard()
        elif self.type == EncryptionInfo.Type.Extensible:
            self.outputExtensible()
        elif self.type == EncryptionInfo.Type.Agile:
            self.outputAgile()

    def outputStandard (self):
        self.outputInt("header stream size", self.size)

    def outputExtensible (self):
        self.outputInt("header stream size", self.size)

    def outputAgile (self):
        print (self.bytes)

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

import  sys, struct

class VBAStreamBase:
    CHUNKSIZE = 4096
    def __init__(self, chars, offset):
        self.mnOffset = offset
        self.chars = chars

    def copyTokenHelp(self):
        difference = self.DecompressedCurrent - self.DecompressedChunkStart
        bitCount = 0
        while( ( 1 << bitCount ) < difference ):
            bitCount +=1

        if bitCount < 4:
            bitCount = 4;

        lengthMask = 0xFFFF >> bitCount
        offSetMask = ~lengthMask
        maximumLength = ( 0xFFFF >> bitCount ) + 3
        return lengthMask, offSetMask, bitCount, maximumLength

class UnCompressedVBAStream(VBAStreamBase):
    def __packCopyToken(self, offset, length ):
        lengthMask, offSetMask, bitCount, maximumLength = self.copyTokenHelp()
        temp1 = offset - 1
        temp2 = 16 - bitCount
        temp3 = length - 3
        copyToken = (temp1 << temp2) | temp3
        return copyToken

    def __compressRawChunk(self):
        self.CompressedCurrent = self.CompressedChunkStart + 2
        self.DecompressedCurrent  = self.DecompressedChunkStart
        padCount = self.CHUNKSIZE
        lastByte = self.DecompressedChunkStart + padCount
        if self.DecompressedBufferEnd < lastByte:
           lastByte =  self.DecompressedBufferEnd

        for index in xrange( self.DecompressedChunkStart,  lastByte ):
            self.CompressedContainer[ self.CompressedCurrent ] = self.chars[ index ]
            self.CompressedCurrent = self.CompressedCurrent + 1
            self.DecompressedCurrent = self.DecompressedCurrent + 1
            padCount = padCount - 1

        for index in xrange( 0, padCount ):
            self.CompressedContainer[ self.CompressedCurrent ] = 0x0;
            self.CompressedCurrent = self.CompressedCurrent + 1

    def __matching( self, decompressedEnd ):
        candidate = self.DecompressedCurrent - 1
        bestLength = 0
        while candidate >= self.DecompressedChunkStart:
            c = candidate
            d = self.DecompressedCurrent
            nLen = 0
            while  d < decompressedEnd and ( self.chars[ d ] == self.chars[ c ] ):
                nLen = nLen + 1
                c = c + 1
                d = d + 1
            if nLen > bestLength:
                bestLength = nLen
                bestCandidate = candidate
            candidate = candidate - 1
        if bestLength >=  3:
            lengthMask, offSetMask, bitCount, maximumLength = self.copyTokenHelp()
            length = bestLength
            if ( maximumLength < bestLength ):
                length = maximumLength
            offset = self.DecompressedCurrent - bestCandidate
        else:
            length = 0
            offset = 0
        return offset, length

    def __compressToken( self, compressedEnd, decompressedEnd, index, flags ):
        offset = 0
        offset, length = self.__matching( decompressedEnd )
        if offset:
            if (self.CompressedCurrent + 1) < compressedEnd:
                copyToken = self.__packCopyToken( offset, length )
                struct.pack_into("<H", self.CompressedContainer, self.CompressedCurrent, copyToken )

                temp1 = ( 1 << index )
                temp2 = flags & ~temp1
                flags = temp2 | temp1

                self.CompressedCurrent = self.CompressedCurrent + 2
                self.DecompressedCurrent = self.DecompressedCurrent + length
            else:
                self.CompressedCurrent = compressedEnd
        else:
            if self.CompressedCurrent < compressedEnd:
                self.CompressedContainer[ self.CompressedCurrent ] = self.chars[ self.DecompressedCurrent ]
                self.CompressedCurrent = self.CompressedCurrent + 1
                self.DecompressedCurrent = self.DecompressedCurrent + 1
            else:
                self.CompressedCurrent = compressedEnd
        return flags

    def __compressTokenSequence(self, compressedEnd, decompressedEnd ):
        flagByteIndex = self.CompressedCurrent
        tokenFlags = 0
        self.CompressedCurrent = self.CompressedCurrent + 1
        for index in xrange(0,8):
            if ( ( self.DecompressedCurrent < decompressedEnd )
                and (self.CompressedCurrent < compressedEnd) ):

                tokenFlags = self.__compressToken( compressedEnd, decompressedEnd, index, tokenFlags )
        self.CompressedContainer[ flagByteIndex ] = tokenFlags

    def __CompressDecompressedChunk(self):
        self.CompressedContainer.extend(  bytearray(self.CHUNKSIZE + 2) )
        compressedEnd = self.CompressedChunkStart + 4098
        self.CompressedCurrent = self.CompressedChunkStart + 2
        decompressedEnd = self.DecompressedBufferEnd
        if  (self.DecompressedChunkStart + self.CHUNKSIZE) <  self.DecompressedBufferEnd:
            decompressedEnd = (self.DecompressedChunkStart + self.CHUNKSIZE)

        while (self.DecompressedCurrent < decompressedEnd) and (self.CompressedCurrent < compressedEnd):
                self.__compressTokenSequence( compressedEnd, decompressedEnd)

        if self.DecompressedCurrent < decompressedEnd:
            self.__compressRawChunk( decompressedEnd - 1 )
            compressedFlag = 0
        else:
            compressedFlag = 1
        size = self.CompressedCurrent - self.CompressedChunkStart
        header = 0x0000
        #Pack CompressedChunkSize with Size and Header
        temp1=header & 0xF000
        temp2 = size - 3
        header = temp1 | temp2
        #Pack CompressedChunkFlag with CompressedFlag and Header
        temp1 = header & 0x7FFF
        temp2 = compressedFlag << 15
        header = temp1 | temp2
        #Pack CompressedChunkSignature with Header
        temp1 = header & 0x8FFF
        Header = temp1 | 0x3000
        #CompressedChunkHeader located at CompressedChunkStart TO Header
        struct.pack_into("<H", self.CompressedContainer, self.CompressedChunkStart, Header )

        # trim buffer to size
        if ( self.CompressedCurrent ):
            self.CompressedContainer = self.CompressedContainer[ 0:self.CompressedCurrent ]

    def compress(self):
        self.CompressedContainer = bytearray()
        self.CompressedCurrent = 0
        self.CompressedChunkStart = 0
        self.DecompressedCurrent = 0
        self.DecompressedBufferEnd = len(self.chars)
        self.DecompressedChunkStart = 0
        SignatureByte = 0x01
        self.CompressedContainer.append( SignatureByte )
        self.CompressedCurrent = self.CompressedCurrent + 1
        while self.DecompressedCurrent < self.DecompressedBufferEnd:
            self.CompressedChunkStart = self.CompressedCurrent
            self.DecompressedChunkStart = self.DecompressedCurrent
            self.__CompressDecompressedChunk()
        return self.CompressedContainer

class CompressedVBAStream(VBAStreamBase):
    def __decompressRawChunk (self):
        for i in xrange(0,self.CHUNKSIZE):
            self.DecompressedChunk[ self.DecompressedCurrent + i ] =  self.chars[self.CompressedCurrent + i ]
        self.CompressedCurrent += self.CHUNKSIZE
        self.DecompressedCurrent += self.CHUNKSIZE

    def __unPackCopyToken (self, copyToken ):
       lengthMask, offSetMask, bitCount, maximumLength = self.copyTokenHelp()
       length = ( copyToken & lengthMask ) + 3
       temp1 = copyToken & offSetMask
       temp2 = 16 - bitCount
       offSet = ( temp1 >> temp2 ) + 1
       return offSet, length

    def __byteCopy( self, srcOffSet, dstOffSet, length ):
        destSize = len( self.DecompressedChunk )
        srcCurrent = srcOffSet
        dstCurrent = dstOffSet
        for i in xrange( 0, length ):
            self.DecompressedChunk[ dstCurrent ] = self.DecompressedChunk[ srcCurrent ]
            srcCurrent +=1
            dstCurrent +=1

    def __decompressToken (self, index, flagByte):
        flagBit = ( ( flagByte >> index ) & 1 )
        if flagBit == 0:
            self.DecompressedChunk[self.DecompressedCurrent] = self.chars[self.CompressedCurrent ]
            self.CompressedCurrent += 1
            self.DecompressedCurrent += 1
        else:
            copyToken = struct.unpack_from("<H", self.chars, self.CompressedCurrent)[0]
            offSet, length = self.__unPackCopyToken( copyToken )
            copySource =  self.DecompressedCurrent - offSet
            self.__byteCopy( copySource, self.DecompressedCurrent, length )
            self.DecompressedCurrent += length
            self.CompressedCurrent += 2

    def __decompressTokenSequence (self):
        flagByte = struct.unpack("b", self.chars[self.CompressedCurrent ])[0]
        self.CompressedCurrent += 1
        if  self.CompressedCurrent < self.CompressedEnd:
            for i in xrange(0,8):
                if  self.CompressedCurrent < self.CompressedEnd:
                    self.__decompressToken(i,flagByte)

    def decompressCompressedChunk (self):
        header = struct.unpack_from("<H",self.chars, self.CompressedChunkStart)[0]
        #extract size from header
        size = header & 0xFFF
        size = size + 3
        #extract chunk sig from header
        sigflag = header >> 12
        sig = sigflag & 0x7
        #extract chunk flag from sig
        compressedChunkFlag = (( sigflag & 0x8 ) ==  0x8)
        self.DecompressedChunk = bytearray(self.CHUNKSIZE);
        self.DecompressedChunkStart = 0
        self.DecompressedCurrent = 0
        self.CompressedEnd = self.CompressedRecordEnd
        if ( ( self.CompressedChunkStart + size ) < self.CompressedRecordEnd ):
            self.CompressedEnd = ( self.CompressedChunkStart + size )
        self.CompressedCurrent = self.CompressedChunkStart + 2
        if compressedChunkFlag == 1:
            while self.CompressedCurrent < self.CompressedEnd:
                self.__decompressTokenSequence()
        else:
            self.__decompressRawChunk()
        if self.DecompressedCurrent:
             truncChunk = self.DecompressedChunk[0:self.DecompressedCurrent]
             self.DecompressedContainer.extend( truncChunk )

    def decompress (self):
        self.DecompressedContainer = bytearray();
        self.CompressedCurrent = self.mnOffset
        self.CompressedRecordEnd = len(self.chars )
        self.DeCompressedBufferEnd = 0
        self.DecompressedChunkStart = 0
        val = struct.unpack("b", self.chars[self.CompressedCurrent])[0]
        if val == 1:
            self.CompressedCurrent += 1
            while self.CompressedCurrent < self.CompressedRecordEnd:
                self.CompressedChunkStart = self.CompressedCurrent
                self.decompressCompressedChunk()
            return self.DecompressedContainer
        else:
            raise Exception("error decompressing container invalid signature byte %i"%val)

        return None

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:

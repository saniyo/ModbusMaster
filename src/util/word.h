/**
@file
Utility Functions for Manipulating Words

@defgroup util_word "util/word.h": Utility Functions for Manipulating Words
@code#include "util/word.h"@endcode

This header file provides utility functions for manipulating words.

*/
/*

  word.h - Utility Functions for Manipulating Words

  This file is part of ModbusMaster.

  ModbusMaster is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  ModbusMaster is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with ModbusMaster.  If not, see <http://www.gnu.org/licenses/>.

  Written by Doc Walker (Rx)
  Copyright © 2009-2015 Doc Walker <4-20ma at wvfans dot net>

*/


#ifndef _UTIL_WORD_H_
#define _UTIL_WORD_H_


/** @ingroup util_word
    Return low word of a 32-bit integer.

    @param uint32_t ww (0x00000000..0xFFFFFFFF)
    @return low word of input (0x0000..0xFFFF)
*/
static inline uint16_t lowWord(uint32_t ww)
{
  return (uint16_t) ((ww) & 0xFFFF);
}


/** @ingroup util_word
    Return high word of a 32-bit integer.

    @param uint32_t ww (0x00000000..0xFFFFFFFF)
    @return high word of input (0x0000..0xFFFF)
*/
static inline uint16_t highWord(uint32_t ww)
{
  return (uint16_t) ((ww) >> 16);
}

static inline uint32_t bytesToDword(uint32_t b3,uint32_t b2,uint32_t b1,uint32_t b0)
{
  return (uint32_t) ((b3 << 24) | (b2 << 16) | (b1 << 8) | b0);
}

/** @ingroup util_word
    Return high word of a 32-bit integer.

    @param uint32_t ww (0x00000000..0xFFFFFFFF)
    @return bytes of input parameter
*/

union ui32_4bytes 
{
 struct
  {
   byte b1;
   byte b2;
   byte b3;
   byte b4;
  
  }; 
  uint32_t equals;
};

/** @ingroup util_crPrintHEX
    
    Serial.print("  1-Digit=");  crPrintHEX(DATA,1);
    Serial.print("  4-Digits="); crPrintHEX(DATA,4);
    Serial.print("  7-Digits="); crPrintHEX(DATA,7);
    Serial.print("  8-Digits="); crPrintHEX(DATA,8);

    @param DATA
    @param numChars
    
    @return print HEX with leading zero
    Prints: 1-Digit=E    4-Digits=017E    7-Digits=000017E    8-Digits=0000017E
*/
static inline void crPrintHEX(unsigned long DATA, unsigned char numChars)
{
  unsigned long mask = 0x0000000F;
  mask = mask << 4 * (numChars - 1);

  for (unsigned int i = numChars; i > 0; --i)
  {
    Serial.print(((DATA & mask) >> (i - 1) * 4), HEX);
    mask = mask >> 4;
  }

  Serial.print(" ");
}

#endif /* _UTIL_WORD_H_ */

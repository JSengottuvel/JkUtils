/*
MIT License

Copyright (c) [2015-2019] [Jayakumar Sengottuvel] [www.jayakumar.de]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/** @file jkchex.h
 *  @brief C hex helper
 *
 *  A helper for hex operations
 *
 *  @author Jayakumar Sengottuvel (JSengottuvel)
 *  @bug No know bugs.
 */

#include <stdio.h>

extern int JkCHex_Str2Format(char* input, char* output, int outbufferlength, char* formatString);

extern int JkCHex_Str2Ascii(char* input, char* output, int outbufferlength);

extern int JkCHex_Str2AsciiHex1(char* input, char* output, int outbufferlength);

extern int JkCHex_Str2AsciiHex2(char* input, char* output, int outbufferlength);

extern int JkCHex_Str2AsciiByteStream(char* input, char* output, int outbufferlength);

extern int JkCHex_ByteArray2Format(unsigned char* inputBytes, int numBytes, char* output,
                int outbufferlength, char* formatString);

extern int JkCHex_ByteArray2AsciiByteStream(unsigned char* inputBytes, int numBytes,
                char* output, int outbufferlength);

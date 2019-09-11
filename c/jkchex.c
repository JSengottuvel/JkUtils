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

/** @file jkchex.c
 *  @brief C Hex helper
 *
 *  A helper for Hex operation
 *
 *  @author Jayakumar Sengottuvel (JSengottuvel)
 *  @bug No know bugs.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "jkchex.h"

int JkCHex_Str2Format(char* input, char* output, int outbufferlength, char* formatString)
{
    int retErrorCode = 0;
    //Check if output buffer size big enough to store the result.
    int lenInput = strlen(input);
    int wIdx = 0;
    int result;
    char* pIn = input;
    char* pOut = output;
    do
    {
        result = snprintf(pOut, (outbufferlength - wIdx), formatString, *pIn);
        if(result < 0)
        {
            retErrorCode = -2;
            break;
        }
        else
        {
            pIn++;
            pOut += result;
            wIdx += result;
            if(wIdx >= outbufferlength)
            {
                retErrorCode = -3;
                break;
            }
        }
    }while((*pIn));
    return retErrorCode;
}

int JkCHex_Str2Ascii(char* input, char* output, int outbufferlength)
{
    return JkCHex_Str2Format(input, output, outbufferlength, "%d ");
}

int JkCHex_Str2AsciiHex1(char* input, char* output, int outbufferlength)
{
    return JkCHex_Str2Format(input, output, outbufferlength, "0x%02X ");
}

int JkCHex_Str2AsciiHex2(char* input, char* output, int outbufferlength)
{
    return JkCHex_Str2Format(input, output, outbufferlength, "$%02X ");
}

int JkCHex_Str2AsciiByteStream(char* input, char* output, int outbufferlength)
{
    return JkCHex_Str2Format(input, output, outbufferlength, "%02X");
}

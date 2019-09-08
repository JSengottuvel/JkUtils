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

/** @file jkcstring.c
 *  @brief C string helper
 *
 *  A helper for string operation
 *
 *  @author Jayakumar Sengottuvel (JSengottuvel)
 *  @bug No know bugs.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "jkcstring.h"

char* JkCString_Trim(char* text)
{
    char* pstart = text;
    char* pend   = text;
    if(text == NULL)
    {
        return NULL;
    }
    //Removes the leading spaces
    while (isspace(*pstart))
    {
        pstart++;
    }
    //Find the end of string
    while (*pend)
    {
        pend++;
    }
    pend--;  //move back one char. (point to last valid character)
    while (isspace(*pend))
    {
        pend--;
    }
    *pend++;     //Move forward one char.
    *pend= '\0'; //Write string termination
    text = pstart; //also return the results by argument
    return pstart; //return the result
}

void  JkCString_PadLeft(char* input, char* output, char padChar, int padLength)
{
    JkCString_CopyFromRightAndPadLeft(input, strlen(input), output, padChar, padLength);
}

void JkCString_CopyFromRight(char* input, int copylength, char* output)
{
    int inputLength = strlen(input);
    int xLength  = copylength < inputLength? copylength: inputLength;
    memcpy(output, &input[inputLength - xLength], xLength);
    output[xLength] = 0; //string termination
}

void JkCString_CopyFromRightAndPadLeft(char* input, int copylength,
        char* output, char padChar, int padLength)
{
    char* oend = output;
    char* iend   = input;
    int xLength  = copylength < strlen(input)? copylength: strlen(input);
    int xpadLength = padLength < xLength ? xLength : padLength;
    memset(output, padChar, xpadLength);
    output[xpadLength] = 0; //string termination
    /* Move pointer to end of the string*/
    while (*oend) { oend++; } oend--;
    while (*iend) { iend++; } iend--;
    /*Adjust source and target pointers for copy job*/
    oend = oend - xLength +1;
    iend = iend - xLength +1;
    memcpy(oend, iend, xLength);
}

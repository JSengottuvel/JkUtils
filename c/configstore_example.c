/*
MIT License

Copyright (c) [2019] [Jayakumar Sengottuvel] [www.jayakumar.de]

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

/** @file configstore_example.c
 *  @brief configstore example
 *
 *  An Example to demonstrate the useage of configstore
 *
 *  @author Jayakumar Sengottuvel (JSengottuvel)
 *  @bug No know bugs.
 */

#include <stdio.h>
#include "configstore.h"
#include "jkcstring.h"
#include "jkchex.h"

ConfigStore_KeyPairType ConfigItems[5] = {
    {"Name",""},
    {"Email",""},
    {"Website",""},
    {"Linked In",""},
    {"GitHub",""},
};

const int numConfigs = sizeof(ConfigItems)/sizeof(ConfigStore_KeyPairType);

int main() {

    /* Example usage of ConfigStore helpers */
    ConfigStore_LoadFromFile("userconfig.txt", ConfigItems, numConfigs);
    ConfigStore_Display(ConfigItems, numConfigs);

    /* Example usage of JkCString helpers */
    char inText[] ="Software Engineers Are Great!";
    char outText[100];
    int length =6;

    JkCString_CopyFromRight(inText, length, outText);
    printf("\nInputText: %s", inText);
    printf("\n%d letters from Right:%s", length, outText);

    JkCString_CopyFromRightAndPadLeft(inText, length, outText, '#', 20);
    printf("\npadded string:%s", outText);

    JkCString_PadLeft(inText, outText, '-', 40);
    printf("\nPadLeft string:%s", outText);

    /*Example usage of JkCHex helpers */
    char outAscii[200];
    JkCHex_Str2Ascii(inText, outAscii, sizeof(outAscii), " ");
    printf("\nAscii string: %s", outAscii);

    return 0;
}

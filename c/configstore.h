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

/** @file configstore.h
 *  @brief A file based config storage
 *
 *  A helper for file based key pair configuration
 *
 *  @author Jayakumar Sengottuvel (JSengottuvel)
 *  @bug No know bugs.
 */

#include <stdio.h>

#define CONFIGSTORE_LINE_MAXCHAR  (1000u)
#define CONFIGSTORE_KEY_MAXCHAR   (200u)
#define CONFIGSTORE_VALUE_MAXCHAR (200u)

typedef struct ConfigStore_KeyPairType {
    char const key[CONFIGSTORE_KEY_MAXCHAR];
    char value[CONFIGSTORE_VALUE_MAXCHAR];
}ConfigStore_KeyPairType;

/*Public functions*/
extern void ConfigStore_LoadFromFile(char* filename, ConfigStore_KeyPairType* list, int numItems);
extern void ConfigStore_Display(ConfigStore_KeyPairType* list, int numItems);
extern int ConfigStore_GetValue(char* filename, char const * key, char*value, int valueLength);
extern char* ConfigStore_TrimText(char* text);
extern int ConfigStore_ParseKeyPair(char *lineText, char** p2pKey, char **p2pValue);
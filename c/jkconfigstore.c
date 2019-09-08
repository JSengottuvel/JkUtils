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

/** @file jkconfigstore.c
 *  @brief A file based config storage
 *
 *  A helper for file based key pair configuration
 *
 *  @author Jayakumar Sengottuvel (JSengottuvel)
 *  @bug No know bugs.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "jkconfigstore.h"
#include "jkcstring.h"

int JkConfigStore_ParseKeyPair(char *lineText, char** p2pKey, char **p2pValue)
{
    int retErrorCode = -1; //Error
    char delimKey[] = ":";
    char delimValue[] = "\n";
    char* pkey;
    char* pvalue;
    if(lineText == NULL)
    {
        return retErrorCode;
    }
    pkey = strtok(lineText, delimKey);
    pkey = JkCString_Trim(pkey);
    *p2pKey = pkey;
    if(pkey != NULL)
    {
        pvalue = strtok(NULL, delimValue);
        pvalue = JkCString_Trim(pvalue);
        *p2pValue = pvalue;
        if(pvalue != NULL)
        {
            retErrorCode = 0; //Success
        }
    }
    return retErrorCode;
}

int JkConfigStore_GetValue(char* filename, char const * key, char*value, int valueLength)
{
    int retErrorCode = -1; //error
    FILE *fp;
    char strLine[JKCONFIGSTORE_LINE_MAXCHAR];
    char* pkey;
    char* pvalue;
    fp = fopen(filename, "r");
    if (fp == NULL){
        return retErrorCode;
    }
    while(fgets(strLine, JKCONFIGSTORE_LINE_MAXCHAR, fp) != NULL)
    {
        if(JkConfigStore_ParseKeyPair(strLine, &pkey, &pvalue) == 0)
        {
            if(strcmp(pkey, key) == 0)
            {
               strncpy(value, pvalue,  valueLength);
               retErrorCode = 0; //Success;
               break;
            }
        }
    }
    fclose(fp);
    return retErrorCode;
}

void JkConfigStore_LoadFromFile(char* filename, JkConfigStore_KeyPairType* list, int numItems)
{
    int i;
    for(i = 0; i < numItems; i++)
    {
        JkConfigStore_KeyPairType* item= &list[i];
        if(JkConfigStore_GetValue(filename, item->key, item->value, sizeof(item->value))== 0)
        {
            //success
        }
    }
}

void JkConfigStore_Display(JkConfigStore_KeyPairType* list, int numItems)
{
    int i;
    for(i = 0; i < numItems; i++)
    {
        JkConfigStore_KeyPairType* item= &list[i];
        printf("\n%-30s:%-20s", item->key, item->value);
    }
}

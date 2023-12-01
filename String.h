#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>
#include <memory.h>

typedef struct String String;

struct String
{
    char* pCharData;
    unsigned int capacity;
};

void String_Init(String* pString, const char* pCharData);
void String_Destroy(String* pString);
void String_SetData(String* pString, const char* pCharData);
void String_Insert(String* pTargetString, String* pAddString, unsigned int index);
void String_Append(String* pTargetString, String* pAddString);
void String_Delete(String* pString, unsigned int startIndex, unsigned int endIndex);
int String_Find(String* pFullString, String* pPatternString);

const char* String_GetData(String* pString);
char String_GetCharAt(String* pString, unsigned int index);
unsigned int String_GetLength(String* pString);
String String_GetSubString(String* pString, unsigned int startIndex, unsigned int endIndex);

#endif
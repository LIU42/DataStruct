#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>
#include <memory.h>

typedef struct String 
{
    char* pData;
    int length;
    int capacity;
} String;

String* String_Create(const char* pData, int capacity);
void String_Destroy(String* pString);
void String_SetData(String* pString, const char* pData);
void String_Insert(String* pTargetString, String* pInsertString, int index);
void String_Append(String* pTargetString, String* pAppendString);
void String_Delete(String* pString, int startIndex, int endIndex);
void String_AdjustCapacity(String* pString, int capacity);
int String_Find(String* pFullString, String* pPatternString);

const char* String_GetData(String* pString);
char String_GetCharAt(String* pString, int index);
int String_GetLength(String* pString);
int String_GetCapacity(String* pString);
String* String_GetSubString(String* pString, int startIndex, int endIndex);

#endif
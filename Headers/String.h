#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>
#include <memory.h>

typedef struct String 
{
    char* pCharArray;
    int length;
    int capacity;
} String;

String* String_Create(const char* pCharArray);
String* String_Copy(String* pString);
String* String_GetSubString(String* pString, int index, int length);

void String_SetCharArray(String* pString, const char* pCharArray);
void String_Clear(String* pString);
void String_Destroy(String* pString);

void String_Insert(String* pTargetString, String* pInsertString, int index);
void String_Append(String* pTargetString, String* pAppendString);
void String_Remove(String* pString, int index, int length);
int String_Search(String* pSearchString, String* pPatternString);

const char* String_GetCharArray(String* pString);
int String_GetLength(String* pString);
int String_GetCapacity(String* pString);
char String_GetCharAt(String* pString, int index);

#endif

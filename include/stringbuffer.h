#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>
#include <memory.h>

typedef struct StringBuffer 
{
    char* pCharArray;
    int length;
    int capacity;
} StringBuffer;

StringBuffer* StringBuffer_Create(const char* pCharArray);
StringBuffer* StringBuffer_Copy(StringBuffer* pStringBuffer);
StringBuffer* StringBuffer_GetSubStringBuffer(StringBuffer* pStringBuffer, int index, int length);

void StringBuffer_SetCharArray(StringBuffer* pStringBuffer, const char* pCharArray);
void StringBuffer_Clear(StringBuffer* pStringBuffer);
void StringBuffer_Destroy(StringBuffer* pStringBuffer);

void StringBuffer_Insert(StringBuffer* pTargetStringBuffer, StringBuffer* pInsertStringBuffer, int index);
void StringBuffer_Append(StringBuffer* pTargetStringBuffer, StringBuffer* pAppendStringBuffer);
void StringBuffer_Remove(StringBuffer* pStringBuffer, int index, int length);
int StringBuffer_Search(StringBuffer* pSearchStringBuffer, StringBuffer* pPatternStringBuffer);

const char* StringBuffer_GetCharArray(StringBuffer* pStringBuffer);
int StringBuffer_GetLength(StringBuffer* pStringBuffer);
int StringBuffer_GetCapacity(StringBuffer* pStringBuffer);
char StringBuffer_GetCharAt(StringBuffer* pStringBuffer, int index);

#endif

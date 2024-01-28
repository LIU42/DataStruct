#include "String.h"

String* String_Create(const char* pData, int capacity)
{
    String* pString = (String*)malloc(sizeof(String));
    pString->length = 0;
    pString->capacity = capacity;

    while (pData[pString->length] != '\0')
    {
        pString->length += 1;
    }
    int dataCapacity = pString->length + 1;

    if (capacity < dataCapacity)
    {
        pString->capacity = dataCapacity;
    }
    pString->pData = (char*)malloc(pString->capacity);
    memcpy(pString->pData, pData, dataCapacity);
    return pString;
}

void String_Destroy(String* pString)
{
    free(pString->pData);
    free(pString);
    pString = NULL;
}

void String_SetData(String* pString, const char* pData)
{
    pString->length = 0;

    while (pData[pString->length] != '\0')
    {
        pString->length += 1;
    }
    int dataCapacity = pString->length + 1;

    if (pString->capacity < dataCapacity)
    {
        pString->pData = (char*)realloc(pString->pData, dataCapacity);
        pString->capacity = dataCapacity;
    }
    memcpy(pString->pData, pData, pString->capacity);
}

void String_CapacityGrowth(String* pTargetString, String* pInsertString)
{
    int sumCapacity = pTargetString->length + pInsertString->length + 1;

    if (pTargetString->capacity < sumCapacity)
    {
        pTargetString->pData = (char*)realloc(pTargetString->pData, sumCapacity);
        pTargetString->capacity = sumCapacity;
    }
}

void String_Insert(String* pTargetString, String* pInsertString, int index)
{
    String_CapacityGrowth(pTargetString, pInsertString);
    memcpy(pTargetString->pData + pInsertString->length + index, pTargetString->pData + index, pTargetString->length - index + 1);
    memcpy(pTargetString->pData + index, pInsertString->pData, pInsertString->length);
    pTargetString->length += pInsertString->length;
}

void String_Append(String* pTargetString, String* pAppendString)
{
    String_CapacityGrowth(pTargetString, pAppendString);
    memcpy(pTargetString->pData + pTargetString->length, pAppendString->pData, pAppendString->length + 1);
    pTargetString->length += pAppendString->length;
}

void String_Delete(String* pString, int startIndex, int endIndex)
{
    memcpy(pString->pData + startIndex, pString->pData + endIndex, pString->length - endIndex + 1);
    pString->length -= endIndex - startIndex;
}

void String_AdjustCapacity(String* pString, int capacity)
{
    if (capacity < pString->length + 1)
    {
        capacity = pString->length + 1;
    }
    pString->pData = (char*)realloc(pString->pData, capacity);
    pString->capacity = capacity;
}

int* String_GetNextList(String* pPatternString)
{
    int* pNextList = (int*)malloc(sizeof(int) * pPatternString->length);
    int nextIndex = 1;
    int nextTemp = 0;
    pNextList[0] = 0;

    while (nextIndex < pPatternString->length)
    {
        if (pPatternString->pData[nextTemp] == pPatternString->pData[nextIndex])
        {
            pNextList[nextIndex] = nextTemp + 1;
            nextTemp += 1;
            nextIndex += 1;
        }
        else if (nextTemp > 0)
        {
            nextTemp = pNextList[nextTemp - 1];
        }
        else if (nextTemp == 0)
        {
            pNextList[nextIndex] = 0;
            nextIndex += 1;
        }
    }
    return pNextList;
}

int String_Find(String* pFullString, String* pPatternString)
{
    int* pNextList = String_GetNextList(pPatternString);
    int fullIndex = 0;
    int patternIndex = 0;
    int findIndex = -1;

    while (fullIndex < pFullString->length)
    {
        if (pFullString->pData[fullIndex] == pPatternString->pData[patternIndex])
        {
            fullIndex += 1;
            patternIndex += 1;
        }
        else if (patternIndex > 0)
        {
            patternIndex = pNextList[patternIndex - 1];
        }
        else if (patternIndex == 0)
        {
            fullIndex += 1;
        }
        if (patternIndex == pPatternString->length)
        {
            findIndex = fullIndex - patternIndex;
            break;
        }
    }
    free(pNextList);
    return findIndex;
}

const char* String_GetData(String* pString)
{
    return pString->pData;
}

char String_GetCharAt(String* pString, int index)
{
    return pString->pData[index];
}

int String_GetLength(String* pString)
{
    return pString->length;
}

int String_GetCapacity(String* pString)
{
    return pString->capacity;
}

String* String_GetSubString(String* pString, int startIndex, int endIndex)
{
    String* pSubString = (String*)malloc(sizeof(String));
    pSubString->length = endIndex - startIndex;
    pSubString->capacity = pSubString->length + 1;
    pSubString->pData = (char*)malloc(pSubString->capacity);
    pSubString->pData[pSubString->length] = '\0';
    memcpy(pSubString->pData, pString->pData + startIndex, pSubString->length);
    return pSubString;
}
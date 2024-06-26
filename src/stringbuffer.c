#include "stringbuffer.h"

int StringBuffer_GetCharArrayLength(const char* pCharArray)
{
    int arrayLength = 0;

    while (pCharArray[arrayLength] != '\0')
    {
        arrayLength += 1;
    }
    return arrayLength;
}

void StringBuffer_CapacityGrowth(StringBuffer* pStringBuffer, int targetLength)
{
    while (pStringBuffer->capacity <= targetLength)
    {
        pStringBuffer->capacity <<= 1;
    }
    pStringBuffer->pCharArray = (char*)realloc(pStringBuffer->pCharArray, pStringBuffer->capacity);
}

StringBuffer* StringBuffer_Create(const char* pCharArray)
{
    StringBuffer* pStringBuffer = (StringBuffer*)malloc(sizeof(StringBuffer));

    pStringBuffer->pCharArray = NULL;
    pStringBuffer->length = 0;
    pStringBuffer->capacity = 16;

    String_SetCharArray(pStringBuffer, pCharArray);
    return pStringBuffer;
}

StringBuffer* StringBuffer_Copy(StringBuffer* pStringBuffer)
{
    StringBuffer* pNewStringBuffer = (StringBuffer*)malloc(sizeof(StringBuffer));

    pNewStringBuffer->pCharArray = (char*)malloc(pStringBuffer->capacity);
    pNewStringBuffer->length = pStringBuffer->length;
    pNewStringBuffer->capacity = pStringBuffer->capacity;

    memcpy(pNewStringBuffer->pCharArray, pStringBuffer->pCharArray, pStringBuffer->length + 1);
    return pNewStringBuffer;
}

StringBuffer* StringBuffer_GetSubStringBuffer(StringBuffer* pStringBuffer, int index, int length)
{
    StringBuffer* pSubStringBuffer = (StringBuffer*)malloc(sizeof(StringBuffer));

    pSubStringBuffer->pCharArray = (char*)malloc(pStringBuffer->capacity);
    pSubStringBuffer->pCharArray[length] = '\0';
    pSubStringBuffer->length = length;
    pSubStringBuffer->capacity = pStringBuffer->capacity;

    memcpy(pSubStringBuffer->pCharArray, pStringBuffer->pCharArray + index, length);
    return pSubStringBuffer;
}

void StringBuffer_Clear(StringBuffer* pStringBuffer)
{
    pStringBuffer->pCharArray[0] = '\0';
    pStringBuffer->length = 0;
}

void StringBuffer_Destroy(StringBuffer* pStringBuffer)
{
    free(pStringBuffer->pCharArray);
    free(pStringBuffer);
    
    pStringBuffer = NULL;
}

void StringBuffer_SetCharArray(StringBuffer* pStringBuffer, const char* pCharArray)
{
    pStringBuffer->length = StringBuffer_GetCharArrayLength(pCharArray);

    StringBuffer_CapacityGrowth(pStringBuffer, pStringBuffer->length);
    memcpy(pStringBuffer->pCharArray, pCharArray, pStringBuffer->length + 1);
}

void StringBuffer_Insert(StringBuffer* pTargetStringBuffer, StringBuffer* pInsertStringBuffer, int index)
{
    StringBuffer_CapacityGrowth(pTargetStringBuffer, pTargetStringBuffer->length + pInsertStringBuffer->length);

    char* pTargetArray = pTargetStringBuffer->pCharArray;
    char* pInsertArray = pInsertStringBuffer->pCharArray;

    memcpy(pTargetArray + pInsertStringBuffer->length + index, pTargetArray + index, pTargetStringBuffer->length - index + 1);
    memcpy(pTargetArray + index, pInsertArray, pInsertStringBuffer->length);
    pTargetStringBuffer->length += pInsertStringBuffer->length;
}

void StringBuffer_Append(StringBuffer* pTargetStringBuffer, StringBuffer* pAppendStringBuffer)
{
    StringBuffer_CapacityGrowth(pTargetStringBuffer, pTargetStringBuffer->length + pAppendStringBuffer->length);

    char* pTargetArray = pTargetStringBuffer->pCharArray;
    char* pAppendArray = pAppendStringBuffer->pCharArray;

    memcpy(pTargetArray + pTargetStringBuffer->length, pAppendArray, pAppendStringBuffer->length + 1);
    pTargetStringBuffer->length += pAppendStringBuffer->length;
}

void StringBuffer_Remove(StringBuffer* pStringBuffer, int index, int length)
{
    int movedIndex = (index + length < pStringBuffer->length) ? index + length : pStringBuffer->length;

    memcpy(pStringBuffer->pCharArray + index, pStringBuffer->pCharArray + movedIndex, pStringBuffer->length - movedIndex + 1);
    pStringBuffer->length -= length;
}

int* StringBuffer_GetNextArray(StringBuffer* pPatternStringBuffer)
{
    int* pNextArray = (int*)malloc(sizeof(int) * pPatternStringBuffer->length);

    int nextIndex = 1;
    int nextTemp = 0;

    pNextArray[0] = 0;

    while (nextIndex < pPatternStringBuffer->length)
    {
        if (pPatternStringBuffer->pCharArray[nextTemp] == pPatternStringBuffer->pCharArray[nextIndex])
        {
            pNextArray[nextIndex] = nextTemp + 1;
            nextTemp += 1;
            nextIndex += 1;
        }
        else if (nextTemp > 0)
        {
            nextTemp = pNextArray[nextTemp - 1];
        }
        else if (nextTemp == 0)
        {
            pNextArray[nextIndex] = 0;
            nextIndex += 1;
        }
    }
    return pNextArray;
}

int StringBuffer_Search(StringBuffer* pSearchStringBuffer, StringBuffer* pPatternStringBuffer)
{
    int* pNextArray = String_GetNextArray(pPatternStringBuffer);

    int searchIndex = 0;
    int patternIndex = 0;
    int resultIndex = -1;

    while (searchIndex < pSearchStringBuffer->length)
    {
        if (pSearchStringBuffer->pCharArray[searchIndex] == pPatternStringBuffer->pCharArray[patternIndex])
        {
            searchIndex += 1;
            patternIndex += 1;
        }
        else if (patternIndex > 0)
        {
            patternIndex = pNextArray[patternIndex - 1];
        }
        else if (patternIndex == 0)
        {
            searchIndex += 1;
        }
        if (patternIndex == pPatternStringBuffer->length)
        {
            resultIndex = searchIndex - patternIndex;
            break;
        }
    }
    free(pNextArray);
    return resultIndex;
}

const char* StringBuffer_GetCharArray(StringBuffer* pStringBuffer)
{
    return pStringBuffer->pCharArray;
}

int StringBuffer_GetLength(StringBuffer* pStringBuffer)
{
    return pStringBuffer->length;
}

int StringBuffer_GetCapacity(StringBuffer* pStringBuffer)
{
    return pStringBuffer->capacity;
}

char StringBuffer_GetCharAt(StringBuffer* pStringBuffer, int index)
{
    return pStringBuffer->pCharArray[index];
}

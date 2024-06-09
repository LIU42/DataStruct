#include "String.h"

int String_GetCharArrayLength(const char* pCharArray)
{
    int arrayLength = 0;

    while (pCharArray[arrayLength] != '\0')
    {
        arrayLength += 1;
    }
    return arrayLength;
}

void String_CapacityGrowth(String* pString, int targetLength)
{
    while (pString->capacity <= targetLength)
    {
        pString->capacity <<= 1;
    }
    pString->pCharArray = (char*)realloc(pString->pCharArray, pString->capacity);
}

String* String_Create(const char* pCharArray)
{
    String* pString = (String*)malloc(sizeof(String));

    pString->pCharArray = NULL;
    pString->length = 0;
    pString->capacity = 16;

    String_SetCharArray(pString, pCharArray);
    return pString;
}

String* String_Copy(String* pString)
{
    String* pNewString = (String*)malloc(sizeof(String));

    pNewString->pCharArray = (char*)malloc(pString->capacity);
    pNewString->length = pString->length;
    pNewString->capacity = pString->capacity;

    memcpy(pNewString->pCharArray, pString->pCharArray, pString->length + 1);
    return pNewString;
}

String* String_GetSubString(String* pString, int index, int length)
{
    String* pSubString = (String*)malloc(sizeof(String));

    pSubString->pCharArray = (char*)malloc(pString->capacity);
    pSubString->pCharArray[length] = '\0';
    pSubString->length = length;
    pSubString->capacity = pString->capacity;

    memcpy(pSubString->pCharArray, pString->pCharArray + index, length);
    return pSubString;
}

void String_Clear(String* pString)
{
    pString->pCharArray[0] = '\0';
    pString->length = 0;
}

void String_Destroy(String* pString)
{
    free(pString->pCharArray);
    free(pString);
    
    pString = NULL;
}

void String_SetCharArray(String* pString, const char* pCharArray)
{
    pString->length = String_GetCharArrayLength(pCharArray);

    String_CapacityGrowth(pString, pString->length);
    memcpy(pString->pCharArray, pCharArray, pString->length + 1);
}

void String_Insert(String* pTargetString, String* pInsertString, int index)
{
    String_CapacityGrowth(pTargetString, pTargetString->length + pInsertString->length);

    char* pTargetArray = pTargetString->pCharArray;
    char* pInsertArray = pInsertString->pCharArray;

    memcpy(pTargetArray + pInsertString->length + index, pTargetArray + index, pTargetString->length - index + 1);
    memcpy(pTargetArray + index, pInsertArray, pInsertString->length);
    pTargetString->length += pInsertString->length;
}

void String_Append(String* pTargetString, String* pAppendString)
{
    String_CapacityGrowth(pTargetString, pTargetString->length + pAppendString->length);

    char* pTargetArray = pTargetString->pCharArray;
    char* pAppendArray = pAppendString->pCharArray;

    memcpy(pTargetArray + pTargetString->length, pAppendArray, pAppendString->length + 1);
    pTargetString->length += pAppendString->length;
}

void String_Remove(String* pString, int index, int length)
{
    int movedIndex = (index + length < pString->length) ? index + length : pString->length;

    memcpy(pString->pCharArray + index, pString->pCharArray + movedIndex, pString->length - movedIndex + 1);
    pString->length -= length;
}

int* String_GetNextArray(String* pPatternString)
{
    int* pNextArray = (int*)malloc(sizeof(int) * pPatternString->length);

    int nextIndex = 1;
    int nextTemp = 0;

    pNextArray[0] = 0;

    while (nextIndex < pPatternString->length)
    {
        if (pPatternString->pCharArray[nextTemp] == pPatternString->pCharArray[nextIndex])
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

int String_Search(String* pSearchString, String* pPatternString)
{
    int* pNextArray = String_GetNextArray(pPatternString);

    int searchIndex = 0;
    int patternIndex = 0;
    int resultIndex = -1;

    while (searchIndex < pSearchString->length)
    {
        if (pSearchString->pCharArray[searchIndex] == pPatternString->pCharArray[patternIndex])
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
        if (patternIndex == pPatternString->length)
        {
            resultIndex = searchIndex - patternIndex;
            break;
        }
    }
    free(pNextArray);
    return resultIndex;
}

const char* String_GetCharArray(String* pString)
{
    return pString->pCharArray;
}

int String_GetLength(String* pString)
{
    return pString->length;
}

int String_GetCapacity(String* pString)
{
    return pString->capacity;
}

char String_GetCharAt(String* pString, int index)
{
    return pString->pCharArray[index];
}

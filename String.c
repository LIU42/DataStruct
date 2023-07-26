#include "String.h"

void String_Init(String* pString, char* pCharData)
{
    pString->capacity = 1;

    for (int i = 0; pCharData[i] != '\0'; i++)
    {
        pString->capacity += 1;
    }
    pString->pCharData = (char*)malloc(pString->capacity);
    memcpy(pString->pCharData, pCharData, pString->capacity);
}

void String_Destroy(String* pString)
{
    free(pString->pCharData);
    pString->capacity = 0;
}

void String_SetData(String* pString, char* pCharData)
{
    String_Destroy(pString);
    String_Init(pString, pCharData);
}

void String_Insert(String* pTargetString, String* pAddString, int index)
{
    if (index >= 0 && index < pTargetString->capacity)
    {
        int targetMemorySize = pTargetString->capacity;
        int addMemorySize = pAddString->capacity;
        int newMemorySize = targetMemorySize + addMemorySize - 1;

        char* pTargetCharData = pTargetString->pCharData;
        char* pAddCharData = pAddString->pCharData;
        char* pNewCharData = (char*)malloc(newMemorySize);

        memcpy(pNewCharData, pTargetCharData, index);
        memcpy(pNewCharData + index, pAddCharData, addMemorySize - 1);
        memcpy(pNewCharData + index + addMemorySize - 1, pTargetCharData + index, targetMemorySize - index);
        free(pTargetCharData);

        pTargetString->pCharData = pNewCharData;
        pTargetString->capacity = newMemorySize;
    }
}

void String_Append(String* pTargetString, String* pAddString)
{
    String_Insert(pTargetString, pAddString, String_GetLength(pTargetString));
}

void String_Delete(String* pString, int startIndex, int endIndex)
{
    if (startIndex >= 0 && endIndex < pString->capacity && startIndex < endIndex)
    {
        int newMemorySize = pString->capacity - endIndex + startIndex;
        char* pNewCharData = (char*)malloc(newMemorySize);

        memcpy(pNewCharData, pString->pCharData, startIndex);
        memcpy(pNewCharData + startIndex, pString->pCharData + endIndex, pString->capacity - endIndex);
        free(pString->pCharData);

        pString->pCharData = pNewCharData;
        pString->capacity = newMemorySize;
    }
}

void String_GetNextList(String* pPatternString, int* pNextList)
{
    pNextList[0] = 0;

    int index = 1;
    int temp = 0;

    while (index < String_GetLength(pPatternString))
    {
        if (String_GetCharAt(pPatternString, temp) == String_GetCharAt(pPatternString, index))
        {
            pNextList[index] = temp + 1;
            temp += 1;
            index += 1;
        }
        else if (temp > 0)
        {
            temp = pNextList[temp - 1];
        }
        else if (temp == 0)
        {
            pNextList[index] = 0;
            index += 1;
        }
    }
}

int String_Find(String* pFullString, String* pPatternString)
{
    int* pNextList = (int*)malloc(sizeof(int) * String_GetLength(pPatternString));

    int fullIndex = 0;
    int patternIndex = 0;
    int findIndex = -1;

    String_GetNextList(pPatternString, pNextList);

    while (fullIndex < String_GetLength(pFullString))
    {
        if (String_GetCharAt(pFullString, fullIndex) == String_GetCharAt(pPatternString, patternIndex))
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
        if (patternIndex == String_GetLength(pPatternString))
        {
            findIndex = fullIndex - patternIndex;
            break;
        }
    }
    free(pNextList);

    return findIndex;
}

char* String_GetData(String* pString)
{
    return pString->pCharData;
}

char String_GetCharAt(String* pString, int index)
{
    return pString->pCharData[index];
}

int String_GetLength(String* pString)
{
    if (pString->capacity > 0)
    {
        return pString->capacity - 1;
    }
    return 0;
}

String String_GetSubString(String* pString, int startIndex, int endIndex)
{
    String subString;

    subString.pCharData = (char*)malloc(endIndex - startIndex + 1);
    subString.pCharData[endIndex - startIndex] = '\0';
    subString.capacity = endIndex - startIndex + 1;
    memcpy(subString.pCharData, pString->pCharData + startIndex, endIndex - startIndex);
    
    return subString;
}
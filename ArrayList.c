#include "ArrayList.h"

void ArrayList_Init(ArrayList* pArrayList, int capacity)
{
    pArrayList->pElementList = (ElementType*)malloc(sizeof(ElementType) * capacity);
    pArrayList->capacity = capacity;
    pArrayList->elementCount = 0;
}

void ArrayList_Destroy(ArrayList* pArrayList)
{
    free(pArrayList->pElementList);
    pArrayList->pElementList = NULL;
    pArrayList->capacity = 0;
    pArrayList->elementCount = 0;
}

void ArrayList_Clear(ArrayList* pArrayList)
{
    pArrayList->elementCount = 0;
}

void ArrayList_Extend(ArrayList* pArrayList)
{
    ElementType* pNewElementList = (ElementType*)malloc(sizeof(ElementType) * pArrayList->capacity * 2);
    
    memcpy(pNewElementList, pArrayList->pElementList, sizeof(ElementType) * pArrayList->elementCount);
    free(pArrayList->pElementList);
    pArrayList->pElementList = pNewElementList;
    pArrayList->capacity *= 2;
}

void ArrayList_Insert(ArrayList* pArrayList, int index, ElementType element)
{
    ElementType* pElementList = pArrayList->pElementList;

    if (pArrayList->elementCount >= pArrayList->capacity)
    {
        ArrayList_Extend(pArrayList);
    }
    memcpy(pElementList + index + 1, pElementList + index, sizeof(ElementType) * (pArrayList->elementCount - index));
    pArrayList->pElementList[index] = element;
    pArrayList->elementCount += 1;
}

void ArrayList_PushBack(ArrayList* pArrayList, ElementType element)
{
    ArrayList_Insert(pArrayList, pArrayList->elementCount, element);
}

void ArrayList_PushFront(ArrayList* pArrayList, ElementType element)
{
    ArrayList_Insert(pArrayList, 0, element);
}

void ArrayList_Delete(ArrayList* pArrayList, int index)
{
    ElementType* pElementList = pArrayList->pElementList;

    memcpy(pElementList + index, pElementList + index + 1, sizeof(ElementType) * (pArrayList->elementCount - index - 1));
    pArrayList->elementCount -= 1;
}

void ArrayList_PopBack(ArrayList* pArrayList)
{
    ArrayList_Delete(pArrayList, pArrayList->elementCount - 1);
}

void ArrayList_PopFront(ArrayList* pArrayList)
{
    ArrayList_Delete(pArrayList, 0);
}

ElementType ArrayList_GetElement(ArrayList* pArrayList, int index)
{
    return pArrayList->pElementList[index];
}

bool ArrayList_IsEmpty(ArrayList* pArrayList)
{
    return pArrayList->elementCount == 0;
}

int ArrayList_GetElementCount(ArrayList* pArrayList)
{
    return pArrayList->elementCount;
}

int ArrayList_GetCapacity(ArrayList* pArrayList)
{
    return pArrayList->capacity;
}
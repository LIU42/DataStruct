#include "ArrayList.h"

ArrayList* ArrayList_Create(int capacity)
{
    ArrayList* pArrayList = (ArrayList*)malloc(sizeof(ArrayList));
    pArrayList->capacity = capacity;
    pArrayList->elementCount = 0;
    pArrayList->pElementList = (ElementType*)malloc(sizeof(ElementType) * capacity);
    return pArrayList;
}

void ArrayList_Destroy(ArrayList* pArrayList)
{
    free(pArrayList->pElementList);
    free(pArrayList);
    pArrayList = NULL;
}

bool ArrayList_IsEmpty(ArrayList* pArrayList)
{
    return pArrayList->elementCount == 0;
}

void ArrayList_Clear(ArrayList* pArrayList)
{
    pArrayList->elementCount = 0;
}

void ArrayList_CapacityGrowth(ArrayList* pArrayList)
{
    if (pArrayList->elementCount >= pArrayList->capacity)
    {
        pArrayList->capacity *= 2;
        pArrayList->pElementList = (ElementType*)realloc(pArrayList->pElementList, sizeof(ElementType) * pArrayList->capacity);
    }
}

void ArrayList_Insert(ArrayList* pArrayList, int index, ElementType element)
{
    ArrayList_CapacityGrowth(pArrayList);
    memcpy(pArrayList->pElementList + index + 1, pArrayList->pElementList + index, pArrayList->elementCount - index);
    pArrayList->pElementList[index] = element;
    pArrayList->elementCount += 1;
}

void ArrayList_PushBack(ArrayList* pArrayList, ElementType element)
{
    ArrayList_CapacityGrowth(pArrayList);
    pArrayList->pElementList[pArrayList->elementCount] = element;
    pArrayList->elementCount += 1;
}

void ArrayList_PushFront(ArrayList* pArrayList, ElementType element)
{
    ArrayList_Insert(pArrayList, 0, element);
}

void ArrayList_Delete(ArrayList* pArrayList, int index)
{
    memcpy(pArrayList->pElementList + index, pArrayList->pElementList + index + 1, pArrayList->elementCount - index - 1);
    pArrayList->elementCount -= 1;
}

void ArrayList_PopBack(ArrayList* pArrayList)
{
    if (pArrayList->elementCount > 0)
    {
        pArrayList->elementCount -= 1;
    }
}

void ArrayList_PopFront(ArrayList* pArrayList)
{
    if (pArrayList->elementCount > 0)
    {
        ArrayList_Delete(pArrayList, 0);
    }
}

void ArrayList_AdjustCapacity(ArrayList* pArrayList, int capacity)
{
    if (capacity < pArrayList->elementCount)
    {
        capacity = pArrayList->elementCount;
    }
    pArrayList->pElementList = (ElementType*)realloc(pArrayList->pElementList, sizeof(ElementType) * capacity);
    pArrayList->capacity = capacity;
}

ElementType ArrayList_GetElement(ArrayList* pArrayList, int index)
{
    return pArrayList->pElementList[index];
}

int ArrayList_GetElementCount(ArrayList* pArrayList)
{
    return pArrayList->elementCount;
}

int ArrayList_GetCapacity(ArrayList* pArrayList)
{
    return pArrayList->capacity;
}
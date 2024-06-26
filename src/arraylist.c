#include "arraylist.h"

ArrayList* ArrayList_Create(int capacity)
{
    ArrayList* pArrayList = (ArrayList*)malloc(sizeof(ArrayList));

    pArrayList->capacity = capacity;
    pArrayList->elementCount = 0;
    pArrayList->pElementList = (ElementType*)malloc(sizeof(ElementType) * capacity);

    return pArrayList;
}

ArrayList* ArrayList_Copy(ArrayList* pArrayList)
{
    ArrayList* pNewArrayList = (ArrayList*)malloc(sizeof(ArrayList));

    pNewArrayList->pElementList = (ElementType*)malloc(sizeof(ElementType) * pArrayList->capacity);
    pNewArrayList->capacity = pArrayList->capacity;
    pNewArrayList->elementCount = pArrayList->elementCount;

    memcpy(pNewArrayList->pElementList, pArrayList->pElementList, sizeof(ElementType) * pArrayList->elementCount);
    return pNewArrayList;
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
        pArrayList->capacity <<= 1;
        pArrayList->pElementList = (ElementType*)realloc(pArrayList->pElementList, sizeof(ElementType) * pArrayList->capacity);
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

void ArrayList_Insert(ArrayList* pArrayList, int index, ElementType element)
{
    ArrayList_CapacityGrowth(pArrayList);

    memcpy(pArrayList->pElementList + index + 1, pArrayList->pElementList + index, pArrayList->elementCount - index);
    pArrayList->pElementList[index] = element;
    pArrayList->elementCount += 1;
}

void ArrayList_AddBack(ArrayList* pArrayList, ElementType element)
{
    ArrayList_CapacityGrowth(pArrayList);

    pArrayList->pElementList[pArrayList->elementCount] = element;
    pArrayList->elementCount += 1;
}

void ArrayList_AddFront(ArrayList* pArrayList, ElementType element)
{
    ArrayList_Insert(pArrayList, 0, element);
}

void ArrayList_Remove(ArrayList* pArrayList, int index)
{
    memcpy(pArrayList->pElementList + index, pArrayList->pElementList + index + 1, pArrayList->elementCount - index - 1);
    pArrayList->elementCount -= 1;
}

void ArrayList_RemoveBack(ArrayList* pArrayList)
{
    if (pArrayList->elementCount > 0)
    {
        pArrayList->elementCount -= 1;
    }
}

void ArrayList_RemoveFront(ArrayList* pArrayList)
{
    if (pArrayList->elementCount > 0)
    {
        ArrayList_Remove(pArrayList, 0);
    }
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

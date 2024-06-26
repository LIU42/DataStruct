#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct ArrayList
{
    ElementType* pElementList;
    int capacity;
    int elementCount;
} ArrayList;

ArrayList* ArrayList_Create(int capacity);
ArrayList* ArrayList_Copy(ArrayList* pArrayList);

bool ArrayList_IsEmpty(ArrayList* pArrayList);
void ArrayList_Destroy(ArrayList* pArrayList);
void ArrayList_Clear(ArrayList* pArrayList);
void ArrayList_AdjustCapacity(ArrayList* pArrayList, int capacity);

void ArrayList_Insert(ArrayList* pArrayList, int index, ElementType element);
void ArrayList_AddBack(ArrayList* pArrayList, ElementType element);
void ArrayList_AddFront(ArrayList* pArrayList, ElementType element);

void ArrayList_Remove(ArrayList* pArrayList, int index);
void ArrayList_RemoveBack(ArrayList* pArrayList);
void ArrayList_RemoveFront(ArrayList* pArrayList);

ElementType ArrayList_GetElement(ArrayList* pArrayList, int index);
int ArrayList_GetElementCount(ArrayList* pArrayList);
int ArrayList_GetCapacity(ArrayList* pArrayList);

#endif

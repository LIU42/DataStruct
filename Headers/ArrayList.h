#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include <stdio.h>
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
void ArrayList_Destroy(ArrayList* pArrayList);
bool ArrayList_IsEmpty(ArrayList* pArrayList);
void ArrayList_Clear(ArrayList* pArrayList);
void ArrayList_Insert(ArrayList* pArrayList, int index, ElementType element);
void ArrayList_PushBack(ArrayList* pArrayList, ElementType element);
void ArrayList_PushFront(ArrayList* pArrayList, ElementType element);
void ArrayList_Delete(ArrayList* pArrayList, int index);
void ArrayList_PopBack(ArrayList* pArrayList);
void ArrayList_PopFront(ArrayList* pArrayList);
void ArrayList_AdjustCapacity(ArrayList* pArrayList, int capacity);

ElementType ArrayList_GetElement(ArrayList* pArrayList, int index);
int ArrayList_GetElementCount(ArrayList* pArrayList);
int ArrayList_GetCapacity(ArrayList* pArrayList);

#endif

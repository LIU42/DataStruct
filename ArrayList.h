#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct ArrayList ArrayList;

struct ArrayList
{
    ElementType* pElementList;
    unsigned int capacity;
    unsigned int elementCount;
};

void ArrayList_Init(ArrayList* pArrayList, unsigned int capacity);
void ArrayList_Destroy(ArrayList* pArrayList);
void ArrayList_Clear(ArrayList* pArrayList);
void ArrayList_Insert(ArrayList* pArrayList, unsigned int index, ElementType element);
void ArrayList_PushBack(ArrayList* pArrayList, ElementType element);
void ArrayList_PushFront(ArrayList* pArrayList, ElementType element);
void ArrayList_Delete(ArrayList* pArrayList, unsigned int index);
void ArrayList_PopBack(ArrayList* pArrayList);
void ArrayList_PopFront(ArrayList* pArrayList);

ElementType ArrayList_GetElement(ArrayList* pArrayList, unsigned int index);
bool ArrayList_IsEmpty(ArrayList* pArrayList);
unsigned int ArrayList_GetElementCount(ArrayList* pArrayList);
unsigned int ArrayList_GetCapacity(ArrayList* pArrayList);

#endif
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
    int capacity;
    int elementCount;
};

void ArrayList_Init(ArrayList*, int);
void ArrayList_Destroy(ArrayList*);
void ArrayList_Clear(ArrayList*);
void ArrayList_Insert(ArrayList*, int, ElementType);
void ArrayList_PushBack(ArrayList*, ElementType);
void ArrayList_PushFront(ArrayList*, ElementType);
void ArrayList_Delete(ArrayList*, int);
void ArrayList_PopBack(ArrayList*);
void ArrayList_PopFront(ArrayList*);

ElementType ArrayList_GetElement(ArrayList*, int);
bool ArrayList_IsEmpty(ArrayList*);
int ArrayList_GetElementCount(ArrayList*);
int ArrayList_GetCapacity(ArrayList*);

#endif
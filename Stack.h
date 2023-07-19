#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct Stack Stack;

struct Stack
{
    ElementType* pElementList;
    int capacity;
    int elementCount;
};

void Stack_Init(Stack*, int);
void Stack_Destroy(Stack*);
void Stack_Clear(Stack*);
void Stack_Push(Stack*, ElementType);
void Stack_Pop(Stack*);

ElementType Stack_GetTopElement(Stack*);
bool Stack_IsEmpty(Stack*);
int Stack_GetElementCount(Stack*);
int Stack_GetCapacity(Stack*);

#endif
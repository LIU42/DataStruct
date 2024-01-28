#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct Stack
{
    ElementType* pElementList;
    int capacity;
    int elementCount;
} Stack;

Stack* Stack_Create(int capacity);
void Stack_Destroy(Stack* pStack);
bool Stack_IsEmpty(Stack* pStack);
void Stack_Clear(Stack* pStack);
void Stack_Push(Stack* pStack, ElementType element);
void Stack_Pop(Stack* pStack);
void Stack_AdjustCapacity(Stack* pStack, int capacity);

ElementType Stack_GetTopElement(Stack* pStack);
int Stack_GetElementCount(Stack* pStack);
int Stack_GetCapacity(Stack* pStack);

#endif
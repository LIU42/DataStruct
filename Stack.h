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
    unsigned int capacity;
    unsigned int elementCount;
};

void Stack_Init(Stack* pStack, unsigned int capacity);
void Stack_Destroy(Stack* pStack);
void Stack_Clear(Stack* pStack);
void Stack_Push(Stack* pStack, ElementType element);
void Stack_Pop(Stack* pStack);

ElementType Stack_GetTopElement(Stack* pStack);
bool Stack_IsEmpty(Stack* pStack);
unsigned int Stack_GetElementCount(Stack* pStack);
unsigned int Stack_GetCapacity(Stack* pStack);

#endif
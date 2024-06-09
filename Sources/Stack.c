#include "Stack.h"

Stack* Stack_Create(int capacity)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack));

    pStack->capacity = capacity;
    pStack->elementCount = 0;
    pStack->pElementList = (ElementType*)malloc(sizeof(ElementType) * capacity);

    return pStack;
}

Stack* Stack_Copy(Stack* pStack)
{
    Stack* pNewStack = (Stack*)malloc(sizeof(Stack));

    pNewStack->pElementList = (ElementType*)malloc(sizeof(ElementType) * pStack->capacity);
    pNewStack->capacity = pStack->capacity;
    pNewStack->elementCount = pStack->elementCount;

    memcpy(pNewStack->pElementList, pStack->pElementList, sizeof(ElementType) * pStack->capacity);
    return pNewStack;
}

void Stack_Destroy(Stack* pStack)
{
    free(pStack->pElementList);
    free(pStack);

    pStack = NULL;
}

bool Stack_IsEmpty(Stack* pStack)
{
    return pStack->elementCount == 0;
}

void Stack_Clear(Stack* pStack)
{
    pStack->elementCount = 0;
}

void Stack_Push(Stack* pStack, ElementType element)
{
    if (pStack->elementCount >= pStack->capacity)
    {
        pStack->capacity <<= 1;
        pStack->pElementList = (ElementType*)realloc(pStack->pElementList, sizeof(ElementType) * pStack->capacity);
    }
    pStack->pElementList[pStack->elementCount] = element;
    pStack->elementCount += 1;
}

void Stack_Pop(Stack* pStack)
{
    if (pStack->elementCount > 0)
    {
        pStack->elementCount -= 1;
    }
}

void Stack_AdjustCapacity(Stack* pStack, int capacity)
{
    if (capacity < pStack->elementCount)
    {
        capacity = pStack->elementCount;
    }
    pStack->pElementList = (ElementType*)realloc(pStack->pElementList, sizeof(ElementType) * capacity);
    pStack->capacity = capacity;
}

ElementType Stack_GetTopElement(Stack* pStack)
{
    return pStack->pElementList[pStack->elementCount - 1];
}

int Stack_GetElementCount(Stack* pStack)
{
    return pStack->elementCount;
}

int Stack_GetCapacity(Stack* pStack)
{
    return pStack->capacity;
}

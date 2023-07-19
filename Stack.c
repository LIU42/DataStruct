#include "Stack.h"

void Stack_Init(Stack* pStack, int capacity)
{
    pStack->pElementList = (ElementType*)malloc(sizeof(ElementType) * capacity);
    pStack->capacity = capacity;
    pStack->elementCount = 0;
}

void Stack_Destroy(Stack* pStack)
{
    free(pStack->pElementList);
    pStack->pElementList = NULL;
    pStack->capacity = 0;
    pStack->elementCount = 0;
}

void Stack_Clear(Stack* pStack)
{
    pStack->elementCount = 0;
}

void Stack_Extend(Stack* pStack)
{
    ElementType* pElementListNew = (ElementType*)malloc(sizeof(ElementType) * pStack->capacity * 2);
    memcpy(pElementListNew, pStack->pElementList, sizeof(ElementType) * pStack->elementCount);
    free(pStack->pElementList);
    pStack->pElementList = pElementListNew;
    pStack->capacity *= 2;
}

void Stack_Push(Stack* pStack, ElementType element)
{
    if (pStack->elementCount >= pStack->capacity)
    {
        Stack_Extend(pStack);
    }
    pStack->pElementList[pStack->elementCount] = element;
    pStack->elementCount += 1;
}

void Stack_Pop(Stack* pStack)
{
    pStack->elementCount -= 1;
}

ElementType Stack_GetTopElement(Stack* pStack)
{
    if (pStack->elementCount > 0)
    {
        return pStack->pElementList[pStack->elementCount - 1];
    }
    return -1;
}

bool Stack_IsEmpty(Stack* pStack)
{
    return pStack->elementCount == 0;
}

int Stack_GetElementCount(Stack* pStack)
{
    return pStack->elementCount;
}

int Stack_GetCapacity(Stack* pStack)
{
    return pStack->capacity;
}
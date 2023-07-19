#include "Queue.h"

void Queue_Init(Queue* pQueue)
{
    pQueue->pHead = NULL;
    pQueue->pTail = NULL;
    pQueue->elementCount = 0;
}

void Queue_Destroy(Queue* pQueue)
{
    Queue_Clear(pQueue);
}

void Queue_Clear(Queue* pQueue)
{
    if (pQueue->elementCount == 0)
    {
        return;
    }
    else if (pQueue->elementCount == 1)
    {
        free(pQueue->pHead);
    }
    else if (pQueue->elementCount >= 2)
    {
        QueueNode* pCurrentNode = pQueue->pHead;
        QueueNode* pNextNode = pCurrentNode->pNext;

        for (int i = 0; i < pQueue->elementCount - 2; i++)
        {
            free(pCurrentNode);
            pCurrentNode = pNextNode;
            pNextNode = pNextNode->pNext;
        }
        free(pCurrentNode);
        free(pNextNode);
    }
    Queue_Init(pQueue);
}

void Queue_AddFirstNode(Queue* pQueue, ElementType element)
{
    if (pQueue->elementCount == 0)
    {
        pQueue->pHead = (QueueNode*)malloc(sizeof(QueueNode));
        pQueue->pHead->element = element;
        pQueue->pHead->pNext = NULL;
        pQueue->pTail = pQueue->pHead;
        pQueue->elementCount += 1;
    }
}

void Queue_DeleteFirstNode(Queue* pQueue)
{
    if (pQueue->elementCount == 1)
    {
        free(pQueue->pHead);
        Queue_Init(pQueue);
    }
}

void Queue_Enqueue(Queue* pQueue, ElementType element)
{
    if (pQueue->elementCount == 0)
    {
        Queue_AddFirstNode(pQueue, element);
        return;
    }
    QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
    pNewNode->element = element;
    pNewNode->pNext = NULL;
    pQueue->pTail->pNext = pNewNode;
    pQueue->pTail = pNewNode;
    pQueue->elementCount += 1;
}

void Queue_Dequeue(Queue* pQueue)
{
    if (pQueue->elementCount == 1)
    {
        Queue_DeleteFirstNode(pQueue);
        return;
    }
    QueueNode* pNewHead = pQueue->pHead->pNext;
    free(pQueue->pHead);
    pQueue->pHead = pNewHead;
    pQueue->elementCount -= 1;
}

ElementType Queue_GetFrontElement(Queue* pQueue)
{
    if (pQueue->elementCount > 0)
    {
        return pQueue->pHead->element;
    }
    return -1;
}

bool Queue_IsEmpty(Queue* pQueue)
{
    return pQueue->elementCount == 0;
}

int Queue_GetElementCount(Queue* pQueue)
{
    return pQueue->elementCount;
}
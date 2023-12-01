#include "Queue.h"

void Queue_Init(Queue* pQueue)
{
    pQueue->pHead = (QueueNode*)malloc(sizeof(QueueNode));
    pQueue->pHead->pNext = pQueue->pHead;
    pQueue->pHead->pLast = pQueue->pHead;
    pQueue->elementCount = 0;
}

void Queue_Destroy(Queue* pQueue)
{
    if (pQueue->elementCount > 0)
    {
        Queue_Clear(pQueue);
    }
    free(pQueue->pHead);
    pQueue->pHead = NULL;
    pQueue->elementCount = 0;
}

void Queue_Clear(Queue* pQueue)
{
    QueueNode* pCurrentNode = pQueue->pHead->pLast;

    for (int i = 0; i < pQueue->elementCount; i++)
    {
        pCurrentNode = pCurrentNode->pLast;
        free(pCurrentNode->pNext);
    }
    pQueue->pHead->pNext = pQueue->pHead;
    pQueue->pHead->pLast = pQueue->pHead;
    pQueue->elementCount = 0;
}

void Queue_Enqueue(Queue* pQueue, ElementType element)
{
    QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
    QueueNode* pPreNode = pQueue->pHead->pLast;

    pNewNode->element = element;
    pNewNode->pNext = pPreNode->pNext;
    pNewNode->pLast = pPreNode;
    pPreNode->pNext = pNewNode;
    pNewNode->pNext->pLast = pNewNode;
    pQueue->elementCount += 1;
}

void Queue_Dequeue(Queue* pQueue)
{
    QueueNode* pDeleteNode = pQueue->pHead->pNext;

    pDeleteNode->pLast->pNext = pDeleteNode->pNext;
    pDeleteNode->pNext->pLast = pDeleteNode->pLast;
    pQueue->elementCount -= 1;
    free(pDeleteNode);
}

ElementType Queue_GetFrontElement(Queue* pQueue)
{
    return pQueue->pHead->pNext->element;
}

bool Queue_IsEmpty(Queue* pQueue)
{
    return pQueue->elementCount == 0;
}

unsigned int Queue_GetElementCount(Queue* pQueue)
{
    return pQueue->elementCount;
}
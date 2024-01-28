#include "Queue.h"

Queue* Queue_Create()
{
    Queue* pQueue = (Queue*)malloc(sizeof(Queue));
    pQueue->elementCount = 0;
    pQueue->pHead = (QueueNode*)malloc(sizeof(QueueNode));
    pQueue->pHead->pNext = pQueue->pHead;
    return pQueue;
}

void Queue_Destroy(Queue* pQueue)
{
    if (pQueue->elementCount > 0)
    {
        Queue_Clear(pQueue);
    }
    free(pQueue->pHead);
    free(pQueue);
    pQueue = NULL;
}

bool Queue_IsEmpty(Queue* pQueue)
{
    return pQueue->elementCount == 0;
}

void Queue_Clear(Queue* pQueue)
{
    QueueNode* pPreNode = pQueue->pHead;
    QueueNode* pCurNode = pQueue->pHead->pNext;

    while (pCurNode != pQueue->pHead)
    {
        pPreNode = pCurNode;
        pCurNode = pCurNode->pNext;
        free(pPreNode);
    }
    pQueue->pHead->pNext = pQueue->pHead;
    pQueue->elementCount = 0;
}

void Queue_Enqueue(Queue* pQueue, ElementType element)
{
    QueueNode* pEnqueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    pQueue->elementCount += 1;
    pQueue->pHead->element = element;
    pEnqueueNode->pNext = pQueue->pHead->pNext;
    pQueue->pHead->pNext = pEnqueueNode;
    pQueue->pHead = pEnqueueNode;
}

void Queue_Dequeue(Queue* pQueue)
{
    QueueNode* pDequeueNode = pQueue->pHead->pNext;
    pQueue->elementCount -= 1;
    pQueue->pHead->pNext = pDequeueNode->pNext;
    free(pDequeueNode);
}

ElementType Queue_GetFrontElement(Queue* pQueue)
{
    return pQueue->pHead->pNext->element;
}

int Queue_GetElementCount(Queue* pQueue)
{
    return pQueue->elementCount;
}
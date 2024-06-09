#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct QueueNode
{
    ElementType element;
    struct QueueNode* pNext;
} QueueNode;

typedef struct Queue
{
    struct QueueNode* pHead;
    int elementCount;
} Queue;

Queue* Queue_Create();
Queue* Queue_Copy(Queue* pQueue);

void Queue_Destroy(Queue* pQueue);
bool Queue_IsEmpty(Queue* pQueue);
void Queue_Clear(Queue* pQueue);

void Queue_Enqueue(Queue* pQueue, ElementType element);
void Queue_Dequeue(Queue* pQueue);

ElementType Queue_GetFrontElement(Queue* pQueue);
int Queue_GetElementCount(Queue* pQueue);

#endif

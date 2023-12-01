#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct QueueNode QueueNode;
typedef struct Queue Queue;

struct QueueNode
{
    ElementType element;
    QueueNode* pNext;
    QueueNode* pLast;
};

struct Queue
{
    QueueNode* pHead;
    unsigned int elementCount;
};

void Queue_Init(Queue* pQueue);
void Queue_Destroy(Queue* pQueue);
void Queue_Clear(Queue* pQueue);
void Queue_Enqueue(Queue* pQueue, ElementType element);
void Queue_Dequeue(Queue* pQueue);

ElementType Queue_GetFrontElement(Queue* pQueue);
bool Queue_IsEmpty(Queue* pQueue);
unsigned int Queue_GetElementCount(Queue* pQueue);

#endif
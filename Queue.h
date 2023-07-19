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
};

struct Queue
{
    QueueNode* pHead;
    QueueNode* pTail;
    int elementCount;
};

void Queue_Init(Queue*);
void Queue_Destroy(Queue*);
void Queue_Clear(Queue*);
void Queue_Enqueue(Queue*, ElementType);
void Queue_Dequeue(Queue*);

ElementType Queue_GetFrontElement(Queue*);
bool Queue_IsEmpty(Queue*);
int Queue_GetElementCount(Queue*);

#endif
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct LinkedList LinkedList;
typedef struct ListNode ListNode;
typedef struct LinkedListIterator LinkedListIterator;

struct ListNode
{
    ElementType element;
    ListNode* pNext;
    ListNode* pLast;
};

struct LinkedList
{
    ListNode* pHead;
    ListNode* pTail;
    int elementCount;
};

struct LinkedListIterator
{
    LinkedList* pLinkedList;
    ListNode* pCurrentNode;
};

void LinkedList_Init(LinkedList*);
void LinkedList_Destroy(LinkedList*);
void LinkedList_Clear(LinkedList*);
void LinkedList_PushBack(LinkedList*, ElementType);
void LinkedList_PushFront(LinkedList*, ElementType);
void LinkedList_Insert(LinkedListIterator*, ElementType);
void LinkedList_PopBack(LinkedList*);
void LinkedList_PopFront(LinkedList*);
void LinkedList_Delete(LinkedListIterator*);
int LinkedList_GetElementCount(LinkedList*);
LinkedListIterator LinkedList_GetHeadIterator(LinkedList*);
LinkedListIterator LinkedList_GetTailIterator(LinkedList*);

bool LinkedListIterator_IsValid(LinkedListIterator*);
bool LinkedListIterator_IsNull(LinkedListIterator*);
bool LinkedListIterator_IsBelong(LinkedListIterator*, LinkedList*);
bool LinkedListIterator_IsHead(LinkedListIterator*);
bool LinkedListIterator_IsTail(LinkedListIterator*);
void LinkedListIterator_GoNext(LinkedListIterator*);
void LinkedListIterator_GoLast(LinkedListIterator*);
void LinkedListIterator_GoHead(LinkedListIterator*);
void LinkedListIterator_GoTail(LinkedListIterator*);
ElementType LinkedListIterator_GetElement(LinkedListIterator*);

#endif
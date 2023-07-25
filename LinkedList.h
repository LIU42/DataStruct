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
bool LinkedList_IsEmpty(LinkedList*);
int LinkedList_GetElementCount(LinkedList*);
LinkedListIterator LinkedList_GetHeadIterator(LinkedList*);
LinkedListIterator LinkedList_GetTailIterator(LinkedList*);

bool LinkedListIterator_IsBelongTo(LinkedListIterator*, LinkedList*);
bool LinkedListIterator_IsEnd(LinkedListIterator*);
bool LinkedListIterator_IsHead(LinkedListIterator*);
bool LinkedListIterator_IsTail(LinkedListIterator*);
void LinkedListIterator_GoNext(LinkedListIterator*);
void LinkedListIterator_GoLast(LinkedListIterator*);
ElementType LinkedListIterator_GetElement(LinkedListIterator*);

#endif
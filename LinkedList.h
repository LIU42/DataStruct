#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct ListNode ListNode;
typedef struct LinkedList LinkedList;
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
    unsigned int elementCount;
};

struct LinkedListIterator
{
    LinkedList* pLinkedList;
    ListNode* pCurrentNode;
};

void LinkedList_Init(LinkedList* pLinkedList);
void LinkedList_Destroy(LinkedList* pLinkedList);
void LinkedList_Clear(LinkedList* pLinkedList);
void LinkedList_PushBack(LinkedList* pLinkedList, ElementType element);
void LinkedList_PushFront(LinkedList* pLinkedList, ElementType element);
void LinkedList_Insert(LinkedListIterator* pLinkedList, ElementType element);
void LinkedList_PopBack(LinkedList* pLinkedList);
void LinkedList_PopFront(LinkedList* pLinkedList);
void LinkedList_Delete(LinkedListIterator* pIterator);
bool LinkedList_IsEmpty(LinkedList* pLinkedList);
unsigned int LinkedList_GetElementCount(LinkedList* pLinkedList);
LinkedListIterator LinkedList_GetHeadIterator(LinkedList* pLinkedList);
LinkedListIterator LinkedList_GetTailIterator(LinkedList* pLinkedList);

bool LinkedListIterator_IsBelongTo(LinkedListIterator* pIterator, LinkedList* pLinkedList);
bool LinkedListIterator_IsEnd(LinkedListIterator* pIterator);
bool LinkedListIterator_IsHead(LinkedListIterator* pIterator);
bool LinkedListIterator_IsTail(LinkedListIterator* pIterator);
void LinkedListIterator_GoNext(LinkedListIterator* pIterator);
void LinkedListIterator_GoLast(LinkedListIterator* pIterator);
ElementType LinkedListIterator_GetElement(LinkedListIterator* pIterator);

#endif
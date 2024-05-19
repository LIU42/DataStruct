#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef enum LinkedListIteratorType
{
    ITERATOR_FORWARD,
    ITERATOR_BACKWARD
} LinkedListIteratorType;

typedef struct ListNode
{
    ElementType element;
    struct ListNode* pNext;
    struct ListNode* pLast;
} ListNode;

typedef struct LinkedList
{
    struct ListNode* pHead;
    int elementCount;
} LinkedList;

typedef struct LinkedListIterator
{
    enum LinkedListIteratorType iteratorType;
    struct LinkedList* pLinkedList;
    struct ListNode* pCurrentNode;
} LinkedListIterator;

LinkedList* LinkedList_Create();
void LinkedList_Destroy(LinkedList* pLinkedList);
bool LinkedList_IsEmpty(LinkedList* pLinkedList);
void LinkedList_Clear(LinkedList* pLinkedList);
void LinkedList_PushBack(LinkedList* pLinkedList, ElementType element);
void LinkedList_PushFront(LinkedList* pLinkedList, ElementType element);
void LinkedList_Insert(LinkedListIterator* pLinkedList, ElementType element);
void LinkedList_PopBack(LinkedList* pLinkedList);
void LinkedList_PopFront(LinkedList* pLinkedList);
void LinkedList_Delete(LinkedListIterator* pIterator);
int LinkedList_GetElementCount(LinkedList* pLinkedList);
LinkedListIterator LinkedList_GetForwardIterator(LinkedList* pLinkedList);
LinkedListIterator LinkedList_GetBackwardIterator(LinkedList* pLinkedList);

bool LinkedListIterator_IsEnd(LinkedListIterator* pIterator);
void LinkedListIterator_Next(LinkedListIterator* pIterator);
ElementType LinkedListIterator_GetElement(LinkedListIterator* pIterator);

#endif

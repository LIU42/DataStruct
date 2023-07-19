#include "LinkedList.h"

void LinkedList_Init(LinkedList* pLinkedList)
{
    pLinkedList->pHead = NULL;
    pLinkedList->pTail = NULL;
    pLinkedList->elementCount = 0;
}

void LinkedList_Destroy(LinkedList* pLinkedList)
{
    LinkedList_Clear(pLinkedList);
}

void LinkedList_Clear(LinkedList* pLinkedList)
{
    if (pLinkedList->elementCount == 0)
    {
        return;
    }
    else if (pLinkedList->elementCount == 1)
    {
        free(pLinkedList->pHead);
    }
    else if (pLinkedList->elementCount >= 2)
    {
        ListNode* pCurrentNode = pLinkedList->pHead;
        ListNode* pNextNode = pCurrentNode->pNext;

        for (int i = 0; i < pLinkedList->elementCount - 2; i++)
        {
            free(pCurrentNode);
            pCurrentNode = pNextNode;
            pNextNode = pNextNode->pNext;
        }
        free(pCurrentNode);
        free(pNextNode);
    }
    LinkedList_Init(pLinkedList);
}

void LinkList_AddFirstNode(LinkedList* pLinkedList, ElementType element)
{
    if (pLinkedList->elementCount == 0)
    {
        pLinkedList->pHead = (ListNode*)malloc(sizeof(ListNode));
        pLinkedList->pHead->element = element;
        pLinkedList->pHead->pNext = NULL;
        pLinkedList->pHead->pLast = NULL;
        pLinkedList->pTail = pLinkedList->pHead;
        pLinkedList->elementCount += 1;
    }
}

void LinkedList_PushBack(LinkedList* pLinkedList, ElementType element)
{
    if (pLinkedList->elementCount == 0)
    {
        LinkList_AddFirstNode(pLinkedList, element);
        return;
    }
    ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
    pNewNode->element = element;
    pNewNode->pNext = NULL;
    pNewNode->pLast = pLinkedList->pTail;
    pLinkedList->pTail->pNext = pNewNode;
    pLinkedList->pTail = pNewNode;
    pLinkedList->elementCount += 1;
}

void LinkedList_PushFront(LinkedList* pLinkedList, ElementType element)
{
    if (pLinkedList->elementCount == 0)
    {
        LinkList_AddFirstNode(pLinkedList, element);
        return;
    }
    ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
    pNewNode->element = element;
    pNewNode->pNext = pLinkedList->pHead;
    pNewNode->pLast = NULL;
    pLinkedList->pHead->pLast = pNewNode;
    pLinkedList->pHead = pNewNode;
    pLinkedList->elementCount += 1;
}

void LinkedList_Insert(LinkedListIterator* pIterator, ElementType element)
{
    if (!LinkedListIterator_IsValid(pIterator) || LinkedListIterator_IsNull(pIterator))
    {
        return;
    }
    if (LinkedListIterator_IsHead(pIterator))
    {
        LinkedList_PushFront(pIterator->pLinkedList, element);
        return;
    }
    ListNode* pCurrentNode = pIterator->pCurrentNode;
    ListNode* pLastNode = pCurrentNode->pLast;
    ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
    pNewNode->element = element;
    pNewNode->pNext = pCurrentNode;
    pNewNode->pLast = pLastNode;
    pCurrentNode->pLast = pNewNode;
    pLastNode->pNext = pNewNode;
    pIterator->pLinkedList->elementCount += 1;
}

void LinkList_DeleteFirstNode(LinkedList* pLinkedList)
{
    if (pLinkedList->elementCount == 1)
    {
        free(pLinkedList->pHead);
        LinkedList_Init(pLinkedList);
    }
}

void LinkedList_PopBack(LinkedList* pLinkedList)
{
    if (pLinkedList->elementCount == 1)
    {
        LinkList_DeleteFirstNode(pLinkedList);
        return;
    }
    pLinkedList->pTail = pLinkedList->pTail->pLast;
    free(pLinkedList->pTail->pNext);
    pLinkedList->pTail->pNext = NULL;
    pLinkedList->elementCount -= 1;
}

void LinkedList_PopFront(LinkedList* pLinkedList)
{
    if (pLinkedList->elementCount == 1)
    {
        LinkList_DeleteFirstNode(pLinkedList);
        return;
    }
    pLinkedList->pHead = pLinkedList->pHead->pNext;
    free(pLinkedList->pHead->pLast);
    pLinkedList->pHead->pLast = NULL;
    pLinkedList->elementCount -= 1;
}

void LinkedList_Delete(LinkedListIterator* pIterator)
{
    if (!LinkedListIterator_IsValid(pIterator) || LinkedListIterator_IsNull(pIterator))
    {
        return;
    }
    if (LinkedListIterator_IsHead(pIterator))
    {
        LinkedListIterator_GoNext(pIterator);
        LinkedList_PopFront(pIterator->pLinkedList);
        return;
    }
    if (LinkedListIterator_IsTail(pIterator))
    {
        LinkedListIterator_GoNext(pIterator);
        LinkedList_PopBack(pIterator->pLinkedList);
        return;
    }
    ListNode* pCurrentNode = pIterator->pCurrentNode;
    ListNode* pNextNode = pCurrentNode->pNext;
    ListNode* pLastNode = pCurrentNode->pLast;
    LinkedListIterator_GoNext(pIterator);
    free(pCurrentNode);
    pLastNode->pNext = pNextNode;
    pNextNode->pLast = pLastNode;
    pIterator->pLinkedList->elementCount -= 1;
}

int LinkedList_GetElementCount(LinkedList* pLinkedList)
{
    return pLinkedList->elementCount;
}

LinkedListIterator LinkedList_GetHeadIterator(LinkedList* pLinkedList)
{
    LinkedListIterator iterator;

    iterator.pLinkedList = pLinkedList;
    iterator.pCurrentNode = pLinkedList->pHead;

    return iterator;
}

LinkedListIterator LinkedList_GetTailIterator(LinkedList* pLinkedList)
{
    LinkedListIterator iterator;

    iterator.pLinkedList = pLinkedList;
    iterator.pCurrentNode = pLinkedList->pTail;

    return iterator;
}

bool LinkedListIterator_IsValid(LinkedListIterator* pIterator)
{
    return pIterator->pLinkedList != NULL;
}

bool LinkedListIterator_IsNull(LinkedListIterator* pIterator)
{
    return pIterator->pCurrentNode == NULL;
}

bool LinkedListIterator_IsBelong(LinkedListIterator* pIterator, LinkedList* pLinkedList)
{
    return pIterator->pLinkedList == pLinkedList;
}

bool LinkedListIterator_IsHead(LinkedListIterator* pIterator)
{
    if (!LinkedListIterator_IsValid(pIterator))
    {
        return false;
    }
    return pIterator->pCurrentNode == pIterator->pLinkedList->pHead;
}

bool LinkedListIterator_IsTail(LinkedListIterator* pIterator)
{
    if (!LinkedListIterator_IsValid(pIterator))
    {
        return false;
    }
    return pIterator->pCurrentNode == pIterator->pLinkedList->pTail;
}

void LinkedListIterator_GoNext(LinkedListIterator* pIterator)
{
    if (LinkedListIterator_IsValid(pIterator) && !LinkedListIterator_IsNull(pIterator))
    {
        pIterator->pCurrentNode = pIterator->pCurrentNode->pNext;
    }
}

void LinkedListIterator_GoLast(LinkedListIterator* pIterator)
{
    if (LinkedListIterator_IsValid(pIterator) && !LinkedListIterator_IsNull(pIterator))
    {
        pIterator->pCurrentNode = pIterator->pCurrentNode->pLast;
    }
}

void LinkedListIterator_GoHead(LinkedListIterator* pIterator)
{
    if (LinkedListIterator_IsValid(pIterator))
    {
        pIterator->pCurrentNode = pIterator->pLinkedList->pHead;
    }
}

void LinkedListIterator_GoTail(LinkedListIterator* pIterator)
{
    if (LinkedListIterator_IsValid(pIterator))
    {
        pIterator->pCurrentNode = pIterator->pLinkedList->pTail;
    }
}

ElementType LinkedListIterator_GetElement(LinkedListIterator* pIterator)
{
    if (!LinkedListIterator_IsValid(pIterator))
    {
        return -1;
    }
    return pIterator->pCurrentNode->element;
}
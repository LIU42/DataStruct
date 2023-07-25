#include "LinkedList.h"

void LinkedList_Init(LinkedList* pLinkedList)
{
    pLinkedList->pHead = (ListNode*)malloc(sizeof(LinkedList));
    pLinkedList->pHead->pNext = pLinkedList->pHead;
    pLinkedList->pHead->pLast = pLinkedList->pHead;
    pLinkedList->elementCount = 0;
}

void LinkedList_Destroy(LinkedList* pLinkedList)
{
    if (pLinkedList->elementCount > 0)
    {
        LinkedList_Clear(pLinkedList);
    }
    free(pLinkedList->pHead);
    pLinkedList->pHead = NULL;
    pLinkedList->elementCount = 0;
}

void LinkedList_Clear(LinkedList* pLinkedList)
{
    ListNode* pCurrentNode = pLinkedList->pHead->pLast;

    for (int i = 0; i < pLinkedList->elementCount; i++)
    {
        pCurrentNode = pCurrentNode->pLast;
        free(pCurrentNode->pNext);
    }
    pLinkedList->pHead->pNext = pLinkedList->pHead;
    pLinkedList->pHead->pLast = pLinkedList->pHead;
    pLinkedList->elementCount = 0;
}

void LinkedList_SetNewNode(LinkedList* pLinkedList, ListNode* pNewNode, ListNode* pPreNode, ElementType element)
{
    pNewNode->element = element;
    pNewNode->pNext = pPreNode->pNext;
    pNewNode->pLast = pPreNode;
    pPreNode->pNext = pNewNode;
    pNewNode->pNext->pLast = pNewNode;
}

void LinkedList_PushBack(LinkedList* pLinkedList, ElementType element)
{
    LinkedList_SetNewNode(pLinkedList, (ListNode*)malloc(sizeof(ListNode)), pLinkedList->pHead->pLast, element);
}

void LinkedList_PushFront(LinkedList* pLinkedList, ElementType element)
{
    LinkedList_SetNewNode(pLinkedList, (ListNode*)malloc(sizeof(ListNode)), pLinkedList->pHead, element);
}

void LinkedList_Insert(LinkedListIterator* pIterator, ElementType element)
{
    ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
    ListNode* pPreNode = pIterator->pCurrentNode->pLast;

    LinkedList_SetNewNode(pIterator->pLinkedList, pNewNode, pPreNode, element);
    pIterator->pCurrentNode = pNewNode;
}

void LinkedList_DeleteNode(LinkedList* pLinkedList, ListNode* pDeleteNode)
{
    pDeleteNode->pLast->pNext = pDeleteNode->pNext;
    pDeleteNode->pNext->pLast = pDeleteNode->pLast;
    free(pDeleteNode);
}

void LinkedList_PopBack(LinkedList* pLinkedList)
{
    LinkedList_DeleteNode(pLinkedList, pLinkedList->pHead->pLast);
}

void LinkedList_PopFront(LinkedList* pLinkedList)
{
    LinkedList_DeleteNode(pLinkedList, pLinkedList->pHead->pNext);
}

void LinkedList_Delete(LinkedListIterator* pIterator)
{
    ListNode* pNextNode = pIterator->pCurrentNode->pNext;

    LinkedList_DeleteNode(pIterator->pLinkedList, pIterator->pCurrentNode);
    pIterator->pCurrentNode = pNextNode;
}

bool LinkedList_IsEmpty(LinkedList* pLinkedList)
{
    return pLinkedList->elementCount == 0;
}

int LinkedList_GetElementCount(LinkedList* pLinkedList)
{
    return pLinkedList->elementCount;
}

LinkedListIterator LinkedList_GetHeadIterator(LinkedList* pLinkedList)
{
    LinkedListIterator iterator;

    iterator.pLinkedList = pLinkedList;
    iterator.pCurrentNode = pLinkedList->pHead->pNext;

    return iterator;
}

LinkedListIterator LinkedList_GetTailIterator(LinkedList* pLinkedList)
{
    LinkedListIterator iterator;

    iterator.pLinkedList = pLinkedList;
    iterator.pCurrentNode = pLinkedList->pHead->pLast;

    return iterator;
}
bool LinkedListIterator_IsBelongTo(LinkedListIterator* pIterator, LinkedList* pLinkedList)
{
    return pIterator->pLinkedList == pLinkedList;
}

bool LinkedListIterator_IsEnd(LinkedListIterator* pIterator)
{
    return pIterator->pCurrentNode == pIterator->pLinkedList->pHead;
}

bool LinkedListIterator_IsHead(LinkedListIterator* pIterator)
{
    if (LinkedList_IsEmpty(pIterator->pLinkedList))
    {
        return false;
    }
    return pIterator->pCurrentNode == pIterator->pLinkedList->pHead->pNext;
}

bool LinkedListIterator_IsTail(LinkedListIterator* pIterator)
{
    if (LinkedList_IsEmpty(pIterator->pLinkedList))
    {
        return false;
    }
    return pIterator->pCurrentNode == pIterator->pLinkedList->pHead->pLast;
}

void LinkedListIterator_GoNext(LinkedListIterator* pIterator)
{
    pIterator->pCurrentNode = pIterator->pCurrentNode->pNext;
}

void LinkedListIterator_GoLast(LinkedListIterator* pIterator)
{
    pIterator->pCurrentNode = pIterator->pCurrentNode->pLast;
}

ElementType LinkedListIterator_GetElement(LinkedListIterator* pIterator)
{
    return pIterator->pCurrentNode->element;
}
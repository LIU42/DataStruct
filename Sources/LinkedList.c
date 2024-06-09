#include "LinkedList.h"

LinkedList* LinkedList_Create()
{
    LinkedList* pLinkedList = (LinkedList*)malloc(sizeof(LinkedList));

    pLinkedList->elementCount = 0;
    pLinkedList->pHead = (ListNode*)malloc(sizeof(ListNode));
    pLinkedList->pHead->pNext = pLinkedList->pHead;
    pLinkedList->pHead->pLast = pLinkedList->pHead;

    return pLinkedList;
}

LinkedList* LinkedList_Copy(LinkedList* pLinkedList)
{  
    LinkedList* pNewLinkedList = LinkedList_Create();

    for (ListNode* pCurNode = pLinkedList->pHead->pNext; pCurNode != pLinkedList->pHead; pCurNode = pCurNode->pNext)
    {
        LinkedList_AddBack(pNewLinkedList, pCurNode->element);
    }
    return pNewLinkedList;
}

void LinkedList_Destroy(LinkedList* pLinkedList)
{
    if (pLinkedList->elementCount > 0)
    {
        LinkedList_Clear(pLinkedList);
    }
    free(pLinkedList->pHead);
    free(pLinkedList);

    pLinkedList = NULL;
}

bool LinkedList_IsEmpty(LinkedList* pLinkedList)
{
    return pLinkedList->elementCount == 0;
}

void LinkedList_Clear(LinkedList* pLinkedList)
{
    for (ListNode* pCurrentNode = pLinkedList->pHead->pLast; pCurrentNode != pLinkedList->pHead; free(pCurrentNode->pNext))
    {
        pCurrentNode = pCurrentNode->pLast;
    }
    pLinkedList->pHead->pNext = pLinkedList->pHead;
    pLinkedList->pHead->pLast = pLinkedList->pHead;
    pLinkedList->elementCount = 0;
}

void LinkedList_AddNode(LinkedList* pLinkedList, ListNode* pPreNode, ElementType element)
{
    ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
    
    pNewNode->element = element;
    pNewNode->pNext = pPreNode->pNext;
    pNewNode->pLast = pPreNode;
    pPreNode->pNext = pNewNode;
    pNewNode->pNext->pLast = pNewNode;
    pLinkedList->elementCount += 1;
}

void LinkedList_AddBack(LinkedList* pLinkedList, ElementType element)
{
    LinkedList_AddNode(pLinkedList, pLinkedList->pHead->pLast, element);
}

void LinkedList_AddFront(LinkedList* pLinkedList, ElementType element)
{
    LinkedList_AddNode(pLinkedList, pLinkedList->pHead, element);
}

void LinkedList_Insert(LinkedListIterator* pIterator, ElementType element)
{
    LinkedList_AddNode(pIterator->pLinkedList, pIterator->pCurrentNode->pLast, element);
    pIterator->pCurrentNode = pIterator->pCurrentNode->pLast;
}

void LinkedList_DeleteNode(LinkedList* pLinkedList, ListNode* pDeleteNode)
{
    pDeleteNode->pLast->pNext = pDeleteNode->pNext;
    pDeleteNode->pNext->pLast = pDeleteNode->pLast;
    pLinkedList->elementCount -= 1;
    free(pDeleteNode);
}

void LinkedList_RemoveBack(LinkedList* pLinkedList)
{
    LinkedList_DeleteNode(pLinkedList, pLinkedList->pHead->pLast);
}

void LinkedList_RemoveFront(LinkedList* pLinkedList)
{
    LinkedList_DeleteNode(pLinkedList, pLinkedList->pHead->pNext);
}

void LinkedList_Remove(LinkedListIterator* pIterator)
{
    pIterator->pCurrentNode = pIterator->pCurrentNode->pNext;
    LinkedList_DeleteNode(pIterator->pLinkedList, pIterator->pCurrentNode->pLast);
}

int LinkedList_GetElementCount(LinkedList* pLinkedList)
{
    return pLinkedList->elementCount;
}

LinkedListIterator LinkedList_GetForwardIterator(LinkedList* pLinkedList)
{
    LinkedListIterator iterator = { ITERATOR_FORWARD, pLinkedList, pLinkedList->pHead->pNext };
    return iterator;
}

LinkedListIterator LinkedList_GetBackwardIterator(LinkedList* pLinkedList)
{
    LinkedListIterator iterator = { ITERATOR_BACKWARD, pLinkedList, pLinkedList->pHead->pLast };
    return iterator;
}

bool LinkedListIterator_IsEnd(LinkedListIterator* pIterator)
{
    return pIterator->pCurrentNode == pIterator->pLinkedList->pHead;
}

void LinkedListIterator_Next(LinkedListIterator* pIterator)
{
    switch (pIterator->iteratorType)
    {
        case ITERATOR_FORWARD: pIterator->pCurrentNode = pIterator->pCurrentNode->pNext; break;
        case ITERATOR_BACKWARD: pIterator->pCurrentNode = pIterator->pCurrentNode->pLast; break;
    }
}

ElementType LinkedListIterator_GetElement(LinkedListIterator* pIterator)
{
    return pIterator->pCurrentNode->element;
}

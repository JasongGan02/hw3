#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    Node* smallerTail = nullptr; 
    Node* largerTail = nullptr;
    smaller = larger = nullptr;
    llpivotHelper(head, smaller, larger, smallerTail, largerTail, pivot);
    head = nullptr;

}

void llpivotHelper(Node *&current, Node *&smaller, Node *&larger, Node *&smallerTail, Node *&largerTail, int pivot)
{
    if (current = nullptr)
    {
        if (smallerTail != nullptr) smallerTail->next = nullptr;
        if (largerTail != nullptr) largerTail->next = nullptr;
        return;
    }

    Node* next = current->next;
    if (current->val <= pivot)
    {
        if (smaller == nullptr)
        {
            smaller = smallerTail = current;
        }
        else
        {
            smallerTail->next = current;
            smallerTail = current;
        }
    }
    else
    {
        if (larger == nullptr)
        {
            larger = largerTail = current;
        }
        else
        {
            largerTail->next = current;
            largerTail = current;
        }
    }
    
    llpivotHelper(next, smaller, larger, smallerTail, largerTail, pivot);

}
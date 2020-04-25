#ifndef LISTDECLARATIONS_H
#define LISTDECLARATIONS_H

struct Node
{
    int   mData;
    Node* mNext;
};

void InsertValAtEnd(int data);
void InsertValAtBeginning(int data);

void printList(Node* head);

void DeleteAll(Node* head);

#endif // LISTDECLARATIONS_H

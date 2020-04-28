#ifndef LISTDECLARATIONS_H
#define LISTDECLARATIONS_H

struct Node
{
    int   mData;
    Node* mNext;
};

void InsertValAtEnd(int data);
void InsertValAtBeginning(int data);
void InserAtGivenIndex(int data,int pos);

void printList();
void printListInReverse(Node* node);

void DeleteAll();
void DeleteAtGivenIndex(int pos);

void reverseList();

#endif // LISTDECLARATIONS_H

#ifndef LISTDECLARATIONS_H
#define LISTDECLARATIONS_H

struct Node
{
    int   mData;
    Node* mPrev;
    Node* mNext;
};

Node* createNode(int data);

void InsertValAtEnd(int data);
void InsertValAtBeginning(int data);
void InserAtGivenIndex(int data,int pos);

void printList();
void printListRecursive(Node* node, bool forword = true);

void DeleteAll();
void DeleteAtGivenIndex(int pos);

void reverseList();
void reverseListRecursive(Node* curr);

#endif // LISTDECLARATIONS_H

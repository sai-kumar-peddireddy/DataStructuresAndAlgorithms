#ifndef TREEDECLARATIONS_H
#define TREEDECLARATIONS_H

struct BstNode
{
    int   mData;
    BstNode* mLeft;
    BstNode* mRight;
};

BstNode* createNode(int data);


#endif // TREEDECLARATIONS_H

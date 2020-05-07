#ifndef TREEDECLARATIONS_H
#define TREEDECLARATIONS_H

struct BstNode
{
    int   mData;
    BstNode* mLeft;
    BstNode* mRight;
};

BstNode* createBstNode(int data);

BstNode* insertBstNodeRecursive(BstNode* root, int data);

bool serachBstRecursive(BstNode* root, int data);


#endif // TREEDECLARATIONS_H

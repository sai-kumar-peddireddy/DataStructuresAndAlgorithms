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
BstNode* insertBstNode(BstNode* root, int data);

bool serachBstRecursive(BstNode* root, int data);
bool serachBst(BstNode* root, int data);

int findMin(BstNode* root);
int findMax(BstNode* root);


#endif // TREEDECLARATIONS_H

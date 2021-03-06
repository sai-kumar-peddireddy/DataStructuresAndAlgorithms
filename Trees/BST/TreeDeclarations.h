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
int findMinRecursive(BstNode* root);

int findMax(BstNode* root);
int findMaxRecursive(BstNode* root);

int heightOfBst(BstNode* root);

void breadthFirst(BstNode* root);

void preOrder(BstNode* root);
void inOrder(BstNode* root);
void postOrder(BstNode* root);

#endif // TREEDECLARATIONS_H

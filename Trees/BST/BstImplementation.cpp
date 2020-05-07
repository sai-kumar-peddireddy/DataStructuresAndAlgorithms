#include <iostream>

#include "TreeDeclarations.h"

using namespace std;

int main()
{
    BstNode* root  = nullptr;
    root = insertBstNodeRecursive(root, 10);
    root = insertBstNodeRecursive(root, 7);
    root = insertBstNodeRecursive(root, 15);
    root = insertBstNodeRecursive(root, 14);
    root = insertBstNodeRecursive(root, 16);

    if(serachBstRecursive(root, 14))
        cout<<"14 is found"<<'\n';

    if(serachBstRecursive(root, 16))
        cout<<"16 is found"<<'\n';

    if(serachBstRecursive(root, 10))
        cout<<"10 is found"<<'\n';

    if(!serachBstRecursive(root, 13))
        cout<<"13 is not found"<<'\n';

    return 0;
}

BstNode* createBstNode(int data)
{
    auto new_element = new BstNode();
    new_element->mData = data;
    new_element->mLeft = nullptr;
    new_element->mRight = nullptr;

    return new_element;
}

BstNode* insertBstNodeRecursive(BstNode* root, int data)
{
    if(!root)
    {
        return createBstNode(data);
    }

    if(root->mData >= data)
    {
        root->mLeft = insertBstNodeRecursive(root->mLeft, data);
    }
    else if(root->mData < data)
    {
        root->mRight = insertBstNodeRecursive(root->mRight, data);
    }

    return root;
}

bool serachBstRecursive(BstNode* root, int data)
{
    if(!root)
        return false;
    if(root->mData == data)
        return true;

    if(root->mData >= data)
        return serachBstRecursive(root->mLeft, data);

    if(root->mData < data)
        return serachBstRecursive(root->mRight, data);

    return false;
}

#include <iostream>

#include "TreeDeclarations.h"

using namespace std;

int main()
{
    BstNode* root  = nullptr;
    root = insertBstNodeRecursive(root, 10);
    root = insertBstNode(root, 7);
    root = insertBstNodeRecursive(root, 15);
    root = insertBstNode(root, 14);
    root = insertBstNodeRecursive(root, 16);

    if(serachBst(root, 14))
        cout<<"14 is found"<<'\n';

    if(serachBstRecursive(root, 16))
        cout<<"16 is found"<<'\n';

    if(serachBstRecursive(root, 10))
        cout<<"10 is found"<<'\n';

    if(!serachBst(root, 13))
        cout<<"13 is not found"<<'\n';

    cout<<"Min in tree: "<<findMin(root)<<'\n';
    cout<<"Max in tree: "<<findMax(root)<<'\n';

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

BstNode* insertBstNode(BstNode* root, int data)
{
    auto temp_itr = root;

    if(!temp_itr)
        return temp_itr = createBstNode(data);

    while (temp_itr != nullptr)
    {
        if(temp_itr->mData >= data)
        {
            if(!temp_itr->mLeft)
            {
                temp_itr->mLeft = createBstNode(data);
                return root;
            }
            temp_itr = temp_itr->mLeft;
        }
        else
        {
            if(!temp_itr->mRight)
            {
                temp_itr->mRight = createBstNode(data);
                return root;
            }
            temp_itr = temp_itr->mRight;
        }
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

bool serachBst(BstNode* root, int data)
{
    auto temp_itr = root;

    if(!temp_itr)
        return false;

    while (temp_itr != nullptr)
    {
        if(temp_itr->mData >= data)
            temp_itr = temp_itr->mLeft;
        else
            temp_itr = temp_itr->mRight;

        if(temp_itr && temp_itr->mData == data)
          return true;
    }
    return false;
}

int findMin(BstNode* root)
{
    if(!root)
    {
        cout<<'\n'<<"tree is empty"<<'\n';
        return -1;
    }

    while (root->mLeft != nullptr)
    {
        root = root->mLeft;
    }
    return root->mData;
}

int findMax(BstNode* root)
{
    if(!root)
    {
        cout<<'\n'<<"tree is empty"<<'\n';
        return -1;
    }

    while (root->mRight != nullptr)
    {
        root = root->mRight;
    }
    return root->mData;
}


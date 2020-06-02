#include <iostream>
#include <algorithm>
#include <queue>

#include "TreeDeclarations.h"

using namespace std;

int main()
{
    BstNode* root  = nullptr;
    root = insertBstNodeRecursive(root, 10);
    root = insertBstNode(root, 7);
    root = insertBstNodeRecursive(root, 15);
    root = insertBstNode(root, 14);
    root = insertBstNode(root, 13);
    root = insertBstNodeRecursive(root, 16);

    if(serachBst(root, 14))
        cout<<"14 is found"<<'\n';

    if(serachBstRecursive(root, 16))
        cout<<"16 is found"<<'\n';

    if(serachBstRecursive(root, 10))
        cout<<"10 is found"<<'\n';

    if(!serachBst(root, 13))
        cout<<"13 is not found"<<'\n';

    cout<<"height of a tree is: "<<heightOfBst(root)<<'\n';

    cout<<"Min in tree: "<<findMin(root)<<'\n';
    cout<<"Max in tree: "<<findMax(root)<<'\n';

    cout<<"Recursive calls: " <<'\n';
    cout<<"Min in tree: "<<findMinRecursive(root)<<'\n';
    cout<<"Max in tree: "<<findMaxRecursive(root)<<'\n';

    breadthFirst(root);

    cout<<'\n'<<"pre Order: "<<'\n';
    preOrder(root);

    cout<<'\n'<<"In Order: "<<'\n';
    inOrder(root);

    cout<<'\n'<<"post Order: "<<'\n';
    postOrder(root);

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

int findMinRecursive(BstNode* root)
{
    if(!root)
    {
        cout<<'\n'<<"tree is empty"<<'\n';
        return -1;
    }

    if(!root->mLeft)
    {
        return root->mData;
    }

    return findMinRecursive(root->mLeft);
}

int findMaxRecursive(BstNode* root)
{
    if(!root)
    {
        cout<<'\n'<<"tree is empty"<<'\n';
        return -1;
    }

    if(!root->mRight)
    {
        return root->mData;
    }
    return findMaxRecursive(root->mRight);
}

int heightOfBst(BstNode* root)
{
    if(!root)
        return  -1;

    const auto h_left  = heightOfBst(root->mLeft);
    const auto h_right = heightOfBst(root->mRight);

    return max(h_left, h_right) + 1;
}

void breadthFirst(BstNode* root)
{
    if(!root)
        return ;

    cout<<"\nBreadth First:"<<'\n';

    queue<BstNode*> node_q;
    node_q.push(root);

    while (!node_q.empty())
    {
        const auto& current = node_q.front();

        cout<<current->mData <<'\t'; //processing the data

        if(current->mLeft)
            node_q.push(current->mLeft);

        if(current->mRight)
            node_q.push(current->mRight);

        node_q.pop();
    }
    cout<<'\n';
}

void preOrder(BstNode* root)
{
    if(!root)
        return ;

    cout <<root->mData <<'\t';
    preOrder(root->mLeft);
    preOrder(root->mRight);
}

void inOrder(BstNode* root)
{
    if(!root)
        return ;

    inOrder(root->mLeft);
    cout <<root->mData <<'\t';
    inOrder(root->mRight);
}

void postOrder(BstNode* root)
{
    if(!root)
        return ;

    postOrder(root->mLeft);
    postOrder(root->mRight);
    cout <<root->mData <<'\t';
}

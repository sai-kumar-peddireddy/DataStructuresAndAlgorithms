#include <iostream>

#include "TreeDeclarations.h"

using namespace std;


int main()
{
    return 0;
}

BstNode* createNode(int data)
{
    auto new_element = new BstNode();
    new_element->mData = data;
    new_element->mLeft = nullptr;
    new_element->mRight = nullptr;

    return new_element;
}

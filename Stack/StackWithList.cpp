#include <iostream>

#include "StackOperations.h"

using namespace std;

struct Node
{
   int      mData;
   Node*    mNext;
};

static Node* Top = nullptr;

int main()
{

    push(10);
    push(20);
    top();

    printStack();
    pop();
    pop();
    pop();

}

// Here we are always inserting an element at the beginning of the list
// because traversing  to end of the list will take O(n)
// inserting an element at the beginning is O(1)
// anyway we always access the top of the stack

void push(const int& data)
{
    auto new_element = new Node;
    new_element->mData = data;
    new_element ->mNext = Top;
    Top = new_element;
}

int pop()
{
    cout << '\n';

    if(!Top)
    {
        cout << "Stack under flow " <<'\n';
        return -1;
    }

    auto element_to_delte = Top;
    Top = element_to_delte->mNext;

    const auto data = element_to_delte->mData;

    cout << "Poping element of Stack: " << data <<'\n';

    delete  element_to_delte;

    return data;
}

int top()
{
    if(!Top)
        return -1;

    cout << '\n' << "Top of Stack: " << Top->mData <<'\n';

    return Top->mData;
}

bool isEmpty()
{
    return  Top ? true: false;
}

void printStack()
{
    cout << '\n' <<"contentes of Stack:";
    auto itr = Top;
    while (itr->mNext != nullptr)
    {
        cout<<itr->mData <<'\t';
        itr = itr->mNext;
    }
    cout << '\n';
}

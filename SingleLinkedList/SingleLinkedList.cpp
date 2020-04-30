#include <iostream>
#include <stack>

#include "ListDeclarations.h"

using namespace std;

static Node* head = nullptr;

int main()
{
    for(int i = 0; i < 10; ++i)
        InsertValAtBeginning(i);

    printList();

    cout<<"Reverse order: " <<'\n';
    reverseListRecursive(head);
    printList();

    cout<<"Reverseing again with stack: " <<'\n';
    reverseListUsingStack();
    printList();

    for(int i = 9; i >= 0; --i)
        InsertValAtEnd(i);

    printList();

    for(int i = 1; i < 10; i += 2)
        InserAtGivenIndex(i + 10, i + 5);

    printList();

    DeleteAtGivenIndex(2);

    printList();
    cout<<"After Reverse";

    reverseList();
    printList();

    DeleteAll();
    return 0;
}

void InsertValAtEnd(int data)
{
    if(head)
    {
        auto iterator = head;

        while (iterator->mNext != nullptr)
            iterator = iterator->mNext;

        auto new_element = new Node();
        new_element->mData = data;
        new_element->mNext = nullptr;

        iterator->mNext = new_element;
    }
    else
    {
        auto new_element = new Node();
        new_element->mData = data;
        new_element->mNext = nullptr;
        head = new_element;
    }
}

void InsertValAtBeginning(int data)
{
    if(head)
    {
        auto new_node = new Node();
        new_node->mData = data;
        new_node->mNext = head;
        head = new_node;
    }
    else
    {
        head = new Node();
        head->mData = data;
        head->mNext = nullptr;
    }
}

void InserAtGivenIndex(int data, int pos)
{
    if(pos == 1)
    {
        auto new_node = new Node();
        new_node->mData = data;
        new_node->mNext = head;
        head = new_node;
    }
    else
    {
        auto itr = head;
        for(int i = 1; i < pos -1; ++i) //traversing till n-1 node
        {
            if(!itr)
            {
                cout<< "given positon is not a vaild position";
                return ;
            }
            itr = itr->mNext;
        }

        auto new_node = new Node();
        new_node->mData = data;
        new_node->mNext = itr->mNext;
        itr->mNext = new_node;
    }
}

void DeleteAtGivenIndex(int pos)
{
    if(pos == 1)
    {
        auto node_to_delete = head;
        head = head->mNext;
        delete node_to_delete;
    }
    else
    {
        auto itr = head;

        // loop to traverse n-1th node

        for(int i = 1; i < pos - 1; ++i)
        {
            itr = itr->mNext;
            if(!itr)
            {
                cout<< "given positon is not a vaild position";
                return ;
            }
        }
        auto node_to_delete = itr->mNext;
        itr->mNext = node_to_delete->mNext;

        cout <<"delteing: " << node_to_delete->mData
            << " pos: "<< pos <<'\t';
        delete node_to_delete;
    }
}

void printList()
{
    cout<<'\n'<<"Values are: "<<'\n';

    auto iterator = head;
    while (iterator != nullptr)
    {
        cout<< iterator->mData <<'\t';
        iterator = iterator->mNext;
    }
    cout<<'\n';
}

void DeleteAll()
{
    cout<<'\n'<<"deleting: "<<'\n';

    auto itr = head;
    while (itr != nullptr)
    {
        cout <<itr->mData <<'\t';

        auto next_itr = itr->mNext;
        delete itr;
        itr = next_itr;

    }
    cout<<'\n';
}

void reverseList()
{
    Node *curr, *prev, *next;
    curr = head;
    prev = nullptr;
    next = nullptr;

    while(curr != nullptr)
    {
        next = curr->mNext;
        curr->mNext = prev; // this is the key logic to reverse
        prev = curr;
        curr = next;
    }
    head = prev; // making head should point to first node
}

void reverseListRecursive(Node* curr)
{
    if(curr->mNext == nullptr)
    {
       head = curr;
       return ;
    }

    reverseListRecursive(curr->mNext);
    //these are key steps
    Node* prev = curr->mNext;
    prev->mNext = curr;
    curr->mNext = nullptr;
}

// by putting bool decession variable we are achiveing
// both forward and backward list printing in recursion

void printListRecursive(Node* node, bool forword)
{
    if(!node)
        return ;

    if(forword)
        cout<< node->mData<<'\t';

    printListRecursive(node->mNext, forword);

    if(!forword)
        cout<< node->mData<<'\t';
}

void reverseListUsingStack()
{
    stack<Node*> list_stack;

    auto itr = head;

    while (itr != nullptr)
    {
        list_stack.push(itr);
        itr = itr->mNext;
    }

    head = list_stack.top();
    list_stack.pop();

    itr = head;
    while (!list_stack.empty())
    {
        itr->mNext = list_stack.top();
        itr = itr->mNext;
        list_stack.pop();
    }

    itr->mNext = nullptr;
}

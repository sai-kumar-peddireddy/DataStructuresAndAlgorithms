#include <iostream>

#include "ListDeclarations.h"

using namespace std;

static Node* head = nullptr;

int main()
{
    printList();

    InsertValAtEnd(10);
    InsertValAtEnd(20);
    InsertValAtEnd(30);
    InserAtGivenIndex(15, 1);
    InserAtGivenIndex(40, 5);
    printList();
    return 0;
}

Node* createNode(int data)
{
    auto new_element = new Node();
    new_element->mData = data;
    new_element->mPrev = nullptr;
    new_element->mNext = nullptr;

    return new_element;
}

void InsertValAtEnd(int data)
{
    if(head)
    {
        auto iterator = head;

        while (iterator->mNext != nullptr)
            iterator = iterator->mNext;

        auto new_element = createNode(data);
        new_element->mData = data;
        new_element->mPrev = iterator;
        new_element->mNext = nullptr;

        iterator->mNext = new_element;
    }
    else
    {
        auto new_element = createNode(data);
        head = new_element;
    }
}

void InsertValAtBeginning(int data)
{
    if(head)
    {
        auto new_elemnet = createNode(data);
        new_elemnet->mNext = head;
        head->mPrev = new_elemnet;
        head = new_elemnet;
    }
    else
    {
         head = createNode(data);
    }
}

void InserAtGivenIndex(int data,int pos)
{
    auto itr = head;
    for(int i = 1; i < pos -1; ++i)
    {
        if(!itr)
        {
            cout<<"not a vaild position";
            return ;
        }
        itr = itr->mNext;
    }
    auto new_node = createNode(data);

    if(pos == 1)
    {
        head->mPrev = new_node;
        new_node->mNext = head;
        head = new_node;
        return ;
    }


    new_node->mNext = itr->mNext;
    itr->mNext = new_node;
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


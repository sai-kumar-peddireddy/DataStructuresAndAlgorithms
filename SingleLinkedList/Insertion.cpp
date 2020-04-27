#include <iostream>

#include "ListDeclarations.h"

using namespace std;

static Node* head = nullptr;

int main()
{
    for(int i = 0; i < 10; ++i)
        InsertValAtBeginning(i);

    printList(head);

    for(int i = 9; i >= 0; --i)
        InsertValAtEnd(i);

    printList(head);

    DeleteAll(head);
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
        auto temp_itr = head;
        head = new Node();
        head->mData = data;
        head->mNext = temp_itr;
    }
    else
    {
        head = new Node();
        head->mData = data;
        head->mNext = nullptr;
    }
}

void printList(Node* head)
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

void DeleteAll(Node* head)
{
    cout<<'\n'<<"deleting: "<<'\t';

    if(head)
    {
        auto itr = head;
        while (itr != nullptr)
        {
            cout <<itr->mData <<'\t';

            auto next_itr = itr->mNext;
            delete itr;
            itr = next_itr;

        }
    }
    cout<<'\n';
}

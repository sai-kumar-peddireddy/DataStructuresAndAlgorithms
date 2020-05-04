#include <iostream>

#include "QueueOperations.h"

using namespace std;


static Node* Qfront = nullptr;
static Node* Qrear  = nullptr;

int main()
{

    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);

    front();

    Dequeue();
    Dequeue();

    front();


    Enqueue(60);
    Enqueue(70);

    front();

    cout<<'\n';
    return 0;
}

// Here modulus operation(%) is key to circulate in array indexes

void Enqueue(const size_t& data)
{
    cout<<'\n';

    auto new_node = new Node;
    new_node->mData = data;
    new_node->mNext = nullptr;

    if(isEmpty())
    {
        Qfront = new_node;
        Qrear  = new_node;
        cout<<"Enqueueing Data: " <<Qrear->mData;
        return ;
    }

    Qrear->mNext = new_node;
    Qrear = new_node;

    cout<<"Enqueueing Data: " <<Qrear->mData;

}

void Dequeue()
{
    cout<<'\n';
    if(isEmpty())
    {
       cout<<"Queue is already empty Dequeue is not possible \n";
       return ;
    }

    cout <<"Dequeue an element: "<< Qfront->mData <<'\n';

    auto to_delete = Qfront;

    Qfront = Qfront->mNext;

    delete to_delete;
}


bool isEmpty()
{
    return Qfront == nullptr;
}

int front()
{
    cout<<"\n";
    if(!isEmpty())
    {
        cout<< "Front element is: " << Qfront->mData;
        return Qfront->mData;
    }
    return -1;
}


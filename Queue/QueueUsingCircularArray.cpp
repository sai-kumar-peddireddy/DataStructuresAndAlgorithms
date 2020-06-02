#include <iostream>

#include "QueueOperations.h"

using namespace std;

static constexpr int QSize = 5;

static size_t Qvar[QSize];

static int Qfront = -1;
static int Qrear = -1;

int main()
{

    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);

    front();

    if(isFull())
        cout<<"\nQueue is full"<<'\n';
    Dequeue();
    Dequeue();

    front();

    if(!isFull())
        cout<<"\nQueue is Not full"<<'\n';

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
    if((Qrear + 1) % QSize  == Qfront)
    {
        cout<<"Queue is full Enqueue is not possible \n";
        return ;
    }

    if(isEmpty())
    {
        Qfront++;
    }

    Qrear = (Qrear + 1) % QSize;

    cout<<"Enqueueing Data: " <<data <<" At index: "<<Qrear;

    Qvar[Qrear] = data;
}

void Dequeue()
{
    if(isEmpty())
    {
       cout<<"Queue is already empty Dequeue is not possible \n";
       return ;
    }

    cout <<"Dequeue an element: "<< Qvar[Qfront]<<" At index: "<<Qfront <<'\n';

    Qfront = (Qfront + 1) % QSize;

    if(Qfront == Qrear)
    {
        Qfront = Qrear = -1;
        return ;
    }
}


bool isEmpty()
{
    return Qfront == -1 && Qrear == -1;
}

int front()
{
    cout<<"\n";
    if(!isEmpty())
    {
        cout<< "Front element is: " << Qvar[Qfront];
        return Qvar[Qfront];
    }
    return -1;
}

bool isFull()
{
    return (Qrear + 1) % QSize == Qfront;
}

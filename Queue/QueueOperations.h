#ifndef QUEUEOPERATIONS_H
#define QUEUEOPERATIONS_H

void Enqueue(const size_t& data);
void Dequeue();

int front();


bool isEmpty();
bool isFull();

struct Node
{
    Node*    mNext;
    size_t   mData;
};


#endif // QUEUEOPERATIONS_H

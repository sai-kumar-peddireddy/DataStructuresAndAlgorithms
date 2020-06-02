#include <iostream>

#include "StackOperations.h"

using namespace std;

static constexpr size_t StackSize = 100;

static int Intstack[StackSize];
static int Top = -1;

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

void push(const int& data)
{
    Intstack[++Top] = data;
}

int pop()
{
    cout << '\n';

    if(Top == -1)
    {
        cout << "Stack under flow " <<'\n';
        return -1;
    }

    auto top_index = Top;
    --Top;

    cout << "Poping element of Stack: " << Intstack[top_index] <<'\n';

    return Intstack[top_index];
}

int top()
{
    if(Top == -1)
        return -1;

    cout << '\n' << "Top of Stack: " << Intstack[Top] <<'\n';

    return Intstack[Top];
}

bool isEmpty()
{
    return  Top == -1 ? true: false;
}

void printStack()
{
    cout << '\n' <<"contentes of Stack:";
    for(int i = Top ; i >= 0 ; --i)
    {
        cout<<Intstack[i] <<'\t';
    }
    cout << '\n';
}

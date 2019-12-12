#include <iostream>

using namespace std;
// function to sum of n natural numbers

void evenOrOdd()
{
    int input = 0;
    string msg;

    cout<< "enter number to check evenOrOdd ";
    cin>> input;

    auto result = input & 1;

    if(result == 0)
        msg = "even number";
    else
        msg = "odd number";

    cout<< input
        << " is a "<< msg.c_str()<< endl;
}

void setBitAtPos()
{
    int input, pos, result;
    string msg;

    cout<< "enter number to setBit ";
    cin>> input;
    cout<< "enter pos to setBit ";
    cin>> pos;

    result = 1 << pos;
    result = input | result;

    cout <<"after setting " << pos
         <<" bit in " << input
         <<" result is " << result <<'\n';

}
int main(int /*argc*/, char *argv[])
{
    (void) argv;
    setBitAtPos();

    //cin.get();
    return  0;
}

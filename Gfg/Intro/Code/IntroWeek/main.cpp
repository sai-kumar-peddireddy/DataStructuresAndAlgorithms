#include <iostream>
#include <ctype.h>

using namespace std;
// function to sum of n natural numbers

void sumOfNaturalNumbers()
{
    int input = 0;
    int sum_of_numbers = 0;

    cout<< "enter number to calculate sum of the natural numbers ";
    cin>> input;


    for(int loop_var = 1; loop_var <= input ; loop_var++)
        sum_of_numbers += loop_var;

    cout<< "sum of the first "<< input
        << " natural numbers is : "<< sum_of_numbers<< endl;
}

int main(int /*argc*/, char *argv[])
{
    sumOfNaturalNumbers();

    cin.get();
    return  0;
}

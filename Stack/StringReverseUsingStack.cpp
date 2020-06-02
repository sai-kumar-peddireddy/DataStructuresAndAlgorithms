#include <iostream>
#include <stack>
#include <string>

using namespace std;

void reverseString(string& input_string);

int main()
{
    string input_string = "hello world";

    cout<<"input string: "<<input_string <<'\n';
    reverseString(input_string);

    cout<<"reversed string is: "<<input_string<<'\n';

}


void reverseString(string& input_string)
{
    stack<char> char_stack;

    for(size_t i = 0; i < input_string.length() ; ++i)
        char_stack.push(input_string[i]);

    for(size_t i = 0; i < input_string.length() ; ++i)
    {
        input_string[i] = char_stack.top();
        char_stack.pop();
    }
}

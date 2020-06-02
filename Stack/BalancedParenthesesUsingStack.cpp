#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkBalancedParentheses(const string expression);

int main()
{
    string input_string = "(1 + 2 (2*5) ) * (5*6)";

    cout<<"input string: "<<input_string <<'\n';

    if(checkBalancedParentheses(input_string))
        cout<<input_string <<" is a valid expresion"<<'\n';
    else
        cout<<input_string <<" is not a valid expresion"<<'\n';

}


bool checkBalancedParentheses(const string expression)
{
    stack<char> expression_stack;

    for(size_t i = 0 ; i < expression.size(); ++i)
    {
        if(expression[i] == '(')
            expression_stack.push('(');

        else if(expression[i] == ')')
            expression_stack.pop();
    }
    return expression_stack.empty();
}

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int  EvaluatePostfix(const string expression);
int  EvaluatePrefix(const string expression);
bool isOperand(const char& input_char);

int main()
{
    //infix 2*5+5*5
    string postfix_string = "25*55*+";
    string prefix_string = "+*25*55";

    cout<<"postfix: "<<postfix_string <<'\n';

    cout<<"result is: " <<EvaluatePostfix(postfix_string)<<'\n';

    cout<<"prefix: "<<prefix_string <<'\n';

    cout<<"result is: " <<EvaluatePrefix(prefix_string)<<'\n';

}

int EvaluatePostfix(const string expression)
{
    stack<int> evalution_stack;

    for(size_t i = 0 ; i < expression.size(); ++i)
    {
        if(isOperand(expression[i]))
        {
            const int val = static_cast<int>(expression[i]) - 48;
            evalution_stack.push(val);

        }
        else
        {
            const auto operand2 = evalution_stack.top();
            evalution_stack.pop();
            const auto operand1 = evalution_stack.top();
            evalution_stack.pop();

            if(expression[i] == '*')
            {
                evalution_stack.push(operand1 * operand2);
            }
            else if(expression[i] == '+')
            {
                evalution_stack.push(operand1 + operand2);
            }

        }
    }

    return  evalution_stack.top();
}

bool isOperand(const char& input_char)
{
    const int val = static_cast<int>(input_char) - 48;

    return val > 0;
}

int EvaluatePrefix(const string expression)
{
    stack<int> evalution_stack;

    for(auto i = expression.rbegin(); i != expression.rend(); ++i)
    {
        if(isOperand(*i))
        {
            const auto int_val = static_cast<int>(*i) - 48;
            evalution_stack.push(int_val);
        }
        else
        {
            const auto operand1 = evalution_stack.top();
            evalution_stack.pop();

            const auto operand2 = evalution_stack.top();
            evalution_stack.pop();

            if(*i == '*')
                evalution_stack.push(operand1 * operand2);
            else if(*i == '+')
                evalution_stack.push(operand1 + operand2);
        }
    }

    return evalution_stack.top();
}


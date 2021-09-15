// infix to posfix (only precedence takken into consideration)
//    + -  -> 1
//    * /  -> 2

// #include <iostream>
// #include <stack>
// using namespace std;

// bool isOperand(char c)
// {
//     if (c == '+' || c == '-' || c == '*' || c == '/' )
//         return false;
//     return true;
// }
// int pre(char c)
// {
//     if (c == '+' || c == '-')
//         return 1;
//     else if (c == '*' || c == '/')
//         return 2;
//     else
//         return 4;
// }

// string ToPostfix(string infix)
// {
//     stack<char> stack;
//     int i = 0, j = 0;
//     char *postfix = new char[infix.length() + 1];

//     while (infix[i] != '\0')
//     {
//         if (isOperand(infix[i]))
//             postfix[j++] = infix[i++];
//         else if (!stack.empty())
//         {

//             if (pre(infix[i]) > pre(stack.top()))
//                 stack.push(infix[i++]);
//             else
//             {
//                 postfix[j++] = stack.top();
//                 stack.pop();
//             }
//         }
//         else if(stack.empty())
//             stack.push(infix[i++]);
//     }
//     while (!stack.empty())
//     {
//         postfix[j++] = stack.top();
//         stack.pop();
//     }
//     postfix[j] = '\0';
//     return postfix;
// }
// int main()
// {
//     string infix;
//     cin >> infix;
//     cout << ToPostfix(infix);
//     return 0;
// }

// // infix to postfix including associatitvity
// /****
//                      opeartor  pre     associativity
//                      +   -     1       L To R
//                      *   /     2       L To R
//                      ^         3       R To L
//                      (         4
//    concept

//                      opeartor  out Stack pre     in stack pre
//                      +   -     1                  2
//                      *   /     3                  4
//                      ^         6                  5
//                      (         7                  0
//                      )         0
//     ^ operator has left to right so pre of operator inside stack should be less than the ^ operator
//     outside the stack , so that later one will pop out first .
//     in-stack precedence for left to right operator must increase , so that first come will pop out first
//     in-stack precedence for right to left operator must decrease , so that first come will pop at last.
//   ***/

// #include <iostream>
// #include <stack>
// using namespace std;

// bool isOperand(char c)
// {
//     if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
//         return false;
//     return true;
// }
// int preInStack(char c)
// {
//     if (c == '+' || c == '-')
//         return 2;
//     else if (c == '*' || c == '/')
//         return 4;
//     else if (c == '^')
//         return 5;
//      else //if (c == '(')
//         return 0;
// }
// int preOutStack(char c)
// {
//     if (c == '+' || c == '-')
//         return 1;
//     else if (c == '*' || c == '/')
//         return 3;
//     else if (c == '^')
//         return 6;
//     else if (c == '(')
//         return 7;
//     else //if (c == ')')
//         return 0;
// }

// string infixToPostfix(string infix)
// {
//     int i = 0, j = 0;
//     stack<char> s;
//     char *postfix = new char[infix.length()];
//     while (infix[i] != '\0')
//     {
//         if (isOperand(infix[i]))
//             postfix[j++] = infix[i++];
//         else if (!s.empty())
//         {
//             if (preOutStack(infix[i]) > preInStack(s.top()))
//                 s.push(infix[i++]);
//             else if (preOutStack(infix[i]) == preInStack(s.top()))
//             {
//                 s.pop();
//                 i++;
//             }
//             else
//             {
//                 postfix[j++] = s.top();
//                 s.pop();
//             }
//         }
//         else if (s.empty())
//             s.push(infix[i++]);
//     }
//     while (!s.empty())
//     {
//         postfix[j++] = s.top();
//         s.pop();
//     }
//     postfix[j] = '\0';

//     return postfix;
// }

// int main()
// {
//     string infix;
//     cin >> infix;
//     cout << infixToPostfix(infix);
//     return 0;
// }

// solving the mathematic opration by converting infix into postfix expression

#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
        return false;
    return true;
}
int preInStack(char c)
{
    if (c == '+' || c == '-')
        return 2;
    else if (c == '*' || c == '/')
        return 4;
    else if (c == '^')
        return 5;
    else //if (c == '(')
        return 0;
}
int preOutStack(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '^')
        return 6;
    else if (c == '(')
        return 7;
    else //if (c == ')')
        return 0;
}

int operationResult(char c, int x, int y)
{
    int res;
    switch (c)
    {

    case '+':
    {
        res = x + y;
        break;
    }
    case '-':
    {
        res = x - y;
        break;
    }
    case '*':
    {
        res = x * y;
        break;
    }
    case '/':
    {
        res = x / y;
        break;
    }
    }
    return res;
}

int infixToPostfix(string infix)
{
    int i = 0, j = 0, res = 0;
    char oprt;
    stack<char> s;
    int *postfix = new int[infix.length() * sizeof(int)];
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++] - '0';
        else if (!s.empty())
        {
            if (preOutStack(infix[i]) > preInStack(s.top()))
                s.push(infix[i++]);
            else if (preOutStack(infix[i]) == preInStack(s.top()))
            {
                s.pop();
                i++;
            }
            else
            {
                // postfix[j++] = s.top();
                oprt = s.top();
                res = operationResult(oprt, postfix[j-2] , postfix[j-1]);
                postfix[j - 2] = res;
                j = j - 1;
                s.pop();
            }
        }

        else if (s.empty())
            s.push(infix[i++]);
    }
    while (!s.empty())
    {
        // postfix[j++] = s.top();
        oprt = s.top();
       res = operationResult(oprt, postfix[j-2] , postfix[j-1]);
                postfix[j - 2] = res;
                j = j - 1;
        s.pop();
    }
    //  postfix[j] = '\0';
    j--;

    return postfix[j];
}

int main()
{
    string str;
    cin >> str;
    cout << infixToPostfix(str);
    return 0;
}
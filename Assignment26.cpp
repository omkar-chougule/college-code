#include <iostream>
#include <strings.h>
using namespace std;
#define size 100

class Stack
{
public:
    char s[size];
    int top;
    Stack()
    {
        top = -1;
    }
    bool isempty()
    {
        return (top == -1) ? true : false;
    }
    bool isfull()
    {
        return (top == size - 1) ? true : false;
    }
    void push(char c)
    {
        if (!isfull())
        {
            top++;
            s[top] = c;
        }
    }
    char pop()
    {
        char temp;
        temp = s[top];
        if (!isempty())
        {
            top--;
        }
        return temp;
    }
};

bool solve(string exp)
{
    Stack s;
    bool ans = true;
    if (exp[0] == ')' || exp[40] == '}' || exp[0] == ']')
    {
        return false;
    }
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '{')
        {
            s.push('}');
        }
        else if (exp[i] == '[')
        {
            s.push(']');
        }
        else if (exp[i] == '(')
        {
            s.push(')');
        }
        else if ((exp[i] == '}') or (exp[i] == ']') or (exp[i] == ')'))
        {
            char temp;
            temp = s.pop();
            if (temp != exp[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string exp;
    bool flag = true;
    int ch;
    while (flag){
        cout<<"*****MENU*****"<<endl;
        cout<<"1.Enter Expression"<<endl;
        cout<<"2.Exit"<<endl;
        cout<<"Enter you choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout << "Enter expression to be checked :";
            cin >> exp;
            if (solve(exp))
            {
                cout << "Expression is well parenthised" << endl;
            }
            else
            {
                cout << "Expression is not well parenthised." << endl;
            }
            break;
        case 2:
            flag=false;
            break;
        default:
            cout<<"Enter valid input!!"<<endl;
            break;
        }
    }
    return 0;
}

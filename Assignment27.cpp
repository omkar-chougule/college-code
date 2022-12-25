#include <iostream>
#include <string>
#include <vector>
#define arr_size 20
using namespace std;

template <class T>
class stack
{
public:
    T arr[arr_size];
    int top = -1;
    bool isempty()
    {
        return (top <= -1) ? true : false;
    }
    bool isfull()
    {
        return (top == arr_size - 1) ? true : false;
    }
    void push(T elmt)
    {
        if (not isfull())
        {
            top++;
            arr[top] = elmt;
        }
    }
    T peek()
    {
        if (top != -1)
        {
            return arr[top];
        }
    }
    T pop()
    {
        if (not isempty())
        {
            top--;
            return arr[top + 1];
        }
    }
};

int priority(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
    else
        return 0;
}

string in_post(string exp)
{
    string ans;
    stack<char> s;
    char ch;
    for (int i = 0; i < exp.size(); i++)
    {
        ch = exp[i];
        if (ch == '(')
        {
            s.push('(');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!s.isempty() && priority(ch) <= priority(s.peek()))
            {
                ans += s.pop();
            }
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.peek() != '(')
            {
                ans += s.pop();
            }
            s.pop();
        }
        else
        {
            ans += ch;
        }
    }
    while (not s.isempty())
    {
        ans += s.pop();
    }
    return ans;
}

int calculate(string exp)
{
    int c = 0, val1, val2, temp;
    stack<int> values;
    char ch;
    int val[20];
    cout << "Enter values for variables." << endl;
    for (int i = 0; i < exp.size(); i++)
    {
        ch = exp[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            cout << "Enter value for " << ch << ":";
            cin >> val[c];
            c++;
        }
    }
    string post = in_post(exp);
    c = 0;
    for (int i = 0; i < post.size(); i++)
    {
        switch (post[i])
        {
        case '+':
            val2 = values.pop();
            val1 = values.pop();
            temp = val1 + val2;
            values.push(temp);
            break;
        case '*':
            val2 = values.pop();
            val1 = values.pop();
            temp = val1 * val2;
            values.push(temp);
            break;
        case '-':
            val2 = values.pop();
            val1 = values.pop();
            temp = val1 - val2;
            values.push(temp);
            break;
        case '/':
            val2 = values.pop();
            val1 = values.pop();
            temp = val1 / val2;
            values.push(temp);
            break;
        case ' ':
            break;

        default:
            values.push(val[c]);
            c++;
            break;
        }
    }
    return values.pop();
}

int main()
{
    string exp;
    bool flag = true;
    int choice;
    while (flag)
    {
        cout << "MENU\n1.Calculator\n2. Exit" << endl;
        cout << "Enter Your Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter expression:";
            cin >> exp;
            cout << "Value of equation is:" << calculate(exp) << endl;
            break;
        case 2:
            flag = false;
            break;
            cout << "Code exited" << endl;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
    return 0;
}
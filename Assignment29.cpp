#include <iostream>
#define size 5
using namespace std;

class queue
{
public:
    int arr[size] = {};
    int f , r;

    queue(){
        r=-1;
        f=-1;
    }

    bool isempty()
    {
        return (r == -1) ? true : false;
    }

    bool isfull()
    {
        return (r == size - 1) ? true : false;
    }

    void enqueue(int val)
    {
        if (isfull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (f == -1)
            {
                f++;
            }
            r++;
            arr[r] = val;
        }
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << arr[f] << " has been deleted." << endl;
            f++;
        }
    }

    void display()
    {
        int temp = f;
        if (isempty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            while (temp <= r)
            {
                cout << arr[temp] << " ";
                temp++;
            }
            cout << "\n";
        }
    }
};

int main()
{
    int ch;
    queue obj;
    bool flag = true;
    while (flag)
    {
        cout << "********MENU********" << endl;
        cout << "Select action to perform:" << endl;
        cout << "1.Queue full or empty" << endl;
        cout << "2.Display Queue" << endl;
        cout << "3.Add element" << endl;
        cout << "4.Remove element" << endl;
        cout << "5.Exit" << endl;
        cout << "enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (obj.isfull())
            {
                cout << "Queue is full" << endl;
            }
            else if (obj.isempty())
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << " Queue has some elements" << endl;
            }
            break;
        case 2:
            obj.display();
            break;
        case 3:
            int val;
            cout << "Enter element you want to add:";
            cin >> val;
            obj.enqueue(val);
            break;
        case 4:
            obj.dequeue();
            break;
        case 5:
            flag = false;
            break;
        default:
            cout << "Enter valid choice!!" << endl;
            break;
        }
    }
}
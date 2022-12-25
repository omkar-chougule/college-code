#include <iostream>
#define size 10
using namespace std;

class dequeue
{
public:
    int arr[size];
    int f = -1, r = -1;

    bool isfull()
    {
        return (f == -1 and r == size - 1) ? true : false;
    }
    bool isempty()
    {
        return (r == -1) ? true : false;
    }
    void enqueuer(int val)
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

    void enqueuef(int val)
    {
        if (isfull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            f--;
            arr[f] = val;
        }
    }
    void dequeuef()
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
    void dequeuer()
    {
        if (isempty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << arr[r] << " has been deleted." << endl;
            r--;
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
    dequeue obj;
    bool flag = true;
    int val;
    while (flag)
    {
        cout << "*********MENU*********" << endl;
        cout << "Select action to perform:" << endl;
        cout << "1.Queue full or empty" << endl;
        cout << "2.Display Queue" << endl;
        cout << "3.Add element at rear" << endl;
        cout << "4.Add element at front" << endl;
        cout << "5.Remove element from rear" << endl;
        cout << "6.Remove element from front" << endl;
        cout << "7.Exit" << endl;
        cout << "enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (obj.isempty())
            {
                cout << "Queue is empty" << endl;
            }
            else if (obj.isfull())
            {
                cout << "Queue is full" << endl;
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
            cout << "Enter element you want to add:";
            cin >> val;
            obj.enqueuer(val);
            break;
        case 4:
            cout << "Enter element you want to add:";
            cin >> val;
            obj.enqueuef(val);
            break;
        case 5:
            obj.dequeuer();
            break;
        case 6:
            obj.dequeuef();
            break;
        case 7:
            flag = false;
            break;
        default:
            cout << "Enter valid choice!!" << endl;
            break;
        }
    }
}
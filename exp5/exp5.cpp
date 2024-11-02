#include <iostream>
using namespace std;

class TwoStacks
{
    int *arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            arr[++top1] = x;
        }
        else
        {
            cout << "Stack1 Overflow\n";
        }
    }

    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            arr[--top2] = x;
        }
        else
        {
            cout << "Stack2 Overflow\n";
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            return arr[top1--];
        }
        else
        {
            cout << "Stack1 Underflow\n";
            return -1;
        }
    }

    int pop2()
    {
        if (top2 < size)
        {
            return arr[top2++];
        }
        else
        {
            cout << "Stack2 Underflow\n";
            return -1;
        }
    }

    void display()
    {
        cout << "\nStack1: ";
        for (int i = 0; i <= top1; i++)
            cout << arr[i] << " ";

        cout << "\nStack2: ";
        for (int i = size - 1; i >= top2; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    TwoStacks ts(10);

    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);

    ts.display();

    cout << "Popped from stack1: " << ts.pop1() << endl;
    cout << "Popped from stack2: " << ts.pop2() << endl;

    ts.display();

    return 0;
}

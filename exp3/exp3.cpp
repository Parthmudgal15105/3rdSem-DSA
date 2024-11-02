#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack\n";
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << temp->data << " popped from stack\n";
        delete temp;
    }

    void traverse()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }
        Node *temp = top;
        cout << "Stack elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.traverse();

    stack.pop();
    stack.pop();

    stack.traverse();

    return 0;
}

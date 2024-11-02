#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the end
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete a node with given value
    void deleteNode(int val)
    {
        if (!head)
            return;

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->data != val)
        {
            temp = temp->next;
        }
        if (temp->next)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Reverse the linked list
    void reverse()
    {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Display the linked list
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;

    // Insert elements
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    cout << "Original list: ";
    list.display();

    // Delete node
    list.deleteNode(2);
    cout << "After deleting 2: ";
    list.display();

    // Reverse list
    list.reverse();
    cout << "After reversing: ";
    list.display();

    return 0;
}
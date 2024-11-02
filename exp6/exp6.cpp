#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    Node *root;

    void preorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        if (!root)
        {
            root = new Node(value);
            return;
        }

        Node *current = root;
        while (true)
        {
            if (value < current->data)
            {
                if (!current->left)
                {
                    current->left = new Node(value);
                    break;
                }
                current = current->left;
            }
            else
            {
                if (!current->right)
                {
                    current->right = new Node(value);
                    break;
                }
                current = current->right;
            }
        }
    }

    void preorder()
    {
        preorderTraversal(root);
        cout << endl;
    }

    void inorder()
    {
        inorderTraversal(root);
        cout << endl;
    }

    void postorder()
    {
        postorderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    return 0;
}
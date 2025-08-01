#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
Node *insert(Node *root, char value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        inOrder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    Node *root = nullptr;

    root = insert(root, 'a');
    insert(root, 'b');
    insert(root, 'd');
    insert(root, 'h');
    insert(root, 'e');
    insert(root, 'i');
    insert(root, 'c');
    insert(root, 'f');
    insert(root, 'j');

    cout << "In-order traversal of the BST: ";
    inOrder(root);
    return 0;
}
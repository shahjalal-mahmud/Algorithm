#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    int preIndex = 0;
    unordered_map<char, int> inorderIndexMap;

    Node* buildTree(const string& preorder, const string& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        char rootVal = preorder[preIndex++];
        Node* root = new Node(rootVal);

        int inIndex = inorderIndexMap[rootVal];
        root->left = buildTree(preorder, inorder, inStart, inIndex - 1);
        root->right = buildTree(preorder, inorder, inIndex + 1, inEnd);

        return root;
    }

    void postorderTraversal(Node* root) {
        if (!root) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }

public:
    void constructAndPrintPostorder(const string& preorder, const string& inorder) {
        preIndex = 0;
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndexMap[inorder[i]] = i;

        Node* root = buildTree(preorder, inorder, 0, inorder.size() - 1);
        cout << "Postorder: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    string preorder = "abdgheicfj";
    string inorder  = "gdhbeiafjc";
    tree.constructAndPrintPostorder(preorder, inorder);
    return 0;
}

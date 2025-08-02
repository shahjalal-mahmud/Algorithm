#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Constructs tree from postorder and inorder
Node* buildTreeFromPostIn(vector<char>& postorder, vector<char>& inorder, 
                          int inStart, int inEnd, int& postIndex, 
                          unordered_map<char, int>& inmap) {
    if (inStart > inEnd) return nullptr;

    char rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);
    int inRoot = inmap[rootVal];

    // ⚠️ Right before left (because postorder is reversed)
    root->right = buildTreeFromPostIn(postorder, inorder, inRoot + 1, inEnd, postIndex, inmap);
    root->left = buildTreeFromPostIn(postorder, inorder, inStart, inRoot - 1, postIndex, inmap);

    return root;
}

// Preorder traversal (Root -> Left -> Right)
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    vector<char> inorder =    {'g', 'd', 'h', 'b', 'e', 'i', 'a', 'f', 'j', 'c'};
    vector<char> postorder = {'g', 'h', 'd', 'i', 'e', 'b', 'j', 'f', 'c', 'a'};

    unordered_map<char, int> inmap;
    for (int i = 0; i < inorder.size(); i++) {
        inmap[inorder[i]] = i;
    }

    int postIndex = postorder.size() - 1;
    Node* root = buildTreeFromPostIn(postorder, inorder, 0, inorder.size() - 1, postIndex, inmap);

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}

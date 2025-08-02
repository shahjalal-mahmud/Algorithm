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

// Construct from inorder + preorder
Node* buildTreeFromPreIn(vector<char>& preorder, vector<char>& inorder,
                         int inStart, int inEnd, int& preIndex,
                         unordered_map<char, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    char rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);
    int inRoot = inMap[rootVal];

    root->left = buildTreeFromPreIn(preorder, inorder, inStart, inRoot - 1, preIndex, inMap);
    root->right = buildTreeFromPreIn(preorder, inorder, inRoot + 1, inEnd, preIndex, inMap);

    return root;
}

// Optional: Inorder traversal to test the built tree
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    vector<char> inorder = {'g', 'd', 'h', 'b', 'e', 'i', 'a', 'f', 'j', 'c'};
    vector<char> preorder = {'a', 'b', 'd', 'g', 'h', 'e', 'i', 'c', 'f', 'j'};

    unordered_map<char, int> inMap;
    for (int i = 0; i < inorder.size(); ++i)
        inMap[inorder[i]] = i;

    int preIndex = 0;
    Node* root = buildTreeFromPreIn(preorder, inorder, 0, inorder.size() - 1, preIndex, inMap);

    cout << "Tree constructed. Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

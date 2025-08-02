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

Node* buildTreeFromPrePost(vector<char>& preorder, vector<char>& postorder,
                           int& preIndex, int postStart, int postEnd,
                           unordered_map<char, int>& postMap) {
    if (postStart > postEnd) return nullptr;

    Node* root = new Node(preorder[preIndex++]);

    // Leaf node
    if (postStart == postEnd) return root;

    // Find next root in postorder
    char nextVal = preorder[preIndex];
    int idx = postMap[nextVal];

    root->left = buildTreeFromPrePost(preorder, postorder, preIndex, postStart, idx, postMap);
    root->right = buildTreeFromPrePost(preorder, postorder, preIndex, idx + 1, postEnd - 1, postMap);

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<char> preorder =  {'a', 'b', 'd', 'g', 'h', 'e', 'i', 'c', 'f', 'j'};
    vector<char> postorder = {'g', 'h', 'd', 'i', 'e', 'b', 'j', 'f', 'c', 'a'};

    unordered_map<char, int> postMap;
    for (int i = 0; i < postorder.size(); i++)
        postMap[postorder[i]] = i;

    int preIndex = 0;
    Node* root = buildTreeFromPrePost(preorder, postorder, preIndex, 0, postorder.size() - 1, postMap);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}

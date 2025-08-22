#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};
Node* buildTree(vector<char>& inorder, vector<char>& preorder, int inStart, int inEnd, int& preIndex, unordered_map<char, int>& inmap){
    if(inStart > inEnd) return nullptr;
    char rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);
    int inRoot = inmap[rootVal];
    root->left = buildTree(inorder, preorder, inStart, inRoot-1, preIndex, inmap);
    root->right = buildTree(inorder, preorder, inRoot+1, inEnd, preIndex, inmap);
    return root;
}
void postorder(Node* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    vector<char> preorder = {'a','b','d','g','h','e','i','c','f','j'};
    vector<char> inorder  = {'g','d','h','b','e','i','a','f','j','c'};

    unordered_map<char, int> inmap;
    for(int i = 0; i<inorder.size(); i++){
        inmap[inorder[i]] = i;
    }
    int preIndex = 0;
    Node* root = buildTree(inorder, preorder, 0, inorder.size()-1, preIndex, inmap);

    cout<<"Post-Order: ";
    postorder(root);

    return 0;
}
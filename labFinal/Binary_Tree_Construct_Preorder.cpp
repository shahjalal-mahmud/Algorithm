#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        char data;
        Node* left;
        Node* right;
        Node(char val) : data(val), left(nullptr), right(nullptr) {}
};
Node* buildTree(vector<char>& inorder, vector<char>& postorder, int inStart, int inEnd, int& postIndex, unordered_map<char, int>& inmap){
    if(inStart > inEnd) return nullptr;
    int rootVal = postorder[postIndex--];
    Node *root = new Node(rootVal);
    int inRoot = inmap[rootVal];
    root->right = buildTree(inorder, postorder, inRoot+1, inEnd, postIndex, inmap);
    root->left = buildTree(inorder, postorder, inStart, inRoot-1, postIndex, inmap);
    return root;
}
void preorder(Node* root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    vector<char> inorder = {'g', 'd', 'h', 'b', 'e', 'i', 'a', 'f', 'j', 'c'};
    vector<char> postorder = {'g', 'h', 'd', 'i', 'e', 'b', 'j', 'f', 'c', 'a'};

    unordered_map<char, int> inmap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]] = i;
    }

    int postIndex = postorder.size() - 1;
    Node *root = buildTree(inorder, postorder, 0, inorder.size()-1, postIndex, inmap);
    cout<<"Preorder: ";
    preorder(root);
    return 0;
}
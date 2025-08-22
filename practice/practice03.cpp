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
Node* buildTree(vector<char>& postorder, vector<char>& inorder, int inStart, int inEnd, int& postIndex, unordered_map<char, int>& inmap){
    if(inStart > inEnd) return nullptr;
    int rootVal = postorder[postIndex--];
    Node *root = new Node(rootVal);
    int inRoot = inmap[rootVal];
    root->right = buildTree(postorder, inorder, inRoot+1, inEnd, postIndex, inmap);
    root->left = buildTree(postorder, inorder, inStart, inRoot-1, postIndex, inmap);
    return root;
}
void preorder(Node *root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    vector<char> postorder = {'g', 'h', 'd', 'i', 'e', 'b', 'j', 'f', 'c', 'a'};
    vector<char> inorder = {'g', 'd', 'h', 'b', 'e', 'i', 'a', 'f', 'j', 'c'};
    unordered_map<char, int> inmap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]] = i;
    }
    int postIndex = postorder.size() - 1;
    Node *root = buildTree(postorder, inorder, 0, inorder.size()-1, postIndex, inmap);
    cout<<"Preorder: ";
    preorder(root);
    return 0;
}
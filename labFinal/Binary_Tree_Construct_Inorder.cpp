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
Node* buildTree(vector<char>& preorder, vector<char>postorder, int postStart, int postEnd, int& preIndex, unordered_map<char, int>& postmap){
    if(postStart > postEnd) return nullptr;
    int rootVal = preorder[preIndex++];
    Node *root = new Node(rootVal);
    if(postStart == postEnd) return root;
    int nextValIndex = postmap[preorder[preIndex]];
    if(nextValIndex <= postEnd){
        root->left = buildTree(preorder, postorder, postStart, nextValIndex, preIndex, postmap);
        root->right = buildTree(preorder, postorder, nextValIndex+1, postEnd-1, preIndex, postmap);
    }
    return root;
}
void inorder(Node *root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}
int main() {
    vector<char> preorder = {'a', 'b', 'd', 'g', 'h', 'e', 'i', 'c', 'f', 'j'};
    vector<char> postorder = {'g', 'h', 'd', 'i', 'e', 'b', 'j', 'f', 'c', 'a'};
    unordered_map<char, int> postmap;
    for (int i = 0; i < postorder.size(); i++)
    {
        postmap[postorder[i]] = i;
    }
    int preIndex = 0;
    Node *root = buildTree(preorder, postorder, 0, postorder.size()-1, preIndex, postmap);
    cout<<"Inorder: ";
    inorder(root);
    return 0;
}
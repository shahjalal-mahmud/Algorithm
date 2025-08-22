#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void inorder(const vector<int>& tree, int i){
    if(i >= tree.size())return;
    inorder(tree, 2*i+1);   //left
    cout<<tree[i]<<" ";     // root
    inorder(tree, 2*i+2);   //right
}
void preorder(const vector<int>& tree, int i){
    if(i >= tree.size()) return;
    cout<<tree[i]<<" ";
    preorder(tree, 2*i+1);
    preorder(tree, 2*i+2);
}
void postorder(const vector<int>& tree, int i){
    if(i >= tree.size()) return;
    postorder(tree, 2*i+1);
    postorder(tree, 2*i+2);
    cout<< tree[i]<<" ";
}
int main() {
    vector<int> tree = {1, 2, 3, 4, 5, 6, 7};
    inorder(tree, 0);
    cout<<endl;
    preorder(tree, 0);
    cout<<endl;
    postorder(tree, 0);
    cout<<endl;
    return 0;
}
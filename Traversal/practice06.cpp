#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void preorder(vector<char>& postorder, vector<char>& inorder, int inStart, int inEnd, int& postIndex, unordered_map<char, int>& inmap){
    if (inStart > inEnd) return;
    char rootVal = postorder[postIndex--];
    int inRoot = inmap[rootVal];
    cout<<rootVal<<" ";
    preorder(postorder, inorder, inStart, inRoot-1, postIndex, inmap);
    preorder(postorder, inorder, inRoot+1, inEnd, postIndex, inmap);
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
    cout<<"Preorder: ";
    preorder(postorder, inorder, 0, inorder.size()-1, postIndex, inmap);
    
    return 0;
}
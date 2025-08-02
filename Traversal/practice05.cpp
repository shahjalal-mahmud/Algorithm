#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void Postorder(vector<char>& preorder, vector<char>& inorder, int inStart, int inEnd, int& preIndex, unordered_map<char, int>& inmap){
    if(inStart > inEnd) return;
    char rootVal = preorder[preIndex++];
    int inRoot = inmap[rootVal];
    Postorder(preorder, inorder, inStart, inRoot-1, preIndex, inmap);
    Postorder(preorder, inorder, inRoot+1, inEnd, preIndex, inmap);
    cout<<rootVal<<" ";
}
int main() {
    vector<char> inorder = {'g', 'd', 'h', 'b', 'e', 'i', 'a', 'f', 'j', 'c'};
    vector<char> preorder = {'a', 'b', 'd', 'g', 'h', 'e', 'i', 'c', 'f', 'j'};
    unordered_map<char, int> inmap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]] = i;
    }
    int preIndex = 0;
    cout << "Postorder traversal: ";
    Postorder(preorder, inorder, 0, inorder.size()-1, preIndex, inmap);
    
    return 0;
}
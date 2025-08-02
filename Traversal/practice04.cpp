#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void postordeer(vector<char> &preorder, vector<char> &inorder, int instart, int inEnd, int& preIndex, unordered_map<char, int>& inmap)
{
    if (instart > inEnd)
    {
        return;
    }
    char rootval = preorder[preIndex++];
    int intRoot = inmap[rootval];
    postordeer(preorder, inorder, instart, intRoot - 1, preIndex, inmap);
    postordeer(preorder, inorder, intRoot + 1, inEnd, preIndex, inmap);
    cout << rootval << " ";
}
int main()
{
    vector<char> inorder = {'g', 'd', 'h', 'b', 'e', 'i', 'a', 'f', 'j', 'c'};
    vector<char> preorder = {'a', 'b', 'd', 'g', 'h', 'e', 'i', 'c', 'f', 'j'};
    unordered_map<char, int> inmap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]]=i;
    }
    int preIndex = 0;
    cout << "Postorder traversal: ";
    postordeer(preorder, inorder, 0,inorder.size()-1, preIndex, inmap);

    return 0;
}
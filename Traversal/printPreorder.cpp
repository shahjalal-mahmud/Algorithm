#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printPreorderFromInPost(vector<char>& inorder, vector<char>& postorder,
                           int inStart, int inEnd, int& postIndex,
                           unordered_map<char, int>& inMap) {
    if (inStart > inEnd) return;
    
    char rootVal = postorder[postIndex--];
    int inRoot = inMap[rootVal];
    
    // Print root first (preorder)
    cout << rootVal << " ";
    
    // Right subtree first (since we're processing postorder backwards)
    printPreorderFromInPost(inorder, postorder, inRoot + 1, inEnd, postIndex, inMap);
    
    // Left subtree
    printPreorderFromInPost(inorder, postorder, inStart, inRoot - 1, postIndex, inMap);
}

int main() {
    vector<char> inorder = {'g', 'd', 'h', 'b', 'e', 'i', 'a', 'f', 'j', 'c'};
    vector<char> postorder = {'g', 'h', 'd', 'i', 'e', 'b', 'j', 'f', 'c', 'a'};
    
    // Create map for quick inorder index lookup
    unordered_map<char, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    int postIndex = postorder.size() - 1;
    cout << "Preorder traversal: ";
    printPreorderFromInPost(inorder, postorder, 0, inorder.size() - 1, postIndex, inMap);
    cout << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void postOrder(vector<char>& inorder, vector<char>& preorder, 
                            int inStart, int inEnd, int& preIndex, 
                            unordered_map<char, int>& inMap) {
    if (inStart > inEnd) return;
    
    char rootVal = preorder[preIndex++];
    int inRoot = inMap[rootVal];
    
    // Left subtree
    postOrder(inorder, preorder, inStart, inRoot - 1, preIndex, inMap);
    
    // Right subtree
    postOrder(inorder, preorder, inRoot + 1, inEnd, preIndex, inMap);
    
    // Print root
    cout << rootVal << " ";
}

int main() {
    vector<char> inorder = {'g', 'd', 'h', 'b', 'e', 'i', 'a', 'f', 'j', 'c'};
    vector<char> preorder = {'a', 'b', 'd', 'g', 'h', 'e', 'i', 'v', 'f', 'j', 'c'};
    
    unordered_map<char, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    int preIndex = 0;
    cout << "Postorder traversal: ";
    postOrder(inorder, preorder, 0, inorder.size() - 1, preIndex, inMap);
    cout << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void inorderFromPrePost(vector<char>& preorder, vector<char>& postorder,
                      int& preIndex, int postStart, int postEnd,
                      unordered_map<char, int>& postMap) {
    if (postStart > postEnd) return;
    
    char rootVal = preorder[preIndex++];
    
    // If leaf node, print and return
    if (postStart == postEnd) {
        cout << rootVal << " ";
        return;
    }
    
    // Find next root in postorder
    char nextRoot = preorder[preIndex];
    int postNextRoot = postMap[nextRoot];
    
    // Process left subtree
    inorderFromPrePost(preorder, postorder, preIndex, postStart, postNextRoot, postMap);
    
    // Print root (inorder position)
    cout << rootVal << " ";
    
    // Process right subtree
    inorderFromPrePost(preorder, postorder, preIndex, postNextRoot + 1, postEnd - 1, postMap);
}

int main() {
    // For full binary trees only (each node has 0 or 2 children)
    vector<char> preorder = {'a', 'b', 'd', 'g', 'h', 'e', 'i', 'c', 'f', 'j'};
    vector<char> postorder = {'g', 'h', 'd', 'i', 'e', 'b', 'j', 'f', 'c', 'a'};
    
    // Create map for postorder positions
    unordered_map<char, int> postMap;
    for (int i = 0; i < postorder.size(); i++) {
        postMap[postorder[i]] = i;
    }
    
    int preIndex = 0;
    cout << "Inorder traversal: ";
    inorderFromPrePost(preorder, postorder, preIndex, 0, postorder.size() - 1, postMap);
    cout << endl;
    
    return 0;
}
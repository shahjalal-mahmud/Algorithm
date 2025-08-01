#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void buildPostorder(const vector<char>& preorder, int preStart, int preEnd,
                    const vector<char>& inorder, int inStart, int inEnd,
                    unordered_map<char, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return;

    char root = preorder[preStart];
    int inRoot = inMap[root];
    int numsLeft = inRoot - inStart;

    buildPostorder(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    buildPostorder(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    cout << root << " ";
}

int main() {
    vector<char> inorder  = {'g','d','h','b','e','i','a','f','j','c'};
    vector<char> preorder = {'a','b','d','g','h','e','i','c','f','j'};

    unordered_map<char, int> inMap;
    for (int i = 0; i < inorder.size(); ++i)
        inMap[inorder[i]] = i;

    cout << "Postorder: ";
    buildPostorder(preorder, 0, preorder.size() - 1,
                   inorder, 0, inorder.size() - 1, inMap);
    cout << endl;

    return 0;
}

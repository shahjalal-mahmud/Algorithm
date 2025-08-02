#include <iostream>
#include <unordered_map>
#include <queue>
#include <functional> // <-- Required for std::function
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildFromPostIn(int postorder[], int inorder[], int length) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < length; ++i)
        inMap[inorder[i]] = i;

    int postIndex = length - 1;
    function<TreeNode*(int, int)> build = [&](int inStart, int inEnd) -> TreeNode* {
        if (inStart > inEnd) return nullptr;
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];
        root->right = build(inIndex + 1, inEnd);
        root->left = build(inStart, inIndex - 1);
        return root;
    };

    return build(0, length - 1);
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    int postorder[] = {4, 5, 2, 6, 3, 1};
    int inorder[]   = {4, 2, 5, 1, 6, 3};
    int length = sizeof(postorder) / sizeof(postorder[0]);

    TreeNode* root = buildFromPostIn(postorder, inorder, length);

    printLevelOrder(root);
    return 0;
}

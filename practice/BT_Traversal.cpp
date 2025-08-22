#include <iostream>
#include <vector>
using namespace std;

void inorder(const vector<int>& tree, int i) {
    if (i >= tree.size()) return;
    inorder(tree, 2*i+1);   // left
    cout << tree[i] << " "; // root
    inorder(tree, 2*i+2);   // right
}

void preorder(const vector<int>& tree, int i) {
    if (i >= tree.size()) return;
    cout << tree[i] << " "; // root
    preorder(tree, 2*i+1);  // left
    preorder(tree, 2*i+2);  // right
}

void postorder(const vector<int>& tree, int i) {
    if (i >= tree.size()) return;
    postorder(tree, 2*i+1); // left
    postorder(tree, 2*i+2); // right
    cout << tree[i] << " "; // root
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> tree(n);
    cout << "Enter elements of the tree: ";
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    cout << "\nInorder: ";
    inorder(tree, 0);

    cout << "\nPreorder: ";
    preorder(tree, 0);

    cout << "\nPostorder: ";
    postorder(tree, 0);

    cout << endl;
    return 0;
}

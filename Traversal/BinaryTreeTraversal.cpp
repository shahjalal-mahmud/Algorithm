#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val) {}
};

class BinaryTree {
    Node* root = nullptr;

    Node* buildFromPreIn(const vector<int>& pre, int& pi, int inL, int inR, unordered_map<int, int>& inMap) {
        if (inL > inR) return nullptr;
        Node* node = new Node(pre[pi]);
        int idx = inMap[pre[pi++]];
        node->left = buildFromPreIn(pre, pi, inL, idx - 1, inMap);
        node->right = buildFromPreIn(pre, pi, idx + 1, inR, inMap);
        return node;
    }

    Node* buildFromInPost(const vector<int>& post, int& pi, int inL, int inR, unordered_map<int, int>& inMap) {
        if (inL > inR) return nullptr;
        Node* node = new Node(post[pi]);
        int idx = inMap[post[pi--]];
        node->right = buildFromInPost(post, pi, idx + 1, inR, inMap);
        node->left = buildFromInPost(post, pi, inL, idx - 1, inMap);
        return node;
    }

    void inorder(Node* n) { if (n) { inorder(n->left); cout << n->data << " "; inorder(n->right); } }
    void preorder(Node* n) { if (n) { cout << n->data << " "; preorder(n->left); preorder(n->right); } }
    void postorder(Node* n) { if (n) { postorder(n->left); postorder(n->right); cout << n->data << " "; } }

public:
    void construct(const vector<int>& t1, const vector<int>& t2, const string& type1, const string& type2) {
        unordered_map<int, int> inMap;
        if ((type1 == "preorder" && type2 == "inorder") || (type1 == "inorder" && type2 == "preorder")) {
            vector<int> pre = (type1 == "preorder") ? t1 : t2;
            vector<int> in = (type1 == "inorder") ? t1 : t2;
            for (int i = 0; i < in.size(); ++i) inMap[in[i]] = i;
            int idx = 0;
            root = buildFromPreIn(pre, idx, 0, in.size() - 1, inMap);
            cout << "Postorder: "; postorder(root);
        }
        else if ((type1 == "postorder" && type2 == "inorder") || (type1 == "inorder" && type2 == "postorder")) {
            vector<int> post = (type1 == "postorder") ? t1 : t2;
            vector<int> in = (type1 == "inorder") ? t1 : t2;
            for (int i = 0; i < in.size(); ++i) inMap[in[i]] = i;
            int idx = post.size() - 1;
            root = buildFromInPost(post, idx, 0, in.size() - 1, inMap);
            cout << "Preorder: "; preorder(root);
        }
        else {
            cout << "Cannot uniquely build tree from " << type1 << " and " << type2 << endl;
        }
        cout << endl;
    }

    void printAllTraversals() {
        cout << "Inorder: "; inorder(root); cout << endl;
        cout << "Preorder: "; preorder(root); cout << endl;
        cout << "Postorder: "; postorder(root); cout << endl;
    }
};

int main() {
    int n;
    string type1, type2;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter two traversal types (preorder, inorder, postorder): ";
    cin >> type1 >> type2;

    vector<int> t1(n), t2(n);
    cout << "Enter " << type1 << " sequence: ";
    for (int i = 0; i < n; ++i) cin >> t1[i];
    cout << "Enter " << type2 << " sequence: ";
    for (int i = 0; i < n; ++i) cin >> t2[i];

    BinaryTree tree;
    tree.construct(t1, t2, type1, type2);

    return 0;
}
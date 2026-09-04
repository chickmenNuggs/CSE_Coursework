#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node *left, *right, *parent;
    Node(int k): key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

struct BST {
    Node* root = nullptr;

    Node* treeMinimum(Node* x) {
        while (x->left) x = x->left;
        return x;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v != nullptr)
            v->parent = u->parent;
    }

    void insert(int k) {
        Node* z = new Node(k);
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            if (z->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }

    Node* search(Node* x, int k) {
        if (x == nullptr || k == x->key) return x;
        if (k < x->key) return search(x->left, k);
        else return search(x->right, k);
    }

    void treeDelete(Node* z) {
        if (z == nullptr) return;

        if (z->left == nullptr)
            transplant(z, z->right);
        else if (z->right == nullptr)
            transplant(z, z->left);
        else {
            Node* y = treeMinimum(z->right);
            if (y->parent != z) {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        delete z;
    }

    void inorder(Node* x) {
        if (!x) return;
        inorder(x->left);
        cout << x->key << "\n";
        inorder(x->right);
    }

    void preorder(Node* x) {
        if (!x) return;
        cout << x->key << "\n";
        preorder(x->left);
        preorder(x->right);
    }

    void postorder(Node* x) {
        if (!x) return;
        postorder(x->left);
        postorder(x->right);
        cout << x->key << "\n";
    }

    void printInorder() { inorder(root); }
    void printPreorder() { preorder(root); }
    void printPostorder() { postorder(root); }
};

int main() {
    BST T;
    string cmd;
    while (cin >> cmd) {
        //exit
        if (cmd[0] == 'e') break;
        //insert
        else if (cmd[0] == 'i') {
            if (cmd.size() > 1) {  
                int key = stoi(cmd.substr(1)); 
                T.insert(key);
            }
            // else: do nothing
        }
        //delete
        else if (cmd[0] == 'd') {
            int key = stoi(cmd.substr(1));
            Node* z = T.search(T.root, key);
            T.treeDelete(z);
        }
        //print
        else if (cmd == "oin")
            T.printInorder();
        else if (cmd == "opre")
            T.printPreorder();
        else if (cmd == "opost")
            T.printPostorder();
    }
}

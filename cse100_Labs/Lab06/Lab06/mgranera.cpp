#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <string>


using namespace std;

struct Node{
        int value; 
        Node* l; 
        Node* r;
        Node* p;
        Node(int key){
            value = key;
            l = nullptr;
            p = nullptr;
            r = nullptr;
        }
};

struct BSTree {
    Node* root = nullptr;
};




void insert(BSTree* T, int k){
    Node* z = new Node(k);
    Node* y = nullptr;
    Node* x = T->root;
    while (x != nullptr) {
        y = x;
        if (z->value < x->value)
        {
            x = x->l;
        }
        else{ x = x->r;}
    }
    z->p = y;
    if (y == nullptr)
    {
        T->root = z;
    }
    else if (z->value < y->value)
    {
        y->l = z;
    }
    else {
        y->r = z;
    }
}

void ts(BSTree* T, Node* u, Node* v){
    if (u->p == nullptr)
    {
        T->root = v;
    }
    else if (u == u->p->l)
    {
        u->p->l = v;
    }
    else 
    {
        u->p->r = v;
    }
    if (v != nullptr)
    {
        v->p = u->p;
    }   
};

Node* tMin(Node* x){
    while (x->l!= nullptr)
    {
        x= x->l;
    }
    return x;
}

void dbn(BSTree* T, Node* z){
    if (z->l == nullptr)
    {
        ts(T, z, z->r);
    }
    else if (z->r == nullptr)
    {
        ts(T, z, z->l);
    }
    else{
        Node* y = tMin(z->r);
        if (y->p != z)
        {
            ts(T, y, y->r);
            y->r = z->r;
            y->r->p = y;
        }
        ts(T, z, y);
        y->l = z->l;
        y->l->p = y;
    }
};

void oin(Node* root){
    if (root == nullptr){
        return;
    }
    oin(root->l);
    cout << root->value << endl;
    oin(root->r);
};
void opre(Node *root){
    if (root == nullptr){
        return;
    }
    cout << root->value << endl;
    opre(root->l);
    opre(root->r);
};
void opost(Node *root){
    if (root == nullptr){
        return;
    }
    
    opost(root->l);
    opost(root->r);
    cout << root->value << endl;
}

Node* search (Node* x, int k){
    if (x == nullptr || k == x->value) return x;
    if (k < x->value) return search(x->l, k);
    else return search(x->r, k);
};


int main(){
    BSTree* tree = new BSTree();
    tree->root = nullptr;
    string input;

    while (input != "e")
    {
        cin >> input;
        if (input[0] == 'i')
        {
            if (input.size() > 1)
            {
                insert(tree, (stoi(input.substr(1))));
            }
        }
        else if (input[0] == 'd')
        {
           
            Node* a = search(tree->root,  stoi(input.substr(1)));
            dbn(tree, a);
        }
        else if (input == "opre")
        {
            opre(tree->root);
        }
        else if (input == "opost")
        {
            opost(tree->root);
        }
        else if (input == "oin")
        {
            oin(tree->root);
        }
    }
    return 0;
};
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct Node{
    int key;
    Node* l;
    Node* r;
    Node* p;
    Node(int k): key(k), l(nullptr), r(nullptr), p(nullptr){}
};

struct Tree{
    Node* root = nullptr;

    Node* tMin(Node* x){
        while (x->l)
        {
            x = x->l;
        }
        return x;
    };
    void ts (Node* u, Node* v){
        if (u->p == nullptr)
        {
            root = v;
        }
        else if (u == u->p->l)
        {
            u->p->l = v;
        }
        else {
            u->p->r = v;
        }
        if (v != nullptr)
        {
            v->p = u->p;
        }
    }
    void insert(int k) {
        Node* z = new Node(k);
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr)
        {
            y = x;
            if (z->key < x->key)
            {
                x = x->l;
            }
            else{
                x = x->r;
            }
           
        };
         z->p = y;
            if (y == nullptr)
        root = z;
        else if (z->key < y->key)
            y->l = z;
        else
            y->r = z;
    }

    Node* search(Node* x, int k){
        if (x == nullptr || k == x->key) return x;
        if (k < x->key) return search(x->l, k);
        else return search(x->r, k);
    }

    void dbt(Node* z) {
        if (z == nullptr) return;

        if (z->l == nullptr)
            ts(z, z->r);
        else if (z->r == nullptr)
            ts(z, z->l);
        else {
            Node* y = tMin(z->r);
            if (y->p != z) {
                ts(y, y->r);
                y->r = z->r;
                y->r->p = y;
            }
            ts(z, y);
            y->l = z->l;
            y->l->p = y;
        }
        delete z;
    }

    void oin(Node* x) {
        if (!x){
            return;
         }
        oin(x->l);
        cout << x->key << "\n";
        oin(x->r);
    }

    void opre(Node *root){
        if (!root){
            return;
        }
        cout << root->key << "\n";
        opre(root->l);
        opre(root->r);
    };
    void opost(Node *root){
        if (!root){
            return;
        }
        opost(root->l);
        opost(root->r);
        cout << root->key << "\n";
    }
    void poin(){oin(root);};
    void popre(){opre(root);};
    void ppost(){opost(root);};
};

int main(){
    Tree t;
    string input;
    while (cin >> input)
    {
        if (input[0] == 'e')
        {
            break;
        }
        else if (input[0] == 'i')
        {
            if (input.size() > 1)
            {
                int key = stoi(input.substr(1));
                t.insert(key);
            }
        }
        else if (input[0] == 'd')
        {
                int key = stoi(input.substr(1));
                Node*a = t.search(t.root, key);
                t.dbt(a);
        }
         else if (input == "opre")
        {
            t.popre();
        }
        else if (input == "opost")
        {
            t.ppost();
        }
        else if (input == "oin")
        {
            t.poin();
        }
        
        
        
    }
    

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct node {
        int val;
        node* parrent;

        node(int key){
            val = key;
          
            parrent = nullptr;
        };
        
        node* traverse (node* tNode){
            while (tNode->parrent != nullptr)
            {
                tNode = tNode->parrent;
            }
            return tNode;
        };

        node* delNode(node* head, int pos){
            node* tNode = head;
            if (pos == 0)
            {
                head = head->parrent;
                delete tNode;
                return head;
            }

            node* prev;

            for (int i = 0; i < pos; i++)
            {
                prev = tNode;
                tNode = tNode->parrent;
            }
            prev->parrent = tNode->parrent;
            delete tNode;

            return head;
        }

        void prepend(node*&head, int key){
            
            node* temp;
            temp = new node(key);
            temp->parrent = head;
            head = temp; 
        };
}node;

class hashTable{
    private:
       
        int size;
        int ndx;
        int aPos[2] = {0,0};
        node** container;
        string msgF = "FOUND_AT";
        string msgD = "DELETED;";
        string erNF = "NOT_FOUND;";
        string erDF = "DELETE_FAILED;";
    public:    
        hashTable(int key);
        int hashKey(int key);
        void insert(int key);
        void del(int key);
        int find(int key);
        void search(int kase);
        void output();
       
};

hashTable::hashTable(int key){
    container = new node*[key];
    for (int i = 0; i < key; i++)
    {
        container[i] = nullptr;
    }
    size = key;
};

int hashTable::hashKey( int key){
    ndx = (key % size);
    return ndx;
};

void hashTable::insert(int key){
    node* tempNode;
    int x = hashKey(key);
    container[x]->prepend(container[x], key);  
};

int hashTable::find(int key){
    int x = hashKey(key);
    node* head = container[x];
    aPos[0] = x;
    aPos[1] = 0; 

    while (head != nullptr)
    {
        if (head->val == key)
        {
            
            return 3;
        }
        head = head->parrent;
        aPos[1]++;
    }
    
    return 0;
};

void hashTable::output(){
    node* tNode;
    for (int i = 0; i < size; i++)
    {
        tNode = container[i];
        cout << i  << ":";
        while (tNode != nullptr)
        {
            cout << tNode->val << "->";
            tNode = tNode->parrent;
        }
        if (tNode == nullptr)
        {
            cout << ";" << endl;
        }
        
    }
};

void hashTable::del(int key){
    find(key);
    container[ndx] = container[ndx]->delNode(container[ndx], aPos[1]);
    search(2);
};

void hashTable::search(int kase){
    if (kase == 0)
    {
        cout << erNF << endl;
    }
    else if (kase == 1)
    {
        cout << erDF << endl;
    }
    else if (kase == 2)
    {
        cout << msgD << endl;
    }
    else if (kase == 3)
    {
        cout << msgF << aPos[0] << "," << aPos[1] << ";" <<endl;
    }
};


int main(){
    int size;
    cin >> size;
    hashTable hT(size);
    string input;
    int pxf;

    while(input != "e"){
        cin >> input;
        
        if (input[0] == 'd' && input.size()>1)
        {
            pxf = std::stoi(input.substr(1));
            if (hT.find(pxf) == 0)
            {
                cout<< pxf << ":";
                hT.search(1);
            }
            else{
            cout<< pxf << ":";
                hT.del(pxf);
            }
        }
        else if (input[0] == 's' && input.size() >1)
        {   
            pxf = std::stoi(input.substr(1));
            cout<< pxf << ":";
            hT.search(hT.find(pxf));
        }
        else if (input[0] == 'i' && input.size() > 1)
        {
            pxf = std::stoi(input.substr(1));
            hT.insert(pxf);
        }
        else if (input[0] == 'o')
        {

            hT.output();
        }
    }

    return 0;
}
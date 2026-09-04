#include <iostream>
#include <climits>
using namespace std;

int inf = INT_MAX;
int ngf = INT_MIN;

class node{
    public:
        int d; //Distance
        int p; //Parent
};

class edge{
    public:
        int u; //src Vect
        int v; //dest Vect
        int w; //edgeWeight
};
class graph{   
    public:
        string sInf = "INFINITY\n";
        bool xst = false;
        bool reach = true;
        int vCount;
        int eCount;
        edge* edges;
        node* verts;

        bool bellmanFord(int s);
        void InitSingSource(int s);
        void relax(int u, int v, int w);
        void printOutput( bool c);
        graph(int v, int e);
        void addEdge(int i,int u, int v, int w);
        ~graph();
};

graph::graph(int v, int e){
    this->vCount = v;
    this->eCount = e;
    this->verts = new node[v];
    this->edges = new edge[e];
};

graph::~graph(){
    delete[] verts;
    this->verts = nullptr;
        delete[] edges;
    this->edges = nullptr;
}

void graph::addEdge(int i, int u, int v, int w){
    edges[i].u = u;
    edges[i].v = v;
    edges[i].w = w;
    
}
void graph::InitSingSource(int s){
    for (int i = 0; i < vCount; i++  )
    {
        verts[i].d = inf;
        verts[i].p = -1;
    }
    verts[s].d = 0;
}

void graph::relax(int u, int v, int w){
    if (verts[u].d != inf){
        if (verts[v].d > (verts[u].d + w))
        {
            verts[v].d = verts[u].d + w;
            verts[v].p = u;
            
        }
    }
};

bool graph::bellmanFord(int s){
    InitSingSource(s);
    for (int i = 1; i < vCount-1; i++)
    {
        for (int j = 0; j < eCount; j++)
        {
            relax(edges[j].u, edges[j].v, edges[j].w);
        }
    }
    for (int i = 0; i < eCount; i++)
    {

        int u = edges[i].u;
        int v= edges[i].v;
        int w = edges[i].w;

        if (verts[u].d != inf){
            if (verts[v].d > verts[u].d + w){
                return false;
            }  
        }
    }
    return true;
};

void graph::printOutput( bool c){
    if (c == true)
    {
        cout <<"TRUE\n";
        for (int i = 0; i < vCount; i++)
        {
            if (verts[i].d == inf){
                cout << "INFINITY" << endl;
            }
            else{
                cout << verts[i].d << endl;
            }
        }
        
    }
    else{
    cout << "FALSE" << endl; 
    }
};


int main() {
    int edges, vects, t1, t2, t3, t4;

    cin >> vects >> edges;

    graph gMan(vects, edges);


    for (int i = 0; i < edges; i++)
    {
        cin >> t1 >> t2 >> t3;
        gMan.addEdge(i, t1, t2, t3);
    }
    
  
   gMan.printOutput( gMan.bellmanFord(0));

    return 0; 
}
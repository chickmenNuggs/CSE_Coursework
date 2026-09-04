#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class sccStuff
{
public:
    int verts;
    vector<vector<int>> adjL;
    vector<vector<int>> adjT;
    vector<bool> visited;
    stack<int> stk;

    sccStuff(int vert);
    void edger(int i, int vert);
    void fill(int vert);
    int min (const vector<int> &vect);
    void dfs(int vert, vector<int> &para);
    vector<int> getSCC();
};

sccStuff::sccStuff(int vert){
    this->verts = vert;
    adjL.resize(vert);
    adjT.resize(vert);
    visited.resize(verts, false);
};

void sccStuff::edger(int x, int y){
    adjL[x].push_back(y);
    adjT[y].push_back(x); 
};

void sccStuff::fill(int vert){
    visited[vert] = true;
    for (int i : adjL[vert])
    {
        if (visited[i]) continue;   

        fill(i);
    }
    stk.push(vert);
};

int sccStuff::min(const vector<int>& vec){
    int minVal = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < minVal)
            minVal = vec[i];
    }
    return minVal;
};

void sccStuff::dfs(int vert, vector<int>& para){
    this->visited[vert] = true;
    para.push_back(vert);

    for (int i : adjT[vert])
    {
        if (visited[i]) continue;

        dfs(i, para);
    }
};

vector<int> sccStuff::getSCC(){
    
    for (int i = 0; i < verts; i++)
    {
        if (visited[i]) continue;

        fill(i);
    }

    for (int i = 0; i < verts; i++)
    {
        visited[i] = false;
    }

    vector<int> sccLabels(verts);
    while (!stk.empty())
    {
        int vert = stk.top();
        stk.pop();

        if (visited[vert]) continue;

        vector<int> para;
        dfs(vert, para);

        int minVertex = min(para);

        for (int i : para)
        {
            sccLabels[i] = minVertex;
        }
    }

    return sccLabels;
};


int main()
{
    int verts, edges;
    cin >> verts >> edges;

    sccStuff graph(verts);

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        graph.edger(x, y);
    }

    vector<int> sccLabels = graph.getSCC();

    for (int i = 0; i < verts; i++)
    {
        cout << sccLabels[i] << endl;
    }

    return 0;
}
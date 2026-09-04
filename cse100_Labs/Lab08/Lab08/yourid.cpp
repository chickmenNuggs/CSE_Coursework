#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph
{
public:
    int vertexCount;
    vector<vector<int>> adjacentList;
    vector<vector<int>> transposedAdjacentList;

    Graph(int v)
    {
        vertexCount = v;
        adjacentList.resize(v);
        transposedAdjacentList.resize(v);
    }

    void AddEdge(int u, int v)
    {
        adjacentList[u].push_back(v);
        transposedAdjacentList[v].push_back(u); 
    }

    void FillOrder(int v, vector<bool>& visited, stack<int>& stack)
    {
        visited[v] = true;
        for (int u : adjacentList[v])
        {
            if (visited[u]) continue;   

            FillOrder(u, visited, stack);
        }
        stack.push(v);
    }

    int Min(const vector<int>& vec)
    {
        int minVal = vec[0];
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] < minVal)
                minVal = vec[i];
        }
        return minVal;
    }

    void DFS(int v, vector<bool>& visited, vector<int>& component)
    {
        visited[v] = true;
        component.push_back(v);

        for (int u : transposedAdjacentList[v])
        {
            if (visited[u]) continue;

            DFS(u, visited, component);
        }
    }

    vector<int> GetSCCs()
    {
        stack<int> stack;
        vector<bool> visited(vertexCount, false);

        for (int i = 0; i < vertexCount; i++)
        {
            if (visited[i]) continue;

            FillOrder(i, visited, stack);
        }

        for (int i = 0; i < vertexCount; i++)
        {
            visited[i] = false;
        }

        vector<int> sccLabels(vertexCount);
        while (!stack.empty())
        {
            int v = stack.top();
            stack.pop();

            if (visited[v]) continue;

            vector<int> component;
            DFS(v, visited, component);

            int minVertex = Min(component);

            for (int u : component)
            {
                sccLabels[u] = minVertex;
            }
        }

        return sccLabels;
    }
};

int main()
{
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    Graph graph(vertexCount);

    for (int i = 0; i < edgeCount; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.AddEdge(u, v);
    }

    vector<int> sccLabels = graph.GetSCCs();

    for (int i = 0; i < vertexCount; i++)
    {
        cout << sccLabels[i] << endl;
    }

    return 0;
}

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class DirectedGraphSCC
{
private:
    int VertexCount;
    vector<vector<int>> AdjacencyList;
    vector<vector<int>> ReverseAdjacencyList;
    vector<bool> Visited;
    stack<int> FinishOrder;
    vector<int> SccIds;

    void DfsFirstPass(int vertex)
    {
        Visited[vertex] = true;

        for (int neighbor : AdjacencyList[vertex])
        {
            if (!Visited[neighbor])
            {
                DfsFirstPass(neighbor);
            }
        }

        FinishOrder.push(vertex);
    }

    int CollectSccAndFindMin(int vertex)
    {
        Visited[vertex] = true;
        int minVertex = vertex;

        for (int neighbor : ReverseAdjacencyList[vertex])
        {
            if (Visited[neighbor]) continue;

            int subMin = CollectSccAndFindMin(neighbor);
            
            if (subMin < minVertex)
            {
                minVertex = subMin;
            }
        }

        SccIds[vertex] = minVertex;
        return minVertex;
    }

    void CollectScc(int vertex, vector<int>& currentScc)
    {
        Visited[vertex] = true;
        currentScc.push_back(vertex);

        for (int neighbor : ReverseAdjacencyList[vertex])
        {
            if (Visited[neighbor]) continue;

            CollectScc(neighbor, currentScc);
        }
    }

public:
    DirectedGraphSCC(int vertexCount)
    {
        VertexCount = vertexCount;
        AdjacencyList.resize(vertexCount);
        ReverseAdjacencyList.resize(vertexCount);
        Visited.resize(vertexCount, false);
        SccIds.resize(vertexCount, -1);
    }

    void AddEdge(int from, int to)
    {
        AdjacencyList[from].push_back(to);
        ReverseAdjacencyList[to].push_back(from);
    }

    vector<int> ComputeSccs()
    {
        for (int i = 0; i < VertexCount; i++)
        {
            if (Visited[i]) continue;

            DfsFirstPass(i);
        }

        for (auto item : Visited)
        {
            item = false;
        }

        //fill(Visited.begin(), Visited.end(), false);

        while (!FinishOrder.empty())
        {
            int vertex = FinishOrder.top();
            FinishOrder.pop();

            if (Visited[vertex])  continue;

            CollectSccAndFindMin(vertex);
        }

        return SccIds;
    }
};

int main()
{
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    DirectedGraphSCC graph(vertexCount);

    for (int i = 0; i < edgeCount; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.AddEdge(u, v);
    }

    vector<int> sccIds = graph.ComputeSccs();

    for (int i = 0; i < vertexCount; i++)
    {
        cout << sccIds[i];
        if (i != vertexCount - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

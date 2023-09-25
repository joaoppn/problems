#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Graph
{

private:
    int V;
    map<int, vector<int>> adj;
    vector<bool> visited;
    vector<int> disc; // Descoberta mais cedo
    vector<int> low;  // Menor descoberta alcançável
    vector<int> parent;
    vector<pair<int, int>> bridges;
    int time;

public:
    Graph(int V) : V(V), visited(V, false), disc(V, 0), low(V, 0), parent(V, -1), time(0) {}

    void addVertex(int vertex)
    {
        if (adj.find(vertex) == adj.end())
        {
            adj[vertex] = vector<int>();
        }
    }

    void addEdge(int from, int to)
    {
        addVertex(from);
        addVertex(to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    void DFS(int u)
    {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                children++;
                parent[v] = u;
                DFS(v);

                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u])
                {
                    bridges.push_back({u, v});
                }
            }
            else if (v != parent[u])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void findBridgesAndArticulationPoints()
    {
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                DFS(i);
            }
        }
        cout << bridges.size();
        for (int i = 0; i < bridges.size(); i++)
        {
            if(bridges[i].first > bridges[i].second){
               swap(bridges[i].first, bridges[i].second);
            }
        }

        sort(bridges.begin(), bridges.end());
        for (int i = 0; i < bridges.size(); i++)
        {
            cout <<" " <<bridges[i].first << " " << bridges[i].second;
        }
    }
};

int main(int argc, char const *argv[])
{
    int m, n, x, y;
    cin >> m >> n;
    while (m != 0 && n != 0)
    {
        Graph links(m);
        while (n != 0)
        {
            cin >> x >> y;
            links.addEdge(x, y);
            n--;
        }
        links.findBridgesAndArticulationPoints();
        cout << "\n";
        cin >> m >> n;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a,
         pair<int, int> &b)
{
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

class Graph
{
private:
    int V;
    map<int, vector<int>> adj;
    vector<bool> visited;
    vector<int> disc; // Descoberta mais cedo
    vector<int> low;  // Menor descoberta alcançável
    vector<int> parent;
    map<int, int> articulationPoints;
    int time;

public:
    Graph(int V) : V(V), visited(V, false), disc(V, 0), low(V, 0), parent(V, -1), time(0) {}

    void addVertex(char vertex)
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
        articulationPoints[u] = 1;
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

                if (parent[u] == -1 && children > 1) {
                    vector<bool> visit(V, false);
                    articulationPoints[u] = aux_DFS(u, visit);
                }

                if (parent[u] != -1 && low[v] >= disc[u]) {
                    vector<bool> visit(V, false);
                    articulationPoints[u] = aux_DFS(u, visit);
                }
            }
            else if (v != parent[u])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    int aux_DFS(int a, vector<bool> &b){
        int pigeon =0;
        b[a] = true;
        for(int next: adj[a]){
            if(!b[next]){
                pigeon++;
                int guarda = aux_DFS(next, b);
            }
        }
        return pigeon;
    }

    void findBridgesAndArticulationPoints(int n)
    {
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                DFS(i);
            }
        }

        vector<pair<int, int>> points_order;

        for (const auto &point : articulationPoints)
        {
            points_order.push_back(point);
        }

        sort(points_order.begin(), points_order.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            cout << points_order[i].first << " " << points_order[i].second << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    int m, n, x, y;
    cin >> m >> n;
    while (m != 0 && n != 0)
    {
        Graph trains(m);
        cin >> x >> y;
        while (x != -1 && y != -1)
        {
            trains.addEdge(x, y);
            cin >> x >> y;
        }
        trains.findBridgesAndArticulationPoints(n);
        cout << "\n";
        cin >> m >> n;
    }
    return 0;
}

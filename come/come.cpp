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
    map<int, vector<int>> adj_inverse;
    vector<int> visited;
    int visits;

public:
    Graph(int A) : V(A+1), visited(V, false), visits(0) {}

    void addVertex(int vertex)
    {
        if (adj.find(vertex) == adj.end())
        {
            adj[vertex] = vector<int>();
            adj_inverse[vertex] = vector<int>();
        }
    }

    void addEdge_undirect(int from, int to)
    {
        addVertex(from);
        addVertex(to);
        adj[from].push_back(to);
        adj[to].push_back(from);
        adj_inverse[from].push_back(to);
        adj_inverse[to].push_back(from);
        //cout << "adicionado!"<<endl;
    }

    void addEdge_direct(int from, int to)
    {
        addVertex(from);
        addVertex(to);
        adj[from].push_back(to);
        adj_inverse[to].push_back(from);
        //cout << "adicionado"<<endl;
    }


    bool check()
    {
        if(V == 1){
            return true;
        }
        DFS(1);
        if (visits == V-1)
        {
       
            DFS_inverse(1);
            if (visits <= 0)
            {
                return true;
            }
            //cout << "problema v2"<<endl;
            return false;
        }
       // cout << "problema v1"<<endl;
        return false;
    }

    void DFS(int a)
    {
        visited[a] = true;
        visits++;
        //cout << "Visiting["<<a<<"]  + 1 = "<<visits<<endl;
        for (auto next : adj[a])
        {
            //cout << "entrou"<< next << endl
            if (!visited[next])
            {
                DFS(next);
            }
        }
    }
    void DFS_inverse(int a)
    {
        visits--;
        //cout << "Visiting["<<a<<"]  - 1 = "<<visits<<endl;
        visited[a] = false;
        for (auto next : adj_inverse[a])
        {
            if (visited[next])
            {
                DFS_inverse(next);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int m, n, x, y, z;
    cin >> m >> n;
    

    while (m != 0 && n != 0)
    {
        Graph city(m);
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            //cout << "x= "<<x<<"  y = "<<y<<"  z="<<z<<endl;
            if (z == 1)
            {
                city.addEdge_direct(x, y);
            }
            else
            {
                city.addEdge_undirect(x, y);
            }
        }
        if(city.check()){
            cout<<"1"<<endl;
        }
        else{
            cout << "0"<<endl;
        }
    cin >> m >>n;
    }

    return 0;
}

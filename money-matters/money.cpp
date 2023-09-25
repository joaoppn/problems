#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Graph
{
public:
    int V;
    map<int, vector<int>> adj;
    vector<bool> visited;
    vector<int> divida;

public:
    Graph(int V) : V(V), visited(V, false) {}

    void addVertex(char vertex)
    {
        if (adj.find(vertex) == adj.end())
        {
            adj[vertex] = vector<int>();
        }
    }
    void add_d(int a)
    {
        divida.push_back(a);
    }

    void addEdge(int from, int to)
    {
        addVertex(from);
        addVertex(to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int DFS(int a, int r){
        visited[a] = 1;
        for (auto x: adj[a])
        {
            if(!visited[x]){
                r = DFS(x, r);
            }
        }
        return r+divida[a];
        
    }
};

int main(int argc, char const *argv[])
{
    int n, m, money, amg_1, amg_2;
    cin >> n >> m; // input das variaveis n(numero de amigos) e m(numero de amizades)
    Graph amigos(n);

    for (int i = 0; i < n; i++) // adiciona a divida de cada amigo ao seu respectivo index e coloca todos os visited como falso.
    {
        cin >> money;
        amigos.add_d(money);
    }

    for (int i = 0; i < m; i++) // cria aresta entre dois amigos
    {
        cin >> amg_1 >> amg_2;
        amigos.addEdge(amg_1, amg_2);
    }

    for (int i = 0; i < n; i++)
    {
        if (amigos.visited[i] == 0)
        { // caso o amigo n tenha sido visitado, aciona a funcao dfs nele
            if (amigos.dfs(i, 0) == 0)
            {
                continue;
            } // para cada ciclo no grafo verifica se é possivel quitar as dividas,caso algum ciclo de errado encerra o for
            else
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    cout << "POSSIBLE" << endl;

    return 0;
}

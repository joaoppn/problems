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
    vector<int> cores;

public:
    Graph(int A) : V(A+1), cores(V, false){}

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



    bool DFS(int a, int color)
    {
        cores[a] = color; //define a cor para esse vertice
        for (auto next : adj[a])
        {
            //cout << "entrou"<< next << endl
            if (cores[next] == 0) //caso o proximo n tenha cor definida
            {
                if(color == 1){
                    return DFS(next, 2); //chama a cor alternativa
                }
                else{
                    return DFS(next, 1); //chama a cor alternativa
                }
            }

            if(cores[next] == color){ //se a cor do prox for igual do atual retorna falso
                return false;
            }
        }
        return true; // se nenhum vertice adj tiver a msm cor retorna true
    }

};

int main(int argc, char const *argv[])
{
    int n_v,  n_a, a;
    cin >> n_v;
    while (n_v != 0) //rodando ate a entrada de n ser 0
    {
        Graph cores(n_v);
        cin>>n_a;  //pega numero de arestas
        for (int i = 0; i < n_a; i++) //adiciona arestas
        {
            int a, b;
            cin >> a >> b;      
            cores.addEdge(a,b);
            
        }
        if(cores.DFS(0, 0)){   //aciona a func dfs para resolver o problema
            cout << "BICOLORABLE."<<endl;
        }
        else{
            cout << "NOT BICOLORABLE."<<endl;
        }

        cin >> n_v;
        
    }
    
    return 0;
}

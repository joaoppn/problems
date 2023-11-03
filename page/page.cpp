#include <bits/stdc++.h>

using namespace std;

class Grafo
{
private:
    int N;
    map<int, vector<int>> adj;

public:
    Grafo(int a): N(a){}
    void addVertex(int vertex)
    {
        if (adj.find(vertex) == adj.end())
        {
            adj[vertex] = vector<int>();
            N = max(N, vertex);
        }
    }

    void addEdge(int from, int to)
    {
        addVertex(from);
        addVertex(to);
        adj[from].push_back(to);
    }
    
    int BFS(int start, int end){
        int path;
        int vertex;
        vector<int> visited(N+1, 0);
        vector<int> distance(N+1, INT_MAX);
        deque<int> fila = {start};
        distance[start] = 0;
        visited[start] = 1;
        if(start == end){
            return 0;
        }

        while (!fila.empty())
        {
            vertex = fila[0];
            path = distance[vertex];
            fila.pop_front();
            for(auto neighbour: adj[vertex]){
                if(neighbour == end){
                    return path+1;
                }
                if(!visited[neighbour] && distance[neighbour] >= path+1){
                    fila.push_back(neighbour);
                    distance[neighbour] = path + 1;
                    visited[neighbour] = 1;
                }
            }
        }

        return -1;
        
    }

    double media(){
        double soma=0;
        int count=0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if(i == j){
                    continue;
                }
                else{
                    int bfs = BFS(i, j);
                    if(bfs != -1){
                        soma += bfs;
                        count++;
                    }
                }
            }
            
        }
        double result = soma/count;

        return count > 0 ? soma / count : 0;
        
    }

};

int main(int argc, char const *argv[])
{
    int a, b, count =1;
    cin >> a >> b;
    setprecision(3);
    while (a != 0 && b != 0)
    {
        Grafo conexao(0);
        while(a != 0 && b !=0){
            conexao.addEdge(a,b);
            cin >> a >> b;
        }
        cout << "Case "<<count<<": average length between pages = "<<fixed<<setprecision(3)<< conexao.media()<<" clicks"<<endl;
        count++;
        cin >> a >>b;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


class Graph
{
private:
    int V;
    map<pair<int, int>, int> adjacencyList;
    vector<int> pais, rank;
    vector<pair<int, pair<int, int>>> sortedPairs;

public:
    Graph(int a) : V(a)
    {
        pais.assign(V+1, 0);
        for (int i = 0; i <= V; i++)
        {
            pais[i] = i;
        }
        
        rank.assign(V+1, 0);
    }

    void add(int a, int b, int c)
    {
        adjacencyList[make_pair(a, b)] = c;
    }

    int find(int i){
        while(i != pais[i]){i = pais[i];}
        return i;
    }

    bool isSameSet(int a, int b)
    {
        return find(a) == find(b);
    }

    void unionSet(int a, int b)
    {
        int x= find(a), y = find(b);
        if(rank[x]> rank[y]){pais[y] = x;}
        else{
            pais[x] = y;
            if(rank[x]==rank[y]){rank[y]++;}
        }
    }
    void print_pais(){
        for(auto a: pais){
            cout << a<< " ";
        }
        cout <<"\n";
    }

    void ordenar()
    {

        for (const auto &pair : adjacencyList)
        {                                                      //[<2,3>] = 5
            sortedPairs.emplace_back(pair.second, pair.first); //<5,<2,3>>
        }

        // Ordenando o vetor pelo valor (primeiro elemento do par)
        sort(sortedPairs.begin(), sortedPairs.end());
        reverse(sortedPairs.begin(), sortedPairs.end());
        
    }

    void resolve()
    {
        int loop=0;
        ordenar();
        for (auto x : sortedPairs)
        {
            int a = x.second.first;
            int b = x.second.second;
            if (!isSameSet(a, b))
            {
                unionSet(a, b);
            }
            else{
                loop += x.first;
            }
        }
        cout << loop<<endl;
    }
};

int main(int argc, char const *argv[])
{

    int d, n, m;
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        cin >> n >> m;
        Graph Ruas(n);
        for (int j = 0;j <m; j++)
        {
            int to, from, peso;
            cin >> from >> to >> peso;
            Ruas.add(from, to, peso);
        }
        Ruas.resolve();
        
    }
    

    return 0;
}
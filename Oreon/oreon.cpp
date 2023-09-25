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
    }

    void resolve()
    {
        ordenar();
        for (auto x : sortedPairs)
        {
            int a = x.second.first;
            int b = x.second.second;
            if (!isSameSet(a, b))
            {
                char a_ = 65 + x.second.first;
                char b_ = 65 + x.second.second;
                unionSet(a, b);
                cout << a_ << "-" << b_<< " " << x.first << endl;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        Graph cidade(m);
        cout << "Case " << i << ":\n";
        for (int j = -1; j < m; j++)
        {
            string pesos, peso;
            getline(cin, pesos);
            std::istringstream ss(pesos);
            int k = 0;
            while (getline(ss, peso, ','))
            {

                int peso_ = stoi(peso);
                if (peso_ > 0)
                {
                    cidade.add(j, k, peso_);
                    
                }
                k++;
            }
        }
        cidade.resolve();
    }

    return 0;
}

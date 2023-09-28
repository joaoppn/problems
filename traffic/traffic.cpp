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
    map<pair<int, int>, int> adjacencyList; //dicionario com arestas e pesos          
    vector<int> pais, rank; //vetor com os pais de cada verticie e seus ranks
    vector<pair<int, pair<int, int>>> sortedPairs; //vetor com as arestas organizzadas por peso

public:
    Graph(int a) : V(a)
    {
        pais.assign(V+1, 0);
        for (int i = 0; i <= V; i++)
        {
            pais[i] = i; //designa o proprio vertice como seu pai
        }
        
        rank.assign(V+1, 0); //designa 0 para todos os ranks
    }

    void add(int a, int b, int c)
    {
        adjacencyList[make_pair(a, b)] = c; //adiciona aresta no dic
    }

    int find(int i){
        while(i != pais[i]){i = pais[i];} //enquanto i = pais[i](não encontrou o pai ainda), torna o i=pais[i] para avancar para a proxima child ate achar o pai.
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
        reverse(sortedPairs.begin(), sortedPairs.end()); //inverte para que tenhamos ordem decrescente
        
    }

    int resolve()
    {
        int min=0;
        ordenar();
        for (auto x : sortedPairs)
        {
            int a = x.second.first;
            int b = x.second.second;
            if (!isSameSet(a, b)) //quando a aresta conecta valores que ainda n foram adicionados
            {
                unionSet(a, b); //fazemos um union
                min = x.first; //guardamos valor min
            }
            else{
                continue;
            }
        }
        return min; //quando ja tivermos colocados todos as arestas, retorna o valor min 
    }
};

int main(int argc, char const *argv[])
{

   int N, n, m, u, v, c;
   cin >> N;
   for (int i = 0; i < N; i++)
   {
    cin >>n >>m;
    Graph cidade(n);
    for (int j = 0; j < m; j++)
    {
        cin >> u >> v >>c;
        cidade.add(u,v,c);
    }
    cout<<"Case #"<<i+1<<": "<< cidade.resolve()<<endl;

    
   }
   
    

    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class DirectedGraph
{
private:
    std::map<char, std::vector<char>> adjacencyList;

public:
    void addVertex(char vertex)
    {
        if (adjacencyList.find(vertex) == adjacencyList.end())
        {
            adjacencyList[vertex] = std::vector<char>();
        }
    }

    void addEdge(char from, char to)
    {
        addVertex(from);
        addVertex(to);
        adjacencyList[from].push_back(to);
    }

    void printGraph()
    {
        for (const auto &entry : adjacencyList)
        {
            std::cout << entry.first << " -> ";
            for (char vertex : entry.second)
            {
                std::cout << vertex << " ";
            }
            std::cout << std::endl;
        }
    }

    void dfs(char vertex, std::unordered_set<char> &visited, std::vector<char> &result)
    {
        visited.insert(vertex);

        for (char adjacent : adjacencyList[vertex])
        {
            if (visited.find(adjacent) == visited.end())
            {
                dfs(adjacent, visited, result);
            }
        }

        result.push_back(vertex);
    }

    std::vector<char> topologicalSort()
    {
        std::unordered_set<char> visited;
        std::vector<char> result;

        for (const auto &entry : adjacencyList)
        {
            if (visited.find(entry.first) == visited.end())
            {
                dfs(entry.first, visited, result);
            }
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{

    string input;

    while (cin >> input)
    {
        DirectedGraph graph;

        vector<string> palavras;

        cin >> input;
        while (input != "#")
        {
            palavras.push_back(input);
            cin >> input;
        }

        for (int i = 0; i < palavras.size(); i++)
        {
            string palavra1 = palavras[i];
            for (int j = 1; j + i < palavras.size(); j++)
            {
                string palavra2 = palavras[i + j];
                for (int h = 0; h < min(palavra1.size(), palavra2.size()); h++)
                {
                    if (palavra1[h] != palavra2[h])
                    {
                        graph.addEdge(palavra1[h], palavra2[h]);
                        break;
                    }
                    continue;
                }
            }
        }

        vector<char> result = graph.topologicalSort();
        for (char i : result)
        {
            cout << i;
        }
        cout<<endl;
    }

    return 0;
}

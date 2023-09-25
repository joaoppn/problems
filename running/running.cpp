#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Graph {
private:
    unordered_map<string, vector<string>> adjacencyList;

public:
    void addVertex(const string& vertex) {
        adjacencyList[vertex] = vector<string>();
    }

    void addEdge(const string& from, const string& to) {
        adjacencyList[from].push_back(to);
    }

    bool check_loop(string a) {
        unordered_map<string, bool> visited;
        unordered_map<string, bool> recursionStack;

            if (check_loopDFS(a, visited, recursionStack)) {
                return true;
            }

        return false;
    }

private:
    bool check_loopDFS(const string& vertex, unordered_map<string, bool>& visited, unordered_map<string, bool>& recursionStack) {
        visited[vertex] = true;
        recursionStack[vertex] = true;

        for (const string& adjacent : adjacencyList[vertex]) {
            if (!visited[adjacent] && check_loopDFS(adjacent, visited, recursionStack)) {
                return true;
            } else if (recursionStack[adjacent]) {
                return true;
            }
        }

        recursionStack[vertex] = false;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    Graph voos;
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        string cid1, cid2;
        cin >> cid1 >> cid2;
        voos.addEdge(cid1, cid2);
    }
    string input;
    while(cin >> input){
        if(voos.check_loop(input)){
            cout << input << " safe"<<endl;
        }
        else {
            cout << input << " trapped"<<endl;
        }
    }
    
    
    return 0;
}

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Estrutura auxiliar para armazenar combinações como um inteiro.
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        int number = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
        return hash<int>()(number);
    }
};

// Estrutura auxiliar para comparar vetores de inteiros.
struct VectorEqual {
    bool operator()(const vector<int>& v1, const vector<int>& v2) const {
        return v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2] && v1[3] == v2[3];
    }
};

unordered_set<vector<int>, VectorHash, VectorEqual> proibidosSet;

vector<vector<int>> adj(const vector<int>& init) {
    vector<vector<int>> result;
    for (int i = 0; i < 4; ++i) {
        for (int d : {1, -1}) {
            vector<int> newComb = init;
            newComb[i] = (newComb[i] + d + 10) % 10;
            result.push_back(newComb);
        }
    }
    return result;
}

int vectorToInt(const vector<int>& v) {
    return v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
}

int BFS(const vector<int>& start, const vector<int>& end) {
    if (proibidosSet.count(start) || proibidosSet.count(end)) return -1;
    if (start == end) return 0;

    unordered_set<vector<int>, VectorHash, VectorEqual> visited;
    deque<vector<int>> queue;
    queue.push_back(start);
    visited.insert(start);

    int steps = 0;
    while (!queue.empty()) {
        ++steps;
        int size = queue.size();
        while (size--) {
            vector<int> current = queue.front();
            queue.pop_front();

            for (auto& next : adj(current)) {
                if (proibidosSet.count(next) || visited.count(next)) continue;
                if (next == end) return steps;
                queue.push_back(next);
                visited.insert(next);
            }
        }
    }
    return -1;
}

int main() {
    int n, digit, numProibidos;
    cin >> n;

    while (n--) {
        vector<int> start(4), end(4);
        for (int& d : start) cin >> d;
        for (int& d : end) cin >> d;

        cin >> numProibidos;
        proibidosSet.clear();
        for (int i = 0; i < numProibidos; ++i) {
            vector<int> proibido(4);
            for (int& d : proibido) cin >> d;
            proibidosSet.insert(proibido);
        }

        cout << BFS(start, end) << endl;
    }
    return 0;
}

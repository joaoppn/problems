#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> mov(pair<int, int> pos, int X, int Y)
{
    vector<pair<int, int>> possible = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<pair<int, int>> result;
    for (auto x : possible)
    {
        pair<int, int> newpos = {pos.first + x.first, pos.second + x.second};
        if (newpos.first >= 0 && newpos.first < X && newpos.second >= 0 && newpos.second < Y)
        {
            result.push_back(newpos);
        }
    }
    return result;
}

int BFS(vector<vector<int>> &grid, int X, int Y, pair<int, int> start, pair<int, int> end)
{
    vector<vector<int>> distance(X, vector<int>(Y, INT_MAX));
    distance[start.first][start.second] = 0;

    deque<pair<int, int>> fila = {start};

    while (!fila.empty())
    {
        pair<int, int> vertex = fila[0];
        int path = distance[vertex.first][vertex.second];
        fila.pop_front();
        for (auto neighbour : mov(vertex, X, Y))
        {
            if (neighbour == end)
            {
                return  path+1;
            }
            if (!grid[neighbour.first][neighbour.second] && path+1 <= distance[neighbour.first][neighbour.second])
            {
                distance[neighbour.first][neighbour.second] = path+1;
                fila.push_back(neighbour);
                grid[neighbour.first][neighbour.second] = 2;
            }
        }
        
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int X, Y, bombs, r, n, l;
    cin >> X >> Y;
    while (X != 0 && Y != 0)
    {
        vector<vector<int>> grid(X, vector<int>(Y, 0));
        cin >> bombs;
        for (int i = 0; i < bombs; i++)
        {
            cin >> r;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                cin >> l;
                grid[r][l] = 1;
            }
        }
        pair<int, int> start, end;
        int a, b;
        cin >> a >> b;
        start = make_pair(a, b);
        cin >> a >> b;
        end = make_pair(a, b);
        cout << BFS(grid, X, Y, start, end) << endl;
        cin >> X >> Y;

    }
    return 0;
}

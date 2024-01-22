#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{   
    int count = 1;
    int n,m;
    vector<pair<int,int>> moves = { {0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    cin >> n >> m;
    while(n != 0 and m != 0){
        vector<vector<int>> matriz(n, vector<int>(m, 0));
        for(int x=0; x<n; x++){
            for(int y=0;y<m;y++){
                char symbol;
                cin >> symbol;
                if(symbol == '*'){
                    for(auto move: moves){
                        if(x+move.first >=0 and x+move.first < n and y+move.second >=0 and y+move.second<m and matriz[x+move.first][y+move.second] != -1){
                            matriz[x+move.first][y+move.second]++;
                        }
                    }
                    matriz[x][y] = -1;
                }
            }
        }
        cout<<"Field #"<<count<<":\n";
        count++;
        for(int x=0; x<n; x++){
            for(int y=0;y<m;y++){
                if(matriz[x][y] == -1){
                    cout << '*';
                }
                else{
                    cout <<matriz[x][y];
                }
            }
            cout<<"\n";
        }
        

        cin >> n >> m;
        if( n != 0){
            cout << "\n";
        }
    }
    return 0;
}

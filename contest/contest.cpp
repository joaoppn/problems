#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >>n >>m;

    while (n != 0 & m!=0)
    {
         vector<int> players(n, 0);
    vector<int> problems(m, 0);
    vector<int> rules(4, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            if(x==1){
                players[i]++;
                problems[j]++;
            }
            
        }
        
    }

    for(auto x: players){
        if(x == m){
            rules[0] = 1;
        }
        if(x == 0){
            rules[3] = 1;
        }
    }

    for(auto x: problems){
        if(x == 0){
            rules[1] = 1;
        }
        if( x == n){
            rules[2] = 1;
        }
    }
    int result =0;

    for(auto x: rules){
        if(x == 0){
            result ++;
        }
    }
    cout << result<<endl;
    cin >>n>>m;
    }
    
   

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string instruct;
        cin >> instruct;
        if (instruct == "fechou")
        {
            n +=1;           
        }
        if(instruct == "clicou"){
            n -=1;
        }
        
    }
    cout << n << endl;
    return 0;
}

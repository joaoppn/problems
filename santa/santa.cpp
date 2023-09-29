#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, good=0, bad=0;
    vector<string> nomes;
    string status, nome;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> status >> nome;
        nomes.push_back(nome);
        if(status == "+"){
            good++;
        }
        else{
            bad++;
        }
    }

    sort(nomes.begin(), nomes.end());
    for(auto x: nomes){
        cout << x<<endl;
    }
    cout<<"Se comportaram: "<<good;
    cout<<" | Nao se comportaram: "<<bad<<endl;
    
    return 0;
}
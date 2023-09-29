#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, number;
    vector<int> par, impar;
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        if(number%2 == 0){
            par.push_back(number);
        }
        else{
            impar.push_back(number);
        }
    }

    sort(par.begin(), par.end());
    for(const auto x: par){
        cout<<x<<"\n";
    }
    sort(impar.begin(), impar.end());
    reverse(impar.begin(), impar.end());
        for(const auto x: impar){
        cout<<x<<"\n";
    }


    

    return 0;

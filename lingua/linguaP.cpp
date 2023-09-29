#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool possible = false;
    string frase, newfrase;
    getline(cin, frase);
    for (int i = 1; i < frase.length(); i= i+2)
    {
        if(i+1 <= frase.length() & frase[i+1] == ' '){
            cout<<frase[i];
            cout<<' ';
            i=i+1;
        }
        else{
             cout<<frase[i];
        }
       
      
        
    }
     cout<<"\n";

    return 0;
}
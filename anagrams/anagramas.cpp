#include <bits/stdc++.h>

using namespace std;


string transform(string input){
    int tam = input.size();
    for(int i =0; i< tam; i++){
        input[i] = tolower(input[i]);
    }
    return input;
}

int main(int argc, char const *argv[])
{
    set<string> saida;
    unordered_map<string,string> anagrams;
    string entrada;
    cin >> entrada;
    while(entrada != "#"){
        string aux = entrada;
        entrada = transform(entrada);
        sort(entrada.begin(), entrada.end());
        if(anagrams.find(entrada)  == anagrams.end()){
            saida.insert(aux);
            anagrams[entrada] = aux;
        }
        else{
            if(saida.find(anagrams[entrada]) != saida.end()){
                saida.erase(saida.find(anagrams[entrada]));
            }
            
            anagrams[entrada] = aux;
        }
        cin>> entrada;
        
    }   
    for(auto palavra: saida) {
        cout<<palavra<<"\n";
    }
    return 0;
}

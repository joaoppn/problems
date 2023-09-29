#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    
    while (getline(cin, input))
    {
        if(input == ""){
            return 0;
        }
        stack<char> teste;

        for (auto x : input)
        {
            if (x == '(')
            {
                teste.push('(');
            }
            else if (x == ')')
            {
                if(teste.empty()){
                    teste.push(')');
        
                }
                else{
                    teste.pop();
                }
            }
        }
        if(teste.empty()){
            cout<<"correct\n";
        }
        else{
            cout<<"incorrect\n";

        }
    }

    return 0;
}
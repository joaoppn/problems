#include <iostream>
 
using namespace std;
 
int main() {
 
    string msg, codigo;

    cin >> msg;
    cin >> codigo;
    int num=0;
    bool ok;

    for (int i = 0; i < msg.size() - codigo.size()+1; i++)
    {
        ok = true;
        for (int j = 0; j < codigo.size(); j++)
        {
            if(codigo[j] == msg[i+j]){
                ok = false;
            }

        }
       if(ok){
        num++;
       }

    }
    cout<<num<<"\n";

    return 0;

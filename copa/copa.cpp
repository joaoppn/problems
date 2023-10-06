#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x, y;
    vector<int> oitava, quarta, semi;
    for (int i = 0; i < 16; i += 2)
    {
        cin >> x >> y;
        if (x > y)
        {
            oitava.push_back(i);
        }
        else
        {
            oitava.push_back(i + 1);
        }
    }
    for (int i = 0; i < 8; i+=2)
    {
        cin >> x >> y;
        if (x > y)
        {
            quarta.push_back(oitava[i]);
        }
        else
        {
            quarta.push_back(oitava[i+1]);
        }
    }
    for (int i = 0; i < 4; i+=2)
    {
        cin >> x >> y;
        if (x > y)
        {
            semi.push_back(quarta[i]);
        }
        else
        {
            semi.push_back(quarta[i+1]);
        }
    }
    int resultado;
    cin >>x>>y;
    if(x>y){
        resultado = semi[0];
    }
    else{
        resultado = semi[1];
    }
    string alfabeto = "ABCDEFGHIJKLMNOP";
    cout << alfabeto[resultado]<<endl;
    

    return 0;
}

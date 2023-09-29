#include <bits/stdc++.h>

using namespace std;

int main()
{

    string entrada;

    cin >> entrada;
    if(entrada == "XOX"){
        cout << "*\n";
        return 0;
    }
    else if (entrada == "OXO")
    {
        cout << "?\n";
        return 0;
    }
    else if (entrada == "OOX")
    {
        cout << "?\n";
        return 0;
    }
    else if (entrada == "XOO")
    {
        cout << "?\n";
        return 0;
    }
        else if (entrada == "OOO")
    {
        cout << "?\n";
        return 0;
    }
        else if (entrada == "XXX")
    {
        cout << "?\n";
        return 0;
    }
    else {
        cout <<"Alice\n";
        return 0;
    }
    
    return 0;

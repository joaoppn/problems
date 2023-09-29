#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    map<int, int> numbers;
    int n,x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        numbers[x]++;
    }
    
    for(auto value: numbers){
        cout << value.first << " aparece "<< value.second << " vez(es)\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, c, s, x;
    int pos=1, result=0;
    cin >> n >> c >> s;
    if(s==1){
        result = 1;
    }
    for (int i = 0; i < c; i++)
    {
        cin >> x;
        if(pos+x > n){
            pos = 1;
        }
        else if (pos + x < 1)
        {
            pos = n;
        }
        else{
            pos = pos+x;
        }

        if(pos == s){
            result++;
        }
        
    }
    cout << result;
    

    return 0;
}
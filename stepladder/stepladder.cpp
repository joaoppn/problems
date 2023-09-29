#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, diff=-1000, count=0;
    cin >> n;
    int y;
    cin >> y;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        if(x-y != diff){
            count++;
            diff = x-y;
        }
        y=x;

    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    cout <<count<<"\n";
    
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
   int n, carlos;
   cin >>n;
   cin>>carlos;
   for (int i = 0; i < n-1; i++){
    int x;
    cin >> x;
    if(x>carlos){
        cout<<"N"<<endl;
        return 0;
    }
   }
   cout << "S"<<endl;

   

    return 0;
}

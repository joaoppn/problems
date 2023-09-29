#include <iostream>
 
using namespace std;
 
int main() {
 
    int n;
    int vel1;
    int vel2;
    cin >> n;
    cin >> vel1;
    for(int i = 2; i <= n;i++){
        cin >> vel2;
        if(vel1>vel2){
            cout << i<< "\n";
            return 0;
        }
        vel1 = vel2;
    }
    cout << 0 << "\n";
 
    return 0;

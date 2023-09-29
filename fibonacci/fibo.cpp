#include <iostream>
 
using namespace std;

unsigned long long fibonacci(int a){
    if(a == 0){
        return 0;}
    if(a == 1){
        return 1;
    }
    unsigned long long pri = 0;
    unsigned long long seg = 1;
    unsigned long long r;
    for (int i = 2; i <= a; i++)
    {
        r = pri + seg;
        pri = seg;
        seg = r;
    }
    return r;
    
}
 
int main() {
 
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        cout << "Fib("<<input<<") = "<<fibonacci(input)<<"\n";
    }
    
 
    return 0;

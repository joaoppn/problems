 #include <iostream>
#include <vector>
 
using namespace std;


bool check_troco(int troco){ //2, 5, 10, 20, 50 and 100.
vector<int> moedas = { 2,5,10,20,50,100};
for (int i = 0; i < 6; i++)
{
    for (int j = 0; j+i < 6; j++)
    {
        if(troco - moedas[i] - moedas[i+j] == 0){
            return true;
        }
    }
    
}
return false;


}
 
int main() {
 
    int n,m;
    cin >>n>> m;
    while (n != 0)
    {
        int troco = m-n;
        if(check_troco(troco)){
        cout << "possible\n";

        }
        else{
        cout << "impossible\n";
        }

        cin >> n >> m;

    }
   
    
    return 0;

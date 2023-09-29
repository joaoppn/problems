#include <iostream>
 
using namespace std;
 
int main() {
 
    int workers, steps;
    scanf("%d %d", &workers, &steps);

    

    int s[workers], result[workers];
    for (int i = 0; i < workers; i++)
    {
        scanf("%d", &s[i]);
        result[i] = 0;
    }

    for (int i = 0; i < steps; i++)
    {
        int last  = s[workers-1];
        for (int j = workers-1; j > 0; j--)
        {
            result[j] += s[j];
            s[j] = s[j-1];
        }
        result[0] += s[0];
        s[0] = last;

    }

    string resultado = "";
    for (int i = 0; i < workers; i++)
    {
       resultado = resultado + to_string(result[i]) + " ";
    }

    cout<<resultado<<endl;
    return 0;
}   
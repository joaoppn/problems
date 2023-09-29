#include <iostream>
 
using namespace std;
 
int main() {
    
    int size, points=0, control=-1, number, result=0;
 
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> number;
        if (number == control){
            points = points+1;
        }
        else{
            if(points>result){
                result = points;
            }
            points = 1;
            control = number;
        }  
        if(points>result){
            result = points;
        }
    }
        

    if(points > result){
        result = points;}    

    cout << result<<endl;;
    
 
    return 0;
}
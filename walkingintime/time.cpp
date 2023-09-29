#include <bits/stdc++.h>

using namespace std;

int main() {
  int x,y,z;
  cin >>x>>y>>z;
  if(x-y == 0){
    cout << "S\n";
    return 0;
  }
  else if(x-z == 0){
    cout << "S\n";
    return 0;
  }
  else if(z-y == 0){
    cout << "S\n";
    return 0;
  }
  else if(x-y-z == 0){
    cout << "S\n";
    return 0;
  }
  else if(-x+y-z == 0){
    cout << "S\n";
    return 0;
  }
  else if(-x-y+z == 0){
    cout << "S\n";
    return 0;
  }
  else if(x+y-z == 0){
    cout << "S\n";
    return 0;
  }
  else if(x-y+z == 0){
    cout << "S\n";
    return 0;
  }
  else if(-x+y+z == 0){
    cout << "S\n";
    return 0;
  }
 
  cout <<"N\n";

  return 0;

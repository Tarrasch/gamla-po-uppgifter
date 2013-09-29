#include <iostream>
using namespace std;
#include <cstdlib>

float divv(int t, int n){
  if(n==0)
  	abort();
  return (float)t/n; 
}

int main(){
  int t,n;
  cin >> t >> n;
  cout << divv(t,n) << endl; 
  return 0;
}

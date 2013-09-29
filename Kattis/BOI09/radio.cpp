#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int l;
string s;

int find_break(int length){
  for(int i = length ;i<l;i++)
    if(s[i]!=s[i%length])
      return i;
  cout << length << endl;
  exit(0);
}

int main(){
  cin >> l >> s;
  int al= 1;
  while(true){
    al=find_break(al)+1;
    }
  return 0;
}
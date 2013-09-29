using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define VI vector < int >
#define all(x) x.begin(), x.end()
#define tr(container,it) for(typeof((container).begin()) it=(container).begin(); (it)!= (container).end(); (it)++)

int main(){
  int n;
  cin >> n;
  VI roster(n);
  tr(roster, it)
    cin >> *it;
  VI orig = roster;
  int sum = accumulate(all(roster), 0);
  //Steg 1
  sort(all(roster), greater< int>());
  
  //Steg 2
  VI partyUsed(sum, -1);
  partyUsed.at(0)=0;
  tr(roster, it){
    for(int i=sum/2-1;i>=0;i--)
      if(partyUsed.at(i)>=0 && partyUsed.at(i+*it)==-1)
	partyUsed.at(i+*it)=it-roster.begin();
  }
  //Steg 3
  int best=0;
  for(int i=sum/2+1;i<sum;i++)
      if(partyUsed.at(i)>0)
	best=i;
  VI anvanda;
  int pos=best;
  while(pos>0){
    VI::iterator it=find(all(orig),roster.at(partyUsed.at(pos)));
    anvanda.push_back(it-orig.begin()+1);
    *it=-1;//så den inte hittas igen
    pos-=roster.at(partyUsed.at(pos));
    }
  cout << anvanda.size() << endl;
  tr(anvanda, it)
    cout << *it << ' ';
  
  return 0;
}

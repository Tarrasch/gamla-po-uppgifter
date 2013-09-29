using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

#define VI vector < int >
#define II pair < int, int >
#define II_I pair < II, int >
#define VII vector < II >
#define VVII vector < VII >
#define VVI vector < VI >
#define VVVI vector < VVI >
#define all(x) x.begin(), x.end()
#define tr(container,it) for(typeof((container).begin()) it=(container).begin(); (it)!= (container).end(); (it)++)

int main(){
  int t;
  cin >> t;
  const int xdiff[]={1,0,-1,0};
  const int ydiff[]={0,1,0,-1};
  for(;t;t--){
    int n;
    cin >> n;
    VVI block(n, VI (n, 0));
    II Astart, Bstart;
    for(int x=0;x<n;x++){
      for(int y=0;y<n;y++){
        char c;
        cin >> c;
        if(c=='A')
          Astart= II (x, y);
        if(c=='B')
          Bstart= II (x, y);
        if(c=='#')
          block[x][y]=true;
        }
      }
      
    VVI ADist(n, VI (n, -1));
    {//BFS för A
      VVI tagen(n, VI (n, 0));
      queue <II_I> q;
      q.push(II_I(Astart, 0));
      tagen[Astart.first][Astart.second]=true;
      while(!q.empty()){
        II_I g=q.front();
        II sq0=g.first;
        q.pop();
        ADist.at(sq0.first).at(sq0.second)= g.second;
        for(int i=0;i<4;i++){
          II sq=sq0;
          sq.first+=xdiff[i];
          sq.second+=ydiff[i];
          if(sq.first>=0 && sq.first<n && sq.second>=0  && sq.second<n && not block[sq.first][sq.second] && not tagen[sq.first][sq.second]){
            q.push( II_I(sq, g.second+1));
            tagen[sq.first][sq.second]=true; 
            }       
          }
        }
      }
    int D = ADist[Bstart.first][Bstart.second];
    int d = D/2;
    if(2*d!=D){
      cout << "A" << endl;
      continue;      
      }
      
    VVI BDist(n, VI (n, -1));
    {//BFS för B
      VVI tagen(n, VI (n, 0));
      queue <II_I> q;
      q.push(II_I(Bstart, 0));
      tagen[Bstart.first][Bstart.second]=true;
      while(!q.empty()){
        II_I g=q.front();
        II sq0=g.first;
        q.pop();
        BDist.at(sq0.first).at(sq0.second)= g.second;
        for(int i=0;i<4;i++){
          II sq=sq0;
          sq.first+=xdiff[i];
          sq.second+=ydiff[i];
          if(sq.first>=0 && sq.first<n && sq.second>=0  && sq.second<n && not block[sq.first][sq.second] && not tagen[sq.first][sq.second]){
            q.push( II_I(sq, g.second+1));
            tagen[sq.first][sq.second]=true; 
            }       
          }
        }
      }
      
    VVII LA(D+1), LB(D+1);
    VVI LA_indexed(n, VI(n,-1)), LB_indexed(n, VI(n,-1));
    for(int x=0;x<n;x++){
      for(int y=0;y<n;y++){
        if(ADist[x][y]+BDist[x][y]==D){
          LA_indexed[x][y]=LA[ADist[x][y]].size();
          LB_indexed[x][y]=LB[BDist[x][y]].size();
          LA[ADist[x][y]].push_back( II (x,y));
          LB[BDist[x][y]].push_back( II (x,y));
          }
        }
      }  
    
    VVVI T(d+1, VVI (n, VI (n, true)));
    tr(LA[d], itA)
      tr(LB[d], itB)
        T[0][itA-LA[d].begin()][itB-LB[d].begin()] = (*itA!=*itB);
    
    for(int k=1;k<=d;k++){
      tr(LA[d-k], itA){
        II sqA0=*itA;
        for(int i=0;i<4;i++){
          II sqA=sqA0;
          sqA.first+=xdiff[i];
          sqA.second+=ydiff[i];
          if(sqA.first>=0 && sqA.first<n && sqA.second>=0  && sqA.second<n && not block[sqA.first][sqA.second] && d-ADist[sqA.first][sqA.second]+1==k){
            tr(LB[d-k], itB){
              II sqB0=*itB;
              for(int i=0;i<4;i++){
	II sqB=sqB0;
	sqB.first+=xdiff[i];
	sqB.second+=ydiff[i];
	if(sqB.first>=0 && sqB.first<n && sqB.second>=0  && sqB.second<n && not block[sqB.first][sqB.second] && d-BDist[sqB.first][sqB.second]+1==k){
	  if(not T[k-1][LA_indexed[sqA.first][sqA.second]][LB_indexed[sqB.first][sqB.second]])
	    T[k][LA_indexed[sqA0.first][sqA0.second]][LB_indexed[sqB0.first][sqB0.second]]=false;
	  }
	}
              }       
            }
          } 
        }
      }
    if(T[d][0][0])
      cout << "A" << endl;
    else
      cout << "B" << endl;    
    }
  
  return 0;
}

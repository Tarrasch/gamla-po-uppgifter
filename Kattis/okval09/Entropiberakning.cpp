#include <iostream>
using namespace std;

int wsaved[18][18];
int w(int n, int e){
	if(wsaved[n][e]==-1){
		int kombs=0;
		for(int i=0;i<=e;i++)
			kombs+=w(n-1,i);		
		wsaved[n][e]=kombs;
	}
	return wsaved[n][e];	
}

int main(int argc, char** argv)
{
	for(int i=0;i<18;i++)
		for(int j=0;j<18;j++)
			wsaved[i][j]=-1;
			
	for(int i=0;i<18;i++)
		wsaved[0][i]=0;
	
	wsaved[0][0]=1;
	
	int n,e;
	cin >> n >> e;
	
	cout << w(n,e) << endl;
	return 0;
}

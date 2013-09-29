#include <iostream>
#include <vector>
using namespace std;

int W[100][100];

int main(int argc, char** argv)
{
	int n,v;
	cin >> n >> v;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
				W[i][j]=1000000;
			else
				W[i][i]=0;
	
	for(int i=0;i<v;i++){
		int p1, p2, vikt;
		cin >> p1 >> p2 >> vikt;
		p1--;p2--;
		W[p1][p2]=W[p2][p1]=vikt;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(W[j][i]+W[i][k] < W[j][k])
					W[j][k]=W[j][i]+W[i][k];
				}
			}
		}				

	int maxx=0;
	int fran,till;
	for(int f=0;f<n;f++){		
		for(int t=f+1;t<n;t++){
			if(maxx<W[f][t]){
				maxx=W[f][t];
				fran=f;
				till=t;
			}
		}
	}
	cout << fran+1 << ' ' << till+1 << ' ' << maxx << "00" << endl;
	
	return 0;
}

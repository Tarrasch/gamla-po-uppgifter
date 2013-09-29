#include <iostream>
#include <vector>
using namespace std;

struct Vag{
	int till,vikt;
};

vector<Vag> nod[100];

int main(int argc, char** argv)
{
	int n,v;
	cin >> n >> v;
	
	for(int i=0;i<v;i++){
		int p1,p2;
		int vikt;
		cin >> p1 >> p2 >> vikt;
		p1--;p2--;
		nod[p1].push_back((Vag){p2,vikt});
		nod[p2].push_back((Vag){p1,vikt});
	}
	int maxx=0;
	int fran,till;
	for(int cn=0;cn<n;cn++){
		bool tagen[100];
		for(int i=0;i<n;i++)
			tagen[i]=false;
		int avst[100];
		for(int i=0;i<n;i++)
			avst[i]=9999999;
		avst[cn]=0;
		int mo=cn;
		for(int i=0;i<n;i++){
			mo=0;
			for(int j=0;j<n;j++)//ta minsta asvtånd
				if( (avst[mo]>avst[j] || tagen[mo] ) && !tagen[j])
					mo=j;
			tagen[mo]=true;
			
			for(unsigned int j=0;j<nod[mo].size();j++){
				avst[nod[mo][j].till]=min(avst[nod[mo][j].till],avst[mo]+nod[mo][j].vikt);
			}
			
		}
		if(maxx<avst[mo]){
			maxx=avst[mo];
			fran=cn;
			till=mo;
		}
	}
	
	cout << fran+1 << ' ' << till+1 << ' ' << maxx << "00" << endl;
	
	return 0;
}

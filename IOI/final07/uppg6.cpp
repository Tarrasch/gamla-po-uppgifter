#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector <int> con[2500];

int rek(int node, int last){
	int maxx=1;
	for(int i=0;i<con[node].size();i++)
		if(con[node][i]!=last)
			maxx=max(maxx, (int)con[node].size()-1+rek(con[node][i],node));
	return maxx;
}

int main(int argc, char** argv)
{
	ifstream fin;
	fin.open("network5.dat");
	
	int n;
	fin >> n;
	for(int i=0;i<n-1;i++){
		int a,b;
		fin >> a >> b;
		a--;b--;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	
	int maxx=0;
	for(int i=0;i<n;i++){
		if(con[i].size()==1){
			maxx=max(maxx,1+rek(i,99999));
		}
	}		
	fin.close();
	
	cout << "Maximalt antal datorer: " << maxx;	
			
				
	return 0;
}

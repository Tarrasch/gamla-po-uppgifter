#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int c,v,n;
char inne[100][100];
int maxdepth;
int kvarav[256];
int kvar;
char *cps[100];


void rek(int d, int vaning, bool lastsucc){
	if(kvar==0){
		cout << "Antal onödiga varor: " << maxdepth-n;
		exit(0);
	}
	if(d==maxdepth)
		return;
		
	if(cps[vaning]>=inne[vaning]){
	char ch = *(cps[vaning]--);
	bool succ=false;
	if(kvarav[(int)ch]-->0){
		kvar--;
		succ=true;
	}
	rek(d+1, vaning, succ);
	if((++kvarav[(int)ch])>0){
		kvar++;
	}
	cps[vaning]++;	
}
	
	if(lastsucc && vaning<(v-1))
		rek(d, vaning+1, true);
}

int main(int argc, char** argv)
{
	ifstream fin;
	fin.open("godis5.dat");
	
	fin >> v >> c >> n;
	kvar=n;
	
	for(int i=0;i<v;i++){
		fin >> inne[i];
		cps[i]=inne[i]+c-1;
	}
	for(int i=0;i<256;i++)
		kvarav[i]=0;
		
	for(int i=0;i<n;i++){
		char a;
		fin >> a;
		kvarav[(int)a]++;
	}
	
	for(maxdepth=0;maxdepth<10000;maxdepth++){
		rek(0,0,true);
		cout << maxdepth << endl;
	}
	
	
	return 0;
}

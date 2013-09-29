#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

typedef char Strang[10];

struct Resa{
	int fran,till;
	int avstand;
};

int sortMyTeckenfalt (const void * a, const void * b)
{
if ( *(char*)a >  *(char*)b ) return 1; return -1;  
}

int sortMyResor (const void * a, const void * b){
  if ( (*(Resa*)a).avstand >  (*(Resa*)b).avstand ) return 1;
  if ( (*(Resa*)a).avstand == (*(Resa*)b).avstand ) return 0;
  if ( (*(Resa*)a).avstand <  (*(Resa*)b).avstand ) return -1;	
}


int sokMyTeckenfalt (const void * a, const void * b)
{

  if ( *(char*)a >  *(char*)b ) return 1;
  if ( *(char*)a == *(char*)b ) return 0;
  if ( *(char*)a <  *(char*)b ) return -1;
}

int main(int argc, char** argv)
{
	int n,m;
	cin >> n >> m;
	
	Strang stadfalt[200];
	
	for(int i=0;i<n;i++)
		cin >> stadfalt[i];
		
	
	qsort(stadfalt, n, 10, sortMyTeckenfalt);
	
	Resa resor[5000];
	
	for(int i=0; i<m;i++){
		char s1[10],s2[10];
		int avstand;
		char vag;
		cin >> s1 >> s2 >> avstand >> vag;
		resor[i].fran= ((char*)bsearch(s1, stadfalt, n, 10, sokMyTeckenfalt)-(char*)stadfalt)/10;
		resor[i].till= ((char*)bsearch(s2, stadfalt, n, 10, sokMyTeckenfalt)-(char*)stadfalt)/10;
		
		resor[i].avstand= avstand*(vag=='R');
		}
	
	qsort(resor, m, sizeof(Resa), sortMyResor);
	
	bool tagna[200];
	
	for(int i=0;i<n;i++)
		tagna[i]=true;
		
	int ntagna=0;
	int totresa=0;
	
	while(ntagna<n)
		if(
		
		
		
	

	return 0;
}

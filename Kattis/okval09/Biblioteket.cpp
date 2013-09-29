#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char** argv){

	int n,k;
	cin >> n >> k;
	
	int ntv=0;
	int tv[100];
	int nth=0;
	int th[100];
	*tv=0;*th=0;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		if(temp<0)
			tv[ntv++]=abs(temp);
		else if(temp>0)
			th[nth++]=abs(temp);
		}	
	qsort(tv, ntv, sizeof(int), compare);
	qsort(th, nth, sizeof(int), compare);	
	
	int ans=0;
	
	for(int i=0;i<nth;i++)	
		if((i%k)==((nth-1)%k) || i==(nth-1))
			ans+=2*abs(th[i]);

	for(int i=0;i<ntv;i++)	
		if((i%k)==((ntv-1)%k) || i==(ntv-1))
			ans+=2*abs(tv[i]);
	if(ntv==0)
		ntv++;			
	if(nth==0)
		nth++;			
	ans-=max(abs(tv[ntv-1]),abs(th[nth-1]));
	
	cout << ans << endl;

}

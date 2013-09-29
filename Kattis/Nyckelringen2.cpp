#include <iostream>
#include <string.h> 

using namespace std;

char ring[61];
int nycklar;

int main(int argc, char** argv)
{	
	
	
	
	
	cin >> ring;
	ring="ABCCBABCDBDEBBABCA";
	
	nycklar= strlen(ring);
			
	nyckeltyper=0;
	bool typer[6]={0,0,0,0,0,0};
	for(int i=0;i<nycklar;i++)
		if(!typer['F'-ring[i]]){
			typer['F'-ring[i]]=true;
			nyckeltyper++;
			}

	return 0;
}

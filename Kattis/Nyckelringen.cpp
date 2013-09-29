#include <iostream>
#include <string.h> 

using namespace std;

char blah[61];
char* ring=(char*)blah;
int nycklar;
int nyckeltyper;
char besokta[10000000][61];
int next=0;

inline char uc(char c){
	return c+('a'-'A')*('F'<c);
}

bool besokt(char* falt){
	for(int i=0;i<next;i++)
		if(strncasecmp(falt, besokta[i], nycklar)==0)
			return true;
	return false;
}

bool vinst(char* falt){		
	int shifts=0;
	for(int i=0;i<nycklar;i++){
		if(uc(falt[(i+1)%nycklar])!=uc(falt[i]))
			shifts++;
		}	
	return shifts==(nyckeltyper);	
}

int main(int argc, char** argv)
{	
	
	cout << strncasecmp("ADC", "ABC", 5);
	
	
	cin >> ring;
	ring="ABCDEFAB";
	
	nycklar= strlen(ring);
			
	nyckeltyper=0;
	bool typer[6]={0,0,0,0,0,0};
	for(int i=0;i<nycklar;i++)
		if(!typer['F'-ring[i]]){
			typer['F'-ring[i]]=true;
			nyckeltyper++;
			}
		
	int now;
	now=0;next=1;
	int djup=0;
	int nextdjup=next;
	strcpy(besokta[now],ring);
	
	while(now<next){
		if(now==nextdjup){
			djup++;
			nextdjup=next;
		}		
		ring=besokta[now];
		
		//if(now<50)
		cout << ring << " " << now << endl;
		for(int fran=0;fran<nycklar;fran++){
			if(ring[fran]>='A' && ring[fran]<='F' && ring[fran]!=ring[fran-1]){				
				char last='H';
				for(int till=0;till<nycklar;till++){
					if(till!=fran){
						for(int i=0;i<(nycklar-1);i++)
							besokta[next][i+(i>=fran)]=ring[i+(i>=till)];
						besokta[next][fran]=ring[till]+'a'-'A';
						besokta[next][nycklar]=NULL;
						
						if(now==0)
						cout << uc(ring[fran]);
						int pos=till;
						while(uc(besokta[next][(pos+nycklar)%nycklar])==uc(besokta[next][(--pos+nycklar)%nycklar]))
							besokta[next][(pos+nycklar)%nycklar]=uc(ring[fran])+'a'-'A';
						pos=till;
						while(uc(besokta[next][(pos+nycklar)%nycklar])==uc(besokta[next][(++pos+nycklar)%nycklar]))
							besokta[next][pos%nycklar]=uc(ring[fran])+'a'-'A';
						
						
						if(vinst(besokta[next])){
							cout <<	"Det krävs djup: " << djup+1;	
							return 0;
						}
						
						
						
						//if(!besokt(besokta[next]))
							next++;
					}
					last=uc(ring[till]);						
				}
			}
		}
	now++;		
	}
				
			
	return 0;
}

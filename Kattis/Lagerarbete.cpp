#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>


int avstandstabell[15][15];
int boxid_o_molid_ger_rackid[15][15];
int boxid_o_rackid_ger_molid[15][15];
int boxid_ger_dens_rack[15];
int rackbara[15];
int minsumma=100000;
int boxar=0;

bool tagen[15];	
int tagna=0;
int tagen_index[15];
int plats_tagen_av[15];
int starta_fran[15];

void sok(int d=0, int summa=0){
	if(boxar==d){
		minsumma=min(summa, minsumma);
		return;
		}
	if(summa>=minsumma)
		return;
		
	for(int i=0; i<d-1; ++i){
		int pd=d-1;
		int m=boxid_o_rackid_ger_molid[pd][boxid_ger_dens_rack[pd]];
		int n=boxid_o_rackid_ger_molid[i][boxid_ger_dens_rack[i]];
		if(boxid_o_molid_ger_rackid[pd][n]>=0){
			int m1=avstandstabell[pd][boxid_o_molid_ger_rackid[pd][m]];//nuvarande
			int m2=avstandstabell[pd][boxid_o_molid_ger_rackid[pd][n]];//för samma box som a1
			int n1=avstandstabell[i][boxid_o_molid_ger_rackid[i][m]];
			int n2=avstandstabell[i][boxid_o_molid_ger_rackid[i][n]];//nuvarande
			//cout << m1 << ' ' << m2 << ' ' << n1 << ' ' << n2 << ' ' << endl;
			if((true && m1+n2>m2+n1) || (m1+n2>=m2+n1 && m>n)){
				return;
			}
		}
	}
	
	for(int i=0; i<rackbara[d]; ++i){
		int molid=boxid_o_rackid_ger_molid[d][i];
		if(!tagen[molid]){
			tagen[molid]=true;	
			tagen_index[d]=molid;
			plats_tagen_av[molid]=d;
			boxid_ger_dens_rack[d]=i;
//			tagna++;
			sok(d+1, summa+avstandstabell[d][i]);
//			tagna--;
			tagen_index[d]=-1;
			plats_tagen_av[molid]=-1;
			tagen[molid]=false;

		}
	}
	
	/*
	if(tagen_index[d]==-1){
		/*	
		int& eget_x_index= boxid_o_rackid_ger_molid[d][at];
		int at=starta_fran[d];
		
		if(tagen[boxid_o_rackid_ger_molid[d][at]]){
			int den_index=plats_tagen_av[boxid_o_rackid_ger_molid[d][at]];
			int delta_avst_den= avstandstabell[den_index, starta_fran[den_index]+1]-avstandstabell[den_index, starta_fran[den_index]];
			int delta_avst_sjalv= avstandstabell[d, starta_fran[d]+1]-avstandstabell[d, starta_fran[d]];
			if(delta_avst_sjalv<delta_avst_den){//EJ KLART!!!!!!!!!!!
				tagen[boxid_o_rackid_ger_molid[d][at]]=true;	
				tagen_index[d]=boxid_o_rackid_ger_molid[d][at];
				plats_tagen_av[boxid_o_rackid_ger_molid[d][at]]=d;
				tagna++;
				sok(d+1);
			}
			else{
				
				
			}
		}
		*/
		/*
		int at=starta_fran[d];
		
		while(tagen[boxid_o_rackid_ger_molid[d][at]]){
			int tagen_av=plats_tagen_av[boxid_o_rackid_ger_molid[d][at]];		
			int den_tagit=tagen_index[tagen_av];		
			
			tagen_index[tagen_av]=-1;		
			tagen_index[d]=den_tagit;
			plats_tagen_av[den_tagit]=d;
			starta_fran[tagen_av]++;	
			
			sok(tagen_av);
			
			tagen_index[tagen_av]=den_tagit;		
			starta_fran[tagen_av]--;	
			tagen_index[d]=-1;
			plats_tagen_av[den_tagit]=tagen_av;		
			
			at++;
		}
		
		tagen[boxid_o_rackid_ger_molid[d][at]]=true;	
		tagen_index[d]=boxid_o_rackid_ger_molid[d][at];
		plats_tagen_av[boxid_o_rackid_ger_molid[d][at]]=d;
		tagna++;
		sok(d+1);
		tagna--;
		tagen_index[d]=-1;
		plats_tagen_av[boxid_o_rackid_ger_molid[d][at]]=-1;
		tagen[boxid_o_rackid_ger_molid[d][at]]=false;
	} 
	else sok(d+1);*/
}

int main(int argc, char** argv)
{
	int b, l;
	cin >> l >> b;
	
	int mol=0;	
	int boxplaceringar[15];
	int molindex[40][40];
	char spelplan[40][40];
	
	for(int i=0;i<l;i++){
		for(int j=0;j<b;j++){
			cin >> spelplan[j][i];
			}
		}
		
	for(int i=0;i<l;i++){
		for(int j=0;j<b;j++){
			if(spelplan[j][i]=='B')
				boxplaceringar[boxar++]=b*i+j;
			if(spelplan[j][i]=='X'){
				molindex[j][i]=mol++;
				}
			}
		}
		
	for(int i=0;i<boxar;i++){
		for(int j=0;j<boxar;j++){
			boxid_o_molid_ger_rackid[i][j]=-1;
		}
	}
		
	for(int i=0;i<boxar;i++){
		int now=0,next=1;
		int nextdjup=next;
		int djup=0;
		
		bool besokt[40*40];
		for(int a=0;a<(40*40);a++)
			besokt[a]=false;
						
		besokt[boxplaceringar[i]]=true;
		int stallen[40*40];		
		stallen[now]=boxplaceringar[i];
		
		rackbara[i]=0;
		
		while(now<next && rackbara[i]<boxar){
			if(now==nextdjup){
				djup++;
				nextdjup=next;
			}
			if(spelplan[stallen[now]%b][stallen[now]/b]=='X'){
				avstandstabell[i][rackbara[i]]=djup;
				boxid_o_rackid_ger_molid[i][rackbara[i]]=molindex[stallen[now]%b][stallen[now]/b];
				boxid_o_molid_ger_rackid[i][molindex[stallen[now]%b][stallen[now]/b]]=rackbara[i]++;
			}
			
			int nyruta;
			nyruta=stallen[now]+1;
			if(nyruta>=0 && nyruta<(b*l) && besokt[nyruta]==false && spelplan[nyruta%b][nyruta/b]!='#'
				&& ((nyruta%b)==(stallen[now]%b) || (nyruta/b)==(stallen[now]/b))){
				stallen[next++]=nyruta;
				besokt[nyruta]=true;
			}
			
			nyruta=stallen[now]-1;
			if(nyruta>=0 && nyruta<(b*l) && besokt[nyruta]==false && spelplan[nyruta%b][nyruta/b]!='#'
				&& ((nyruta%b)==(stallen[now]%b) || (nyruta/b)==(stallen[now]/b))){
				stallen[next++]=nyruta;
				besokt[nyruta]=true;
			}			
			
			nyruta=stallen[now]+b;
			if(nyruta>=0 && nyruta<(b*l) && besokt[nyruta]==false && spelplan[nyruta%b][nyruta/b]!='#'
				&& ((nyruta%b)==(stallen[now]%b) || (nyruta/b)==(stallen[now]/b))){
				stallen[next++]=nyruta;
				besokt[nyruta]=true;
			}			
			
			nyruta=stallen[now]-b;
			if(nyruta>=0 && nyruta<(b*l) && besokt[nyruta]==false && spelplan[nyruta%b][nyruta/b]!='#'
				&& ((nyruta%b)==(stallen[now]%b) || (nyruta/b)==(stallen[now]/b))){
				stallen[next++]=nyruta;
				besokt[nyruta]=true;
			}
			now++;
			
		}
		
	}
		
		for(int i=0;i<boxar;i++){
			tagen[i]=false;	
			tagen_index[i]=-1;
			plats_tagen_av[i]=-1;
			starta_fran[i]=0;
		}
	sok();
	
	cout << minsumma;			
	
	return 0;
}

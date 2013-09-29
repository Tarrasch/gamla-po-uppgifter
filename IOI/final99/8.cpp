/*
 *      final99u8.html
 *      
 *      Copyright 2008 arash1868 <arash1868@GYM008>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */


#include <iostream>
#include <fstream>
#include <stdint.h>
using namespace std;

struct entri{
	int x;
	int y;
	uint64_t pjaser;
	int d;
};

char peicemap[8][8];
bool movemap[8][8] ;
entri besokta[100000];
int nbesokta=0;
 uint64_t pjaser=0;
int sposx,sposy;
int molx,moly;



int besokt(uint64_t pjaser,int x, int y);
void nollmove();
void addmoves();
void addallmoves();
void sok(int d);

int besokt(uint64_t pjaser,int x, int y, int d) //returnerar d, ifall ej finns d=-1
{
	for(int i=0;i<nbesokta;i++)
		if(besokta[i].x==x && besokta[i].y==y && besokta[i].pjaser==pjaser && besokta[i].d>=d)
			return true;
	return false;
		
}

void nollmove(){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			movemap[i][j]=false;
}

void addmoves(int x, int y, int kx, int ky){
	if(0>x || x>7 || 0>y || y>7)
		return;
	movemap[x][y]=true;
	
	if((peicemap[x][y]=='.' || peicemap[x][y]=='*') && (kx!=0 || ky!=0))
		addmoves(x+kx, y+ky, kx, ky);
}

void addallmoves(){
	nollmove();
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			switch(peicemap[i][j]){
				case 'S':
						addmoves(i+2, j+1, 0,0);
						addmoves(i+2, j-1, 0,0);
						addmoves(i+1, j-2, 0,0);
						addmoves(i+1, j+2, 0,0);
						addmoves(i-1, j+2, 0,0);
						addmoves(i-1, j-2, 0,0);
						addmoves(i-2, j+1, 0,0);
						addmoves(i-2, j-1, 0,0);			
						break;
				case 'K':
						addmoves(i+1, j+1, 0,0);
						addmoves(i+1, j+0, 0,0);
						addmoves(i+1, j-1, 0,0);
						addmoves(i, j+1, 0,0);
						addmoves(i, j-1, 0,0);
						addmoves(i-1, j+1, 0,0);
						addmoves(i-1, j, 0,0);
						addmoves(i-1, j-1, 0,0);		
						break;
				case 'T':
						addmoves(i+1, j, 1,0);
						addmoves(i-1, j, -1,0);
						addmoves(i, j-1, 0,-1);
						addmoves(i, j+1, 0,1);	
						break;
						
				case 'L':
						addmoves(i+1, j+1, 1,1);
						addmoves(i-1, j-1, -1,-1);
						addmoves(i+1, j-1, 1,-1);
						addmoves(i-1, j+1, -1,1);	
						break;
						
				case 'D':
						addmoves(i+1, j+1, 1,1);
						addmoves(i-1, j-1, -1,-1);
						addmoves(i+1, j-1, 1,-1);
						addmoves(i-1, j+1, -1,1);	
						addmoves(i+1, j, 1,0);
						addmoves(i-1, j, -1,0);
						addmoves(i, j-1, 0,-1);
						addmoves(i, j+1, 0,1);		
						break;
				
			}
}		

int dragdettar;
void slutpunkt(){
	cout << endl << "det kostar " << dragdettar << " att komma till mål";
	exit(0);
};

void sok(int d){
	if(sposx==molx && sposy==moly)
		slutpunkt();
	if(d==0)
		return;
		
	if(besokt(pjaser,sposx,sposy,d))
		return;
		
	besokta[nbesokta++]=(entri){sposx,sposy,pjaser,d};
		
	int mlx[8];
	int mly[8];
	
	mlx[0]=sposx+1;
	mlx[1]=sposx+1;
	mlx[2]=sposx+2;
	mlx[3]=sposx+2;
	mlx[4]=sposx-1;
	mlx[5]=sposx-1;
	mlx[6]=sposx-2;
	mlx[7]=sposx-2;
	
	mly[0]=sposy+2;
	mly[1]=sposy-2;
	mly[2]=sposy+1;
	mly[3]=sposy-1;
	mly[4]=sposy-2;
	mly[5]=sposy+2;
	mly[6]=sposy+1;
	mly[7]=sposy-1;
	
	int sposx0=sposx;
	int sposy0=sposy;
	
	for(int i=0;i<8;i++){
		if(mlx[i]>=0 && mlx[i]<=7 && mly[i]>=0 && mly[i]<=7 && movemap[mlx[i]][mly[i]]==false){
		
		sposx=mlx[i];
		sposy=mly[i];
		
		if(peicemap[mlx[i]][mly[i]]!='.'){
			char temp=peicemap[mlx[i]][mly[i]];
			peicemap[mlx[i]][mly[i]]='.';
			addallmoves();
			pjaser-=(1 << mlx[i]) << (mly[i]*8);
			
	
		
			sok(d-1);
			pjaser+=(1 << mlx[i]) << (mly[i]*8);
			peicemap[mlx[i]][mly[i]]=temp;
			addallmoves();
		}
		else
		sok(d-1);
	}}
	
	sposx=sposx0;
	sposy=sposy0;
}

int main(int argc, char** argv)
{
	ifstream fin;
	fin.open("lidl");
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
		fin >> peicemap[j][7-i];
		
		
	addallmoves();
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			//cout << peicemap[i][j];
			//cout << movemap[j][7-i];
			if(peicemap[i][j]=='*'){
				molx=i;
				moly=j;
			}
			else
			if(peicemap[i][j]!='.'){
				pjaser+=(1 << i) << (j*8);
			}
			}}
		
	for(dragdettar=1;dragdettar<2000;dragdettar++){
		
		sposx=0;
		sposy=0;
		nbesokta=0;
		sok(dragdettar);
		
	}
	
	cout << "ingen väg på 2000 drag";
	
	return 0;
}

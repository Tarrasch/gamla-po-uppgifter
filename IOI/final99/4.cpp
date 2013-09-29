/*
 *      4.cpp
 *      
 *      Copyright 2008 arash <arash@arash-desktop>
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

using namespace std;

int maxx=0;


	int n=20;
	bool t[20];
	int k[20][3];
	int v[20][3][6];
	int m[20];
	
void slutpunkt(){
	cout << maxx;	
	exit(0);
}


void fora(int h, int b, int l, int forv, int kvar){
	if(h>maxx)
		maxx=h;
		
	if((forv-h)>kvar)
		return;
		
	if(h>=forv)
		slutpunkt();
	
	for(int i=0;i<n;i++)
		if(!t[i]){
			t[i]=true;
			for(int j=0;j<6;j++)
				if((v[i][1][j]<b) && (v[i][2][j]<l))
					fora(h+v[i][0][j],v[i][1][j],v[i][2][j],forv,kvar-m[i]);
			t[i]=false;
			}
	return;
}
				

			
int main(int argc, char** argv)
{
	ifstream fin;
	
	fin.open("lidl");
	
	
	fin >> n;
	
	
	for(int i=0;i<n;i++){
		t[i]=false;
		fin >> k[i][0];
		fin >> k[i][1];
		fin >> k[i][2];
		}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<6;j++){
			v[i][0][j]=k[i][j/2];
			}
		
			v[i][1][0]=k[i][1];
			v[i][2][0]=k[i][2];
			
			v[i][1][1]=k[i][2];
			v[i][2][1]=k[i][1];
			
			v[i][1][2]=k[i][0];
			v[i][2][2]=k[i][2];
			
			v[i][1][3]=k[i][2];
			v[i][2][3]=k[i][0];
			
			v[i][1][4]=k[i][0];
			v[i][2][4]=k[i][1];
			
			v[i][1][5]=k[i][1];
			v[i][2][5]=k[i][0];
		}
	int drillsum=0;
	
	for(int i=0;i<n;i++){
		m[i]=max(max(k[i][0],k[i][1]),k[i][2]);
		drillsum+=m[i];
	}
	
	int forv=drillsum;
	
	cout << drillsum;
	
	while(true){
		fora(0,51,51,forv,forv);
		forv--;
	}
	
	//cout << endl << maxx;	
	
	
	return 0;
}

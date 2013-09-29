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

using namespace std;

int matris[44][44];


int lista1[1000],lista2[1000];
int n1=0,n2=0;
#include <iostream>

void sok(int lista[],int &n, int x, int y, int xk, int yk){
	if(xk+x>=0 && yk+y>=0 && xk+x<=43 && yk+y<=43 && matris[x+xk][y+yk]){
		lista[n++]=matris[x+xk][y+yk];		
		sok(lista, n, x+xk, y+yk, xk, yk);		
	}
}
int main(int argc, char** argv)
{
	
	for(int x=0;x<=43;x++)
		for(int y=0;y<=43;y++)
			if((43-x-y)>0)
				matris[x][y]=0;
			else
				matris[x][y]=  (x+y-42)+(((y+1)*(y+1)+(y+1))/2-(y+1));
	
	
	
	int tal1,tal2;			
	cin >> tal1 >> tal2;	
	
	int x1=0,y1=0,x2=0,y2=0;
	
	
	
	cout << endl;
	while(matris[x1][y1]!=tal1){
		
		x1++;
		if(x1>=44){
			y1++;
			x1=0;
		}
	}
	while(matris[x2][y2]!=tal2){
		x2++;
		if(x2>=44){
			y2++;
			x2=0;
		}
	}
	
	
	if(x1!=x2){
		sok(lista1,n1,x1,y1,0,1);
		sok(lista1,n1,x1,y1,0,-1);
	}
	
	if(y1!=y2){
		sok(lista1,n1,x1,y1,1,0);
		sok(lista1,n1,x1,y1,-1,0);
	}
	if(abs(x1-x2)!=abs((y1-y2))){
		sok(lista1,n1,x1,y1,-1,1);
		sok(lista1,n1,x1,y1,1,-1);
	}
	
	
	
	if(x1!=x2){
		sok(lista2,n2,x2,y2,0,1);
		sok(lista2,n2,x2,y2,0,-1);
	}
	
	if(y1!=y2){
		sok(lista2,n2,x2,y2,1,0);
		sok(lista2,n2,x2,y2,-1,0);
	}
	if(abs(x1-x2)!=abs((y1-y2))){
		sok(lista2,n2,x2,y2,-1,1);
		sok(lista2,n2,x2,y2,1,-1);
	}
	
	for(int i=0;i<n1;i++)
		for(int j=0;j<n2;j++) 
			if(lista1[i]==lista2[j])
			cout << "Punkt 3: " << lista1[i] << endl;
	
	
	return 0;
}

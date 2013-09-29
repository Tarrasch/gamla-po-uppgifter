/*
 *      6.cpp
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
#include <cstring>
using namespace std;

int forers[6]; //5 olika dragförflyttningar
char winstring[17];
char pos[17];
int currd;

void eval(){
	//cout << " hej";
	for(int i=0;i<15;i++)
		if(pos[i]!=winstring[i])
			return;
	cout << "Bästa vinst hitttad:" << endl << "Innehåller följande drag: ";
	for(int i=0;i<currd;i++)
		cout << forers[i] << " ";
	exit(0);
}

void s(int d){
	if(d==0){
		eval();
		return;
	}
	int turn= (8+d-currd) & 1;
	int& j=forers[currd-d];
	
	
	
	int peicepos[2][5];
	
	int p=5;
	int at=0;

	while(p){
	if(pos[at]=='A')
		peicepos[0][--p]=at;
	at++;
}
	p=5;
	at=0;
	while(p){
	if(pos[at]=='B')
		peicepos[1][--p]=at;
	at++;
}
	
	
	for(int i=0;i<5;i++)
		for(j=1;j<=5;j++){
			if((15>(peicepos[turn][i]+j)) && (pos[peicepos[turn][i]+j]!=pos[peicepos[turn][i]])
				&& ((pos[peicepos[turn][i]+j]=='.') 
					|| ((pos[peicepos[turn][i]+j-1]!=pos[peicepos[turn][i]+j])
						&&
						(pos[peicepos[turn][i]+j+1]!=pos[peicepos[turn][i]+j]))
					)){
				char a=pos[peicepos[turn][i]];
				pos[peicepos[turn][i]]=pos[peicepos[turn][i]+j];
				pos[peicepos[turn][i]+j]=a;
				
				s(d-1);
				
				a=pos[peicepos[turn][i]];
				pos[peicepos[turn][i]]=pos[peicepos[turn][i]+j];
				pos[peicepos[turn][i]+j]=a;
				}
		}	
}



int main(int argc, char** argv){
	cin >> winstring;
	strcpy(pos,"ABABABABAB..... \0");
	
	cout << winstring << endl << pos << endl << endl;
	
	
	
	for(currd=0;currd<=6;currd++)
		s(currd);
	
	
	return 0;
}

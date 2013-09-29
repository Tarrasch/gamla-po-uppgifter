/*
 *      2.cpp
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

using namespace std;

int forers[25];
int indexx[25];
bool groupp[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}; //[index][färg]
int amountused[5]={0,0,0,0,0};
int top=0;

void avslut(){
	for(int i=0;i<25;i++){
		
		if((i%5)==0)
			cout << endl;
		cout << forers[i]+'A'<< ' ';
	}
	exit(0);
	
}

void fora(int d){
	if(top==d){
		cout << endl << d;
		top++;
	}
		
	if(d==25)
		avslut();
	
	for(forers[d]=0;forers[d]<5;forers[d]++){
		if(amountused[forers[d]]==5)
			continue;
		if(groupp[indexx[d]-1][forers[d]]==true)
			continue;
		
		amountused[forers[d]]++;
		groupp[indexx[d]-1][forers[d]]=true;
		fora(d+1);
		amountused[forers[d]]--;
		groupp[indexx[d]-1][forers[d]]=false;
	}
		
}

int main(int argc, char** argv)
{
	for(int i=0;i<25;i++)
		cin >> indexx[i];
	fora(0);
	
			
	return 0;
}

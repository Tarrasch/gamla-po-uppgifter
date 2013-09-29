/*
 *      3.cpp
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

#include <iostream>
#include <cmath>


struct Taltrio{
	long long tal1;
	long long tal2;
	long long tal3;
};

Taltrio allakomb[99999];
int antkombs=0;

void skapakombs(long long tal){
	Taltrio temp;
	if(log10(tal)<9)
		return;
	for(int i=1;i<9;i++)
		for(int j=1;(i+j)<10;j++){
			temp.tal1=tal/(long long)(0.5+pow(10.0,10.0-i));
			temp.tal2=(tal%(long long)(0.5+pow(10.0,10.0-i)))/(long long)(0.5+pow(10.0,10.0-i-j));
			temp.tal3=tal%(long long)(0.5+pow(10.0,10.0-i-j));
			allakomb[antkombs++]=temp;
		}
		
	
}

bool legal(Taltrio trio){
	if((trio.tal1==0 || trio.tal2==0 || trio.tal3==0))
		return false;
	if((trunc(log10(trio.tal1))+trunc(log10(trio.tal2))+trunc(log10(trio.tal3)))<7)
		return false;
	if((trio.tal1*trio.tal2)!=trio.tal3)
		return false;
	return true;
};
	
int main(int argc, char** argv)
{
	long long input;	
	cin >> input;
	
	long long varv=input;
	
	for(int i=0;i<10;i++){
		skapakombs(varv);
		cout << varv << endl;
		varv=varv/10+(long long)(0.99+(1E9*(varv%10)));
	}
	
	for(int i=0; i<antkombs;i++)
		if(legal(allakomb[i])){
			cout << endl << allakomb[i].tal1 << '*' << allakomb[i].tal2 << '=' << allakomb[i].tal3;
		}
	
			
	
	
	
	return 0;
}

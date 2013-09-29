/*
 *      1.cpp
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

int sum=0;

	int forers[7];
	int streck[7];
	int vinst[8]={0,0,0,0,0,0,0,0};

void eval(){
	int ratt=0;
	for(int i=0;i<7;i++)
		if(forers[i]==0)
		ratt++;
	sum+=vinst[7-ratt];
}

void fora(int d){
	if(d==7){
		eval();
		return;
	}
	for(forers[d]=0;forers[d]<(streck[d]);forers[d]++)
	{
		fora(d+1);
	}
	return;
}


int main(int argc, char** argv)
{
	for(int i=0; i<7;i++)
		cin >> streck[i];
		
	for(int i=0; i<3;i++)
		cin >> vinst[i];
	
	cout << "tänker";
		
	fora(0);
	
	cout << endl << sum;
	
	
	return 0;
}

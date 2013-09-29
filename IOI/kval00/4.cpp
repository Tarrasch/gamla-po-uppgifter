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

using namespace std;


int forers[6];
int ringar;
int resultat[10];
int antavpoang[300];

void fora(int d);

bool sorted(){
	if(
	resultat[forers[0]]>=
	resultat[forers[1]] && resultat[forers[1]] >=
	resultat[forers[2]] && resultat[forers[2]] >=
	resultat[forers[3]] && resultat[forers[3]] >=
	resultat[forers[4]] && resultat[forers[4]] >=
	resultat[forers[5]]
	)
		return true;
	return false;
}
	
void fora(int d){
	if(d==6){	
		if(sorted())	
			antavpoang[resultat[forers[0]]+resultat[forers[1]]+resultat[forers[2]]+resultat[forers[3]]+resultat[forers[4]]+resultat[forers[5]]]++;
		return;
	}
	for(forers[d]=0;forers[d]<ringar;forers[d]++)
	{
		fora(d+1);
	}
	return;
}


int main(int argc, char** argv)
{
	for(int i=0; i<300;i++)
		antavpoang[i]=0;
		
	cin >> ringar;
	
	for(int i=0;i<ringar;i++)
		cin >> resultat[i];
		
	fora(0);
	
	int n=0;
	
	for(int i=0; i<300;i++)
		n+=antavpoang[i]==1;
		
	cout << endl << n;
	
	return 0;
}

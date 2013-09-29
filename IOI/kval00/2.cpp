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
using namespace std;

#include <iostream>
#include <cmath>

struct Talosteg{
	long long tal;
	int steg;
	int starttal;
};

long long talbakofram(long long tal){
	int langd=(int)log10(tal)+1;
	long long nytttal=0;
	for(int i=0;i<langd;i++){
		nytttal+=(((tal%10)*(long long)round(pow((float)10,(float)langd-1-i))));
		tal/=10;
		
		}
	return nytttal;
}

void gorklar(Talosteg& indata){
	while(indata.tal!=talbakofram(indata.tal) && indata.steg<26)
	{	
	indata.steg++;
	indata.tal+=talbakofram(indata.tal);
	}
} 

int main(int argc, char** argv)
{
	int lbound, ubound;
	
	cin >> lbound >> ubound;
	
	Talosteg best={11,0,11};
	
	for(int i=lbound;i<=ubound;i++){
		Talosteg temp={i,0,i};
		gorklar(temp);
		cout << temp.starttal << "\t\t" << temp.steg << endl;
		if(temp.steg>=best.steg && temp.steg<26){
			best=temp;
		}
	
	}
	cout << "Bäst tal: " << best.starttal << endl;
	cout << "Steg: " << best.steg << endl;
	cout << "Palindromtal: " << best.tal << endl;
		
	
	return 0;
}

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


#include <iostream>
#include <cmath>

using namespace std;

int sum=0;
bool tagen[10]={0,0,0,0,0,0,0,0,0,0};
unsigned long long helatal=0;

int amount[10][10];


void fora(int d){
	
	
	double floatd=d;
	if(d==10)
		if((((helatal%1000)*((helatal/1000)%100))==(helatal/100000))){
			sum++;
			cout << helatal << endl;
			return;
		}
	
	for(int i=0+(d==2)+(d==4)+(d==9);i<10;i++){
		if(!tagen[i]){
		tagen[i]=true;
		unsigned long long start=helatal;
		helatal+=i*round(pow(10.0,floatd));
		fora(d+1);
		tagen[i]=false;
		helatal=start;
		}
	}
	
}
	


int main(int argc, char** argv)
{
	
	fora(0);
	cout << endl << sum;
	
	return 0;
}

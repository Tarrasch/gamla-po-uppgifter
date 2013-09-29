/*
 *      5.cpp
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
int dn[2]={0,0};
int d[2][15];

int n;
	
int m[15],v[15];

int forers[15];

int best=0;	

using namespace std;

void eval(){
	int summ[2]={0,0};
	int sumv[2]={0,0};
	
	for(int i=0;i<n;i++)
		if(forers[i]!=0){
			summ[forers[i]-1]+=m[i];
			sumv[forers[i]-1]+=v[i];	
		}
		
	if((summ[0]<=150) && (summ[1]<=150) && ((sumv[0]+sumv[1])>best))
		best=sumv[0]+sumv[1];
}
void s(int d){
		if(d==n){
			eval();
			return;
		}
		for(forers[d]=0;forers[d]<3;forers[d]++)
			s(d+1);	
	}
	
	

int main(int argc, char** argv)
{
	cin >> n;
	

	for(int i=0;i<n;i++){
		cout << "vikt " << i+1 << endl;			
		cin >> m[i];
		cout << "värde " << i+1 << endl;
		cin >> v[i];
	}
	
	s(0);
	
	cout << best;
	
	return 0;
}

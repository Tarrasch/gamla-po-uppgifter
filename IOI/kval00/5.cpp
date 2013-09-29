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
#include <vector>
#include <iomanip>


using namespace std;

int kortlek[52]; 
vector <int> korts;

void shuffle(){
	int kortkvar[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int n=50;
	kortlek[0]=(50);
	while(n){
		int r=rand()%50;
		if(kortkvar[r]==0){
			kortlek[--n+1]=r;
			kortkvar[r]++;
		}
	}	
	kortlek[51]=(51);
} 

void rensa(){
	int i=korts.size()-1;
	if(i>2){
		if(((korts.at(i)/13) == (korts.at(i-3)/13)) || ((korts.at(i)%13) == (korts.at(i-3)%13))){ //färg lr valör
			korts.erase(korts.begin()+i-2,korts.begin()+i-1);
			rensa();
			return;
		}
	}
	if(i>1){
		if(((korts.at(i)/13) == (korts.at(i-2)/13)) || ((korts.at(i)%13) == (korts.at(i-2)%13))){ //färg lr valör
			korts.erase(korts.begin()+i-1); 
			rensa();
			return;
		}
	}
	return;
}

bool spela(){
	shuffle();
	for(int i=0;i<52;i++){
		korts.push_back(kortlek[i]);
		rensa();
	}
	//cout << endl << korts.at(0) << " " << korts.at(1) << " ";
	//cout << korts.size();
	return korts.size()==2;
			
}
	



int main(int argc, char** argv)
{
	srand(time(0));
	
	int n;
	int lyckade=0;
	
	cin >> n;
	
	for(int i=0;i<n;i++)
		lyckade+=spela();
		
	cout << setprecision(4) << (float)lyckade/n*100;
	
	return 0;
}

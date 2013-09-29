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


#include <iostream>
using namespace std;


struct AKER{
	int ov;
	int k;
	int mv;
};

void sortera(AKER l[],int n){
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(l[j].k>l[i].k){
				AKER tempv=l[i];
				l[i]=l[j];
				l[j]=tempv;
			}	
}

int main(int argc, char** argv)
{
	cout << "totvol:" << endl;
	int tv;
	cin >> tv;
	cout << "åkrar:" << endl;
	int n;
	cin >> n;
	
	AKER akrar[n];
	
	cout << "i";	

	for(int i=0;i<n;i++){
		cout << "åker " << i+1 << " optimal v" << endl;
		cin >> akrar[i].ov;
		cout << "åker " << i+1 << " kanslighet" << endl;
		cin >> akrar[i].k;
		cout << "åker " << i+1 << " minimal v" << endl;
		cin >> akrar[i].mv;
	}
		
	sortera(akrar,n);
	
	int mf=0;
	
	for(int i=0;i<n;i++){
		tv-=akrar[i].mv;
		mf+=(akrar[i].ov-akrar[i].mv) * akrar[i].k;
	}

	int at=0;
	while(tv && (at<5)){
		if(akrar[at].mv==akrar[at].ov){
			at++;
			continue;
		}
		akrar[at].mv++;
		tv--;
		mf-=akrar[at].k;
	}
	
	cout << endl << mf;
	return 0;
}

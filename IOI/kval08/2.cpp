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
#include <string>
using namespace std;

bool is_in(string e,string l[],int n){
	for(int i=0;i<n;i++)
		if(l[i]==e){
			//cout << e << endl;
			return true;
		}
	return false;
}
		

int main(int argc, char** argv)
{
	int hn=0,fn=0;
	string hlist[100],flist[100];
	int an=0,nn=0;
	string alist[10000],nlist[1000];

	
	cin >> hn;
	for(int i=0;i<hn;i++){
		cin >> hlist[i];
		alist[an++]=hlist[i];
	}
	cin >> fn;
	for(int i=0;i<fn;i++){
		cin >> flist[i];
		alist[an++]=flist[i];
	}
	
	
	for(int i=0;i<hn;i++)
		for(int j=0;j<fn;j++){	
			alist[an]="AA";
			alist[an].at(0)=hlist[i].at(0);
			alist[an++].at(1)=flist[j].at(1);

			alist[an]="AA";	
			alist[an].at(0)=flist[j].at(0);
			alist[an++].at(1)=hlist[i].at(1);
		}
		
	for(int i=0;i<an;i++){
		if(!is_in(alist[i],nlist,nn))
			nlist[nn++]=alist[i];
	}
	cout << nn;
	
	return 0;
}

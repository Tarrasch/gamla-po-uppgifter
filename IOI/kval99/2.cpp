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

string indata;

unsigned int bestresult=0;
string beststring;


void sok(string utd, string kvar){
	if(kvar.empty()){
		if(utd.length()>bestresult){
			bestresult=utd.size();
			beststring=utd;
		}		
		return;
	}
	
	sok(utd, kvar.substr(1));
	
		
	if(  (utd.empty()?('A'-1):utd.at(utd.length()-1)) < kvar.at(0)){	
	utd+=kvar.at(0);	
	sok(utd, kvar.substr(1));
}	
	return;
}


int main(int argc, char** argv)
{
	//cin >> indata;
	
	//indata="KBWZSROCFUJDEILANTMYGVXHPQ";
	
	//indata="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	indata="ZYXWVUTSRQPONMLKJIHGFEDCBA";
	
	sok("",indata);
	
	cout << beststring;
				
		
	return 0;
}

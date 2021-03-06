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
#include <string>
#include <cmath>

using namespace std;

string matris[100][100];

int parse(string s);

int parse(string s){
	if(s.empty())
		return 0;
	if(s.at(0)=='0')
		return 0;
	int sum=0;
	
	if(s.at(0)=='-')
	if(s.at(1)>='1'  && s.at(1)<='9')
	return -parse(s.substr(1));
	else
	return -parse(s.substr(1))+2*parse(s.substr(3));
	
	
	//cout << s;
	
	if(s.at(0)=='+')
	return parse(s.substr(1));
	
	
	//cout << s;
	
	if(s.at(0)>='1'  && s.at(0)<='9'){
	for(int i=0;i!=(signed int)s.size();i++)
		sum+=round(pow(10.0,(signed int)s.size()-1-i)*(s.at(i)-'1'+1));	
	return sum;
	}
	//cout << s;
	sum+=parse(matris[s.at(0)-'A'][s.at(1)-'0'])+parse(s.substr(2));
	return sum;
}


int main(int argc, char** argv)
{
	int x,y;
	cin >> y >> x;
	y--;
	x--;
	for(int i=0;i<=x;i++)
		for(int j=0;j<=y;j++){
			cout << "Cell " <<(char)(i+'A') << (char)(j+'0') <<": ";
			cin >> matris[i][j];
		}
	
	
	for(int j=0;j<=y;j++)
		for(int i=0;i<=x;i++){
			 if(i==0)
			 	cout << endl;
			 cout << '\t';
			 cout << parse(matris[i][j]);
		}
	
	
	return 0;
}

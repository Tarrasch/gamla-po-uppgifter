/*
 *      6.cpp
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

char pos[9];
int zpos;

int movelist[9][5]=

{{3,1,-1}
,{0,4,2,-1}
,{1,5,-1}
,{0,6,4,-1}
,{3,1,5,7,-1}
,{4,2,8,-1}
,{3,7,-1}
,{6,4,8,-1}
,{7,5,-1}};
	
int eval(){
	return pos[0]=='1' && pos[1]=='2' && pos[2]=='3'
	&& pos[3]=='4' && pos[4]=='5' && pos[5]=='6'
	&& pos[6]=='7' && pos[7]=='8' && pos[8]=='0';
}
void makemove(int move){
	pos[zpos]=pos[move];
	pos[move]='0';
	zpos=move;
}
	
int search(int d){
	if(eval() || d==0)
		return d;
		
	int bestresult=0;
	for(int i=0;movelist[zpos][i]!=-1;i++){
		int ozpos=zpos;
		makemove(movelist[zpos][i]);
		int res= search(d-1);
		if(res>bestresult)
			bestresult=res;
		makemove(ozpos);
	}
	return bestresult;
}

#include <iostream>

int main(int argc, char** argv)
{
	cin >> pos;
	zpos=0;
	while(pos[zpos]!='0')
		zpos++;
	
	cout << 15-search(15);
	return 0;
}

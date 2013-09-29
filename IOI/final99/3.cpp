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


#include <string>
#include <iostream>
using namespace std;

int n; //snurrningar
string s[3];

bool win[59][50][50];
int bestat[59][50][50];//poäng-drag

int best=0;

void search(int at, int i, int j, int k,int score){
	
	if(at==n){
		if(score>best)
			best=score;

		return;
	}
		
	if(bestat[i][j][k]<(score-at))
		bestat[i][j][k]=score-at;
	else
		return;
	
	if(win[i+1][j+1][k+1]){
		search(at+1, i+1, j+1, k+1, score+1);
	
}
	if(win[i+1][j][k+1])
		search(at+1, i+1, j, 1+k, score+1);
	if(win[i+1][j+1][k])
		search(at+1, i+1, 1+j, k, score+1);
	if(win[i][j+1][k+1])
		search(at+1, i, 1+j, 1+k, score+1);

	if(win[i+1][j][k])
		search(at+1, 1+i, j, k, score+1);
	if(win[i][j+1][k])
		search(at+1, i, 1+j, k, score+1);
	if(win[i][j][k+1])
		search(at+1, i, j, 1+k, score+1);
	

	if(!win[i+1][j+1][k+1])
		search(at+1, i+1, j+1, k+1, score);

	if(!win[i+1][j][k+1])
		search(at+1, i+1, j, 1+k, score);
	if(!win[i+1][j+1][k])
		search(at+1, i+1, 1+j, k, score);
	if(!win[i][j+1][k+1])
		search(at+1, i, 1+j, 1+k, score);

	if(!win[i+1][j][k])
		search(at+1, 1+i, j, k, score);
	if(!win[i][j+1][k])
		search(at+1, i, 1+j, k, score);
	if(!win[i][j][k+1])
		search(at+1, i, j, 1+k, score);
	
	return;
	}

int main(int argc, char** argv)
{
	cin >> n;
	/*
	cin >> s[0];
	cin >> s[1];
	cin >> s[2];
	*/
	
	s[0]="PCCPPPCCPCCPPCCPPPCCPCCPPCCPPPCCPCCPPCPCPCCPPPPCPCPCPCCPPPPCPCPCPCCPPPPC";
	s[1]="PCPCPCCPPPPCPCPCPCCPPPPCPCPCPCCPPPPCPCPCPCCPPPPCPCPCPCCPPPPCPCPCPCCPPPPC";
	s[2]="PCCPPPCCPCCPPCCPPPCCPCCPPCCPPPCCPCCPPCPCPCCPPPPCPCPCPCCPPPPCPCPCPCCPPPPC";
	
	/*
	s[0]="CCCCCCCPPPPP";
	s[1]="CCCCCCCPPPPP";
	s[2]="PPPPPPPCCCCC";
	*/
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	for(int k=0;k<n;k++){
	win[i][j][k]=((s[0].at(i))==(s[1].at(j)) && (s[0].at(i))==(s[2].at(k)));
	//cout << win[i][j][k];
	bestat[i][j][k]= -100;
}
	search(0,0,0,0,0);

	
	cout << best;
	
	return 0;
}

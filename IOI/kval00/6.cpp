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


struct Square{
	int x,y;
};

bool board [5][5]=
{{0,0,0,0,1},
{1,1,0,0,0},
{1,0,0,0,0},
{1,0,1,0,1},
{1,0,1,1,0}
};  
int bricks=10;
Square rookpos;

Square movelist[10];

void hittat();

void generatemoves(Square list[],int& n){
	n=0;
	for(int x=0;x<5; x++)
		for(int y=0;y<5; y++)
			if(((rookpos.x==x) ^ (rookpos.y==y))==1 && board[x][y]){
				list[n].x=x;
				list[n].y=y;
				n++;
			}

}

void search(){
	int n;
	Square list[9];
	generatemoves(list,n);

	if(n==1 && bricks==2){
		movelist[0]=list[0];
		hittat();
	}
	
	if(n==0)
		return;
	
	Square oldpos=rookpos;
	bricks--;
	board[rookpos.x][rookpos.y]=0;
	for(int i=0;i<n;i++){
		rookpos=list[i];
		movelist[bricks-1]=rookpos;
		search();		
	}
	rookpos=oldpos;
	bricks++;
	board[rookpos.x][rookpos.y]=1;
		
}

void hittat(){
	cout << "Hittat en väg: ";
	for(int i=9;i>=0;i--)
		cout << endl << movelist[i].x+1 << ' ' << movelist[i].y+1;
	exit(0);
	
}
	


int main(int argc, char** argv)
{
	for(int x=0;x<5;x++)
		for(int y=0;y<5;y++){
			cout << "x=" << x << " " << "y=" << y << ":" << endl ;
			cin >> board[x][y];
		}
		
	
		
	for(int x=0;x<5;x++)
		for(int y=0;y<5;y++){
			rookpos.x=x;
			rookpos.y=y;
			movelist[bricks-1].x=x;
			movelist[bricks-1].y=y;
			if(board[x][y])
				search();
		}		
	return 0;
}

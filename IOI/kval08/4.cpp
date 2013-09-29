/*
 *      4.cpp
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

int main(int argc, char** argv)
{
	int talj;
	cin >> talj;
	int namn;
	cin >> namn;
	
	float flyt=(float)talj/namn;
	
	const float e=0.0000001;
	
	for(int i=0;i<1024;i++){
		float nyfloat=0.0;
		for(int j=1; j<11;j++){
			if(i & (1 << (j-1)))
				nyfloat+=1.0/j;
			}
		if( ((nyfloat-flyt)*(nyfloat-flyt))<e){
			for(int j=1; j<11;j++)
				if(i & (1 << (j-1))){
					cout << "1/" << j << " ";
				}
			exit(0);
			}
		}
	cout << "Omöjligt";
	
	
	
	return 0;
}

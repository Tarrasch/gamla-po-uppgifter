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

#include <math.h>
#include <iostream>

using namespace std;

bool magiskttal(int tal){
	unsigned int talfalt[10]={0,0,0,0,0,0,0,0,0,0,};
	for(int i=1;i!=1000000000;i*=10){
		if(i>=100000000)
			cout << i << endl;
		//talfalt[(tal/i)%10]++;
		if(talfalt[(tal/i)%10]++)
			return false;
	}
	return true;
	
}

int main(int argc, char** argv)
{
	int lowerbound= (int)(sqrt(1E9)+0.99999);
	int upperbound= (int)(sqrt(1E10)+0.99999);
	
	int amount=0;
	for(int i=lowerbound;upperbound>=i;i++)
		if(magiskttal(i*i))
			amount++;
		
	cout << amount << endl << lowerbound << endl << upperbound;
	
	return 0;
}

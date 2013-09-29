/*
 *      untitled.cpp
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

int ak,au,bk,bu;
int total;

int antalavb(int antalava){
	return (int)((float)(total-au*antalava)/bu+0.9999);	
}

int main(int argc, char** argv)
{
	cin >> ak;
	cin >> au;
	cin >> bk;
	cin >> bu;
	cin >> total;
	
	int basthittilsava=(int)((float)total/au+0.9999);
	
	for(int anta=(int)((float)total/au+0.9999);anta>=0;anta--)
		{
			if((ak*basthittilsava+bk*antalavb(basthittilsava))>(ak*anta+bk*antalavb(anta)))
			basthittilsava=anta;
		}
		
	cout << basthittilsava << endl;
	cout << antalavb(basthittilsava) << endl;
	cout << ak*basthittilsava+bk*antalavb(basthittilsava);
	
	
	return 0;
}

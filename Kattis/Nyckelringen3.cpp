#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string ring;
//bool platstagen[60];
int nycklar;
bool nyckeltagen[6]={0,0,0,0,0,0};
int tryd;

void rek(int bortkvar, int at, int ls=-1){
	if(at==nycklar){
		cout << tryd << endl;
		exit(0);
	}

	if(bortkvar)
		rek(bortkvar-1, at+1, ls);

	if(!nyckeltagen[ring[at]-'A']){
		nyckeltagen[ring[at]-'A']=true;
		rek(bortkvar, at+1, at);
		nyckeltagen[ring[at]-'A']=false;
	}
	else if(ring[at]==ring[ls]){
		rek(bortkvar, at+1, at);
	}

}

int main(int argc, char** argv)
{
	cin >> ring;
	//ring="ABCCBABCDBDEBBABCA";
	//ring="AABBAABB";
	nycklar= ring.length();

	while(ring[0]==ring[nycklar-1]){
		ring=ring.substr(1);
		ring+=ring[nycklar-2];
	}

//	cout << ring;

	for(tryd=0;tryd<nycklar;tryd++)
		rek(tryd, 0);

	//cout << ring;


	return 0;
}


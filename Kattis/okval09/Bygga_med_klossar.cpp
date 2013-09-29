#include <iostream>
using namespace std;

int klossar;
int atkloss;
struct Kloss{
	int v,c,u,b;
	int talj,namn;
};
//bool debug=false;
//#define LOG if(debug) printf
Kloss kloss[1000];

bool ramlar(Kloss* k){
	float t=(float)(k->talj)/k->namn;
	k=&kloss[k->u-1];
//	LOG("%f\n",t);
	return !( t>(k->c-(float)k->b/2) && t<(k->c+(float)k->b/2)) ;
}

int main(int argc, char** argv)
{
	cin >> klossar;

	for(int i=0;i<klossar;i++){
		int h;
		cin >> kloss[i].u >> kloss[i].b >> h >> kloss[i].c;
		kloss[i].v=kloss[i].b*h;
		kloss[i].talj=kloss[i].v*kloss[i].c;
		kloss[i].namn=kloss[i].v;
	}
	
	for(atkloss=0;atkloss<klossar;atkloss++){	
		Kloss* k=&kloss[atkloss];
		int t=k->talj;
		int n=k->namn;
		while(k->u>0){
			if(ramlar(k)){
				cout << atkloss << endl;
				return 0;
			}
			k=&kloss[k->u-1];
			k->talj+=t;
			k->namn+=n;
		}
	}
	cout << klossar << endl;
	return 0;
}

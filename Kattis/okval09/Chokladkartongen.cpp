#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	int o[100];
	for(int i=0;i<n;i++)
		cin >> o[i];
		
	int kop=0;
	
	for(int i=1;i<n;i++)
		if(o[i]>o[i-1])
			kop++;		
			
	cout << kop << endl;	
	return 0;
}

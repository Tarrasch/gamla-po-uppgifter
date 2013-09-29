#include <iostream>
#include <string>
using namespace std;

int ninstr;
string instr[256];
int params[256][2];
int reg[256];

int carpet;

int nparams(string s){
	if(s=="HALT")
		return 0;
	if(s=="OUTPUT" || s=="INPUT")
		return 1;
	return 2;	
}

int main(int argc, char** argv)
{
	for(int i=0;i<256;i++){
		reg[i]=0;
	}
	cin >> ninstr;
	
	for(int i=0;i<ninstr;i++){
		string s;
		cin >> s;
		instr[i]=s;
		for(int j=0;j<nparams(s);j++)
			cin >> params[i][j];		
	}
	
	carpet=0;
	
	while(true){
//		cout << carpet << endl;
		string s = instr[carpet];
		
		if(s=="CONST"){
			reg[params[carpet][1]]=params[carpet][0];
			carpet++;
		}
		else if(s=="ADD"){
			reg[params[carpet][1]]+=reg[params[carpet][0]];
			carpet++;			
		}
		else if(s=="SUB"){
			reg[params[carpet][1]]-=reg[params[carpet][0]];
//			cout << " " << reg[params[carpet][1]] ;
			carpet++;			
		}
		else if(s=="JNZ"){
			if(reg[params[carpet][0]]>0)
				carpet=params[carpet][1];
			else
				carpet++;			
		}
		else if(s=="INPUT"){
			cin >> reg[params[carpet][0]];
			carpet++;			
		}
		else if(s=="OUTPUT"){
			cout << reg[params[carpet][0]] << endl;
			carpet++;
		}
		else if(s=="HALT"){
			return 0;
		}
	}
	
	return 0;
}

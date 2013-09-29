#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

struct State{
	char at;
	char senast_char;
	char forsta_char;
	int8_t nyckeltagen[6];
};

int nycklar;
string ring;
void expand(State s, vector <State>& arr){
	for(; s.at<nycklar+1; s.at++){
		arr.push_back(s);
		if(s.senast_char!=ring[s.at]){
			if(s.nyckeltagen[ring[s.at]-'A']==0)
				s.nyckeltagen[ring[s.at]-'A']=true;
			else
				if(ring[s.at]!=s.forsta_char || s.nyckeltagen[ring[s.at]-'A']==2){
					arr.pop_back();
					break;
				}
				else
					s.nyckeltagen[ring[s.at]-'A']=2;
			s.senast_char=ring[s.at];
		}
		if(s.forsta_char=='G')
			s.forsta_char=ring[s.at];
		//n++;
	}
}

int main(int argc, char** argv){
	cin >> ring;
	nycklar= ring.length();

	vector <State> states [60];

	State s=(State){0,'G','G',{0,0,0,0,0,0}};

	expand(s, states[0]);

	for (int d = 0; d < nycklar; ++d) {
		for (unsigned int n = 0; n < states[d].size(); ++n) {
			s=states[d][n];
			s.at++;
			if(s.at==nycklar){
				if(s.nyckeltagen[s.forsta_char-'A']<2 || s.forsta_char==s.senast_char){
					cout << d << endl;
					exit(0);
				}
			}
			else
				expand(s, states[d+1]);
		}
	}

	return 0;
}

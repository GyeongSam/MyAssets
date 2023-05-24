#include <iostream>
#include <string>
using namespace std;

char mirror(char c){
	switch (c){
		case 'b':
			return 'd';
		case 'd':
			return 'b';
		case 'i':
			return 'i';
		case 'l':
			return 'l';
		case 'm':
			return 'm';
		case 'n':
			return 'n';
		case 'o':
			return 'o';
		case 'p':
			return 'q';
		case 'q':
			return 'p';
		case 's':
			return 'z';
		case 'z':
			return 's';
		case 'u':
			return 'u';
		case 'v':
			return 'v';
		case 'w':
			return 'w';
		case 'x':
			return 'x';
		default:
			return '0';
	}
}


int main() {
	int trans[26];
	
	for (int i=0; i<26;++i){
		trans[i]=-1;
	}
	
	
	int N;
	scanf("%d",&N);
	
	while(N--){
		string ip;
		cin >> ip;
		string trans="";
		for (auto iter = ip.rbegin(); iter!=ip.rend(); ++iter){
			trans += mirror(*iter);
		}
		cout << ((ip==trans)?"Mirror":"Normal") << "\n";
	}
	return 0;
}
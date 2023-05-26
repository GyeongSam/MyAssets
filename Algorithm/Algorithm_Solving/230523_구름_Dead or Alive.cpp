#include <iostream>
#include <vector>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector <int> wInfo(1001);
	vector <int> numInfo(1001);
	
	for (int i=1; i<=N;++i){
		int v,w;
		cin >> v >> w;
		
		if (wInfo[v]==0 || w>=wInfo[v]) {
			wInfo[v]=w;
			numInfo[v]=i;
		}
	}
	long long ans =0;
	for (int i=1;i<1001;++i){
		if (numInfo[i]!=0) ans+=numInfo[i];
	}
	cout <<ans;
}
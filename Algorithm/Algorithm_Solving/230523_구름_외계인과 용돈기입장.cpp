#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N,M;
	cin >> N >> M;
	
	vector <long long> sum(N+1);
	long long total = 0;
	for (int i=1; i<=N;++i){
		long long temp;
		cin >> temp;
		total +=temp;
		sum[i] = total;
	}
	while(M--){
		int s, e;
		cin >> s >> e;
		long long temp = sum[e] - sum[s-1]; 
		if (temp>0) cout <<"+";
		cout <<temp <<"\n";
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int min (int a, int b){
	return a<b?a:b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	if (N<=2) { cout<<0; return 0; }
	vector<int> poisons(N+1);
	vector<int> dp(N+1);
	for (int i=0;i<N;++i) cin >> poisons[i];
	for (int i=0;i<3;++i) dp[i]=poisons[i];
	for (int i=3;i<=N;++i){
		dp[i] = poisons[i]+min(min(dp[i-3],dp[i-2]),dp[i-1]);
	}
	cout << dp[N];
}
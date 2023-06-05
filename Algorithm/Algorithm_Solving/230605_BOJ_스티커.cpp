#include <iostream>
#include <vector>


using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector <vector<int>> dp(N+1, vector<int>(2));
		//vector <vector<int>> dp(N, vector<int>(3));
		for (int i = 1; i <= N; ++i) {
			cin >> dp[i][0];
		}
		for (int i = 1; i <= N; ++i) {
			cin >> dp[i][1];
		}
		for (int i = 2; i <= N; ++i) {
			dp[i][0] += max(dp[i - 1][1], dp[i - 2][1]);
			dp[i][1] += max(dp[i - 1][0], dp[i - 2][0]);
		}
		cout << max(dp[N][0],max(dp[N][1],max(dp[N-1][0],dp[N-1][1]))) << "\n";
	}
}
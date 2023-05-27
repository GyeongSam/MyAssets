#include <iostream>
#include <vector>

using namespace std;

struct item {
	int V,C;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; ++tc) {
		int N, K;
		cin >> N >> K;
		vector <item> items(N);
		vector <vector<int>> DPtable(K+1,vector<int>(N,0));

		for (int n = 0; n < N; ++n) {
			cin >> items[n].V >> items[n].C;
		}

		for (int k = 1; k <= K; ++k) {
			for (int n = 0; n < N; ++n) {
				if (!n) {
					if (k >= items[n].V) DPtable[k][n] = items[n].C;
				}
				else {
					if (k >= items[n].V) {
						DPtable[k][n] = DPtable[k - items[n].V][n-1] + items[n].C;
					}
					if (DPtable[k][n - 1] > DPtable[k][n])  DPtable[k][n] = DPtable[k][n - 1];
				}
			}
		}
		cout << DPtable[K][N - 1];
	}
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool comp(vector<int> a, vector<int> b) {
	if (a[1] == b[1]) return a[0] > b[0];
	return a[1] < b[1];
}

int main() {

	int N;
	scanf("%d", &N);
	vector <vector<int>> time(N, vector<int>(2));
	for (int n = 0; n < N; ++n) {
		scanf("%d %d", &time[n][0], &time[n][1]);
	}
	sort(time.begin(), time.end(), comp);


	int lastTime = 0;
	int count = 0;
	for (int i = 0; i < time.size(); ++i) {
		if (time[i][0] > lastTime) {
			count++;
			lastTime = time[i][1];
		}
	}

	printf("%d", count);

	return 0;
}
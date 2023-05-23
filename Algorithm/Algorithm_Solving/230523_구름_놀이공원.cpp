#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<iostream>
#include<algorithm>


using namespace std;


int get_minimum_trashes(int** waste, int N, int K) {
	int answer = K * K;
	int dWaste[100][100] = { 0, };

	for (int i = 0; i < N; ++i) {
		int temp = 0;
		for (int j = 0; j < K; ++j) {
			if (waste[i][j]) temp++;
		}
		dWaste[i][0] = temp;
		for (int j = 0; j < N - K; ++j) {
			temp += waste[i][j + K] - waste[i][j];
			dWaste[i][j + 1] = temp;
		}
	}
	// for (int i=0;i<N;++i){
	// 	for (int j=0;j<N;++j){
	// 		printf("%d ",dWaste[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for (int j = 0; j <= N - K; ++j) {
		int temp = 0;
		for (int i = 0; i < K; ++i) {
			temp += dWaste[i][j];
		}
		if (temp < answer) answer = temp;
		for (int i = 0; i < N - K; ++i) {
			temp += dWaste[i + K][j] - dWaste[i][j];
			if (temp < answer) answer = temp;
		}
	}
	return answer;
}

void test_case(int caseIndex) {
	int N, K;
	scanf("%d %d", &N, &K);

	int** wastes = new int* [N];
	for (int r = 0; r < N; r += 1) {
		wastes[r] = new int[N];
		for (int c = 0; c < N; c += 1) {
			scanf("%d", &wastes[r][c]);
		}
	}

	int answer = get_minimum_trashes(wastes, N, K);
	printf("%d\n", answer);

	for (int r = 0; r < N; r += 1) {
		delete[] wastes[r];
	}
	delete[] wastes;
}

int main() {
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 0; caseIndex < caseSize; caseIndex += 1) {
		test_case(caseIndex);
	}
	return 0;
}
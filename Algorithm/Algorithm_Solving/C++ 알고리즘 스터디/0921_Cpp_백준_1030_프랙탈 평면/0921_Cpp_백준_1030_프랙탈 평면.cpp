#include <iostream>

int s, N, K, R1, R2, C1, C2, i,j,l,r, n;

int goback(int s,int di, int dj) {	// s:과거로 돌아가야할 횟수, di:현재 i좌표, dj:현재 j좌표
	if (!s) {				// 태초는 하얀색 사각형 하나입니다.
		return 0;
	}
	else {
		int x;
		x=goback(s-1, di / N, dj / N);		// x 는 바로 전 과거의 di/N, dj/N 점프로 부터 온 정보입니다.
		if (!x) {	//x가 하얀색 사각형이었다면		
			if ((di%N) >= l && (di%N) < r && (dj%N) >= l && (dj%N) < r) {
				return 1;	// 가운데에 속한 점은 검은색 사각형입니다.
			}
			else return 0;	// 외곽은 하얀색 사각형입니다.
		}
		else return 1;	//검은색사각형으로 부터
	}
}


int main() {
	scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);
	l = (N - K)/2;			// 하얀색이 분열할 때 필요한 보조변수 l입니다.
	r = N - l;					// 보조변수 r입니다.
	for (int i = R1; i <= R2; ++i) {
		for (int j = C1; j <= C2; ++j) {
			printf("%d",goback(s,i, j));		// 해당 좌표가 어떤 경로로 온 것인지 추적해서 인쇄합니다.
		}
		printf("\n");
	}
	printf("\n");
}



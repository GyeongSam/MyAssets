#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N,K;
	cin >> N >> K;
	long long answer=0;
	
	while(K--){
		int i,j;
		cin >> i >> j;
		answer+=5;
		if (i==1) answer--;
		if (i==N) answer--;
		if (j==1) answer--;
		if (j==N) answer--;
	}
	cout << answer;
}
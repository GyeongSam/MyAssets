#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,T;
	cin >> N >> T;
	int idx=0;
	int time=5000001;
	for (int i=1; i<=N;++i){
		int s, d;
		cin >> s >> d;
		if (T>s){
			s += d*((T-s)/d + ((T-s)%d==0?0:1));
		}
		if (s<time) {
			time = s;
			idx = i;
		}
	}
	cout << idx;
}
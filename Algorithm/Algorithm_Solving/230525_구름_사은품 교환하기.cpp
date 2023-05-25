#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >>T;
	for (int tc=1; tc<=T;++tc){
		long long n,m;
		cin >> n >> m;
		
		long long temp = (7*n - 5*m);
		long long x = temp/12 + (temp%12==0?0:1);
		if (x<0) x=0;
		cout << (n-x)/5 <<"\n";
		
	}
	
}
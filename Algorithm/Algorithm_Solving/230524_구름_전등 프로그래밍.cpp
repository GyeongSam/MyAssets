#include <iostream>
#include <vector>
using namespace std;

int main() {	
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	vector <vector<int>> board(n,vector<int>(m));
	vector <int> rowCount(n);
	vector <int> colCount(m);
	
	for (int i=0; i<n;++i){
		for (int j=0; j<m;++j)
			cin >> board[i][j];
	}
	
	int p;
	cin >> p;
	
	while(p--){
		int w,idx;
		cin >> w >> idx;
		if (w==0 && 1<=idx && idx <=n){
			rowCount[idx-1]++;
		}
		else if (w==1 && 1<=idx && idx <=m) {
			colCount[idx-1]++;
		}
	}
	
	for (int i=0; i<n;++i){
		for (int j=0; j<m;++j){
			if ((rowCount[i]+colCount[j])%2==0){
				cout << board[i][j] <<" ";
			}
			else{
				cout << 1-board[i][j] <<" ";
			}
		}
		cout <<"\n";
	}
	
	
	return 0;
}
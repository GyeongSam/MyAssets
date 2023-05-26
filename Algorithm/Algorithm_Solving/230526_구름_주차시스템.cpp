#include <iostream>
#include <vector>


struct ax{
	int i,j;
};
int di[4]={1,0,-1,0};
int dj[4]={0,1,0,-1};

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N,M,answer=0;
	cin >> N >> M;
	
	vector<vector<int>> parkingPlace(N,vector<int>(M));
	for (int i=0; i<N;++i){
		for (int j=0; j<M;++j)
			cin >> parkingPlace[i][j];
	}
	
	for (int i=0; i<N;++i){
		for (int j=0; j<M;++j){
			if (parkingPlace[i][j]!=1){
				int score = 0;
				vector <ax> stack;
				ax init = {i,j};
				stack.push_back(init);
				score += (parkingPlace[i][j]==2?-2:1);
				parkingPlace[i][j]=1;

				
				while(!stack.empty()){
					ax now = stack.back();
					stack.pop_back();
					
					for (int d=0; d<4; ++d){
						ax next = {now.i+di[d],now.j+dj[d]};
						
						if (next.i<0||next.i>=N || next.j<0 || next.j>=M || parkingPlace[next.i][next.j]==1) continue;
						stack.push_back(next);
						score += (parkingPlace[next.i][next.j]==2?-2:1);
						parkingPlace[next.i][next.j]=1;
					}
				}
				if (score>answer) answer = score;
				
			}
		}
	}
	cout << answer;
}
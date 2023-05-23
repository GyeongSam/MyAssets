#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	unordered_set<int> set;
	while (N--) {
		int temp;
		scanf("%d", &temp);
		set.insert(temp);
	}


	int M;
	scanf("%d", &M);
	while (M--) {
		int temp;
		scanf("%d", &temp);
		if (set.find(temp) != set.end()) printf("1\n");
		else printf("0\n");
	}



	return 0;
}
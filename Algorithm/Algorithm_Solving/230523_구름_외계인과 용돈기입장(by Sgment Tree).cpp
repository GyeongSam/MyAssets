#include <iostream>
#include <vector>
using namespace std;



long long make_segment(int l, int r, int idx, vector<long long>& container, vector<long long>& segment_tree) {
	// cout << "l:" <<l << " / r:" << r <<  " / idx : " << idx <<"\n";
	if (l == r) {
		segment_tree[idx] = container[l];
		return container[l];
	}
	int m = (l + r) >> 1;
	segment_tree[idx] = make_segment(l, m, idx << 1, container, segment_tree) + make_segment(m + 1, r, (idx << 1) + 1, container, segment_tree);
	return segment_tree[idx];
}

long long find_sum(int l, int r, int idx, int target_l, int target_r, vector<long long>& segment_tree) {
	if (r < target_l || target_r < l) return 0;
	if (target_l <= l && r <= target_r) return segment_tree[idx];
	int m = (l + r) >> 1;
	return find_sum(l, m, idx << 1, target_l, target_r, segment_tree) + find_sum(m + 1, r, (idx << 1) + 1, target_l, target_r, segment_tree);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;


	vector <long long> input(N);
	int S = 2;
	while (S < N) S <<= 1;
	S <<= 1;
	vector <long long> segment_tree(S);

	for (int i = 0; i < N; ++i) cin >> input[i];
	make_segment(0, N - 1, 1, input, segment_tree);

	// for (int i=0; i<S; ++i) cout << segment_tree[i] << ", ";

	while (M--) {
		int l, r;
		cin >> l >> r;
		long long temp = find_sum(0, N - 1, 1, l - 1, r - 1, segment_tree);
		if (temp > 0) cout << "+";
		cout << temp << "\n";
	}
	return 0;
}
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct heap {
//	vector <int> tree = { 0 };
//	int last_idx = 0;
//	void swap(int idx1, int idx2) {
//		int temp = tree[idx2];
//		tree[idx2] = tree[idx1];
//		tree[idx1] = temp;
//	}
//	void add(int c) {
//		tree.push_back(c);
//		int idx = ++last_idx;
//		while (idx > 1 && tree[idx / 2] < tree[idx]) {
//			swap(idx / 2, idx);
//			idx /= 2;
//		}
//	}
//	int pop() {
//		int temp = tree[1];
//		swap(1, last_idx);
//		last_idx--;
//		tree.pop_back();
//		int idx = 1;
//		while (idx * 2 <= last_idx) {
//			if (idx * 2 == last_idx) {
//				if (tree[idx] < tree[2 * idx]) {
//					swap(idx, idx * 2);
//				}
//				else break;
//			}
//			else {
//				int next_idx = tree[idx * 2] > tree[idx * 2 + 1] ? idx * 2 : idx * 2 + 1;
//				swap(idx, next_idx);
//				idx = next_idx;
//			}
//		}
//		return temp;
//	}
//	
//	void printing() {
//		for (int i = 1; i <= last_idx; ++i) cout << tree[i] << " ";
//		cout << "\n";
//	}
//};
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//	int testCase;
//	cin >> testCase;
//
//	for (int tc = 1; tc <= testCase; ++tc) {
//		heap MaxHeap, MinHeap;
//		int N,answer =0;
//		int c1, c2;
//		cin >> N >> c2;
//		MaxHeap.add(c2);
//
//		while (N--) {
//			cin >> c1 >> c2;
//			if (c1 < MaxHeap.tree[1]) {
//				MaxHeap.add(c1);
//				MinHeap.add(-MaxHeap.pop());
//			}
//			else MinHeap.add(-c1);
//
//			if (c2 > -MinHeap.tree[1]) {
//				MinHeap.add(-c2); 
//				MaxHeap.add(-MinHeap.pop());
//			}
//			else MaxHeap.add(c2);
//			answer += MaxHeap.tree[1];
//			answer %= 20171109;
//		}
//		cout << "#" << tc << " " << answer << "\n";
//	}
//}
#include <iostream>
#include <vector>
using namespace std;


int max(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int> > land)
{
    int N = land.size() - 1;
    for (int i = 1; i <= N; ++i) {
        int c = i - 1;
        land[i][0] += max(max(land[c][1], land[c][2]), land[c][3]);
        land[i][1] += max(max(land[c][0], land[c][2]), land[c][3]);
        land[i][2] += max(max(land[c][0], land[c][1]), land[c][3]);
        land[i][3] += max(max(land[c][0], land[c][1]), land[c][2]);
    }
    return max(max(max(land[N][0], land[N][1]), land[N][2]), land[N][3]);
}
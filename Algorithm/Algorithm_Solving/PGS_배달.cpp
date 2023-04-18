#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int>* comp_dp;
struct comp {
    bool operator()(int a, int b) {
        return (*comp_dp)[a] > (*comp_dp)[b];
    }
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> dp(N + 1, 1 << 24);
    comp_dp = &dp;
    vector <vector<int>> edges(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < road.size(); ++i) {
        if (edges[road[i][0]][road[i][1]] == 0 || edges[road[i][0]][road[i][1]] > road[i][2]) {
            edges[road[i][0]][road[i][1]] = road[i][2];
            edges[road[i][1]][road[i][0]] = road[i][2];
        }
    }
    priority_queue<int, vector<int>, comp> pq;
    dp[1] = 0;
    pq.push(1);

    while (!pq.empty()) {
        int now = pq.top();
        pq.pop();
        for (int i = 1; i <= N; ++i) {
            if (edges[now][i] != 0 && dp[i] > dp[now] + edges[now][i]) {
                dp[i] = dp[now] + edges[now][i];
                pq.push(i);
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (dp[i] <= K) answer++;
    }
    return answer;
}
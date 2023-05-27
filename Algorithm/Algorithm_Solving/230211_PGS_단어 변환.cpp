#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool can_trans(string A, string B) {
    int l = A.length();
    for (int i = 0; i < l; ++i) {
        bool c = true;
        for (int j = 0; j < l; ++j) {
            if (i == j) continue;
            if (A[j] != B[j]) {
                c = false;
                break;
            }
        }
        if (c) return true;
    }
    return false;
}


void dfs(int* answer, int n,int N, int idx, int goal, int visit, vector<vector<bool>> edges) {
    if (n >= *answer) return;
    if (idx == goal) {
        *answer = n;
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (!(visit & (1 << i)) && edges[idx][i]) {
            dfs(answer, n + 1, N, i, goal, visit | (1 << i), edges);
        }
    }
    return;
}


int solution(string begin, string target, vector<string> words) {
    
    int answer = 1e10;
    int N = words.size();
    int goal = -1;
    vector<vector<bool>>edges(N,vector<bool>(N,false));

    for (int i = 0; i < N; ++i) if (target == words[i]) goal = i;
    if (goal == -1) return 0;

    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j) {
            edges[i][j] = can_trans(words[i], words[j]);
            edges[j][i] = edges[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        if (can_trans(begin, words[i])) {
            dfs(&answer, 1, N, i, goal, 1<<i, edges);
        }
    }
    return answer;
}


int main() {
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}
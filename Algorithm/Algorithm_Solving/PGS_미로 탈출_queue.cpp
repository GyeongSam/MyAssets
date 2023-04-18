#include <string>
#include <vector>
#include <iostream>
// #include <stack>
#include <queue>

using namespace std;


struct mat {
    int i, j, t;
};
int di[4] = { 1,0,-1,0 };
int dj[4] = { 0,1,0,-1 };
mat operator+(mat m, int d) {
    mat temp = { m.i + di[d],m.j + dj[d],m.t + 1 };
    return temp;
}

int li, lj;

int bfs(mat S, mat E, vector<string>& maps) {

    vector<vector<bool>> visit(li, vector<bool>(lj, false));
    queue<mat> q;
    q.push(S);
    visit[S.i][S.j] = true;

    while (!q.empty()) {

        mat now = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            mat next = now + d;
            if (next.i < 0 || next.i >= li || next.j < 0 || next.j >= lj || visit[next.i][next.j]) continue;
            if (next.i == E.i && next.j == E.j) return next.t;
            if (maps[next.i][next.j] != 'X') {
                visit[next.i][next.j] = true;
                q.push(next);
            }
        }
    }
    return -1;


}



int solution(vector<string> maps) {
    int answer = -1;
    mat S, E, L;
    li = maps.size();
    lj = maps[0].size();
    for (int i = 0; i < li; ++i) {
        for (int j = 0; j < lj; ++j) {
            if (maps[i][j] == 'S') {
                S.i = i; S.j = j; S.t = 0;
            }
            else if (maps[i][j] == 'E') {
                E.i = i; E.j = j; E.t = 0;
            }
            else if (maps[i][j] == 'L') {
                L.i = i; L.j = j; L.t = 0;
            }
        }
    }

    int ans1 = bfs(S, L, maps);
    if (ans1 == -1) return answer;
    int ans2 = bfs(L, E, maps);
    if (ans2 != -1) answer = ans1 + ans2;
    return answer;
}
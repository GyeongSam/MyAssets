#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct AX {
    int i, j;
    AX(int ii, int jj) {
        i = ii;
        j = jj;
    }
    bool operator==(AX temp) {
        return i == temp.i && j == temp.j;
    }
};
bool operator==(AX a, AX b) {
    return a.i == b.i && a.j == b.j;
}

vector <AX> Searching(AX first, vector<vector<int>>& board, const vector<int>& di, const vector<int>& dj) {
    const int N = board.size();
    const int target = board[first.i][first.j];
    const int marking = 1 - target;

    board[first.i][first.j] = marking;

    vector <AX> block;

    vector <AX> stack;
    stack.push_back(first);

    while (!stack.empty()) {
        AX now = stack.back();
        stack.pop_back();
        for (int d = 0; d < 4; ++d) {
            AX next(now.i + di[d], now.j + dj[d]);
            if (next.i >= 0 && next.i < N && next.j >= 0 && next.j < N && board[next.i][next.j] == target) {
                board[next.i][next.j] = marking;
                AX dAX(next.i - first.i, next.j - first.j);
                block.push_back(dAX);
                stack.push_back(next);
            }
        }
    }
    return block;
}

void Checking(vector<AX>& onTable_root, vector<vector<AX>>& onTable_shape, vector<vector<int>>& table, vector<vector<AX>>& blocks, int& answer) {
    for (int i = onTable_shape.size() - 1; i >= 0; --i) {
        bool isMatching = false;
        for (int j = blocks.size() - 1; j >= 0; --j) {
            if (blocks[j] == onTable_shape[i]) {
                answer += blocks[j].size() + 1;
                blocks.erase(blocks.begin() + j);
                onTable_shape.erase(onTable_shape.begin() + i);
                onTable_root.erase(onTable_root.begin() + i);
                isMatching = true;
                break;
            }
        }
        if (!isMatching) {
            table[onTable_root[i].i][onTable_root[i].j] = 1;
            for (int n = 0; n < onTable_shape[i].size(); ++n) {
                table[onTable_root[i].i + onTable_shape[i][n].i][onTable_root[i].j + onTable_shape[i][n].j] = 1;
            }
        }
    }
}

vector<vector<int>> Turn(vector<vector<int>>& before) {
    int N = before.size();
    vector<vector<int>> after(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            after[i][j] = before[N - j - 1][i];
        }
    }
    return after;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    const int N = game_board.size();
    vector<vector<AX>> blocks;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (game_board[i][j] == 0) {
                vector<AX> block = Searching(AX(i, j), game_board, { 0,1,0,-1 }, { 1,0,-1,0 });
                blocks.push_back(block);
            }
        }
    }

    vector<AX> onTable_root;
    vector<vector<AX>> onTable_shape;
    for (int n = 0; n < 4; ++n) {
        onTable_root.clear();
        onTable_shape.clear();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (table[i][j] == 1) {
                    vector<AX> block = Searching(AX(i, j), table, { 0,1,0,-1 }, { 1,0,-1,0 });
                    onTable_root.push_back(AX(i, j));
                    onTable_shape.push_back(block);
                }
            }
        }
        Checking(onTable_root, onTable_shape, table, blocks, answer);
        if (n != 4) {
            vector<vector<int>> temp;
            temp = Turn(table);
            table = move(temp);
        }
    }
    return answer;
}
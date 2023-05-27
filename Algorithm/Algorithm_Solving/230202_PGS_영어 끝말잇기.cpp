#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    int temp = 1;
    bool c = false;
    char last = words[0].back();
    cout << last << "\n";

    for (int i = 1; i < words.size(); ++i) {

        cout << "c" << c << "  temp:" << temp << "\n";

        if (last != words[i][0]) {
            c = true;
            cout << "여기서 걸림"<< "\n";

            break;
        }
        for (int j = 0; j < i; ++j) {
            if (words[i] == words[j]) {
                c = true;
                cout << "저기서 걸림" << "\n";
                break;
            }
        }
        if (c) break;
        temp++;
        last = words[i].back();
    }
    vector <int> answer(2, 0);

    if (c){
        answer[0] = temp % n + 1;
        answer[1] = temp / n + 1;
    }
    return answer;
}

int main() {
    vector<int> answer = solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" });
    cout << answer[0] << answer[1];
}
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;




int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map <string, int> count;
    for (int i = 0; i < clothes.size(); ++i) {
        if (count.find((clothes[i][1])) == count.end()) {
            count.insert({ clothes[i][1], 1 });
        }
        else count[(clothes[i][1])]++;
    }

    for (map<string, int>::iterator iter = count.begin(); iter != count.end(); ++iter) {
        answer *= (iter->second+1);
    }
    return --answer;
}

int main() {

}
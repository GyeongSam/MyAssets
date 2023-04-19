#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


struct genre {
    int sum;
    vector <pair<int, int>> ids;
};

bool comp(pair<string, genre> A, pair<string, genre> B) {
    return A.second.sum > B.second.sum;
}
bool comp2(pair<int, int>A, pair<int, int> B) {
    if (A.first != B.first) return A.first > B.first;
    else return A.second < B.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map <string, genre> um;

    for (int i = 0; i < plays.size(); ++i) {
        if (um.find(genres[i]) != um.end()) {
            um[genres[i]].sum += plays[i];
            um[genres[i]].ids.emplace_back(plays[i], i);
        }
        else {
            genre c;
            c.sum = plays[i];
            c.ids.emplace_back(plays[i], i);
            um[genres[i]] = c;
        }
    }

    vector<pair<string, genre>> temp(um.begin(), um.end());
    sort(temp.begin(), temp.end(), comp);

    for (int i = 0; i < temp.size(); ++i) {
        sort(temp[i].second.ids.begin(), temp[i].second.ids.end(), comp2);
        answer.push_back(temp[i].second.ids[0].second);
        if (temp[i].second.ids.size() != 1) answer.push_back(temp[i].second.ids[1].second);
    }
    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


bool solution(vector<string> phone_book) {
    bool answer = true;



    for (int l = 1; l < 21; ++l) {
        unordered_map <string, bool> um;
        for (int i = 0; i < phone_book.size(); ++i) {
            int temp = phone_book[i].size();
            if (temp > l) {
                string sub(phone_book[i].substr(0, l));
                if (um.find(sub) != um.end() && um[sub] == true) {
                    answer = false;
                    break;
                }
                um[sub] == false;
            }
            else if (temp == l) {
                if (um.find(phone_book[i]) != um.end()) {
                    answer = false;
                    break;
                }
                um[phone_book[i]] = true;
            }
        }
    }


    return answer;
}
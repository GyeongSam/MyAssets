#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector <int> pre(26,-1);
    for (int i=0; i<skill.size();++i){
        pre[skill[i]-'A']=i;
    }
    for (auto iter = skill_trees.begin();iter!=skill_trees.end();++iter){
        int order=0;
        answer++;
        for (int i=0; i<(*iter).size();++i){
            int idx = pre[(*iter)[i]-'A'];
            if (idx==-1) continue;
            else if (idx!=order) {
                answer--;
                break;
            }
            else order++;
        }
    }
    
    return answer;
}
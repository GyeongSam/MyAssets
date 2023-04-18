#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue <int> q;
    
    for (int i=0; i<priorities.size();++i){ 
        q.push(priorities[i]);
    }
    sort(priorities.begin(),priorities.end());
    
    while (!priorities.empty()){
        int temp = q.front();
        q.pop();
        
        if (temp!=priorities.back()){
            q.push(temp);
        }
        else {
            answer++;
            if (location==0) break;
            priorities.pop_back();
        }
        if (--location<0) location = priorities.size()-1;
    }
    
    
    return answer;
}
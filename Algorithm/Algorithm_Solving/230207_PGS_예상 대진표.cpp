#include <iostream>
#include <math.h>
using namespace std;
int solution(int n, int a, int b)
{
    int answer=0;
    int l = 1;
    int r = n;
    while (true){
        int c = (l + r) / 2;
        if (c < a && c < b) l=c+1;
        else if (a <= c && b <= c) r=c;
        else break;
        answer++;
    }
    return log2(n) - answer;
}

int main() {
    cout << solution(8, 4, 7);
}
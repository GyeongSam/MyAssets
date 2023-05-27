#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;
    while (n) {
        if (n % 2) {
            n -= 1;
            answer++;
        }
        else n /= 2;
            

    }
    return answer;
}
int main() {
    cout << solution(5);
}
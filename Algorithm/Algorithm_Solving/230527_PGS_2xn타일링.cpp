#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<long long> dpTable(n + 1);

    dpTable[0] = 1;
    dpTable[1] = 1;

    for (int i = 2; i <= n; ++i) dpTable[i] = (dpTable[i - 1] + dpTable[i - 2]) % 1000000007;
    return dpTable[n];
}
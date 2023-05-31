#include <string>
#include <vector>
using namespace std;

long long comp(long long target, vector<int>& times) {
    long long temp = 0;
    for (int i = 0; i < times.size(); ++i) {
        temp += target / times[i];
    }
    return temp;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long l = 1;
    long long r = 1 << 30;

    while (comp(r, times) < n) {
        l = r;
        r *= 2;
    }
    while (l <= r) {
        long long m = (l + r) / 2;
        if (comp(m, times) < n) {
            l = m + 1;
        }
        else r = m - 1;
    }
    return l;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool promissing(long long mid, vector<int> times, int n)
{
    long long sum = 0;
    for (int i = 0; i < times.size(); i++) {
        sum += (mid / times[i]);
    }
    if (sum >= n)
        return true;
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long left = 1;
    long long max_time = times[times.size() - 1];
    long long right = max_time * n;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (promissing(mid, times, n)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}
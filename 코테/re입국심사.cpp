#include<string>
#include<vector>
#include<algorithm>
using  namespace std;

bool promissing(long long mid, int n, vector<int> times)
{
	long long sum = 0;
	for (int i = 0; i < times.size(); i++) {
		sum += (mid / times[i]);
	}
	if (sum >= n)return true;
	return false;
}

long long solution(int n, vector<int> times) {
	long long answer = 0;
	sort(times.begin(), times.end());
	long long max_time = times[times.size() - 1];
	long long high = max_time * n;
	long long low = 1;
	while (low <= high) {
		long long mid = (high + low) / 2;
		if (promissing(mid, n, times)) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}
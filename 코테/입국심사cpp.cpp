#include<string>
#include<vector>
using namespace std;

long long Binary_Search(long long mid, vector<int> t) {
	long long result = 0;
	for (int i = 0; i < t.size(); i++) {
		result += (mid / t[i]);
	}
	return result;
}

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long start = 1;
	long long end = 0;
	long long temp = 0;
	for (int i = 0; i < times.size(); i++) {
		if (temp < times[i])temp = times[i];
	}
	end = temp * n;
	while (start <= end) {
		long long mid = (start + end) / 2;
		if (Binary_Search(mid, times) < n) {
			start = mid + 1;
		}
		else {
			answer = mid;
			end = mid - 1;
		}
	}
	return answer;
}
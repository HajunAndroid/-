#include<iostream>
#include<algorithm>
#define MAX 1000000
using namespace std;

long long n, m;
long long tree[MAX];

bool checking(int len)
{
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (tree[i] > len) {
			cnt += (tree[i] - len);
		}
	}
	if (cnt >= m)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	long long high = 0;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		high = max(high, tree[i]);
	}
	long long low = 1;
	long long mid;
	long long result = 0;
	while (low <= high) {
		mid = (high + low) / 2;
		if (checking(mid)) {
			if (result < mid)
				result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result;
	return 0;
}
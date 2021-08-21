#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;

int n, k;
int arr[MAX];

void Input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
}


bool Promissing(int mid)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += (arr[i] / mid);
	}
	if (cnt >= k) {
		return true;
	}
	return false;
}

void Solution()
{
	long long low = 1;
	long long high = arr[n];
	long long mid;
	long long answer = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (Promissing(mid)) {
			low = mid + 1;
			if (answer < mid) {
				answer = mid;
			}
		}
		else {
			high = mid - 1;
		}
	}
	cout << answer;
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
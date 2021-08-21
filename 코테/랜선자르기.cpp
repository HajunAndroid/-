#include<iostream>
#include<algorithm>
#define MAX 10000
using namespace std;

int k, n;
int arr[MAX];
long long ans;

void Input()
{
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + k);
}

bool promising(int dist)
{
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += (arr[i] / dist);
	}
	if (cnt >= n)
		return true;
	else
		return false;
}

void Solution()
{
	long long low = 1;
	long long high = arr[k - 1];
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (promising(mid)) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans;
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
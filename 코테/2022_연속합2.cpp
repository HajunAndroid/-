#include<iostream>
#include<algorithm>
#define MAX 100010
using namespace std;

int n;
int arr[MAX];
int left_sum[MAX];
int right_sum[MAX];

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void Solution()
{
	left_sum[1] = arr[1];
	int ans = left_sum[1];
	for (int i = 2; i <= n; i++) {
		left_sum[i] = max(left_sum[i - 1] + arr[i], arr[i]);
		ans = max(ans, left_sum[i]);
	}
	right_sum[n] = arr[n];
	for (int i = n - 1; i >= 1; i--) {
		right_sum[i] = max(right_sum[i + 1] + arr[i], arr[i]);
	}
	for (int i = 2; i < n; i++) {
		ans = max(ans, left_sum[i - 1] + right_sum[i + 1]);
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
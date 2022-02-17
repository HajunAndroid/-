#include<iostream>
#define MAX 100010
using namespace std;

int n, ans;
int arr[MAX];
int left_sum[MAX];
int right_sum[MAX];

int Max(int a, int b) { return a > b ? a : b; }

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void Solution()
{
	if (n == 1) {
		cout << arr[1];
		return;
	}
	left_sum[1] = arr[1];
	ans = left_sum[1];
	for (int i = 2; i <= n; i++) {
		left_sum[i] = Max(arr[i], left_sum[i - 1] + arr[i]);
		ans = Max(ans, left_sum[i]);
	}
	right_sum[n] = arr[n];
	for (int i = n - 1; i >= 1; i--) {
		right_sum[i] = Max(arr[i], right_sum[i + 1] + arr[i]);
	}
	
	for (int i = 2; i <= n - 1; i++) {
		ans = Max(ans, left_sum[i - 1] + right_sum[i + 1]);
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
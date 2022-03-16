#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;

int arr[MAX];
int dp[MAX];

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int ans = -1e9;
	dp[1] = arr[1];
	ans = max(ans, dp[1]);
	for (int i = 2; i <= n; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
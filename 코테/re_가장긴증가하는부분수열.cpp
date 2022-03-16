#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;

int n;
int arr[MAX];
int dp[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
#include<iostream>
#include<algorithm>
#define MAX 1010
using namespace std;

int n;
int arr[MAX];
int dp[MAX];

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void Solve()
{
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(dp[i], ans);
	}
	cout << ans;
}

void Solve()
{
	Input();
	Solve();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
#include<iostream>
#include<cstring>
#define MAX 110
#define MODULER 1234567891
using namespace std;

int n, last, answer;
int arr[MAX];
long long dp[MAX][25];

void Initialize()
{
	memset(dp, 0, sizeof(dp));
}

void Input()
{
	cin >> n;
	for (int i = 1; i < n; i++)cin >> arr[i];
	cin >> last;
}

void Solution()
{
	dp[1][arr[1]] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - arr[i] >= 0)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i]]) % MODULER;
			if (j + arr[i] <= 20)
				dp[i][j] = (dp[i][j] + dp[i - 1][j + arr[i]]) % MODULER;
		}
	}
	answer = dp[n - 1][last] % MODULER;
}
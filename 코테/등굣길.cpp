#include<string>
#include<vector>
using namespace std;

int solution(int m, int n, vector<vector<int>>puddles)
{
	int dp[101][101] = { 0 };
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i <= m; i++) {
		dp[1][i] = 1;
	}
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][1]][puddles[i][0]] = -1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			if (dp[i][j] == -1) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
			}
		}
	}
	return dp[n][m];
}
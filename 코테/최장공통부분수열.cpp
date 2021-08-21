#include<iostream>
#include<cstring>
#define MAX 1001
using namespace std;

char a[MAX], b[MAX];
int dp[MAX][MAX];

int Bigger(int a, int b) { if (a > b)return a; return b; }

void Input()
{
	cin >> a >> b;
}

void Solution()
{
	int a_size = strlen(a);
	int b_size = strlen(b);
	for (int i = 1; i <= a_size; i++) {
		for (int j = 1; j <= b_size; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = Bigger(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[a_size][b_size] << endl;
	cout << a_size;
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
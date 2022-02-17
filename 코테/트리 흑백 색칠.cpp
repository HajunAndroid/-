#include<iostream>
#include<cstring>
#include<vector>
#define MAX 100010
#define MODULER 1000000007
using namespace std;

int n;
long long answer;
long long dp[MAX][2];
vector<int> node[MAX];

void Initialize()
{
	for (int i = 0; i < MAX; i++)
		node[i].clear();
	memset(dp, -1, sizeof(dp));
}

void Input()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
}

long long DFS(int cur, int color, int parent)
{
	if (dp[cur][color] != -1)return dp[cur][color];
	dp[cur][color] = 1;
	
	for (int i = 0; i < node[cur].size(); i++) {
		int next = node[cur][i];
		if (next == parent)continue;

		if (color == 0) {
			dp[cur][color] = dp[cur][color] * (DFS(next, 0, cur) + DFS(next, 1, cur));
			dp[cur][color] = dp[cur][color] % MODULER;
		}
		else {
			dp[cur][color] = dp[cur][color] * (DFS(next, 0, cur));
			dp[cur][color] = dp[cur][color] % MODULER;
		}
	}
	return dp[cur][color];
}

void Solution()
{
	long long result = DFS(1, 0, -1) % MODULER;
	long long result2 = DFS(1, 1, -1) % MODULER;
	answer = result + result2;
	answer = answer % MODULER;
}

void Solve()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		Initialize();
		Input();
		Solution();
		cout << "#" << i << " " << answer << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
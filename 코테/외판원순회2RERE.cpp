#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 11
using namespace std;

int n;
int map[MAX][MAX];
int visited[MAX];

int ans;

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	ans = 987654321;
}

void DFS(int start, int now, int sum, int cnt)
{
	if (cnt == n && start == now) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!map[now][i])continue;
		if (visited[i])continue;
		if (ans < sum + map[now][i])continue;
		visited[i] = 1;
		DFS(start, i, sum + map[now][i], cnt + 1);
		visited[i] = 0;
	}
}

void Solution()
{
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		DFS(i, i, 0, 0);
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
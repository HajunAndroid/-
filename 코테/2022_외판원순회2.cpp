#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 11
using namespace std;

int n;
int map[MAX][MAX];
int visited[MAX];
int ans = 1e9;

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int start, int x, int sum, int cnt)
{
	if (cnt == n && start == x) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (map[x][i] == 0)continue;
		if (visited[i])continue;
		if (ans <= sum + map[x][i])continue;
		visited[i] = 1;
		bfs(start, i, sum + map[x][i], cnt + 1);
		visited[i] = 0;
	}
}

void Solution()
{
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		bfs(i, i, 0, 0);
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
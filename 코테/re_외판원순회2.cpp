#include<iostream>
#include<cstring>
#define MAX 11
using namespace std;
int n;
int map[MAX][MAX];
bool visited[MAX];
int ans = 1e9;

void dfs(int End, int start, int cnt, int sum)
{
	if (cnt == n && start == End) {
		if (sum < ans)
			ans = sum;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i])continue;
		if (map[start][i] == 0)continue;
		if (sum + map[start][i] > ans)continue;
		visited[i] = 1;
		dfs(End, i, cnt + 1, sum + map[start][i]);
		visited[i] = 0;
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i, 0, 0);
	}
	cout << ans;
	return 0;
}
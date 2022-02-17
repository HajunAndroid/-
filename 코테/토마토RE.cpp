#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 1001
using namespace std;

int m, n;
int map[MAX][MAX];
int visited[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

queue<pair<int, int>>q;

void Input()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
}

void Solve()
{
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx<1 || ny<1 || nx>n || ny>m)continue;
			if (map[nx][ny] == -1)continue;
			if (visited[nx][ny])continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != -1 && visited[i][j] == 0) {
				cout << "-1";
				return;
			}
			cnt = max(cnt, visited[i][j]);
		}
	}
	cout << cnt - 1;
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
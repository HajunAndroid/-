#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];

int m, n;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void Input()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= m; j++) {
			map[i][j] = temp.at(j - 1) - '0';
			visited[i][j] = 1e9;
		}
	}
}

void bfs(int x, int y)
{
	visited[1][1] = 0;
	queue<pair<int, int>>q;
	q.push({ 1,1 });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m)continue;
			if (map[nx][ny] == 1) {
				if (visited[nx][ny] > visited[x][y] + 1) {
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
				}
			}
			else {
				if (visited[nx][ny] > visited[x][y]) {
					visited[nx][ny] = visited[x][y];
					q.push({ nx,ny });
				}
			}
		}
	}
}

void Solution()
{
	bfs(1, 1);
	cout << visited[n][m];
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
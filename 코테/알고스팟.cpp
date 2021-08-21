#include<iostream>
#include<cstring>
#include<queue>
#define MAX 101
using namespace std;

int n, m;
int map[MAX][MAX];
int dist[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string temp; cin >> temp;
		for (int j = 1; j <= m; j++) {
			map[i][j] = temp.at(j - 1) - '0';
			dist[i][j] = 1e9;
		}
	}
	dist[1][1] = 0;
}

void Solution()
{
	queue<pair<int, int>>q;
	q.push({ 1,1 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (map[nx][ny] == 1) {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
			}
			else if (map[nx][ny] == 0) {
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					q.push({ nx,ny });
				}
			}
		}
	}
	cout << dist[n][m];
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
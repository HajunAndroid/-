#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j + 1] = s.at(j) - '0';
		}
	}
}

void BFS(int x, int y)
{
	queue<pair<int, int>>q;
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m)continue;
			if (visited[nx][ny])continue;
			if (!map[nx][ny])continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}

void Solve()
{
	BFS(1, 1);
	cout << visited[n][m];
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
#include<iostream>
#include<queue>
#include<cstring>
#define MAX 301
using namespace std;

int map[MAX][MAX];
int c_map[MAX][MAX];
bool visited[MAX][MAX];
int N, M;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
}

bool IsFinsh()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] != 0)
				return false;
		}
	}
	return true;
}

void CopyMap()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = c_map[i][j];
		}
	}
}

void BFS(int x, int y)
{
	visited[x][y] = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		int water = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M)continue;
			if (visited[nx][ny])continue;
			if (map[nx][ny] == 0)water++;
			if (map[nx][ny] != 0) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
		int now = map[x][y] - water;
		if (now < 0)now = 0;
		c_map[x][y] = now;
	}
}

void Solve()
{
	int year = 0;
	while (!IsFinsh()) {
		memset(visited, 0, sizeof(visited));
		memset(c_map, 0, sizeof(c_map));
		int island = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] == 0 || visited[i][j] != 0)continue;
				island++;
				BFS(i, j);
			}
		}
		if (island >= 2) {
			cout << year;
			return;
		}
		CopyMap();
		year++;
	}
	cout << "0";
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
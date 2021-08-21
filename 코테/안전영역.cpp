#include<iostream>
#include<queue>
#include<cstring>
#define MAX 101
using namespace std;

int N, H;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> N;
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			map[i][j] = temp;
			if (H < temp)
				H = temp;
		}
	}
}

void BFS(int x, int y, int h)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N)continue;
			if (map[nx][ny] <= h)continue;
			if (visited[nx][ny])continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

void Solution()
{
	int ans=0;
	for (int h = 0; h <= H; h++) {
		memset(visited, 0, sizeof(visited));
		int temp = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] <= h)continue;
				if (visited[i][j])continue;
				temp++;
				BFS(i, j, h);
			}
		}
		if (ans < temp)
			ans = temp;
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
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
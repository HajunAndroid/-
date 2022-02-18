#include<iostream>
#include<queue>
#include<cstring>
#define MAX 129
using namespace std;

int map[MAX][MAX];
int n;

int blue, white;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int x, int y, int s)
{
	if (s == 1) {
		if (map[x][y] == 0) {
			white++;
			return;
		}
		else {
			blue++;
			return;
		}
	}
	bool visited[MAX][MAX] = { 0, };
	bool flag = true;
	int color = map[x][y];
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty() && flag) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx < x || ny < y || nx >= x + s || ny >= y + s)continue;
			if (visited[nx][ny])continue;
			if (map[nx][ny] != color) {
				bfs(x, y, s / 2);
				bfs(x + s / 2, y, s / 2);
				bfs(x, y + s / 2, s / 2);
				bfs(x + s / 2, y + s / 2, s / 2);
				flag = false;
				break;
			}
			else {
				q.push({ nx,ny });
				visited[nx][ny] = 1;
			}
		}
	}
	if (flag) {
		if (color == 0) {
			white++;
		}
		else {
			blue++;
		}
	}
}

void Solution()
{
	bfs(1, 1, n);
	cout << white << '\n';
	cout << blue;
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
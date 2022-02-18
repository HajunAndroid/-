#include<iostream>
#include<cstring>
#include<queue>
#define MAX 101
using namespace std;

int N, L, R;
int map[MAX][MAX];
int visited[MAX][MAX];
int ans;
bool flag = true;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> c_q;
	q.push({ x,y });
	c_q.push({ x,y });
	visited[x][y] = 1;
	int cnt = 1;
	int sum = map[x][y];
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N)continue;
			if (visited[nx][ny] == 1)continue;
			if (abs(map[x][y] - map[nx][ny]) >= L && abs(map[x][y] - map[nx][ny]) <= R) {
				q.push({ nx,ny });
				c_q.push({ nx,ny });
				visited[nx][ny] = 1;
				cnt++;
				sum += map[nx][ny];
			}
		}
	}
	if (cnt > 1)flag = true;
	int temp = sum / cnt;
	while (!c_q.empty()) {
		x = c_q.front().first;
		y = c_q.front().second;
		c_q.pop();
		map[x][y] = temp;
	}
}

void Solution()
{
	while (flag) {
		ans++;
		flag = false;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i][j] == 1)continue;
				bfs(i, j);
			}
		}
	}
	ans--;
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
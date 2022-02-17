#include<iostream>
#include<cstring>
#include<queue>
#define MAX 50
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
bool visited2[MAX][MAX];
int n, l, r;
int ans;
bool flag;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	cin >> n >> l >> r;
	ans = 0;
	flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

bool Checking(int x, int y, int xx, int yy)
{
	int temp = abs(map[x][y] - map[xx][yy]);
	if (temp >= l && temp <= r)return true;
	return false;
}

void BFS(int x, int y)
{
	memset(visited2, 0, sizeof(visited2));
	visited[x][y] = 1;
	visited2[x][y] = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	int sum = map[x][y]; int cnt = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (visited[nx][ny] == true ||
				visited2[nx][ny] == true)continue;
			if (!Checking(x, y, nx, ny))continue;
			visited[nx][ny] = 1;
			visited2[nx][ny] = 1;
			q.push({ nx,ny });
			sum += map[nx][ny];
			cnt++;
		}
	}
	if (cnt != 1)
		flag = true;
	else
		return;
	int temp = sum / cnt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited2[i][j])
				map[i][j] = temp;
		}
	}
}

void Solution()
{
	while (flag) {
		flag = false;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					BFS(i, j);
				}
			}
		}
		if (flag)
			ans++;
	}
	cout << ans << '\n';
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
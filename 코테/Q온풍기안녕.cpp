#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define MAX 21
using namespace std;

int R, C, K;
int map[MAX][MAX];
int wall[MAX][MAX];
int c_map[MAX][MAX];
int visited[MAX][MAX];
vector<pair<pair<int, int>, int>> fan;
vector<pair<int, int>> check;
int ans;

int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };

void Input()
{
	cin >> R >> C >> K;
	int temp;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> temp;
			if (temp == 0)continue;
			if (temp == 5)check.push_back({ i,j });
			else fan.push_back({ {i,j},temp });
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			wall[i][j] = -1;
		}
	}
	cin >> temp;
	int x, y, t;
	for (int i = 0; i < temp; i++) {
		cin >> x >> y >> t;
		wall[x][y] = t;
	}
}

bool DirCheck(int x, int y)
{
	if (x<1 || y<1 || x>R || y>C)return false;
	return true;
}

void Dir1(int x, int y)
{
	memset(visited, 0, sizeof(visited));
	visited[x][y + 1] = 1;
	c_map[x][y + 1] = 5;
	queue<pair<int, int>>q;
	q.push({ x,y + 1 });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (c_map[x][y] == 0)continue;
		if (wall[x][y] != 0 && wall[x - 1][y] != 1 && DirCheck(x - 1, y + 1) && visited[x - 1][y + 1] == 0) {
			c_map[x - 1][y + 1] = c_map[x][y] - 1;
			visited[x - 1][y + 1] = 1;
			q.push({ x - 1,y + 1 });
		}
		if (wall[x][y] != 1 && DirCheck(x, y + 1) && visited[x][y + 1] == 0) {
			c_map[x][y + 1] = c_map[x][y] - 1;
			visited[x][y + 1] = 1;
			q.push({ x,y + 1 });
		}
		if (wall[x + 1][y] == -1 && DirCheck(x + 1, y + 1) && visited[x + 1][y + 1] == 0) {
			c_map[x + 1][y + 1] = c_map[x][y] - 1;
			visited[x + 1][y + 1] = 1;
			q.push({ x + 1,y + 1 });
		}
	}
}

void Dir2(int x, int y)
{
	memset(visited, 0, sizeof(visited));
	visited[x][y - 1] = 1;
	c_map[x][y - 1] = 5;
	queue<pair<int, int>>q;
	q.push({ x,y - 1 });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (c_map[x][y] == 0)continue;
		if (wall[x][y] != 0 && wall[x-1][y-1] != 1 && DirCheck(x - 1, y - 1) && visited[x - 1][y - 1] == 0) {
			c_map[x - 1][y - 1] = c_map[x][y] - 1;
			visited[x - 1][y - 1] = 1;
			q.push({ x - 1,y - 1 });
		}
		if (wall[x][y-1] != 1 && DirCheck(x, y - 1) && visited[x][y - 1] == 0) {
			c_map[x][y - 1] = c_map[x][y] - 1;
			visited[x][y - 1] = 1;
			q.push({ x,y - 1 });
		}
		if (wall[x + 1][y] !=0 && DirCheck(x + 1, y-1) && visited[x + 1][y-1] == 0) {
			c_map[x + 1][y-1] = c_map[x][y] - 1;
			visited[x + 1][y - 1] = 1;
			q.push({ x + 1,y - 1 });
		}
	}
}

void Dir3(int x, int y)
{
	memset(visited, 0, sizeof(visited));
	visited[x-1][y] = 1;
	c_map[x-1][y] = 5;
	queue<pair<int, int>>q;
	q.push({ x-1,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (c_map[x][y] == 0)continue;
		if (wall[x][y-1]==-1&&DirCheck(x - 1, y - 1) && visited[x - 1][y - 1] == 0) {
			c_map[x - 1][y - 1] = c_map[x][y] - 1;
			visited[x - 1][y - 1] = 1;
			q.push({ x - 1,y - 1 });
		}
		if (wall[x][y] != 0 && DirCheck(x-1, y) && visited[x-1][y] == 0) {
			c_map[x-1][y] = c_map[x][y] - 1;
			visited[x-1][y] = 1;
			q.push({ x-1,y});
		}
		if (wall[x][y]!=1&&wall[x][y+1] != 0 && DirCheck(x -1, y + 1) && visited[x - 1][y + 1] == 0) {
			c_map[x - 1][y + 1] = c_map[x][y] - 1;
			visited[x - 1][y + 1] = 1;
			q.push({ x - 1,y + 1 });
		}
	}
}

void Dir4(int x, int y)
{
	memset(visited, 0, sizeof(visited));
	visited[x + 1][y] = 1;
	c_map[x + 1][y] = 5;
	queue<pair<int, int>>q;
	q.push({ x + 1,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (c_map[x][y] == 0)continue;
		if (wall[x][y - 1] !=1&&wall[x+1][y-1]!=0 && DirCheck(x + 1, y - 1) && visited[x + 1][y - 1] == 0) {
			c_map[x + 1][y - 1] = c_map[x][y] - 1;
			visited[x + 1][y - 1] = 1;
			q.push({ x + 1,y - 1 });
		}
		if (wall[x+1][y] != 0 && DirCheck(x + 1, y) && visited[x + 1][y] == 0) {
			c_map[x+ 1][y] = c_map[x][y] - 1;
			visited[x + 1][y] = 1;
			q.push({ x + 1,y });
		}
		if (wall[x][y] != 1 && wall[x+1][y + 1] != 0 && DirCheck(x + 1, y + 1) && visited[x + 1][y + 1] == 0) {
			c_map[x + 1][y + 1] = c_map[x][y] - 1;
			visited[x + 1][y + 1] = 1;
			q.push({ x + 1,y + 1 });
		}
	}
}

void First(int x, int y, int dir)
{
	if (dir == 1) Dir1(x, y);
	else if (dir == 2) Dir2(x, y);
	else if (dir == 3) Dir3(x, y);
	else if (dir == 4) Dir4(x, y);
}

bool IsDone()
{
	for (int i = 0; i < check.size(); i++) {
		int x = check[i].first;
		int y = check[i].second;
		if (map[x][y] < K)return false;
	}
	return true;
}

void Second()
{
	memset(c_map, 0, sizeof(c_map));
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int x = i; int y = j;
			c_map[x][y] += map[x][y];
			for (int k = 1; k <= 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx<1 || ny<1 || nx>R || ny>C)continue;
				if (k == 1 && wall[x][y] == 0)continue;
				if (k == 2 && wall[x][y] == 1)continue;
				if (k == 3 && wall[x + 1][y] == 0)continue;
				if (k == 4 && wall[x][y - 1] == 1)continue;
				if (map[x][y] - map[nx][ny] > 0) {
					c_map[x][y] -= ((map[x][y] - map[nx][ny]) / 4);
					c_map[nx][ny] += ((map[x][y] - map[nx][ny]) / 4);
				}
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j] = c_map[i][j];
		}
	}
}

void Third()
{
	for (int i = 1; i <= C; i++) {
		if (map[1][i] == 0)continue;
		map[1][i] -= 1;
		if (map[R][i] == 0)continue;
		map[R][i] -= 1;
	}
	for (int i = 2; i < R; i++) {
		if (map[i][1] == 0)continue;
		map[i][1] -= 1;
		if (map[i][C] == 0)continue;
		map[i][C] -= 1;
	}
}

void Solution()
{
	while (!IsDone()) {
		for (int i = 0; i < fan.size(); i++) {
			memset(c_map, 0, sizeof(c_map));
			First(fan[i].first.first, fan[i].first.second, fan[i].second);
			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
					map[i][j] += c_map[i][j];
				}
			}
		}
		Second();
		Third();
		ans++;
		if (ans >= 101) {
			ans == 101;
			break;
		}
	}
	cout << ans;
}

void Solve()
{
	Input();
	Solution();
	/*
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
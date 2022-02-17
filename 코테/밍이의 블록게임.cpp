#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 30
using namespace std;

char map[MAX][MAX];
int N, M, Q;

bool visited[MAX][MAX];
vector<pair<int, pair<int, int>>> v;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

void Trim()
{
	for (int i = 0; i < M; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (map[j][i] == '#')continue;
			int temp = j + 1;
			while (temp < N && map[temp][i] == '#')temp++;
			temp--;
			if (temp == j)continue;
			map[temp][i] = map[j][i];
			map[j][i] = '#';
		}
	}
}

void Up()
{
	string s; 
	cin >> s;
	bool flag = false;
	for (int i = 0; i < M; i++) {
		if (map[0][i] != '#') {
			flag = true;
			break;
		}
	}
	if (flag)return;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = map[i + 1][j];
		}
	}
	for (int i = 0; i < M; i++) {
		map[N - 1][i] = s.at(i);
	}
	Trim();
}

void DFS(int x, int y)
{
	char color = map[x][y];
	int cnt = 1;
	int tx = x;
	int ty = y;
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
			if (nx<0 || ny<0 || nx>N || ny>M)continue;
			if (visited[nx][ny])continue;
			if (map[nx][ny] != color)continue;
			cnt++;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	v.push_back({ cnt,{tx,ty} });
}

void DFS2(int x, int y)
{
	char color = map[x][y];
	bool visited2[MAX][MAX];
	memset(visited2, 0, sizeof(visited2));
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited2[x][y] = 1;
	map[x][y] = '#';
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>N || ny>M)continue;
			if (visited2[nx][ny])continue;
			if (map[nx][ny] != color)continue;
			visited2[nx][ny] = 1;
			map[nx][ny] = '#';
			q.push({ nx,ny });
		}
	}
}

bool cmp(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b)
{
	if (a.first > b.first)return true;
	return false;
}

void Down()
{
	memset(visited, 0, sizeof(visited));
	v.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '#')continue;
			if (visited[i][j] == 1)continue;
			DFS(i, j);
		}
	}
	if (v.size() == 0)return;
	sort(v.begin(), v.end(), cmp);
	int m = v[0].first;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first != m)continue;
		DFS2(v[i].second.first, v[i].second.second);
	}
	Trim();
}

void Left()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '#')continue;
			int temp = j - 1;
			while (temp >= 0 && map[i][temp] == '#') temp--;
			temp++;
			if (temp == j)continue;
			map[i][temp] = map[i][j];
			map[i][j] = '#';
		}
	}
}

void Right()
{
	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			if (map[i][j] == '#')continue;
			int temp = j + 1;
			while(temp < M && map[i][temp] == '#')temp++;
			temp--;
			if (temp == j)continue;
			map[i][temp] = map[i][j];
			map[i][j] = '#';
		}
	}
}

bool IsEmpty()
{
	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != '#') {
				flag = false;
				return flag;
			}
		}
	}
	return flag;
}

void Solution()
{
	while (Q--) {
		char button;
		cin >> button;
		if (button == 'U') {
			Up();
		}
		else if (button == 'D') {
			if (IsEmpty())continue;
			Down();
		}
		else if (button == 'R') {
			if (IsEmpty())continue;
			Right();
		}
		else if (button == 'L') {
			if (IsEmpty())continue;
			Left();
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}

void Print(int i)
{
	cout << "#" << i << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Solve()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		Input();
		Solution();
		Print(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
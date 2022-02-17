#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 51
using namespace std;

int map[MAX][MAX];
int c_map[MAX][MAX];

int dx[] = { 0, 0,-1,-1,-1,0,1,1,1 };
int dy[] = { 0, -1,-1,0,1,1,1,0,-1 };

int n, m;
queue<pair<int, int>>q_move;
vector<pair<int, int>>v_first;
vector<pair<int, int>>v_second;

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		q_move.push({ a,b });
	}
	v_first.push_back({ n,1 });
	v_first.push_back({ n,2 });
	v_first.push_back({ n - 1,1 });
	v_first.push_back({ n - 1,2 });
}

void Move()
{
	int d = q_move.front().first;
	int s = q_move.front().second;
	q_move.pop();
	s = s % n;
	for (int i = 0; i < v_first.size(); i++) {
		int x = v_first[i].first;
		int y = v_first[i].second;
		for (int k = 0; k < s; k++) {
			x = x + dx[d];
			if (x < 1)x = n;
			else if (x > n)x = 1;
			y = y + dy[d];
			if (y < 1)y = n;
			else if (y > n)y = 1;
		}
		v_first[i] = pair<int, int>(x, y);
	}
}

void Raining()
{
	for (int i = 0; i < v_first.size(); i++) {
		int x = v_first[i].first;
		int y = v_first[i].second;
		map[x][y] += 1;
	}
}

void Clone()
{
	queue<pair<pair<int, int>, int>>q;
	for (int i = 0; i < v_first.size(); i++) {
		int x = v_first[i].first;
		int y = v_first[i].second;
		int cnt = 0;
		for (int j = 2; j <= 8; j+=2) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx<1 || ny<1 || nx>n || ny>n)continue;
			if(map[nx][ny]!=0)
				cnt++;
		}
		if(cnt!=0)
			q.push({ {x,y},cnt });
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		map[x][y] += cnt;
	}
}

void NewCloud()
{
	memset(c_map, 0, sizeof(c_map));
	for (int i = 0; i < v_first.size(); i++) {
		int x = v_first[i].first;
		int y = v_first[i].second;
		c_map[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] < 2)continue;
			if (c_map[i][j])continue;
			v_second.push_back({ i,j });
			map[i][j] -= 2;
		}
	}
	v_first.clear();
	v_first = v_second;
	v_second.clear();
}

void Sum()
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += map[i][j];
		}
	}
	cout << sum;
}

void Solve()
{
	while (!q_move.empty()) {
		Move();
		Raining();
		Clone();
		NewCloud();
	}
	Sum();
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
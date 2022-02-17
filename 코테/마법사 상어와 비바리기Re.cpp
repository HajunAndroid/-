#include<iostream>
#include<cstring>
#include<vector>
#define MAX 55
using namespace std;

int n, m, answer;
int map[MAX][MAX];
bool cloud_map [MAX][MAX];
vector<pair<int, int>>cloud;
vector<pair<int, int>>cmd;

int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cmd.push_back({ a,b });
	}
}

void Init_Cloud()
{
	cloud.push_back(make_pair(n - 2, 0));
	cloud.push_back(make_pair(n - 2, 1));
	cloud.push_back(make_pair(n - 1, 0));
	cloud.push_back(make_pair(n - 1, 1));
	cloud_map[n - 2][0] = true;
	cloud_map[n - 2][1] = true;
	cloud_map[n - 1][0] = true;
	cloud_map[n - 1][1] = true;
}

int Make_Range(int x)
{
	if (x < 0)return n - 1;
	if (x >= n)return 0;
	return x;
}

void Move_Cloud(int idx)
{
	int dir = cmd[idx].first;
	int cnt = cmd[idx].second;
	memset(cloud_map, false, sizeof(cloud_map));
	for (int i = 0; i < cloud.size(); i++) {
		int x = cloud[i].first;
		int y = cloud[i].second;
		int nx = x;
		int ny = y;
		for (int j = 0; j < cnt; j++) {
			nx += dx[dir];
			ny += dy[dir];
			nx = Make_Range(nx);
			ny = Make_Range(ny);
		}
		cloud[i].first = nx;
		cloud[i].second = ny;
	}
	for (int i = 0; i < cloud.size(); i++) {
		int x = cloud[i].first;
		int y = cloud[i].second;
		cloud_map[x][y] = true;
	}
}

void Make_Rain()
{
	for (int i = 0; i < cloud.size(); i++) {
		int x = cloud[i].first;
		int y = cloud[i].second;
		map[x][y]++;
	}
}

void Water_Bug()
{
	for (int i = 0; i < cloud.size(); i++) {
		int x = cloud[i].first;
		int y = cloud[i].second;
		int cnt = 0;
		for (int j = 2; j <= 8; j += 2) {
			int nx = x + dx[i];
			int ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (map[nx][ny] >= 1)cnt++;
		}
		map[x][y] += cnt;
	}
}

void Delete_Cloud()
{
	cloud.clear();
}

void Make_Cloud()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cloud_map[i][j])continue;
			if (map[i][j] < 2)continue;
			map[i][j] -= 2;
			cloud.push_back({ i,j });
		}
	}
	memset(cloud_map, false, sizeof(cloud_map));
	for (int i = 0; i < cloud.size(); i++) {
		int x = cloud[i].first;
		int y = cloud[i].second;
		cloud_map[x][y] = true;
	}
}

void Find_Answer()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += map[i][j];
		}
	}
}

void solution()
{
	Init_Cloud();
	for (int i = 0; i < m; i++) {
		Move_Cloud(i);
		Make_Rain();
		Water_Bug();
		Delete_Cloud();
		Make_Cloud();
	}
	Find_Answer();
	cout << answer << endl;
}

void Solve()
{
	Input();
	solution();
}

int main()
{
	Solve();
	return 0;
}
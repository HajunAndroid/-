#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;

struct shark_Info
{
	int r;
	int c;
	int speed;
	int direct;
	int size;
};

int r, c, m, ans;
vector<int>map[MAX][MAX];
vector<shark_Info>shark;

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };

bool Standard(int a, int b)
{
	if (shark[a].size > shark[b].size)return true;
	return false;
}

void Input()
{
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark.push_back({ r,c,s,d,z });
		map[r][c].push_back(i);
	}
}

bool Check()
{
	for (int i = 0; i < shark.size(); i++) {
		if (shark[i].size != 0)return false;
	}
	return true;
}

void Fishing(int idx)
{
	for (int i = 1; i <= r; i++) {
		if (map[i][idx].size() != 0) {
			ans += shark[map[i][idx][0]].size;
			shark[map[i][idx][0]].size = 0;
			map[i][idx].pop_back();
			break;
		}
	}
}

void Move_Shark()
{
	for (int i = 0; i < shark.size(); i++) {
		if (shark[i].size == 0)continue;
		int x = shark[i].r;
		int y = shark[i].c;
		map[x][y].clear();
	}
	for (int i = 0; i < shark.size(); i++) {
		if (shark[i].size == 0)continue;
		int x = shark[i].r;
		int y = shark[i].c;
		int direct = shark[i].direct;
		int speed = shark[i].speed;
		if (direct == 1 || direct == 2){
			int rotate = (r - 1) * 2;
			if (speed >= rotate)speed = speed % rotate;
			for (int j = 0; j < speed; j++) {
				int nx = x + dx[direct];
				int ny = y + dy[direct];
				if (nx < 1) {
					direct = 2;
					nx += 2;
				}
				if (nx > r) {
					direct = 1;
					nx -= 2;
				}
				x = nx;
				y = ny;
			}
		}
		else {
			int rotate = (c - 1) * 2;
			if (speed >= rotate)speed = speed % rotate;
			for (int j = 0; j < speed; j++) {
				int nx = x + dx[direct];
				int ny = y + dy[direct];
				if (ny < 1) {
					direct = 3;
					ny += 2;
				}
				if (ny > c) {
					direct = 4;
					ny -= 2;
				}
				x = nx;
				y = ny;
			}
		}
		shark[i].r = x;
		shark[i].c = y;
		shark[i].direct = direct;
		map[x][y].push_back(i);
	}
}

void Kill_Shark()
{
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j].size() > 1) {
				sort(map[i][j].begin(), map[i][j].end(), Standard);
				int live_index = map[i][j][0];
				for (int k = 1; k < map[i][j].size(); k++) {
					shark[map[i][j][k]].size = 0;
				}
				map[i][j].clear();
				map[i][j].push_back(live_index);
			}
		}
	}
}

void Solution()
{
	for (int i = 1; i <= c; i++) {
		Fishing(i);
		Move_Shark();
		Kill_Shark();
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
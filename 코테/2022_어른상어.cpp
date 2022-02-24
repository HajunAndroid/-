#include<iostream>
#include<cstring>
#define MAX 21
using namespace std;

int map[MAX][MAX];
int c_map[MAX][MAX];
pair<int, int> smell[MAX][MAX];

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };

int n, m, k;
int left_shark = m;

int t = 0;

struct Shark {
	int x;
	int y;
	int idx;
	int live;
	int dir;
	int dir_arr[5][5];
};

Shark shark_arr[410];

void Input()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				Shark shark;
				shark.x = i; shark.y = j;
				shark.idx = map[i][j];
				shark.live = 1;
				shark_arr[map[i][j]] = shark;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> shark_arr[i].dir;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> shark_arr[i].dir_arr[j][k];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		smell[shark_arr[i].x][shark_arr[i].y] = { i,k };
	}
}

void Move()
{
	memset(c_map, 0, sizeof(c_map));
	for (int i = 1; i <= m; i++) {
		if (shark_arr[i].live == 0)continue;
		int x = shark_arr[i].x;
		int y = shark_arr[i].y;
		int dir = shark_arr[i].dir;
		bool flag = false;
		//int ans = 0;
		for (int j = 1; j <= 4; j++) {
			int n_dir = shark_arr[i].dir_arr[dir][j];
			int nx = x + dx[n_dir];
			int ny = y + dy[n_dir];
			//cout<< i<<"x"<<x<<"y"<<y<<"n_dir"<<n_dir<<"nx" << nx << "ny" << ny << endl;
			if (nx<1 || ny<1 || nx>n || ny>n)continue;
			if (smell[nx][ny].second != 0)continue;
			
			if (c_map[nx][ny] == 0) {
				c_map[nx][ny] = i;
				shark_arr[i].x = nx;
				shark_arr[i].y = ny;
				shark_arr[i].dir = n_dir;
			}
			else {
				if (c_map[nx][ny] > i) {
					int temp = c_map[nx][ny];
					shark_arr[temp].live = 0;
					left_shark--;
					c_map[nx][ny] = i;
					shark_arr[i].x = nx;
					shark_arr[i].y = ny;
					shark_arr[i].dir = n_dir;
				}
				else {
					shark_arr[i].live = 0;
					left_shark--;
				}
			}
			flag = true;
			break;
		}
		if (!flag) {
			for (int j = 1; j <= 4; j++) {
				int n_dir = shark_arr[i].dir_arr[dir][j];
				int nx = x + dx[n_dir];
				int ny = y + dy[n_dir];
				if (nx<1 || ny<1 || nx>n || ny>n)continue;
				if (smell[nx][ny].first == i) {
					c_map[nx][ny] = i;
					shark_arr[i].x = nx;
					shark_arr[i].y = ny;
					shark_arr[i].dir = n_dir;
					break;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(smell[i][j].second>0)
				smell[i][j].second--;
			if (smell[i][j].second == 0)
				smell[i][j].first = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (c_map[i][j] == 0)continue;
			int idx = c_map[i][j];
			smell[i][j].first = idx;
			smell[i][j].second = k;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = c_map[i][j];
		}
	}
}

bool Cnt()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != 0)cnt++;
		}
	}
	if (cnt == 1)return true;
	return false;
}

void Solution()
{
	while (!Cnt()) {
		if (t >= 1000) {
			cout << "-1";
			return;
		}
		Move();
		/*
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << smell[i][j].first << "," << smell[i][j].second << " ";
			}
			cout << endl;
		}*/
		t++;
	}
	cout << t;
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
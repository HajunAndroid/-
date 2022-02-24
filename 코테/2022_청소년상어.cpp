#include<iostream>
#include<algorithm>
using namespace std;

struct Fish {
	int x;
	int y;
	int dir;
	int live;
};

Fish fish_arr[17];
int map[4][4];

int dx[] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,0,-1,-1,-1,0,1,1,1 };

int ans = -1;

void Input()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			Fish fish;
			fish.x = i; fish.y = j;
			fish.dir = b; fish.live = 1;
			fish_arr[a] = fish;
			map[i][j] = a;
		}
	}
}

void FishMove(int shark_x,int shark_y)
{
	for (int i = 1; i <= 16; i++) {
		if (fish_arr[i].live == 0)continue;
		int x = fish_arr[i].x;
		int y = fish_arr[i].y;
		int dir = fish_arr[i].dir;
		while (true) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {
				dir++;
				if (dir == 9)dir = 1;
				if (dir == fish_arr[i].dir) {
					break;
				}
				continue;
			}
			if (shark_x == nx && shark_y == ny) {
				dir++;
				if (dir == 9)dir = 1;
				if (dir == fish_arr[i].dir) {
					break;
				}
				continue;
			}
			if (map[nx][ny] == 0) {
				map[nx][ny] = i;
				map[x][y] = 0;
				fish_arr[i].x = nx;
				fish_arr[i].y = ny;
				fish_arr[i].dir = dir;
				break;
			}
			else {
				fish_arr[i].x = nx;
				fish_arr[i].y = ny;
				fish_arr[i].dir = dir;
				fish_arr[map[nx][ny]].x = x;
				fish_arr[map[nx][ny]].y = y;
				map[x][y] = map[nx][ny];
				map[nx][ny] = i;
				break;
			}
		}
	}
}

void DFS(int shark_x, int shark_y, int shark_dir, int sum)
{
	ans = max(ans, sum);
	FishMove(shark_x, shark_y);
	int c_map[4][4];
	Fish c_fish_arr[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c_map[i][j] = map[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		c_fish_arr[i] = fish_arr[i];
	}

	for (int i = 1; i < 4; i++) {
		int nsx = shark_x + dx[shark_dir] * i;
		int nsy = shark_y + dy[shark_dir] * i;
		if (nsx < 0 || nsy < 0 || nsx >= 4 || nsy >= 4)break;
		if (map[nsx][nsy] == 0)continue;
		int idx = map[nsx][nsy];
		fish_arr[idx].live = 0;
		map[nsx][nsy] = 0;
		DFS(nsx, nsy, fish_arr[idx].dir, sum + idx);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				map[i][j] = c_map[i][j];
			}
		}
		for (int i = 1; i <= 16; i++) {
			fish_arr[i] = c_fish_arr[i];
		}
	}
}

void Solution()
{
	int idx = map[0][0];
	fish_arr[idx].live = 0;
	map[0][0] = 0;
	DFS(0, 0, fish_arr[idx].dir, idx);
	cout << ans;
}

void Solve()
{
	Input();
	Solution();
	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
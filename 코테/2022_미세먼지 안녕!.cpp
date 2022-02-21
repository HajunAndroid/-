#include<iostream>
#include<cstring>
#define MAX 51
using namespace std;

int map[MAX][MAX];
int c_map[MAX][MAX];
int r, c, t;
int cleaner = -1;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && cleaner == -1) {
				cleaner = i;
			}
		}
	}
}

void Spread()
{
	memset(c_map, 0, sizeof(c_map));
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == -1 || map[i][j] == 0)continue;
			int temp = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx<1 || ny<1 || nx>r || ny>c)continue;
				if (map[nx][ny] == -1)continue;
				temp++;
			}
			int temp2 = map[i][j] / 5;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx<1 || ny<1 || nx>r || ny>c)continue;
				if (map[nx][ny] == -1)continue;
				c_map[nx][ny] += temp2;
			}
			map[i][j] -= temp2*temp;
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == -1)continue;
			map[i][j] += c_map[i][j];
		}
	}
}

void Wind()
{
	for (int i = cleaner - 1; i > 1; i--) {
		map[i][1] = map[i - 1][1];
	}
	for (int i = 1; i < c; i++) {
		map[1][i] = map[1][i + 1];
	}
	for (int i = 1; i < cleaner; i++) {
		map[i][c] = map[i + 1][c];
	}
	for (int i = c; i >= 3; i--) {
		map[cleaner][i] = map[cleaner][i - 1];
	}
	map[cleaner][2] = 0;

	cleaner++;

	for (int i = cleaner + 1; i < r; i++) {
		map[i][1] = map[i + 1][1];
	}
	for (int i = 1; i < c; i++) {
		map[r][i] = map[r][i + 1];
	}
	for (int i = r; i > cleaner; i--) {
		map[i][c] = map[i - 1][c];
	}
	for (int i = c; i >= 3; i--) {
		map[cleaner][i] = map[cleaner][i - 1];
	}
	map[cleaner][2] = 0;

	cleaner--;
}

void Solution()
{
	while (t--) {
		Spread();
		Wind();
		/*
		cout << "@@@@\n";
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	int ans = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == -1)continue;
			ans += map[i][j];
		}
	}
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
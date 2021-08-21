#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int N, M, H;
int map[MAX][MAX][MAX];

queue<pair<pair<int, int>, int>>q;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int dh[] = { -1,1 };

void Input()
{
	cin >> M >> N >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> map[j][k][i];
				if (map[j][k][i] == 1) {
					q.push({ {j,k},i });
				}
			}
		}
	}
}

void bfs()
{
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int h = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M)continue;
			if (map[nx][ny][h] == -1 || map[nx][ny][h] != 0)continue;
			map[nx][ny][h] = map[x][y][h] + 1;
			q.push({ {nx,ny},h });
		}
		for (int i = 0; i < 2; i++) {
			int nh = h + dh[i];
			if (nh<1 || nh>H)continue;
			if (map[x][y][nh] == -1 || map[x][y][nh] != 0)continue;
			map[x][y][nh] = map[x][y][h] + 1;
			q.push({ {x,y},nh });
		}
	}
}

void checking()
{
	int temp = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (map[j][k][i] == -1)continue;
				if (map[j][k][i] == 0) {
					cout << "-1";
					return;
				}
				if (temp < map[j][k][i])
					temp = map[j][k][i];
			}
		}
	}
	cout << temp - 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	Input();
	bfs();
	checking();
	return 0;
}
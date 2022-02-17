#include<iostream>
#include<queue>
#define MAX 10
using namespace std;

int map[MAX][MAX];

int n = 8;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	map[4][2] = 1;
	map[2][3] = 1;
}

void Solution(int x, int y, int k)
{
	map[x][y] = 3;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)break;
			if (map[nx][ny] == 1)break;
			map[nx][ny] = 2;
		}
	}
}

void Solve()
{
	Input();
	Solution(4, 3, 3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
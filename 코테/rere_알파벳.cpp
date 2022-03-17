#include<iostream>
#include<vector>
#define MAX 21
using namespace std;

char map[MAX][MAX];
bool visited[MAX][MAX];
int r, c;
int ans = 1;
vector<char>v;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool promising(char c)
{
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == c)return false;
	}
	return true;
}

void DFS(int x, int y, int cnt)
{
	if (cnt > ans)ans = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c)continue;
		if (visited[nx][ny])continue;
		if (promising(map[nx][ny])) {
			visited[nx][ny] = 1;
			v.push_back(map[nx][ny]);
			DFS(nx, ny, cnt + 1);
			visited[nx][ny] = 0;
			v.pop_back();
		}
	}
}

int main()
{
	cin >> r >> c;
	string s;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
		}
	}
	v.push_back(map[0][0]);
	visited[0][0] = 1;
	DFS(0, 0, 1);
	cout << ans;
	return 0;
}
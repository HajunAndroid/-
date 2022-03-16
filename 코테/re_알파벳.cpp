#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#define MAX 21
using namespace std;

int r, c;
char map[MAX][MAX];
int ans;
vector<char>v;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int promising(char temp)
{
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		if (*iter == temp)
			return 0;
	}
	return 1;
}

void dfs(int y, int x)
{
	if (v.size() > ans)
		ans = v.size();
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || ny >= r || nx >= c)continue;
		if (!promising(map[ny][nx]))continue;
		v.push_back(map[ny][nx]);
		dfs(ny, nx);
		v.pop_back();
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < c; j++) {
			map[i][j] = temp[j];
		}
	}
	v.push_back(map[0][0]);
	dfs(0, 0);
	cout << ans;
	return 0;
}
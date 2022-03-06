#include<iostream>
#include<string>
#include<cstring>
#include<queue>

#define MAX 25
using namespace std;

int n, m;
bool finish_mark;
bool visit[MAX][MAX][4][16];
char map[MAX][MAX];
string answer;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void Initialize()
{
	finish_mark = false;
	memset(visit, false, sizeof(visit));
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '@')
				finish_mark = true;
		}
	}
}

void Solution()
{
	queue<pair<pair<int, int>, pair<int, int>>>q;
	q.push({ {0,0},{0,0} });
	visit[0][0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int memory = q.front().second.second;
		q.pop();
		if (map[x][y] == '@') {
			answer = "YES";
			return;
		}
		char c = map[x][y];
		int nDir, nMemory;
		nDir = dir;
		nMemory = memory;
		if (c == '<')nDir = 1;
		else if (c == '>')nDir = 0;
		else if (c == '^')nDir = 3;
		else if (c == 'v')nDir = 2;
		else if (c == '_')nDir = memory == 0 ? 0 : 1;
		else if (c == '|')nDir = memory == 0 ? 2 : 3;
		else if (c == '+')nMemory = memory + 1 == 16 ? 0 : memory + 1;
		else if (c == '-')nMemory = memory - 1 == -1 ? 15 : memory - 1;
		else if ('0' <= c && c <= '9')nMemory = c - '0';

		if (c == '?') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (nx < 0)nx = n - 1;
				else if (nx == n)nx = 0;
				if (nx < 0)ny = m - 1;
				else if (ny == m)ny = 0;

				if (visit[nx][ny][i][nMemory] == false) {
					visit[nx][ny][i][nMemory] = true;
					q.push({ {nx,ny},{i,nMemory} });
				}
			}
		}
		else {
			int nx = x + dx[nDir];
			int ny = y + dy[nDir];

			if (nx < 0)nx = n - 1;
			else if (nx == n)nx = 0;
			if (nx < 0)ny = m - 1;
			else if (ny == m)ny = 0;

			if (visit[nx][ny][nDir][nMemory] == false) {
				visit[nx][ny][nDir][nMemory] = true;
				q.push({ {nx,ny},{nDir,nMemory} });
			}
		}
	}
	answer = "No";
}

void Solve()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		Initialize();
		Input();
		Solution();

		cout << "#" << i << " " << answer << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	Solve();
	return 0;
}
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int r, c;
char map[20][20];
int x, y, dir,memo;
bool visit[20][20][4][16];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void Initialize()
{
	x = 0; y = 0; dir = 1; memo = 0;
	memset(visit, 0, sizeof(visit));
}

void Input()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
}

void Solution()
{
	queue<pair<pair<int, int>, pair<int, int>>>q;
	q.push({ {0,0},{1,0} });
	visit[0][0][1][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int meno = q.front().second.second;
		q.pop();
		char c = map[x][y];
		bool flag = false;
		if (c == '<')dir = 0;
		else if (c == '>')dir = 1;
		else if (c == '^')dir = 2;
		else if (c == 'v')dir = 3;
		else if (c == '_')dir = memo == 0 ? 1 : 0;
		else if (c == '|')dir = memo == 0 ? 3 : 2;
		else if (c == '?') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0)nx = r - 1;
				else if (nx >= r)nx = 0;
				if (ny < 0)ny = c - 1;
				else if (ny >= c)ny = 0;
				if (visit[nx][ny][dir][memo] == true)continue;
				if (map[nx][ny] == '@') {
					cout << "YES"; return;
				}
				visit[nx][ny][dir][memo] = true;
				q.push({ {nx,ny},{dir,memo} });
				flag = true;
			}
		}
		else if (c == '.') {
			//Nothing
		}
		else if (c == '@') {
			cout << "YES";
			return;
		}
		else if (c >= '0' && c <= '9') {
			memo = c - '0';
		}
		else if (c == '+') {
			memo++; if (memo == 16)memo = 0;
		}
		else if (c == '-') {
			memo--; if (memo == -1)memo = 15;
		}
		if (flag)continue;
		x = x + dx[dir];
		y = y + dy[dir];
		if (x < 0)x = r - 1;
		else if (x >= r)x = 0;
		if (y < 0)y = c - 1;
		else if (y >= c)y = 0;
		if (visit[x][y][dir][memo] == true)continue;
		if (map[x][y] == '@') {
			cout << "YES"; return;
		}
		visit[x][y][dir][memo] = true;
		q.push({ {x,y},{dir,memo} });
	}
	cout<<"NO";
}

void Solve()
{
	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		Initialize();
		Input();
		cout << "#" << i << " ";
		Solution();
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
#include<iostream>
#include<queue>
#include<cstring>
#define MAX 2010
using namespace std;

char map[MAX][MAX];
bool visit[MAX][MAX];

int n, m;
string ans;

int dx[] = { 0,1 };
int dy[] = { 1,0 };

void Initialize()
{
	memset(visit, 0, sizeof(visit));
	ans = "";
}

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
}

void Solution()
{
	ans += map[1][1];
	visit[1][1] = true;
	queue<pair<int, int>>q;
	q.push({ 1,1 });
	while (!q.empty()) {
		int Size = q.size();
		char MIN = 'z';
		vector<pair<int, int>>v;
		while (Size--) {
			int x = q.front().first;
			int y = q.front().second;
			if (x == n && y == m)return;
			q.pop();
			for (int i = 0; i < 2; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<1 || ny<1 || nx>n || ny>m)continue;
				if (visit[nx][ny])continue;
				visit[nx][ny] = true;
				if (map[nx][ny] <= MIN) {
					if (map[nx][ny] < MIN)v.clear();
					MIN = map[nx][ny];
					v.push_back({ nx,ny });
				}
			}
		}
		ans += MIN;
		for (int i = 0; i < v.size(); i++) {
			q.push(v[i]);
		}
	}
}

void Solve()
{
	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		Initialize();
		Input();
		Solution();
		cout << "#" << i << " " << ans << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
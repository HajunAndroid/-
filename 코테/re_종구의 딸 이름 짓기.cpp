#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#define MAX 2000
using namespace std;

int n, m;
char map[MAX][MAX];
bool visit[MAX][MAX];
string ans;

int dx[] = { 0,1 };
int dy[] = { 1,0 };

void Initialize()
{
	ans = "";
	memset(visit, false, sizeof(visit));
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void Solution()
{
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	visit[0][0] = true;
	ans = ans + map[0][0];
	bool flag = false;
	while (!q.empty()) {
		int q_size = q.size();
		char min_value = 'z';
		vector<pair<int, int>>v;
		for (int i = 0; i < q_size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == n - 1 && y == m - 1) {
				flag = true;
				break;
			}
			for (int j = 0; j < 2; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
				if (visit[nx][ny])continue;
				if (map[nx][ny] <= min_value) {
					if (map[nx][ny] < min_value)v.clear();
					v.push_back({ nx,ny });
					visit[nx][ny] = true;
					min_value = map[nx][ny];
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			q.push(v[i]);
		}
		if (!flag)
			ans = ans + min_value;
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
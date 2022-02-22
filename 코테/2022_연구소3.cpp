#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 51
using namespace std;

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX];
int Answer = 1e9;

vector<pair<int, int>>v;
int arr[MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
}

void bfs()
{
	memset(visited, -1, sizeof(visited));
	queue<pair<int, int>>q;
	for (int i = 0; i < m; i++) {
		q.push({ v[arr[i]].first,v[arr[i]].second });
		visited[v[arr[i]].first][v[arr[i]].second] = 0;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>n)continue;
			if (map[nx][ny] == 1)continue;
			if (visited[nx][ny] != -1)continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 2)continue;
			if (map[i][j] == 0 && visited[i][j] == -1)return;
			if (visited[i][j] > ans) {
				ans = visited[i][j];
			}
		}
	}
	Answer = min(Answer, ans);
}

void Pick(int idx, int cnt)
{
	if (cnt == m) {
		/*for (int i = 0; i < m; i++) {
			cout<<arr[i]+1<<":" << v[arr[i]].first << " " << v[arr[i]].second << endl;
		}
		cout << endl;*/
		bfs();
	}
	for (int i = idx; i < v.size(); i++) {
		arr[cnt] = i;
		Pick(i + 1, cnt + 1);
	}
}

void Solution()
{
	Pick(0, 0);
	if (Answer == 1e9)
		Answer = -1;
	cout << Answer;
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
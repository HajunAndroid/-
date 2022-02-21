#include<iostream>
#include<queue>
#include<cstring>
#define MAX 21
using namespace std;

int n;
int shark_x, shark_y;
int shark_size = 2;
int eaten_fish;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool flag = true;
int ans;

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark_x = i; 
				shark_y = j;
				map[i][j] = 0;
			}
		}
	}
}

void bfs(int x, int y)
{
	visited[x][y] = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	int depth = 0;
	while (!q.empty()) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		int t = q.size();
		depth++;
		while (t--) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<1 || ny<1 || nx>n || ny>n)continue;
				if (visited[nx][ny])continue;
				if (map[nx][ny] > shark_size)continue;
				if (map[nx][ny] != 0 && map[nx][ny] < shark_size) {
					pq.push({ nx,ny });
					q.push({ nx,ny });
					visited[nx][ny] = 1;
				}
				else {
					q.push({ nx,ny });
					visited[nx][ny] = 1;
				}
			}
		}
		if (pq.size() != 0) {
			flag = true;
			int tx = pq.top().first;
			int ty = pq.top().second;
			ans += depth;
			shark_x = tx;
			shark_y = ty;
			eaten_fish ++;
			map[tx][ty] = 0;
			if (shark_size == eaten_fish) {
				eaten_fish = 0;
				shark_size++;
			}
			break;
		}
	}
}

void Solution()
{
	while(flag){
		flag = false;
		memset(visited, 0, sizeof(visited));
		bfs(shark_x, shark_y);
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
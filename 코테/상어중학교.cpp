#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define MAX 21
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int n, m;

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}

bool cmp(pair<pair<int,int>,pair<int,int>>a, pair<pair<int, int>, pair<int, int>>b)
{
	if (a.first.first >= b.first.first) {
		if (a.first.first == b.first.first) {
			if (a.first.second >= b.first.second) {
				if (a.first.second == b.first.second) {
					if (a.second.first >= b.second.first) {
						if (a.second.first == b.second.first) {
							if (a.second.second < b.second.second) {
								return false;
							}
							return true;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

vector<pair<pair<int, int>, pair<int, int>>>v;

void BFS(int x, int y, int num)
{
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>>q;
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	int cnt = 0;
	int rainbow = 0;
	visited[x][y] = 1;
	q.push({ x,y });
	pq.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>n)continue;
			if (visited[nx][ny])continue;
			if (map[nx][ny] == -1 || map[nx][ny] == -2 || map[nx][ny] != num)continue;
			cnt++;
			cout << cnt << " ";
			if (map[nx][ny] == 0) { rainbow++; }
			else{ pq.push({ nx,ny }); }
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	if (cnt < 2)return;
	v.push_back({ {cnt,rainbow},{pq.top().first,pq.top().second} });
}

int POINT = 0;
int max_x, max_y;
bool FindBlock()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == -1 || map[i][j] == -2 || map[i][j] == 0)continue;
			BFS(i, j, map[i][j]);
		}
	}
	sort(v.begin(), v.end(), cmp);
	if (v.size() == 0) {
		return false;
	}
	POINT += (v[0].first.first * v[0].first.first);
	max_x = v[0].second.first;
	max_y = v[0].second.second;
	cout << "\n#####" << v[0].first.first << " " << v[0].first.second << " " << v[0].second.first << " " << v[0].second.second << endl;
	return true;
}

void DeleteBlock()
{
	int num = map[max_x][max_y];
	//cout << "\n@@@" << num << endl;
	int x = max_x; int y = max_y;
	//memset(visited, 0, sizeof(visited));
	queue<pair<int, int>>q;
	q.push({ x,y });
	map[x][y] = -2;
	//visited[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>n)continue;
			if (map[nx][ny] == num) {
				map[nx][ny] = -2;
				q.push({ nx,ny });
			}
		}
	}
}

void Gravity()
{

}

void Spinning()
{

}

void Solve()
{
	//while (FindBlock()) {
	//	DeleteBlock();
	//}
	FindBlock();
	DeleteBlock();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void Solve()
{
	Input();
	Solve();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
#include<iostream>
#include<cstring>
#include<queue>
#define MAX 21
using namespace std;

int n, m, tank;
int left_person;
int map[MAX][MAX];
bool visited[MAX][MAX];
int t_x, t_y;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct person
{
	int idx;
	int s_x; int s_y;
	int e_x; int e_y;
};
person p_arr[401];

void Input()
{
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	memset(p_arr, 0, sizeof(p_arr));
	cin >> n >> m >> tank;
	left_person = m;
	int temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			if (temp == 1)
				temp = -1;
			map[i][j] = temp;
		}
	}
	cin >> t_x >> t_y;
	int a, b, c, d;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c >> d;
		map[a][b] = i;
		p_arr[i].idx = i; p_arr[i].s_x = a; p_arr[i].s_y = b;
		p_arr[i].e_x = c; p_arr[i].e_y = d;
	}
}

void find_End(int x, int y, int distance)
{
	if (tank - distance < 0) {
		cout << "-1";
		exit(0);
	}
	tank -= distance;
	tank = tank + distance + distance;
	t_x = x;
	t_y = y;
	left_person--;
}

void BFS(int x, int y, int xx, int yy)
{
	memset(visited, 0, sizeof(visited));
	queue<pair<pair<int, int>, int>>q;
	visited[x][y] = 1;
	q.push({ {x,y},0 });
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int distance = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>n)continue;
			if (map[nx][ny] == -1)continue;
			if (visited[nx][ny])continue;
			if ((nx == xx) && (ny == yy)) {
				find_End(xx, yy, distance + 1);
				return;
			}
			visited[nx][ny] = 1;
			q.push({ {nx,ny},distance + 1 });
		}
	}
	cout << "-1" << endl;
	exit(0);
}

void func2(int idx, int x, int y, int distance)
{
	if (tank <= distance) {
		cout << "-1" << endl;
		exit(0);
	}
	tank -= distance;
	BFS(x, y, p_arr[idx].e_x, p_arr[idx].e_y);
}

void func1()
{
	while (left_person) {
		memset(visited, 0, sizeof(visited));
		bool flag1 = true;
		bool flag2 = true;
		queue<pair<int, int>>q;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		int x = t_x; int y = t_y;
		int distance = 0;
		if (map[x][y] >= 1) {
			func2(map[x][y], x, y, 0);
			map[x][y] = 0;
			flag1 = false;
		}
		else {
			q.push({ x,y });
			while (!q.empty()) {
				distance++;
				int temp_size = q.size();
				while (temp_size--) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					visited[x][y] = 1;
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx<1 || ny<1 || nx>n || ny>n)continue;
						if (visited[nx][ny])continue;
						if (map[nx][ny] == -1)continue;
						if (map[nx][ny] >= 1) {
							visited[nx][ny] = 1;
							flag1 = false;
							flag2 = false;
							pq.push({ nx,ny });
							q.push({ nx,ny });
						}
						else {
							visited[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
				if (!flag2) {
					break;
				}
			}
			if (flag1) {
				cout << "-1" << endl;
				exit(0);
			}
			x = pq.top().first;
			y = pq.top().second;
			func2(map[x][y], x, y, distance);
			map[x][y] = 0;
		}
	}
}

void Solution()
{
	func1();
	cout << tank << '\n';
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
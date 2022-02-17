#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 101
using namespace std;

int N, K;
int ans;
int map[MAX][MAX];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> map[N][i];
	}
}

void First()
{
	int min = 1e9;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		if (min > map[N][i]) {
			v.clear();
			v.push_back(i);
			min = map[N][i];
		}
		else if (min == map[N][i]) {
			v.push_back(i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int idx = v[i];
		map[N][idx]++;
	}
}

void Second()
{
	int h, w, pivot;
	h = w = pivot = 1;
	for (int idx = 0;; idx++) {
		if (pivot - 1 + w + h > N)break;
		for (int c = pivot; c < pivot + w; c++) {
			for (int r = N; r > N - h; r--) {
				int nr = N - w + (c - pivot);
				int nc = pivot + w + (N - r);
				map[nr][nc] = map[r][c];
				map[r][c] = 0;
			}
		}
		pivot += (idx / 2 + 1);
		if (idx % 2 == 0) { h++; }
		else { w++; }
	}
}

void Third()
{
	int c_map[MAX][MAX] = { 0, };
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			if (map[x][y] == 0)continue;
			c_map[x][y] += map[x][y];
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<1 || ny<1 || nx>N || ny>N)continue;
				if (map[nx][ny] == 0)continue;
				if (abs(map[nx][ny] - map[x][y]) / 5 > 0) {
					if (map[x][y] > map[nx][ny]) {
						c_map[x][y] -= (abs(map[nx][ny] - map[x][y]) / 5);
						c_map[nx][ny] += (abs(map[nx][ny] - map[x][y]) / 5);
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = c_map[i][j];
		}
	}
}

void Fourth()
{
	//cout << "ok1" << endl;
	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (map[N][i] == 0)continue;
		for (int j = N; j >= 1; j--) {
			if (map[j][i] == 0)break;
			q.push(map[j][i]);
		}
	}
	//cout << "ok2" << endl;
	for (int i = 1; i <= N; i++) {
		map[N][i] = q.front();
		//cout << q.front() << " ";
		q.pop();
	}
	//cout << "ok3" << endl;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
		}
	}
}

void Fifth()
{
	int c_map[MAX][MAX] = { 0, };
	int right = N;
	for (int i = 1; i <= N / 4; i++, right--) {
		c_map[N - 1][right] = map[N][i];
		c_map[N - 3][right] = map[N][N / 2 + i];
	}
	right = N;
	for (int i = 0; i < N / 4; i++, right--) {
		c_map[N - 2][right] = map[N][N / 2 - i];
		c_map[N][right] = map[N][N - i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = c_map[i][j];
		}
	}
}

bool IsDone()
{
	int Imin = 1e9;
	int Imax = 0;
	for (int i = 1; i <= N; i++) {
		Imin = min(Imin, map[N][i]);
		Imax = max(Imax, map[N][i]);
	}
	if (Imax - Imin <= K)return true;
	return false;
}

void Solution()
{
	while (!IsDone()) {
		ans++;
		//cout << "1" << endl;
		First();
		//cout << "2" << endl;
		Second();
		//cout << "3" << endl;
		Third();
		//cout << "4" << endl;
		Fourth();
		//cout << "5" << endl;
		Fifth();
		//cout << "6" << endl;
		Third();
		Fourth();
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
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 11
using namespace std;

int n, m, K;
int A_map[MAX][MAX];
int t_map[MAX][MAX];
vector<int> map[MAX][MAX];

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

void Input()
{
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A_map[i][j];
			t_map[i][j] = 5;
			map[i][j].clear();
		}
	}
	int x, y, z;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		map[x][y].push_back(z);
	}
}

void SpringAndSummer()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].size() == 0)continue;
			sort(map[i][j].begin(), map[i][j].end());
			vector<int> v;
			int dead = 0;
			for (int k = 0; k < map[i][j].size(); k++) {
				if (t_map[i][j] >= map[i][j][k]) {
					t_map[i][j] -= map[i][j][k];
					v.push_back(map[i][j][k] + 1);
				}
				else {
					dead += (map[i][j][k] / 2);
				}
			}
			map[i][j] = v;
			t_map[i][j] += dead;
		}
	}
}

void Full()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].size() == 0)continue;
			for (int k = 0; k < map[i][j].size(); k++) {
				if (map[i][j][k] % 5 == 0) {
					for (int p = 0; p < 8; p++) {
						int nx = i + dx[p];
						int ny = j + dy[p];
						if (nx<1 || ny<1 || nx>n || ny>n)continue;
						map[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void Winter()
{

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			t_map[i][j] += A_map[i][j];
		}
	}
}

void Solution()
{
	while (K--) {
		SpringAndSummer();
		Full();
		Winter();
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += map[i][j].size();
		}
	}
	cout << sum;
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
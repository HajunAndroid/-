#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 11
using namespace std;

int n, m, k;
vector<int> map[MAX][MAX];
int A[MAX][MAX];
int meal[MAX][MAX];

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

void Input()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j].clear();
		}
	}
	memset(A, 0, sizeof(A));
	memset(meal, 0, sizeof(meal));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
			meal[i][j] = 5;
		}
	}
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		map[x][y].push_back(z);
	}
}

void SpringAndSummer()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].empty())continue;
			sort(map[i][j].begin(), map[i][j].end());
			vector<int>temp; int dead_tree = 0;
			for (int K = 0; K < map[i][j].size(); K++) {
				if (meal[i][j] >= map[i][j][K]) {
					meal[i][j] -= map[i][j][K];
					temp.push_back(map[i][j][K] + 1);
				}
				else {
					dead_tree += (map[i][j][K] / 2);
				}
			}
			map[i][j].clear();
			map[i][j] = temp;
			meal[i][j] += dead_tree;
		}
	}
}

void PlusTree(int x, int y)
{
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny<1 || nx>n || ny>n)continue;
		map[nx][ny].push_back(1);
	}
}

void Fall()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].empty())continue;
			for (int K = 0; K < map[i][j].size(); K++) {
				if (map[i][j][K] % 5 == 0) {
					PlusTree(i, j);
				}
			}
		}
	}
}

void Winter()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			meal[i][j] += A[i][j];
		}
	}
}

void FoundLiveTree()
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].empty())continue;
			sum += map[i][j].size();
		}
	}
	cout << sum << '\n';
}

void Solution()
{
	while (k--) {
		SpringAndSummer();
		Fall();
		Winter();
	}
	FoundLiveTree();
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
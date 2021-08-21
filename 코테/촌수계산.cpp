#include<iostream>
#define MAX 101
using namespace std;

int num;
int a, b;
int CASE;

int map[MAX][MAX];
int visited[MAX];

void dfs(int start, int sum)
{
	if (start == b) {
		cout << sum;
		exit(0);
	}
	visited[start] = 1;
	for (int i = 1; i <= num; i++) {
		if (map[start][i] && visited[i] != 1) {
			dfs(i, sum + 1);
		}
	}
	visited[start] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> num; cin >> a; cin >> b;
	cin >> CASE;
	while (CASE--) {
		int x, y;
		cin >> x; cin >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	dfs(a, 0);
	cout << "-1";
	return 0;
}
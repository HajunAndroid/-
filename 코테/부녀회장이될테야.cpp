#include<iostream>
#define MAX 15
using namespace std;

int map[MAX][MAX];
int t;

void Solve()
{
	int k, n;
	cin >> k >> n;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = map[i - 1][j] + map[i][j - 1];
		}
	}
	cout << map[k][n] << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		for (int i = 1; i < MAX; i++) {
			map[0][i] = i;
		}
		Solve();
	}
	return 0;
}
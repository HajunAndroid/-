#include<iostream>
#define MAX 15
using namespace std;

int map[MAX][MAX];

int main()
{
	int t; cin >> t;
	while (t--) {
		int k, n;
		cin >> k >> n;
		for (int i = 0; i <= n; i++) {
			map[0][i] = i;
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
		}
		cout << map[k][n] << '\n';
	}
	return 0;
}
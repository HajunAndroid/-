#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define MAX 10010
using namespace std;

int west_culture[MAX];
int east_culture[MAX];
int n, m;
int ans;
int idx;

void Input()
{
	memset(west_culture, 0, sizeof(west_culture));
	memset(east_culture, 0, sizeof(east_culture));
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		string s; cin >> s;
		for (int j = 1; j <= n; j++) {
			if (s.at(j - 1) == 'W') {
				west_culture[j]++;
			}
			else {
				east_culture[j]++;
			}
		}
	}
	ans = 1e9;
	idx = 0;
}

void Solution()
{
	int left = 0;
	int right = 0;
	for (int i = 1; i <= n; i++) {
		right += west_culture[i];
	}
	ans = min(ans, left + right);
	for (int i = 1; i <= n + 1; i++) {
		left += east_culture[i];
		right -= west_culture[i];
		if (ans > left + right) {
			idx = i;
			ans = left + right;
		}
	}
}

void Solve()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		Input();
		Solution();
		cout << "#" << i << " " << idx << " " << idx + 1 << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	Solve();
	return 0;
}
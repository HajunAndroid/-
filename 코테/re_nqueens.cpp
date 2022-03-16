#include<iostream>
#include<cmath>
#define MAX 16
using namespace std;

int arr[MAX];
int n;
int ans;

bool promising(int row, int col)
{
	for (int i = 0; i < row; i++) {
		if (abs(i - row) == abs(arr[i] - col) || col == arr[i])
			return 0;
	}
	return 1;
}

void dfs(int depth)
{
	if (depth == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!promising(depth, i))
			continue;
		arr[depth] = i;
		dfs(depth + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dfs(0);
	cout << ans;
	return 0;
}
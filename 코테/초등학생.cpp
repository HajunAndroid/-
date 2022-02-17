#include<iostream>
#define MAX 110
using namespace std;

int numbers[MAX];
int n;
int ans;

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}
	ans = 0;
}

void DFS(int idx, int sum, int cnt)
{
	if (cnt == n - 2) {
		if (sum == numbers[n]) {
			ans++;
		}
		return;
	}
	if (sum + numbers[idx] >= 0 && sum + numbers[idx] <= 20)
		DFS(idx + 1, sum + numbers[idx], cnt + 1);
	if (sum - numbers[idx] >= 0 && sum - numbers[idx] <= 20)
		DFS(idx + 1, sum - numbers[idx], cnt + 1);
}

void Solution()
{
	DFS(2, numbers[1], 0);
}

void Solve()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		Input();
		Solution();
		cout << "#" << i << " " << ans % 1234567891 << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
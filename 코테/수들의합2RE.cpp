#include<iostream>
#define MAX 10001
using namespace std;

int n, m;
int arr[MAX];

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void Solve()
{
	int ans = 0;
	int low = 1;
	int high = 1;
	while (low <= high && high <= n) {
		int sum = 0;
		for (int i = low; i <= high; i++) {
			sum += arr[i];
		}
		if (sum < m) {
			high++;
		}
		else if (sum == m) {
			ans++;
			high++;
		}
		else if (sum > m) {
			low++;
			if (low > high) {
				high = low;
			}
		}
	}
	cout << ans;
}

void Solve()
{
	Input();
	Solve();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
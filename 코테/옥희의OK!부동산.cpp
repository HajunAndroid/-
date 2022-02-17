#include<iostream>
#define MAX 10001
using namespace std;

int n, m;
int arr[MAX];
int ans;

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ans = 0;
}

void Solution()
{
	int low = 1;
	int high = 1;
	int sum = arr[1];
	while (low <= high && high <= n) {
		if (sum < m) {
			high++;
			sum += arr[high];
		}
		else if (sum == m) {
			ans++;
			high++;
			sum += arr[high];
		}
		else {
			sum -= arr[low];
			low++;
			if (low > high) {
				high = low;
			}
		}
	}
}

void Solve()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		Input();
		Solution();
		cout << "#" << i << " " << ans << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
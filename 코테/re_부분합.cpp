#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;

int n, s;
int arr[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = arr[0];
	int ans = 1e9;
	int low = 0;
	int high = 0;
	while (low <= high && high < n) {
		if (sum < s)
			sum += arr[++high];
		else if (sum == s) {
			ans = min(ans, high - low + 1);
			sum += arr[++high];
		}
		else {
			ans = min(ans, high - low + 1);
			sum -= arr[low++];
			if (low > high)
				break;
		}
	}
	if (ans == 1e9)ans = 0;
	cout << ans;
	return 0;
}
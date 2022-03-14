#include<iostream>
#define MAX 10010
using namespace std;

int arr[MAX];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
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
		else {
			low++;
			if (low > high)
				high = low;
		}
	}
	cout << ans;
	return 0;
}
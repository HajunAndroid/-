#include<iostream>
#define MAX 10000
using namespace std;

int arr[MAX];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int low = 0;
	int high = 0;
	int sum = arr[0];
	int ans = 0;
	while (low <= high && high < n) {
		if (sum < m) {
			sum += arr[++high];
		}
		else if (sum == m) {
			ans++;
			sum += arr[++high];
		}
		else {
			sum -= arr[low++];
			if (low > high) {
				high = low;
				sum = arr[low];
			}
		}
	}
	cout << ans;
	return 0;
}
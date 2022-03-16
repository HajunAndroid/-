#include<iostream>
#include<algorithm>
#define MAX 200010
using namespace std;

int arr[MAX];
int n, c;

bool Promising(int mid)
{
	int cnt = 1;
	int prev = arr[1];
	for (int i = 2; i <= n; i++) {
		if (arr[i] - prev >= mid) {
			prev = arr[i];
			cnt++;
		}
	}
	if (cnt >= c)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	int low = 1;
	int high = arr[n] - arr[1];
	while (low <= high) {
		int mid = (low + high) / 2;
		if (Promising(mid)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << high;
	return 0;
}
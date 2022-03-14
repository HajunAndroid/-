#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[100010];

void binary(int key)
{
	int start = 0;
	int end = n - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == key) {
			cout << "1" << '\n';
			return;
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << "0" << '\n';
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	int temp;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		binary(temp);
	}
	return 0;
}
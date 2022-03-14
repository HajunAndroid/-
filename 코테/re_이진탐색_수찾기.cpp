#include<iostream>
#include<algorithm>
#define MAX 100010
using namespace std;

int n, m;
int arr[MAX];

void binary(int key)
{
	int low = 1;
	int high = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			cout << "1" << '\n';
			return;
		}
		else if(arr[mid] > key){
			high = mid - 1;
		}
		else {
			low = mid + 1;
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
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	cin >> m;
	int temp;
	for (int i = 1; i <= m; i++) {
		cin >> temp;
		binary(temp);
	}
	return 0;
}
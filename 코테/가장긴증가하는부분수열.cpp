#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;

int arr[MAX];
int arr2[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr2[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				arr2[i] = max(arr2[i], arr2[j] + 1);
			}
		}
	}

	int temp = 0;
	for (int i = 1; i <= n; i++) {
		if (temp < arr2[i])
			temp = arr2[i];
	}

	cout << temp;

	return 0;
}
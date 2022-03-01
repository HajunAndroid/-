#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;

int arr[MAX];
int n;
int arr2[5];

int a = -1e9;//max
int b = 1e9;//min

void DFS(int cnt, int sum)
{
	if (cnt == n) {
		a = max(a, sum);
		b = min(b, sum);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (arr2[i] == 0)continue;
		if (i == 1) {
			arr2[i]--;
			DFS(cnt + 1, sum + arr[cnt + 1]);
			arr2[i]++;
		}
		else if (i == 2) {
			arr2[i]--;
			DFS(cnt + 1, sum - arr[cnt + 1]);
			arr2[i]++;
		}
		else if (i == 3) {
			arr2[i]--;
			DFS(cnt + 1, sum * arr[cnt + 1]);
			arr2[i]++;
		}
		else if (i == 4) {
			arr2[i]--;
			DFS(cnt + 1, sum / arr[cnt + 1]);
			arr2[i]++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= 4; i++) {
		cin >> arr2[i];
	}
	DFS(1, arr[1]);
	cout << a << endl;
	cout << b;
	return 0;
}
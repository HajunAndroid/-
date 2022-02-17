#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;

int k, n;
int arr[MAX];

int temp;

void Input()
{
	cin >> k >> n;
	for (int i = 1; i <= k; i++) {
		cin >> arr[i];
		temp = max(temp, arr[i]);
	}
}

bool Promising(int len)
{
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += (arr[i] / len);
	}
	if (sum >= n)return true;
	return false;
}

void Solution()
{
	long long low = 1;
	long long high = temp;
	long long mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (Promising(mid)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << high;
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
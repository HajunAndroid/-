#include<iostream>
#define MAX 100001
using namespace std;

int n;
int arr[MAX];

int Max(int a, int b)
{
	return a > b ? a : b;
}

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void Solution()
{
	int ans = 1;
	int len = 1;
	int len2 = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] <= arr[i + 1])len++;
		else len = 1;
		if (arr[i] >= arr[i + 1])len2++;
		else len2 = 1;
		int result = Max(len, len2);
		ans = Max(ans, result);
	}
	cout << ans;
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	Solve();
	return 0;
}
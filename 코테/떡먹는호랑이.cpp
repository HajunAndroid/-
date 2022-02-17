#include<iostream>
#define MAX 31
using namespace std;

int d, k;
int a[MAX];
int b[MAX];

void Input()
{
	cin >> d >> k;
}

void Solution()
{
	a[1] = 1;
	a[2] = 0;
	b[1] = 0;
	b[2] = 1;
	for (int i = 3; i <= d; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	for (int i = 1; i <= k; i++) {
		int spare = k - (a[d] * i);
		if (spare % b[d] == 0) {
			cout << i << '\n' << spare / b[d];
			return;
		}
	}
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
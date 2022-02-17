#include<iostream>
using namespace std;

int a, b, c, n;

void Input()
{
	cin >> a >> b >> c >> n;
}

void Solution()
{
	for (int i = 0; i <= n; i++) {
		int sa = a * i;
		for (int j = 0; j <= n; j++) {
			int sb = b * j;
			for (int k = 0; k <= n; k++) {
				int sc = c * k;
				if (sa + sb + sc == n) {
					cout << 1 << endl;
					return;
				}
			}
		}
	}
	cout << 0 << endl;
	return;
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
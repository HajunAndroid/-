#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

long long n, answer;

void Input()
{
	cin >> n;
}

void Solution()
{
	long long candidate = sqrt(n * 2);
	if (candidate * (candidate + 1) == n * 2)
		answer = candidate;
	else answer = -1;
}

void Solve()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		Input();
		Solution();
		cout << "#" << i << " " << answer << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
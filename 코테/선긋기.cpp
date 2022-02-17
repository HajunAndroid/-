#include<iostream>
#include<algorithm>
#define MAX 1000010
#define INF 1000000010
using namespace std;

struct LINE {
	int Start;
	int End;
};
int n;
LINE Line[MAX];

int Max(int a, int b)
{
	return a > b ? a : b;
}

bool Cmp(LINE A, LINE B)
{
	if (A.Start < B.Start)return true;
	return false;
}

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> Line[i].Start >> Line[i].End;
	}
}

void Solution()
{
	sort(Line + 1, Line + n + 1, Cmp);
	int ans = 0;
	int left = -INF;
	int right = -INF;
	for (int i = 1; i <= n; i++) {
		if (Line[i].Start <= right)
			right = Max(right, Line[i].End);
		else {
			ans += (right - left);
			left = Line[i].Start;
			right = Line[i].End;
		}
	}
	ans += (right - left);
	cout << ans;
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
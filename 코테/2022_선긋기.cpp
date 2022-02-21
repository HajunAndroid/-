#include<iostream>
#include<algorithm>
#define MAX 1000010
#define INF 1e9
using namespace std;

struct LINE
{
	int Start;
	int End;
};
int N;
LINE Line[MAX];

int Max(int a, int b) { return a > b ? a : b; }

bool Compare(LINE A, LINE B)
{
	if (A.Start < B.Start)return true;
	return false;
}

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Line[i].Start >> Line[i].End;
	}
}

void Solution()
{
	sort(Line + 1, Line + N + 1, Compare);
	int answer = 0;
	int leff = -INF;
	int right = -INF;
	for (int i = 1; i <= N; i++) {
		if (Line[i].Start <= right) {
			right = Max(right, Line[i].End);
		}
		else {
			answer += right - leff;
			leff = Line[i].Start;
			right = Line[i].End;
		}
	}
	answer += right - leff;
	cout << answer << endl;
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
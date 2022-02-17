#include<iostream>
#include<queue>
#define MAX 129
using namespace std;

int n, blue, white;
int map[MAX][MAX];

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void DFS(int x, int y, int Size)
{
	bool zero, one;
	zero = one = true;
	for (int i = x; i < x + Size; i++) {
		for (int j = y; j < y + Size; j++) {
			if (map[i][j] == 1)zero = false;
			if (map[i][j] == 0)one = false;
		}
	}
	if (zero == true) { white++; return; }
	if (one == true) { blue++; return; }
	DFS(x, y, Size / 2);
	DFS(x, y + Size / 2, Size / 2);
	DFS(x + Size / 2, y, Size / 2);
	DFS(x + Size / 2, y + Size / 2, Size / 2);
}

void Solution()
{
	DFS(0, 0, n);
	cout << white << '\n' << blue;
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
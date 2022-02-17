#include<iostream>
#define MAX 6
using namespace std;

int arr[MAX];
bool visited[MAX];

void Input()
{
	for (int i = 1; i <= 5; i++) {
		arr[i] = i;
	}
}

void DFS(int idx, int cnt)
{
	if (cnt == 3) {
		for (int i = 1; i <= 5; i++) {
			if (visited[i]) {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
		return;
	}
	for (int i = idx; i <= 5; i++) {
		visited[i] = 1;
		DFS(i + 1, cnt + 1);
		visited[i] = 0;
	}
}

void Solution()
{
	DFS(1, 0);
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
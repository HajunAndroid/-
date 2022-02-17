#include<iostream>
#include<cstring>
#define MAX 14
using namespace std;

int k;
int arr[MAX];
bool visited[MAX];

void Input()
{
	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= k; i++) {
		cin >> arr[i];
	}
}

void DFS(int idx, int cnt)
{
	if (cnt == 6) {
		for (int i = 1; i <= k; i++) {
			if (visited[i])
				cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i <= k; i++) {
		visited[i] = 1;
		DFS(i + 1, cnt + 1);
		visited[i] = 0;
	}
}

void Solve()
{
	DFS(1, 0);
}

void Solve()
{
	while (1) {
		cin >> k;
		if (k == 0)return;
		Input();
		Solve();
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
#include<iostream>
#include<cstring>
#include<queue>
#define MAX 100001
using namespace std;

int t;
int n;
int cnt;
int arr[MAX];
bool done[MAX];
bool visited[MAX];

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	memset(done, 0, sizeof(done));
	memset(visited, 0, sizeof(visited));
	cnt = 0;
}

void DFS(int idx)
{
	if (done[idx])return;
	if (!done[idx] && visited[idx]) {
		for (int i = arr[idx]; i != idx; i = arr[i]) {
			cnt++;
		}
		cnt++;
		return;
	}
	visited[idx] = 1;
	DFS(arr[idx]);
	done[idx] = 1;
}

void Solve()
{
	for (int i = 1; i <= n; i++) {
		if (done[i])continue;
		DFS(i);
	}
	cout << n - cnt << '\n';
}

void Solve()
{
	cin >> t;
	while (t--) {
		Input();
		Solve();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
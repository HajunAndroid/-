#include<iostream>
#define MAX 21
using namespace std;
int n, s;
int arr[MAX];
int ans;
void DFS(int idx, int sum, int cnt, int pick)
{
	if (cnt == n) {
		if (sum == s && pick != 0)ans++;
		return;
	}
	DFS(idx + 1, sum + arr[idx], cnt + 1,pick+1);
	DFS(idx + 1, sum, cnt + 1,pick);
}
int main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	DFS(1, 0, 0, 0);
	cout << ans;
	return 0;
}
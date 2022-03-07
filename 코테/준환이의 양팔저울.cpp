#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 9
using namespace std;

int n, sum, ans;
int arr[MAX];
bool visit[MAX];

int Exp[] = { 1,2,4,8,16,32,64,128,256,512 };
int factorial[] = { 0,1,2,6,24,120,720,5040,40320,362880 };

void Initialize()
{
	ans = 0;
	sum = 0;
	memset(visit, false, sizeof(visit));
}

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
}

void DFS(int cnt, int left, int right)
{
	if (cnt == n) {
		ans++;
		return;
	}
	if (left >= sum - left) {
		ans = ans + Exp[n - cnt] * factorial[n - cnt];
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == true)continue;
		visit[i] = true;
		DFS(cnt + 1, left + arr[i], right);
		if (right + arr[i] <= left)
			DFS(cnt + 1, left, right + arr[i]);
		visit[i] = false;
	}
}

void Solution()
{
	DFS(0, 0, 0);
}

void Solve()
{
	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		Initialize();
		Input();
		Solution();

		cout << "#" << tc << " " << ans << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
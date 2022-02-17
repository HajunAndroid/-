#include<iostream>
#define MAX 100001
using namespace std;

int arr[MAX];
int n;
int ans;

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ans = 1;
}

int Get_State(int idx)
{
	if (arr[idx] < arr[idx + 1])return 1;
	else if (arr[idx] == arr[idx + 1])return 0;
	else return -1;
}

void Solution()
{
	int state = Get_State(1);
	for (int i = 2; i < n; i++) {
		if (state == 0)state = Get_State(i);
		if (arr[i] < arr[i + 1]) {
			if (state != 1) {
				ans++;
				i++;
				state = Get_State(i);
			}
		}
		else if (arr[i] > arr[i + 1]) {
			if (state != -1) {
				ans++;
				i++;
				state = Get_State(i);
			}
		}
	}
}

void Solve()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		Input();
		Solution();
		cout << "#" << i << " " << ans << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
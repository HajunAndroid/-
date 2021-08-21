#include<iostream>
#include<cstring>
#define MAX 14
using namespace std;

int arr[MAX];
int k;
bool choose[MAX];

void Input()
{
	for (int i = 1; i <= k; i++) {
		cin >> arr[i];
	}
}

void DFS(int idx, int cnt)
{
	if (cnt == 6) {
		for (int i = 1; i <= k; i++) {
			if (choose[i])
				cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = idx; i <= k; i++) {
		choose[i] = 1;
		DFS(i + 1, cnt + 1);
		choose[i] = 0;
	}
}

void Solution()
{
	DFS(1, 0);
}

void Solve()
{
	while (true) {
		cin >> k;
		if (k == 0)break;
		memset(choose, 0, sizeof(choose));
		Input();
		Solution();
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
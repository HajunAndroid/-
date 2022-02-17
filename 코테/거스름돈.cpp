#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;

int DP[MAX];

int main()
{
	int n; cin >> n;
	int ans = 0;
	
	DP[1] = -1; DP[2] = 1; DP[3] = -1;
	DP[4] = 2; DP[5] = 1;
	for (int i = 6; i <= n; i++) {
		if (DP[i - 2] == -1 && DP[i - 5] == -1)DP[i] = -1;
		else if (DP[i - 2] == -1)DP[i] = DP[i - 5] + 1;
		else if (DP[i - 5] == -1)DP[i] = DP[i - 2] + 1;
		else DP[i] = min(DP[i - 2] + 1, DP[i - 5] + 1);
	}
	cout << DP[n];
	return 0;
}
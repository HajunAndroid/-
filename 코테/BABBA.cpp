#include<iostream>
using namespace std;

int FA[46];
int FB[46];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	FA[0] = 1;
	FB[0] = 0;
	FA[1] = 0;
	FB[1] = 1;
	for (int i = 2; i <= n; i++) {
		FA[i] = FB[i - 1];
		FB[i] = FA[i - 1] + FB[i - 1];
	}
	cout << FA[n] << " " << FB[n];
	return 0;
}
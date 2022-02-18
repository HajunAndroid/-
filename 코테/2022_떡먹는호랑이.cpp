#include<iostream>
#define MAX 31
using namespace std;

int a[MAX], b[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int D, K; cin >> D >> K;
	a[1] = 1; a[2] = 0;
	for (int i = 3; i <= D; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	b[1] = 0; b[2] = 1;
	for (int i = 3; i <= D; i++) {
		b[i] = b[i - 1] + b[i - 2];
	}
	int x = 0;
	while (true) {
		x++;
		if ((K - a[D] * x) % b[D] != 0)continue;
		int y = (K - a[D] * x) / b[D];
		cout << x << endl;
		cout << y;
		break;
	}
	return 0;
}
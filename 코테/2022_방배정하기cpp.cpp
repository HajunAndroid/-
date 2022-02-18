#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int A, B, C, N;
	cin >> A >> B >> C >> N;
	bool flag = false;
	for (int i = 0; i * A <= N; i++) {
		for (int j = 0; j * B <= N; j++) {
			for (int k = 0; k * C <= N; k++) {
				if (i * A + j * B + k * C == N) {
					flag = true;
					cout << "1";
					exit(0);
				}
			}
		}
	}
	cout << "0";
	return 0;
}
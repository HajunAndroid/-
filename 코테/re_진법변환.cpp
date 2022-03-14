#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string s = "";
	while (n != 0) {
		int temp = n % m;
		if (temp < 10) {
			s += (temp + '0');
		}
		else {
			s += (temp - 10 + 'A');
		}
		n = n / m;
	}
	string ss = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		ss += s[i];
	}
	cout << ss;
	return 0;
}
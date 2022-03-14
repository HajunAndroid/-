#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	string s="";
	while (a != 0) {
		int temp = a % b;
		if (temp < 10) {
			s += (temp + '0');
		}
		else {
			s += (temp - 10 + 'A');
		}
		a = a / b;
	}
	string ans="";
	for (int i = s.length() - 1; i >= 0; i--) {
		ans += s[i];
	}
	cout << ans;
	return 0;
}
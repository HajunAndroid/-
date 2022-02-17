#include<iostream>
#include<string>
using namespace std;

string str, str2;

void Input()
{
	getline(cin, str);
	getline(cin, str2);
}

void Solution()
{
	if (str.length() < str2.length()) {
		cout << 0 << endl;
		return;
	}
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		bool flag = true;
		for (int j = 0; j < str2.length(); j++) {
			if (str[i + j] != str[j]) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cnt++;
			i = i + str2.length() - 1;
		}
	}
	cout << cnt << '\n';
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
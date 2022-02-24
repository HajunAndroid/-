#include<iostream>
#include<string>
#include<vector>
using namespace std;

int T;
vector<string> v;

void Input()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s; cin >> s;
		v.push_back(s);
	}
}

int Is(int left, int right, int Delete, string str)
{
	while (left < right) {
		if (str[left] != str[right]) {
			if (Delete == 0) {
				if (Is(left + 1, right, 1, str) == 0 ||
					Is(left, right - 1, 1, str) == 0) {
					return 1;
				}
				else {
					return 2;
				}
			}
			else {
				return 2;
			}
		}
		else {
			left++;
			right--;
		}
	}
	return 0;
}

void Solution()
{
	for (int t = 0; t < T; t++) {
		string Str = v[t];
		int result = Is(0, Str.length() - 1, 0, Str);
		cout << result << endl;
	}
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	Solve();
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s = "hello";
	s.erase(s.begin() + 1);
	s.erase(1);
	s.erase(1, 1);
	s.erase(s.begin(), s.begin() + 1);
	s.replace(1, 1, "z");
	s.replace(s.begin(), s.begin() + 2, "year");
	s.substr(5);
	s.substr(5, 1);
	if (s.find("k") == string::npos) {
		reverse(s.begin(), s.end());
	}
	string num = "123";
	int k = stoi(num);
	string str1 = to_string(100);
	return 0;
}
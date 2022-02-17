#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s1 = "hello";
	string s2 = "my name is kim";

	string a = s1.substr(1, 2);
	//reverse(s1.begin(), s1.end());
	int idx = s1.find("h");
	s1.erase(1, 2);
	cout << s1;

	s1.replace(1,2,"z");
	s2.replace(s2.begin(), s2.begin() + 2, "your");
	//s2.replace(s2.find("my"), 2, "your");
	//cout << s1;
	/*
	if (s1.find("y") == string::npos) {
		cout << true;
	}
	else {
		cout << false;
	}*/
	return 0;
}
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int solution(string s)
{
	int answer = s.length();
	for (int len = 1; len <= s.length() / 2; len++) {
		string result = "";
		string temp = s.substr(0, len);
		int cnt = 1;
		int i;
		for (i = len; i <= s.length(); i += len) {
			if (temp == s.substr(i, len))cnt++;
			else {
				if (cnt == 1)result += temp;
				else {
					result += to_string(cnt);
					result += temp;
				}
				temp = s.substr(i, len);
				cnt = 1;
			}
		}
		if (i > s.length()) {
			if (cnt == 1)result += temp;
			else {
				result += to_string(cnt);
				result += temp;
			}
		}
		answer = min(answer, result.length());
	}
	return answer;
}
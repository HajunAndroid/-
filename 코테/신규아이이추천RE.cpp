#include<string>
#include<vector>
using namespace std;

void OneTwo(string& str)
{
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		if ('A' <= c && c <= 'Z')result += tolower(c);
		else if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '.' || c == '-' || c == '_')
			result += c;
	}
	str = result;
}

void Three(string& str)
{
	if (str.length() < 2)return;
	string result = "";
	int idx = 0;
	while (idx < str.length()) {
		if (idx + 1 < str.length() && (str[idx] == '.' && str[idx + 1] == '.')) {
			while (idx < str.length() && str[idx] == '.')idx++;
			result += '.';
		}
		else result += str[idx++];
	}
	str = result;
}

void Four(string& str)
{
	if (str.length() == 0)return;
	if (str[0] == '.')
		str = str.substr(1);
	if (str.length() >= 1 && str[str.length() - 1] == '.')
		str = str.substr(0, str.length() - 1);
}

void Five(string& str)
{
	if (str.length() == 0)str = "a";
}

void Six(string& str)
{
	if (str.length() < 16)return;
	str = str.substr(0, 15);
	Four(str);
}

void Seven(string& str)
{
	if (str.length() >= 3)return;
	char c = str[str.length() - 1];
	while (str.length() < 3)str += c;
}

string solution(string new_id)
{
	string answer = new_id;
	OneTwo(answer);
	Three(answer);
	Four(answer);
	Five(answer);
	Six(answer);
	Seven(answer);
	return answer;
}
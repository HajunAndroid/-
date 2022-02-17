#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

string solution(string number, int k)
{
	string answer = "";
	stack<char>st;
	int cnt = 0;
	int ans_size = number.length() - k;
	for (int i = 0; i < number.length(); i++) {
		char a = number[i];
		while (!st.empty() && cnt < k) {
			char b = st.top();
			if (b < a) {
				st.pop();
				cnt++;
			}
			else
				break;
		}
		st.push(a);
	}
	while (ans_size != st.size()) {
		st.pop();
	}
	while (!st.empty()) {
		answer += st.top();
		st.pop();
	}
	reverse(answer.begin(), answer.end());
	return answer;
}
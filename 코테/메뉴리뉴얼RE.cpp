#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string, int> m;
int temp_max = 0;

void DFS(int idx, int cnt, int len, string str, string temp)
{
	if (cnt == len) {
		sort(temp.begin(), temp.end());
		m[temp] += 1;
		if (m[temp] > temp_max) {
			temp_max = m[temp];
		}
		return;
	}
	for (int i = idx; i < str.size(); i++) {
		DFS(i + 1, cnt + 1, len, str, temp + str[i]);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string>answer;
	for (int i = 0; i < course.size(); i++) {
		int len = course[i];
		m.clear();
		temp_max = 0;
		for (int j = 0; j < orders.size(); j++) {
			if (orders[j].size() < len)continue;
			DFS(0, 0, len, orders[j], "");
		}
		for (auto iter : m) {
			if (iter.second < 2)continue;
			if (iter.second == temp_max) {
				answer.push_back(iter.first);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
#include<string>
#include<vector>
#include<algorithm>
#define MAX 50
using namespace std;

int visited[MAX];
int ans = 1e9;
bool ans_flag = false;

void DFS(string str, int cnt, string target, vector<string> words) {
	if (cnt > ans)return;
	if (str == target) {
		ans_flag = true;
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		if (visited[i] == 1)continue;
		int ans = 0;
		for (int j = 0; j < words[i].size(); j++) {
			if (str[j] != words[i][j]) {
				ans++;
			}
		}
		if (ans == 1) {
			visited[i] = 1;
			DFS(words[i], cnt + 1, target, words);
			visited[i] = 0;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	bool flag = false;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == target) {
			flag = true;
			break;
		}
	}
	if (!flag)return answer;
	DFS(begin, 0, target, words);
	if (ans_flag) {
		return ans;
	}
	else return answer;
}
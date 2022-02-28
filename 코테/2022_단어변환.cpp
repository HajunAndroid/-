#include <string>
#include <vector>
#include <algorithm>
#define MAX 50
using namespace std;

int answer = 1e9;
int visited[MAX];

bool cmp(string a, string b)
{
    int temp = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a.at(i) != b.at(i)) {
            temp++;
        }
    }
    if (temp == 1)return true;
    return false;
}

void dfs(string begin, string target, vector<string> words, int cnt)
{
    if (begin == target) {
        answer = min(answer, cnt);
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (visited[i] == 1)continue;
        if (cmp(begin, words[i])) {
            visited[i] = 1;
            if (answer > cnt + 1)
                dfs(words[i], target, words, cnt + 1);
            visited[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if (answer == 1e9)
        answer = 0;
    return answer;
}
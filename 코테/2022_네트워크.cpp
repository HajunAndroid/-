#include <string>
#include <vector>

using namespace std;

int visited[201];

void dfs(int n, int idx, vector<vector<int>> computers)
{
    visited[idx] = 1;
    for (int i = 0; i < n; i++) {
        if (computers[idx][i] == 0 || visited[i] == 1)continue;
        dfs(n, i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(n, i, computers);
            answer++;
        }
    }
    return answer;
}
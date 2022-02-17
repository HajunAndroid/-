#include<string>
#include<vector>
using namespace std;

bool visit[210];

void DFS(int n, int cur, vector<vector<int>>v) {
	for (int i = 0; i < n; i++) {
		if (v[cur][i] == 1 && visit[i] == false) {
			visit[i] = true;
			DFS(n, i, v);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		visit[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			DFS(n, i, computers);
			answer++;
		}
	}
	return answer;
}
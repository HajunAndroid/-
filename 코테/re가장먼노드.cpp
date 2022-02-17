#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 20001
#define INF 1e9
using namespace std;

vector<vector<int>>v;
int dist[MAX];

void Func(int idx)
{
	priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>>pq;
	pq.push({ 0,idx });
	dist[idx] = 0;
	while (!pq.empty()) {
		idx = pq.top().second;
		int len = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[idx].size(); i++) {
			if (dist[v[idx][i]] > len + 1) {
				dist[v[idx][i]] = len + 1;
				pq.push({ dist[v[idx][i]],v[idx][i] });
			}
		}
	}
}

int solution(int n, vector<vector<int>> edge)
{
	int answer = 0;
	v.resize(n + 1);
	for (int i = 0; i < edge.size(); i++) {
		int a, b;
		a = edge[i][0];
		b = edge[i][1];
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	Func(1);
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF)continue;
		temp = max(temp, dist[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == temp)
			answer++;
	}
	return answer;
}
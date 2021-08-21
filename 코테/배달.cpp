#include<iostream>
#include<vector>
#include<queue>
#define MAX 51
using namespace std;

int arr[MAX];
vector<vector<pair<int, int>>>v;

void bfs()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int now_node = pq.top().second;
		int now_cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[now_node].size(); i++) {
			int next_node = v[now_node][i].second;
			int next_cost = v[now_node][i].first;
			if (arr[next_node] > now_cost + next_cost) {
				arr[next_node] = now_cost + next_cost;
				pq.push({ arr[next_node],next_node });
			}
		}
	}
}

int solution(int N, vector<vector<int>> road, int K) {
	int answer = 0;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		arr[i] = 1e9;
	}
	arr[1] = 0;
	for (int i = 0; i < road.size(); i++) {
		int node1 = road[i][0];
		int node2 = road[i][1];
		int cost = road[i][2];
		v[node1].push_back({ cost,node2 });
		v[node2].push_back({ cost,node1 });
	}
	bfs();
	for (int i = 1; i <= N; i++) {
		if (arr[i] <= K) {
			answer++;
		}
	}
	return answer;
}
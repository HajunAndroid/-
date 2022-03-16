#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 100001
using namespace std;

int n, m, max_cost, start, End;
bool visited[MAX];
vector<vector<pair<int, int>>>v;

int Bigger(int a, int b)
{
	if (a > b)return a;
	return b;
}

void Input()
{
	v.resize(MAX);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int pos1, pos2, cost;
		cin >> pos1 >> pos2 >> cost;
		v[pos1].push_back({ pos2,cost });
		v[pos2].push_back({ pos1,cost });
		max_cost = Bigger(max_cost, cost);
	}
	cin >> start >> End;
}

bool BFS(int cur_cost)
{
	queue<int>q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int cur_factory = q.front();
		q.pop();
		if (cur_factory == End)return true;
		for (int i = 0; i < v[cur_factory].size(); i++) {
			int next_factory = v[cur_factory][i].first;
			int next_factory_cost = v[cur_factory][i].second;
			if (!visited[next_factory] && cur_cost <= next_factory_cost) {
				visited[next_factory] = true;
				q.push(next_factory);
			}
		}
	}
	return false;
}

void Solution()
{
	int low = 0;
	int high = max_cost;
	while (low <= high) {
		memset(visited, 0, sizeof(visited));
		int mid = (low + high) / 2;
		if (BFS(mid))low = mid + 1;
		else high = mid - 1;
	}
	cout << high << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
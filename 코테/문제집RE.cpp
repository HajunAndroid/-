#include<iostream>
#include<queue>
#include<vector>
#define MAX 32001
using namespace std;

int n, m;
int arr[MAX];
vector<vector<int>>v;

void bfs()
{
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int idx = q.top();
		q.pop();
		cout << idx << " ";
		for (int i = 0; i < v[idx].size(); i++) {
			int temp = v[idx][i];
			arr[temp]--;
			if (arr[temp] == 0) {
				q.push(temp);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[b]++;
		v[a].push_back(b);
	}
	bfs();
	return 0;
}
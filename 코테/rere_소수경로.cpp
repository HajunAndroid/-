#include<iostream>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
int a, b;
bool eratos[10000];
bool visited[10000];

void Eratos()
{
	eratos[1] = 0;
	for (int i = 2; i < 10000; i++) {
		if (eratos[i] == 0)continue;
		for (int j = i + i; j < 10000; j += i) {
			eratos[j] = 0;
		}
	}
}

void BFS()
{
	queue<pair<int, int>>q;
	q.push({ a,0 });
	visited[a] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == b) {
			cout << cnt << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			string sx = to_string(x);
			for (int j = 0; j < 10; j++) {
				sx[i] = j + '0';
				int ix = stoi(sx);
				if (ix < 1000)continue;
				if (visited[ix])continue;
				if (eratos[ix] == 0)continue;
				visited[ix] = 1;
				q.push({ ix,cnt + 1 });
			}
		}
	}
	cout << "Impossible\n";
}

int main()
{
	int t; cin >> t;
	memset(eratos, 1, sizeof(eratos));
	Eratos();
	while (t--) {
		cin >> a >> b;
		memset(visited, 0, sizeof(visited));
		BFS();
	}
	return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 102
using namespace std;

int map[MAX][MAX];
bool visited[MAX];

int Start;
int End;

vector<pair<int, int>>v;
int n;

void Input()
{
	memset(map, 0, sizeof(0));
	memset(visited, 0, sizeof(visited));
	v.clear();

	cin >> n;
	Start = 0; End = n + 1;
	int x, y;
	for (int i = 0; i <= n + 1; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}

	int temp;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = i; j <= n + 1; j++) {
			x = abs(v[i].first - v[j].first);
			y = abs(v[i].second - v[j].second);
			temp = (x + y) / 50;
			if ((x + y) % 50)temp++;
			map[i][j] = temp;
			map[j][i] = temp;
		}
	}
}

void Solution(int idx)
{
	visited[0] = 1;
	queue<int>q;
	q.push(idx);
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		if (idx == End) {
			cout << "happy" << endl;
			return;
		}
		for (int i = 0; i <= n + 1; i++) {
			if (visited[i])continue;
			if (map[idx][i] > 20)continue;
			visited[i] = 1;
			q.push(i);
		}
	}
	cout << "sad" << endl;
}

void Solve()
{
	int t; cin >> t;
	while (t--) {
		Input();
		Solution(0);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
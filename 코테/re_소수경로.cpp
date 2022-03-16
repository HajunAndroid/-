#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#define MAX 10000
using namespace std;

int a, b;
bool flag;
bool visited[MAX];
bool eratos[MAX];

void eratos_check()
{
	for (int i = 2; i < MAX; i++) {
		if (eratos[i] == 0)continue;
		for (int j = i + i; j < MAX; j += i) {
			eratos[j] = 0;
		}
	}
}

void bfs(int v, int cnt)
{
	queue<pair<int, int>>q;
	q.push({ v,cnt });
	visited[v] = 1;
	while (!q.empty()) {
		v = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (v == b) {
			cout << cnt << '\n';
			flag = 1;
			break;
		}
		string v_string = to_string(v);
		for (int i = 0; i< 4; i++) {
			for (int j = 0; j < 10; j++) {
				string temp = v_string;
				temp[i] = j + '0';
				int temp_int = stoi(temp);
				if (temp_int >= 1000 && eratos[temp_int] && !visited[temp_int]) {
					q.push({ temp_int,cnt + 1 });
					visited[temp_int] = 1;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	memset(eratos, 1, sizeof(eratos));
	eratos_check();
	while (t--) {
		flag = 0;
		cin >> a >> b;
		memset(visited, 0, sizeof(visited));
		bfs(a, 0);
		if (!flag) {
			cout << "Impossible" << '\n';
		}
	}
	return 0;
}
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 5002
using namespace std;

int people[MAX];
int visited[MAX];
vector<int> answer;
int n;
bool flag;

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}
	sort(people + 1, people + n + 1);
	memset(visited, 0, sizeof(visited));
	answer.clear();
	flag = false;
}

void Check()
{
	for (int i = 0; i < answer.size()-1; i++) {
		if (answer[i] + 1 == answer[i + 1]) {
			return;
		}
	}
	flag = true;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}

void DFS(int cnt)
{
	if (flag)return;
	if (cnt == n) {
		Check();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1)continue;
		visited[i] = 1;
		answer.push_back(people[i]);
		DFS(cnt + 1);
		answer.pop_back();
		visited[i] = 0;
	}
}

void Solution()
{
	DFS(0);
}

void Solve()
{
	int t;
	cin >> t;
	while (t--) {
		Input();
		Solution();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
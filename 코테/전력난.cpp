#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 200000
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>>v;
int parent[MAX];
int ans;
int cost;

int getParent(int idx)
{
	if (parent[idx] == idx)return idx;
	return getParent(parent[idx]);
}

bool isSameParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)return true;
	else return false;
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}

void Input()
{
	cin >> m >> n;
	if (m == 0 && n == 0) {
		exit(0);
	}
	v.clear();
	int a, b, c;
	ans = 0;
	cost = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
		cost += c;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		parent[i] = i;
	}
}

void Solution()
{
	int a, b, c;
	for (int i = 0; i < n; i++) {
		a = v[i].second.first;
		b = v[i].second.second;
		c = v[i].first;
		if (isSameParent(a, b) == false) {
			ans += c;
			unionParent(a, b);
		}
	}
	cout << cost - ans << '\n';
}

void Solve()
{
	while (true) {
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
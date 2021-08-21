#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 101
using namespace std;

int parent[MAX];

int find_parent(int idx)
{
	if (parent[idx] == idx)return idx;
	return find_parent(parent[idx]);
}

bool IS_same(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);
	if (a == b)return true;
	else return false;
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool cmp(vector<int> a, vector<int> b)
{
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs)
{
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	sort(costs.begin(), costs.end(),cmp);
	for (int i = 0; i < costs.size(); i++) {
		int a = costs[i][0];
		int b = costs[i][1];
		int c = costs[i][2];
		if (!IS_same(a, b)) {
			answer += c;
			union_parent(a, b);
		}
	}
	return answer;
}
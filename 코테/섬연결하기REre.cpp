#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 101

using namespace std;

int parent[MAX];
vector<pair<int, pair<int, int>>>v;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[2] < b[2])return true;
    return false;
}

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
    return false;
}

bool unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a > b)parent[a] = b;
    else parent[b] = a;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < costs.size(); i++) {
        int a = costs[i][0];
        int b = costs[i][1];
        int c = costs[i][2];
        v.push_back({ c,{a,b} });
    }
    sort(costs.begin(), costs.end(), cmp);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        int c = v[i].first;
        if (!isSameParent(a, b)) {
            answer += c;
            unionParent(a, b);
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>>cost;
    cost.resize(5);
    cost[0].push_back(0);
    cost[0].push_back(1);
    cost[0].push_back(1);

    cost[1].push_back(0);
    cost[1].push_back(2);
    cost[1].push_back(2);

    cost[2].push_back(1);
    cost[2].push_back(2);
    cost[2].push_back(5);

    cost[3].push_back(1);
    cost[3].push_back(3);
    cost[3].push_back(1);

    cost[4].push_back(2);
    cost[4].push_back(3);
    cost[4].push_back(8);

    cout << solution(4, cost);

    return 0;
}
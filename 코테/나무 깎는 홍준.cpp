#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int>v;
long long MAX;

void Input()
{
	cin >> n >> m;
	v.clear();
	long long temp;
	MAX = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		MAX = max(MAX, temp);
		v.push_back(temp);
	}
}

bool Promising(long long mid)
{
	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		long long temp = v[i] - mid;
		if (temp <= 0)continue;
		sum += temp;
	}
	if (sum >= m)return true;
	return false;
}

void Solution(int i)
{
	long long low = 0;
	long long high = MAX;
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (Promising(mid)) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << "#" << i << " ";
	cout << high << '\n';
}

void Solve()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		Input();
		Solution(i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
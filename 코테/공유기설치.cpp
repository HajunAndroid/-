#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, c;
vector<int>v;

bool Promissing(int mid)
{
	int cnt = 1;
	int prev = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] - prev >= mid) {
			prev = v[i];
			cnt++;
		}
	}
	if (cnt >= c)return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> c;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int low = 1;
	int high = v[n - 1] - v[0];
	int mid;
	int answer = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (Promissing(mid)) {
			answer = max(mid, answer);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << answer;
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << upper_bound(v.begin(), v.end(), num) -
			lower_bound(v.begin(), v.end(), num) << " ";

	}
	return 0;
}
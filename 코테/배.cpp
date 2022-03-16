#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int i, int j)
{
	return i > j;
}

int max_value(vector<int>& v, int n)
{
	int maxValue = v[0];
	for (int i = 0; i < n; i++) {
		if (maxValue < v[i])maxValue = v[i];
	}
	return maxValue;
}

int main()
{
	int n; cin >> n;
	vector<int>crane(n);
	for (int i = 0; i < n; i++)cin >> crane[i];
	int m; cin >> m;
	vector<int>box(m);
	for (int i = 0; i < m; i++)cin >> box[i];
	int craneMaxValue = max_value(crane, n);
	int boxMaxValue = max_value(box, m);
	if (craneMaxValue < boxMaxValue) {
		cout << -1; return 0;
	}
	sort(crane.begin(), crane.end(), compare);
	sort(box.begin(), box.end(), compare);
	int min = 0;
	while (true) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < box.size(); j++) {
				if (box[j] <= crane[i]) {
					box.erase(box.begin() + j);
					break;
				}
			}
			if (box.size() == 0)break;
		}
		min++;
		if (box.size() == 0)break;
	}
	cout << min;
}
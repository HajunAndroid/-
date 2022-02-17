#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> vn;
int m;
vector<int> vm;

void Input()
{
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vn.push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		vm.push_back(temp);
	}
	sort(vn.begin(), vn.end());
}

void Solve()
{
	for (int i = 0; i < m; i++) {
		int target = vm[i];
		int low = 0;
		int high = n - 1;
		int mid;
		bool flag = true;
		while (low <= high) {
			mid = (low + high) / 2;
			if (vn[mid] == target) {
				cout << "1 ";
				flag = false;
				break;
			}
			else if (vn[mid] > target) {
				high = mid - 1;
			}
			else if (vn[mid] < target) {
				low = mid + 1;
			}
		}
		if (flag)cout << "0 ";
	}
}

void Solve()
{
	Input();
	Solve();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
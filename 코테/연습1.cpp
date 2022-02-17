#include<iostream>
#include<map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	map<string, int> m;
	int t; cin >> t;
	int a; string b; int c;
	while (t--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			cin >> c;
			m[b] += c;
		}
		else if (a == 2) {
			cin >> b;
			m.erase(b);
		}
		else if (a == 3) {
			cin >> b;
			if (m.find(b) == m.end()) {
				cout << "0" << endl;
			}
			else {
				cout << m[b] << endl;
			}
		}
	}
	return 0;
}
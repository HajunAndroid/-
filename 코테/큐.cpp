#include<iostream>
#include<queue>
using namespace std;

int main()
{
	queue<int>q;
	int t; cin >> t;
	while (t--) {
		string str; cin >> str;
		int num;
		if (str == "push") {
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") {
			if (q.empty())cout << "-1" << endl;
			else {
				int temp = q.front();
				cout << temp<<endl;
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "empty") {
			if (q.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (str == "front") {
			if (q.empty())cout << "-1" << endl;
			else { cout << q.front() << endl; }
		}
		else if (str == "back") {
			if (q.empty())cout << "-1" << endl;
			else { cout << q.back() << endl; }
		}
	}
	return 0;
}
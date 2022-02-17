#include<iostream>
#include<vector>
#include<stack>
#define MAX 100001
using namespace std;

int n;
vector<int> arr;
vector<char> answer;

void Input()
{
	arr.clear();
	answer.clear();
	cin >> n;
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
}

void Solution(int term)
{
	int idx = 1;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		int now = arr[i];
		while (st.empty() || st.top() != now) {
			if (idx > n)break;
			st.push(idx++);
			answer.push_back('+');
		}
		if (st.top() == now) {
			st.pop();
			answer.push_back('-');
		}
	}
	if (st.empty()) {
		cout << "#" << term << " ";
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i];
		}
		cout << endl;
	}
	else {
		cout << "#" << term << " ";
		cout << "NO" << endl;
	}
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
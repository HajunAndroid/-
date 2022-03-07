#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

bool timeArr[1001];
int timeAns[101];

int n, a, b;

void Initialize()
{
	memset(timeArr, 0, sizeof(timeArr));
	memset(timeAns, 0, sizeof(timeAns));
}

void Input()
{
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		timeArr[temp] = true;
	}
}

void Solution()
{
	queue<int>q;
	int fin = 0;
	int Time = 0;
	int idx = 0;
	while (true) {
		if (fin == n)break;
		if (timeArr[Time])
			q.push(Time);
		if (q.empty()) {
			Time++;
			continue;
		}
		else {
			if (q.size() == a || Time - b == q.front()) {
				int Size = q.size() / 2 + q.size() % 2;
				for (int i = 0; i < Size; i++) {
					timeAns[idx++] = Time;
					q.pop();
					fin++;
				}
			}
		}
		Time++;
	}
}

void Solve()
{
	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		Initialize();
		Input();
		Solution();
		cout << "#" << i << " ";
		for (int j = 0; j < n; j++) {
			cout << timeAns[j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
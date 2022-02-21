#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;

int r, c, k;
int Map[MAX][MAX];

int row = 3;
int col = 3;

void Input()
{
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> Map[i][j];
		}
	}
	if (Map[r][c] == k) {
		cout << "0";
		exit(0);
	}
}

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if (a.second >= b.second) {
		if (a.second == b.second) {
			if (a.first < b.first) {
				return true;
			}
			return false;
		}
		return false;
	}
	return true;
}

bool cmp2(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)return true;
	return false;
}

void Move1()
{
	vector<pair<int, int>> len;
	for (int i = 1; i <= row; i++) {
		map<int,int> m;
		vector<int> keys;
		for (int j = 1; j <= col; j++) {
			if (Map[i][j] == 0)continue;
			int temp = Map[i][j];
			if (m.count(temp) == 0) {
				m[temp] = 1;
				keys.push_back(temp);
			}
			else {
				m[temp]++;
			}
		}
		vector<pair<int,int>> v;
		for (int j = 0; j < keys.size(); j++) {
			int temp = keys[j];
			int temp2 = m[temp];
			v.push_back({ temp,temp2 });
		}
		sort(v.begin(), v.end(), cmp);
		int idx = 1;
		for (int j = 0; j < v.size(); j++) {
			Map[i][idx++] = v[j].first;
			if (idx > 100) { 
				len.push_back({ i,100 });
				break; 
			}
			Map[i][idx++] = v[j].second;
			if (idx > 100) {
				len.push_back({ i,100 });
				break;
			}
		}
		idx--;
		len.push_back({ i,idx });
	}
	
	sort(len.begin(), len.end(),cmp2);
	int temp = len[0].second;
	col = temp;
	for (int i = 0; i <len.size(); i++) {
		int r = len[i].first;
		int c = len[i].second;
		for (int j = c+1; j <= col; j++) {
			Map[r][j] = 0;
		}
	}
}

void Move2()
{
	vector<pair<int, int>> len;
	for (int i = 1; i <= col; i++) {
		map<int, int> m;
		vector<int> keys;
		for (int j = 1; j <= row; j++) {
			if (Map[j][i] == 0)continue;
			int temp = Map[j][i];
			if (m.count(temp) == 0) {
				m[temp] = 1;
				keys.push_back(temp);
			}
			else {
				m[temp]++;
			}
		}
		vector<pair<int, int>> v;
		for (int j = 0; j < keys.size(); j++) {
			int temp = keys[j];
			int temp2 = m[temp];
			v.push_back({ temp,temp2 });
		}
		sort(v.begin(), v.end(), cmp);
		int idx = 1;
		for (int j = 0; j < v.size(); j++) {
			Map[idx++][i] = v[j].first;
			if (idx > 100) {
				len.push_back({ i,100 });
				break;
			}
			Map[idx++][i] = v[j].second;
			if (idx > 100) {
				len.push_back({ i,100 });
				break;
			}
		}
		idx--;
		len.push_back({ i,idx });
	}

	sort(len.begin(), len.end(), cmp2);
	
	/*for (int i = 0; i < len.size(); i++) {
		cout << len[i].first << " " << len[i].second << endl;
	}*/
	
	int temp = len[0].second;
	row = temp;
	for (int i = 0; i < len.size(); i++) {
		int r = len[i].first;//ї­
		int c = len[i].second;//За max
		for (int idx = c + 1; idx <= row; idx++) {
			Map[idx][r] = 0;
		}
	}
}

void Solution()
{
	int ans = 0;
	while (true) {
		
		if (row >= col) {
			Move1();
		}
		else {
			Move2();
		}

		ans++;

		/*cout << ans << '\n';
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				cout << Map[i][j] << " ";
			}
			cout << endl;
		}*/
		
		if (Map[r][c] == k) {
			cout << ans;
			break;
		}
		if (ans >= 100) {
			cout << "-1";
			break;
		}
	}
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
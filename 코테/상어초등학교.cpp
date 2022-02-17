#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 21
using namespace std;

int n;
int SEAT[MAX][MAX];
int EMPTY[MAX][MAX];
int LOVE[MAX][MAX];
vector<vector<int>>v;
vector<int> Sequence;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> n;
	v.resize(n*n + 1);
	int a, b;
	for (int i = 1; i <= n * n; i++) {
		cin >> a;
		Sequence.push_back(a);
		for (int j = 0; j < 4; j++) {
			cin >> b;
			v[a].push_back(b);
		}
	}
}

void Find(int idx)
{
	priority_queue<pair<int, pair<int, int>>>pq_love;
	priority_queue<pair<int, pair<int, int>>>pq_empty;
	int max_love = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (SEAT[i][j] != 0)continue;
			int cnt_love = 0;
			int cnt_empty = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx<1 || ny<1 || nx>n || ny>n)continue;
				for (int h = 0; h < 4; h++) {
					if (v[idx][h] == SEAT[nx][ny]) {
						cnt_love++;
						break;
					}
				}
				if (SEAT[nx][ny] == 0)cnt_empty++;
			}
			pq_love.push({ cnt_love,{i,j} });
			if (max_love < cnt_love) {
				max_love = cnt_love;
				while (!pq_empty.empty())pq_empty.pop();
				pq_empty.push({ cnt_empty,{i,j} });
			}
			else if (max_love == cnt_love) {
				pq_empty.push({ cnt_empty,{i,j} });
			}
		}
	}
	//조건1
	int temp_love = pq_love.top().first;
	int temp_x = pq_love.top().second.first;
	int temp_y = pq_love.top().second.second;
	pq_love.pop();
	if (pq_love.empty()) {
		SEAT[temp_x][temp_y] = idx;
		return;
	}
	int temp_love2 = pq_love.top().first;
	if (temp_love != temp_love2) {
		SEAT[temp_x][temp_y] = idx;
		return;
	}
	//조건2
	int temp_empty = pq_empty.top().first;
	temp_x = pq_empty.top().second.first;
	temp_y = pq_empty.top().second.second;
	pq_empty.pop();
	if (pq_empty.empty()) {
		SEAT[temp_x][temp_y] = idx;
		return;
	}
	int temp_empty2 = pq_empty.top().first;
	if (temp_empty != temp_empty2) {
		SEAT[temp_x][temp_y] = idx;
		return;
	}
	//조건3
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>npq;
	npq.push({ temp_x,temp_y });
	
	while (temp_empty == pq_empty.top().first) {
		npq.push({ pq_empty.top().second.first,pq_empty.top().second.second });
		pq_empty.pop();
		if (pq_empty.empty())break;
	}
	SEAT[npq.top().first][npq.top().second] = idx;
}

void SUM()
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int now = SEAT[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				for (int h = 0; h < 4; h++) {
					int nx = i + dx[h];
					int ny = j + dy[h];
					if (nx<1 || ny<1 || nx>n || ny>n)continue;
					if (SEAT[nx][ny] == v[now][k]) {
						cnt++;
						break;
					}
				}
			}
			if (cnt == 1) {
				sum += 1;
			}
			else if (cnt == 2) {
				sum += 10;
			}
			else if (cnt == 3) {
				sum += 100;
			}
			else if (cnt == 4) {
				sum += 1000;
			}
		}
	}
	cout << sum;
}

void Solve()
{
	for (int i = 0; i < n * n; i++) {
		int now_student = Sequence[i];
		memset(LOVE, 0, sizeof(LOVE));
		memset(EMPTY, 0, sizeof(EMPTY));
		Find(now_student);
	}
	SUM();
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
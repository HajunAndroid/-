#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;

struct Shark
{
	int r, c, s, d, z;
};

vector<Shark> map[MAX][MAX];
vector<Shark> c_map[MAX][MAX];
int R, C, M;

int sum;
int idx = 0;

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };

void Input()
{
	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		Shark shark;
		shark.r = r; shark.c = c; shark.s = s;
		shark.d = d; shark.z = z;
		map[r][c].push_back(shark);
	}
}

bool cmp(Shark a, Shark b)
{
	if (a.z > b.z)return true;
	return false;
}

void Move()
{
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			c_map[i][j].clear();
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j].size() == 0)continue;
			int d = map[i][j][0].d;
			int r = map[i][j][0].r;
			int c = map[i][j][0].c;
			int z = map[i][j][0].z;
			int ss = map[i][j][0].s;
			if (d == 1 || d == 2) {
				int s = map[i][j][0].s % ((R - 1) * 2);
				while (s--) {
					r += dx[d];
					c += dy[d];
					if (r == 0) {
						r = 2;
						d = 2;
					}
					else if (r == R + 1) {
						r = R - 1;
						d = 1;
					}
				}
			}
			else {
				int s = map[i][j][0].s % ((C - 1) * 2);
				while (s--) {
					r += dx[d];
					c += dy[d];
					if (c == 0) {
						//cout << "######\n";
						c = 2;
						d = 3;
					}
					else if (c == C + 1) {
						c = C - 1;
						d = 4;
					}
				}
			}
			Shark shark;
			shark.r = r; shark.c = c; shark.s = ss;
			shark.d = d; shark.z = z;
			c_map[r][c].push_back(shark);
			//cout <<"fish"<< r << " " << c << " " << endl;
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j].clear();
			if (c_map[i][j].size() == 0)continue;
			else if (c_map[i][j].size() == 1) {
				map[i][j] = c_map[i][j];
			}
			else if (c_map[i][j].size() >= 2) {
				sort(c_map[i][j].begin(), c_map[i][j].end(), cmp);
				map[i][j].push_back(c_map[i][j][0]);
			}
		}
	}
}

void Solution()
{
	while (idx < C) {
		idx++;
		for (int i = 1; i <= R; i++) {
			if (map[i][idx].size() != 0) {
				sum += map[i][idx][0].z;
				map[i][idx].clear();
				break;
			}
		}
		/*
		cout << idx << "before\n";
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j].size() == 0)cout << "0 ";
				else cout << map[i][j][0].z << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		Move();
		/*
		cout << idx<<"after@@@\n";
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j].size() == 0)cout << "0 ";
				else cout << map[i][j][0].z << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
	}
	cout << sum;
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
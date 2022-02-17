#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAX 25
using namespace std;

struct BLOCK
{
	int size;
	int rainbow_cnt;
	int x;
	int y;
	vector<pair<int, int>>block_pos;
};

int n, m, answer;
int map[MAX][MAX];
bool visited[MAX][MAX];
bool r_visited[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

bool cmp(pair<int, int>a, pair<int, int>b)
{
	if (a.first <= b.first) {
		if (a.first == b.first) {
			if (a.second < b.second) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

BLOCK BFS(int a, int b, int color)
{
	memset(r_visited, false, sizeof(r_visited));
	vector<pair<int, int>>block;
	vector<pair<int, int>>except_rainbow_block;
	queue<pair<int, int>>q;
	block.push_back({ a,b });
	except_rainbow_block.push_back({ a,b });
	q.push({ a,b });
	visited[a][b] = true;
	int rainbow = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (map[nx][ny] == 0) {
					if (r_visited[nx][ny] == false) {
						r_visited[nx][ny] = true;
						rainbow++;
						block.push_back({ nx,ny });
						q.push({ nx,ny });
					}
				}
				else if (map[nx][ny] == color) {
					if (visited[nx][ny] == false) {
						visited[nx][ny] = true;
						q.push({ nx,ny });
						block.push_back({ nx,ny });
						except_rainbow_block.push_back({ nx,ny });
					}
				}
			}
		}
	}
	sort(except_rainbow_block.begin(), except_rainbow_block.end(), cmp);
	BLOCK r_block;
	r_block.size = block.size();
	r_block.rainbow_cnt = rainbow;
	r_block.x = except_rainbow_block[0].first;
	r_block.y = except_rainbow_block[0].second;
	r_block.block_pos = block;
	return r_block;
}
bool compare_block(BLOCK a, BLOCK b)
{
	if (a.size >= b.size) {
		if (a.size == b.size) {
			if (a.rainbow_cnt >= b.rainbow_cnt) {
				if (a.rainbow_cnt == b.rainbow_cnt) {
					if (a.x >= b.x) {
						if (a.x == b.x) {
							if (a.y > a.y) {
								return true;
							}
							return false;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

BLOCK find_biggest_block()
{
	memset(visited, false, sizeof(visited));
	BLOCK Result;
	Result.size = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == true)continue;
			if (map[i][j] == -1 || map[i][j] == -2 || map[i][j] == 0)continue;
			BLOCK temp_result = BFS(i, j, map[i][j]);

			if (Result.size == -1)Result = temp_result;
			else {
				if (compare_block(temp_result, Result) == true) Result = temp_result;
			}
		}
	}
	return Result;
}

void Delete_Block(BLOCK Result)
{
	vector<pair<int, int>>v = Result.block_pos;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		map[x][y] = -2;
	}
	answer += (v.size() * v.size());
}

void Gravity()
{
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == -2) continue;
			if (map[i][j] == -1) continue;

			int Color = map[i][j];
			int nx = i + 1;
			while (1)
			{
				if (map[nx][j] != -2) break;
				if (nx == n) break;
				nx++;
			}
			nx--;
			map[i][j] = -2;
			map[nx][j] = Color;
		}
	}
}

void Rotate()
{
	for (int i = 0; i < n / 2; i++)
	{
		int Sx = i;
		int Sy = i;
		int Ex = n - i - 1;
		int Ey = n - i - 1;

		int x_Idx = Ex;
		int y_Idx = Sy;
		int Idx = 0;
		vector<int> Temp;
		for (int x = Ex; x > Sx; x--) Temp.push_back(map[x][Sy]);
		for (int y = Sy; y < Ey; y++) map[x_Idx--][Sy] = map[Sx][y];
		for (int x = Sx; x < Ex; x++) map[Sx][y_Idx++] = map[x][Ey];
		for (int y = Ey; y > Sy; y--) map[x_Idx++][Ey] = map[Ex][y];
		for (int y = Ey; y > Sy; y--) map[Ex][y] = Temp[Idx++];
	}
}

void Solve()
{
	while (1) {
		BLOCK Result = find_biggest_block();
		if (Result.size < 2)break;
		Delete_Block(Result);
		Gravity();
		Rotate();
		Gravity();
	}
	cout << answer << endl;
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
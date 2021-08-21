#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;

bool visited[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int M, N;

int BFS(int x, int y, int number, vector<vector<int>>& picture)
{
	int cnt = 1;
	visited[x][y] = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)continue;
			if (visited[nx][ny])continue;
			if (picture[nx][ny] != number)continue;
			cnt++;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>>picture)
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	memset(visited, 0, sizeof(visited));
	M = m; N = n;

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != 1) {
				if (picture[i][j] == 0)continue;
				cnt++;
				int temp = BFS(i, j, picture[i][j], picture);
				max_size_of_one_area = max(max_size_of_one_area, temp);
			}
		}
	}
	number_of_area = cnt;
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
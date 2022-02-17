#include<string>
#include<vector>
#include<queue>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool BFS(int a, int b, vector<string> MAP)
{
	vector<vector<bool>>visited(5, vector<bool>(5, false));
	queue<pair<pair<int, int>, int>>q;
	q.push({ {a,b},1 });
	visited[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (cnt == 3)continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)continue;
			if (visited[nx][ny])continue;
			if (MAP[nx][ny] == 'O') {
				visited[nx][ny] = true;
				q.push({ {nx,ny},cnt + 1 });
			}
			else if (MAP[nx][ny] == 'P') {
				return false;
			}
		}
	}
	return true;
}

int Find_Answer(vector<string>MAP)
{
	for (int i = 0; i < MAP.size(); i++) {
		for (int j = 0; j < MAP[i].size(); j++) {
			if (MAP[i][j] == 'P') {
				if (BFS(i, j, MAP) == false)
					return 0;
			}
		}
	}
	return 1;
}

vector<int> Function(vector<vector<string>>MAP)
{
	vector<int> Result;
	for (int i = 0; i < MAP.size(); i++) {
		Result.push_back(Find_Answer(MAP[i]));
	}
	return Result;
}

vector<int> solution(vector<vector<string>>places)
{
	vector<int> answer;
	answer = Function(places);
	return answer;
}
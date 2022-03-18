#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#define MAX 25
using namespace std;

int N, M;
bool Finish_Mark;
bool Visit[MAX][MAX][4][16];
char MAP[MAX][MAX];
string Answer;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void Initialize()
{
	Finish_Mark = false;
	memset(Visit, false, sizeof(Visit));
}

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == '@')Finish_Mark = true;
		}
	}
}

void Solution()
{
    queue<pair<pair<int, int>, pair<int, int>>>Q;
    Q.push({ {0,0},{0,0} });
    Visit[0][0][0][0] = true;
    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Dir = Q.front().second.first;
        int Memory = Q.front().second.second;
        Q.pop();
        if (MAP[x][y] == '@') {
            Answer = "YES";
            return;
        }
        char C = MAP[x][y];
        int nDir, nMemory;
        nDir = Dir;
        nMemory = Memory;

        if (C == '<') nDir = 1;
        else if (C == '>') nDir = 0;
        else if (C == '^') nDir = 3;
        else if (C == 'v') nDir = 2;
        else if (C == '_') nDir = Memory == 0 ? 0 : 1;
        else if (C == '|') nDir = Memory == 0 ? 2 : 3;
        else if (C == '+') nMemory = Memory + 1 == 16 ? 0 : Memory + 1;
        else if (C == '-') nMemory = Memory - 1 == -1 ? 15 : Memory - 1;
        else if ('0' <= C && C <= '9') nMemory = C - '0';
        
        if (C == '?') {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0)nx = N - 1;
                else if (nx == N)nx = 0;
                if (ny < 0)ny = M - 1;
                else if (ny == M)ny = 0;
                
                if (Visit[nx][ny][i][nMemory] == false) {
                    Visit[nx][ny][i][nMemory] = true;
                    Q.push({ {nx,ny},{i,nMemory} });
                }
            }
        }
        else {
            int nx = x + dx[nDir];
            int ny = y + dy[nDir];
            if (nx < 0)nx = N - 1;
            else if (nx == N)nx = 0;
            if (ny < 0)ny = M - 1;
            else if (ny == M)ny = 0;
            if (Visit[nx][ny][nDir][nMemory] == false) {
                Visit[nx][ny][nDir][nMemory] = true;
                Q.push({ {nx,ny},{nDir,nMemory} });
            }
        }
    }
    Answer = "NO";
}

void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();

        cout << "#" << T << " " << Answer << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
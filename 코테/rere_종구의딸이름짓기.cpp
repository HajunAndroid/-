#include<iostream>
#include<string>
#include<cstring>
#include<queue>

#define MAX 2000
using namespace std;

int N, M;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];
string Answer;

int dx[] = { 0,1 };
int dy[] = { 1,0 };

void Initialize()
{
	Answer = "";
	memset(Visit, false, sizeof(Visit));
}

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
}

void Solution()
{
    queue<pair<int, int>>Q;
    Q.push({ 0,0 });
    Visit[0][0] = true;
    Answer += MAP[0][0];
    bool Flag = false;
    while (Q.empty() == 0) {
        int Q_Size = Q.size();
        char Min_Value = 'z';
        vector<pair<int, int>>V;
        for (int i = 0; i < Q_Size; i++) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            if (x == N - 1 && y == M - 1) {
                Flag = true;
                break;
            }
            for (int i = 0; i < 2; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (Visit[nx][ny] == false) {
                        if (MAP[nx][ny] <= Min_Value) {
                            if (MAP[nx][ny] < Min_Value) {
                                V.clear();
                            }
                            V.push_back({ nx,ny });
                            Visit[nx][ny] = true;
                            Min_Value = MAP[nx][ny];
                        }
                    }
                }
            }
        }
        for (int i = 0; i < V.size(); i++)
            Q.push(V[i]);
        if (Flag == false) {
            Answer += Min_Value;
        }
    }
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
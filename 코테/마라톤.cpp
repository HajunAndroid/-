#include<iostream>
#include<cstring>
#include<cmath>
#define MAX 510
using namespace std;

struct COORD
{
	int x;
	int y;
};

int N, K, Answer;
COORD Coord[MAX];
int DP[MAX][MAX];

int Min(int A, int B) { return A < B ? A : B; }

void Initialize()
{
	memset(DP, -1, sizeof(DP));
}

int Dist(int pos1, int pos2)
{
	return abs(Coord[pos1].x - Coord[pos2].x) +
		abs(Coord[pos1].y - Coord[pos2].y);
}

void Input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> Coord[i].x >> Coord[i].y;
	}
}

int DFS(int Cur, int Spare_Jump)
{
	if (Cur == N - 1)return 0;
	if (DP[Cur][Spare_Jump] != -1)return DP[Cur][Spare_Jump];
	DP[Cur][Spare_Jump] = 1e9;
	for (int i = 0; i <= K; i++) {
		int Next = Cur + i + 1;
		if (Next >= N)continue;
		if (Spare_Jump - i < 0)continue;
		DP[Cur][Spare_Jump] = Min(DP[Cur][Spare_Jump],
			DFS(Next, Spare_Jump - i) + Dist(Cur,Next));
	}
	return DP[Cur][Spare_Jump];
}

void  Solution()
{
	Answer = DFS(0, K);
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
	Solve();
	return 0;
}
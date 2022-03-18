#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 9
using namespace std;

int N, Sum, Answer;
int Arr[MAX];
bool Select[MAX];

int Exp[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
int Factorial[] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

void Initialize()
{
    Answer = 0;
    Sum = 0;
    memset(Select, false, sizeof(Select));
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
        Sum = Sum + Arr[i];
    }
}

void DFS(int Cnt, int Left, int Right)
{
    if (Cnt == N) {
        Answer++;
        return;
    }
    if (Left >= Sum - Left) {
        Answer = Answer + Exp[N - Cnt] * Factorial[N - Cnt];
        return;
    }
    for (int i = 0; i < N; i++) {
        if (Select[i] == true)continue;
        Select[i] = true;
        DFS(Cnt + 1, Left + Arr[i], Right);

        if (Right + Arr[i] <= Left)
            DFS(Cnt + 1, Left, Right + Arr[i]);
        Select[i] = false;
    }
}

void Solution()
{
    DFS(0, 0, 0);
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
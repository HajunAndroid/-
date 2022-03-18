#include<iostream>
#include<queue>
#include<cstring>
#define MAX 1010
#define MAIL_MAX 105
using namespace std;

int N, A, B;
int Answer[MAIL_MAX];
bool Mail[MAX];

void Initialize()
{
	memset(Mail, false, sizeof(Mail));
}

void Input()
{
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        Mail[a] = true;
    }
}

void Solution()
{
    queue<int>Q;
    int Finish = 0;
    int Time = 0;
    int Idx = 0;
    while (1) {
        if (Finish == N)break;
        if (Time < MAX && Mail[Time] == true)Q.push(Time);
        int Mail_Cnt = Q.size();
        if (Mail_Cnt == 0) {
            Time++;
            continue;
        }
        if (Mail_Cnt == A || Q.front() + B == Time) {
            int Read = (Q.size() / 2) + (Q.size() % 2);
            for (int i = 0; i < Read; i++) {
                Q.pop();
                Answer[Idx++] = Time;
                Finish++;
            }
        }
        Time++;
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

        cout << "#" << T << " ";
        for (int i = 0; i < N; i++) cout << Answer[i] << " ";
        cout << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}

#include<string>
#include<vector>
using namespace std;

int Max_Cnt = 9;
int Arr[8];

void Make_NumberArray(int n)
{
	int Temp = n;
	for (int i = 0; i < 8; i++) {
		Arr[i] = Temp;
		Temp = Temp * 10;
		Temp = Temp + n;
	}
}

void DFS(int cnt, int res, int number)
{
	if (cnt >= Max_Cnt)return;
	if (res == number) {
		Max_Cnt = cnt;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int ncnt = cnt + (i + 1);
		DFS(ncnt, res + Arr[i], number);
		DFS(ncnt, res - Arr[i], number);
		DFS(ncnt, res * Arr[i], number);
		DFS(ncnt, res / Arr[i], number);
	}
}

int solution(int n, int number)
{
	Make_NumberArray(n);
	DFS(0, 0, number);
	if (Max_Cnt == 9)Max_Cnt = -1;
	return Max_Cnt;
}
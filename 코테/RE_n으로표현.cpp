#include<string>
#include<vector>
using namespace std;

int max_cnt = 9;
int can_make[8];

void make_number(int n)
{
	int temp = n;
	for (int i = 0; i < 8; i++) {
		can_make[i] = temp;
		temp = temp * 10;
		temp += n;
	}
}

void DFS(int cnt, int res, int n, int number)
{
	if (cnt >= max_cnt)return;
	if (res == number) {
		max_cnt = cnt;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int ncnt = cnt + (i + 1);
		DFS(ncnt, res + can_make[i], n, number);
		DFS(ncnt, res - can_make[i], n, number);
		DFS(ncnt, res * can_make[i], n, number);
		DFS(ncnt, res / can_make[i], n, number);
	}
}

int solution(int n, int number)
{
	make_number(n);
	DFS(0, 0, n, number);
	if (max_cnt == 9)return -1;
	return max_cnt;
}
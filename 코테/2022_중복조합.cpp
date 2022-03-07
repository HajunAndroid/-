#include<iostream>
using namespace std;

int arr[5] = { 1,2,3,4,5 };
int select[3];

void DFS(int cnt, int idx)
{
	if (cnt == 3) {
		for (int i = 0; i < 3; i++) {
			cout << select[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = idx; i < 5; i++) {
		select[cnt] = arr[i];
		DFS(cnt + 1, i);
	}
}

int main()
{
	DFS(0, 0);
	return 0;
}
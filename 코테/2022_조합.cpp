#include<iostream>
using namespace std;

int arr[5] = { 1,2,3,4,5 };
int Select[3];

void DFS(int idx, int cnt)
{
	if (cnt == 3) {
		for (int i = 0; i < 3; i++) {
			cout << Select[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = idx; i < 5; i++) {
		Select[cnt] = arr[i];
		DFS(i + 1, cnt + 1);
	}
}

int main()
{
	DFS(0, 0);
	return 0;
}
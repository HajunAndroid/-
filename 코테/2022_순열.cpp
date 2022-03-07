#include<iostream>
using namespace std;

int arr[5] = { 1,2,3,4,5 };
bool visit[5];
int select[3];

void DFS(int cnt)
{
	if (cnt == 3) {
		for (int i = 0; i < 3; i++) {
			cout << select[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (visit[i])continue;
		visit[i] = true;
		select[cnt] = arr[i];
		DFS(cnt + 1);
		visit[i] = false;
	}
}

int main()
{
	DFS(0);
	return 0;
}
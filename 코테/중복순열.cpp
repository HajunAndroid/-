#include<iostream>
using namespace std;

int arr[6];
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
	for (int i = 1; i <= 5; i++) {
		select[cnt] = arr[i];
		DFS(cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 5; i++) {
		arr[i] = i;
	}

	DFS(0);

	return 0;
}
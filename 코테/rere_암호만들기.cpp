#include<iostream>
#include<algorithm>
#define MAX 15
using namespace std;
int l, c;
char arr[MAX];

void DFS(int idx, string s, int ja, int mo)
{
	if ((ja + mo) == l && mo >= 1 && ja >= 2) {
		cout << s << '\n';
		return;
	}
	for (int i = idx; i < c; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' ||
			arr[i] == 'o' || arr[i] == 'u') {
			DFS(i + 1, s + arr[i], ja, mo + 1);
		}
		else {
			DFS(i + 1, s + arr[i], ja + 1, mo);
		}
	}
}

int main()
{
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	DFS(0, "", 0, 0);
	return 0;
}
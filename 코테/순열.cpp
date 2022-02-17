#include<iostream>
#include<vector>
using namespace std;

int arr[6];
bool visited[6];
vector<int> v;

void DFS(int cnt)
{
	if (cnt == 3) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= 5; i++) {
		if (visited[i] == 1)continue;
		visited[i] = 1;
		v.push_back(arr[i]);
		DFS(cnt + 1);
		visited[i] = 0;
		v.pop_back();
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
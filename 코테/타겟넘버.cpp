#include<iostream>
#include<vector>
using namespace std;

int ans;

void DFS(int sum, int cnt, int target, int size, vector<int> &numbers, int idx)
{
	if (cnt == size)
	{
		if (sum == target) {
			ans++;
		}
		return;
	}
	DFS(sum + numbers[idx], cnt + 1, target, size, numbers, idx + 1);
	DFS(sum - numbers[idx], cnt + 1, target, size, numbers, idx + 1);
}

int solution(vector<int> numbers, int target) 
{
	int answer = 0;
	int size = numbers.size();
	DFS(0, 0, target, size, numbers, 0);
	answer = ans;
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
	int target = 3;
	cout<<solution(num, target);
	return 0;
}
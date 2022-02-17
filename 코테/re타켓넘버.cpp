#include<iostream>
#include<vector>
using namespace std;

int answer;
void DFS(int sum, int cnt, int target, int size, vector<int>& number, int idx)
{
	if (cnt == size) {
		if (sum == target) {
			answer++;
		}
		return;
	}
	DFS(sum + number[idx], cnt + 1, target, size, number, idx + 1);
	DFS(sum - number[idx], cnt + 1, target, size, number, idx + 1);
}

int solution(vector<int> numbers, int target) {
	DFS(0, 0, target, numbers.size(), numbers, 0);
	return answer;
}
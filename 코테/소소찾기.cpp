#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool visit_num[10000000];
bool visit_idx[7];
int ans;

bool check(int num)
{
	if (num < 2)return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)return false;
	}
	return true;
}

void DFS(string s, string temp)
{
	if (temp != "" && visit_num[stoi(temp)] == 0) {
		int number = stoi(temp);
		visit_num[number] = 1;
		if (check(number) == true)ans++;
	}
	for (int i = 0; i < s.length(); i++) {
		if (visit_idx[i] == 1)continue;
		visit_idx[i] = 1;
		DFS(s, temp + s[i]);
		visit_idx[i] = 0;
	}
}

int solution(string numbers)
{
	DFS(numbers,"");
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	string s = "17";
	cout << solution(s);
	return 0;
}
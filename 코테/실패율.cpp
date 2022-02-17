#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool Cmp(pair<double, int>a, pair<double, int>b)
{
	if (a.first >= b.first) {
		if (a.first == b.first) {
			if (a.second < b.second) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	vector<pair<double, int>>Fail;
	for (int i = 1; i <= N; i++) {
		int cur_stage = i;
		int clear_num = 0;
		int progress_num = 0;
		for (int j = 0; j < stages.size(); j++) {
			if (stages[j] >= cur_stage)clear_num++;
			if (stages[j] == cur_stage)progress_num++;
		}
		if (clear_num == 0)Fail.push_back(make_pair(0, cur_stage));
		else {
			double failPercent = (double)progress_num / (double)clear_num;
			Fail.push_back({ failPercent,cur_stage });
		}
	}
	sort(Fail.begin(), Fail.end(), Cmp);
	for (int i = 0; i < Fail.size(); i++)
		answer.push_back(Fail[i].second);
	return answer;
}
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int>a, vector<int>b)
{
	return a[1] < b[1];
}

int solution(vector<vector<int>> jobs)
{
	int start = 0;
	int time = 0;
	int size = jobs.size();
	sort(jobs.begin(), jobs.end(), compare);
	while (!jobs.empty()) {
		for (int i = 0; i < jobs.size(); i++) {
			if (jobs[i][0] <= start) {
				start += jobs[i][1];
				time += start - jobs[i][0];
				jobs.erase(jobs.begin() + i);
				break;
			}
			if (i == jobs.size() - 1)start++;
		}
	}
	return time / size;
}
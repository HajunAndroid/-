#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> routes)
{
	int answer = 1;
	sort(routes.begin(), routes.end());
	int cam_pos = routes[0][1];
	for (int i = 1; i < routes.size(); i++) {
		if (routes[i][1] < cam_pos)
			cam_pos = routes[i][1];
		else if (routes[i][0] > cam_pos) {
			answer++;
			cam_pos = routes[i][1];
		}
	}
	return answer;
}
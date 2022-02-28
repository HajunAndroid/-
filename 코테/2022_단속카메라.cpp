#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0]) return true;
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    int left = routes[0][0];
    int right = routes[0][1];
    for (int i = 1; i < routes.size(); i++) {
        if (right < routes[i][0]) {
            answer++;
            left = routes[i][0];
            right = routes[i][1];
        }
        else {
            right = min(right, routes[i][1]);
        }
    }
    answer++;
    return answer;
}
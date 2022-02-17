#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int left = 0;
    int right = people.size() - 1;
    while (left < right) {
        if (people[left] + people[right] <= limit) {
            left++;
            right--;
            answer++;
        }
        else {
            left++;
            answer++;
        }
    }
    if (left == right)answer++;
    return answer;
}

int main()
{
    vector<int> v;
    v.push_back(70);
    v.push_back(80);
    v.push_back(90);
    v.push_back(100);
    cout << solution(v, 100);
    return 0;
}
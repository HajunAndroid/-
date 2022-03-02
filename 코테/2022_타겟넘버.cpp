#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(int sum, int idx, vector<int> numbers, int target)
{
    if (idx == numbers.size()) {
        if (sum == target)
            answer++;
        return;
    }
    DFS(sum + numbers[idx], idx + 1, numbers, target);
    DFS(sum - numbers[idx], idx + 1, numbers, target);
}

int solution(vector<int> numbers, int target) {
    DFS(0, 0, numbers, target);
    return answer;
}
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int Invert_Time(vector<int> idx_v, int line_idx, vector<string> line)
{
	string result = "";
	int idx = 0;
	for (int i = 0; i < idx_v.size(); i++)
		result += line[line_idx][idx_v[i]];
	return stoi(result);
}

int Invert_Response_Time(int line_idx, vector<string> line)
{
	string result = "";
	int idx = 24;
	while (line[line_idx][idx] != 's') {
		if (line[line_idx][idx] == '.') {
			idx++; continue;
		}
		result += line[line_idx][idx++];
	}
	while (result.length() != 4)result += '0';
	return stoi(result);
}

bool Cmp(pair<int, bool> A, pair<int, bool> B)
{
	if (A.first <= B.first) {
		if (A.first == B.first) {
			if (A.second > B.second) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int solution(vector<string> lines)
{
	vector<string> my_lines = lines;
	vector<pair<int, bool>> Time;
	for (int i = 0; i < my_lines.size(); i++) {
		int H = Invert_Time({ 11,12 }, i, my_lines);
		int M = Invert_Time({ 14,15 }, i, my_lines);
		int S = Invert_Time({ 17,18 }, i, my_lines);
		int MS = Invert_Time({ 20,21,22 }, i, my_lines);
		int Response_Time = Invert_Response_Time(i, my_lines);
		H = H * 60 * 60 * 1000;
		M = M * 60 * 1000;
		S = S * 1000;
		int total_time = H + M + S + MS;
		int start_time = total_time - Response_Time + 1;
		int end_time = total_time + 999;

		Time.push_back({ start_time,true });
		Time.push_back({ end_time,false });
	}
	sort(Time.begin(), Time.end(), Cmp);
	int traffic = 0;
	int answer = 0;
	for (int i = 0; i < Time.size(); i++) {
		if (Time[i].second == true)traffic++;
		else traffic--;

		if (answer < traffic) answer = traffic;
	}
	return answer;
}
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int Invert_Time(vector<int> Idx_V, int line_Idx, vector<string> line)
{
	string Result = "";
	int Idx = 0;
	for (int i = 0; i < Idx_V.size(); i++)
		Result += line[line_Idx][Idx_V[i]];
	return stoi(Result);
}

int Invert_Response_Time(int line_Idx, vector<string>line)
{
	string Result = "";
	int Idx = 24;
	while (line[line_Idx][Idx] != 's') {
		if (line[line_Idx][Idx] == '.') {
			Idx++;
			continue;
		}
		Result += line[line_Idx][Idx++];
	}
	while (Result.length() != 4) Result += '0';
	return stoi(Result);
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
	vector<string> My_lines = lines;
	vector<pair<int, bool>> Time;
	for (int i = 0; i < My_lines.size(); i++) {
		int H = Invert_Time({ 11,12 }, i, My_lines);
		int M = Invert_Time({ 14,15 }, i, My_lines);
		int S = Invert_Time({ 17,18 }, i, My_lines);
		int Ms = Invert_Time({ 20,21,22 }, i, My_lines);
		int Response_Time = Invert_Response_Time(i, My_lines);
		H = H * 60 * 60 * 1000;
		M = M * 60 * 1000;
		S = S * 1000;
		int Total_Time = H + M + S + Ms;
		int Start_Time = Total_Time - Response_Time + 1;
		int End_Time = Total_Time + 999;
		
		Time.push_back(make_pair(Start_Time, true));
		Time.push_back(make_pair(End_Time, false));
	}
	sort(Time.begin(), Time.end(), Cmp);
	int Traffic = 0;
	int answer = 0;
	for (int i = 0; i < Time.size(); i++) {
		if (Time[i].second == true)Traffic++;
		else Traffic--;

		if (answer < Traffic) answer = Traffic;
	}
	return answer;
}
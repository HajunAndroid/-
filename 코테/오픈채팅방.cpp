#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> answer;
	vector<pair<string, string>> temp;
	map<string, string> reserve;
	for (int i = 0; i < record.size(); i++) {
		if (record[i][0] == 'E') {
			int j;
			string id;
			for (j = 6; record[i][j] != ' '; j++) {
				id += record[i][j];
			}

			string nickname;
			for (int k = j + 1; k < record[i].size(); k++) {
				nickname += record[i][k];
			}

			reserve[id] = nickname;
			temp.push_back({ id,"E" });
		}
		else if (record[i][0] == 'L') {
			int j;
			string id;
			for (j = 6; j < record[i].size(); j++) {
				id += record[i][j];
			}

			temp.push_back({ id,"L" });
		}
		else if (record[i][0] == 'C') {
			int j;
			string id;
			for (j = 7; record[i][j] != ' '; j++) {
				id += record[i][j];
			}

			string nickname;
			for (int k = j + 1; k < record[i].size(); k++) {
				nickname += record[i][k];
			}
			reserve[id] = nickname;
		}
	}
	
	for (int i = 0; i < temp.size(); i++) {
		string result;
		result += reserve[temp[i].first];
		
		if (temp[i].second == "E") {
			result += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
		}
		else if (temp[i].second == "L") {
			result += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
		}
		answer.push_back(result);
	}
	return answer;
}
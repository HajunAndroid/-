#include<string>
#include<vector>
using namespace std;

bool Correct_String(string S)
{
	int flag = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '(')flag++;
		else flag--;
		if (flag < 0)return false;
	}
	return true;
}

string Parsing(string S, int Start, int End)
{
	string R = "";
	for (int i = Start; i <= End; i++) {
		R += S[i];
	}
	return R;
}

string solution(string p)
{
	if (p.length() == 0)return "";
	string U, V, Answer;
	int Open, Close;
	Open = Close = 0;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(')Open++;
		else Close++;
		if (Open == Close) {
			U = Parsing(p, 0, i);
			V = Parsing(p, i + 1, p.length() - 1);
			break;
		}
	}
	if (Correct_String(U) == true) {
		Answer = Answer + U;
		Answer = Answer + solution(V);
		return Answer;
	}
	else {
		string temp = "(";
		temp = temp + solution(V);
		temp = temp + ")";
		U = Parsing(U, 1, U.length() - 2);
		for (int i = 0; i < U.length(); i++) {
			if (U[i] == '(')temp = temp + ')';
			else temp = temp + '(';
		}
		return temp;
	}
}
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#define MAX 510
#define endl "\n"
using namespace std;

int N, M, Answer;
vector<int> Need_Tile;
vector<pair<pair<int, int>, bool>> Have_Tile;

void Initialize()
{
	Answer = 0;
	Need_Tile.clear();
	Have_Tile.clear();
}

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		int Len = pow(2, a);
		/*
		int Len = 1;
		for (int j = 0; j < a; j++) {
			Len <<= 1;
		}
		*/
		Need_Tile.push_back(Len);
	}
}

bool Cmp(int a, int b)
{
	return a > b ? true : false;
}

void Solution()
{
	sort(Need_Tile.begin(), Need_Tile.end(), Cmp);
	Have_Tile.push_back({ {M,M},false });
	Answer++;
	for (int i = 0; i < Need_Tile.size(); i++) {
		int Need_Len = Need_Tile[i];
		bool flag = false;
		for (int j = 0; j < Have_Tile.size(); j++) {
			if (Have_Tile[j].second == true)continue;
			int sero = Have_Tile[j].first.first;
			int garo = Have_Tile[j].first.second;
			if (sero >= Need_Len && garo >= Need_Len) {
				flag = true;
				Have_Tile[j].second = true;
				if (garo > Need_Len) Have_Tile.push_back(make_pair(make_pair(sero, garo - Need_Len), false));
				if (sero > Need_Len) Have_Tile.push_back(make_pair(make_pair(sero - Need_Len, Need_Len), false));
				break;
			}
		}
		if (flag == false) {
			Answer++;
			if (M > Need_Len) Have_Tile.push_back(make_pair(make_pair(M, M - Need_Len), false));
			if (M > Need_Len) Have_Tile.push_back(make_pair(make_pair(M - Need_Len, Need_Len), false));
		}
	}
}

void Solve()
{
	int Tc; cin >> Tc;
	for (int T = 1; T <= Tc; T++) {
		Initialize();
		Input();
		Solution();
		cout << "#" << T << " " << Answer << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	Solve();
	return 0;
}
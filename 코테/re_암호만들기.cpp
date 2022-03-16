#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int l, c;
vector<char>v;

void dfs(int index, string s, int ja, int mo)
{
	if (s.size() == l) {
		if (ja >= 2 && mo >= 1)
			cout << s << '\n';
		return;
	}
	for (int i = index; i < c; i++) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
			dfs(i + 1, s + v[i], ja, mo + 1);
		else
			dfs(i + 1, s + v[i], ja + 1, mo);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> l >> c;
	v.resize(c);
	for (int i = 0; i < c; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	dfs(0, "", 0, 0);
	return 0;
}
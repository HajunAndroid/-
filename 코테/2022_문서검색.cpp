#include<iostream>
#include<string>
using namespace std;

int main()
{
	string x; getline(cin, x);
	string y; getline(cin, y);
	int index = 0, result = 0;
	while ((x.size() - index >= y.size())) {
		bool same = true;
		for (int i = 0; i < y.size(); i++) {
			if (x[i + index] != y[i]) {
				same = false;
				index++;
				break;
			}
		}
		if (same) {
			result++;
			index += y.size();
		}
	}
	cout << result;
	return 0;
}
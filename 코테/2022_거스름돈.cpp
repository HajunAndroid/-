#include<iostream>
using namespace std;

int main()
{
	int x; cin >> x;
	x = 1000 - x;
	int sum = 0;
	while (x >= 500) {
		x -= 500;
		sum++;
	}
	while (x >= 100) {
		x -= 100;
		sum++;
	}
	while (x >= 50) {
		x -= 50;
		sum++;
	}
	while (x >= 10) {
		x -= 10;
		sum++;
	}
	while (x >= 5) {
		x -= 5;
		sum++;
	}
	while (x >= 1) {
		x -= 1;
		sum++;
	}
	cout << sum;

	return 0;
}
#include<iostream>
#include<cmath>
#define MAX 11
using namespace std;

int n;
int arr[MAX];
int Plus, Minus, Multiple, Divide;
int operator_num, max_value, min_value;

void Input()
{
	max_value = -1000000001;
	min_value = 1000000001;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> Plus >> Minus >> Multiple >> Divide;
	operator_num = n - 1;
}

void DFS(int pl, int mi, int mul, int div, int sum, int n_idx, int cnt)
{
	if (cnt == operator_num) {
		if (max_value < sum)max_value = sum;
		if (min_value > sum)min_value = sum;
		return;
	}
	if (pl < Plus)DFS(pl + 1, mi, mul, div, sum + arr[n_idx], n_idx +1 , cnt + 1);
	if (mi < Minus)DFS(pl, mi + 1, mul, div, sum - arr[n_idx], n_idx + 1, cnt + 1);
	if (mul < Multiple)DFS(pl, mi, mul + 1, div, sum * arr[n_idx], n_idx + 1, cnt + 1);
	if (div < Divide)DFS(pl, mi, mul, div + 1, sum / arr[n_idx], n_idx + 2, cnt + 1);
}

void Solution()
{
	
}
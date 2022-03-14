#include<iostream>
using namespace std;

template<typename T>
void sort(T* arr, T* end) {
	int l = 0, r = (end - arr) - 1;
	if (l >= r) return;
	T mid = arr[(l + r) / 2];
	while (l <= r) {
		while (arr[l] < mid) ++l;
		while (mid < arr[r]) --r;
		if (l <= r) {
			swap(arr[l++], arr[r--]);
		}
	}
	sort(arr, arr + l);
	sort(arr + l, end);
}
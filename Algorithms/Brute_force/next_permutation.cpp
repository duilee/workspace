#include <iostream>
#include <algorithm>
using namespace std;

//getting next permutation

bool next_permutation(int *a, int n){
	int i = n - 1;
	// largest i that satisfies below
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;
	if (i <= 0) return false; //last sequence
	int j = n - 1;
	// swap with the smallest larger number
	while (a[j] <= a[i - 1]) j -= 1;
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
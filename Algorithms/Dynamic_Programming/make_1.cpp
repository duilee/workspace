//given a number, get the shortest step to 1
// you can either divide by 3, 2 or subtract 1

#include <iostream>
using namespace std;

int d[10000];
int go(int n) {
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];
	d[n] = go(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = go(n / 2) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = go(n / 3) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	return d[n];
}

#include <iostream>
using namespace std;

int d[1000];
//for given array a
int a[1000];

int main()
{
// get the biggest consecutive sums
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		if (i == 0) continue;
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	return 0;
}

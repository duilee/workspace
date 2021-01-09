#include <iostream>
#include <algorithm>
using namespace std;
int d[100000];
int a[100000];

int main()
{
	int n;
	// getting longest increasing subsequence
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}

	return 0;
}


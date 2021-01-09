//fill in 2 x n tile given 1 x 2 tile. 

#include <iostream>
using namespace std;

int d[1001];

int main()
{
	d[0] = 1;
	d[1] = 1;
	int n;
	scanf_s("%d", &n);
	if (d[n] > 0) return d[n];
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	printf("%d\n", d[n]);
	return 0;
}
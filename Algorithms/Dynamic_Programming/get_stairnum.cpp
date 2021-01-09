#include <iostream>
using namespace std;

int d[1000][10];

int main()
{
// given length N
// get number of combinations for array of numbers with difference of 1
// ex, 45654 
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= 9; i++) d[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 0; j++) {
			d[i][j] = 0;
			if (j - 1 >= 0) d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9) d[i][j] += d[i - 1][j - 1];
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) ans += d[n][i];
	printf("%d", ans);
	return 0;
}

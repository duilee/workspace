#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1001][3];
int d[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 1000 * 1000 + 1;
	for (int k = 0; k <= 2; k++) { // house1's color
		for (int j = 0; j <= 2; j++) {
			if (j == k) {
				d[1][j] = a[1][j];
			}
			else {
				d[1][j] = 1000 * 1000 + 1;
			}
		}
		for (int i = 2; i <= n; i++) {
			d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
			d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
			d[i][2] = min(d[i - 1][1], d[i - 1][0]) + a[i][2];
		}
		for (int j = 0; j <= 2; j++) {
			if (j == k) continue;
			ans = min(ans, d[n][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}
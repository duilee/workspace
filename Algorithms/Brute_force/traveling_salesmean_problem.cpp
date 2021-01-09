#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// the famous TSP, traveling salesman problem
int a[20][20];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = i;
	}

	int ans = 2000000000;

	do{
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[d[i]][d[i + 1]] == 0) {
				ok = false;
			}
			else {
				sum += a[d[i]][d[i + 1]];
			}
		}
		if (ok && a[d[n - 1]][d[0]] != 0) {
			sum += a[d[n - 1]][d[0]];
			if (ans > sum) ans = sum;
		}
	} while (next_permutation(d.begin() + 1, d.end()));

	cout << ans << '\n';

	return 0;
}

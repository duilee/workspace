#include <iostream>
#include <algorithm>
using namespace std;

//choosing all permutation of length M from 1~N with no repetition
bool c[10];
int a[10];
void go(int index, int n, int m) {
	if (index == m){
		for (int i = 0; i < m; i++){
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++){
		if (c[i]) continue;
		c[i] = true;
		a[index] = i;
		go(index + 1, n, m);
		c[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	go(0, n, m);
	return 0;
}
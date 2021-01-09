#include <iostream>
#include <algorithm>
using namespace std;

//choosing all permutation of length M from 1~N with no repetition
// for ascending permutations only add start, and change condition
int a[10];
void go(int index, int start, int n, int m) {
	if (index == m){
		for (int i = 0; i < m; i++){
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++){
		a[index] = i;
		go(index + 1, i+1 ,n, m);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	return 0;
}


/*
//choosing all permutation of length M from 1~N with no repetition
// for ascending permutations only add start, and change condition
// this uses method to select whether certain number will be chosen or not
int a[10];
void go(int index, int selected, int n, int m) {
	if (selected == m){
		for (int i = 0; i < m; i++){
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index > n) return;
	a[selected] = index;
	go(index + 1, selected + 1, n, m);
	a[selected] = 0;
	go(index + 1, selected, n, m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	go(1, 0, n, m);
	return 0;
}
*/
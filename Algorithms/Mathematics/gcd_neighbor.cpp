#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// get shortest number of path to neighbors
// https://www.acmicpc.net/problem/17087

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b); 
	}
}

int main()
{
	int n;
	int s;
	int a[100000];
	int d;
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	d = a[0] - s;

	for (int i = 1; i < n; i++) {
		d = gcd(d, a[i] - s);
		if (d < 0) d = -d;
	}
	
	cout << d << '\n'; 
	
	return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n = 100;
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			printf("%d\n", i);
			n /= i;
		}
	}
	if (n > 1) {
		printf("%d\n", n);
	}
	return 0;
}

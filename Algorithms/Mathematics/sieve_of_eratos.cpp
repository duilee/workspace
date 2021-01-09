#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	//sieve of Eratosthenes
	int prime[100]; //save prime numbers
	int pn = 0; // number of primes
	bool check[101]; // True if erased
	int n = 100; // primes until 100
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i*i; j <= n; j += i) {
				check[j] = true;
			}
		}
	}
	return 0;
}

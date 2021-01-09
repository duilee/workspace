#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//check whether input integer n is prime
bool prime(int n) {
	if (n < 2){
		return false;
	}
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

#include <vector>
#include <stack>
using namespace std;

//get sum of all gcd combinations 
// given iteration t
// length of array n

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
	int t;
	cin >> t;
	
	while (t--){

		int n;
		cin >> n;
		int a[111];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long sum = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++) {
				sum += gcd(a[i],a[j]);
			}
		}

		cout << sum << '\n';
	}
	return 0;
}
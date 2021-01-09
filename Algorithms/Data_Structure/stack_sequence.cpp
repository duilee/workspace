#include <iostream>
#include <string>
#include <stack>
using namespace std;

//given a sequence, determine whether following sequence can be made
// using only pop and push of consecutive numbers

int main()
{
	stack<int> s;
	int n;
	string ans;

	cin >> n;

	int m = 0;

	while (n--) {
		int x;
		cin >> x;
		if (x > m) {
			while (x > m) {
				s.push(++m);
				ans += '+';
			}
			s.pop();
			ans += '-';
		}
		else {
			bool found = false;
			if (!s.empty()) {
				int top = s.top();
				s.pop();
				ans += '-';
				if (x == top) {
					found = true;
				}
			}
			if (!found) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	for (auto x : ans) {
		cout << x << '\n';
	}
	return 0;
}
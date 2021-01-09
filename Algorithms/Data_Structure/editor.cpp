#include <iostream>
#include <string>
#include <stack>
using namespace std;
char a[600000];
// editor
// L move cursor to the left
// D move cursor to the right
// B delete chracter on the left
// P$ add $ to the left

int main()
{
	scanf_s("%s", a);
	stack<char> left, right;
	int n = strlen(a);

	for (int i = 0; i < n; i++) {
		left.push(a[i]);
	}

	int m;
	scanf_s("%d", &m);
	while (m--) {
		char what;
		scanf_s(" %c", &what);
		if (what == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (what == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (what == 'B') {
			if (!left.empty()) {
				if (!left.empty()) {
					left.pop();
				}
			}
		}
		else if (what == 'P') {
			char c;
			scanf_s(" %c", &c);
			left.push(c);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}
	printf("\n");
	return 0;
}

#include <iostream>
using namespace std;

struct Node {
	int left;
	int right;
};
Node a[50];

void preorder(int x) {
	if (x == -1) return;
	cout << (char)(x + 'A');
	preorder(a[x].left);
	preorder(a[x].right);
}

void inorder(int x) {
	if (x == -1) return;
	inorder(a[x].left);
	cout << (char)(x + 'A');
	inorder(a[x].right);
}

void postorder(int x) {
	if (x == -1) return;
	postorder(a[x].left);
	postorder(a[x].right);
	cout << (char)(x + 'A');
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A';
		if (y == '.') {
			a[x].left = -1;
		}
		else {
			a[x].left = y - 'A';
		}
		if (z == '.') {
			a[x].right = -1;
		}
		else {
			a[x].right = z - 'A';
		}
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
	
}
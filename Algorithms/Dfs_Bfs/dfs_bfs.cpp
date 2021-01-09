#include <iostream>
#include <vector>
using namespace std;

int check[10000];
void dfs(int x) {
	// using adjacent matrix
	check[x] = true;
	for (int i = 1; i <= n; i++) {
		if (a[x][i] == 1 && check[i] == false) {
			dfs(i);
		}
	}
}

void dfs(int x) {
	//using adjacent list
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

void bfs() {
	//using adjacent matrix
	queue<int> q;
	check[1] = true; q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 1; i <= n; i++) {
			if (a[x][i] == 1 && check[i] == false) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

int bfs() {
	queue<int> q;
	check[1] == true; q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check[y] == false) {
				check[y] = true; q.push(y);
			}
		}
	}
}
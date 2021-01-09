// https://www.acmicpc.net/problem/16929

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char color[100][100]; 
bool check[100][100];
int dx[] = { 0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0};
int n, m;

bool go(int x, int y, int px, int py) {
	if (check[x][y] == 1) {
		return true;
	}
	check[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx, ny;
		nx = x + dx[k];
		ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (!(nx == px && ny == py)) {
				if (color[x][y] == color[nx][ny]) {
					if (go(nx, ny, x, y)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
			cin >> color[i];
	}

	bool ok;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			if (check[i][j]) continue;
			ok = go(i, j, -1, -1);
			if (ok == true) {
				cout << "Yes" << '\n';
				return 0;
			}
		}
	}
	cout << "No" << '\n';
	return 0;
	
}

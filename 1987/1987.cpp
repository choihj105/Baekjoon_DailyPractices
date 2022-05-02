#include <iostream>
using namespace std;

char board[20][20];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool alpabet[26]; // A ~ Z1987

int r, c;
int maxDist(0);

void switchV(char ch) {
	alpabet[ch - 'A'] = !alpabet[ch - 'A'];
}

void DFS(int y, int x, int cnt) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		
		// 한 번 지나간 알파벳인지 확인
		if (alpabet[board[ny][nx] - 'A']) continue;

		switchV(board[ny][nx]);
		DFS(ny, nx, cnt + 1);
		switchV(board[ny][nx]);
	}

	maxDist = maxDist < cnt ? cnt : maxDist;
}


int main() {

	// Input
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char tmp; cin >> tmp;
			board[i][j] = tmp;
		}
	}

	// Solve
	switchV(board[0][0]);
	DFS(0,0,1);

	// Output
	cout << maxDist;
}
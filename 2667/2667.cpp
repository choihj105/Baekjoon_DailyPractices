#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, totalCnt = 0;
int totalArr[400] = { 0, };
bool map[27][27] = { {0,} };  // (x, y)
queue<pair<int, int>> q;

void BFS(int x, int y) {
	q.push(make_pair(x, y));
	map[x][y] = false;

	while (!q.empty()) {
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();
		totalArr[totalCnt]++;

		if (map[_x + 1][_y]) {
			q.push(make_pair(_x + 1, _y));
			map[_x + 1][_y] = false;
		}
		if (map[_x - 1][_y]) {
			q.push(make_pair(_x - 1, _y));
			map[_x - 1][_y] = false;
		}
		if (map[_x][_y + 1]) {
			q.push(make_pair(_x, _y + 1));
			map[_x][_y + 1] = false;
		}
		if (map[_x][_y - 1]) {
			q.push(make_pair(_x, _y - 1));
			map[_x][_y - 1] = false;
		}
	}
}

int main() {
	// Input
	cin >> n;

	for (int i = 0; i < (n * n); i++) {
		int x = i % n; x++;
		int y = i / n; y++;
		char tmp; cin >> tmp;

		if (tmp == '0') map[x][y] = false;
		else if (tmp == '1') map[x][y] = true;
	}

	// ÀüÃ¼Å½»ö
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[j][i]) {
				++totalCnt;
				BFS(j, i);
			}
		}
	}

	// Output
	cout << totalCnt << endl;
	sort(totalArr + 1, totalArr + totalCnt + 1);
	for (int i = 1; i <= totalCnt; i++) {
		cout << totalArr[i] << endl;
	}
}
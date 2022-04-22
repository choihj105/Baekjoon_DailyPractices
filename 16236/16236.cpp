#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// variable
tuple<int, int, int> shark; // y, x, 상어크기
queue<tuple<int, int, int>> q; // BFS()
int n;
int map[22][22];
bool isVisited[22][22];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int MAX = 0, curEat = 0;

void check() {
	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void clear() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			isVisited[i][j] = false;
		}
	}
}

// 가까운 먹이 찾기 (거리가 같으면 맨 위, 그 중 맨 왼쪽)
int BFS() {
	int y = get<0>(shark); int x = get<1>(shark); int sharkSize = get<2>(shark);
	q.push({ y, x, 0});
	map[y][x] = 0;
	isVisited[y][x] = true;

	while (!q.empty()) {
		int _y = get<0>(q.front());
		int _x = get<1>(q.front());
		int _cnt = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (map[_y + dy[i]][_x + dx[i] ] <= sharkSize && !isVisited[_y + dy[i]][_x + dx[i]]) {
				if (map[_y + dy[i]][_x + dx[i]] != 0 && map[_y + dy[i]][_x + dx[i]] != sharkSize) {
					curEat++;
					if (curEat == sharkSize) {
						shark = { _y + dy[i], _x + dx[i], sharkSize + 1 };
						curEat = 0;
					}
					else
						shark = { _y + dy[i], _x + dx[i], sharkSize };

					map[_y + dy[i]][_x + dx[i]] = 0;
					cout << "y: " << _y - 1 << " x: " << _x << " : " << _cnt + 1 << " size:" << get<2>(shark) << endl;
					while (!q.empty()) q.pop();
					return _cnt + 1;
				}
				else {
					q.push({ _y + dy[i],_x + dx[i], _cnt + 1 });
					isVisited[_y + dy[i]][_x + dx[i]] = true;
				}
			}
		}
	}

	return 0;
}


int main() {

	// Input
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int x = i % n; x++;
		int y = i / n; y++;

		cin >> map[y][x];
		if (map[y][x] == 9) shark = { y, x, 2 };
	}

	// 벽치기
	for (int i = 0; i <= n + 1; i++) {
		isVisited[i][0] = true;
		isVisited[i][n+1] = true;
		isVisited[0][i] = true;
		isVisited[n+1][i] = true;
	}

	// Algorithm
	while (true) {
		int k = BFS();
		check();
		clear();
		if (k == 0) break;
		else MAX += k;
	}

	// Output
	cout << MAX;
}
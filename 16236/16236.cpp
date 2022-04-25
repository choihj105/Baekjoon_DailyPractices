#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// variable
tuple<int, int, int> shark; // y, x, 상어크기
queue<tuple<int, int, int>> q; // BFS를 위한 Q (y, x, 이동거리)
int n;
int map[22][22];
bool isVisited[22][22];
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int MAX = 0, curFeed = 0, feedY = -1, feedX = -1;

void clear() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			isVisited[i][j] = false;
		}
	}
	feedY = -1;
	feedX = -1;
}

// 가까운 먹이 찾기 (거리가 같으면 맨 위(같은 행이면 그 행), 그 중 맨 왼쪽)
int BFS() {
	int Min = 123123; // 최소거리
	int y = get<0>(shark); int x = get<1>(shark); 
	int sharkSize = get<2>(shark);
	q.push({ y, x, 0});
	map[y][x] = 0;
	isVisited[y][x] = true;

	while (!q.empty()) {
		int _y = get<0>(q.front()); int _x = get<1>(q.front()); // y좌표, x좌표
		int _cnt = get<2>(q.front()); // 물고기까지의 거리
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = _y + dy[i];
			int nx = _x + dx[i];

			// 지도밖으로 넘어갔을 경우 넘어갑니다.
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			// 이미 방문한 물고기이고, 상어보다 큰 물고기인경우 넘어갑니다.
			if (isVisited[ny][nx] || map[ny][nx] > sharkSize) continue;

			// 먹을 수 있는 물고기인 경우
			if (map[ny][nx] < sharkSize && map[ny][nx] != 0) {
				// 최소 거리인 경우
				if (Min > (_cnt + 1)) {
					Min = _cnt + 1;
					feedY = ny;
					feedX = nx;
				}
				// 최소 거리가 여러마리이고, 우선순위에 따르는 경우
				else if (Min == (_cnt + 1)) {
					// 다른 행인 경우
					if (feedY > ny) {
						feedY = ny;
						feedX = nx;
					}
					// 같은 행인경우, 왼쪽를 기준으로
					else if (feedY == ny) {
						// 왼쪽을 기준으로
						if (feedX > nx) {
							feedY = ny;
							feedX = nx;
						}
					}
				}
			}
			// 이동한 곳은 넣어두고, 다시는 못찾게 만듭니다.
			q.push({ ny, nx, _cnt + 1 });
			isVisited[ny][nx] = true;
		}
	}

	// 먹이를 찾은 아기상어
	if (Min != 123123) {
		return Min;
	}
	// 먹이를 찾지 못한 아기상어, 엄마를 부릅니다 엄마~
	else {
		return 0;
	}

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

	// Algorithm
	while (true) {
		clear();
		int t = BFS();
		if (t == 0) break;
		else {
			// 먹이를 찾은 아기상어
			MAX += t;
			map[feedY][feedX] = 0;

			// 아기상어 몸집 및 위치 갱신
			curFeed++;
			if (curFeed == get<2>(shark)) {
				shark = { feedY, feedX, get<2>(shark) + 1 };
				curFeed = 0;
			}
			else {
				shark = { feedY, feedX, get<2>(shark) };
			}
		}
	}

	// Output
	cout << MAX;
}
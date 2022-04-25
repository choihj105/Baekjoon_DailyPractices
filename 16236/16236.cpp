#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// variable
tuple<int, int, int> shark; // y, x, ���ũ��
queue<tuple<int, int, int>> q; // BFS�� ���� Q (y, x, �̵��Ÿ�)
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

// ����� ���� ã�� (�Ÿ��� ������ �� ��(���� ���̸� �� ��), �� �� �� ����)
int BFS() {
	int Min = 123123; // �ּҰŸ�
	int y = get<0>(shark); int x = get<1>(shark); 
	int sharkSize = get<2>(shark);
	q.push({ y, x, 0});
	map[y][x] = 0;
	isVisited[y][x] = true;

	while (!q.empty()) {
		int _y = get<0>(q.front()); int _x = get<1>(q.front()); // y��ǥ, x��ǥ
		int _cnt = get<2>(q.front()); // ���������� �Ÿ�
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = _y + dy[i];
			int nx = _x + dx[i];

			// ���������� �Ѿ�� ��� �Ѿ�ϴ�.
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			// �̹� �湮�� ������̰�, ���� ū ������ΰ�� �Ѿ�ϴ�.
			if (isVisited[ny][nx] || map[ny][nx] > sharkSize) continue;

			// ���� �� �ִ� ������� ���
			if (map[ny][nx] < sharkSize && map[ny][nx] != 0) {
				// �ּ� �Ÿ��� ���
				if (Min > (_cnt + 1)) {
					Min = _cnt + 1;
					feedY = ny;
					feedX = nx;
				}
				// �ּ� �Ÿ��� ���������̰�, �켱������ ������ ���
				else if (Min == (_cnt + 1)) {
					// �ٸ� ���� ���
					if (feedY > ny) {
						feedY = ny;
						feedX = nx;
					}
					// ���� ���ΰ��, ���ʸ� ��������
					else if (feedY == ny) {
						// ������ ��������
						if (feedX > nx) {
							feedY = ny;
							feedX = nx;
						}
					}
				}
			}
			// �̵��� ���� �־�ΰ�, �ٽô� ��ã�� ����ϴ�.
			q.push({ ny, nx, _cnt + 1 });
			isVisited[ny][nx] = true;
		}
	}

	// ���̸� ã�� �Ʊ���
	if (Min != 123123) {
		return Min;
	}
	// ���̸� ã�� ���� �Ʊ���, ������ �θ��ϴ� ����~
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
			// ���̸� ã�� �Ʊ���
			MAX += t;
			map[feedY][feedX] = 0;

			// �Ʊ��� ���� �� ��ġ ����
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
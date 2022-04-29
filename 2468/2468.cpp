#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 1~100, ����  0���� 99���� ���� �� ���� �ó�����
// ó�� ���� �� ��, �ִ밪�� ������ ������ ���� ��
// BFS�� DFS�� ���Ͽ� ���� �ϴ� ���ϸ� �ɵ�?


// variable
int n;
int MAX = 0;

int map[100][100];
bool isVisited[100][100];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS(int rain) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] <= rain) {
				isVisited[i][j] = true;
			}
		}
	}

	int cnt(0);
	queue<pair<int, int>> q;
	for (int i = 0; i < n * n; i++) {
		int y = i / n; 
		int x = i % n; 

		if (isVisited[y][x]) continue;

		q.push({ y,x });
		isVisited[y][x] = true;

		// �ֺ� �� �ѷ�����
		while (!q.empty()) {
			int _y = q.front().first;
			int _x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int ny = _y + dy[j];
				int nx = _x + dx[j];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (isVisited[ny][nx]) continue;

				q.push({ ny,nx });
				isVisited[ny][nx] = true;
			}
		}
		cnt++;
	}
	
	return cnt;

}


int main() {
	// Input
	cin >> n;

	int heightMax(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			map[i][j] = tmp;
			heightMax = tmp > heightMax ? tmp : heightMax;
		}
	}

	// Solve
	for (int i = 0; i < heightMax; i++) {
		memset(isVisited, 0, sizeof(isVisited));
		int tmp = BFS(i);
		MAX = MAX < tmp ? tmp : MAX;
	}


	// Output
	cout << MAX;
}
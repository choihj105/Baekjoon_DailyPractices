#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//모눈종이 모양의 치즈에서 각 치즈 격자(작 은 정사각형 모양)의 
//4변 중에서 적어도 2변 이상이 실내온도의 공기와 접촉한 것은 정확히 한시간만에 녹아 없어져 버린다.

// 적어도, 3변이상이 모두 치즈 혹은 속에 있어야지 남아 있을 수 있습니다.
// 그렇다면 안의 공기는 어떻게 구할 수 있을까? -> 사실 구할 필요가 없네요

// 겉의 공기에서 접촉하는 치즈만 cnt를 올려주면되네요.

// Variable
int n, m;
int paper[101][101];
int cntAttachAir[101][101];
bool isVisited[101][101];

int dy[4] = { -1, 1, 0 ,0 };
int dx[4] = { 0, 0, -1 ,1 };

// 바깥 공기 체크
void airCheck() {

	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int _y = q.front().first;
		int _x = q.front().second;
		q.pop();

		if (isVisited[_y][_x]) continue;
		isVisited[_y][_x] = true;

		for (int i = 0; i < 4; i++) {
			int ny = _y + dy[i];
			int nx = _x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			
			if (paper[ny][nx] == 1) {
				cntAttachAir[ny][nx]++;
			}
			else if (paper[ny][nx] == 0) {
				q.push({ ny, nx });
			}
		}
	}
}

// 치즈 녹이기
void melt() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cntAttachAir[i][j] >= 2) paper[i][j] = 0;
		}
	}

}

// 치즈가 남아있는지 체크
bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] == 1) return true;
		}
	}
	return false;
}


int main() {

	// Input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	// Solve
	int hour(0);
	while (check()) {
		
		// 2차원 배열 초기화
		memset(isVisited, 0, sizeof(isVisited));
		memset(cntAttachAir, 0, sizeof(cntAttachAir));

		airCheck();
		melt(); // 치즈 녹이기
		hour++;
	}


	// Output
	cout << hour;

}
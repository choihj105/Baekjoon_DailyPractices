#include <iostream>
#include <queue>
using namespace std;

// 다리를 한개 씩 놓아 보는 방법 (바다 수 만큼 까지)
// 어떻게 이어진지를 아느냐는, 가지고 있는 bfs 수가 [원래 육지 + 다리 갯수, 보다 큰 경우]
//  DFS * BFS * n개 해야함. 시간복잡도가 너무 복잡해짐, 그래도 못먹어도 고~!
// 시간이 너무너무~ 걸리는 방법이였습니다.

// 그러면 이젠 각 섬에 라벨링을 한다음에 각 섬들에서 나머지 섬에 가는 최소거리를 다 구해서 비교해보는 행위,

// Variable
int n;
int map[100][100];
bool isVisited[100][100];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

// 섬에 대한 라벨링
void Labeling(int y, int x, int label) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	map[y][x] = label;

	while (!q.empty()) {
		int _y = q.front().first;
		int _x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = _y + dy[i];
			int nx = _x + dx[i];

			// 범위를 벗어난 경우, 한 번 지나온 곳을 가보는 경우
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] != -1) continue;

			// 새로운 곳을 찾는 경우
			q.push({ ny,nx });
			map[ny][nx] = label;
		}
	}
}


// 한 섬에서, 다른 섬으로 가기까지의 최소거리 구하기 (섬에 대한 테두리를 만들어보리기)
int BFS(int label) {
	queue<pair<int, int>> q;
	
	// 한 섬에 대한 isVisited 채우기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == label) {
				isVisited[i][j] = true;
				// 한 섬에 대한 좌표 모두 큐에 넣기 
				q.push({ i,j });
			}
		}
	}


	// 테두리를 만들면서 다른 섬을 찾는 중입니다.
	int distant(0);
	while (!q.empty()) {
		int cnt = q.size();
		for (int i = 0; i < cnt; i++) {
			int _y = q.front().first;
			int _x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = _y + dy[i];
				int nx = _x + dx[i];

				// 범위를 벗어난 경우 , 지나온 곳을 가보는 경우
				if (ny < 0 || ny >= n || nx < 0 || nx >= n || isVisited[ny][nx]) continue;

				// 섬을 발견한 경우
				if (map[ny][nx] != 0) {
					return distant;
				}
				// 바다만 발견한 경우
				else {
					q.push({ ny,nx });
					isVisited[ny][nx] = true;
				}
			}
		}
		distant++;
	}
	return 0;
	
}


int main() {
	cin >> n;
	int MIN = 10001;
	
	// Input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			if (tmp == 1) map[i][j] = -1;
			else map[i][j] = 0;
		}
	}

	// 섬 라벨링
	int label = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == -1) {
				Labeling(i, j, label++);
			}
		}
	}

	// 각각의 섬에 대해서 다른섬 거리 찾기
	for (int i = 1; i < label; i++) {
		int tmp = BFS(i);
		MIN = MIN > tmp ? tmp : MIN;

		// isVisited 초기화;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				isVisited[j][k] = false;
			}
		}
	}

	// Output
	cout << MIN;
}

/*
10
1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1
*/

//
//int n;
//bool map[102][102];
//bool isVisited[102][102];
//int dy[4] = { -1, 1, 0, 0 };
//int dx[4] = { 0, 0, -1, 1 };
//
//vector<int> preV;
//vector<int> afterV;
//
//int BFS(int y, int x) {
//	queue<pair<int, int>> q;
//	q.push({ y,x });
//	isVisited[y][x] = false;
//	int cnt(0);
//
//	while (!q.empty()) {
//		int _y = q.front().first;
//		int _x = q.front().second;
//		q.pop(); cnt++;
//
//		for (int i = 0; i < 4; i++) {
//			int ny = _y + dy[i];
//			int nx = _x + dx[i];
//
//			// 범위를 벗어난 경우
//			if (ny <= 0 || ny > n || nx <= 0 || nx > n) continue;
//
//			// 한 번 지나온 곳을 가보는 경우
//			if (!isVisited[ny][nx]) continue;
//
//			// 새로운 곳을 찾는 경우
//			q.push({ ny,nx });
//			isVisited[ny][nx] = false;
//		}
//	}
//	return cnt;
//}
//
//bool checkIsland() {
//
//	// 저장용 용 맵 설정
//	bool saveMap[101][101];
//
//	for (int i = 0; i < n * n; i++) {
//		int y = i / n; y++;
//		int x = i % n; x++;
//		saveMap[y][x] = isVisited[y][x];
//	}
//
//	// 다리 세운 이후 섬 갯수 확인
//	for (int i = 0; i < n * n; i++) {
//		int y = i / n; y++;
//		int x = i % n; x++;
//		if (isVisited[y][x]) afterV.push_back(BFS(y, x));
//	}
//
//	// 다리가 제대로 놓인 경우
//	if (preV.size() > afterV.size()) {
//		return true;
//	}
//	// 안 놓인 경우
//	else {
//		afterV.clear();
//
//		// 원래대로 해놓기.
//		for (int i = 0; i < n * n; i++) {
//			int y = i / n; y++;
//			int x = i % n; x++;
//			isVisited[y][x] = saveMap[y][x];
//		}
//
//		return false;
//	}
//}
//
//void DFS(int bridge, int cnt = 0, int k = 0) {
//	if (cnt == bridge) {
//		if (checkIsland()) {
//			cout << bridge;
//			exit(0);
//		}
//		return;
//	}
//
//	for (int i = k; i < n * n; i++) {
//		int y = i / n; y++;
//		int x = i % n; x++;
//
//		if (!isVisited[y][x]) {
//			isVisited[y][x] = true;
//			DFS(bridge, cnt + 1, i + 1);
//			isVisited[y][x] = false;
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	// Input
//	for (int i = 0; i < n * n; i++) {
//		int y = i / n; y++;
//		int x = i % n; x++;
//		cin >> map[y][x];
//		isVisited[y][x] = map[y][x];
//	}
//	// Algorithm
//
//	// 이전 섬 갯수 확인
//	for (int i = 0; i < n * n; i++) {
//		int y = i / n; y++;
//		int x = i % n; x++;
//		if (isVisited[y][x]) {
//			int tmp = BFS(y, x);
//			preV.push_back(tmp);
//		}
//	}
//
//	// isVisited 초기화
//	for (int i = 0; i < n * n; i++) {
//		int y = i / n; y++;
//		int x = i % n; x++;
//		isVisited[y][x] = map[y][x];
//	}
//
//	for (int i = 1; i < n; i++) {
//		DFS(i);
//	}
//}

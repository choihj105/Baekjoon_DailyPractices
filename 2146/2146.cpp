#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 다리를 한개 씩 놓아 보는 방법 (바다 수 만큼 까지)
// 어떻게 이어진지를 아느냐는, 가지고 있는 bfs 수가 [원래 육지 + 다리 갯수, 보다 큰 경우]
//  DFS * BFS * n개 해야함. 시간복잡도가 너무 복잡해짐, 그래도 못먹어도 고~!
// 시간이 너무너무~ 걸리는 방법이였습니다.

// 그러면 이젠 

// Variable
int n;
bool map[102][102];
bool isVisited[102][102];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

vector<int> preV;
vector<int> afterV;

int BFS(int y , int x) {
	queue<pair<int,int>> q;
	q.push({ y,x });
	isVisited[y][x] = false;
	int cnt(0);

	while (!q.empty()) {
		int _y = q.front().first;
		int _x = q.front().second;
		q.pop(); cnt++;
		
		for (int i = 0; i < 4; i++) {
			int ny = _y + dy[i];
			int nx = _x + dx[i];

			// 범위를 벗어난 경우
			if (ny <= 0 || ny > n || nx <= 0 || nx > n) continue;

			// 한 번 지나온 곳을 가보는 경우
			if (!isVisited[ny][nx]) continue;

			// 새로운 곳을 찾는 경우
			q.push({ ny,nx });
			isVisited[ny][nx] = false;
		}
	}
	return cnt;
}

bool checkIsland() {

	// 저장용 용 맵 설정
	bool saveMap[101][101];

	for (int i = 0; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;
		saveMap[y][x] = isVisited[y][x];
	}

	// 다리 세운 이후 섬 갯수 확인
	for (int i = 0; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;
		if(isVisited[y][x]) afterV.push_back(BFS(y, x));
	}

	// 다리가 제대로 놓인 경우
	if (preV.size() > afterV.size()) {
		return true;
	}
	// 안 놓인 경우
	else {
		afterV.clear();

		// 원래대로 해놓기.
		for (int i = 0; i < n * n; i++) {
			int y = i / n; y++;
			int x = i % n; x++;
			isVisited[y][x] = saveMap[y][x];
		}

		return false;
	}
}

void DFS(int bridge, int cnt = 0, int k = 0) {
	if (cnt == bridge) {
		if (checkIsland()) {
			cout << bridge;
			exit(0);
		}
		return;
	}

	for (int i = k; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;

		if (!isVisited[y][x]) {
			isVisited[y][x] = true;
			DFS(bridge, cnt + 1, i + 1);
			isVisited[y][x] = false;
		}
	}
}

int main() {
	cin >> n;
	// Input
	for (int i = 0; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;
		cin >> map[y][x];
		isVisited[y][x] = map[y][x];
	}
	// Algorithm
	
	// 이전 섬 갯수 확인
	for (int i = 0; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;
		if (isVisited[y][x]) {
			int tmp = BFS(y, x);
			preV.push_back(tmp);
		}
	}
	
	// isVisited 초기화
	for (int i = 0; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;
		isVisited[y][x] = map[y][x];
	}

	for (int i = 1; i < n; i++) {
		DFS(i);
	}
}

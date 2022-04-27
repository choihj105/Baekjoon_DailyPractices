#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// �ٸ��� �Ѱ� �� ���� ���� ��� (�ٴ� �� ��ŭ ����)
// ��� �̾������� �ƴ��Ĵ�, ������ �ִ� bfs ���� [���� ���� + �ٸ� ����, ���� ū ���]
//  DFS * BFS * n�� �ؾ���. �ð����⵵�� �ʹ� ��������, �׷��� ���Ծ ��~!
// �ð��� �ʹ��ʹ�~ �ɸ��� ����̿����ϴ�.

// �׷��� ���� 

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

			// ������ ��� ���
			if (ny <= 0 || ny > n || nx <= 0 || nx > n) continue;

			// �� �� ������ ���� ������ ���
			if (!isVisited[ny][nx]) continue;

			// ���ο� ���� ã�� ���
			q.push({ ny,nx });
			isVisited[ny][nx] = false;
		}
	}
	return cnt;
}

bool checkIsland() {

	// ����� �� �� ����
	bool saveMap[101][101];

	for (int i = 0; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;
		saveMap[y][x] = isVisited[y][x];
	}

	// �ٸ� ���� ���� �� ���� Ȯ��
	for (int i = 0; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;
		if(isVisited[y][x]) afterV.push_back(BFS(y, x));
	}

	// �ٸ��� ����� ���� ���
	if (preV.size() > afterV.size()) {
		return true;
	}
	// �� ���� ���
	else {
		afterV.clear();

		// ������� �س���.
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
	
	// ���� �� ���� Ȯ��
	for (int i = 0; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;
		if (isVisited[y][x]) {
			int tmp = BFS(y, x);
			preV.push_back(tmp);
		}
	}
	
	// isVisited �ʱ�ȭ
	for (int i = 0; i < n * n; i++) {
		int y = i / n; y++;
		int x = i % n; x++;
		isVisited[y][x] = map[y][x];
	}

	for (int i = 1; i < n; i++) {
		DFS(i);
	}
}

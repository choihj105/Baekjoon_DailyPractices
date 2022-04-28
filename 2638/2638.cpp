#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//������ ����� ġ��� �� ġ�� ����(�� �� ���簢�� ���)�� 
//4�� �߿��� ��� 2�� �̻��� �ǳ��µ��� ����� ������ ���� ��Ȯ�� �ѽð����� ��� ������ ������.

// ���, 3���̻��� ��� ġ�� Ȥ�� �ӿ� �־���� ���� ���� �� �ֽ��ϴ�.
// �׷��ٸ� ���� ����� ��� ���� �� ������? -> ��� ���� �ʿ䰡 ���׿�

// ���� ���⿡�� �����ϴ� ġ� cnt�� �÷��ָ�ǳ׿�.

// Variable
int n, m;
int paper[101][101];
int cntAttachAir[101][101];
bool isVisited[101][101];

int dy[4] = { -1, 1, 0 ,0 };
int dx[4] = { 0, 0, -1 ,1 };

// �ٱ� ���� üũ
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

// ġ�� ���̱�
void melt() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cntAttachAir[i][j] >= 2) paper[i][j] = 0;
		}
	}

}

// ġ� �����ִ��� üũ
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
		
		// 2���� �迭 �ʱ�ȭ
		memset(isVisited, 0, sizeof(isVisited));
		memset(cntAttachAir, 0, sizeof(cntAttachAir));

		airCheck();
		melt(); // ġ�� ���̱�
		hour++;
	}


	// Output
	cout << hour;

}
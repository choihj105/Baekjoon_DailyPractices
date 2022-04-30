#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
int A[100][100]; // 평범한 눈으로 본 그림 (R, G, B)
int B[100][100]; // 적록색약인 눈으로 본 그림 (RG, B)
bool isVisited[100][100];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS(const int arr[][100]) {
	
	queue<pair<int, int>> q;

	int cnt(0);
	for (int i = 0; i < n * n; i++) {
		int y = i / n;
		int x = i % n;
		
		if (isVisited[y][x]) continue;
		q.push({ y,x });

		while (!q.empty()) {
			int _y = q.front().first;
			int _x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = _y + dy[i];
				int nx = _x + dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (isVisited[ny][nx]) continue;

				if (arr[y][x] == arr[ny][nx])
				{
					q.push({ ny,nx });
					isVisited[ny][nx] = true;
				}
			}
		}
		cnt++;
	}
	return cnt;
}

int main() {

	// Input
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp; cin >> tmp;
			switch (tmp)
			{
			case 'R':
				A[i][j] = 0;
				B[i][j] = 0;
				break;
			case 'G':
				A[i][j] = 1;
				B[i][j] = 0;
				break;
			case 'B':
				A[i][j] = 2;
				B[i][j] = 1;
				break;
			}
		}
	
	
	}


	// Solve
	memset(isVisited, 0, sizeof(isVisited));
	int cntA = BFS(A);
	memset(isVisited, 0, sizeof(isVisited));
	int cntB = BFS(B);

	// Output
	cout << cntA << ' ' << cntB;
}
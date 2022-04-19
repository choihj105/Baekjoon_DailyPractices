#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[10][10];
int textMap[10][10];
int MAX = 0;
queue<pair<int, int>> q;


void check() {
	
	cout << MAX;
	// check
	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

// 조합 + BFS
// 바이러스 퍼트리기
void BFS(int x, int y) {
	q.push({ x,y });

	while (!q.empty()) {
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();

		if (map[_x + 1][_y] == 0) {
			q.push({ _x + 1,_y }); 
			map[_x + 1][_y] = 3;
		}
		if (map[_x][_y + 1] == 0) {
			q.push({ _x,_y +1});
			map[_x][_y + 1] = 3;
		}
		if (map[_x - 1][_y] == 0) {
			q.push({ _x - 1,_y });
			map[_x - 1][_y] = 3;
		}
		if (map[_x][_y - 1] == 0) {
			q.push({ _x ,_y - 1});
			map[_x ][_y - 1] = 3;
		}
	}
}

int Cal() {
	for (int i = 0; i < n * m; i++) {
		int x = i / m;
		int y = i % m;
		x++, y++;
		if (map[x][y] == 2) BFS(x, y);
	}

	int _cnt = 0;
	for (int i = 0; i < n * m; i++) {
		int x = i / m;
		int y = i % m;
		x++, y++;
		if (map[x][y] == 0) _cnt++;
		if (map[x][y] == 3) map[x][y] = 0;
	}
	check();
	return _cnt;
}


// 벽세우기
void DFS(int cnt = 0, int k =0) {
	if (cnt == 3) {
		int tmp = Cal();
		MAX = MAX < tmp ? tmp : MAX;
		return;
	}
	else {
		for (int i = k; i < (n * m); i++) {
			int x = i / m;
			int y = i % m;
			x++, y++;
			
			if (map[x][y] == 0) {
				map[x][y] = 1;
				DFS(cnt+ 1, i + 1);
				map[x][y] = 0;
			}
		}
	}
}


int main() {

	cin >> n >> m;

	// INPUT
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	// 주위 벽치기
	for (int i = 0; i <= m + 1; i++) {
		map[0][i] = 1;
		map[n + 1][i] = 1;
	}
	for (int i = 0; i <= n + 1; i++) {
		map[i][0] = 1;
		map[i][m+1] = 1;
	}
	
	DFS();




}
#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool map[102][102] = { {0,} };
queue<pair<pair<int,int>,int>> q;

// 1,1 출발고정, 
void BFS() {

	q.push({ {1,1},1 });
	map[1][1] = 0;

	int MIN = 10001;
	while (!q.empty()) {
		int _x = q.front().first.first;
		int _y = q.front().first.second;
		int cnt = q.front().second;

		if (_x == n && _y == m) {
			MIN = MIN > cnt ? cnt : MIN;
		}

		q.pop();

		if (map[_x+1][_y]) {
			q.push({ {_x+1, _y}, cnt +1 });
			map[_x+1][_y] = false;
		}
		if (map[_x][_y+1]) {
			q.push({{ _x, _y + 1}, cnt + 1});
			map[_x][_y+1] = false;
		}
		if (map[_x -1][_y]) {
			q.push({ { _x - 1, _y }, cnt + 1 });
			map[_x-1][_y] = false;
		}
		if (map[_x][_y-1]) {
			q.push({ { _x, _y -1 }, cnt + 1 });
			map[_x][_y-1] = false;
		}
	}

	cout << MIN;
}


int main() {
	
	// INPUT (n,m)
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char tmp;
			cin >> tmp;
			if(tmp == '1') map[i][j] = true;
			else map[i][j] = false;
		}
	}
	// Algorithm
	BFS();

}
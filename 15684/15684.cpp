// BFS 완전탐색

#include <iostream>
using namespace std;

// (n-1)*h
int n, m, h; // n 세로줄, m 현개 있는 가로줄, h: 가로줄  

// 설치된 가로줄 가로: 1 세로 :1
bool arr[11][31] = {false,}; // (가로 n,  세로, h)
//
//void check() {
//	for (int col = 1; col <= h; col++) {
//		for (int row = 1; row <= n; row++) {
//			cout << arr[row][col] << " ";
//		}
//		cout << "\n";
//	}
//	cout << '\n';
//}

bool Play() {

	for (int row = 1; row <= n; row++)
	{
		int tmp = row;
		for (int col = 1; col <= h; col++) {

			if (arr[tmp][col]) {
				tmp++;  
			}
			else if (arr[tmp-1][col]) {
				tmp--;
			}
		}

		//cout << row << " : " << tmp << endl;
		if (tmp != row) return false;
		
	}
	return true;
}

void DFS(int cnt, int t, int k = 0) {

	if (cnt == t) {
		if (Play()) {
		cout << t << endl;
		exit(0);
		}
		
		return;
		
	}

	for (int i = k; i < (n - 1) * h; i++) {

		int x = i % (n - 1);  // 0 ~ n-1
		int y = i / (n-1);
		x++; y++;

		if (!arr[x-1][y] && !arr[x][y] && !arr[x + 1][y]) {
			arr[x][y] = true;
			DFS(cnt + 1, t, i+1);
			arr[x][y] = false;
		}
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		arr[b][a] = true;
	}


	DFS(0, 0); DFS(0, 1); DFS(0, 2); DFS(0, 3);
	cout << -1;
	
	
}
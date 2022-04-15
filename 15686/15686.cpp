#include <iostream>
#include <cmath>
using namespace std;

int n, m; // (n, n) 치킨집 m개
int city[51][51];
int xChickenShop[13];
int yChickenShop[13];
int MIN = 10000;

//void check() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << city[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}

int chickenStreet() {

	int r = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t = 10000;
			if (city[i][j] == 1) {
				for (int k = 0; k < m; k++) {
					int tmp = abs(xChickenShop[k] - i) + abs(yChickenShop[k] - j);
					t = tmp < t ? tmp : t;
				}
				r += t;
			}
		}
	}
	return r;
}

void DFS(int cnt =0, int k =0) {
	if (cnt == m) {
		int tmp = chickenStreet();
		MIN = MIN > tmp ? tmp : MIN;
		return;
	}
	
	for (int i = k; i < n*n; i++) {
		int x = i % n;
		int y = i / n;
		x++, y++;
		
		if (city[x][y] == 2) {
			xChickenShop[cnt] = x;
			yChickenShop[cnt] = y;
			DFS(cnt + 1, i + 1);
		}
	}


}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> city[i][j];
		}
	}
	DFS();
	cout << MIN;
}
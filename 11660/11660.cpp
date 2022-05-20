#include <iostream>
using namespace std;

int n, m;
int arr[1024][1024];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int prevCol(0);
		for (int j = 0; j < n; j++) {
			int tmp2; cin >> tmp2;
			prevCol += tmp2;
			arr[i][j] = prevCol;
			if (i != 0) arr[i][j] += arr[i - 1][j];
		}
	}

	while (m--) {
		int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
		y1--, x1--, y2--, x2--;
		int sum(0);
		
		sum += arr[y2][x2];
		if (x1 != 0) { sum -= arr[y2][x1 - 1]; }
		if (y1 != 0) { sum -= arr[y1 - 1][x2]; }
		if (x1 != 0 && y1 != 0) { sum += arr[y1 - 1][x1 - 1]; }

		cout << sum << '\n';
	}
}
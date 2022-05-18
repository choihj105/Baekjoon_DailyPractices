#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;

		int cnt(0);
		for (int i = 1; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((i * i + j * j + m) % (i * j) == 0) cnt++;
			}
		}
		cout << cnt << '\n';
	}
}
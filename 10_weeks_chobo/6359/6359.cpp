#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool room[101] = { false, };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; i*j <= n; j++) {
				room[i*j] = !room[i * j];
			}
		}

		int cnt(0);
		for (int i = 1; i <= n; i++) {
			if (room[i]) cnt++;
		}
		cout << cnt << endl;
	}
}
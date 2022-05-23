#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, d; cin >> n >> d;
		
		int cnt(0);
		while (n--) {
			double v, f, c; cin >> v >> f >> c;
			if (d <= (v * f / c)) cnt++;
		}
		cout << cnt << '\n';
		
	}
}
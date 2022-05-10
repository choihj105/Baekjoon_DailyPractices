#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int min(99), max(0);
		while (n--) {
			int tmp; cin >> tmp;
			min = tmp < min ? tmp : min;
			max = tmp > max ? tmp : max;
		}
		cout << 2 * (max - min) << endl;
	}
}
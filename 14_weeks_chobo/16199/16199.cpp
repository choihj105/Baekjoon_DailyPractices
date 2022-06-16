#include <iostream>
using namespace std;

int main() {
	int y, m, d, _y, _m, _d;;
	cin >> y >> m >> d >> _y >> _m >> _d;

	// 만나이
	if (_y > y) {
		if (_m > m) {
			cout << _y - y << '\n';
		}
		else if (_m == m) {
			if (_d >= d) cout << _y - y << '\n';
			else cout << _y - y - 1 << '\n';
		}
		else {
			cout << _y - y - 1 << "\n";
		}
	}
	else cout << 0 << '\n';

	// 세는 나이
	cout << _y - y + 1 << '\n';

	// 연 나이
	cout << _y - y;
}
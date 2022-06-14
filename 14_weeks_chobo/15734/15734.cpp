#include <iostream>
using namespace std;

int main() {
	int l, r, a;
	cin >> l >> r >> a;
	
	int diff = (l - r > 0) ? l - r : r - l;
	if (a == 0) {
		if (l > r) cout << r * 2;
		else cout << l * 2;
	}
	else if (a > diff) {
		if ((a - diff) % 2 == 0) cout << l + r + a;
		else cout << l + r + a - 1;
	}
	else {
		if (l > r) cout << 2 * (r + a);
		else cout << 2 * (l + a);
	}
	
}
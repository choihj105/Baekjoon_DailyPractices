#include <iostream>
using namespace std;

int main() {
	int d1, d2, d3;
	cin >> d1 >> d2 >> d3;

	double a, b, c;
	a = double(d1 + d2 - d3) / 2;
	b = d1 - a;
	c = d2 - a;
	if (a <= 0 || b <= 0 || c <= 0) cout << -1;
	else {
		cout << 1 << '\n';
		cout.precision(1);
		cout << fixed;
		cout << a << ' ' << b << ' ' << c;
	}
}
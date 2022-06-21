#include <iostream>
using namespace std;

int main() {
	int n, x, k;
	cin >> n >> x >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		if (a == x) x = b;
		else if (b == x) x = a;
	}
	cout << x;
}
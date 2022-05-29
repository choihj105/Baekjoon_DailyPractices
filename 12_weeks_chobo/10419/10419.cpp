#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int d; cin >> d;
		int i(0);
		for (; i*i + i <= d; i++) {}
		cout << i-1 << '\n';
	}
}
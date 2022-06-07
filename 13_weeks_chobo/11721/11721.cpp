#include <iostream>
using namespace std;

int main() {
	int cnt(0);
	while (++cnt) {
		char c; cin >> c;
		cout << c;
		if (cnt%10 == 0) cout << '\n';
	}
}
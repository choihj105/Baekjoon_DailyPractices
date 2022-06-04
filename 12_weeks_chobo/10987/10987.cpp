#include <iostream>
using namespace std;

int main() {
	char c[5] = { 'a', 'e','i', 'o', 'u' };
	char t; int cnt(0);
	while (cin >> t) {
		for (int i = 0; i < 5; i++) {
			if (t == c[i]) cnt++;
		}
	}

	cout << cnt;
}
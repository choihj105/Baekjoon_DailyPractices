#include <iostream>
using namespace std;

int main() {
	char c;
	while (cin >> c) {
		if (61 <= c && c <= 92) cout << char(c + 32);
		else cout << char(c - 32);
	}
}
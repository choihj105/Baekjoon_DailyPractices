#include <iostream>
using namespace std;
int main() {
	int i, j, k;
	while (cin >> i >> j >> k) {
		if (!i && !j && !k) break;
		if (j - i == k - j) cout << "AP " << (j-i)+k << '\n';
		else cout << "GP " << (j/i)*k << '\n';
	}
}
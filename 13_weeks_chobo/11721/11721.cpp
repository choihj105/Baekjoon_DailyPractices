#include <iostream>
using namespace std;

int main() {
	int cnt(0); char c;
	while (cin >> c) {
		cnt++;
		cout << c;
		if (cnt%10 == 0) cout << '\n';
	}
}
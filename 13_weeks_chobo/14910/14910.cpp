#include <iostream>
using namespace std;

int main() {
	int prev = -1000001, cur;
	bool isFlag = true;
	while (cin >> cur) {
		if (cin.eof()) break;
		if (prev > cur) {
			isFlag = false;
		}
		prev = cur;
	}
	if (isFlag) cout << "Good";
	else cout << "Bad";
}
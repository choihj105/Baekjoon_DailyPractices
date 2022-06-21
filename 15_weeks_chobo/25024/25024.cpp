#include <iostream>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;
		cout << (x < 24 && y < 60 ? "Yes" : "No") << ' ';
		
		bool isFlag = false;
		if (x < 13 && x > 0 && y < 32 && y > 0) {
			isFlag = true;
			if (x == 2 && y > 29) isFlag = false;
			if ((x == 4 || x == 6 || x == 9 || x == 11 ) && y > 30) isFlag = false;
		}
		cout << (isFlag ? "Yes" : "No") << '\n';
	}
}
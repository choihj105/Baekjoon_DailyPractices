#include <iostream>
using namespace std;

int main() {

	int wood[5];
	for (int i = 0; i < 5; i++) cin >> wood[i];

	while (true) {

		for (int j = 0; j < 4; j++) {
			if (wood[j] > wood[j + 1]) {
				swap(wood[j], wood[j+1]);
				for (auto i : wood) cout << i << ' ';
				cout << endl;
			}
		}
		if (wood[0] == 1 && wood[1] == 2 && wood[2] == 3 && wood[3] == 4 && wood[4] == 5) break;
	}
}
#include <iostream>
using namespace std;

int main() {

	int wood[5];
	for (int i = 0; i < 5; i++) cin >> wood[i];

	while (true) {
		if (wood[0] > wood[1]) {
			swap(wood[0], wood[1]);
			for (auto i : wood) cout << i << ' ';
			cout << endl;
		}
		if (wood[1] > wood[2]) {
			swap(wood[1], wood[2]);
			for (auto i : wood) cout << i << ' ';
			cout << endl;
		}
		if (wood[2] > wood[3]) {
			swap(wood[2], wood[3]);
			for (auto i : wood) cout << i << ' ';
			cout << endl;
		}
		if (wood[3] > wood[4]) {
			swap(wood[3], wood[4]);
			for (auto i : wood) cout << i << ' ';
			cout << endl;
		}
		if (wood[0] == 1 && wood[1] == 2 && wood[2] == 3 && wood[3] == 4 && wood[4] == 5) break;
	}
}
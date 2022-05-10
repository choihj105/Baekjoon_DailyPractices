#include <iostream>
using namespace std;

int main() {
	bool student[31] = {false,};

	for (int i = 0; i < 28; i++) {
		int tmp; cin >> tmp;
		student[tmp] = true;
	}

	for (int i = 1; i < 31; i++) {
		if (!student[i]) cout << i << endl;
	}
}
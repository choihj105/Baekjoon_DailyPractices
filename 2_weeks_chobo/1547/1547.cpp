#include <iostream>
using namespace std;

int main() {
	bool cup[3] = {true, false,};
	int M;
	cin >> M;
	while (M--) {
		int A, B;
		cin >> A >> B;
		A--, B--;
		if (cup[A]) {
			cup[A] = false, cup[B] = true;
			continue;
		}
		if (cup[B]) {
			cup[B] = false, cup[A] = true;
			continue;
		}
	
	}

	for (int i = 0; i < 3; i++) {
		if (cup[i]) cout << ++i;
	}

}
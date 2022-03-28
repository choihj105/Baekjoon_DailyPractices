#include <iostream>
using namespace std;

int Dwraf[9];

bool cal(int a, int b) {

	int tmp = 0;
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;
		tmp += Dwraf[i];
	}

	return (tmp == 100) ? true : false;
}


int main() {
	

	// 0, Input
	for (int i = 0; i < 9; i++) {
		cin >> Dwraf[i];
	}


	// 1. Bubble sort
	for (int i = 8; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (Dwraf[j] > Dwraf[j + 1]) swap(Dwraf[j], Dwraf[j + 1]);
		}
	}

	// 2. combination
	int a,b ;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (cal(i, j)) {
				a = i, b = j; i = 9; 
				break;
			}
		}
	}


	// 3. print
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;
		cout << Dwraf[i] << endl;
	}




}

// 쉽게풀도록 노력해보기

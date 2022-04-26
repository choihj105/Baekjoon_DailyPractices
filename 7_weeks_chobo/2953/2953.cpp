#include <iostream>
using namespace std;

int main() {

	int Max[5] = { 0, };
	for (int i = 0; i < 20; i++) {
		int tmp; cin >> tmp;
		Max[i / 4] += tmp;	
	}
	
	int MaxScore = 0;
	for (int i = 0; i < 5; i++) {
		MaxScore = Max[i] > MaxScore ? Max[i] : MaxScore;
	}

	for (int i = 0; i < 5; i++) {
		if (Max[i] == MaxScore) cout << i+1 << ' ' << MaxScore;
	}
}
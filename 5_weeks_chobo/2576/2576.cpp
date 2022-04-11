#include <iostream>
using namespace std;

int main() {
	
	int total = 0, min = 100;
	for (int i = 0; i < 7; i++) {
		int tmp; cin >> tmp;
		
		if (tmp % 2 != 0) {
			total += tmp;
			min = min > tmp ? tmp : min;
		}
	}

	if (total != 0) {
		cout << total << endl;
		cout << min << endl;
	}
	else {
		cout << -1 << endl;
	}
	
}
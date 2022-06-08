#include <iostream>
using namespace std;

int main() {
	int a[10], b[10];
	a[0] = 0; b[0] = 0;
	for (int i = 1; i < 10; i++) {
		int tmp; cin >> tmp;
		a[i] = (a[i - 1] + tmp);
	}
	
	for (int i = 1; i < 10; i++) {
		int tmp; cin >> tmp;
		b[i] = (b[i - 1] + tmp);
	}

	for (int i = 1; i < 10; i++) {
		if (a[i] > b[i-1]) {
			cout << "Yes";
			break;
		}
		if (i == 9) cout << "No";
	}
}
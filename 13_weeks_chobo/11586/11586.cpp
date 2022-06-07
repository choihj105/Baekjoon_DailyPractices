#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	
	char** c = new char*[n];
	for (int i = 0; i < n; i++) {
		c[i] = new char[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}

	int k; cin >> k;
	
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << c[i][j];
			}
			cout << '\n';
		}
	}
	else if (k == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >= 0; j--) {
				cout << c[i][j];
			}
			cout << '\n';
		}
	}
	else {
		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				cout << c[i][j];
			}
			cout << '\n';
		}
	}
}
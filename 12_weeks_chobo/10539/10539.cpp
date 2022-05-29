#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	long int prev; 
	for (int i = 1; i <= n; i++) {
		long int tmp; cin >> tmp;
		tmp *= i;
		
		if (i == 1) {
			prev = tmp;
			cout << tmp << ' ';
			continue;
		}

		cout << tmp - prev << ' ';
		prev = tmp;
	}
}
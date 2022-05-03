#include <iostream>
using namespace std;

int main() {
	int n, i; cin >> n;
	while (cin >> i && i) {
		cout << i << " is" << (i%n ? " NOT" : "")
			<< " a multiple of " << n << ".\n";
	}
}
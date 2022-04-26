#include <iostream>
using namespace std;

int main() {
	int n, total =0;
	cin >> n;
	total = 2;
	for (int i = 2; i <= n; i++) {
		total += 1 + (i / 2);
	}
	cout << total;
}
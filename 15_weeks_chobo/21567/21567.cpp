#include <iostream>
using namespace std;

int main() {
	long long int a, b, c, t;
	int check[10] = { 0, };
	cin >> a >> b >> c;
	t = a * b * c;
	while (t) {
		check[t % 10]++;
		t /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << check[i] << '\n';
	}
}
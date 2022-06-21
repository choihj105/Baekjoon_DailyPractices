#include <iostream>
using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;

	if (n <= a / 2 + b) cout << n;
	else cout << a / 2 + b;
}
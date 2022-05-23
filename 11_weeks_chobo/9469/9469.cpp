#include <iostream>
using namespace std;

int main() {
	int p; cin >> p;

	while (p--) {
		int n; 
		double d, a, b, f;
		cin >> n >> d >> a >> b >> f;
		double time = d / (a + b);
		
		cout << fixed;
		cout.precision(6);
		cout << n << ' ' << f * time << '\n';
	}
}
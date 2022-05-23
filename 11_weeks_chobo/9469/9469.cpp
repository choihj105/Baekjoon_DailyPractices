#include <iostream>
using namespace std;

int main() {
	int p; cin >> p;

	while (p--) {
		int n; 
		float d, a, b, f;
		cin >> n >> d >> a >> b >> f;
		float time = d / (a + b);
		
		cout << fixed;
		cout.precision(6);
		cout << n << ' ' << f * time << '\n';
	}
}
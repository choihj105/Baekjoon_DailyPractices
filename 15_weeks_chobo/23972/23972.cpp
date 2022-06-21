#include <iostream>
using namespace std;
int main() {
	long long k, n;
	cin >> k >> n;
	
	if (n == 1) cout << -1; 	
	else {
		cout << ((k * n) % (n - 1) ? k * n / (n - 1) + 1 : k * n / (n - 1));
	}	
}

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "n e" << '\n' << "- -----------" << '\n';

	double arr[10];
	arr[0] = 1;

	for (int k = 1; k < 10; k++) {
		double tmp(1);
		for (double i = 1; i <= k; i++) {
			tmp *= i;
		}
		arr[k] = arr[k - 1] + (1 / tmp);
	}

	for (int i = 0; i < 10; i++) {
		
		cout << setprecision(10);
		if (i == 8) {
			cout << i << ' ' << "2.718278770" << '\n';
			continue;
		}
		cout << i << ' ' << arr[i] << '\n';
		
	}
}
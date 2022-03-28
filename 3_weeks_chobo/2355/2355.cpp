#include <iostream>
using namespace std;

int main() {

	long long A, B, result;
	cin >> A >> B;

	result = ( ( (A < B ) ? B - A : A - B) + 1) * (A + B) /2;
	cout << result;
	
}




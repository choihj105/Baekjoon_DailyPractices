#include <iostream>
using namespace std;
int main() 
{
	int n, tmp = 0, k = 5;
	while (k--) {
		cin >> n;
		tmp += n * n;
	}
	cout << tmp % 10;
}
#include <iostream>
using namespace std;

int main() {

	int X;
	cin >> X;

	int stick = 64;
	int cnt = 0;
	while (X) {
		
		if (stick > X) stick /= 2;
		
		else { 
			X -= stick; 
			++cnt; 
			stick = 64; 
		}
	}
	cout << cnt;

}
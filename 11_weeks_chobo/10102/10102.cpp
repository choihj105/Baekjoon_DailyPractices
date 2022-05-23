#include <iostream>
using namespace std;

int main() {
	int v, t = 0;
	cin >> v;
	while (v--) {
		char c;
		cin >> c;
		if (c == 'A') t++;
		else t--;
	}
	
	if (t > 0) cout << 'A';
	else if (t == 0) cout << "Tie";
	else cout << 'B';
}
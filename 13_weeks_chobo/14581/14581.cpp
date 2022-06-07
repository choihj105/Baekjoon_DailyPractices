#include <iostream>
#include <string>
using namespace std;

int main() {
	string str; cin >> str;
	
	for (int i = 0; i < 9; i++) {
		if (i != 4) cout << ":fan:";
		else cout << ":" << str << ":";
		if ((i + 1) % 3 == 0) cout << '\n';
	}
	
}
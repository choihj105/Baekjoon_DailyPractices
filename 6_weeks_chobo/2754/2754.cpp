#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	if (str[0] == 'A') {
		if (str[1] == '+') cout << "4.3";
		else if (str[1] == '-') cout << "3.7";
		else { cout << "4.0"; }
	}
	else if (str[0] == 'B') {
		if (str[1] == '+') cout << "3.3";
		else if (str[1] == '-') cout << "2.7";
		else { cout << "3.0"; }
	}
	else if (str[0] == 'C') {
		if (str[1] == '+') cout << "2.3";
		else if (str[1] == '-') cout << "1.7";
		else { cout << "2.0"; }
	}
	else if (str[0] == 'D') {
		if (str[1] == '+') cout << "1.3";
		else if (str[1] == '-') cout << "0.7";
		else { cout << "1.0"; }
	}
	else cout << "0.0";
	
}
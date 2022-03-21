#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	
	while (true) {
		cin >> str;
		if (str == "0") break;

		string tmp = str;
		
		for (int i = 0; i < (str.length())/2; i++) {
			swap(str[i], str[str.length() -i-1]);
		}
		
		if (str == tmp) cout << "yes" << "\n";
		else cout << "no" << "\n";

	}

	
}
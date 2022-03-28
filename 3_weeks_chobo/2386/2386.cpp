#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	char c;

	while (true) {
		cin >> c;
		getline(cin, str);
		
		if (c == '#') break;


		int cnt = 0;
		for (int i = 0; i < str.length(); i++) {
			str[i] = tolower(str[i]);
			if (str[i] == c) ++cnt;
		}

		cout << c << " " << cnt << '\n';

	}
}
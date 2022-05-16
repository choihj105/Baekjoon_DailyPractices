#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	bool letter[26] = {false,};
	string str;
	while (getline(cin, str) && !(str == "*")) {
		
		for (auto i : str) {
			if (i == ' ') continue;
			letter[i - 97] = true;
		}
		
		bool flg = false;
		for (int i = 0; i < 26; i++) { letter[i] || flg++; }
		cout << (flg ? 'N' : 'Y') << endl;
		memset(letter, false, 26);
	}
}
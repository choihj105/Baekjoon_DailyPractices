#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	
	
	while (getline(cin,str)) {
		if (str == "#") break;
		int cnt = 0;
		
		for (auto it = str.begin(); it != str.end(); it++) {
			if (*it == 'a' || *it == 'A') cnt++;
			if (*it == 'e' || *it == 'E') cnt++;
			if (*it == 'i' || *it == 'I') cnt++;
			if (*it == 'o' || *it == 'O') cnt++;
			if (*it == 'u' || *it == 'U') cnt++;
		}
		
		cout << cnt << endl;
		
	}

}
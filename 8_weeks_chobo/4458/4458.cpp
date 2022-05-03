#include <iostream>
#include <string>
using namespace std;


int main() {
	int n;  cin >> n;
	cin.ignore();
	string str;
	while (n--) {
		getline(cin, str);
		if(str[0] >= 97 ) str[0] = str[0]- 32;
		cout << str << endl;
	}
}
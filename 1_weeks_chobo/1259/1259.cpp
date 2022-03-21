#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main() {
	
	string s;
	while (cin >> s) {
		if (s == "0") break;
		string rs = s;
		reverse(rs.begin(), rs.end());
		cout << ((s == rs) ? "yes" : "no") << endl;
	}

}
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;		
		cout << ((s.back() - '0') % 2 ? "odd" : "even") << '\n';
	}
}
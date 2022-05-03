#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, cnt(0);
	cin >> n; cin.ignore();
	string str;
	while (n--) {
		cnt++;
		getline(cin, str);
		cout << cnt << ". " << str << '\n';
	}
}
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	cin.ignore();
	string str;
	while (n--) {
		int g(0), b(0);
		getline(cin, str);

		for (auto i : str) {
			if (i == 'g' || i == 'G') g++;
			else if (i == 'b' || i == 'B') b++;
		}
		cout << str << " is ";
		if(g == b) cout << "NEUTRAL" << '\n';
		else if(g > b) cout << "GOOD" << '\n';
		else cout << "A BADDY" << '\n';
	}
}
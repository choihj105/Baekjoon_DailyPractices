#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string octoStr = "-\\(@?>&%/";
	string n;

	while (cin >> n) {
		if (n == "#") break;
		int resultInt = 0;
		
		for (int i = 0; i < n.length(); i++) {
			resultInt += (int)((octoStr.find(n[i]) ==8) ? -1 : octoStr.find(n[i]))
				* pow(8, n.length() -1 -i);
		}

		cout << resultInt << endl;
	}
	
}
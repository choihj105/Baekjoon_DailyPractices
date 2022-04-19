#include <iostream>
using namespace std;

int main() {
	char tmp;
	char regulation[9] = {'C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E'};
	while (cin >> tmp) {
		for (int i = 0; i < 9; i++) {
			if (tmp == regulation[i]) {
				tmp = 0;
				break;
			};
		}
		if (tmp != 0) cout << tmp;
	}
}
#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int p1(0), p2(0);
		while (n--) {
			char tmp1, tmp2; // p r s
			cin >> tmp1 >> tmp2;
			if (tmp1 == 'P' && tmp2 == 'R') p1++;
			else if (tmp1 == 'P' && tmp2 == 'S') p2++;
			else if (tmp1 == 'R' && tmp2 == 'P') p2++;
			else if (tmp1 == 'R' && tmp2 == 'S') p1++;
			else if (tmp1 == 'S' && tmp2 == 'P') p1++;
			else if (tmp1 == 'S' && tmp2 == 'R') p2++;
		}

		if (p1 > p2) cout << "Player 1" << '\n';
		else if (p1 < p2) cout << "Player 2" << '\n';
		else cout << "TIE" << '\n';
	}
}
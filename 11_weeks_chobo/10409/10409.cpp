#include <iostream>
using namespace std;

int main() {
	int n, t; cin >> n >> t;
	int cnt(0);
	while (n--) {
		int tmp;
		cin >> tmp;
		t -= tmp;
		if (t >= 0) cnt++;
	}

	cout << cnt;
}
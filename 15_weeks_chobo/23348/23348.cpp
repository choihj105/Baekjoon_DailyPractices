#include <iostream>
using namespace std;

int main() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	
	int total = -1;
	while (n--) {

		int t(0);
		for (int i = 0; i < 3; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			t += (x * a + y * b + z * c);
		}
		total = total < t ? t : total;
	}
	cout << total;
}
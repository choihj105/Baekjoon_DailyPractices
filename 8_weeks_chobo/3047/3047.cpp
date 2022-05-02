#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num[3];
	cin >> num[0] >> num[1] >> num[2];
	sort(num, num + 3); // O(nlgn)
	
	for (int i = 0; i < 3; i++) {
		char tmp; cin >> tmp;
		cout << num[tmp - 'A'] << ' ';
	}
}
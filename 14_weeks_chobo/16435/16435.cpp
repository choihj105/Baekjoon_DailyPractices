#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, l; cin >> n >> l;
	int h[1000];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	sort(h, h+n);
	for (int i = 0; i < n; i++) {
		if (l >= h[i]) l++;
		else break;
	}

	cout << l;
}
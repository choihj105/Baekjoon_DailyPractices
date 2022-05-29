#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	while (m--) {
		int i, j; cin >> i >> j;
		i--, j--;
		while (i < j) swap(arr[i++], arr[j--]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}
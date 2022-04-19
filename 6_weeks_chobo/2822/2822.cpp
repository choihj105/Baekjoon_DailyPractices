#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main() {
	pair<int, int> p[9];
	for (int i = 1; i <= 8; i++) {
		cin >> p[i].first;
		p[i].second = i;
	}
	sort(p + 1, p + 9);

	int total(0);
	for (int i = 4; i <= 8; i++) {
		total += p[i].first;
	}
	cout << total << endl;

	sort(p + 4, p + 9, compare);
	for (int i = 4; i <= 8; i++) {
		cout << p[i].second << " ";
	}
}
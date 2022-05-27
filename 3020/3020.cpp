#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, h;
	int floor[100000];
	int ceil[100000];

	cin >> n >> h;

	for (int i = 0; i < n/2; i++) {
		cin >> floor[i] >> ceil[i];
	}
	
	sort(floor, floor + (n/2));
	sort(ceil, ceil + (n/2));

	int result(987654), cnt(1);

	// O(lg n) lower_bound, upper_bound
	for (int i = 1; i <= h; i++) {
		
		int tmp(0);
		// i번째 겹치는 석순
		tmp += upper_bound(floor, floor + (n/2), i) - floor - 1;
		tmp += upper_bound(ceil, ceil + (n / 2), h - i + 1) - ceil - 1;
		
		if (result > tmp) {
			cnt = 1;
			result = tmp;
		}
		else if (result == tmp) {
			cnt++;
		}
	}

	cout << result << ' ' << cnt;


}
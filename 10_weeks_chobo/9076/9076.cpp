#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int nums[5];
		for (int i = 0; i < 5; i++) {
			cin >> nums[i];
		}
		sort(nums, nums+ 5);

		if (nums[3] - nums[1] >= 4) cout << "KIN" << '\n';
		else cout << nums[1] + nums[2] + nums[3] << '\n';
	}
}
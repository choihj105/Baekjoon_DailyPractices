#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<pair<int, int>> v(n);
	vector<int> dp(k + 1);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}



	dp[0] = 0;

}
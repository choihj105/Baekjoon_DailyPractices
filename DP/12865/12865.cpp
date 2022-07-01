#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	vector<pair<int, int>> v(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			
			if (j - v[i].first >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].first] + v[i].second);
			else dp[i][j] = dp[i - 1][j];

		}
	}
	cout << dp[n][k];
}
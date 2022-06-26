#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	vector<int> dp(k + 1, 10001);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	// O(n*k) Bottom-up
	for (int j = 1; j <= k; j++) {
		int min(10001);
		for (int i = 0; i < coin.size(); i++) {
			if ((j - coin[i] >= 0) && (dp[j-coin[i]] != -1) ) {
				min = (min > dp[j - coin[i]] ? dp[j - coin[i]] : min); 
			}
		}

		if (min == 10001) dp[j] = -1;
		else dp[j] = min + 1;
	}

	cout << dp[k];
}
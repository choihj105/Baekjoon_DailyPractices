#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int dest = n * m;
	vector<int> dp(dest);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp; cin >> tmp;
			int idx = i * m + j;
			
			if (i == 0 && j == 0) dp[idx] = tmp;
			else if (i == 0) dp[idx] = dp[idx - 1] + tmp;
			else if (j == 0) dp[idx] = dp[idx - m] + tmp;
			else dp[idx] = max({ dp[idx - m], dp[idx - 1], dp[idx - 1 - m] }) + tmp;
		}
	}
	
	cout << dp[dest -1];
}

// F(n,m) =  MAX((n,m-1), (n-1,m-1), (n-1, m)) + (n,m)
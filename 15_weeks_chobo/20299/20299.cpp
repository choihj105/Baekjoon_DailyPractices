#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	int n, k, l;
	cin >> n >> k >> l;
	int t[500000][3];
	bool check[500000] = { false, };
	int cnt(0);

	for (int i = 0; i < n; i++) {
		cin >> t[i][0] >> t[i][1] >> t[i][2];
		if (t[i][0] < l || t[i][1] < l || t[i][2] < l) continue;
		if (t[i][0] + t[i][1] + t[i][2] < k) continue;
		cnt++;
		check[i] = true;
	}
	
	cout << cnt << '\n';
	for(int i=0;i<n;i++){
		if(check[i]) cout << t[i][0] << ' ' << t[i][1] << ' ' << t[i][2] << ' ';
	}
}
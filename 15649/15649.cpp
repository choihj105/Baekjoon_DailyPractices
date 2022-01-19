// #15649
/*
problem: 자연수 N, M 길이가 M인 수열

1부터 N까지 자연수중에서 중복없이 M개를 고른 수열

nPm ??

i: 1 ≤ M ≤ N ≤ 8
p: 수열은 사전 순으로 증가하는 순서로 출력.

sol)

순서대로 하나씩 알고리즘 만들어가면됨

*/


#include <iostream>
using namespace std;


int bucket[8] = {0,};
bool bucket_flag[8] = { false, };


// nPm
void dfs(int n, int m, int cnt = 0) {
	
	if (cnt == m) {
		for (int i = 0; i < m; i++) { cout << bucket[i] << " "; }
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		
		if (bucket_flag[i]) { continue; }

		bucket[cnt] = i + 1;
		bucket_flag[i] = true;
		
		dfs(n, m, cnt+1);
		bucket_flag[i] = false;
	}
	

}

int main() {

	int n, m;
	cin >> n >> m;
	dfs(n, m);

}
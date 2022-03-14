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

// 1. recursive 

int arr[8] = {0,};
bool isVisited[8] = { false, };

void dfs(int n, int m, int cnt = 0) {
	
	if (cnt == m) {
		for (int i = 0; i < m; i++) { cout << arr[i] << " "; }
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		
		if (isVisited[i]) { continue; }

		arr[cnt] = i + 1;
		isVisited[i] = true;
		
		dfs(n, m, cnt+1);
		isVisited[i] = false;
	}
	

}

int main() {

	int n, m;
	cin >> n >> m;
	dfs(n, m);

}


//// 2.
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//
//	int* result = new int[m];
//	result 
//
//	for (int i = 0; i < m; i++) {
//
//
//
//	}
//
//
//}
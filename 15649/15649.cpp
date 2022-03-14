// #15649
/*
problem: �ڿ��� N, M ���̰� M�� ����

1���� N���� �ڿ����߿��� �ߺ����� M���� �� ����

nPm ??

i: 1 �� M �� N �� 8
p: ������ ���� ������ �����ϴ� ������ ���.

sol)

������� �ϳ��� �˰��� �������

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
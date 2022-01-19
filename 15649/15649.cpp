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
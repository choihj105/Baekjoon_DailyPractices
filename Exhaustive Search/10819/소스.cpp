/*  ���� 10819 "���̸� �ִ��"
	
	N���� ������ �̷���� �迭 A�� �־�����.�̶�, �迭�� ����ִ� ������ ������ ������ �ٲ㼭 
	���� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 

	|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| �� MAX��
*/

// 1. ����: ����Ž�� .. n���� 3 <= N <= 8 �����̱⿡ ������ ã�� ��� �ĺ��˻��� ����� ��
// ��� �ĺ��˻� O(2**n)
// DFS ���̿켱Ž��, Back Tracking .. 

#include <iostream>
#include <vector>
using namespace std;

int arr[10];
int check[10];
int use_arr[10];
int n;
int max_n = 0;

int cal() {
	int result = 0;

	for (int i = 0; i < n-1; i++) {
		result += abs(use_arr[i] - use_arr[i + 1]);
	}
	return result;
}

void dfs(int cnt) {
	if (cnt == n) { max_n = max(max_n, cal()); return; }

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;

		use_arr[cnt] = arr[i];
		check[i] = 1;
		dfs(cnt + 1);
		check[i] = 0;
	}
}

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		check[i] = 1;
		use_arr[0] = arr[i];
		dfs(1);
		check[i] = 0;
	}

	cout << max_n;

}
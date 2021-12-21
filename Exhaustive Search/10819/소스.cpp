/*  ���� 10819 "���̸� �ִ��"
	
	N���� ������ �̷���� �迭 A�� �־�����.�̶�, �迭�� ����ִ� ������ ������ ������ �ٲ㼭 
	���� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 

	|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| �� MAX��
*/

// 1. ����: ����Ž�� .. n���� 3 <= N <= 8 �����̱⿡ ������ ã�� ��� �ĺ��˻��� ����� ��
// DFS ���̿켱Ž��, Back Tracking .. 


#include <iostream>
using namespace std;

int A[10]; // �־��� �迭
int n; // ���� ����
int basket[10]; // ���ʴ�� �迭�� ���� ��
bool basket_check[10]; // �뿡 �迭�� ����ִ��� Ȯ���ϴ� �뵵
int MAX_result = 0; // �ִ� ��

int cal() {
	int result = 0;
	for (int i = 0; i < n - 1; i++) {
		result += abs(basket[i] - basket[i + 1]);
	}
	return result;
}

// 1. ����� ���
void DFS(int cnt) { 
	if (cnt == n) {
		MAX_result = max(MAX_result, cal()); return;
	}

	for (int i = 0; i < n; i++) {

		if (basket_check[i]) continue;

		basket[cnt] = A[i];
		basket_check[i] = true;
		DFS(cnt + 1);
		basket_check[i] = false;
	}
}
// ��ġ������ ���� ������� basket�� ����־�鼭 ���� ������ �ϴ� �˰����̴�.

int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	DFS(0);

	cout << MAX_result;
	
}



































//int arr[10];
//int check[10];
//int use_arr[10];
//int n;
//int max_n = 0;
//
//// �ϼ��� �迭�� ���� �˱����� ����Լ�
//int cal() {
//	int result = 0;
//
//	for (int i = 0; i < n-1; i++) {
//		result += abs(use_arr[i] - use_arr[i + 1]);
//	}
//	return result;
//}
//
//// 1. ��� �Լ��� �����ϱ�
//void dfs(int cnt) {
//	if (cnt == n) { max_n = max(max_n, cal()); return; }
//
//	for (int i = 0; i < n; i++) {
//		if (check[i]) continue;
//
//		use_arr[cnt] = arr[i];
//		check[i] = 1;
//		dfs(cnt + 1);
//		check[i] = 0;
//	}
//}
//
//int main() 
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	for (int i = 0; i < n; i++) {
//		check[i] = 1;
//		use_arr[0] = arr[i];
//		dfs(1);
//		check[i] = 0;
//	}
//
//	cout << max_n;
//
//}
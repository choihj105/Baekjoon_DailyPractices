// 2798. ����
// ī�� ���� 21 ���� �ʴ� �ѵ� ������, ī�� ���� �ִ��� ũ�� ����� ����
// �̹� ��Ģ���� N���� ī�忡�� 3���� ���� �� M�� ���� �����鼭 M�� �ִ��� ������ ����� ����
// �Է� : 3 <= N <= 100. 10 <= M <= 300,000, 0 < ī�� ���� < 100,000 ���� ����

// ���չ����� Ǫ�°�, �� N C 3�� �Ͽ� M�� ���� �����. �ִ� �� 100C3�̿��� 100*99*98/6�̱� ������ ������ ���ϵ����Ѵ�
#include <iostream>

int A[100];
int basket[3];
bool check[100];
int result = 0;

// 1. ����� ������� ���� �����ϱ�.
void DFS(int idx, int cnt) {
	if (cnt == 3) { result = basket[0] + basket[1] + basket[2];  return; } // cal()�� �ش��ϴ� �Լ�

	for (int i = idx; i < 3; i++) {
		if (check[i]) { continue; }

		check[i] = true;
		//basket[cnt] = 




	}



}

int main() {
	

	
	int n;
	int Max_m;
	

}
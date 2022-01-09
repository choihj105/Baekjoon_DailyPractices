// #6588 
/*

i:6 <= n <= 1,000,000 (�� n�� ¦��)
o : n = a + b (�� a,b�� Ȧ���� �Ҽ�), b-a�� ���� ū ������ ���, 
���� ��Ÿ�� �� ���� ��� "Goldbach's conjecture is wrong." ���


sol 
1) �Ҽ��� ��Ÿ���� ��� O(n)�� ������ ����� ������, �ش� ������ ��Ʈ n���� Ȯ���ϴ� ���

*/
#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false; // 1 is not Prime.

	// 2���� ��Ʈ n���� ������� �ִ��� Ȯ��
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	int n[100001];
	int odd_i, odd_j;
	int cnt = 0;
	
	// �Է�
	while (true) {		
		cin >> n[cnt];
		if (n[cnt] == 0) break;
		++cnt;
	}


	// ���
	for (int i = 0; i < cnt; i++) {
		
		odd_i = 1; odd_j = n[i] - 1; // defalut

		for (int j = 1; j <= (n[i] / 4) + 1; j++) {

			if (isPrime(odd_j) && isPrime(odd_i))
			{
				cout << n[i] << " = " << odd_i << " + " << odd_j << endl;
				break;
			}

			odd_i += 2; odd_j -= 2;
		}
		if (odd_i > odd_j) cout << "Goldbach's conjecture is wrong." << endl;
	}

}
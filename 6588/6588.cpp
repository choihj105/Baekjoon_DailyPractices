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
	if (n == 2) return true; // 2 is Prime.

	// 2���� ��Ʈ n���� ������� �ִ��� Ȯ��
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	int n;
	int odd_i, odd_j;
		
	while (cin >> n) {

		if (n == 0) break;

		odd_i = 1; odd_j = n - 1; // defalut

		for (int i = 1; i <= (n / 4) + 1; i++) {

			if (isPrime(odd_j) && isPrime(odd_i))
			{
				cout << n << " = " << odd_i << " + " << odd_j << endl;
				break;
			}
		
			odd_i += 2; odd_j -= 2;
		}

		if (odd_i >= odd_j) cout << "\"Goldbach's conjecture is wrong.\"" << endl;
	
	}

}
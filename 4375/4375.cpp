// 4375.
/*
* Problem
2�� 5�� ������ �������� �ʴ� ���� n(1 �� n �� 10000)�� �־����� ��,
1�θ� �̷����  n�� ����� ã�� ���α׷��� �ۼ��Ͻÿ�.

* Solution
1) ���� ��Ÿ�� �״�� Ǫ�� ��� -> �ð��ʰ�(1��)
2)							 

*/

#include <iostream>
using namespace std;

int cal(int n) {
	
	// ��� m, �ڸ��� result
	
	int m = 1, result = 0;
	
	while (true)
	{
		// ��� m �� ã�� ���� ��
		if (m % n == 0)
		{
			do {
				result += 1;
			} while (m /= 10);
			return result;
			
		}
		// m�� -> 1 -> 11 -> 111 -> ...
		else {
			m = m * 10 + 1;
		}
	}
	
}

int main()
{
	// �־��� �� n, ��� m, �ڸ��� k
	int n[3];
	int k[3];

	// �Է¹�
	for (int i = 0; i < 3; i++) {

		cin >> n[i];
	}

	// ��¹�
	for (int i = 0; i < 3; i++) {

		k[i] = cal(n[i]);
		cout << k[i] << endl;
	}

}
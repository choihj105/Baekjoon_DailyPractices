// #1748
/*

i: 1 <= N <= 100,000,000
o: 1���� n���� �̾� ���� ���� �ڸ��� ���


sol)
1) 1~9 : 1  - 9��
2) 10~99 : 2  - 90��
3) 100~999 : 3 - 900��

�ð����� 0.15��


�ڸ����� ���� ������ ���� �迭�� �����.
ex) int n[3]   // n[0]�� x  n[1]���� ���� // n[1]�� = 9, n[2] = 90 *
*/

#include <iostream>
using namespace std;

int main() {
	long long int n; // input
	long long int output; // output
	int k =0; // n�� �ڸ���

	cin >> n; // 1<= n <= 100,000,000

	for (int i = n; i != 0; i /= 10) {
		k++;
	}

	


}


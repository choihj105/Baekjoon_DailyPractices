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

int main()
{
	int n; // �Է� n
	long long m; // 1�� �̷���� �� -> 1, 11, 111 ...
	int cnt; // �����, �ڸ���
	
	
	while (cin >> n) {
		m = 1; cnt = 1;

		while (true) {
			
			if (m % n == 0) {
				cout << cnt << endl;
				break;
			}
			else {
				m %= n; // m�� ���� �̸� mod ���༭ �ӵ��� ������.
				m = m * 10 + 1;
				cnt += 1;
			}
		
		}
	}
}
// #6064
/*

i : 1<= M , N <= 40,000,  1<=x<=M  , 1<= y<= N
	M , N�� �ּҰ����
	�׽�Ʈ ������ T
	M, N, x, y

o : <x,y>�� ���° ������ ������ �ȸ����� -1


sol)
x, y�� ���̸�ŭ�� ������ �����Ѵ�.

|x-y| % |M-N| == 0
*/

#include <iostream>
using namespace std;

// �ִ� ����� ���� (��Ŭ���� ȣ����)
int gcd(int a, int b) {

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

// �ּ� ����� ����
int lcm(int a, int b) { return  (a * b) / gcd(a, b); }



int main() {
	int m, n, x, y, t, k = 0; // k = result 
	cin >> t;

	while (t--) {
		int _m = 0;
		int _lcm;
		cin >> m >> n >> x >> y;

		// �ּҰ���� ����
		if (m >= n) _lcm = lcm(m, n);
		else _lcm = lcm(n, m);


		k = x; // default ��
		while (true) {
			int tmp = (x + m * _m) % n;
			// ���� ����
			if (tmp == y) break; // % �Ҷ� 0�ΰ��� �߰��ؾ��Ѵ�.
			else if (tmp == 0) { if (n == y) break; }
			k += m;
			_m++;

			// �ƴ� ����
			if (k > _lcm){
				k = -1;
				break;
			}
		}

		cout << k << "\n";
	}
}


// �ּҰ���� -> �� �ڿ����� �� / �ִ� �����(��Ŭ���� ȣ����)
// GCD ( Greatest Common Divisor)
// LCM ( Least Common Multiple )

// �ݷ� 13 11  1 11
// #6064
/*

i : 1<= M , N <= 40,000,  1<=x<=M  , 1<= y<= N
	M , N의 최소공배수
	테스트 데이터 T
	M, N, x, y

o : <x,y>는 몇번째 해인지 조건이 안맞으면 -1


sol)
x, y의 차이만큼의 조건을 생각한다.

|x-y| % |M-N| == 0
*/

#include <iostream>
using namespace std;

// 최대 공약수 공식 (유클리드 호제법)
int gcd(int a, int b) {

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

// 최소 공배수 공식
int lcm(int a, int b) { return  (a * b) / gcd(a, b); }



int main() {
	int m, n, x, y, t, k = 0; // k = result 
	cin >> t;

	while (t--) {
		int _m = 0;
		int _lcm;
		cin >> m >> n >> x >> y;

		// 최소공배수 대입
		if (m >= n) _lcm = lcm(m, n);
		else _lcm = lcm(n, m);


		k = x; // default 값
		while (true) {
			int tmp = (x + m * _m) % n;
			// 구할 조건
			if (tmp == y) break; // % 할때 0인것을 추가해야한다.
			else if (tmp == 0) { if (n == y) break; }
			k += m;
			_m++;

			// 아닐 조건
			if (k > _lcm){
				k = -1;
				break;
			}
		}

		cout << k << "\n";
	}
}


// 최소공배수 -> 두 자연수의 곱 / 최대 공약수(유클리드 호제법)
// GCD ( Greatest Common Divisor)
// LCM ( Least Common Multiple )

// 반례 13 11  1 11
// 4375.
/*
* Problem
2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때,
1로만 이루어진  n의 배수를 찾는 프로그램을 작성하시오.

* Solution
1) 문제 스타일 그대로 푸는 경우 -> 시간초과(1초)
2)							 

*/

#include <iostream>
using namespace std;

int cal(int n) {
	
	// 배수 m, 자리수 result
	
	int m = 1, result = 0;
	
	while (true)
	{
		// 배수 m 를 찾아 냈을 때
		if (m % n == 0)
		{
			do {
				result += 1;
			} while (m /= 10);
			return result;
			
		}
		// m을 -> 1 -> 11 -> 111 -> ...
		else {
			m = m * 10 + 1;
		}
	}
	
}

int main()
{
	// 주어진 수 n, 배수 m, 자리수 k
	int n[3];
	int k[3];

	// 입력문
	for (int i = 0; i < 3; i++) {

		cin >> n[i];
	}

	// 출력문
	for (int i = 0; i < 3; i++) {

		k[i] = cal(n[i]);
		cout << k[i] << endl;
	}

}
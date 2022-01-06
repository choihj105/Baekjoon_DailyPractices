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

int main()
{
	int n; // 입력 n
	long long m; // 1로 이루어진 값 -> 1, 11, 111 ...
	int cnt; // 결과값, 자릿수
	
	
	while (cin >> n) {
		m = 1; cnt = 1;

		while (true) {
			
			if (m % n == 0) {
				cout << cnt << endl;
				break;
			}
			else {
				m %= n; // m의 수를 미리 mod 해줘서 속도를 높힌다.
				m = m * 10 + 1;
				cnt += 1;
			}
		
		}
	}
}
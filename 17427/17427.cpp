// #17427 약수의 합
/*
* 
i : 1 <= n <= 1,000,000
o : n의 보다 작은 자연수 k의 약수의 합 f(k)들의 합 g(k)

sol
1) 공약수의 성질을 이용해서 -> 시간 초과가 난다.

*/
#include <ctime>

#include <iostream>
using namespace std;

int main()
{
	clock_t start, finish;

	start = clock();

	int n;
	cin >> n;

	int res = 0;
	
	for (int i = 1; i <= n; i++) {
			
		// 결과값 계산해주는 식
		for (int j = i; j <= n; j += i) {
			res += i;
		}
			
	}
	cout << res << endl;

	finish = clock();

	cout << (double)(finish - start) / CLOCKS_PER_SEC;
	
}
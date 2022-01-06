// #17427 약수의 합
/*
* 
i : 1 <= n <= 1,000,000
o : n의 보다 작은 자연수 k의 약수의 합 f(k)들의 합 g(k)

sol
1) 공약수의 성질을 이용해서 -> 시간 초과가 난다.
2) 이중 for문에서 단순하게 생각하여 풀게끔.
*/
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int n;
	cin >> n;

	long long res = 0;
	
	for (int i = 1; i <= n; i++) {
		
		res += (n / i) * i;

	}

	cout << res << endl;

}
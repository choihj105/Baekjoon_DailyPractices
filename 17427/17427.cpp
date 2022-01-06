// #17427 ����� ��
/*
* 
i : 1 <= n <= 1,000,000
o : n�� ���� ���� �ڿ��� k�� ����� �� f(k)���� �� g(k)

sol
1) ������� ������ �̿��ؼ� -> �ð� �ʰ��� ����.

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
			
		// ����� ������ִ� ��
		for (int j = i; j <= n; j += i) {
			res += i;
		}
			
	}
	cout << res << endl;

	finish = clock();

	cout << (double)(finish - start) / CLOCKS_PER_SEC;
	
}
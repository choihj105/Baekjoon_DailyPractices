// #17427 ����� ��
/*
* 
i : 1 <= n <= 1,000,000
o : n�� ���� ���� �ڿ��� k�� ����� �� f(k)���� �� g(k)

sol
1) ������� ������ �̿��ؼ� -> �ð� �ʰ��� ����.
2) ���� for������ �ܼ��ϰ� �����Ͽ� Ǯ�Բ�.
*/
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int res = 0;
	
	for (int i = 1; i <= n; i++) {
			
		// ����� ������ִ� ��
		
		res += (n / i) * i;

			
	}
	cout << res << endl;
}
// # 9095

/*
i : �׽�Ʈ ���̽� T�� , ���� 0 < n <11
o : 1, 2, 3���� �̷���� ������� ��

sol)
1) �Ѱ��� ������ ���Ѵ�. ��� �� �� ������?

2) �ڸ����� ���ϱ�?

3) DP�� Ǯ��
*/
/*
1/ 1
2/ 1+ 1 / 2
3/ 1+1+1/ 1+2/ 2+1/ 3

*/
#include <iostream>
using namespace std;

int main() {

	int t = 0 , tmp = 0;
	cin >> t;

	int *input = new int[t];
	
	for (int k = 0; k < t; k++) {
		cin >> input[k];
	}


	int n[11] = { 0, 1, 2, 4, 0, }; // idx == number n

	for (int i = 4; i < 11; i++) {
		n[i] = n[i - 1] + n[i - 2] + n[i - 3];
	}

	for (int j = 0; j < t; j++) {
		cout << n[(input[j])] << endl;
	}
}
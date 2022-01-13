// # 9095

/*
i : 테스트 케이스 T개 , 정수 0 < n <11
o : 1, 2, 3으로 이루어진 방법들의 수

sol)
1) 한개씩 일일히 구한다. 재귀 쓸 수 있을듯?

2) 자리별로 구하기?

3) DP로 풀기
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
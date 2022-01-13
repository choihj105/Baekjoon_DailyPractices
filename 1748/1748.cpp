// #1748
/*

i: 1 <= N <= 100,000,000
o: 1부터 n까지 이어 붙힌 수의 자릿수 출력


sol)
1) 1~9 : 1  - 9개
2) 10~99 : 2  - 90개
3) 100~999 : 3 - 900개

시간제한 0.15초


자리수에 따른 길이의 갯수 배열을 만든다.
ex) int n[3]   // n[0]은 x  n[1]부터 시작 // n[1]은 = 9, n[2] = 90 *
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long int n; // input
	long long int output = 0; // output
	
	int k =0; // n의 자릿수
	int bucket[10] = { 0, }; // 0은 제외한 1부터 9번째까지의 자릿수 합 ex) n[1] = 9*1 ,n[2] = 90*2
	
	for (int i = 1; i < 10; i++) {
		bucket[i] = 9 * i * (long long int)pow(10, i - 1);
	}
	
	cin >> n; // 1<= n <= 100,000,000

	for (int i = n; i != 0; i /= 10) {
		k++;
	}

	for (int i = 1; i < k; i++) {
		output += bucket[i];
	}

	output += (n - pow(10, k - 1) + 1) * k;
	
	cout << output;

	


}


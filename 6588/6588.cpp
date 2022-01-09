// #6588 
/*

i:6 <= n <= 1,000,000 (단 n은 짝수)
o : n = a + b (단 a,b는 홀수인 소수), b-a가 가장 큰 것으로 출력, 
만약 나타낼 수 없는 경우 "Goldbach's conjecture is wrong." 출력


sol 
1) 소수를 나타내는 방법 O(n)인 원초적 방법을 제외한, 해당 숫자의 루트 n까지 확인하는 방법
2) 시간초과를 줄이기 위해서 endl보다 \n을 써줘야한다.
*/
#include <iostream>
using namespace std;

bool isPrime(int n) {
	// 2부터 루트 n까지 공약수가 있는지 확인
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false; 
	}
	return true;
}


int main( ){
	
	// cout , cin 최적화를 위한 코드(?)
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 1;
	int odd_i, odd_j;

	while(n) {		
		cin >> n;

		//odd_i = 3; odd_j = n - 3; // defalut

		for(int i = 1; i < n/2 ; i++){
			odd_i = 2 * i + 1;
			odd_j = n - odd_i;

			if (isPrime(odd_i) and isPrime(odd_j))
			{
				cout << n << " = " << odd_i << " + " << odd_j << "\n";
				break;
			}
		}
		
		if (odd_i > odd_j) { cout << "Goldbach's conjecture is wrong." << "\n"; }
	}
}

// 문제점은 바로 endl 을 쓴 이유,, -> \n이 훨씬 더 빨리 돌아간다.

/*
int main() {
	int n[100001];
	int odd_i, odd_j;
	int cnt = 0;

	// 입력
	while (true) {
		cin >> n[cnt];
		if (n[cnt] == 0) break;
		++cnt;
	}


	// 출력
	for (int i = 0; i < cnt; i++) {

		odd_i = 1; odd_j = n[i] - 1; // defalut

		for (int j = 1; j <= (n[i] / 4) + 1; j++) {

			if (isPrime(odd_j) && isPrime(odd_i))
			{
				cout << n[i] << " = " << odd_i << " + " << odd_j << endl;
				break;
			}

			odd_i += 2; odd_j -= 2;
		}
		if (odd_i > odd_j) cout << "Goldbach's conjecture is wrong." << endl;
	}

}
*/
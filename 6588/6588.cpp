// #6588 
/*

i:6 <= n <= 1,000,000 (�� n�� ¦��)
o : n = a + b (�� a,b�� Ȧ���� �Ҽ�), b-a�� ���� ū ������ ���, 
���� ��Ÿ�� �� ���� ��� "Goldbach's conjecture is wrong." ���


sol 
1) �Ҽ��� ��Ÿ���� ��� O(n)�� ������ ����� ������, �ش� ������ ��Ʈ n���� Ȯ���ϴ� ���
2) �ð��ʰ��� ���̱� ���ؼ� endl���� \n�� ������Ѵ�.
*/
#include <iostream>
using namespace std;

bool isPrime(int n) {
	// 2���� ��Ʈ n���� ������� �ִ��� Ȯ��
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false; 
	}
	return true;
}


int main( ){
	
	// cout , cin ����ȭ�� ���� �ڵ�(?)
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

// �������� �ٷ� endl �� �� ����,, -> \n�� �ξ� �� ���� ���ư���.

/*
int main() {
	int n[100001];
	int odd_i, odd_j;
	int cnt = 0;

	// �Է�
	while (true) {
		cin >> n[cnt];
		if (n[cnt] == 0) break;
		++cnt;
	}


	// ���
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
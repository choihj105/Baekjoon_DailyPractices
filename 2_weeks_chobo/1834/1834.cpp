#include <iostream>
using namespace std;

int main() {

	long long int N, i = 0, t = 0 ;
	cin >> N;

	while (++i) {
		if (i == N) break;
		t += N * i + i;
	}
	cout << t;
}
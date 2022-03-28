#include <iostream>
using namespace std;

int main() {
	long long N, M;
	cin >> N >> M;
	long long total = N - M;

	total *= (total < 0) ? -1 : 1;
	cout << total;
}
#include <iostream>
using namespace std;

int main() {
	int e, f, c; // 가진 빈 병, 발견한 빈 병, 새 병으로 바꾸는데 필요한 갯수
	cin >> e >> f >> c;

	int cnt(0); // 마신 갯수
	int bottle = e + f;
	
	while (bottle >= c) {
		int newSoda = bottle / c;
		cnt += newSoda;
		bottle %= c;
		bottle += newSoda;
	}
	cout << cnt;
	
}